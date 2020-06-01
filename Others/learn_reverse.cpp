#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int reverse_int(int x) {
    int result = 0;
    int last;         // 当前x的最低位
    while (x != 0) {
        last = x % 10;
        result = result * 10 + last;
        x = x / 10;
    }
    return result;
}

int main () {

    // 翻转字符串
    string s = "hello, world";
    // string rev_s = reverse(s.begin(), s.end());  // 这样是错的，因为reverse没有返回值
    string rev_s = s;
    reverse(rev_s.begin(), rev_s.end());

    cout << s << endl << rev_s << endl;

    // 翻转数组
    vector<int> v = {0, 1, 2, 3};
    reverse(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) {
        cout << i << " ";
    }
    cout << endl;


    // 翻转int
    cout << reverse_int(54321) << endl << reverse_int(-54321) << endl;

    return 0;
}