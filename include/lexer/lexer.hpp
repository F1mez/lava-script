#pragma once

#include "token.hpp"

#include <vector>

namespace lexer {
    vector<tokens::token_struct> lexer(vector<string> source_code);
}