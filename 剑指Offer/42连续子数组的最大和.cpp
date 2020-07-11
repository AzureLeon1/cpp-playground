// 今日头条一面问过这道题，当时想了个O(n^2)的dp
// 实际上可以用O(n)的dp完成，具体看这篇题解：https://leetcode-cn.com/problems/lian-xu-zi-shu-zu-de-zui-da-he-lcof/solution/mian-shi-ti-42-lian-xu-zi-shu-zu-de-zui-da-he-do-2/
// 而且空间复杂度也可以优化到O(1)，因为只需要dp[i]和dp[i-1]两个值，这里用了O(n)的空间复杂度是为了方便理解

#include<vector>
#include<limits.h>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int len = nums.size();

        if (len==0)
            return 0;
        
        int res = INT_MIN;
        vector<int> dp(len, 0);

        for (int i = 0; i < len; ++i) {
            if (i==0 || dp[i-1]<0) {
                dp[i] = nums[i];
            }
            else {
                dp[i] = dp[i-1] + nums[i];
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};