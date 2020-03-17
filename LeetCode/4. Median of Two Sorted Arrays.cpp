#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // 对两个 vector 中 size() 小的那个进行二分，以保证时间复杂度为 log(min(m, n)) 级
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int m = nums1.size();
        int n = nums2.size();
        int low = 0;
        int high = m;
        while (low <= high)
        {
            int i = low + (high - low) / 2;
            int j = (m + n + 1) / 2 - i;

            int max_left_A = i == 0 ? INT_MIN : nums1[i - 1];
            int min_right_A = i == m ? INT_MAX : nums1[i];

            int max_left_B = j == 0 ? INT_MIN : nums2[j - 1];
            int min_right_B = j == n ? INT_MAX : nums2[j];

            if (max_left_A <= min_right_B && max_left_B <= min_right_A) {
                // total length is even
                if ((m+n) % 2 == 0) {
                    return (double)((max(max_left_A, max_left_B) + min(min_right_A, min_right_B))) / 2;
                }
                else {
                    // total length is odd
                    return (double) max(max_left_A, max_left_B);
                }
            }
            else if (max_left_A > min_right_B) {
                high = i - 1;
            }
            else {
                low = i + 1;
            }
        }
        return 0.0;
    }
};