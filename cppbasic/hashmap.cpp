#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>


class CountryInfo {
private:
    std::unordered_map<std::string, std::vector<std::string>> country;

public:
    // add a country with info
    void addCountry(const std::string& code, const std::vector<std::string>& info){
        country[code] = info;
    }

    // get info
    std::vector<std::string> getInfo(const std::string& code) const {
        auto it = country.find(code);
        if (it != country.end()) {
            return it-> second;
        }
        return {}; // return empty if it not found
    }

    // check if a country code exists
    bool hasCountry(const std::string& code) const {
        return country.find(code) != country.end();
    }

    // print all countries and their info
    void printAllCountries() const {
        for(const auto& pair: country) {
            std::cout << "country code: " << pair.first << std::endl;
            for (const auto& info : pair.second) {
                std::cout << info << ", ";
            }
            std::cout << std::endl << std::endl;
        }
    }
};

int main() {
    CountryInfo countries;

    countries.addCountry("AU", {"Australia", "Australian Dollar"});
    countries.addCountry("US", {"United States", "US Dollar"});
    countries.addCountry("JP", {"Japan", "Japanese Yen"});

    std::cout << "All" << std::endl;
    countries.printAllCountries();

    //for a specific country

    std::string code = "AU";
    if(countries.hasCountry(code)) {
        std::vector<std::string> info = countries.getInfo(code);
        std::cout << "Info for: " << code << std::endl;
        for (const auto& item : info) {
            std::cout << item << std::endl;
        }
    } else {
        std::cout << "country not found" << code << std::endl;
    }

    return 0;
}