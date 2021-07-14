#include <iostream>

using namespace std;

void func(int m[][2]) {
    cout << m[0][0] << endl;
    m[0][0] = 9;
}

int main() {

    int mat[2][2] = {{1,2}, {3,4}};

    func(mat);

    cout << mat[0][0] << mat[1][1];

    return 0;
}