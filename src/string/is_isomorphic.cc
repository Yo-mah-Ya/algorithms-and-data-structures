#include <assert.h>

#include <iostream>
#include <map>

bool isIsomorphic(std::string s, std::string t) {
    if (s.length() != t.length()) {
        return false;
    }
    std::map<char, int> sMap;
    std::map<char, int> tMap;

    auto has_key = [&](std::map<char, int> &map, char key) {
        return map.find(key) != map.end();
    };

    for (int i = 0; i < s.length(); i++) {
        if (has_key(sMap, s[i])) {
            if (!has_key(tMap, t[i])) {
                return false;
            }
            if (sMap[s[i]] != tMap[t[i]]) {
                return false;
            }
        } else if (has_key(tMap, t[i])) {
            return false;
        }

        sMap[s[i]] = i;
        tMap[t[i]] = i;
    }
    return true;
}

int main(int argc, char const *argv[]) {
    assert(isIsomorphic("egg", "add"));
    assert(isIsomorphic("foo", "bar") == false);
    assert(isIsomorphic("paper", "title"));

    return 0;
}
