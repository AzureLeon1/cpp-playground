// 题目：输入任意（用户，成绩）序列，可以获得成绩从高到低或从低到高的排列,相同成绩
// 都按先录入排列在前的规则处理。

// input:
// 输入多行，先输入要排序的人的个数，然后输入排序方法0（降序）或者1（升序）再分别输入他们的名字和成绩，以一个空格隔开
// 3
// 0
// fang 90
// yang 50
// ning 70

// output:
// 按照指定方式输出名字和成绩，名字和成绩之间以一个空格隔开
// fang 90
// ning 70
// yang 50

// 使用stable_sort()的解法

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

struct Student {

    string name;
    int score;
};

bool cmp_1(Student s1, Student s2) {
    return s1.score < s2.score;
}

bool cmp_2(Student s1, Student s2) {
    return s1.score > s2.score;
}

int main() {

    int cnt;
    int type;
    // cin >> cnt;
    // cin >> type;

    while (cin >> cnt >> type) {
        vector<Student> stus;

        for (int i = 0; i < cnt; i++) {
            string temp_name;
            int temp_score;
            cin >> temp_name >> temp_score;
            Student stu = {temp_name, temp_score};
            stus.push_back(stu);
        }

        if (type == 1) {
            stable_sort(stus.begin(), stus.end(), cmp_1);
        }
        else {
            stable_sort(stus.begin(), stus.end(), cmp_2);
        }

        for (int i = 0; i < cnt; i++) {
            cout << stus[i].name << " " << stus[i].score << endl;
        }
    }
    return 0;
}