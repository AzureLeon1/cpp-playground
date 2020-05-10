// 用最大公约数的方法来算，不要用什么队列广度搜索
// 因为Yes输出成YES还wa了一次，眼睛不需要可以捐给有需要的人了

#include <unordered_set>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int t;
int n, a, b;

int cnt=0;

int gcd(int m, int n)
{
    return n == 0 ? m : gcd(n, m % n);
}

int main() {

    cin>>t;

    for (int z=0; z<t; z++) {
        cnt = 2;

        cin >> n >> a >> b;

        if (a < b) {
            swap(a, b);
        }

        int g = gcd(a, b);
        if (a%g==0 && b%g==0) {
            cnt = n / g;
        }
        
        // cout << "gcd: " << g << ", n/gcd: " << n/g << ", cnt: " << cnt << endl;
        if (cnt%2==1) {
            cout << "Yes";
        }
        else {
            cout << "No";
        }

        if (z<t-1){
            cout << endl;
        }


    }


    return 0;
}