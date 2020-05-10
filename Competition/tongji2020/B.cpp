// c++ 切分字符串 split 的实现
// 数学化简
// 输出格式一定要按照要求来，即使自己以为不需要

#include <string>
#include <vector>
#include <iostream>
#include <string.h>
#include <iomanip>


using namespace std;

long double damage = 0;
string origin;
vector<string> ss;
double temp_damage = 0;

const double eps = 1e-10;

int n, x, a;

vector<string> split(const string& s, const string& sep)
{
	vector<string> v; 
    string::size_type pos1, pos2;
    pos2 = s.find(sep);
    pos1 = 0;
    while(string::npos != pos2)
    {
        v.push_back(s.substr(pos1, pos2-pos1));

        pos1 = pos2 + sep.size();
        pos2 = s.find(sep, pos1);
    }
    if(pos1 != s.length())
        v.push_back(s.substr(pos1));
    return v;
}

int main() {

    cin >> origin;

    ss = split(origin, "+");

    for (int i=0; i<ss.size(); i++) {
        vector<string> temp_s = split(ss[i], "d");
        if (temp_s.size() == 1) {
            // cout<<"fix"<<endl;
            a = double(stoi(temp_s[0]));
            damage += a;
        }
        else {
            // cout<<"non-fix"<<endl;
            n = stoi(temp_s[0]);
            x = stoi(temp_s[1]);
            damage += (double)n * (double)(x+1) / 2.0;
        }
    }
    // cout << damage;

    // 竟然真的是小数位数的问题 wa了3次
    if (damage-(double)(int)damage < eps) {
        cout<< (long long)damage;
    }
    else {
        cout << setprecision (1); 
	    cout.setf(ios::fixed,ios::floatfield);
        cout << damage;

    }

    return 0;
}

// 1d6+1d70+1d10+6+1d70+1d10+6+1d70+1d10+6+1d70+1d10+6+1d70+1d10+6+1d70+1d10+6+1d70+1d10+6+1d70+1d10+6+1d70+1d10+6