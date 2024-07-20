#include "./filtered_string_view.h"
#include <optional>

namespace fsv {
	filtered_string_view::iter::iter() = default;

	filtered_string_view::iter::iter(const filtered_string_view* fsv, size_t index)
	: fsv(fsv)
	, index(index) {
		advance_if_needed();
	}

	auto filtered_string_view::iter::operator*() const -> reference {
		return fsv->data_[index];
	}

	auto filtered_string_view::iter::operator->() const -> pointer {
		return &fsv->data_[index];
	}

	auto filtered_string_view::iter::operator++() -> iter& {
		++index;
		advance_if_needed();
		return *this;
	}

	auto filtered_string_view::iter::operator++(int) -> iter {
		iter temp = *this;
		++(*this);
		return temp;
	}

	auto filtered_string_view::iter::operator--() -> iter& {
		do {
			--index;
		} while (index < fsv->length && !fsv->predicate_(fsv->data_[index]));
		return *this;
	}

	auto filtered_string_view::iter::operator--(int) -> iter {
		iter temp = *this;
		--(*this);
		return temp;
	}

	auto operator<=>(const filtered_string_view& lhs, const filtered_string_view& rhs) -> std::strong_ordering {
		auto lhs_str = std::string(lhs.begin(), lhs.end());
		auto rhs_str = std::string(rhs.begin(), rhs.end());
		return lhs_str <=> rhs_str;
	}

	void filtered_string_view::iter::advance_if_needed() {
		while (index < fsv->length && !fsv->predicate_(fsv->data_[index])) {
			++index;
		}
	}
	auto filtered_string_view::iter::operator+(int len) -> iter {
		index = std::min(fsv->length, index + static_cast<size_t>(len));
		return *this;
	}

	auto filtered_string_view::iter::operator-(int len) -> iter {
		if (static_cast<size_t>(len) > index) {
			index = static_cast<size_t>(-1);
		}
		else {
			index -= static_cast<size_t>(len);
		}
		return *this;
	}

	// fsv class implementations
	filtered_string_view::filtered_string_view()
	: data_(nullptr)
	, length(0)
	, predicate_(default_predicate) {}

	filtered_string_view::filtered_string_view(const std::string& str)
	: data_(str.data())
	, length(str.size())
	, predicate_(default_predicate) {}

	filtered_string_view::filtered_string_view(const std::string& str, std::function<bool(char)> predicate)
	: data_(str.data())
	, length(str.size())
	, predicate_(std::move(predicate)) {}

	filtered_string_view::filtered_string_view(const char* str)
	: data_(str)
	, length(std::strlen(str))
	, predicate_(default_predicate) {}

	filtered_string_view::filtered_string_view(const char* str, std::function<bool(char)> predicate)
	: data_(str)
	, length(std::strlen(str))
	, predicate_(std::move(predicate)) {}

	filtered_string_view::filtered_string_view(const filtered_string_view& other)
	: data_(other.data_)
	, length(other.length)
	, predicate_(other.predicate_) {}

	filtered_string_view::filtered_string_view(filtered_string_view&& other) noexcept
	: data_(std::exchange(other.data_, nullptr))
	, length(std::exchange(other.length, 0))
	, predicate_(std::move(other.predicate_)) {}

	filtered_string_view::~filtered_string_view() = default;

	filtered_string_view& filtered_string_view::operator=(const filtered_string_view& other) {
		if (this != &other) {
			data_ = other.data_;
			length = other.length;
			predicate_ = other.predicate_;
		}
		return *this;
	}

	filtered_string_view& filtered_string_view::operator=(filtered_string_view&& other) noexcept {
		if (this != &other) {
			data_ = std::exchange(other.data_, nullptr);
			length = std::exchange(other.length, 0);
			predicate_ = std::move(other.predicate_);
		}
		return *this;
	}

	// Subscript operator
	char filtered_string_view::operator[](int n) const {
		if (n < 0) {
			throw std::out_of_range("Index cannot be negative");
		}

		size_t count = 0;
		for (size_t i = 0; i < length; ++i) {
			if (predicate_(data_[i])) {
				if (count == static_cast<size_t>(n)) {
					return data_[i];
				}
				++count;
			}
		}

		throw std::out_of_range("Index out of range");
	}

	filtered_string_view::operator std::string() const {
		std::string result;
		for (size_t i = 0; i < length; ++i) {
			if (predicate_(data_[i])) {
				result += data_[i];
			}
		}
		return result;
	}

	auto fsv::filtered_string_view::size() const -> std::size_t {
		return static_cast<std::string>(*this).length();
	}

	auto filtered_string_view::empty() const -> bool {
		return size() == 0;
	}

	auto filtered_string_view::data() const -> const char* {
		return data_;
	}

