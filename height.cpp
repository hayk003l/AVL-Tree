#include "height.hpp"

int heightTree(Node* root) {
    if (!root) {
        return -1;
    }
    return root->height;
}