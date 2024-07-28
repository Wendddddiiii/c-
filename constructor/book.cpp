#include <iostream>

using namespace std;

class Book {
public:
    string title;
    string author;
    int pages;

    //constructor
    Book() {
        title = "no title given";
        author = "no author";
        pages = 0;
    }
    Book(string Title, string Author, int Pages) {
        title = Title;
        author = Author;
        pages = Pages;
    }


};

int main() {
    Book book1("harry potter", "jk", 344);
    Book book2("house of cards", "xxx", 345);
    Book book3; 
    book2.title = "hunger games";
    cout << book1.title << endl;
    cout << book2.title << endl;
    cout << book3.title << endl;

    return 0;
}