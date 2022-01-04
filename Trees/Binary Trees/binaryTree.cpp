#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class TreeNode{
public:
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
    int getData(){
        return this->data;
    }
    void setData(int data){
        this->data = data;
    }
    TreeNode* getLeft(){
        return this->left;
    }
    void setLeft(TreeNode* left){
        this->left = left;
    }
    TreeNode* getRight(){
        return this->right;
    }
    void setRight(TreeNode* right){
        this->right = right;
    }
};

class BinaryTree{
private:
    void buildTree(vector<int> data){
        TreeNode* parent = root;
        for(int i=0;i<data.size();i++){
            if(data[i]!=-1){
                if(data[i]!=0){
                    addLeft(parent,data[i]);
                    parent = parent->getLeft();
                }
                else{
                    parent = root;
                }
            }
            else{
                parent = root;
            }
        }
    }
public:
    TreeNode* root;
    BinaryTree(vector<int> data){
        root = new TreeNode(data[0]);
        buildTree(data);
    }
    void addLeft(TreeNode* parent,int data){
        TreeNode* child = new TreeNode(data);
        parent->setLeft(child);
    }
    void addRight(TreeNode* parent,int data){
        TreeNode* child = new TreeNode(data);
        parent->setRight(child);
    }
    //for a proper binary tree N node N-1 edges N is odd and N-1 is even

    //perfect binary tree : all nodes have 2 children n nodes and n-1 edges (2^n-1)
    //complete binary tree : all nodes have 2 children except leaf nodes
    //full binary tree : all nodes have 2 children except leaf nodes
    
    
};