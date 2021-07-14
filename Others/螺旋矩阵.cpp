#include <vector>
#include <iostream>

using namespace std;



class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        
        vector<int> res = {};
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        if (m == 0) return res;
        if (m == 1) return matrix[0];
        
        vector<int> delta_x = {0, 1, 0, -1};
        vector<int> delta_y = {1, 0, -1, 0};
        
        int x = 0;
        int y = 0;
        
        int i;
        for (i = 0; i < m / 2; i++) {
            if (i > 0) {
                x += 1;
                y += 1;
            }
            
            int cur_delta_x = delta_x[0];
            int cur_delta_y = delta_y[0];
            for (int j = 0; j < n-2*i-1; j++) {
                res.push_back(matrix[x][y]);
                x += cur_delta_x;
                y += cur_delta_y;
            }
            
            cur_delta_x = delta_x[1];
            cur_delta_y = delta_y[1];
            for (int j = 0; j < m-2*i-1; j++) {
                res.push_back(matrix[x][y]);
                x += cur_delta_x;
                y += cur_delta_y;
            }
            
            cur_delta_x = delta_x[2];
            cur_delta_y = delta_y[2];
            for (int j = 0; j < n -2*i-1; j++) {
                res.push_back(matrix[x][y]);
                x += cur_delta_x;
                y += cur_delta_y;
            }
            
            cur_delta_x = delta_x[3];
            cur_delta_y = delta_y[3];
            for (int j = 0; j < m-2*i-1; j++) {
                res.push_back(matrix[x][y]);
                x += cur_delta_x;
                y += cur_delta_y;
            }
            
            
            
        }
        
        if (m % 2 == 1) {
            x += 1;
            int cur_delta_x = delta_x[0];
            int cur_delta_y = delta_y[0];
            for (int j = 0; j < n-2*i; j++) {
                res.push_back(matrix[x][y]);
                x += cur_delta_x;
                y += cur_delta_y;
            }
        }
        
        
        return res;
        
        
    }
};


int main () {

    vector<vector<int> >  matrix = {{1,2,3},{4,5,6},{7,8,9}};


    Solution s;
    vector<int> ans = s.spiralOrder(matrix);



    return 0;
}