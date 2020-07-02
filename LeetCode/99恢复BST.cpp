// 恢复BST（有一对元素位置交换了）

// - 法一：列举所有情况，分别处理
// - 法二：中序遍历找逆序对，根据相邻不相邻有两种情况
// https://leetcode.wang/leetcode-99-Recover-Binary-Search-Tree.html


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include<vector>
#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* generateBTree(vector<int>& data, int index) {
    TreeNode* new_node = nullptr;
    if (index < data.size() && data[index]!=-1) {
        new_node = new TreeNode();
        new_node->val = data[index];
        new_node->left = generateBTree(data, 2*index+1);
        new_node->right = generateBTree(data, 2*index+2);
    }
    return new_node;
}



class Solution {
public:
    TreeNode* first = NULL;
    TreeNode* second = NULL;
    TreeNode* pre = NULL;
    void inorderTraversal(TreeNode* root) {
        if (root==NULL)
            return;
        
        inorderTraversal(root->left);

        if (pre!=NULL && pre->val > root->val) {
            if (first==NULL){
                first = pre;
                second = root;
            }
            else{
                second = root;
            }
        }
        pre = root;     // 注意要处理完每个节点之后，把该节点置为root

        inorderTraversal(root->right);
    }
    void recoverTree(TreeNode* root) {
        inorderTraversal(root);
        int temp = first->val;
        first->val = second->val;
        second->val = temp;
    }
};



int main() {
    // null 要用 -1 表示
    vector<int> data {1, 3, -1, -1, 2};

    TreeNode* root = generateBTree(data, 0);

    Solution s;
    s.inorderTraversal(root);


    return 0;
}

