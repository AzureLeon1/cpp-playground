// 找找规律，当成等差数列来算

class Solution {
public:
    int lastRemaining(int n) {
        int first = 1;
        int diff = 1;
        int cnt = n;
        bool from_left = true;
        while(cnt>1) {
            if (from_left) {
                first += diff;
            }
            else {
                if (cnt % 2 == 1) {
                    first += diff;
                }
            }
            diff *= 2;
            cnt /= 2;
            from_left = !from_left;
        }
        return first;
    }
};