#ifndef COMP6771_ZIP_H
#define COMP6771_ZIP_H

#include <vector>
#include <iterator>

using ivec = std::vector<int>;

//reversible container
class zip {
    // a random access iterator
    class iter {
        friend zip;
    public:
        using iterator_category = std::random_access_iterator_tag;
        using value_type = std::pair<int, int>;
        using reference = std::pair<int, int>;
        using pointer = void;
        using difference_type = std::ptrdiff_t;//difference between 2 pointers 

        iter() = default;//provides a default constructor for the iter class

        //Dereference Operator
        reference operator*() const {
            return (*this)[0];//returns value pointed by the iterator
            //here it uses the operator[] to return a pair of integers
        }

        //arrow operator: used to access members of an object through a pointer
        // if p is a pointer to an object of a class, p->member is used to access the member of that object
        //which is equivalent to (*p).member, but easier
        //-> is used to access members of the value pointed to by the iterator
        pointer operator->() const {/*do nothing*/}

        //prefix increment 
        iter &operator++() {
            ++ix_;
            return *this;//return by reference to the modified object 
        }
        

        //postfix increment 
        iter operator++(int) {
            auto self = *this; //create a copy of the object 
            ++*this;//modify the original object 
            return self;//return the copy
        }
        //prefix decrement 
        iter &operator--() {
            --ix_;
            return *this;
        }

        //postfix decrement 
        iter operator--(int) {
            auto self = *this;
            --*this;//decrement the original 
            return self;//return the copy 
        }


        //move forward by n positions
        iter &operator+=(int n) {
            ix_ += static_cast<std::size_t>(n);
            return *this;
        }

        //move backward by n positions
        iter &operator-=(int n) {
            ix_ -= static_cast<std::size_t>(n);
            return *this;
        }

        //subscript operator: operator[] allows objects of a class to be accessed using the array subscript syntax
        //using reference instead of auto: allows the function to return a specific type
        reference operator[](int n) const {
            std::size_t N = static_cast<std::size_t>(n);
            return std::make_pair((*l_)[ix_ + N], (*r_)[ix_ + N]);
        }

        friend iter operator+(iter i, int n) {
            return i += n;
        }

        friend iter operator+(int n, iter i) {
            return i + n;
        }


        friend iter operator-(iter i, int n) {
            return i -= n;
        }

        friend iter operator-(int n, iter i) {
            return i - n;
        }

        friend difference_type operator-(iter l, iter r) {
            return static_cast<difference_type>(l.ix_ - r.ix_);
        }

        // spaceship operator automatically generate all comparison operators (==, !=, <, >, <=, >=) for the iterator.
        auto operator<=>(const iter &) const = default;


    private:
        iter(const ivec *l, const ivec *r, std::size_t ix) : l_{l}, r_{r}, ix_{ix} {}

        const ivec *l_;
        const ivec *r_;
        std::size_t ix_; // keep track of the current position in the iteration process
    };

public:
    using iterator = iter;
    using const_iterator = iter;
    using reverse_iterator = std::reverse_iterator<iterator>;
    using const_reverse_iterator = std::reverse_iterator<const_iterator>;

    zip() = default;

    zip(const ivec &rng1, const ivec &rng2)
    : lhs_{&rng1}, rhs_{&rng2}, len_{std::min(rng1.size(), rng2.size())}{}

    auto begin() -> iterator {
        return {lhs_, rhs_, 0};//0: initial index for the beginning of the iterator
    }

    auto end() -> iterator {
        return {lhs_, rhs_, len_ };//length (or size) of the zipped range
    }

    // Returns a constant iterator to the beginning and end
    //These functions are const, meaning they can be called on a constant object and do not modify the object.
    auto begin() const -> const_iterator {
		return { lhs_, rhs_, 0 };
	}

	auto end() const -> const_iterator {
		return { lhs_, rhs_, len_ };
	}

    // Convenience functions that call the begin() and end() functions.
    // returned iterator should be treated as constant.
	auto cbegin() const -> const_iterator {
		return begin();
	}

	auto cend() const -> const_iterator {
		return end();
	}


    auto rbegin() -> reverse_iterator {
		return reverse_iterator{ end() };
	}
	
	auto rend() -> reverse_iterator {
		return reverse_iterator{ begin() };
	}
	
	auto rbegin() const -> const_reverse_iterator {
		return const_reverse_iterator{ end() };
	}
	
	auto rend() const -> const_reverse_iterator {
		return const_reverse_iterator{ begin() };
	}
	
	auto crbegin() const -> const_reverse_iterator {
		return rbegin();
	}
	
	auto crend() const -> const_reverse_iterator {
		return rend();
	}

private:
    const ivec *lhs_;
    const ivec *rhs_;
    std::size_t len_;
};

#endif // COMP6771_ZIP_H

//return by value:a copy of the object is created and returned
//This involves calling the copy constructor and possibly the destructor, which can be costly for large objects.
//Returning by reference: returning a reference to the original object.