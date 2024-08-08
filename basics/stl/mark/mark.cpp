#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <unordered_set>
#include <stdexcept>
#include <numeric>

auto read_marks(const std::string& path) -> std::vector<int>
{
    std::unordered_set<std::string> marks;
    std::ifstream file(path);
    std::string num;
    if (file.is_open()) {
        while (std::getline(file, num)) {
            marks.insert(num);
        }
        file.close();
    }
    else {
        throw std::runtime_error("Unable to open file: " + path);
    }
    // Convert the set of strings to a vector of integers
    std::vector<int> int_marks;
    for (const auto& mark : marks) { 
        int_marks.push_back(std::stoi(mark));
    }
    return int_marks;
}

// Struct to hold statistics
struct stats {
    int lowest;
    int highest;
    int median;
    float mean;
};

auto calculate_stats(const std::vector<int>& marks) -> stats
{      
    std::vector<int> sorted_marks = marks; 
    std::sort(sorted_marks.begin(), sorted_marks.end());

    int lowest = marks.front();
    int highest = marks.back();
    // int lowest = *marks.begin();
    // int highest = *(marks.end() - 1);
    size_t size = marks.size();
    int median = 0;
    if (size % 2 == 0) {
        median = (sorted_marks[size / 2 - 1] + sorted_marks[size / 2]) / 2;
    } else {
        median = sorted_marks[size / 2];
    }
    
    int sum = std::accumulate(sorted_marks.begin(), sorted_marks.end(), 0);
    float mean = static_cast<float>(sum) / size;

    return stats{lowest, highest, median, mean};
}

int main () {
    try {
        std::vector<int> marks = read_marks("marks.txt");
        auto result = calculate_stats(marks);

        // Print result
        std::cout << "Lowest" << result.lowest << std::endl;
        std::cout << "Highest" << result.highest<< std::endl;
        std::cout << "Median" << result.median << std::endl;
        std::cout << "Mean" << result.mean << std::endl;

    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}

