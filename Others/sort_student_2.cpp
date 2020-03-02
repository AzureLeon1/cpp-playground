// 不使用stable_sort()的方法，在结构体中加入priority属性，修改cmp函数

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Stu {
    string name;
    int score;
    int priority;
};

bool cmp_0(Stu s1, Stu s2) {
    if (s1.score != s2.score) {
        return s1.score > s2.score;
    }
    else {
        return s1.priority < s2.priority;
    }
}

bool cmp_1(Stu s1, Stu s2) {
    if (s1.score != s2.score) {
        return s1.score < s2.score;
    }
    else {
        return s1.priority < s2.priority;
    }
}

int main() {

    int cnt;
    int type;
    
    while(cin>>cnt>>type) {
        string temp_name;
        int temp_score;
        vector<Stu> stus;

        for (int i = 0; i < cnt; i++) {
            cin >> temp_name >> temp_score;
            Stu stu = {temp_name, temp_score, i};
            stus.push_back(stu);
        }

        if (type == 0) {
            sort(stus.begin(), stus.end(), cmp_0);
        }
        else {
            sort(stus.begin(), stus.end(), cmp_1);
        }

        for (int i = 0; i < cnt; i++) {
            cout << stus[i].name << " " << stus[i].score << endl;
        }
    }

    return 0;
}