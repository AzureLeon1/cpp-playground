// 题目描述
//     Among grandfather's papers a bill was found.     72 turkeys $_679_     The first and the last digits of the number that obviously represented the total price of those turkeys are replaced here by blanks (denoted _), for they are faded and are illegible. What are the two faded digits and what was the price of one turkey?     We want to write a program that solves a general version of the above problem.     N turkeys $_XYZ_     The total number of turkeys, N, is between 1 and 99, including both. The total price originally consisted of five digits, but we can see only the three digits in the middle. We assume that the first digit is nonzero, that the price of one turkeys is an integer number of dollars, and that all the turkeys cost the same price.     Given N, X, Y, and Z, write a program that guesses the two faded digits and the original price. In case that there is more than one candidate for the original price, the output should be the most expensive one. That is, the program is to report the two faded digits and the maximum price per turkey for the turkeys.
// 输入描述:
//     The first line of the input file contains an integer N (0<N<100), which represents the number of turkeys. In the following line, there are the three decimal digits X, Y, and Z., separated by a space, of the original price $_XYZ_.
// 输出描述:
//     For each case, output the two faded digits and the maximum price per turkey for the turkeys.

//分析：猜一个五位数，这个五位数的中间三位已知，要求这个五位数能被N整除，如果有多种可能，去最大的那个五位数，按照贪心的思想从大到小进行枚举


#include <iostream>

using namespace std;

int main() {

    int n;
    int x, y,z;
    int price_per_turckey;
    bool has_found = false;

    while (cin >> n)
    {
        has_found = false;
        cin >> x >> y >> z;
        for(int i = 9; i>= 1; i--) {
            if (has_found) {
                break;
            }
            for (int j = 9; j >=0; j--) {
                if ( (i*10000 + x*1000 + y*100 + z*10 + j) % n == 0) {
                    price_per_turckey = (i*10000 + x*1000 + y*100 + z*10 + j) / n;
                    cout << i << " " << j << " " << price_per_turckey << endl;
                    has_found = true;
                    break;
                }
            }
        }
        if (!has_found)
        {
            cout << 0 << endl;    // if can not find result
        }
        
    }

    return 0;
}