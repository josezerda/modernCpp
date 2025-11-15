#include "math_utils.hpp"
#include <numeric>

namespace math_utils {

int add(int a, int b) {
    return a + b;
}

double average(const std::vector<int>& values) {
    if (values.empty()) return 0.0;
    double sum = std::accumulate(values.begin(), values.end(), 0.0);
    return sum / values.size();
}

}
