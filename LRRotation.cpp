#include "LRRotation.hpp"

Node* LRRotation(Node* root) {
    root->left = RRRotation(root->left);
    return LLRotation(root);
}