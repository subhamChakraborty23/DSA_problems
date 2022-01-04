#include<iostream>
#include<vector>
#include<queue>


using namespace std;

class Node{
public:
    int data;
    vector<Node*> children;
    Node(int data){
        this->data = data;
    }

    void addChild(Node* child){
        children.push_back(child);
    }

    void print(){
        cout<<data<<" ";
        for(int i=0;i<children.size();i++){
            children[i]->print();
        }
    }
};

class NarryTree{
public:
    Node* root;
    NarryTree(int data){
        root = new Node(data);
    }

    void addChild(Node* parent,int data){
        Node* child = new Node(data);
        parent->addChild(child);
    }

    void print(){
        root->print();
    }

    vector<vector<int > > levelOrderTraversal(Node* root){

        queue<Node*> q;
        vector<vector<int > > result;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            vector<int > level;
            for(int i=0;i<size;i++){
                Node* node = q.front();q.pop();
                level.push_back(node->data);
                for(int j=0;j<node->children.size();j++){
                    q.push(node->children[j]);
                }
            }
            result.push_back(level);
        }
        return result;
    }
    
};

int main(){
    NarryTree tree(1);
    tree.addChild(tree.root,2);
    tree.addChild(tree.root,3);
    tree.addChild(tree.root,4);
    tree.addChild(tree.root,5);
    tree.addChild(tree.root,6);
    tree.addChild(tree.root,7);
    tree.addChild(tree.root,8);
    tree.addChild(tree.root,9);
    tree.addChild(tree.root,10);
    tree.addChild(tree.root,11);
    tree.addChild(tree.root,12);
    tree.addChild(tree.root,13);
    tree.addChild(tree.root,14);
    tree.addChild(tree.root,15);
    tree.addChild(tree.root,16);
    tree.addChild(tree.root,17);
    tree.addChild(tree.root,18);
    tree.addChild(tree.root,19);

    tree.print();  
    vector<vector<int > > result = tree.levelOrderTraversal(tree.root);

    for(auto &v:result){
        for(int &j:v){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    
    return 0;   
}