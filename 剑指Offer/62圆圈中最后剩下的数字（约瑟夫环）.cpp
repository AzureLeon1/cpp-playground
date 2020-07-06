
// 约瑟夫环问题，用数学方法解。用链表模拟太慢了。
// 递推公式是反过来思考才容易理解。比较好的讲解：https://zhuanlan.zhihu.com/p/121831528


class Solution {
public:
    int lastRemaining(int n, int m) {
        int lastPosition = 0;
        for (int i = 2; i <= n; i++) {
            lastPosition = (lastPosition + m) % i;
        }
        return lastPosition;  // because the sequence is from 0 to n-1, so the value of number in the index of lastPosition is lastPosition
    }
};