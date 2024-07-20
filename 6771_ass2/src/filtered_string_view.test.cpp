#include "./filtered_string_view.h"

#include <catch2/catch.hpp>
#include <functional>
#include <set>
#include <string>

TEST_CASE("Constructors") {
	SECTION("Default Constructor") {
		fsv::filtered_string_view sv;
		REQUIRE(sv.size() == 0);
		REQUIRE(sv.data() == nullptr);
		REQUIRE(sv.predicate()('a') == true);
	}

	SECTION("Implicit String Constructor") {
		std::string str = "cat";
		fsv::filtered_string_view sv = str;
		REQUIRE(sv.size() == str.size());
		REQUIRE(sv.data() == str.data());
		REQUIRE(sv.predicate()('c') == true);
	}

	SECTION("String Constructor with Predicate") {
		std::string str = "cat";
		auto pred = [](char c) { return c == 'a'; };
		fsv::filtered_string_view sv(str, pred);
		REQUIRE(sv.size() == 1);
		REQUIRE(sv.data() == str.data());
		REQUIRE(sv.predicate()('a') == true);
		REQUIRE(sv.predicate()('c') == false);
	}

	SECTION("Implicit Null-Terminated String Constructor") {
		const char* str = "cat";
		fsv::filtered_string_view sv = str;
		REQUIRE(sv.size() == 3);
		REQUIRE(sv.data() == str);
		REQUIRE(sv.predicate()('c') == true);
	}

	SECTION("Null-Terminated String with Predicate Constructor") {
		const char* str = "cat";
		auto pred = [](char c) { return c == 'a'; };
		fsv::filtered_string_view sv(str, pred);
		REQUIRE(sv.size() == 1);
		REQUIRE(sv.data() == str);
		REQUIRE(sv.predicate()('a') == true);
		REQUIRE(sv.predicate()('c') == false);
	}

	SECTION("Copy Constructor") {
		fsv::filtered_string_view sv1 = "bulldog";
		fsv::filtered_string_view copy = sv1;
		REQUIRE(copy.size() == sv1.size());
		REQUIRE(copy.data() == sv1.data());
		REQUIRE(copy.predicate()('b') == sv1.predicate()('b'));
	}

	SECTION("Move Constructor") {
		fsv::filtered_string_view sv1 = "bulldog";
		fsv::filtered_string_view moved = std::move(sv1);
		REQUIRE(moved.size() == 7);
		REQUIRE(moved.data() != nullptr);
		REQUIRE(sv1.data() == nullptr);
		REQUIRE(sv1.size() == 0);
	}
}

TEST_CASE("Destructor") {
	SECTION("Destruction of object") {
		auto* sv = new fsv::filtered_string_view("cat");
		delete sv;
		REQUIRE(true);
	}
}

TEST_CASE("Copy Assignment") {
	auto pred = [](const char& c) { return c == '4' || c == '2'; };
	fsv::filtered_string_view fsv1{"42 bro", pred};
	fsv::filtered_string_view fsv2{};
	fsv2 = fsv1;
	REQUIRE(fsv1 == fsv2);
}

TEST_CASE("Member Operators") {
	SECTION("Move Assignment") {
		auto pred = [](const char& c) { return c == '8' || c == '9'; };
		fsv::filtered_string_view fsv1{"'89 baby", pred};
		fsv::filtered_string_view fsv2{};
		fsv2 = std::move(fsv1);
		REQUIRE(fsv1.size() == 0);
		REQUIRE(fsv1.data() == nullptr);
		REQUIRE(fsv2.size() == 2);
	}

	SECTION("Subscript Operator") {
		auto pred = [](const char& c) { return c == '9' || c == '0' || c == ' '; };
		fsv::filtered_string_view fsv{"only 90s kids understand", pred};
		REQUIRE(fsv[2] == '0');
	}

	SECTION("String Type Conversion") {
		fsv::filtered_string_view sv{"vizsla"};
		std::string s = static_cast<std::string>(sv);
		REQUIRE(s == "vizsla");
		REQUIRE(s.data() != sv.data());
	}
}

