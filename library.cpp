#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cmath>
#include <functional>
#include <numeric>
namespace library_system {

class Book {
    // TODO: Implement the Book class
private:
    std::string title_;
    std::string author_;
    std::string isbn_;
    int year_;
public:
    //default constructor
    Book() = default;
    ~Book() = default;
    Book(std::string title, std::string author, std::string isbn, int year)
        : title_(std::move(title)), author_(std::move(author)), isbn_(std::move(isbn)), year_(year) {}

    auto set_title(const std::string& title) -> void {
        title_ = title;
    }
    auto get_title() const-> std::string {
        return title_;
    }
    auto set_isbn(const std::string& isbn) -> void {
        isbn_ = isbn;
    }
    auto get_isbn() const -> std::string {
        return isbn_;
    }
    auto set_author(const std::string& author)-> void {
        author_ = author;
    }
    auto get_author() const-> std::string {
        return author_;
    }
    auto set_year(int& year) -> void {
        year_ = year;
    }
    auto get_year() const -> int {
        return year_;
    }
    auto operator==(const Book& other) -> bool {
        return isbn_ == other.isbn_;
    } 
};

class Library {
private:
    // TODO: Choose appropriate container(s) for storing books
    std::vector<Book> library_;
public:
    Library() = default;
    ~Library() = default;

    // TODO: Declare member functions as specified in the requirements
    auto add_book(const Book& book) -> void {
        library_.push_back(book);
    }
    
    auto remove_book(const std::string& isbn) -> bool {
        auto it = std::remove_if(library_.begin(), library_.end(), [&isbn](const Book& book){return book.get_isbn() == isbn;});
        if(it != library_.end()) {
            library_.erase(it, library_.end());
            return true;
        }
        return false;
    }
    auto find_book(const std::string& isbn) -> Book* {
        auto it = std::find_if(library_.begin(), library_.end(), [&isbn](const Book& book){return book.get_isbn() == isbn;});
        return it != library_.end() ? &(*it) : nullptr;
    }

    auto find_books_by_author(const std::string& author) -> std::vector<Book*> {
        std::vector<Book*> result;
        for(auto& book: library_) {
            if(book.get_author() == author) {
                result.push_back(&book);
            }
        }
        return result;
    }
    auto book_count() const -> std::size_t {
        return library_.size();
    }

    auto sort_book(const Library& l) const -> std::vector<Book> {
        std::vector<Book> sorted_books = library_;
        std::sort(sorted_books.begin(), sorted_books.end(), [](const Book& a, const Book& b){return a.get_year() < b.get_year();});
        return sorted_books;
    }
    // TODO: Implement comparison operators
    auto operator==(const Library& other) const -> bool {
        return library_ == other.library_;
    }
    //copy constructor and assignment
    Library(Library& other) noexcept = default;
    Library& operator=(Library& other) noexcept = default;
    //move constructor and assignment
    Library(Library&& other) noexcept = default;
    Library& operator=(Library&& other) noexcept = default;

    //File I/O methods
    auto save_to_file(const std::string& filename) const -> bool {
        std::ofstream file(filename);
        if(!file) {return false;}
        for(const auto& book : library_) {
            file << book.get_title() << ", " << book.get_author() << ", "
                << book.get_isbn() << ", " << book.get_year() << "\n";
        }
        return true; 
    }

    auto load_from_file(const std::string& filename) -> bool{
        std::ifstream file(filename);
        if (!file) return false;
        library_.clear();
        std::string line, title, author, isbn;
        int year;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            if (std::getline(iss, title, ',') && std::getline(iss, author, ',') &&
                std::getline(iss, isbn, ',') && (iss >> year)) {
                library_.emplace_back(title, author, isbn, year);
            }
        }
        return true;
    }
    // TODO: Declare stream operators as friend functions
    friend std::ostream& operator<<(std::ostream& os, const Library& lib) {
        for(const auto& book : lib.library_) {
            os << book.get_title() << "by" << book.get_author() << "ISBN" << book.get_isbn() << "in" << book.get_year() << "\n";

        }
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Library& lib) {
        std::string title, author, isbn;
        int year;
        if (std::getline(is, title, ',') && std::getline(is, author, ',') &&
            std::getline(is, isbn, ',') && (is >> year)) {
            lib.add_book(Book(title, author, isbn, year));
        }
        return is;
    }

    // Get the total duration of all songs in the playlist
    // int get_total_duration() const {
    //     return std::accumulate(songs_.begin(), songs_.end(), 0, [](int total, const auto& song){return total + song->get_duration();});
    // }
};

} // namespace library_system
  


