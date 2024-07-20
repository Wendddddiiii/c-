#ifndef COMP6771_ASS2_FSV_H
#define COMP6771_ASS2_FSV_H

#include <algorithm>
#include <compare>
#include <cstring>
#include <functional>
#include <iostream>
#include <iterator>
#include <optional>
#include <string>
#include <utility>
#include <vector>

namespace fsv {
	class filtered_string_view {
		class iter {
		 public:
			using iterator_category = std::bidirectional_iterator_tag;
			using value_type = char;
			using difference_type = std::ptrdiff_t;
			using pointer = const char*;
			using reference = const char&;
			iter();

			explicit iter(const filtered_string_view* fsv, size_t index);
			auto operator*() const -> reference;
			auto operator->() const -> pointer;
			auto operator++() -> iter&;
			auto operator++(int) -> iter;
			auto operator--() -> iter&;
			auto operator--(int) -> iter;

			friend auto operator==(const iter& lhs, const iter& rhs) -> bool {
				return lhs.fsv == rhs.fsv && lhs.index == rhs.index;
			}

			friend auto operator!=(const iter& lhs, const iter& rhs) -> bool {
				return !(lhs == rhs);
			}
			auto operator+(int len) -> iter;
			auto operator-(int len) -> iter;
			friend auto operator-(const iter& lhs, const iter& rhs) -> size_t {
				if (lhs.fsv != rhs.fsv || lhs.index < rhs.index)
					return 0;
				return lhs.index - rhs.index;
			}

		 private:
			void advance_if_needed();
			const filtered_string_view* fsv;
			size_t index;
		};

	 public:
		using iterator = iter;
		filtered_string_view();
		filtered_string_view(const std::string& str);
		filtered_string_view(const std::string& str, std::function<bool(char)> predicate);
		filtered_string_view(const char* str);
		filtered_string_view(const char* str, std::function<bool(char)> predicate);
		filtered_string_view(const filtered_string_view& other);
		filtered_string_view(filtered_string_view&& other) noexcept;
		~filtered_string_view();

		filtered_string_view& operator=(const filtered_string_view& other);
		filtered_string_view& operator=(filtered_string_view&& other) noexcept;
		filtered_string_view(iterator begin, iterator end, std::function<bool(char)> predicate);

		char operator[](int n) const;
		explicit operator std::string() const;
		auto size() const -> std::size_t;
		auto empty() const -> bool;
		auto data() const -> const char*;
		auto predicate() const -> const std::function<bool(char)>&;
		auto at(int index) const -> const char&;

		iter begin() const;
		iter end() const;
		iter cbegin() const;
		iter cend() const;
		iter rbegin() const;
		iter rend() const;
		iter crbegin() const;
		iter crend() const;

		friend auto operator<=>(const filtered_string_view& lhs, const filtered_string_view& rhs) -> std::strong_ordering;

		friend auto operator<<(std::ostream& os, const filtered_string_view& fsv) -> std::ostream& {
			std::string for_out;
			for (auto iter = fsv.begin(); iter != fsv.end(); iter++) {
				if (fsv.predicate_(*iter)) {
					for_out += *iter;
				}
			}
			return os << for_out;
		}

		friend auto operator==(const filtered_string_view& lhs, const filtered_string_view& rhs) -> bool;

	 private:
		const char* data_;
		size_t length;
		std::function<bool(char)> predicate_;

		static bool default_predicate(char unused);
	};
	using filter = std::function<bool(const char&)>;
	// non-member functions
	auto compose(const filtered_string_view& fsv, const std::vector<filter>& filts) -> filtered_string_view;
	auto split(const filtered_string_view& fsv, const filtered_string_view& tok) -> std::vector<filtered_string_view>;
	auto substr(const filtered_string_view& fsv, int pos = 0, int count = 0) -> filtered_string_view;
} // namespace fsv

#endif // COMP6771_ASS2_FSV_H