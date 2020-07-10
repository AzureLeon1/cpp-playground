#include <vector>
#include <math.h>
#include <stack>
#include <iostream>

using namespace std;

// 方法：单调栈，栈内只存对应的下标index即可
// https://blog.csdn.net/Zolewit/article/details/88863970
// 理解的关键点：左边沿和右边沿的概念。右边沿是根据单调入栈的特点来直接确定的，找左边沿的过程就是出栈的过程，最后根据栈顶元素或是否空栈来确定左边沿
// 注意遇到第一个递减元素位置时开始出栈，此时是跟还未入栈的heights[i]作比较，出栈的元素都是大于等于heights[i]的元素

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        if (heights.size()==0)
            return 0;

        if (heights.size()==1)
            return heights[0];

        int res = 0;
        heights.push_back(0);    // trick: 原数组最后补一个0，使得原来的最后一个元素之后也是递减的
        int num = heights.size();
        stack<int> st;


        for (int i = 0; i < num; ++i) {
            if (st.empty() || heights[st.top()]<=heights[i])  // 如果是空栈，或者仍然是在单调递增的，则直接压栈
                st.push(i);        // push到栈中的是下标i
            else {
                int temp_res = 0;
                while (!st.empty() && heights[st.top()]>heights[i]) {
                    int temp_index = st.top();
                    st.pop();
                    if (st.empty())                    // 如果是空的，说明heights[i]左边所有元素都比它小
                        temp_res = heights[temp_index] * (i);
                    else
                        temp_res = heights[temp_index] * (i - st.top() - 1);
                    res = max(res, temp_res);
                }
                st.push(i);
            }
        }
        return res;
    }
};

// class Solution {
// public:
//     int largestRectangleArea(vector<int> &height) {
//         int res = 0;
//         stack<int> st;
//         height.push_back(0);
//         for (int i = 0; i < height.size(); ++i) {
//             if (st.empty() || height[st.top()] < height[i]) {
//                 st.push(i);
//             } else {
//                 int cur = st.top(); st.pop();
//                 res = max(res, height[cur] * (st.empty() ? i : (i - st.top() - 1)));
//                 --i;
//             }     
//         }
//         return res;
//     }
// };

int main () {

    vector<int> data = {2,3,3,4};

    Solution s;
    int res = s.largestRectangleArea(data);

    cout << res << endl;

    return 0;
}