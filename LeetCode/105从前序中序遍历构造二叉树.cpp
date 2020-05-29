/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 方法：递归，前序遍历的第一个值作为根节点，然后选出左子树对应的前序中序遍历片段，生成左子树，再生成右子树 
// 需要注意边界问题：左子树可能没有、右子树也可能没有，一定要加判断条件
// 如果遍历序列是空的话，直接返回NULL

#include <unordered_map>
#include <vector>

using namespace std;

struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:

    bool has_build_map = false;
    unordered_map<int, int> m_inorder;
    
    void buildMap(vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) {
            m_inorder[inorder[i]] = i;
        }
        has_build_map = true;
    }

    TreeNode* buildTreeCore(vector<int>& preorder, int p_start, int p_end, 
                            vector<int>& inorder, int i_start, int i_end) {

        if (p_start > preorder.size()-1 || i_start > inorder.size()-1) return NULL;

        int pos_inorder = m_inorder[preorder[p_start]];
        int num_left = pos_inorder - i_start;

        TreeNode* root = new TreeNode(preorder[p_start]);
        if (p_start==p_end) return root;
        if (pos_inorder > i_start)
            root -> left = buildTreeCore(preorder, p_start+1, p_start+num_left, inorder, i_start, pos_inorder-1);
        if (pos_inorder < i_end)
            root -> right = buildTreeCore(preorder, p_start+num_left+1, p_end, inorder, pos_inorder+1, i_end);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0) {
            return NULL;
        }

        // 构建 inorder 数组的索引map，只构建一次
        if (!has_build_map) {
            buildMap(inorder);
        }

        // 递归法构建(前序遍历)
        TreeNode* root = buildTreeCore(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
        
        return root;
    }
};

int main() {
    // vector<int> preorder {3,9,20,15,7};
    // vector<int> inorder {9,3,15,20,7};
    vector<int> preorder {1, 2};
    vector<int> inorder {2, 1};

    Solution s;
    s.buildTree(preorder, inorder);

    return 0;
}