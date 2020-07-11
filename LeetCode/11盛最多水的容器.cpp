// 双指针，表示左右的木板，每次让小木板向中心移动

#include<vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        // 双指针
        int i = 0;
        int j = height.size() - 1;

        int res = 0;

        while(i < j) {
            int min_height = min(height[i], height[j]);
            int cur_res = min_height * (j - i);
            res = max(res, cur_res);

            if (min_height == height[i])
                ++i;
            else
                --j;
        }
        return res;
    }
};