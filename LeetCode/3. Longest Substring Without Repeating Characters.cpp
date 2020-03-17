#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, bool> mapper;
        int res = 0;
        vector<char> sliding_window;

        int s_length =  s.length();
        for (size_t i = 0; i < s_length; i++)
        {
            if ( mapper[s[i]] ) {
                // 已经出现过了，则删除
                const vector<char>::iterator it = find(sliding_window.begin(), sliding_window.end(), s[i]);
                vector<char>::iterator temp;
                for (temp = sliding_window.begin(); temp <= it; temp++) {
                    mapper[*temp] = false; 
                }

                sliding_window.erase(sliding_window.begin(), it+1);
                sliding_window.push_back(s[i]);
                
            }
            else {
                // 新字符
                sliding_window.push_back(s[i]);
                if (sliding_window.size() > res) {
                    res = sliding_window.size();
                }
            }
            mapper[s[i]] = true;
        }
        return res;
    }
};