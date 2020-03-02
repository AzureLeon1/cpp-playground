// 题目描述
//     用小于等于n元去买100只鸡，大鸡5元/只，小鸡3元/只,还有1/3元每只的一种小鸡，分别记为x只,y只,z只。编程求解x,y,z所有可能解。
// 输入描述:
//     测试数据有多组，输入n。
// 输出描述:
//     对于每组输入,请输出x,y,z所有可行解，按照x，y，z依次增大的顺序输出。

//分析：x+y+z=100; 5x+3y+(1/3)z<=n; 因为有输出顺序的限制，所以要注意循环的顺序

#include <iostream>

using namespace std;

int main() {

    int n;
    while (cin >> n)
    {
        for (int x = 0; x <= 100; x++) {
            for (int y = 0; y <= 100 - x; y++) {
                int z = 100 - x - y;
                if (15 * x + 9 * y + z <= 3 * n) {
                    cout << "x=" << x << ",y=" << y << ",z=" << z << endl;
                }
            }
        }
    }

    return 0;
}
