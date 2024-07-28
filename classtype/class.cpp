#include <iostream>

using namespace std;

class Book {
public:
    string title;
    string author;
    int pages;
};

int main() {

    Book book1;
    book1.title = "harry potter";
    book1.author = "jk";
    book1.pages = 344;

    Book book2;
    book2.title = "house of cards";
    book2.author = "xx";
    book2.pages = 364;
    book2.title = "hunger games";


    cout << book1.title << endl;
    cout << book2.title << endl;

    return 0;
}