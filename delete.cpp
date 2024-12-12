#include "node.hpp"

#include "height.hpp"
#include "getBalance.hpp"
#include "LLRotation.hpp"
#include "LRRotation.hpp"
#include "RRRotation.hpp"
#include "RLRotation.hpp"

#include <algorithm>

Node* minValue(Node* root) {
    if (!root) {
        return  nullptr;
    }

    Node* curr = root;

    while (curr->left) {
        curr = curr -> left;
    }
    return curr;
}

Node* deleteElem(Node* root, int key) {
    if (!root) {
        return nullptr;
    }

    if (key < root->val) {
        root->left = deleteElem(root->left, key);
    }
    else if (key > root->val) {
        root->right = deleteElem(root->right, key);
    }
    else {
        if (!root->left || !root->right) {
            Node* temp = root->left ? root->left : root->right;

            if (!temp) {
                temp = root;
                root = nullptr;
            }
            else {
                *root = *temp;
            }
            delete(temp);
        }
        else {
            Node* temp = minValue(root->right);

            root->val = temp->val;

            root->right = deleteElem(root->right, temp->val);
        }

        
    }

    if (!root) {
            return nullptr;
        }

    root->height = std::max(heightTree(root->right), heightTree(root->left)) + 1;

    int balance = getBalance(root);


    if (balance > 1 && getBalance(root->left) >= 0) {
        return LLRotation(root);
    }

    if (balance > 1 && getBalance(root->left) < 0) {
        return LRRotation(root);
    }

    if (balance < -1 && getBalance(root->right) <= 0) {
        return RRRotation(root);
    }

    if (balance < -1 && getBalance(root->right) > 0) {
        return RLRotation(root);
    }

    return root;
}