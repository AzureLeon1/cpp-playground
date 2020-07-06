// KMP 算法
// 注意主串和模式串各自为空字符串的情况，审题

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:

    vector<int> getNext(string& s) {
        int len = s.length();
        vector<int> next(len, 0);
        int i = -1;
        int j = 0;
        next[j] = -1;
        while (j < len-1) {
            if (i==-1 || s[i]==s[j]) {
                i++; j++;
                next[j] = i;
            }
            else {
                i = next[i];
            }
        }
        return next;
    }

    int kmp(string& haystack, string& needle) {
        int res = -1;

        vector<int> next = getNext(needle);

        int len1 = haystack.length();
        int len2 = needle.length();

        int i = 0, j = 0;
        while (i < len1 && j < len2) {
            if (j==-1 || haystack[i]==needle[j]) {
                i++; j++;
            }
            else {
                j = next[j];
            }
        }
        if (j == len2) {
            return i - j;
        }
        return res;
    }
    int strStr(string haystack, string needle) {
        if (needle.length()==0) {
            return 0;
        } 
        if (haystack.length()==0) {
            return -1;
        }

        int res = kmp(haystack, needle);

        return res;
    }
};

int main() {

    string haystack = "aaa";
    string needle = "aaa";

    Solution s;
    int res = s.strStr(haystack, needle);

    cout << res << endl;

    return 0;
}