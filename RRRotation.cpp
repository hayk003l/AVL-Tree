#include "RRRotation.hpp"
#include "height.hpp"

#include <algorithm>

Node* RRRotation(Node* root) {
    Node* tmp = root->right;
    root->right = tmp->left;
    tmp->left = root;

    root->height = std::max(heightTree(root->left), heightTree(root->right)) + 1;
    tmp->height = std::max(heightTree(tmp->right), root->height) + 1;

    return tmp;
}