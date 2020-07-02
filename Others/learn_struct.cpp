#include<iostream>

using namespace std;

struct Ele {
    int x;
    int y;
    Ele () {}
    Ele (int x, int y) : x(x), y(y) {}
};

int main() {

    Ele e;
    e.x = 1;
    e.y = 2;

    Ele e2(2, 3);

    return 0;
}