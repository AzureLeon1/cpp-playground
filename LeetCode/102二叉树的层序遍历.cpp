// 该题的要点在于：需要知道每个节点属于哪一层
// 有两种方法：1. 按层细分的BFS 2. DFS

#include<queue>
#include<vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {

        vector<vector<int> > res;

        if (root==nullptr) {
            return res;
        }

        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            vector<int> cur;
            int row_num = q.size();
            for (int i = 0; i < row_num; ++i) {
                TreeNode* temp = q.front();
                q.pop();
                cur.push_back(temp->val);
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            res.push_back(cur);
        }
        return res;
    }
};