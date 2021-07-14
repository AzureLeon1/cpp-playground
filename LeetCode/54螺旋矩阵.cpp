#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        vector<int> res;

        int m = matrix.size();
        int n = matrix[0].size();

        if (m == 0 || n == 0) return res;

        int left = 0, right = n - 1, top = 0, bottom = m - 1;

        while (left <= right && top <= bottom) {
            for (int col = left; col <= right; col++) {
                res.push_back(matrix[top][col]);
            }
            for (int row = top + 1; row <= bottom; row++) {
                res.push_back(matrix[row][right]);
            }
            // 注意下面的条件
            if (left < right && top < bottom) {
                for (int col = right - 1; col > left; col--) {
                    res.push_back(matrix[bottom][col]);
                }
                for (int row = bottom; row > top; row--) {
                    res.push_back(matrix[row][left]);
                }
            }
            left++;
            right--;
            top++;
            bottom--;
        }


        return res;

    }
};
int main() {

    // vector<vector<int>> mat = {{1,2,3},{4,5,6},{7,8,9}};
    // vector<vector<int>> mat = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    // vector<vector<int>> mat = {{1,2,3},{4,5,6},{7,8,9},{10,11,12}};
    // vector<vector<int>> mat = {};
    vector<vector<int>> mat = {{2,3,4},{5,6,7},{8,9,10},{11,12,13},{14,15,16}};





    Solution s;
    vector<int> res = s.spiralOrder(mat);

    for (auto ele : res) {
        cout << ele << " ";
    }

    return 0;
}