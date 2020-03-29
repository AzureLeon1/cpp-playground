// 叠筐
// 模拟 - 图形排版
// 思路：很难把图形规律转换成输出规律，所以现在内存中构造，再统一输出；注意剔除最外面四个角；注意边界情况

#include <iostream>

using namespace std;

int main() {

    int n;
    char x, y;

    char map[80][80];          // 在循环外部申请内存，避免循环你多次申请内存
    memset(map, '*', sizeof(map));

    bool firstCase = true;     // 控制输出格式

    while (cin >> n >> x >> y) {

        if (firstCase) {
            firstCase = false;
        }
        else {
            cout << endl;
        }

        int num_circle = n / 2;  // 圈数
        for (int i = 0; i <= num_circle; i++) {
            // 把这圈置为对应的字符
            int j = n - i - 1;      // 这圈的左上角是(i, i)， 右下角是(j, j)
            int length = j - i + 1;   // 这圈的边长
            char current_char;                   // 这圈填充用的字符
            if ((n/2 - i) % 2 == 0) {
                current_char = x;
            }
            else {
                current_char = y;
            }
            for(int k = 0; k < length; k++) {
                map[i][i+k] = current_char;      // 上边
                map[i+k][j] = current_char;      // 右边
                map[i+k][i] = current_char;      // 左边
                map[j][i+k] = current_char;      // 下边
            }
        }

        // 剔除最外面四个角（边界条件：n==1时不需要）
        if (n != 1) {
            map[0][0] = ' ';
            map[0][n-1] = ' ';
            map[n-1][0] = ' ';
            map[n-1][n-1] = ' ';
        }

        // output
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << map[i][j];
            }
            cout << endl;
        }
        
    }

    return 0;
}