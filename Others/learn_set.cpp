#include <map>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

int lengthOfLongestSubstring(string s) {
        map<char, int> mapper;
        int res = 0;
        vector<char> sliding_window;
        int window_start_index = 0;

        int s_length =  s.length();
        for (int i = 0; i < s_length; i++)
        {
            if ( mapper.find(s[i])!=mapper.end() && mapper[s[i]]>window_start_index ) {
                // 已在当前滑窗内，则更新vector和map
                const vector<char>::iterator it = find(sliding_window.begin(), sliding_window.end(), s[i]);
                sliding_window.erase(sliding_window.begin(), it+1);

                window_start_index = mapper[s[i]] + 1;
                mapper[s[i]] = i;

                sliding_window.push_back(s[i]);
                
            }
            else {
                // 新字符
                sliding_window.push_back(s[i]);
                mapper[s[i]] = i;
                if (sliding_window.size() > res) {
                    res = sliding_window.size();
                }
            }
        }
        return res;
    }
int main() {

    int result = lengthOfLongestSubstring("pwwkew");
    cout << result << endl;
    return 0;
}