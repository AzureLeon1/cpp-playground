#include<string>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);
        int len = s.length();
        for (int i = 0; i < len/2; ++i) {
            if (s[i] != s[len-1-i])
                return false;
        }
        return true;
    }
};