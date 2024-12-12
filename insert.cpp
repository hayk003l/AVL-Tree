#include "node.hpp"

#include "height.hpp"
#include "getBalance.hpp"
#include "LLRotation.hpp"
#include "LRRotation.hpp"
#include "RRRotation.hpp"
#include "RLRotation.hpp"

#include <algorithm>

Node* insert(Node* root, int key) {
    if (!root) {
        root = new Node(key);
        return root;
    }

    if (key < root->val) {
        root->left = insert(root->left, key);
    }
    else if (key > root->val) {
        root->right = insert(root->right, key);
    }
    else {
        return root;
    }

    root->height = std::max(heightTree(root->left), heightTree(root->right)) + 1;

    int balance = getBalance(root);

    if (balance > 1 && key < root->left->val) {
        LLRotation(root);
    }

    if (balance > 1 && key > root->left->val) {
        LRRotation(root);
    }

    if (balance < -1 && key > root->right->val) {
        RRRotation(root);
    }

    if (balance < -1 && key < root->right->val) {
        RLRotation(root);
    }

    return root;
}
