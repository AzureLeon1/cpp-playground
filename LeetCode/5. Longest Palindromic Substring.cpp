#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s == "") {
            return "";
        }

        int len = s.length();
        vector<vector<int> > dp(len, vector<int>(len, 0));
        int start = 0, end = 0, max = 0;
        //initialize the basic case
        for(int i = 0;i<s.size();i++){
            dp[i][i] = 1;//长度为1的子串的情况
            if((i+1)<s.size()&&s[i]==s[i+1]){//长度为2的子串的情况
                dp[i][i+1] = 1;
            }
        }
        for(int i = 2;i<s.size();i++){//i为第几个从左上到右下的对角线，i=0表示主对角线
            for(int j = 0; j<s.size()-i; j++){//j为第几行
                if(dp[j+1][j+i-1]==1 && (s[j]==s[j+i]) ){
                    dp[j][j+i]=1;
                }
            }
        }
        
        for(int i = 0;i<s.size();i++){
            for(int j = i; j<s.size(); j++){
                if(dp[i][j]){
                    if(j-i>max){
                        start = i;
                        end = j;
                        max = j-i;
                    }
                }
            }
        }
        return s.substr(start, end+1-start);
    }
};