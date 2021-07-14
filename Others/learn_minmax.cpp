#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int a = 10, b = 20;

    // int res = min(a, b);
    int res = max(a, b);

    cout << res << endl;

    vector<int> v = {3, 1, 5, 0, 9};

    vector<int>::iterator it = max_element(begin(v), end(v));
    cout << *it << endl;

    return 0;
}