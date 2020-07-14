#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <sstream>

using namespace std;

int maxSquare(vector<vector<int> >& arr) {
    if (arr.size() == 0 || arr[0].size() == 0) {
        return 0;
    }
    int res = 0;
    int rows = arr.size();
    int cols = arr[0].size();
    vector<vector<int> > dp(rows, vector<int>(cols));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (arr[i][j] == 1) {
                if (i == 0 || j == 0) {
                    dp[i][j] = 1;
                } 
                else {
                    dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
                }
                res = max(res, dp[i][j]);
            }
        }
    }
    return res;
}


int main() {

    vector<vector<int> > arr;

    // input data
    string temp;
    int pos;
    getline(cin, temp);
    while(temp!="") {
        vector<int> cur_vec;
        string cur;
        stringstream input(temp);
        while(input >> cur) {
            cur_vec.push_back(atoi(cur.c_str()));
            // cout<<atoi(cur.c_str())<<endl;
        }
        arr.push_back(cur_vec);
        getline(cin, temp);
        // getchar();
        // getchar();
    }

    int res = maxSquare(arr);

    cout << res;


    return 0;
}