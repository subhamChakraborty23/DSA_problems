#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>

using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
    int getData()
    {
        return this->data;
    }
    void setData(int data)
    {
        this->data = data;
    }
    TreeNode *getLeft()
    {
        return this->left;
    }
    void setLeft(TreeNode *left)
    {
        this->left = left;
    }
    TreeNode *getRight()
    {
        return this->right;
    }
    void setRight(TreeNode *right)
    {
        this->right = right;
    }
};

class BinaryTree
{
private:
    void buildTree(vector<int> data)
    {
        TreeNode *parent = root;
        for (int i = 0; i < data.size(); i++)
        {
            if (data[i] != -1)
            {
                if (data[i] != 0)
                {
                    addLeft(parent, data[i]);
                    parent = parent->getLeft();
                }
                else
                {
                    parent = root;
                }
            }
            else
            {
                parent = root;
            }
        }
    }

public:
    TreeNode *root;
    BinaryTree(vector<int> data)
    {
        root = new TreeNode(data[0]);
        buildTree(data);
    }
    void addLeft(TreeNode *parent, int data)
    {
        TreeNode *child = new TreeNode(data);
        parent->setLeft(child);
    }
    void addRight(TreeNode *parent, int data)
    {
        TreeNode *child = new TreeNode(data);
        parent->setRight(child);
    }
    // for a proper binary tree N node N-1 edges N is odd and N-1 is even

    // perfect binary tree : all nodes have 2 children n nodes and n-1 edges (2^n-1)
    // complete binary tree : all nodes have 2 children except leaf nodes
    // full binary tree : all nodes have 2 children except leaf nodes

    // binary tree : all nodes have 0 or 2 children

    void recPreOrder(TreeNode *root)
    {
        if (root != NULL)
        {
            // process root first
            cout << root->getData() << " ";

            recPreOrder(root->getLeft());
            recPreOrder(root->getRight());
        }
    }

    void recInOrder(TreeNode *root)
    {
        if (root != NULL)
        {
            recInOrder(root->getLeft());
            // process root second
            cout << root->getData() << " ";
            recInOrder(root->getRight());
        }
    }

    void recPostOrder(TreeNode *root)
    {
        if (root != NULL)
        {
            recPostOrder(root->getLeft());
            recPostOrder(root->getRight());
            // process root third
            cout << root->getData() << " ";
        }
    }

    vector<int> iterPreOrder(TreeNode *root)
    {
        vector<int> result;
        if (root != NULL)
        {
            stack<TreeNode *> s;
            s.push(root);
            while (!s.empty())
            {
                TreeNode *temp = s.top();
                s.pop();
                result.push_back(temp->getData());
                if (temp->getRight() != NULL)
                {
                    s.push(temp->getRight());
                }
                if (temp->getLeft() != NULL)
                {
                    s.push(temp->getLeft());
                }
            }
        }
        return result;
    }

    vector<int> iterInOrder(TreeNode *root)
    {
        vector<int> result;
        if (root != NULL)
        {
            stack<TreeNode *> s;
            TreeNode *temp = root;
            while (temp != NULL || !s.empty())
            {
                while (temp != NULL)
                {
                    s.push(temp);
                    temp = temp->getLeft();
                }
                temp = s.top();
                s.pop();
                result.push_back(temp->getData());
                temp = temp->getRight();
            }
        }
        return result;
    }

