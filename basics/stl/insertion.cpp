//basic vector operators
//constructors vector<Elem> c; vector<Elem>c1(c2);
//simple methods v.size()//num items v.empty() //empty? ==, !=, <, >, <=, >=, //比较两个vector不是比较vector里面的东西 v.swap(v2)//交换两个vector 不是里面的东西 所有vector里的东西交换
//Iterators I.begin(), I.end()
//Element access v.at(index) v[index] v.front()// first item v.back()//last item
//add/remove/find v.push_back(e) // add a new element to the end of the container
//v.pop_back() //remove the last element from the container
//v.insert(pos, e) 
//Single Element Insertion: iterator insert(iterator pos, const T& value); value: The value of the element to be inserted.
//iterator insert(iterator pos, size_type count, const T& value); count: The number of elements to be inserted.
//Range insertion: template<class InputIt>//iterator insert(iterator pos, InputIt first, InputIt last); 
//Initializer list: iterator insert(iterator pos, std::initializer_list<T> ilist);
#include <iostream>
#include <vector>

int main() {
    std::vector<int> v = {1, 2, 3, 4, 5};

    // Single element insertion
    auto it = v.insert(v.begin() + 2, 10);
    // v now contains: 1, 2, 10, 3, 4, 5
    std::cout << "After single element insertion: ";
    for (int elem : v) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    // Fill insertion
    v.insert(v.begin() + 1, 3, 20);
    // v now contains: 1, 20, 20, 20, 2, 10, 3, 4, 5
    std::cout << "After fill insertion: ";
    for (int elem : v) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    // Range insertion
    std::vector<int> v2 = {7, 8, 9};
    v.insert(v.begin() + 4, v2.begin(), v2.begin()+3);
    // v now contains: 1, 20, 20, 20, 7, 8, 9, 2, 10, 3, 4, 5
    std::cout << "After range insertion: ";
    for (int elem : v) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    // Initializer list insertion
    v.insert(v.end(), {11, 12, 13});
    // v now contains: 1, 20, 20, 20, 7, 8, 9, 2, 10, 3, 4, 5, 11, 12, 13
    std::cout << "After initializer list insertion: ";
    for (int elem : v) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    return 0;
}



