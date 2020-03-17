// 输出梯形
// tag: 模拟 - 图形排版

#include <iostream>

using namespace std;

int main() {

    int h;

    while (cin >> h) {
        // calculate
        int col = h + (h - 1) * 2;      // 总列数
        for (int i = 0; i < h; i++) {
            int num_star = h + 2 * i;
            int num_space = col - num_star;
            for (int j = 0; j < num_space; j++) {
                cout << " ";
            }
            for (int k = 0; k < num_star; k++) {
                cout << "*";
            }
            cout << endl;
        }
    }

    return 0;
}