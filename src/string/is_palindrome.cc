
#include <assert.h>
#include <iostream>
#include <regex>

/*
Palindrome is a word, phrase, or sequence that reads the same backward as
forward,
*/
bool is_palindrome(std::string str) {
    std::regex re("\\W");
    std::string alphanumeric = std::regex_replace(str, re, "$1");

    int i = 0;
    int j = alphanumeric.length() - 1;
    while (i < j) {
        if (tolower(alphanumeric[i]) != tolower(alphanumeric[j]))
            return false;
        i++;
        j++;
    }
    return true;
}

int main(int argc, char const *argv[]) {
    assert(is_palindrome("awesome"));
    assert(is_palindrome("foobar"));
    assert(is_palindrome("tacocat"));
    assert(is_palindrome("amanaplanacanalpanama"));
    return 0;
}
