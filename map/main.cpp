// #include <iostream>
// #include <map>
// #include <string>

// auto invert(const std::map<std::string, int>& mp) -> std::map<int, std::string> {
//     std::map<int, std::string> invertedMap;
//     for(const auto& pair : mp) {
//         invertedMap[pair.second] = pair.first;
//     }

//     return invertedMap;
// }

// int main() {
//     std::map<std::string, int> originalMap = {
//         {"Alice", 20},
//         {"bob", 32},
//         {"Sally", 11}
//     };

//     std::map<int, std::string> invertedMap = invert(originalMap);

//     std::cout << "Inverted Map" << std::endl;
//     for (const auto& pair : invertedMap) {
//         std::cout << pair.first << ": " << pair.second << std::endl;
//     }

//     return 0;
// }

//return the longest string 
//auto m = std::map<std::string, int> {
//     {"a", 6771},
//     {"ab", 6771},
//     {"abc", 6771},
//     {"xyz", 6772},
// };
// the inversion should be 
// auto n = std::map<int, std::string> {
//     {6771, "abc"},
//     {6772, "xyz"},
// };

#include <iostream>
#include <map>
#include <string>

auto invert(const std::map<std::string, int>& mp) -> std::map<int, std::string> {
    std::map<int, std::string> invertedMap;
    for(const auto& pair : mp) {
        int key = pair.second;
        const std::string& value = pair.first;


        //update the longest key
        //If the key is not found, it returns an iterator to invertedMap.end().
        // if ==, means not find the key, can init invertedMap[key] with value;
        if (invertedMap.find(key) == invertedMap.end() || value.length() > invertedMap[key].length()) {
            invertedMap[key] = value;
        }
    }
    return invertedMap;

}

int main() {
    std::map<std::string, int> originalMap = {
        {"Alice", 30},
        {"bob", 30},
        {"Bobby", 25},
        {"Charlie", 25}
    };

    std::map<int, std::string> invertedMap = invert(originalMap);

    std::cout << "Inverted map with longest strings:" << std::endl;
    for (const auto& pair : invertedMap) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}