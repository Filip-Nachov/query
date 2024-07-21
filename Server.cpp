#include <cctype>
#include <cstdio>
#include <iostream>
#include <string>
#include <type_traits>
using namespace std;

bool match_pattern(const string& input_line, const string& pattern) {
    if (pattern.length() == 1) {
        return input_line.find(pattern) != string::npos;
    }
    else if (pattern == "\\d") {
        for (const auto& c: input_line) {
            if (isdigit(c)) {
                return true;
            }
            else {
                return false;
            }
        }
    }
    else if (pattern == "\\w") {
        for (const auto& c: input_line) {
            if (isdigit(c) || isalpha(c)) {
                return true;
            }
            else {
                return false;
            }
        }
    }
    else if (pattern.at(0) == '[' && pattern.at(pattern.length() - 1) == ']') {
        return input_line.find_first_of(pattern) != string::npos;
    }
    else {
        throw runtime_error("Unhandled pattern " + pattern);
    }
}

int main(int argc, char* argv[]) {
    // Flush after every cout / cerr
    cout << unitbuf;
    cerr << unitbuf;


    if (argc != 3) {
        cerr << "Expected two arguments" << endl;
        return 1;
    }

    string flag = argv[1];
    string pattern = argv[2];

    if (flag != "-E") {
        cerr << "Expected first argument to be '-E'" << endl;
        return 1;
    }

    
    string input_line;
    getline(cin, input_line);
    
    try {
         if (match_pattern(input_line, pattern)) {
             printf("Match\n");
             return 0;
         } else {
            printf("Not Matching\n");       
            return 1;
         }
     } catch (const runtime_error& e) {
         cerr << e.what() << endl;
         return 1;
     }
}
