#include <iostream>
#include "math_utils.hpp"

int main() {
    int x = 5, y = 7;
    std::cout << "Sum: " << math_utils::add(x, y) << "\n";

    std::vector<int> nums = {1, 2, 3, 4, 5};
    std::cout << "Average: " << math_utils::average(nums) << "\n";

    return 0;
}
