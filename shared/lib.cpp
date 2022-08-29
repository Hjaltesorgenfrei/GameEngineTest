#include "lib.hpp"

std::vector<int> Grades() {
    return {1, 2, 3, 4, 5};
}

int sum(std::vector<int>& values) {
    int result = 0;
    for (auto &v : values) {
        result += v;
    }
    return result;
}