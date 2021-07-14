// 最小堆（优先级队列）

#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int main() {
    int t, n;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        string occupy;
        cin >> occupy;
        priority_queue<int, vector<int>, greater<int>> heap0;
        priority_queue<int, vector<int>, greater<int>> heap1;
        for (long j = 0; j < n; j++) {
            if (occupy[j] == '0') {
                heap0.push(j+1);
            }
            else if (occupy[j] == '1') {
                heap1.push(j+1);
            }
        }

        long m;
        cin >> m;
        string q;
        cin >> q;
        int res;
        for (long i = 0; i < m; i++) {
            if (q[i] == 'M') {
                if (!heap1.empty()) {
                    res = heap1.top();
                    heap1.pop();
                }
                else if (!heap0.empty()) {
                    res = heap0.top();
                    heap0.pop();
                    heap1.push(res);
                }
            }
            else {
                if (!heap0.empty()) {
                    res = heap0.top();
                    heap0.pop();
                    heap1.push(res);
                }
                else if (!heap1.empty()) {
                    res = heap1.top();
                    heap1.pop();
                }
            }
            cout << res << '\n';
        }
    }
    
    
    return 0;
}