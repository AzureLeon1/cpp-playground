// 快速排序，降序，当partition返回的pos等于k-1时，返回nums[pos]

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if(nums.size() == 1) {
            return nums[0];
        }
        int l = 0;
        int r = nums.size() - 1;
        while (true) {
            int pos = partition(nums, l, r);
            if (pos == k-1) {
                return nums[pos];
            }
            else if (pos < k - 1)
                l = pos + 1;
            else
                r = pos - 1;
        }
    }

    int partition(vector<int>& nums, int l, int r) {
        swap(nums[l], nums[l + rand() % (r - l + 1)]);
        int pivot = nums[l];
        int i = l, j = r;
        while (i < j) {
            while (i < j && nums[j] <= pivot)   // 应该 j 在前，否则外面的swap应该是l与i-1
                j--;
            while (i < j && nums[i] >= pivot)
                i++;
            if (i < j)
                swap(nums[i], nums[j]);
        }
        swap(nums[l], nums[i]);
        return i;
    }
};

int main () {
    vector<int> nums {2, 1};
    int k = 1;
    Solution s;
    int ans = s.findKthLargest(nums, k);
    cout << ans << endl;

    return 0;
}