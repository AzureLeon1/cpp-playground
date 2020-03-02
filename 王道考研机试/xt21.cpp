// 题目描述
// 一个正整数,如果它能被7整除,或者它的十进制表示法中某个位数上的数字为7, 则称其为与7相关的数.现求所有小于等于n(n<100)的与7无关的正整数的平方和。
// 输入描述:
// 案例可能有多组。对于每个测试案例输入为一行,正整数n,(n<100)
// 输出描述:
// 对于每个测试案例输出一行，输出小于等于n的与7无关的正整数的平方和。

#include <iostream>

using namespace std;

bool contain_seven (int x) {
    int last;
    while(x != 0) {
        last = x % 10;
        if (last == 7) {
            return true;
        }
        x = x / 10;
    }
    return false;
}

int main() {

    int n;

    while (cin >> n) {
        int result = 0;
        for (int i = 1; i <= n; i++) {
            if (i % 7 != 0 && !contain_seven(i)) {
                result += i * i;
            }
        }
        cout << result << endl;;
    }

    return 0;
}