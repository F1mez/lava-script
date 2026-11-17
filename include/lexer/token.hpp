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
        DECL,
        TYPE,
        NAME,
        EQU,
        COMMENT,
        ERROR,
        EMPTY,
        
        INT,
        BOOL,
        STRING
    };

    struct token_struct {
        // there used to be a really long string here but i'll put it in test/stuff/token.txt
        string value;
        TType type;
        int line_num;
    };
}


