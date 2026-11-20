#include "lexer/token.hpp"
#include <iostream>
#include <fstream>
#include <filesystem>
#include <unordered_set>
#include <vector>
using namespace std;

#include <all.hpp>

const unordered_set<string> file_ext = {
    ".ls",
    ".Ls",
    ".LS",
    ".Lavas",
    ".LavaS",
    ".Lvs",
    ".LvS",
    ".LVS",
    ".lavascript",
    ".Lavascript",
    ".LavaScript"
};

int main(int argc, char* argv[]) {
    // flags and input file
    int input_file_check = helper::input_check(argc);
    if (input_file_check != 0) {
        // FINALLY a use case for switch, lol xD
        switch (input_file_check) {
            case 30:
                cerr << "Not enough arguments!\n";
                return 30;
            case 31:
                cerr << "Overdose of arguments!\n";
                return 31;
        }
    }

    string filename = argv[1];

    if (filename == "-h" || filename == "--help") {
        cout << "Possible file extensions: \n";
        for (auto i: file_ext) {
            cout << i << '\n';
        }

        return 0;
    }
    // end of flags and input file


    // file extension check and open
    string extension = filesystem::path(filename).extension().string();
    
    if (file_ext.find(extension) == file_ext.end()) {
        cerr << "Wrong file extension! Expected .ls or other extensions, use -h(or --help) for help\n";
        return 32;
    }

    ifstream input_file(filename);
    if (!input_file.is_open()) {
        cerr << "Could not open file!\n";
        return 33;
    }
    // end of file extension check and open

    vector<string> source_code;
    string line;
    while (getline(input_file, line)) {
        source_code.push_back(line);
    }

    if (!source_code.size()) return 0;

    vector<tokens::token_struct> lexed =  lexer::lexer(source_code);
    
}
