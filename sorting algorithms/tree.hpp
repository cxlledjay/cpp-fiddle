#pragma once

#include <iostream>
#include <memory>
#include <vector>

namespace bst{

    template <class T>
    class Node{
        std::unique_ptr<Node> left;
        std::unique_ptr<Node> right;
        std::unique_ptr<T> data;

        public:
        Node(T data) : left(nullptr) , right(nullptr), data(std::make_unique<T>(data)) {}
        Node() : left(nullptr) , right(nullptr), data(nullptr) {} //empty

        void insert(T data){
            if(this->data == nullptr) this->data = std::make_unique<T>(data);
            else if(data < *(this->data)){
                if(left == nullptr) left = std::make_unique<Node>(data);
                else left->insert(data);
            } else {
                if(right == nullptr) right = std::make_unique<Node>(data);
                else right->insert(data);
            }
        }
        template <class U>
        friend void inorder(Node<U>* root, std::vector<U>& out);
    };

    template <class T>
    void inorder(Node<T>* root, std::vector<T>& out){
        if(root == nullptr || root->data == nullptr) return;
        inorder(root->left.get() , out);
        out.push_back(*(root->data));
        inorder(root->right.get() , out);
    }

}