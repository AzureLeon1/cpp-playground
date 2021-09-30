from typing import List

class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:

        #input:   [1,  2,3,4]
        # output: [24,12,8,6]
        # 24 =     2 * 3 * 4
        # 12 = 1 *     3 * 4
        #  8 = 1 * 2 *     4
        #  6 = 1 * 2 * 3 

        # view the final product consists of two parts: left part and right part
        # we can compute these two parts by going through input list two times
        # time: O(2*n)

        length = len(nums)

        left_products = [0] * length
        right_products = [0] * length
        tmp = 1
        for i in range(length):
            tmp *+ nums[i]
            left_products[i] = tmp
        tmp = 1
        for i in range(length-1, -1, -1):
            tmp *= nums[i]
            right_products[i] = tmp
        
        ans = []
        for i in range(length):
            left_part = left_products[i-1] if i != 0 else 1
            right_part = right_products[i+1] if i != length -1 else 1
            ans.append(left_part * right_part)
        return ans


if __name__ == "__main__":
    s = Solution()
    nums = [1,2,3,4]
    ans = s.productExceptSelf(nums)
    print(ans)