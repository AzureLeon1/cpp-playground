// 超时版本，不需要这么麻烦，直接用最大公约数做就好了，在 A-2.cpp 里

#include <unordered_set>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int t;
int n, a, b;
unordered_set<int> s;
// vector<int> vector_s;
unordered_set<int> candidate_s;

int cnt=0;

int main() {

    cin>>t;

    for (int z=0; z<t; z++) {
        cnt = 0;
        queue<int> candidate;
        s.clear();
        candidate_s.clear();
        // vector_s.clear();

        cin >> n >> a >> b;

        s.insert(a);
        s.insert(b);


        if(a+b <= n) {
            candidate.push(a+b);
            candidate_s.insert(a+b);
            cnt++;
        }

        if (a < b) {
            swap(a, b);
        }
        if(a-b > 0 && (a-b)!=b) {
            candidate.push(a-b);
            candidate_s.insert(a-b);
            cnt++;
        }

        while(!candidate.empty()) {
            
            int cand = candidate.front();
            for(unordered_set<int>::iterator it=s.begin(); it!=s.end(); it++) {
                int temp = *it;
                // cout<< temp << endl;

                int sum = cand + temp;
                int diff = (cand>temp)?(cand-temp):(temp-cand);
                if ( sum <= n && s.find(sum)==s.end() && candidate_s.find(sum)==candidate_s.end() ) {
                    candidate.push(sum);
                    candidate_s.insert(sum);
                    cnt++;
                }
                if ( diff > 0 && s.find(diff)==s.end() && candidate_s.find(diff)==candidate_s.end() ) {
                    candidate.push(diff);
                    candidate_s.insert(diff);
                    cnt++;
                }
            }

            candidate.pop();
            candidate_s.erase(cand);
            s.insert(cand);
        }

        cout << cnt << endl;
        if (cnt%2==1) {
            cout << "Yes";
        }
        else {
            cout << "No";
        }

        if (z<t-1){
            cout << endl;
        }


    }


    return 0;
}