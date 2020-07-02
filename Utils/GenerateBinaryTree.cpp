#include<iostream>
#include<vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 根据数组生成二叉树
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

// 中序遍历输出
void inorderPrint(TreeNode* root) {
    if (root==nullptr) return;
    inorderPrint(root->left);
    cout << root->val << " ";
    inorderPrint(root->right);
}

int main() {
    // null 要用 -1 表示
    vector<int> data {1, 3, -1, -1, 2};

    TreeNode* root = generateBTree(data, 0);

    return 0;
}
