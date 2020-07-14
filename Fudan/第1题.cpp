#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <string>

using namespace std;

vector<int> toPoSort(int num, vector<vector<int> >& graph, vector<int>& in_degree) {
    vector<int> res;
    priority_queue<int, vector<int>, greater<int> > nodes;
    for(int i = 0; i < num; ++i) {
        if (in_degree[i]== 0) {
            nodes.push(i);
        }
    }
    while(!nodes.empty()) {
        int cur = nodes.top();
        nodes.pop();
        res.push_back(cur);
        for (int i = 0; i < graph[cur].size(); ++i) {
            int to_node = graph[cur][i];
            in_degree[to_node]--;
            if (in_degree[to_node]==0) {
                nodes.push(to_node);
            }
        }
    }
    return res;
}


int main() {

    int num;   // num of course

    vector<vector<int> > graph(num, vector<int>());  // 邻接表
    vector<int> in_degree(num, 0);         // 入度

    string temp;
    getline(cin, temp);

    if (temp.length() == 0) 
        return 0;

    int pos = temp.find(',');

    if (pos == -1 && temp.length() != 0) {
        num = atoi(temp.c_str());
        for (int i = 0; i < num; ++i) {
            cout << i;
            if (i < num-1)
                cout<<',';
        }
        cout << endl;
        return 0;
    }

    num = atoi(temp.substr(0, pos).c_str());

    if (num == 0) 
        return 0;

    int from, to;
    int pos1, pos2;
    while(pos != -1) {
        pos1 = temp.find('[', pos);
        pos2 = temp.find(',', pos1);
        to = atoi(temp.substr(pos1+1, pos2-pos1-1).c_str());
        pos1 = pos2;
        pos2 = temp.find(']', pos1);
        from = atoi(temp.substr(pos1+1, pos2-pos1-1).c_str());
        // cout << from << ' ' << to << endl;
        graph[from].push_back(to);
        in_degree[to]++;
        pos = temp.find(',', pos2);
    }

    vector<int> res = toPoSort(num, graph, in_degree);

    // output
    int cnt = res.size();
    if (cnt != num){
        cout << "无解";
    }
    else {
        for (int i = 0; i < cnt; ++i) {
        if (i == 0) {
            cout << res[i];
        }
        else {
            cout << ',' << res[i];
        }
    }
    }

    return 0;
}


// 4,[1,0],[2,0],[3,1],[3,2]