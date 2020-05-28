/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 1. 题目要求从任意节点出发到任意节点
// 2. 节点中更可能有负值

// 方法：对二叉树的递归遍历，二叉树遍历的过程中维护result，遍历完就有了最佳结果

class Solution {
public:

    int result = INT_MIN;

    int oneSidePath(TreeNode* root) {
        if (root == NULL)
            return 0;
        int left_path = max(0, oneSidePath(root->left));
        int right_path = max(0, oneSidePath(root->right));
        this->result = max(this->result, root->val + left_path + right_path); // compute result
        return root->val + max(left_path, right_path);
    }

    int maxPathSum(TreeNode* root) {
        if (root == NULL)
            return 0;
        oneSidePath(root);
        return this->result;
    }
};