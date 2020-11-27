// 拓扑排序题，通过维护一个反向图（有向图中的前序关系）提高效率

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void remove_edge(vector<vector<int>>& graph, vector<vector<int>>& inverse_graph, int node, int edge_id, vector<int>& res, vector<bool>& has_record) {
        if (graph[node].size()==0) {
            return;
        }
        auto it = find(graph[node].begin(), graph[node].end(), edge_id);
        if (it != graph[node].end()) {
            graph[node].erase(it);
            if (graph[node].size()==0) {
                res.push_back(node);
                has_record[node] = true;
                for (int last_node : inverse_graph[node]) {
                    remove_edge(graph, inverse_graph, last_node, node, res, has_record);
                }
            }
            
        }
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> res;
        int len = graph.size();

        // 通过反向图记录每个节点的上一个节点
        vector<vector<int>> inverse_graph;
        inverse_graph.resize(len);
        for (int i = 0; i < len; ++i) {
            for (int& ele : graph[i]) {
                inverse_graph[ele].push_back(i);
            }
        }

        // 拓扑排序
        vector<bool> has_record(len, 0); // 辅助数组
        for (int i = 0; i < len; ++i) {
            if (graph[i].size()==0) {
                if (!has_record[i]) {
                    res.push_back(i);
                    for (int ele : inverse_graph[i]) {
                        remove_edge(graph, inverse_graph, ele, i, res, has_record);
                    }
                    has_record[i] = true;
                }
                
            }
        }

        sort(res.begin(), res.end());
        return res;
    }
};

int main() {
    Solution s;

    vector<vector<int>> data {{1,2},{2,3},{5},{0},{5},{},{}};

    auto res = s.eventualSafeNodes(data);
    
    for (int& ele : res) {
        cout << ele << " ";
    }

    return 0;
}