#include <type_traits>

// Define a simple variadic template class Vector
template<int... Ns>
struct Vector {};

// Primary template for Prepend (not used but required by the compiler)
template<int, typename>
struct Prepend {};

// Specialization of Prepend for an int and a Vector of ints
template<int V, int... Ns>
struct Prepend<V, Vector<Ns...>> {
    using type = Vector<V, Ns...>;
};

// Static assertion to check if the Prepend works as expected
static_assert(std::is_same_v<Prepend<1, Vector<2, 3>>::type, Vector<1, 2, 3>>);


// Primary template for Append (not used but required by the compiler)
template<int, typename>
struct Append {};

// Specialization of Append for an int and a Vector of ints
template<int V, int... Ns>
struct Append<V, Vector<Ns...>> {
    using type = Vector<Ns..., V>;
};

// Static assertion to check if the Append works as expected
static_assert(std::is_same_v<typename Append<1, Vector<2, 3>>::type, Vector<2, 3, 1>>);

template<typename>
struct Popback {};

//if at last element
template<int V>
struct Popback<Vector<V>> {
    using type = Vector<>;
};

template<int H>
struct Popback<Vector<H>> {
    using type = Vector<>;
};


//pop back from vector with more than 1 elem
template<int H, int... Ns>
struct Popback<Vector<H, Ns...>> {
    using type = typename Prepend<H, typename Popback<Vector<Ns...>>::type>::type;
};

static_assert(std::is_same_v<typename Popback<Vector<2, 3, 1>>::type, Vector<2, 3>>);



int main() {
    return 0;
}
