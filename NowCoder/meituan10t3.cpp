// 超时

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int t, n, origin;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        //vector<int> cnt(n);
        //cin >> origin;
        //for (int j = 0; j < n; j++) {
        //    int temp = origin % 10;
        //    cnt[n-1-j] = temp;
        //    origin /= 10;
        //}
        string occupy;
        cin >> occupy;
        vector<int> occ;
        for (long j = 0; j < n; j++) {
            occ.push_back(int(occupy[j]) - int('0'));
        }
        long m;
        cin >> m;
        string q;
        cin >> q;
        for (long i = 0; i < m; i++) {
            long res = n + 1;
            long backup = n + 1;
            if (q[i] == 'M') {
                for (long j = 0; j < n; j++) {
                    if (occ[j] == 1) {
                        res = j+1;
                        break;
                    }
                    else if (occ[j] == 0 && backup == n+1) {
                        backup = j + 1;
                    }
                }
            }
            else {
                for (long j = 0; j < n; j++) {
                    if (occ[j] == 0) {
                        res = j+1;
                        break;
                    }
                    else if (occ[j] == 1 && backup == n+1) {
                        backup = j + 1;
                    }
                }
            }
            if (res < n + 1) {
                cout << res << endl;
                occ[res - 1]++;
            }
            else {
                cout << backup << endl;
                occ[backup - 1]++;
            }
        }
    }
    
    
    return 0;
}