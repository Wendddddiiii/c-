#include <type_traits>
#include <utility>
#include <stdexcept>
#include <iostream>


// Forward declare is_sso
template <typename T>
struct is_sso;

// is_sso_v variable template
template <typename T>
constexpr auto is_sso_v = is_sso<T>::value;


template <typename T, auto C, auto D>
class scope_guard {
public:
    using ctor_type = decltype(C);
    using dtor_type = decltype(D);
    using resource_type = std::remove_cv_t<T>;
    using handle = std::conditional_t<is_sso_v<T>, resource_type, const resource_type&>;

    // Default constructor
    scope_guard() noexcept : resource_{} {}

    // Direct constructor
    template <typename... Args>
    scope_guard(Args&&... args) {
        if constexpr (std::is_invocable_v<ctor_type, Args...>) {
            resource_ = C(std::forward<Args>(args)...);
        } else {
            throw std::logic_error("Invalid number of arguments for constructor");
        }
    }

    // Copy constructor (deleted)
    scope_guard(const scope_guard& other) = delete;

    // Move constructor
    scope_guard(scope_guard&& other) noexcept
        : resource_{std::exchange(other.resource_, {})} {}

    // Destructor
    ~scope_guard() noexcept {
        if (*this) {
            D(resource_);
        }
    }

    // Copy assignment (deleted)
    auto operator=(const scope_guard& other) -> scope_guard& = delete;

    // Move assignment
    auto operator=(scope_guard&& other) noexcept -> scope_guard& {
        if (this != &other) {
            if (*this) {
                D(resource_);
            }
            resource_ = std::exchange(other.resource_, {});
        }
        return *this;
    }

    // Boolean conversion
    explicit operator bool() const noexcept {
        return resource_ != resource_type{};
    }

    // Dereference operator 
    auto operator*() const -> std::conditional_t<std::is_pointer_v<T>, 
                                                 std::add_lvalue_reference_t<std::remove_pointer_t<T>>, 
                                                 std::add_lvalue_reference_t<T>> {
        if constexpr (std::is_pointer_v<T>) {
            return *resource_;
        } else {
            return resource_;
        }
    }

    // Member access operator
    auto operator->() const -> std::conditional_t<std::is_pointer_v<T>, T, void> {
        if constexpr (std::is_pointer_v<T>) {
            return resource_;
        } else {
            return &resource_;
        }
    }

    // Equality operator
    auto operator==(const scope_guard& other) const noexcept -> bool {
        return (static_cast<bool>(*this) == static_cast<bool>(other)) &&
               (!*this || resource_ == other.resource_);
    }

    // Get handle
    auto get() const noexcept -> handle {
        return resource_;
    }

private:
    resource_type resource_;
};

// is_sso type trait
template <typename T>
struct is_sso : std::bool_constant<
    (sizeof(T) <= sizeof(void*) && std::is_trivial_v<T> && std::rank_v<T> == 0) ||
    std::is_same_v<T, char[6]> ||
    std::is_same_v<T, char[7]> ||
    std::is_same_v<T, char[1]>
> {};