	auto filtered_string_view::predicate() const -> const std::function<bool(char)>& {
		return predicate_;
	}

	auto filtered_string_view::at(int index) const -> const char& {
		if (index < 0 || static_cast<size_t>(index) >= size()) {
			throw std::domain_error("filtered_string_view::at(" + std::to_string(index) + "): invalid index");
		}

		size_t count = 0;
		for (size_t i = 0; i < length; ++i) {
			if (predicate_(data_[i])) {
				if (count == static_cast<size_t>(index)) {
					return data_[i];
				}
				++count;
			}
		}

		throw std::domain_error("filtered_string_view::at(" + std::to_string(index) + "): invalid index");
	}
	fsv::filtered_string_view::iter fsv::filtered_string_view::begin() const {
		size_t index = 0;
		while (index < length && !predicate_(data_[index])) {
			++index;
		}
		return iter(this, index);
	}
	fsv::filtered_string_view::iter fsv::filtered_string_view::end() const {
		return iter(this, length);
	}

	fsv::filtered_string_view::iter fsv::filtered_string_view::cbegin() const {
		return begin();
	}

	fsv::filtered_string_view::iter fsv::filtered_string_view::cend() const {
		return end();
	}

	fsv::filtered_string_view::iter fsv::filtered_string_view::rbegin() const {
		ssize_t index = static_cast<ssize_t>(length) - 1;
		while (index >= 0 && !predicate_(data_[index])) {
			--index;
		}
		return iter(this, static_cast<size_t>(index));
	}

	fsv::filtered_string_view::iter fsv::filtered_string_view::rend() const {
		return iter(this, static_cast<size_t>(-1));
	}

	fsv::filtered_string_view::iter fsv::filtered_string_view::crbegin() const {
		return rbegin();
	}

	fsv::filtered_string_view::iter fsv::filtered_string_view::crend() const {
		return rend();
	}

	bool filtered_string_view::default_predicate(char unused) {
		(void)unused;
		return true;
	}

	filtered_string_view::filtered_string_view(iterator begin, iterator end, std::function<bool(char)> predicate)
	: data_(begin.operator->())
	, length(end - begin)
	, predicate_(std::move(predicate)) {}

	auto operator==(const filtered_string_view& lhs, const filtered_string_view& rhs) -> bool {
		if (lhs.size() != rhs.size()) {
			return false;
		}

		auto it_lhs = lhs.begin();
		auto it_rhs = rhs.begin();

		while (it_lhs != lhs.end() && it_rhs != rhs.end()) {
			if (*it_lhs != *it_rhs) {
				return false;
			}
			++it_lhs;
			++it_rhs;
		}

		return true;
	}

	auto compose(const filtered_string_view& fsv, const std::vector<std::function<bool(const char&)>>& filts)
	    -> filtered_string_view {
		auto combined_predicate = [&fsv, &filts](char c) {
			if (!fsv.predicate()(c))
				return false; // Check against the fsv's predicate
			for (const auto& filt : filts) {
				if (!filt(c))
					return false; // Check against each filter in filts
			}
			return true;
		};

		return filtered_string_view(fsv.data(), combined_predicate);
	}

	auto substr(const filtered_string_view& fsv, int pos, int count) -> filtered_string_view {
		if (pos < 0) {
			pos = 0;
		}
		size_t size = fsv.size();
		auto rcount = (count <= 0 || static_cast<size_t>(pos) + static_cast<size_t>(count) > size)
		                  ? size - static_cast<size_t>(pos)
		                  : static_cast<size_t>(count);

		char* str = strdup(fsv.data() + pos);
		if (rcount < size) {
			str[rcount] = '\0';
		}
		return {str, fsv.predicate()};
	}

	auto split(const filtered_string_view& fsv, const filtered_string_view& tok) -> std::vector<filtered_string_view> {
		std::vector<filtered_string_view> result;

		if (fsv.empty()) {
			result.push_back(fsv); // Push back an empty copy of fsv
			return result;
		}

		auto fsv_iter = fsv.begin();
		auto tok_iter = tok.begin();

		while (fsv_iter != fsv.end()) {
			auto match_start = std::search(fsv_iter, fsv.end(), tok_iter, tok.end());
			result.push_back(filtered_string_view(fsv_iter, match_start, fsv.predicate()));

			if (match_start != fsv.end()) {
				auto distance = static_cast<int>(std::distance(tok_iter, tok.end()));
				fsv_iter = match_start + static_cast<std::size_t>(distance);
			}
			else {
				break;
			}
			// If the match_start is at the end of fsv, add an empty segment to result
			if (match_start == fsv.end()) {
				result.push_back(filtered_string_view());
				break;
			}
		}

		return result;
	}

} // namespace fsv