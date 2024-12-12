#include "node.hpp"
#include <algorithm>


int isAVL(Node* root) {
    if (!root) {
        return 0;
    }

    int left = isAVL(root->left);
    if (left == -1) {
        return -1;
    }

    int right = isAVL(root->right);
    if(right == -1) {
        return -1;
    }

    if(std::abs(right - left) > 1) {
        return -1;
    }

    return std::max(right, left) + 1;
}