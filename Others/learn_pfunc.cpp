// C++中函数作为函数的参数的写法，需要用typedef定义一个类型。用typedef是为了更加简洁，如果不用typedef也可以。
// .NET课上讲到C#中用delegate类型来实现函数作为函数的参数，顺便学习下C/C++中该怎么写

#include <iostream>

using namespace std;

typedef void (*CFUN)(const char* name);

void greetInEnglish(const char* name) {
    cout << "Morning, " << name << endl;
}

void greetInChinese(const char* name) {
    cout << "早上好, " << name << endl;
}

void greetPeople (const char* name, CFUN greetFun) {
    greetFun(name);
}

int main() {

    CFUN f1 = greetInEnglish;
    CFUN f2 = greetInChinese;

    greetPeople("Leon Wang", f1);
    greetPeople("小王", f2);

    return 0;
}