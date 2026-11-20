#include <helper/is_num.hpp>
#include <string>
#include <cctype>
#include <utility>

using namespace std;

namespace helper {
    // copied this thing on stack overflow
    // pretty good!
    pair<bool, int> is_num_int(const string& input) {
        try {
            int num = stoi(input);
            return {true, num};
        } catch (const exception&) {
            return {false, 0};
        }
    }
}