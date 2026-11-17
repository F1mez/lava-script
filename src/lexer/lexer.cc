#include "lexer/token.hpp"
#include <chrono>
#include <lexer/lexer.hpp>

#include <vector>
#include <string>
#include <unordered_map>

using namespace tokens;

namespace lexer {
    unordered_map<string, tokens::TType> keywords = {
        {"set", DECL}, {"Set", DECL},
        {"int", INT}, {"Int", INT},
        {"bool", BOOL}, {"Bool", BOOL}, {"boolean", BOOL}, {"Boolean", BOOL},
        {"string", STRING}, {"String", STRING}, {"str", STRING}, {"String", STRING},
        {"=", EQU}
    };
    vector<tokens::token_struct> lexed_code;
    vector<tokens::token_struct> lexer(vector<string> source_code) {
        int last_lexed_code = 0;
        for (int i = 0; i < source_code.size(); ++ i) {
            const string line = source_code[i];

            if (line.empty()) {
                continue;
            }
            int value_position_1 = line.find_first_not_of(" \t\n", last_lexed_code);
            if (value_position_1 == string::npos) {
                last_lexed_code = 0;
                continue;
            }
            
            int value_position_2 = line.find_first_of(" \t\n", value_position_1);
            if (value_position_2 == string::npos) {
                last_lexed_code = 0;
                continue;
            }
            last_lexed_code = value_position_2 + 1;

            
        }
    }
}