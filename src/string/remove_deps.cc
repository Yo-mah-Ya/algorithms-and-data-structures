#include <iostream>
#include <set>
std::string removeDeps(std::string str) {
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
    std::cout << removeDeps("abcd") << std::endl;
    std::cout << removeDeps("aabbccdd") << std::endl;
    std::cout << removeDeps("abcddbca") << std::endl;
    std::cout << removeDeps("abababcdcdcd") << std::endl;

    return 0;
}
