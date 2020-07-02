#include<queue>
#include<iostream>

using namespace std;

// struct Element
// {
//     int x;
//     int y;
//     // Element() {}
//     // Element(int x, int y): x(x), y(y) {}
//     bool operator < (const Element& e2) {
//         return x < e2.x;
//     }
// };

class Element
{
public:
    int x;
    int y;
    Element() {}
    Element(int x, int y): x(x), y(y) {}
    bool operator < (const Element& e2) {
        return x < e2.x;
    }
};


int main() {

    priority_queue<int> pq;
    pq.push(1);
    pq.push(2);

    priority_queue<Element> pq2;
    Element e1(1, 2);
    pq2.push(e1);

    return 0;
}