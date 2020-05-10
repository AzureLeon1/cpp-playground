#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mapper;
        int res = 0;
        int window_start_index = 0;

        int s_length =  s.length();
        for (int i = 0; i < s_length; i++)
        {
            if ( mapper.find(s[i])!=mapper.end() && mapper[s[i]]>=window_start_index ) {
                // 已在当前滑窗内，则更新map
                window_start_index = mapper[s[i]] + 1;
                mapper[s[i]] = i;
                
            }
            else {
                // 新字符
                mapper[s[i]] = i;
                int cur_len = i - window_start_index + 1;
                if (cur_len > res) {
                    res = cur_len;
                }
            }
        }
        return res;
    }
};