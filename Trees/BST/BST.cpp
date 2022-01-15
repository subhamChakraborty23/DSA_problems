#include<iostream>
#include<queue>

using namespace std;


class BSTNode{
public:
    int data;
    BSTNode* left;
    BSTNode* right;
    BSTNode(int data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

class BST{
public:
    BSTNode* root;
    BST(){
        root = NULL;
    }
    void insert(int data){
        if(root==NULL){
            root = new BSTNode(data);
        }
        else{
            BSTNode* iter = root;
            while(iter!=NULL){
                if(data<iter->data){
                    if(iter->left==NULL){
                        iter->left = new BSTNode(data);
                        break;
                    }
                    else{
                        iter = iter->left;
                    }
                }
                else{
                    if(iter->right==NULL){
                        iter->right = new BSTNode(data);
                        break;
                    }
                    else{
                        iter = iter->right;
                    }
                }
            }
        }
    }

    //build bst from a vector
    void buildBST(vector<int>& v){
        for(int i=0;i<v.size();i++){
            insert(v[i]);
        }
    }

    void inorder(BSTNode* root){
        if(root==NULL){
            return;
        }
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
    void preorder(BSTNode* root){
        if(root==NULL){
            return;
        }
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
    void postorder(BSTNode* root){
        if(root==NULL){
            return;
        }
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
    void levelorder(BSTNode* root){
        if(root==NULL){
            return;
        }
        queue<BSTNode*> q;
        q.push(root);
        while(!q.empty()){
            BSTNode* iter = q.front();
            q.pop();
            cout<<iter->data<<" ";
            if(iter->left!=NULL){
                q.push(iter->left);
            }
            if(iter->right!=NULL){
                q.push(iter->right);
            }
        }
    }

    

    //search a node in a bst
    bool search(int data){
        if(root==NULL){
            return false;
        }
        BSTNode* iter = root;
        while(iter!=NULL){
            if(iter->data==data){
                return true;
            }
            if(data<iter->data){
                iter = iter->left;
            }
            else{
                iter = iter->right;
            }
        }
        return false;
    }

    //delete a node in a bst
    void deleteNode(int data){
        if(root==NULL){
            return;
        }
        BSTNode* parent = NULL;
        BSTNode* iter = root;
        while(iter!=NULL){
            if(iter->data==data){
                break;
            }
            parent = iter;
            if(data<iter->data){
                iter = iter->left;
            }
            else{
                iter = iter->right;
            }
        }
        if(iter==NULL){
            return;
        }
        if(iter->left==NULL and iter->right==NULL){
            if(parent==NULL){
                root = NULL;
            }
            else if(parent->left==iter){
                parent->left = NULL;
            }
            else{
                parent->right = NULL;
            }
        }
        else if(iter->left==NULL or iter->right==NULL){
            if(iter->left==NULL){
                if(parent==NULL){
                    root = iter->right;
                }
                else if(parent->left==iter){
                    parent->left = iter->right;
                }
                else{
                    parent->right = iter->right;
                }
            }
            else{
                if(parent==NULL){
                    root = iter->left;
                }
                else if(parent->left==iter){
                    parent->left = iter->left;
                }
                else{
                    parent->right = iter->left;
                }
            }
        }
        else{
            BSTNode* succ = iter->right;
            while(succ->left!=NULL){
                succ = succ->left;
            }
            iter->data = succ->data;
            if(succ->right==NULL){
                if(parent==NULL){
                    root = succ->left;
                }
                else if(parent->left==succ){
                    parent->left = succ->left;
                }
                else{
                    parent->right = succ->left;
                }
            }
            else{
                if(parent==NULL){
                    root =  succ->right;
                }
                else if(parent->left==succ){
                    parent->left = succ->right;
                }
                else{
                    parent->right = succ->right;
                }
            }
        }
    }



    //find the minimum value in the tree
    int findMin(BSTNode* root){
        if(root==NULL){
            return INT_MAX;
        }
        if(root->left==NULL){
            return root->data;
        }
        return findMin(root->left);
    }

    //find the maximum value in the tree
    int findMax(BSTNode* root){
        if(root==NULL){
            return INT_MIN;
        }
        if(root->right==NULL){
            return root->data;
        }
        return findMax(root->right);
    }
    //searching in balanced binary search tree is order of N


    //check bst
    bool isBST(BSTNode* root){
        if(root==NULL){
            return true;
        }
        if(root->left!=NULL and root->left->data>root->data){
            return false;
        }
        if(root->right!=NULL and root->right->data<root->data){
            return false;
        }
        if(!isBST(root->left) or !isBST(root->right)){
            return false;
        }
        return true;
    }

    //recover bst
    void recoverBST(BSTNode* root){
        if(root==NULL){
            return;
        }
        BSTNode* parent = NULL;
        BSTNode* iter = root;
        while(iter!=NULL){
            if(iter->left!=NULL and iter->left->data>iter->data){
                break;
            }
            parent = iter;
            iter = iter->left;
        }
        if(iter==NULL){
            return;
        }
        BSTNode* succ = iter->right;
        while(succ->left!=NULL){
            succ = succ->left;
        }
        iter->data = succ->data;
        if(succ->right==NULL){
            if(parent==NULL){
                root = succ->left;
            }
            else if(parent->left==succ){
                parent->left = succ->left;
            }
            else{
                parent->right = succ->left;
            }
        }
        else{
            if(parent==NULL){
                root =  succ->right;
            }
            else if(parent->left==succ){
                parent->left = succ->right;
            }
            else{
                parent->right = succ->right;
            }
        }
    }
};