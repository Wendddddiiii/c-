#ifndef COMP6771_ROPE_H
#define COMP6771_ROPE_H
//cbegin and cend provide constant iterators for forward traversal.
// crbegin and crend provide constant reverse iterators for backward traversal.
#include <string>
#include <vector>
#include <utility>//std::move

//model a reversible container
class rope {
    //model a bidirectional iterator
    class iter {
    public:
        //These using declarations define types used by the iterator
        using iterator_category = std::bidirectional_iterator_tag; // type of iterator:bidirectional
        using value_type = char;// type of value iterator points to: char
        using reference = const value_type&; // type of reference to the value
        using pointer = void;// void is becoz it is not used here
        using difference_type = std::ptrdiff_t;// difference between 2 iterators

        iter() = default;

        //move to next character
        auto operator++() -> iter& {
            ++inner_; // go to the next char within the current string
            //if hit the end of the string, and aren't at the end of the rope
            while(outer_ != last_ and inner_ == outer_->end()) {
                //go to the next string of the rope
                ++outer_;
                if(outer_ != last_) {
                    //look at the start of it
                    inner_ = outer_ -> begin();
                }
            }
            return *this;
        }

        //while loop is necessary to skip over empty strings and ensure that
        //inner_ always points to a valid character within a non-empty string or to the end of the rope

        //move to previous character
        auto operator--() -> iter& {
            // do it in the reverse way
            // if we are at the end, step back until we find a non-empty string
            // don't need to handle if they do not exist
            while(outer_ == last_ or inner_ == outer_->begin()) {
                --outer_;
                inner_ = outer_->end();
            }
            --inner_;
            //*this is a pointer to the object that called the member function. 
            // return a reference to the updated iterator.
            return *this;//When you dereference this pointer using *, you get a reference to the object itself.
        }
        
        //return a copy of the iterator before it was incremented or decremented.
        auto operator++(int) -> iter {
            auto old = *this;
            ++*this;
            return old;
        }
        auto operator--(int) -> iter {
			auto old = *this;
			--*this;
			return old;
		}

        //dereference operator, returns a reference to the character the iterator points to.
        auto operator*() const -> reference {
            return *inner_;
        }


        //compare the posistions in the outer_ and inner_
        friend auto operator==(const iter& lhs, const iter& rhs) -> bool {
            //make sure the "outer" is the same; if so
            return lhs.outer_ == rhs.outer_ and (lhs.outer_ ==  lhs.last_ or lhs.inner_ == rhs.inner_);
        }
    private:
        using outer_t = std::vector<std::string>::const_iterator; //first non-empty string
        using inner_t = std::string::const_iterator; //beginning of the string

		iter(outer_t first, outer_t last)
			: last_(last)
			, outer_(std::find_if_not(first, last, [](const auto &s) { return s.empty(); }))
			, inner_(outer_ == last_ ? inner_t{} : outer_->begin())
		{}

        outer_t last_ {};	// the end of the rope
		outer_t outer_ {};	// which string we're looking at, current string
		inner_t inner_ {};	// which character we're looking at in the string

        friend class rope; // allow it to access iter's private members
    };  

public:
    //iterator types;
    using iterator = iter;
    using const_iterator = iter;
    using reverse_iterator = std::reverse_iterator<iterator>;
    using const_reverse_iterator = std::reverse_iterator<const_iterator>;

	explicit rope(std::vector<std::string> rope) : rope_{std::move(rope)} {}

    //non-const begin/end
    auto begin() -> iterator {
        return {rope_.begin(), rope_.end()};
    }

    auto end() -> iterator {
        return {rope_.end(), rope_.end()};
    }

    //const begin/end; get cbegin/cend for free
    auto begin() const -> const_iterator {
        return { rope_.begin(), rope_.end()};
    }

    auto end() const -> const_iterator {
        return {rope_.end(), rope_.end()};
    }

    auto cbegin() const -> const_iterator {
        return begin();
    }

    auto cend() const -> const_iterator {
        return end();
    }

    // reverse iterators all come for free as well
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
	std::vector<std::string> rope_;

};

#endif // COMP6771_ROPE_H