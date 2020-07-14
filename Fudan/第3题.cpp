#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void modifyColor(int x, vector<int>& color, vector<int>& colored) {
    if (color[x]==0) {
        color[x] = 1;
        colored.push_back(x);
    }
}

int query(int x, vector<int>& father, vector<int>& length, vector<int>& color, vector<int>& colored) {
    
    
    int res = 0;

    // 记录x到根节点的路径
    unordered_map<int, int> path;
    path[x] = 0;
    int sum_length = 0;
    int cur_node = x;
    int last_node;
    while(cur_node!=0 || father[cur_node]!=0) {
        sum_length += length[cur_node];
        // last_node = cur_node;
        cur_node = father[cur_node];
        path[cur_node] = sum_length;
    }
    // path[0] = sum_length + father[last_node];

    int num_colored_node = colored.size();
    for (int i = 0; i < num_colored_node; i++) {
        cur_node = colored[i];
        if (cur_node==x)
            continue;
        while(path.find(cur_node)==path.end()) {
            res += length[cur_node];
            cur_node = father[cur_node];
        }
        res += path[cur_node];
    }
    return res;
}

int main() {

    int n, m; // num of nodes, num of operations

    cin >> n >> m;

    vector<int> father;
    vector<int> length;
    vector<int> color(n, 0);   // 0 white, 1 black
    vector<int> colored;
    father.push_back(0); // father[0]=0
    length.push_back(0);
    int temp;
    for (int i = 1; i < n; ++i) {
        cin >> temp;
        father.push_back(temp);
    }
    for (int i = 1; i < n; ++i) {
        cin >> temp;
        length.push_back(temp);
    }


    int operation, node;
    while(cin >> operation >> node) {
        if (operation==1) {
            modifyColor(node, color, colored);
        }
        else {
            int res = query(node, father, length, color, colored);
            cout << res << endl;
        }
    }
    return 0;
}