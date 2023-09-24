#include <assert.h>

#include <iostream>
#include <map>

bool is_isomorphic(std::string s, std::string t) {
    if (s.length() != t.length()) {
        return false;
    }
    std::map<char, int> s_map;
    std::map<char, int> t_map;

    auto has_key = [&](std::map<char, int> &map, char key) {
        return map.find(key) != map.end();
    };

    for (int i = 0; i < s.length(); i++) {
        if (has_key(s_map, s[i])) {
            if (!has_key(t_map, t[i])) {
                return false;
            }
            if (s_map[s[i]] != t_map[t[i]]) {
                return false;
            }
        } else if (has_key(t_map, t[i])) {
            return false;
        }

        s_map[s[i]] = i;
        t_map[t[i]] = i;
    }
    return true;
}

int main(int argc, char const *argv[]) {
    assert(is_isomorphic("egg", "add"));
    assert(is_isomorphic("foo", "bar") == false);
    assert(is_isomorphic("paper", "title"));

    return 0;
}
