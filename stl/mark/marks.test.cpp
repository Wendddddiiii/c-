#include "mark.h"  // Include your header file where read_marks and calculate_stats are defined
#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include <fstream>

TEST_CASE("can load the basic marks file") {
    auto expected = std::vector<int> {
        2,
        14,
        90,
        56,
        88,
        44,
        76,
        33,
        100,
        4,
        47,
        67,
        71,
        8
    };

    CHECK(read_marks("marks.txt") == expected);
}

TEST_CASE("correct stats for marking.txt") {
    auto statistics = std::vector<int> {
        85,
        92,
        78,
        90,
        88
    };

    auto expected = stats{
        78,     // lowest
        92,     // highest
        88,     // median
        86.6f   // mean
    };

    auto actual = calculate_stats(statistics);

    CHECK(actual.lowest == expected.lowest);
    CHECK(actual.highest == expected.highest);
    CHECK(actual.median == expected.median);
    CHECK(actual.mean == Approx(expected.mean).epsilon(0.1));  // Approx for floating-point comparison with tolerance
}
