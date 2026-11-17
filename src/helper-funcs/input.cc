#include <helper/input.hpp>

#include <iostream>
using namespace std;

namespace helper {
    constexpr int NO_INPUT = 30;
    constexpr int TOO_MUCH_INPUT = 31;
    int input_check(int argc) {
        if (argc <= 1) {
            return NO_INPUT;
        }
    
        if (argc > 2) {
            return TOO_MUCH_INPUT;
        }

        return 0;
    }
}