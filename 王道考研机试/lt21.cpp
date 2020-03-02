// 设a、b、c均是0到9之间的数字，abc、bcc是两个三位数，且有：abc+bcc=532。求满足条件的所有a、b、c的值。

// 输入描述:
// 题目没有任何输入。

// 输出描述:
// 请输出所有满足题目条件的a、b、c的值。
// a、b、c之间用空格隔开。
// 每个输出占一行。

#include <iostream>

using namespace std;

int main() {

    int num1, num2, sum;

    for (int a = 1; a <= 5; a++) {
        for (int b = 0; b <= 9; b++) {
            for (int c = 0; c <= 9; c++) {
                // num1 = a * 100 + b * 10 + c * 1;
                // num2 = b * 100 + c * 10 + c * 1;
                // sum = num1 + num2;

                // 对上面进行数学推导可以进行简化
                sum = a * 100 + b * 110 + c * 12;
                if (sum == 532) {
                    cout << a << " " << b << " " << c << endl;
                }
            }
        }
    }

    return 0;
}