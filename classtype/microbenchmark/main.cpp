#include <iostream>
#include <deque>
#include <list>
#include <vector>
#include <random>
#include <algorithm>
#include <numeric>
#include <chrono>

constexpr auto LOWER_BOUND = 0;
constexpr auto UPPER_BOUND = 500'000; // C++11 onwards allows ' as a number separator

struct timings {
    double list_avg_time;
    double deque_avg_time;
    double vec_avg_time;
};

/**
 * In the benchmark, the following steps need to be performed in-order:
 * 1. A container (can be any sequential container) needs to be filled with n_elems random numbers.
 * 2. This container of numbers needs to be copied to a std::list, std::deque, and std::vector.
 * 3. A number, n, to find needs to be randomly generated.
 * 4. The time it takes each of the containers to lookup n with std::find() should be recorded and stored.
 * 4. Steps 1 - 4 should be repeated n_repetitions times.
 * 5. Return a `timings` struct, where each member is the sum of that container's timings / n_repetitions.
 *
 * @param n_repetitions - the number of times the above procedure should be repeated.
 * @param n_elems - the number of elements to fill each container with
 */


// A useful function to generate random numbers in a mathematically sound way
auto rand() -> int
{
    static auto rd = std::random_device {}; // Will be used to obtain a seed for the random number engine
    static auto gen = std::mt19937(rd()); // Standard mersenne_twister_engine seeded with rd()
    static auto distrib = std::uniform_int_distribution<>(LOWER_BOUND, UPPER_BOUND);

    return distrib(gen);
}

auto make_nums(int n_elems) -> std::vector<int> {
    auto nums = std::vector<int>{};
    //reserve function is used to preallocate memory for the vector
    //convert n_elem from int to std::size_t, which is unsigned integral type
    // reserve  function is a member function of the std::vector  in stl
    nums.reserve(static_cast<std::size_t>(n_elems));
    //from 0 to n_elems - 1
    for (auto j = 0; j < n_elems; ++j)
        nums.push_back(rand());
    return nums;
}


auto microbenchmark_lookup(int n_repetitions, int n_elems) -> timings {
    using nanosecond_t = std::chrono::duration<double, std::nano>;

    //timing vectors
    auto l_timings = std::vector<double>{};
    auto d_timings = std::vector<double>{};
    auto v_timings = std::vector<double>{};

    //benchmark loop
    for (auto i = 0; i < n_repetitions; ++i) {
        auto nums = make_nums(n_elems);
        auto target = rand();
        
        auto l = std::list<int>{nums.begin(), nums.end()};
        auto d = std::deque<int>{nums.begin(), nums.end()};
        auto v = std::vector<int>{nums.begin(), nums.end()};

        {
            auto then = std::chrono::steady_clock::now();
            (void) std::find(l.begin(), l.end(), target);
            auto now = std::chrono::steady_clock::now();
            auto time_taken = std::chrono::duration_cast<nanosecond_t>(now - then).count();
            l_timings.push_back(time_taken);
        }   

        {
            auto then = std::chrono::steady_clock::now();
            (void) std::find(d.begin(), d.end(), target);
            auto now = std::chrono::steady_clock::now();
            auto time_taken = std::chrono::duration_cast<nanosecond_t>(now - then).count();
            d_timings.push_back(time_taken);
        }      

        {
            auto then = std::chrono::steady_clock::now();
            (void) std::find(v.begin(), v.end(), target);
            auto now = std::chrono::steady_clock::now();
            auto time_taken = std::chrono::duration_cast<nanosecond_t>(now - then).count();
            v_timings.push_back(time_taken);
        }
    }

    return timings {
        //use dot . to initialize the struct members by specifying their names explicitly within the {} initializer list. 
        .list_avg_time = std::accumulate(l_timings.begin(), l_timings.end(), 0.0) / static_cast<double>(n_repetitions),
        .deque_avg_time = std::accumulate(d_timings.begin(), d_timings.end(), 0.0) / static_cast<double>(n_repetitions),
        .vec_avg_time = std::accumulate(v_timings.begin(), v_timings.end(), 0.0) / static_cast<double>(n_repetitions)
    };
}

int main() {
    constexpr int N_REPS = 3;
    constexpr int N_ELEMS = 2'500'000; // 250k
    const auto &[l_time, d_time, v_time] = microbenchmark_lookup(N_REPS, N_ELEMS);
    
    // Output the average times for std::list, std::deque, and std::vector
    std::cout << l_time << " " << d_time << " " << v_time << std::endl;

}