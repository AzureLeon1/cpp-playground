#include <string>
#include <vector>
#include <iostream>
using namespace std;

// class Solution {
// public:
//     string longestPalindrome(string s) {
//         if (s == "") {
//             return "";
//         }

//         int len = s.length();
//         vector<vector<int> > dp(len, vector<int>(len, 0));
//         int start = 0, end = 0, max = 0;
//         //initialize the basic case
//         for(int i = 0;i<s.size();i++){
//             dp[i][i] = 1;//长度为1的子串的情况
//             if((i+1)<s.size()&&s[i]==s[i+1]){//长度为2的子串的情况
//                 dp[i][i+1] = 1;
//             }
//         }
//         for(int i = 2;i<s.size();i++){//i为第几个从左上到右下的对角线，i=0表示主对角线
//             for(int j = 0; j<s.size()-i; j++){//j为第几行
//                 if(dp[j+1][j+i-1]==1 && (s[j]==s[j+i]) ){
//                     dp[j][j+i]=1;
//                 }
//             }
//         }
        
//         for(int i = 0;i<s.size();i++){
//             for(int j = i; j<s.size(); j++){
//                 if(dp[i][j]){
//                     if(j-i>max){
//                         start = i;
//                         end = j;
//                         max = j-i;
//                     }
//                 }
//             }
//         }
//         return s.substr(start, end+1-start);
//     }
// };

class Solution {
public:
    bool dp[1000][1000];
    string longestPalindrome(string s) {
        int max_len = 1;
        string result;

        int len = s.length();
        for (int i = 0; i < len; i++) {
            dp[i][i] = true;
            if (i < len-1) {
                if (s[i]==s[i+1]) {
                    dp[i][i+1] =  true;
                    max_len = 2;
                }
                else {
                    dp[i][i+1] = false;
                }
            }
        }

        for (int len_substring = 3; len_substring <= len; len_substring++) {
            for (int start = 0; start <= len - len_substring; start++) {
                if (dp[start+1][start+len_substring-2]==true && s[start]==s[start+len_substring-1]) {
                    dp[start][start+len_substring-1] = true;
                    if (len_substring > max_len) {
                        max_len = len_substring;
                        result = s.substr(start, len_substring);   // 注意取子串的写法
                    }
                    
                }
                else
                    dp[start][start+len_substring-1] = false;
            }
        }
        return result;
    }
};

int main() {
    string str = "abbc";
    Solution s;
    string result = s.longestPalindrome(str);

    cout << result << endl;

    return 0;
}