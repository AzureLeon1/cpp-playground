// 总结：主要包括两部分：求next数组、进行匹配
// 两个部分中都有双指针while循环，比较像，但含义是不一样的。求next数组时，两个指针都在pattern串上滑动，而且从一开始
// i就落后于j一个身位；而在进行匹配时，两个指针分别在主串和模式串上，一开始都从下标0开始


#include<string>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace  std;


// j 从 0 开始，i 从 -1 开始。如果匹配或i==-1，则i++、j++并记录next。否则i回退。
vector<int> getNextTable(string& pattern) {
    int length = pattern.length();
    vector<int> next = vector<int>(length, 0);
    int j = 0;
    next[j] = -1;
    int i = next[j];
    while (j < length) {
        if (i==-1 || pattern[i]==pattern[j]) {
            i++; j++;
            next[j] = i;
        }
        else {
            i = next[i];
        }
    }
    return next;
}


// i, j 都从0开始
int KMP(string& text, string& pattern) {
    int len_text = text.length();
    int len_pattern = pattern.length();

    int res = 0;

    vector<int> next = getNextTable(pattern);

    int i = 0;
    int j = 0;
    while (i < len_pattern && j < len_text) {
        if (i==-1 || pattern[i]==text[j]) {
            i++;
            j++;
        }
        else {
            i = next[i];
        }
    }
    
    if (i == len_pattern) {      // successful
        res = j - len_pattern;
    }
    else {                            // fail
        res = -1;
    }
    return res;
}


int main () {

    string text = "ABABACABDABABADBA";

    string pattern = "ABABAD";

    int position = KMP(text, pattern);

    cout << "match position: " << position << endl;

    int verify_position = text.find(pattern);
    cout << "verify using STL: " << verify_position << endl;

    return 0;
}