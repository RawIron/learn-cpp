#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>


void ranges_views() {
    const std::vector elements{ 1,2,3,4,5,6,7,8,9 };

    auto is_even = [](int e) { return e%2 == 0; };
    for (const auto current : elements | std::views::filter(is_even)) {
        std::cout << current << " ";
    }
    std::cout << std::endl;
}

void ranges_sort() {
    std::vector vec{ -1, 2, -3, 4, -5, 6 };
    std::ranges::sort(vec);

    std::cout << "regular sort:" << std::endl;
    auto print = [](int i) { std::cout << i << ", "; };
    std::ranges::for_each(vec, print);
    std::cout << std::endl;
}

void ranges_input() {
    auto words = std::ranges::istream_view<std::string>(std::cin);
    for (const auto word : words) {
        std::cout << word << " ";
    }
}

template <std::ranges::range R>
auto to_vector(R&& r) {
    std::vector<std::ranges::range_value_t<R>> v{};

    if constexpr (requires { std::ranges::size(r); }) {
        v.reserve(std::ranges::size(r));
    }
    std::ranges::copy(r, std::back_inserter(v));

    return v;
}


int main() {
    ranges_sort();
    ranges_views();

    ranges_input();
}
