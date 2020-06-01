// 直接暴力枚举就过了

#include <iostream>
#include <string>
using namespace std;

int main () {
    string s;
    while (cin >> s) {
        int len = s.size();
        bool is_first = false;
        for (int i = 0; i < len; ++i) {
            if (s[i] != '*') {
                for (int j = i+1; j < len; ++j) {
                    if (s[i] == s[j]) {
                        if (!is_first) {
                            cout << s[i] << ':' << to_string(i);
                            is_first = true;
                        }
                        cout << ',' << s[i] << ':' << to_string(j);
                        s[j] = '*';
                    }
                }
                if (is_first) {
                    cout << endl;
                    is_first = false;
                }
            }
        }
        
    }
    return 0;
}