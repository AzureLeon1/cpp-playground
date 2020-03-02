// 题目描述
// 设N是一个四位数，它的9倍恰好是其反序数（例如：1234的反序数是4321）
// 求N的值
// 输入描述:
// 程序无任何输入数据。
// 输出描述:
// 输出题目要求的四位数，如果结果有多组，则每组结果之间以回车隔开。

#include <iostream>

using namespace std;

int reverse(int x) {
    int result = 0;
    int last;         // 当前x的最低位
    while (x != 0) {
        last = x % 10;
        result = result * 10 + last;
        x = x / 10;
    }
    return result;
}

int main() {

    for (int i = 1000; i <= 1111; i++) {
        if (9 * i == reverse(i)) {
            cout << i << endl;
        }
    }

    return 0;
}