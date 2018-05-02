//
// Created by Eyey on 2018/4/29.
//

#ifndef ARITHMETIC_BST_H
#define ARITHMETIC_BST_H


#include <iostream>

using namespace std;

template<typename Key, typename Value>
class BST {
private:


    struct Node {
        Key key;
        Value value;
        Node *left;
        Node *right;

        Node(Key key, Value value) {
            this->key = key;
            this->value = value;
            this->left = this->right = NULL;
        }
    };

    Node *insert(Node *node, Key key, Value value) {

        if (node == NULL) {
            count++;
            return new Node(key, value);
        }

        if (key == node->key)
            node->value = value;
        else if (key < node->key)
            node->left = insert(node->left, key, value);
        else    // key > node->key
            node->right = insert(node->right, key, value);

        return node;
    }

    int count;
    Node *root;

public:

    BST() {
        root = NULL;
        count = 0;
    }

    // 向二分搜索树中插入一个新的(key, value)数据对
    void insert(Key key, Value value) {
        root = insert(root, key, value);
    }


    //TODO
    void remove(Key key) {
        Node *parent = NULL;
        Node *temp = root;
        int dir = 0;
        while (temp != NULL) {
            if (temp->key == key) {
                break;
            } else if (temp->key > key) {
                parent = temp;
                temp = temp->left;
                dir = 1;

            } else {
                parent = temp;
                temp = temp->right;
                dir = 2;
            }
        }
        if (temp != NULL) {
            Node *replace = NULL;
            if (parent == NULL) {
                temp = NULL;
                return;
            } else if (temp->left == NULL) {
                replace = temp->right;
            } else if (temp->right == NULL) {
                replace = temp->left;
            } else {
                replace = min(temp);
            }
            if (dir == 1) {
                parent->left = replace;
            } else if (dir == 2) {
                parent->right = replace;
            }
        }
    }


    Node *min(Node *root) {
        Node *temp = root;
        while (temp != NULL && temp->left != NULL)
            temp = temp->left;
        return temp;
    }


    Node *find(Key key) {
        Node *temp = root;
        while (temp != NULL) {
            if (temp->key == key) {
                return temp;
            }
            if (key > temp->key) {
                temp = temp->right;
            }
            if (key < temp->key) {
                temp = temp->left;
            }
        }
        return NULL;
    }
};


#endif //ARITHMETIC_BST_H
