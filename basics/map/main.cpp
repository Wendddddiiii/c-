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

//using ->
auto inverted(const std::map<std::string, int> &mp) -> std::map<int, std::string> {
    auto inverted = std::map<int, std::string>{};


    //iterate over each key-value pair in the input map
    for (const auto &[k, v] : mp) {

        //try to find the value (v) in the inverted map; if v is not found, it will be equal to inverted.end(), which represents a position past the last element.
        if (auto it = inverted.find(v); it != inverted.end()) {
            //if found, check if the current string k is longer than existing one
            //->: Dereferencing it, access the second member of the pair 
            //it是iterator //在 std::pair<const int, std::string>里first is the key(int), second is the value (std::string)
            if (it->second.size() < k.size()) {   // k is std::string
                inverted[v] = k; 
            } else {  
                // no change, current "k" isn't the longest string we've seen for this "v"
            }
        } else { 
            inverted.insert({v, k});//最开始为空存进来的时候就已经调换顺序, 所以dereference it的时候second是std::string, first is int
        }
    }

    return inverted;
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