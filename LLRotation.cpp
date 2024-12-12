#include "LLRotation.hpp"
#include "height.hpp"

#include <algorithm>

Node* LLRotation(Node* root) {
    Node* tmp = root->left;
    root->left = tmp->right;
    tmp->right = root;

    root->height = std::max(heightTree(root->left), heightTree(root->right)) + 1;
    tmp->height = std::max(heightTree(tmp->left), root->height) + 1;

    return tmp;
}