#include <iostream>
#include <vector>

using namespace std;

int main() {
    int len=5;
    vector<vector<int> > a(len, vector<int>(len, 1));
    vector<vector<int> > b(len, vector<int>(len, 2));

    vector<vector<int> > result(len, vector<int>(len, 0));


    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len; j++)
        {
            for (int k = 0; k < len; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++)
        {
            cout << result[i][j] << ' ';
        }
        cout << endl;
    }
    

    return 0;
}