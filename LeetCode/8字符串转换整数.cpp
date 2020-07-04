// 自动机
// 难点：越界的处理，转换成long long进行计算


#include<iostream>
#include<string>

using namespace std;

// 解法一：使用long long的解法
// class Solution {
// public:
//     int myAtoi(string str) {


//         long long res = 0;

//         bool flag = false;           // 正数 or 负数
//         bool sign_has_used = false; 
//         int sign = 1;                // 转换是否已经正式开始（已处理完开头的无用字符）
//         int len = str.length();
//         for (int i = 0; i < len; ++i) {
//             if (flag==false && str[i]==' ') {
//                 continue;
//             }
//             if (flag==false && str[i]=='+') {
//                 flag = true;
//                 continue;
//             }
//             if (flag==false && str[i]=='-') {
//                 sign = -1;
//                 flag = true;
//                 continue;
//             }
//             if (flag==false && !isdigit(str[i])) {
//                 return 0;
//             }
//             if (isdigit(str[i])) {

//                 if (sign==1)
//                     res = min((long long)INT_MAX, res * 10 + sign * (long long)(str[i] - '0'));
//                 if (sign==-1)
//                     res = max((long long)INT_MIN, res * 10 + sign * (long long)(str[i] - '0'));

//                 if (res==INT_MAX || res==INT_MIN)
//                     return res;

//                 if (flag==false) {
//                     flag = true;
//                 }

//             }
//             if (flag==true && !isdigit(str[i])) {
//                 break;
//             }
//         }
//         return res;
        
//     }
// };

// 解法二：通过计算判断是否越界
class Solution {
public:
    int myAtoi(string str) {


        int res = 0;

        bool flag = false;           // 正数 or 负数
        bool sign_has_used = false; 
        int sign = 1;                // 转换是否已经正式开始（已处理完开头的无用字符）
        int len = str.length();
        for (int i = 0; i < len; ++i) {
            if (flag==false && str[i]==' ') {
                continue;
            }
            if (flag==false && str[i]=='+') {
                flag = true;
                continue;
            }
            if (flag==false && str[i]=='-') {
                sign = -1;
                flag = true;
                continue;
            }
            if (flag==false && !isdigit(str[i])) {
                return 0;
            }
            if (isdigit(str[i])) {

                int cur_digit = str[i] - '0';

                if (res > (INT_MAX - cur_digit)/10)
                    return INT_MAX;
                else if (res < (INT_MIN + cur_digit)/10) 
                    return INT_MIN;

                if (sign==1)
                    res = res * 10 + sign * cur_digit;
                if (sign==-1)
                    res = res * 10 + sign * cur_digit;

                if (flag==false) {
                    flag = true;
                }

            }
            if (flag==true && !isdigit(str[i])) {
                break;
            }
        }
        return res;
        
    }
};

int main() {
    // string str = "-2147483649";
    // string str = "3.1415926";
    string str = "2147483646";


    Solution s;
    int res = s.myAtoi(str);

    cout << res << endl;

    return 0;
}