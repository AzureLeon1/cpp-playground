// Hello World for U
// 模拟-图形排版

#include <iostream>
#include <cstring>
#include <string>

using namespace std;

char map[30][30];

int main() {

    string s;

    while(cin >> s) {

        memset(map, ' ', sizeof(map));

        // cout << s.length() << endl;
        int n = s.length();
        
        // compute width and height
        int height = (n+2)/3;
        int width = (n+2) - 2 * height;

        for (int i = 0; i < n; i++) {
            if (i < height) {
                map[i][0] = s[i];
            }
            else if (i < height + width -1) {
                map[height - 1][i - height + 1] = s[i];
            }
            else {
                map[n - 1 - i][width - 1] = s[i];
            }
        }

        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                cout << map[i][j];
            }
            cout << endl;
        }
    }

    return 0;
}