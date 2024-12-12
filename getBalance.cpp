#include "getBalance.hpp"

int getBalance(Node* root) {
    if (!root) {
        return -1;
    }

    return heightTree(root->left) - heightTree(root->right);
}