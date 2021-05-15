//
// Created by kobic on 5/15/2021.
//

#include <numeric>
#include <iterator>

[[nodiscard]]
auto better_sum_vals() {
    constexpr auto MAX = 10U;
    int a[MAX]{1, 2, 3, 4, 5, 6, 7, 8 /* the rest is 0's */}; // init if needed
    auto ret = 0ULL;
    // remember, algos will take a range
    ret = std::accumulate(std::begin(a), std::end(a), 0ULL);
    return ret;
}

[[nodiscard]]
auto sum_vals_range_loop() {
    constexpr auto MAX = 10U;
    int a[MAX]{1, 2, 3, 4, 5, 6, 7, 8 /* the rest is 0's */}; // init if needed
    auto val = 0U; // use auto
    for (const auto i : a) {
        val += i;
    }
    return val;
}

[[nodiscard]]
auto sum_vals() { // int?? maybe auto to let the compiler deduce ?
    constexpr auto MAX = 10U;
    int a[MAX]{1, 2, 3, 4, 5, 6, 7, 8 /* the rest is 0's */}; // init if needed
    auto val = 0U; // use auto
    for (int i=0; i < MAX; ++i) { // or std::size(a) if you are on 20's
        val += a[i];
    }
    return val;
}

int main() {
    return sum_vals() + sum_vals_range_loop() + better_sum_vals();
}
