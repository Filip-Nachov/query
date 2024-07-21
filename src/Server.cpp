#include <cctype>
#include <cstdio>
#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

// Helper to match single character pattern
bool handle_single_char_pattern(const string& input_line, const string& pattern) {
    return input_line.find(pattern) != string::npos;
}

// Helper to match digit pattern
bool handle_digit_pattern(const string& input_line) {
    return input_line.find_first_of("0123456789") != string::npos;
}

// Helper to match alphanumeric pattern
bool handle_alphanumeric_pattern(const string& input_line) {
    for (const auto& c : input_line) {
        if (isdigit(c) || isalpha(c)) {
            return true;
        }
    }
    return false;
}

// Helper to match character class pattern
bool handle_character_class_pattern(const string& input_line, const string& pattern) {
    return input_line.find_first_of(pattern.substr(1, pattern.length() - 2)) != string::npos;
}

// Helper to match any character pattern
bool handle_dot_pattern(const string& input_line) {
    return !input_line.empty();
}

// Helper to match repetition patterns (+ and *)
bool handle_repetition_patterns(const string& input_line, const string& pattern) {
    if (pattern.length() < 2) {
        throw runtime_error("Invalid repetition pattern: " + pattern);
    }

    char repeated_char = pattern[0];
    char repetition_type = pattern[1];

    if (repetition_type == '+') {
        return input_line.find(repeated_char) != string::npos;
    } else if (repetition_type == '*') {
        return true; // Any string will match zero or more occurrences
    } else {
        throw runtime_error("Unhandled repetition pattern: " + pattern);
    }
}

// Main pattern matching function
bool match_pattern(const string& input_line, const string& pattern) {
    if (pattern.length() == 1) {
        return handle_single_char_pattern(input_line, pattern);
    } else if (pattern == "\\d") {
        return handle_digit_pattern(input_line);
    } else if (pattern == "\\w") {
        return handle_alphanumeric_pattern(input_line);
    } else if (pattern == ".") {
        return handle_dot_pattern(input_line);
    } else if (pattern.at(0) == '[' && pattern.at(pattern.length() - 1) == ']') {
        return handle_character_class_pattern(input_line, pattern);
    } else if (pattern.length() > 1 && (pattern[1] == '+' || pattern[1] == '*')) {
        return handle_repetition_patterns(input_line, pattern);
    } else {
        throw runtime_error("Unhandled pattern: " + pattern);
    }
}

int main(int argc, char* argv[]) {
    // Flush after every cout / cerr
    cout << unitbuf;
    cerr << unitbuf;

    // Check for the correct number of arguments
    if (argc != 3) {
        cerr << "Expected two arguments" << endl;
        return 1;
    }

    string flag = argv[1];
    string pattern = argv[2];

    // Validate the flag
    if (flag != "-E") {
        cerr << "Expected first argument to be '-E'" << endl;
        return 1;
    }

    // Read input line from standard input
    string input_line;
    getline(cin, input_line);

    // Attempt pattern matching
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
