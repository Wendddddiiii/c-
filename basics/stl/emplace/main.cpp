#include <iostream>
#include <functional>
#include <optional>
#include <vector>

// Define the paint enum
enum class paint : unsigned char {
    RED,
    GREEN,
    BLUE,
    YELLOW,
    CYAN,
    MAGENTA,
    BROWN
};

// Function to mix two paints
auto wacky_colour(paint p1, paint p2) -> std::optional<paint> {
    auto ret = std::optional<paint>{};

    if (p1 == paint::RED && p2 == paint::GREEN) {
        ret.emplace(paint::YELLOW);
    } else if (p1 == paint::RED && p2 == paint::BLUE) {
        ret.emplace(paint::MAGENTA);
    } else if (p1 == paint::GREEN && p2 == paint::BLUE) {
        ret.emplace(paint::CYAN);
    } else if (p1 == paint::YELLOW && p2 == paint::MAGENTA) {
        ret.emplace(paint::BROWN);
    } else if (p1 == paint::YELLOW && p2 == paint::CYAN) {
        ret.emplace(paint::BROWN);
    } else if (p1 == paint::CYAN && p2 == paint::MAGENTA) {
        ret.emplace(paint::BROWN);
    } else if (p1 == paint::BROWN && p2 == paint::BROWN) {
        ret.emplace(paint::BROWN);
    }

    return ret;
}

// Function to mix a vector of paints using a mixing function
auto mix(const std::vector<paint>& paints, std::function<std::optional<paint>(paint, paint)> fn) -> std::optional<paint> {
    auto new_paint = std::optional<paint>{paints.front()};
    for (auto i = 1u; i < paints.size() && new_paint.has_value(); ++i) {
        new_paint = fn(*new_paint, paints[i]);
    }
    return new_paint;
}


// Function to convert paint enum to string
std::string paint_to_string(paint p) {
    switch (p) {
        case paint::RED:     return "RED";
        case paint::GREEN:   return "GREEN";
        case paint::BLUE:    return "BLUE";
        case paint::YELLOW:  return "YELLOW";
        case paint::CYAN:    return "CYAN";
        case paint::MAGENTA: return "MAGENTA";
        case paint::BROWN:   return "BROWN";
        default:             return "UNKNOWN";
    }
}


int main() {
    std::vector<paint> paints = { paint::RED, paint::GREEN, paint::CYAN };

    // Example 1: Mixing using wacky_colour function
    auto result1 = mix(paints, wacky_colour);

    if (result1.has_value()) {
        std::cout << "Mixed paint (wacky_colour): " <<  paint_to_string(*result1)<< std::endl;
    } else {
        std::cout << "Mixing failed." << std::endl;
    }

    // Example 2: Mixing with different set of paints
    std::vector<paint> paints2 = { paint::YELLOW, paint::MAGENTA, paint::BROWN };

    auto result2 = mix(paints2, wacky_colour);

    if (result2.has_value()) {
        std::cout << "Mixed paint (wacky_colour): " <<  paint_to_string(*result2) << std::endl;
    } else {
        std::cout << "Mixing failed." << std::endl;
    }

    return 0;
}
