#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cmath>
#include <functional>
#include <numeric>

enum class move : uint8_t {
    NN, SS, WW, EE, NW, NE, SW, SE
};

class style {
protected:
    char background_;

public:
    style() : background_(' ') {}
    explicit style(char background) : background_(background) {}
    virtual ~style() noexcept = default;

    virtual char style_tile() const { return background_; }
    virtual char style_tile(move end_move) const { return '0'; }
    virtual char style_tile(move prev_move, move curr_move) const { return '*'; }

    // Add copy and move constructors, and assignment operators
    style(const style& other) noexcept = default;
    style& operator=(const style& other) noexcept = default;
    style(style&& other) noexcept = default;
    style& operator=(style&& other) noexcept = default;

    auto operator==(const style& other) const -> bool {
        return background_ == other.background_;
    }
};

class detailed_style : public style {
private:
    char end_1_;
    char end_2_;
    size_t move_count_;

public:
    detailed_style(char end_1, char end_2) : style('+'), end_1_(end_1), end_2_(end_2) {}

    auto style_tile(move end_move) const -> char override {
        // Implement this based on the number of moves
        return (move_count_ > 8) ? end_1_ : end_2_;
    }

    void increment_move_count() {
        ++move_count_;
    }

    auto style_tile(move prev_move, move curr_move) const -> char override {
        // Implement this based on the move directions
        if(prev_move != curr_move) {
            switch(curr_move) {
                case move::NN:
                case move::SS:
                    return '|';
                case move::EE:
                case move::WW:
                    return '-';
                case move::NE:
                case move::SW:
                    return '/';
                case move::NW:
                case move::SE:
                    return '\\';
                default:
                    return '+'; // background character, in case of unexpected move
            }
        } else {
            switch (curr_move) {
                case move::NN:
                    return '^';
                case move::SS:
                    return 'v';
                case move::EE:
                    return '>';
                case move::WW:
                    return '<';
                case move::NE:
                case move::SW:
                    return '/';
                case move::NW:
                case move::SE:
                    return '\\';
                default:
                    return '+'; // background character, in case of unexpected move
            }
        }
    }
    // Add copy and move constructors, and assignment operators
    detailed_style(const detailed_style& other) noexcept
    : style(other), end_1_(other.end_1_), end_2_(other.end_2_), move_count_(other.move_count_) {}

    detailed_style& operator=(const detailed_style& other) noexcept {
        if(this != &other) {
            style::operator==(other);
            end_1_ = other.end_1_;
            end_2_ = other.end_2_;
            move_count_ = other.move_count_;
        }
        return *this;
    }
    detailed_style(detailed_style&& other) noexcept 
    : style(std::move(other)), end_1_(std::exchange(other.end_1_, '0')), end_2_(std::exchange(other.end_2_, '0')), move_count_(std::exchange(other.move_count_, 0)) {}
    
    detailed_style& operator=(detailed_style&& other) noexcept {
        if (this != &other) {
            style::operator=(std::move(other));
            end_1_ = std::exchange(other.end_1_, '0');
            end_2_ = std::exchange(other.end_2_, '0');
            move_count_ = std::exchange(other.move_count_, 0);
        }
        return *this;
    }
};


using map = std::vector<std::vector<char>>;
auto at(const map &mp, int x, int y) -> char {
    return mp[y][x];
}
auto at(map &mp, int x, int y) -> char& {
    return mp[y][x];
}

void apply_move(move m, int& x, int& y) {
    switch (m) {
        case move::NN: --y; break;
        case move::SS: ++y; break;
        case move::WW: --x; break;
        case move::EE: ++x; break;
        case move::NW: --x; --y; break;
        case move::NE: ++x; --y; break;
        case move::SW: --x; ++y; break;
        case move::SE: ++x; ++y; break;
    }
}

auto make_map(const std::vector<move>& path, const style& styler) -> map {
    if (path.empty()) {
        return map(1, std::vector<char>(1, styler.style_tile()));
    }
    // 1. Calculate the map dimensions based on the path
    int max_x = 0, max_y = 0;
    int curr_x = 0, curr_y = 0;

    for(const auto& m: path) {
        apply_move(m, curr_x, curr_y);
        max_x = std::max(max_x, curr_x);
        max_y = std::max(max_y, curr_y);
    }

    // 2. Create the map with the calculated dimensions
    map result(max_y + 1, std::vector<char>(max_x + 1, styler.style_tile()));
    // 3. Traverse the path and style each tile
    curr_x = 0; curr_y = 0;
    move prev_move = path[0];  // Assume path is not empty
    for (size_t i = 0; i < path.size(); ++i) {
        const auto& curr_move = path[i];
        at(result, curr_x, curr_y) = styler.style_tile(prev_move, curr_move);
        apply_move(curr_move, curr_x, curr_y);
        prev_move = curr_move;
    }
    at(result, curr_x, curr_y) = styler.style_tile(path.back());
    return result;
}
