
// ferrari(const std::string &owner, int modelno)
// This constructor should initialise the object state to keep track of 
//the owner name and model number. Speed is initially 0.

// ferrari()
// This constructor should default-initialise the object's state so that its owner name is "unknown"
// and its model number is 6771. Speed is initially 0.

// std::pair<std::string, int> get_details().
// Returns this Ferrari's owner and model number.

// void drive(int spd).
// Start driving at speed spd. If no speed is given, it should default to 88.


// std::string vroom().
// Returns a string depending on how fast this Ferrari is currently moving.
// If the speed is strictly less than 20, it should return the empty string. 
//If 20 <= speed < 80, it should return "vroom!!". Otherwise, it should return "VROOOOOOOOM!!!".
#include <string>
#include <utility>

class ferrari {
public: 
    //there are 3 constructors defined
    //delegate: When someone asks for a Ferrari without giving any information, call the private constructor and tell it to use 'unknown' as the owner, 6771 as the model number, and 0 as the speed
    //1.default constructor, this delegates to the private constructor with default values
    ferrari() : ferrari("unknown", 6771, 0) {}
    //2.two-parameters constructor
    //This also delegates to the private constructor, setting speed to 0.

    ferrari(const std::string &owner, int modelno) : ferrari(owner, modelno, 0) {}

    //member functions
    auto get_details() const -> std::pair<std::string, int> {
        return std::make_pair(owner_, modelno_);
    }

    auto drive(int spd = 88) -> void {
        speed_ = spd;
    }

    auto vroom() const -> std::string {
        if (speed_ < 20) {
            return "";
        } else if (speed_ < 80) {
            return "vroom!!";
        } else {
            return "vrooooom";
        }
    } 
private:
    // 3. 3-parameters constructor
    // member initializer list
    // Direct initialization avoids an extra step of default construction followed by assignment.
    ferrari(const std::string &owner, int modelno, int spd): owner_{owner}, modelno_{modelno}, speed_{spd}{}

    //private member variables
    //store the state of the ferrari object
    std::string owner_;
    int modelno_;
    int speed_;
}; 