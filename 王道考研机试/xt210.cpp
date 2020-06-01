// 没审好题，做错了，同级目录要合并，以后有空再改吧

#include <iostream>
#include <string>

using namespace std;

int main() {

    int n;
    string str;
    int start, end;
    int pre_space;
    cin >> n;
    getchar();
    while (n != 0) {
        for (int i = 0; i < n; ++i) {
            getline(cin, str);
            start = 0;
            pre_space = 0;
            end = str.find('\\');
            while (true) {
                if (end != string::npos) {
                    for (int j = 0; j < pre_space; ++j) {
                        cout << ' ';
                    }
                    cout << str.substr(start, end-start) << endl;
                    if (end == str.size() - 1)
                        break;
                    pre_space = pre_space + (end-start) + 1;
                    start = end + 1;
                    end = str.find('\\', start);
                }
                else {
                    for (int j = 0; j < pre_space; ++j) {
                        cout << ' ';
                    }
                    cout << str.substr(start, (str.size() - start)) << endl;
                    break;
                }
            }
            
        }

        cin >> n;
    }

    return 0;
}