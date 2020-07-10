// 注意没要求格子内全部是0
// 方法：一个正方形有四条边。通过dp可以快速判断下边和右边的长度，然后还需要一个循环来判断可行的最大的上边和左边的长度
// trick：dp数组的第0行和第0列是空的，都是0，这是为了统一对dp数组的操作，即不需要对grid的首行首列单独处理。类似带头结点的链表。
// 同时需要注意的是，dp[i][j]对应的是grid[i-1][j-1]

#include <vector>
#include <math.h>
#include <iostream>

using namespace std;

class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int res = 0;

        if (grid.size() == 0)
            return 0;

        int height = grid.size();
        int width = grid[0].size();

        vector<vector<vector<int> > > dp(height+1, vector<vector<int>>(width+1, vector<int>(2, 0)));    // dp[i][j][0]表示从i,j位置向上连续的1的个数，dp[i][j][1]表示从i,j位置向左连续的1的个数

        for (int i = 1; i <= height; ++i) {
            for (int j = 1; j <= width; ++j) {
                if (grid[i-1][j-1]==0)        // 如果是0则不要继续了
                    continue;

                dp[i][j][0] = dp[i-1][j][0] + 1;   // 求出up情况下连续的个数
                dp[i][j][1] = dp[i][j-1][1] + 1;   // 求出left情况下连续的个数

                int len = min(dp[i][j][0], dp[i][j][1]);    // 拿出两者较小的长度，因为四条边都要相等。

                // for (int k = 0; k < len; k++) {       //拿出后并不一定就是min这个长度，有可能另外两条边比较短，没有min长。而且在这种情况下，k具体是多大是不知道的，要去所有可能情况下的最大值，所以要一个一个判断。
                //     if (dp[i][j-k][0]>=k+1 && dp[i-k][j][1]>=k+1)   // 判断另外的两条边是否都比当前长度大。
                //         res = max(res, k+1);
                        
                // }

                // 也可以按k从大到小循环
                int k;
                for (k = len-1; k >=0; k--) {       //拿出后并不一定就是min这个长度，有可能另外两条边比较短，没有min长。而且在这种情况下，k具体是多大是不知道的，要去所有可能情况下的最大值，所以要一个一个判断。
                    if (dp[i][j-k][0]>=k+1 && dp[i-k][j][1]>=k+1)   // 判断另外的两条边是否都比当前长度大。
                        break;
                }
                res = max(res, k+1);
            }
        }
        return res * res;

    }
};

int main() {

    // vector<vector<int> > grid = {{1,1,1},{1,0,1},{1,1,1}};
    vector<vector<int> > grid = {{1,1,0,0}};


    Solution s;
    int res = s.largest1BorderedSquare(grid);

    cout << res << endl;

    return 0;


}