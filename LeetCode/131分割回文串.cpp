// 根据切割位置，通过dfs来做
// 预先生成dp数组，方便查询回文串


#include<string>
#include<vector>
#include<iostream>
using namespace std;


class Solution {
public:
    
    void dfs(string s, int start, vector<string>& cur, vector<vector<string> >& res, vector<vector<int> >& dp) {
        if (s=="") {
            res.push_back(cur);
            return;
        }

        for (int i = 1; i <= s.length(); i++) {
            string sub = s.substr(0, i);
            if (dp[start][start+i-1]) {
                cur.push_back(sub);
                dfs(s.substr(i, s.length()-i), start+i, cur, res, dp);
                cur.pop_back();
            }
        }
    }
    vector<vector<string> > partition(string s) {
        int len = s.length();

        vector<vector<int> > dp (len, vector<int>(len, 0));
    //    memset(dp, 0, sizeof(dp));

        for (int i = 0; i < len; i++) {
            dp[i][i] = 1;
            if (i < len-1 && s[i]==s[i+1]){
                dp[i][i+1] = 1;
            }
        } 
        for (int n = 2; n < len; n++) {
            for (int i = 0; i < len - 1; i++) {
                int j = i + n;
                if (i < len && j < len && dp[i+1][j-1]==1 && s[i]==s[j]) {
                    dp[i][j] = 1;
                }
            }
        }

        vector<vector<string> > res;
        vector<string> cur;
        dfs(s, 0, cur, res, dp);
        return res;
    }
};

int main() {
    string str = "aab";

    Solution s;
    vector<vector<string> > res = s.partition(str);

    return 0;
}