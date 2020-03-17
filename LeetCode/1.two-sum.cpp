/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
#include<vector>
#include<map>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> m;
        map<int,int>::iterator it;
        vector<int> result;
        int size = nums.size();
        for (int i = 0; i < size; i++) {
            int temp = target - nums[i];
            it = m.find(temp);
            if (it != m.end()) {
                result.push_back(it->second);
                result.push_back(i);
                return result;
            }
            else {
                m[nums[i]] = i;
            }
        }
        return result;
    }
};
// @lc code=end

