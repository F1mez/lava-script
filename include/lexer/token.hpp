#pragma once


#include <iostream>
using namespace std;

namespace tokens {
    // token types
    // TType is TokenType
 
    // i could technically do TType : unsigned char because it's so small(it saves 3 bytes)
    // but FUCK RAM ALTMAN
    enum TType {
        // short for "DECLARATION"
        DECL, // 0
        TYPE, // 1
        NAME, // 2
        EQU, // 3
        ERROR, // 4
        EMPTY, // 5
       
       // declaration types 
        D_INT, // 6
        D_BOOL, // 7
        D_STRING, // 8

        // actual types
        INT, // 9
        BOOL, // 10
        STRING, // 11

        OPERATOR // 12
    };

    struct token_struct {
        // there used to be a really long string here but i'll put it in test/stuff/token.txt
        string value;
        TType type;
        int line_num;
    };
}


