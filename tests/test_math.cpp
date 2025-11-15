#include <iostream>
#include "math_utils.hpp"

int main() {
    if (math_utils::add(2, 3) != 5) {
        std::cerr << "Test failed: add(2,3)\n";
        return 1;
    }

    std::vector<int> nums = {2, 4, 6, 8};
    double avg = math_utils::average(nums);
    if (avg != 5.0) {
        std::cerr << "Test failed: average()\n";
        return 1;
    }

    std::cout << "All tests passed!\n";
    return 0;
}
