// 使用priority_queue实现的huffman tree

#include<queue>
#include<vector>
#include<iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() {}
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
    TreeNode(int val, TreeNode* left, TreeNode* right) : val(val), left(left), right(right) {}
};

struct cmp
{
    bool operator() (TreeNode* node1, TreeNode* node2) {
    return node1->val > node2->val;        // 对应最小堆
}
};

int main() {

    vector<int> data = {7, 5, 2, 4};

    priority_queue<TreeNode*, vector<TreeNode*>, cmp> pq;

    // init
    for (int i = 0; i < data.size(); ++i) {
        pq.push(new TreeNode(data[i]));
    }

    while (pq.size() > 1) {
        TreeNode* min1 = pq.top();
        pq.pop();
        TreeNode* min2 = pq.top();
        pq.pop();

        TreeNode* new_node = new TreeNode(min1->val + min2->val, min1, min2);
        pq.push(new_node);
    }

    TreeNode* res = pq.top();

    return 0;
}