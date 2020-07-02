// 用优先级队列来做，每次val最小的出队列，第k次出队列的值就是第k小
// 注意优先级队列的用法
// 如果优先级队列用于struct的话，需要创建cmp结构体并重载函数运算符

#include<queue>
#include<vector>
#include<iostream>

using namespace std;

struct Ele {
    int x;
    int y;
    int val;
    Ele () {}
    Ele(int x, int y, int val) : x(x), y(y), val(val) {}
};

struct cmp
{
    bool operator() (Ele& e1, Ele& e2) {
        return e1.val > e2.val;
    }
};


class Solution {
public:
    int kthSmallest(vector<vector<int> >& matrix, int k) {
        priority_queue<Ele, vector<Ele>, cmp> pq;
        int n = matrix.size();
        for(int i = 0; i < n; i++) {
            Ele cur(0, i, matrix[0][i]);
            pq.push(cur);
        }

        
        for (int i = 0; i < k-1; i++) {
            Ele temp = pq.top();
            pq.pop();
            int temp_x = temp.x;
            int temp_y = temp.y;
            if (temp_x+1 < n) {
                Ele cur(temp_x+1, temp_y, matrix[temp_x+1][temp_y]);
                pq.push(cur);
            }
        }

        Ele res_ele = pq.top();
        return res_ele.val;
    }
};

int main() {

    vector<vector<int> > v;
    vector<int> row1 = {1, 5, 9};
    vector<int> row2 = {10, 11, 13};
    vector<int> row3 = {12, 13, 15};
    v.push_back(row1);
    v.push_back(row2);
    v.push_back(row3);
    Solution s;
    int res = s.kthSmallest(v, 8);
    cout << res << endl;
    return 0;
}