TEST_CASE("filtered_string_view::at") {
	SECTION("Valid index in filtered string") {
		auto vowels = std::set<char>{'a', 'A', 'e', 'E', 'i', 'I', 'o', 'O', 'u', 'U'};
		auto is_vowel = [&vowels](const char& c) { return vowels.contains(c); };
		auto sv = fsv::filtered_string_view{"Malamute", is_vowel};
		REQUIRE(sv.at(0) == 'a');
		REQUIRE(sv.at(1) == 'a');
		REQUIRE(sv.at(2) == 'u');
		REQUIRE(sv.at(3) == 'e');
	}

	SECTION("Invalid index - empty string") {
		auto sv = fsv::filtered_string_view{""};
		REQUIRE_THROWS_AS(sv.at(0), std::domain_error);
		REQUIRE_THROWS_WITH(sv.at(0), "filtered_string_view::at(0): invalid index");
	}

	SECTION("Invalid index - out of range") {
		auto sv = fsv::filtered_string_view{"Hello"};
		REQUIRE_THROWS_AS(sv.at(5), std::domain_error);
		REQUIRE_THROWS_WITH(sv.at(5), "filtered_string_view::at(5): invalid index");
	}

	SECTION("Invalid index - negative") {
		auto sv = fsv::filtered_string_view{"Hello"};
		REQUIRE_THROWS_AS(sv.at(-1), std::domain_error);
		REQUIRE_THROWS_WITH(sv.at(-1), "filtered_string_view::at(-1): invalid index");
	}

	SECTION("Filtered access") {
		auto is_vowel = [](const char& c) { return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'; };
		auto sv = fsv::filtered_string_view{"Hello World", is_vowel};

		REQUIRE(sv.at(0) == 'e');
		REQUIRE(sv.at(1) == 'o');
		REQUIRE(sv.at(2) == 'o');
		REQUIRE_THROWS_AS(sv.at(3), std::domain_error);
	}
}

TEST_CASE("filtered_string_view::size") {
	SECTION("Unfiltered string") {
		auto sv = fsv::filtered_string_view{"Maltese"};
		REQUIRE(sv.size() == 7);
	}

	SECTION("Filtered string") {
		auto sv = fsv::filtered_string_view{"Toy Poodle", [](const char& c) { return c == 'o'; }};
		REQUIRE(sv.size() == 3);
	}

	SECTION("String with all matching characters") {
		auto sv = fsv::filtered_string_view{"aaaaaa", [](const char& c) { return c == 'a'; }};
		REQUIRE(sv.size() == 6);
	}

	SECTION("String with spaces") {
		auto sv = fsv::filtered_string_view{"a b c d", [](const char& c) { return c != ' '; }};
		REQUIRE(sv.size() == 4);
	}
}

TEST_CASE("filtered_string_view::empty") {
	SECTION("Non-empty unfiltered string") {
		auto sv = fsv::filtered_string_view{"Australian Shephard"};
		REQUIRE_FALSE(sv.empty());
	}

	SECTION("Empty string") {
		auto empty_sv = fsv::filtered_string_view{};
		REQUIRE(empty_sv.empty());
	}

	SECTION("Filtered string with no matches") {
		auto sv = fsv::filtered_string_view{"Border Collie", [](const char& c) { return c == 'z'; }};
		REQUIRE(sv.empty());
	}
}

TEST_CASE("fsv::data") {
	SECTION("Return Underlying Data") {
		auto s = "Sum 42";
		auto pred = [](const char&) { return false; }; // Predicate that filters out all characters
		fsv::filtered_string_view sv{s, pred};

		const char* data_ptr = sv.data();
		std::string result;
		for (const char* ptr = data_ptr; *ptr; ++ptr) {
			result += *ptr;
		}

		REQUIRE(result == "Sum 42"); // Ensure the data method returns the original string
	}
}

TEST_CASE("fsv::predicate") {
	SECTION("Default predicate") {
		auto sv = fsv::filtered_string_view{"doggo"};
		const auto& predicate = sv.predicate();
		REQUIRE(predicate('a') == true);
		REQUIRE(predicate('1') == true);
		REQUIRE(predicate(' ') == true);
	}

	SECTION("Custom predicate") {
		int call_count = 0;
		auto custom_predicate = [&call_count](const char& c) {
			++call_count;
			return c == 'o';
		};
		auto sv = fsv::filtered_string_view{"doggo", custom_predicate};
		const auto& predicate = sv.predicate();

		REQUIRE(predicate('o') == true);
		REQUIRE(predicate('d') == false);
		REQUIRE(call_count == 2);
	}

	SECTION("Predicate side effects") {
		int print_count = 0;
		const auto print_and_return_true = [&print_count](const char&) {
			++print_count;
			return true;
		};
		const auto sv = fsv::filtered_string_view{"doggo", print_and_return_true};

		const auto& predicate = sv.predicate();
		predicate(char{});
		REQUIRE(print_count == 1);
	}
}

TEST_CASE("Equality and Inequality Operators") {
	SECTION("Equality Operator") {
		auto const lo = fsv::filtered_string_view{"aaa"};
		auto const hi = fsv::filtered_string_view{"zzz"};

		REQUIRE((lo == hi) == false);
		REQUIRE((lo != hi) == true);
	}
}

TEST_CASE("Stream Insertion Operator") {
	SECTION("Stream Insertion") {
		auto fsv = fsv::filtered_string_view{"c++ > rust > java", [](const char& c) { return c == 'c' || c == '+'; }};
		std::ostringstream oss;
		oss << fsv;
		REQUIRE(oss.str() == "c++");
	}
}

TEST_CASE("Three-Way Comparison Operator") {
	SECTION("Three-Way Comparison") {
		auto const lo = fsv::filtered_string_view{"aaa"};
		auto const hi = fsv::filtered_string_view{"zzz"};

		REQUIRE((lo < hi) == true);
		REQUIRE((lo <= hi) == true);
		REQUIRE((lo > hi) == false);
		REQUIRE((lo >= hi) == false);
		REQUIRE((lo <=> hi == std::strong_ordering::less) == true);
	}
}

TEST_CASE("compose") {
	auto best_languages = fsv::filtered_string_view{"c / c++"};
	auto vf =
	    std::vector<std::function<bool(const char&)>>{[](const char& c) { return c == 'c' || c == '+' || c == '/'; },
	                                                  [](const char& c) { return c > ' '; },
	                                                  [](const char& c) {
		                                                  (void)c;
		                                                  return true;
	                                                  }};

	auto sv = fsv::compose(best_languages, vf);
	std::ostringstream oss;
	oss << sv;
	REQUIRE(oss.str() == "c/c++");
}

TEST_CASE("substr function tests") {
	SECTION("Basic substring extraction") {
		fsv::filtered_string_view sv{"Siberian Husky"};
		auto result = fsv::substr(sv, 9);
		REQUIRE(static_cast<std::string>(result) == "Husky");
	}
	SECTION("Substring extraction with length specified") {
		auto is_upper = [](const char& c) { return std::isupper(static_cast<unsigned char>(c)); };
		fsv::filtered_string_view sv{"Sled Dog", is_upper};
		auto result = fsv::substr(sv, 0, 2);
		REQUIRE(static_cast<std::string>(result) == "SD");
	}
}

TEST_CASE("Print via iterator with default predicate") {
	auto print_via_iterator = [](fsv::filtered_string_view const& sv) {
		std::copy(sv.begin(), sv.end(), std::ostream_iterator<char>(std::cout, " "));
	};

	SECTION("Printing 'corgi'") {
		std::stringstream output;
		std::streambuf* coutBuf = std::cout.rdbuf(); // Save old buffer
		std::cout.rdbuf(output.rdbuf()); // Redirect cout to stringstream

		auto fsv1 = fsv::filtered_string_view{"corgi"};
		print_via_iterator(fsv1);

		std::cout.rdbuf(coutBuf); // Restore cout's original buffer
		REQUIRE(output.str() == "c o r g i ");
	}
}

TEST_CASE("Print via iterator with custom predicate") {
	auto print_via_iterator = [](fsv::filtered_string_view const& sv) {
		std::copy(sv.begin(), sv.end(), std::ostream_iterator<char>(std::cout, " "));
	};

	SECTION("Printing 'samoyed' without lowercase vowels") {
		std::stringstream output;
		std::streambuf* coutBuf = std::cout.rdbuf(); // Save old buffer
		std::cout.rdbuf(output.rdbuf()); // Redirect cout to stringstream

		auto fsv = fsv::filtered_string_view{"samoyed", [](const char& c) {
			                                     return !(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
		                                     }};
		print_via_iterator(fsv);

		std::cout.rdbuf(coutBuf); // Restore cout's original buffer
		REQUIRE(output.str() == "s m y d ");
	}
}

TEST_CASE("Iterator operations on filtered_string_view") {
	SECTION("Using std::prev and std::next on 'tosa'") {
		std::stringstream output;
		std::streambuf* coutBuf = std::cout.rdbuf(); // Save old buffer
		std::cout.rdbuf(output.rdbuf()); // Redirect cout to stringstream

		const auto str = std::string("tosa");
		const auto s = fsv::filtered_string_view{str};
		auto it = s.cend();
		std::cout << *std::prev(it) << *std::prev(it, 2);

		std::cout.rdbuf(coutBuf); // Restore cout's original buffer

		std::string actualOutput = output.str();
		actualOutput.erase(std::remove_if(actualOutput.begin(), actualOutput.end(), ::isspace), actualOutput.end());
		REQUIRE(actualOutput == "as");
	}
}

TEST_CASE("Using std::begin and std::end on 'puppy' with predicate removing 'u' and 'y'") {
	const auto s = fsv::filtered_string_view{"puppy", [](const char& c) { return !(c == 'u' || c == 'y'); }};
	std::vector<char> v{s.begin(), s.end()};
	std::string result(v.begin(), v.end());
	REQUIRE(result == "ppp");
}

TEST_CASE("Empty string with predicate") {
	const auto s = fsv::filtered_string_view{"", [](const char& c) { return c == 'x'; }};
	std::vector<char> v{s.rbegin(), s.rend()};
	std::string result(v.begin(), v.end());
	REQUIRE(result == "");
}

TEST_CASE("Split filtered_string_view - Basic cases") {
	SECTION("Split with interest set") {
		auto interest = std::set<char>{'a', 'A', 'b', 'B', 'c', 'C', 'd', 'D', 'e', 'E', 'f', 'F', ' ', '/'};
		auto sv = fsv::filtered_string_view{"0xDEADBEEF / 0xdeadbeef",
		                                    [&interest](const char& c) { return interest.contains(c); }};
		auto tok = fsv::filtered_string_view{" / "};
		auto v = fsv::split(sv, tok);

		REQUIRE(v.size() == 2);
		CHECK(static_cast<std::string>(v[0]) == "DEADBEEF");
		CHECK(static_cast<std::string>(v[1]) == "deadbeef");
	}
}

TEST_CASE("Split function tests") {
	SECTION("Splitting 'xax' by 'x'") {
		auto sv = fsv::filtered_string_view{"xax"};
		auto tok = fsv::filtered_string_view{"x"};
		auto v = fsv::split(sv, tok);
		auto expected = std::vector<fsv::filtered_string_view>{"", "a", ""};
		CHECK(v == expected);
	}

	SECTION("Splitting 'xx' by 'x'") {
		auto sv = fsv::filtered_string_view{"xx"};
		auto tok = fsv::filtered_string_view{"x"};
		auto v = fsv::split(sv, tok);
		auto expected = std::vector<fsv::filtered_string_view>{"", "", ""};
		CHECK(v == expected);
	}
}