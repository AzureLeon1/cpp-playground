// 整数翻转
// 1. 不需要特别处理正负号，翻转代码本身可以处理
// 2. 要注意int越界问题。处理思路：判断执行乘法后是否越界，可以计算INT_MAX和INT_MIN执行除法的值进行比较
// 3. 判断越界的其他思路：可以把int转成unsigned来判断


public:
    int reverse(int x) {
        if (x == 0) {
            return 0;
        }
        // bool is_positive;   // 不需要判断正负，翻转代码本身能够处理正负的问题
        // if (x > 0) {
        //     is_positive = true;
        // }
        // else {
        //     is_positive = false;
        // }
        // x = abs(x);

        int result = 0;
        while(x!=0) {
            if(result > INT_MAX / 10) return 0;        //判断是否将要发生越界
            if(result < INT_MIN / 10) return 0;    

            int temp = x % 10;
            result = result * 10 + temp;
            x = x / 10;
        }

        // result = is_positive ? result : (-1)*result;
        return result;
    }
};