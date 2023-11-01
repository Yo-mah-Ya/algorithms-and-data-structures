#include <algorithm>
#include <iostream>
#include <vector>

typedef struct Node {
    size_t value;
    std::vector<Node> children;
} Node;

void recursive(Node &root_node, bool is_root) {
    if (is_root) {
        std::cout << root_node.value << std::endl;
    };
    for (auto child : root_node.children) {
        std::cout << child.value << std::endl;
        recursive(child, false);
    };
};

void loop(Node &root_node) {
    std::vector<Node> l{root_node};

    while (!l.empty()) {
        Node child = l.front();
        l.erase(l.begin());

        std::cout << child.value << std::endl;

        std::vector<Node> w;
        std::reverse_copy(child.children.begin(), child.children.end(), std::back_inserter(w));
        for (auto c : w) {
            l.insert(l.begin(), c);
        }
    };
};

int main(int argc, char const *argv[]) {
    Node data = {
        .value = 0,
        .children =
            {
                {
                    .value = 1,
                    .children =
                        {
                            {
                                .value = 2,
                                .children =
                                    {
                                        {.value = 3, .children = {}},
                                        {.value = 4, .children = {}},
                                    },
                            },
                            {
                                .value = 5,
                                .children =
                                    {
                                        {.value = 6, .children = {}},
                                        {.value = 7, .children = {}},
                                    },
                            },
                        },
                },
                {
                    .value = 8,
                    .children =
                        {
                            {.value = 9,
                             .children = {{.value = 10, .children = {}}}},
                            {.value = 11, .children = {}},
                        },
                },
            },
    };
    recursive(data, true);
    loop(data);
    return 0;
}
