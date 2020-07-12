#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        
        int len1 = text1.size();
        int len2 = text2.size();

        if (len1==0 || len2==0)
            return 0;

        vector<vector<int>> dp(len1+1, vector<int>(len2+1, 0));


        for(int i = 0; i < len1+1; i++) {
            dp[i][0] = 0;
        }
        for (int i = 0; i < len2+1; i++) {
            dp[0][i] = 0;
        }

        for (int i = 1; i <=len1; i++) {
            for (int j = 1; j <= len2; j++) {
                if (text1[i-1]==text2[j-1]) {         // 注意dp数组的下标比string的下标多1，因为dp数组开头多了一行和一列
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        return dp[len1][len2];
    }
};

int main() {
    string text1 = "abc";
    string text2 = "def";
    Solution s;
    s.longestCommonSubsequence(text1, text2);

    return 0;
}