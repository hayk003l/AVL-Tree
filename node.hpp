#pragma once

struct Node {
    int val = 0;
    Node* left = nullptr;
    Node* right = nullptr;
    int height = 0;
    Node(int value) : val(value) {

    }
};