#include <iostream>
#include <set>
std::string remove_deps(std::string str) {
    std::set<char> set;
    for (int i = 0; i < str.length(); i++) {
        set.insert(str[i]);
    }
    std::string result = "";
    for (auto s : set) {
        result += s;
    }
    return result;
}

int main(int argc, char const *argv[]) {
    std::cout << remove_deps("abcd") << std::endl;
    std::cout << remove_deps("aabbccdd") << std::endl;
    std::cout << remove_deps("abcddbca") << std::endl;
    std::cout << remove_deps("abababcdcdcd") << std::endl;

    return 0;
}
