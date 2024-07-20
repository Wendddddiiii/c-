#include <iostream>
#include <map>
#include <string>
//emplace:constructs the new element directly in the map's storage
// if the key deos not in map, insert new k v pair
// otherwise doing nothing and return a pair where the first element is an iterator to the existing element and second element is false

int main() {
    std::map<std::string, double> m;
    
    // Inserting a pair using insert
    std::pair<std::string, double> p1 {"bat", 1.78};
    m.insert(p1);

    // Inserting a pair using initializer list with insert
    //m.insert({"cat", 1.9011});

    // Inserting a pair using emplace
    m.emplace("cat", 1.9233);  // Correct usage of emplace

    // Printing the value associated with key "bat"
    std::cout << m["bat"] << std::endl;

    // Finding an element in the map
    auto it = m.find("cat");
    if (it != m.end()) {
        std::cout << "Found: " << it->first << " " << it->second << std::endl;
    } else {
        std::cout << "Key not found" << std::endl;
    }

    // Iterating over the map and printing all key-value pairs
    for (const std::pair<const std::string, double>& kv : m) {
        std::cout << kv.first << ' ' << kv.second << std::endl;
    }

    return 0;
}
