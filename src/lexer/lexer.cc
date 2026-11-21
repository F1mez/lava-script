#include <lexer/token.hpp>
#include <lexer/lexer.hpp>
#include <helper/is_num.hpp>

#include <vector>
#include <string>
#include <unordered_map>

using namespace tokens;

namespace lexer {
    
    // I don't use tokens:: here is because i hate typing
    // basically too lazy
    unordered_map<string, tokens::TType> keywords = {
        {"set", DECL}, {"Set", DECL},
        {"int", D_INT}, {"Int", D_INT},
        {"bool", D_BOOL}, {"Bool", D_BOOL}, {"boolean", D_BOOL}, {"Boolean", D_BOOL},
        {"string", D_STRING}, {"String", D_STRING},
        {"=", EQU},
        {"+", OPERATOR}, {"-", OPERATOR}, {"*", OPERATOR}, {"/", OPERATOR},
        {"True", BOOL}, {"true", BOOL}, {"T", BOOL}, {"t", BOOL},
        {"False", BOOL}, {"false", BOOL}, {"F", BOOL}, {"f", BOOL}
    };
    vector<tokens::token_struct> lexed_code;
    vector<tokens::token_struct> lexer(vector<string> source_code) {
        int last_lexed_code = 0;
        string str;
        for (int line_num = 0; line_num < source_code.size(); ++ line_num) {
            const string line = source_code[line_num];

            if (line.empty()) {
                continue;
            }
            code:
            size_t value_position_1 = line.find_first_not_of(" \t\n", last_lexed_code);
            if (value_position_1 == string::npos) {
                last_lexed_code = 0;
                continue;
            }

            // This checks for string so we can tokenize it
            if (line[value_position_1] == '"') {
                size_t closing_quote = line.find('"', value_position_1 + 1);
            
                if (closing_quote == string::npos) {
                    lexed_code.push_back({"", ERROR, line_num});
                    last_lexed_code = 0;
                    continue;
                }
            
                string value = line.substr(
                    value_position_1,
                    closing_quote - value_position_1 + 1
                );
            
                lexed_code.push_back({value, STRING, line_num});
            
                last_lexed_code = closing_quote + 1;

                // can't go to jmp here for some reason :D
                if (last_lexed_code) {
                    goto code;
                }
            }

            size_t value_position_2 = line.find_first_of(" \t\n", value_position_1);
            if (value_position_2 == string::npos) {
                value_position_2 = line.size();
            }

            string value = line.substr(value_position_1, value_position_2 - value_position_1);       
            if (!last_lexed_code) {
                if (value == ";") {
                    continue;
                }
            }

        
            last_lexed_code = value_position_2 + 1;

            pair<bool, int> num = helper::is_num_int(value);

            if (keywords.contains(value)) {
                lexed_code.push_back({value, keywords[value], line_num});
                goto jmp;
            }

            else if (num.first) { // if it's a number
                lexed_code.push_back({value, INT, line_num});
                goto jmp;
            }
            
            else {
                // unlike the vector i would actually type
                // tokens::
                lexed_code.push_back({value, tokens::NAME, line_num});
            }  
            jmp:
                if (last_lexed_code) {
                    goto code;
                }
        }

        return lexed_code;
    }
}
