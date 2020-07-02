#include <unordered_set>
#include <iostream>

using namespace std;

int main() {

    unordered_set<int> s;
    s.insert(1);
    s.insert(99);
    bool found = (s.find(99)!=s.end());
    cout << found << endl;
    return 0;
}