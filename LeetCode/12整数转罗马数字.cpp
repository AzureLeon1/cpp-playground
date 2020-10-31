#include <vector>

class Solution {
public:
    string intToRoman(int num) {
        vector<int> nums = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> romans = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

        string res = "";

        for (int i = 0; i < nums.size(); ++i) {
            int cur_num = nums[i];
            while (num >= cur_num) {
                res += romans[i];
                num -= cur_num;
            }
        }
        return res;
    }
};