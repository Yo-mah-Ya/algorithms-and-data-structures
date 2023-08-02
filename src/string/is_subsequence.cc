#include <iostream>

/*
Given two strings s and t, return true if s is a subsequence of t, or false
otherwise. A subsequence of a string is a new string that is formed from the
original string by deleting some (can be none) of the characters without
disturbing the relative positions of the remaining characters. (i.e., "ace" is a
subsequence of "abcde" while "aec" is not).
*/
bool is_subsequence(std::string s, std::string t) {
    if (t.length() < s.length()) {
        return false;
    }
    int j = 0;
    for (size_t i = 0; i < t.length(); i++) {
        if (s[j] == t[i])
            j++;
        if (j == s.length()) {
            return true;
        }
    }
    return false;
}

int main(int argc, char const *argv[]) {
    assert(is_subsequence("abc", "ahbgdc"));
    assert(!is_subsequence("aaaaaa", "bbaaaa"));
    assert(!is_subsequence("axc", "ahbgdc"));

    return 0;
}
