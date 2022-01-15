#include<iostream>

using namespace std;


class SpecialNode{
public:
    int data;
    SpecialNode* left;
    SpecialNode* right;
    SpecialNode* nextRight;
    SpecialNode(int data){
        this->data = data;
        left = NULL;
        right = NULL;
        nextRight = NULL;
    }
};

SpecialNode* connectNextRight(SpecialNode* root){
    SpecialNode* leftNode = root;
    while(leftNode!=nullptr and leftNode->left!=nullptr){
        SpecialNode* iter = leftNode;
        while(iter!=nullptr){
            iter->left->nextRight = iter->right;
            if(iter->nextRight!=nullptr){
                iter->right->nextRight = iter->nextRight->left;
            }
            iter = iter->nextRight;
        }
        leftNode = leftNode->left;
    }
    return root;
}

int main()
{
    return 0;
}