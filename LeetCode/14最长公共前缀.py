from typing import List

class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if not strs:
            return ""
        
        prefix = strs[0]
        count = len(strs)

        for i in range(1, count):
            prefix = self.lcp(prefix, strs[i])
            if not prefix:
                break
        return prefix

    def lcp(self, str1: str, str2: str) -> str:
        max_length = min(len(str1), len(str2))
        idx = 0
        for i in range(max_length):
            if str1[i] == str2[i]:
                idx += 1
                continue
            else:
                break
        return str1[:idx]

# strs = ['hadfstp', 'hadfsqq', 'hadpd']
strs = ['adfstp', 'hadfsqq', 'hadpd']
s = Solution()
prefix = s.longestCommonPrefix(strs)
print(prefix)
print(type(prefix))
