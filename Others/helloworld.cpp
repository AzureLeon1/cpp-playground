#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{


    // valid in C++11 (initializer list)
    vector<string> msg = {"Hello", "C++", "World", "from", "VS Code!"};

    // if initializer list is not supported
    // string msg_array[5] = {"Hello", "C++", "World", "from", "VS Code!"};
    // vector<string> msg(msg_array, msg_array+5);
    

    // valid in C++14, invalid in C++11 (foreach)
    // for (const string& word : msg)
    // {
    //     cout << word << " ";
    // }
    // cout << endl;

    // if foreach is not supoorted
    for (int i = 0; i < msg.size(); i++) {
        cout << msg[i] << " ";
    }
    cout << endl;

    vector<string>::iterator it;
    for (it = msg.begin(); it < msg.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    // test input
    cout << "Input a int number: ";
    int n;
    cin >> n;
    cout << n << endl;

    // test operator %
    cout << (-3) % 10 << endl;
    
    return 0;
}