// 计算n个数组能构成的二叉搜索树的个数
// 用递归来做的
// 但是也可以用dp来做


#include<vector>

using namespace std;

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
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<TreeNode*> generateTreesCore(int start, int end) {

        vector<TreeNode*> res;

        if (start>end) {
            res.push_back(nullptr);
            return res;
        }

        if (start==end) {
            TreeNode* root = new TreeNode(start);
            res.push_back(root);
            return res;
        }
        

        for (int i = start; i <= end; i++) {
            vector<TreeNode*> lefts = generateTreesCore(start, i-1);
            vector<TreeNode*> rights = generateTreesCore(i+1, end);

            for (int m = 0; m < lefts.size(); ++m) {
                for (int j = 0; j < rights.size(); ++j) {
                    TreeNode* left = lefts[m];
                    TreeNode* right = rights[j];
                    TreeNode* root = new TreeNode(i, left, right);
                    res.push_back(root);
                }
            }
        }

        return res;
        

    }

    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> res;
        if (n==0) 
            return res;
        if (n==1) {
            res.push_back(new TreeNode(n));
            return res;
        }

        res = generateTreesCore(1, n);
        return res;
    }
};