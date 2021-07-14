#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {

    // 1. 列表初始化
    vector<int> a {1, 2, 3};
    vector<int> b = {1, 2, 3};

    // 2. 创建空vector
    vector<int> c;

    // 3. 拷贝初始化
    vector<int> d(a);
    vector<int> e = a;

    // 4. 通过迭代器
    vector<int> f(a.begin()+1, a.end()-1);

    // 5. 指定size、指定size和值
    vector<int> g(5);
    vector<int> h(5, 1);

    a[2] = 4;  // 拷贝创建的d和e不会改变

    b.reserve(10);  // 分配内存，不会影响现有的元素


    // 创建二维数组
    vector<vector<int>> aa(5, vector<int>(4, 1));

    cout << a[1] << endl;
    cout << b[1] << endl;

    sort(a.begin(), a.end(), less<int>());  // 第三个参数默认是 less<int>()
    for (auto& e : a) {
        cout << e << " ";
    }
    cout << endl;

    sort(a.begin(), a.end(), greater<int>());
    for (auto& e : a) {
        cout << e << " ";
    }
    return 0;
}