    vector<int> iterPostOrder(TreeNode *root)
    {
        vector<int> result;
        if (root != NULL)
        {
            stack<TreeNode *> s;
            s.push(root);
            while (!s.empty())
            {
                TreeNode *temp = s.top();
                s.pop();
                result.push_back(temp->getData());

                if (temp->getLeft() != NULL)
                {
                    s.push(temp->getLeft());
                }
                if (temp->getRight() != NULL)
                {
                    s.push(temp->getRight());
                }
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }

    vector<int> iterLevelOrder(TreeNode *root)
    {
        vector<int> result;
        if (root != NULL)
        {
            queue<TreeNode *> q;
            q.push(root);
            while (!q.empty())
            {
                TreeNode *temp = q.front();
                q.pop();
                result.push_back(temp->getData());
                if (temp->getLeft() != NULL)
                {
                    q.push(temp->getLeft());
                }
                if (temp->getRight() != NULL)
                {
                    q.push(temp->getRight());
                }
            }
        }
        return result;
    }

    int height(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        int leftHeight = height(root->getLeft());
        int rightHeight = height(root->getRight());
        return max(leftHeight, rightHeight) + 1;
    }

    void invertTree(TreeNode *root)
    {
        if (root != NULL)
        {
            TreeNode *temp = root->getLeft();
            root->setLeft(root->getRight());
            root->setRight(temp);
            invertTree(root->getLeft());
            invertTree(root->getRight());
        }
    }

    bool isMirrorImage(TreeNode *root1, TreeNode *root2)
    {
        if (root1 == NULL && root2 == NULL)
        {
            return true;
        }
        if (root1 == NULL || root2 == NULL)
        {
            return false;
        }
        return (root1->getData() == root2->getData()) && isMirrorImage(root1->getLeft(), root2->getRight()) && isMirrorImage(root1->getRight(), root2->getLeft());
    }

    bool isSymmetric(TreeNode *root)
    {
        if (root == NULL)
        {
            return true;
        }
        return isMirrorImage(root->getLeft(), root->getRight());
    }

    bool isBST(TreeNode *root)
    {
        if (root == NULL)
        {
            return true;
        }
        if (root->getLeft() != NULL && root->getLeft()->getData() > root->getData())
        {
            return false;
        }
        if (root->getRight() != NULL && root->getRight()->getData() < root->getData())
        {
            return false;
        }
        return isBST(root->getLeft()) && isBST(root->getRight());
    }

    int diameterOfTree(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        int leftHeight = height(root->getLeft());
        int rightHeight = height(root->getRight());
        int leftDiameter = diameterOfTree(root->getLeft());
        int rightDiameter = diameterOfTree(root->getRight());
        return max(leftHeight + rightHeight, max(leftDiameter, rightDiameter));
    }

    int diameterOfTreeIter(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        int result = 0;
        stack<TreeNode *> s;
        s.push(root);
        while (!s.empty())
        {
            TreeNode *temp = s.top();
            s.pop();
            if (temp->getLeft() != NULL)
            {
                s.push(temp->getLeft());
            }
            if (temp->getRight() != NULL)
            {
                s.push(temp->getRight());
            }
            result = max(result, (int)s.size());
        }
        return result;
    }

    class diameterOfTreeResult
    {
    public:
        int height;
        int diameter;
    };
    // O(n)
    diameterOfTreeResult diameterOfTreeRec(TreeNode *root)
    {
        if (root == NULL)
        {
            diameterOfTreeResult result;
            result.height = 0;
            result.diameter = 0;
            return result;
        }
        diameterOfTreeResult leftResult = diameterOfTreeRec(root->getLeft());
        diameterOfTreeResult rightResult = diameterOfTreeRec(root->getRight());
        diameterOfTreeResult result;
        result.height = max(leftResult.height, rightResult.height) + 1;
        result.diameter = max(leftResult.height + rightResult.height + 1, max(leftResult.diameter, rightResult.diameter));
        return result;
    }

    int heightDp(TreeNode *root, unordered_map<TreeNode *, int> &map)
    {
        if (root == NULL)
            return 0;

        if (map.find(root) != map.end())
            return map[root];

        int left = heightDp(root->left, map);
        int right = heightDp(root->right, map);

        int ans = max(left, right) + 1;

        map[root] = ans;
        return map[root];
    }

    bool isBalancedUtil(TreeNode *root)
    {
        if (root == NULL)
            return true;
        unordered_map<TreeNode *, int> map;
        int lh = heightDp(root->left, map);
        int rh = heightDp(root->right, map);

        int diff = abs(lh - rh);
        if (diff <= 1 and isBalancedUtil(root->left) and isBalancedUtil(root->right))
            return true;
        else
            return false;
    }

    class isHeightBalanced
    {
    public:
        int height;
        bool isBalanced;
        isHeightBalanced(int h, bool b)
        {
            height = h;
            isBalanced = b;
        }
    };

    isHeightBalanced isHeightBal(TreeNode *root)
    {
        if (root == NULL)
        {
            return isHeightBalanced(0, true);
        }
        isHeightBalanced left = isHeightBal(root->getLeft());
        isHeightBalanced right = isHeightBal(root->getRight());
        if (abs(left.height - right.height) > 1)
        {
            return isHeightBalanced(max(left.height, right.height), false);
        }
        return isHeightBalanced(max(left.height, right.height) + 1, true);
    }

    bool isBalanced(TreeNode *root)
    {
        if (root == NULL)
        {
            return true;
        }
        isHeightBalanced result = isHeightBal(root);
        return result.isBalanced;
    }
    ///////VERTICAL ORDER TRAVERSAL////////////
    void getVerticalOrder(TreeNode *root, int level, map<int, vector<int> > &m)
    {
        if (root == NULL)
        {
            return;
        }
        m[level].push_back(root->getData());
        getVerticalOrder(root->getLeft(), level - 1, m);
        getVerticalOrder(root->getRight(), level + 1, m);
    }

    vector<vector<int> > verticalOrder(TreeNode *root)
    {
        map<int, vector<int> > m;
        getVerticalOrder(root, 0, m);
        vector<vector<int> > result;
        for (auto it = m.begin(); it != m.end(); it++)
        {
            result.push_back(it->second);
        }
        return result;
    }

    vector<int> topView(TreeNode *root)
    {
        map<int, vector<int> > m;
        getVerticalOrder(root, 0, m);
        vector<int> result;
        for (auto it = m.begin(); it != m.end(); it++)
        {
            result.push_back(it->second[0]);
        }
        return result;
    }

    vector<int> topviewIter(TreeNode *root)
    {
        vector<int> ans;
        if (root == NULL)
            return ans;

        queue<pair<TreeNode *, int> > level;
        map<int, int> top;

        level.push(make_pair(root, 0));

        // Using Level order traversal to find the top view
        while (!level.empty())
        {
            pair<TreeNode *, int> curr = level.front();
            level.pop();
            if (top.find(curr.second) == top.end())
                top[curr.second] = curr.first->getData();
            if (curr.first->left != NULL)
            {
                level.push(make_pair(curr.first->left, curr.second - 1));
            }
            if (curr.first->right != NULL)
            {
                level.push(make_pair(curr.first->right, curr.second + 1));
            }
        }

        for (auto i = top.begin(); i != top.end(); i++)
        {
            ans.push_back(i->second);
        }
        return ans;
    }

    vector<int> bottomView(TreeNode *root)
    {
        map<int, vector<int> > m;
        getVerticalOrder(root, 0, m);
        vector<int> result;
        for (auto it = m.begin(); it != m.end(); it++)
        {
            result.push_back(it->second[it->second.size() - 1]);
        }
        return result;
    }
    /// BOUNDARY TRAVERSAL///

    void leftBoundary(TreeNode *root, vector<int> &result)
    {
        if (root == NULL)
        {
            return;
        }
        if (root->getLeft() == NULL && root->getRight() == NULL)
        {
            result.push_back(root->getData());
            return;
        }
        leftBoundary(root->getLeft(), result);
        if (root->getLeft() == NULL && root->getRight() != NULL)
        {
            result.push_back(root->getData());
        }
    }

    void rightBoundary(TreeNode *root, vector<int> &result)
    {
        if (root == NULL)
        {
            return;
        }
        if (root->getLeft() == NULL && root->getRight() == NULL)
        {
            result.push_back(root->getData());
            return;
        }
        rightBoundary(root->getRight(), result);
        if (root->getRight() == NULL && root->getLeft() != NULL)
        {
            result.push_back(root->getData());
        }
    }

    void leaves(TreeNode *root, vector<int> &result)
    {
        if (root == NULL)
        {
            return;
        }
        if (root->getLeft() == NULL && root->getRight() == NULL)
        {
            result.push_back(root->getData());
            return;
        }
        leaves(root->getLeft(), result);
        leaves(root->getRight(), result);
    }

    vector<int> boundary(TreeNode *root)
    {
        vector<int> result;
        if (root == NULL)
        {
            return result;
        }
        leftBoundary(root->getLeft(), result);
        result.push_back(root->getData());
        rightBoundary(root->getRight(), result);
        leaves(root->getLeft(), result);
        leaves(root->getRight(), result);
        return result;
    }
    // left view of binary tree
    void leftView(TreeNode *root, int level, map<int, int> &m)
    {
        if (root == NULL)
        {
            return;
        }
        if (m.find(level) == m.end())
        {
            m[level] = root->getData();
        }
        leftView(root->getLeft(), level - 1, m);
        leftView(root->getRight(), level - 1, m);
    }

    vector<int> leftView(TreeNode *root)
    {
        map<int, int> m;
        leftView(root, 0, m);
        vector<int> result;
        for (auto it = m.begin(); it != m.end(); it++)
        {
            result.push_back(it->second);
        }
        return result;
    }

    // right view of binary tree
    void rightView(TreeNode *root, int level, map<int, int> &m)
    {
        if (root == NULL)
        {
            return;
        }
        if (m.find(level) == m.end())
        {
            m[level] = root->getData();
        }
        rightView(root->getRight(), level + 1, m);
        rightView(root->getLeft(), level + 1, m);
    }

    vector<int> rightView(TreeNode *root)
    {
        map<int, int> m;
        rightView(root, 0, m);
        vector<int> result;
        for (auto it = m.begin(); it != m.end(); it++)
        {
            result.push_back(it->second);
        }
        return result;
    }

    vector<int> rightviewIter(TreeNode *root)
    {
        vector<int> ans;
        queue<TreeNode *> q;
        if (root == NULL)
            return ans;
        q.push(root);
        q.push(NULL);
        while (!q.empty())
        {
            TreeNode *temp = q.front();
            if (temp)
            {
                ans.push_back(temp->getData());
                while (q.front() != NULL)
                {
                    if (temp->right)
                        q.push(temp->right);
                    if (temp->left)
                        q.push(temp->left);
                    q.pop();
                    temp = q.front();
                }
                q.push(NULL);
            }
            q.pop();
        }
        return ans;
    }
    // left view iterative
    vector<int> leftViewIterative(TreeNode *root)
    {
        vector<int> ans;
        return ans;
    }

    /////Zig Zag Traversal of Binary Tree/////
    void zigZag(TreeNode *root, int level, vector<vector<int> > &result)
    {
        if (root == NULL)
        {
            return;
        }
        if (result.size() == level)
        {
            vector<int> v;
            v.push_back(root->getData());
            result.push_back(v);
        }
        else
        {
            result[level].push_back(root->getData());
        }
        zigZag(root->getLeft(), level + 1, result);
        zigZag(root->getRight(), level + 1, result);
    }

    vector<vector<int> > zigZagTraversal(TreeNode *root)
    {
        vector<vector<int> > result;
        zigZag(root, 0, result);
        return result;
    }

    // lowest common ancestor of two nodes
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == NULL)
            return NULL;
        if (root == p || root == q)
            return root;
        TreeNode *left = lowestCommonAncestor(root->getLeft(), p, q);
        TreeNode *right = lowestCommonAncestor(root->getRight(), p, q);
        if (left && right)
            return root;
        return left ? left : right;
    }

    class BSTIterator
    {
        stack<TreeNode *> st; // for storing the values of the nodes
    public:
        BSTIterator(TreeNode *root)
        {
            while (root)
            {
                st.push(root);
                root = root->left; // follow the inorder traversal algo
            }
        }

        int next()
        {
            TreeNode *node = st.top();
            st.pop();
            int res = node->data;
            node = node->right;
            while (node)
            {
                st.push(node);
                node = node->left;
            }
            return res;
        }

        bool hasNext()
        {
            return !st.empty();
        }
    };
};