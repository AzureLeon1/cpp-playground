#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int maxn = 301;

vector<int> v(maxn, 0);
int mem[maxn][maxn][maxn];

int dp(int left, int right, int father) {
    int res = 1 << 30;

    if (left > right) return 0;
    if (mem[left][right][father] != -1) return mem[left][right][father];

    for (int i = left; i <= right; i++) {
        int l_res = dp(left, i-1, i);
        int r_res = dp(i+1, right, i);
        res = min(res, l_res+r_res+v[i]*v[father]);
    }

    mem[left][right][father] = res;
    return res;
}

int main() {
    int n;
    cin >> n;
    int temp;
    for(int i = 1; i < n+1; i++) {
        cin >> v[i];
    }

    memset(mem, -1, sizeof(mem));

    int res = dp(1, n, 0);
    cout << res << endl;



    return 0;
}