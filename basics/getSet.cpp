#include <iostream>
using namespace std;


class Movie {
public:
    string title;
    string director;
    Movie(string aTitle, string aDirector, string aRating) {
        title = aTitle;
        director = aDirector;
        setRating(aRating);
    }

    void setRating(string aRating) {
        if(aRating == "pg" || aRating == "pg12") {
            rating = aRating;
        } else {
            rating = "nr";
        }
    }

    string getRating() {
        return rating;
    }
private:
    string rating;

};

int main() {
    Movie avengers("The Avengers", "Joss", "pg12");
    avengers.setRating("dog");
    cout << avengers.getRating() << endl;

    return 0;
}
