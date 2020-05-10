// 和区间相关的题目，输入数据的时候记哨兵（区间端点）即可，全部区间读完之后再遍历，这样不会超时
// 不要一边读入，一边处理区间
// 另外区间一定要开大一点，因为区间长度少了1，wa了一次

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

// struct data {
//     int index;
//     int cnt;
// };

long cnt[200002];

bool cmp(int i, int j) {
    return (i>j);
}

long long sum = 0;

long shaobing[200002];


int main() {

    long n, m, l, r;
    cin >> n >> m;

    memset(cnt, 0, sizeof(cnt));
    memset(shaobing, 0, sizeof(shaobing));
    // vector<data> cnts(n, )

    
    for (int i = 0; i < m; i++) {

        cin >> l >> r;
        if (l>r) {
            continue;
        }
        // for (int j = l; j <= r; j++) {
        //     cnt[j]++;
        // }
        shaobing[l]++;
        shaobing[r+1]--;
    }

    long delta = 0;
    for (int i = 1; i <=n; i++) {
        delta += shaobing[i];
        cnt[i] = delta;
    }

    sort(cnt+1, cnt+1+n, cmp);

    long current = n;
    for (int i = 1; i <= n; i++) {
        if (cnt[i]==0) break;
        sum += cnt[i] * current;
        current--;
    }

    cout << sum;

    return 0;
}