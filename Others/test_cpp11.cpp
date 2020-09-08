#include <iostream>
#include <assert.h>
#include <map>

using namespace std;

int main() {

    auto a = 10;
    cout << "[c++11 auto]: " << a << endl;

    assert(&a != nullptr);
    cout << "[c++11 nullptr]: " << "nullptr ok" << endl;

    map<int, string> m {{1, "hello"}, {2, "world"}, {3, "^_^"}};
    for (auto i : m) {
        cout << "[c++11 for]" << i.first << " - " << i.second << endl;
    }

    return 0;
}