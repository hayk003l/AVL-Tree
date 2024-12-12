#include "RLRotation.hpp"

Node* RLRotation(Node* root) {
    root->right = LLRotation(root->right);
    return RRRotation(root);
}