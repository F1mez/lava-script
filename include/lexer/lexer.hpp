#pragma once

#include "token.hpp"

#include <vector>
#include <string>
using namespace std;

namespace lexer {
    vector<tokens::token_struct> lexer(vector<string> source_code);
}