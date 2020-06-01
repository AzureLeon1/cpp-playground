#include <iostream>
#include <string>

using namespace std;

int main (){
    
    string s;
    getline(cin, s);
    
    int len = s.size();
    for (int i = 0; i < len; ++i) {
        if (s[i]=='z') {
            s[i] = 'a';
            continue;
        }
        if (s[i]=='Z') {
            s[i] = 'A';
            continue;
        }
        if (( s[i] >= 'a' && s[i] <= 'z') || ( s[i] >= 'A' && s[i] <= 'Z'))
            s[i]++;
        
    }
    
    cout << s;
    
    
    
    return 0;
}