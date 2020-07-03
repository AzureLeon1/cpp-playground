// 95题的简化版，只需要输出BST的个数，不同输出具体的树
// 注意start>end条件下也是返回1，对应一种树的情况（空树）
// 需要注意的是，之间套用95题的方法会超时。
// 可优化的地方：1. 不需要用start,end，而只需要传需要排的元素的个数即可，因为用1~5生成，和用2~6生成，树的个数是一样的
// 对于重复计算，memoization


#include<iostream>
#include<unordered_map>

using namespace std;

class Solution {
public:

    unordered_map<int, int> m;

    int numTreesCore(int n) {

        if (n == 0) 
            return 1;

        if (n == 1) 
            return 1;

        if (m.find(n)!=m.end()) 
            return m[n];
        
        int res = 0;

        for (int i = 1; i <= n; i++) {
            int lefts = numTreesCore(i - 1);
            int rights = numTreesCore(n - i);
            res += (lefts * rights);
        }
        if (m.find(n)==m.end()) {
            m[n] = res;
        }
        return res;
    }

    int numTrees(int n) {
        if (n==0) 
            return 0;
        if (n==1)
            return 1;

        int res = numTreesCore(n);
        return res;
    }
};

int main() {

    Solution s;
    int res = s.numTrees(3);

    return 0;
}