**二分查找**

排好序的数据 -> 联想到二分查找

进行二分时要注意 low 和 high的值，不要越界

---

**极限**

```c++
#include <limits>
numeric_limits<T>::min()
numeric_limits<T>::max()

or

#include <limits>
INT_MIN
INT_MAX
```

---

**翻转int**

```c++
int reverse(int x) {
    int result = 0;
    int last;         // 当前x的最低位
    while (x != 0) {
        last = x % 10;
        result = result * 10 + last;
        x = x / 10;
    }
    return result;
}
```

**翻转string、vector**

调用`<algorithm>`中的reverse()，注意reverse()是没有返回值的。如果想保留原数据，要先拷贝一份，再调用reverse函数。

头文件：`algorithm`

```c++
#include <algorithm>
...
// 翻转string
string s = "test String"
string copy = s;
reverse(copy.begin(), copy.end());
// 翻转vector
vector<int> v = {0, 1, 2, 3};
reverse(v.begin(), v.end());
```
---

**==运算符用于数组**

C++中可以用 == 比较两个数组的值是否相等

---

**string的length(), size(), strlen()**

c++ 中 string 的 length() 和 size() 是完全一样的，但是与 C 中 string 的strlen() 不同，strlen() 统计到 '\0' 的长度，而length和size获得的是完整字符串的长度。

---

**避免在循环中重复申请内存**

如果一道题的输入包括多组数据，要把变量、数组等在while循坏之前定义并申请内存，尤其是数组，避免在处理每组数据时重新申请。

---

**合并循环**

有些循环是可以合并的，例如为数组中一个正方形的四条边赋值，用一个循环就可以完成，不用分成四个循环。

---

**memset()**

注意参数的顺序

头文件：`<string>`

虽然头文件是string，但是memset()不仅可以用于string，还可以用于其他数据结构，如数组

```c++
char map[80][80];    
memset(map, '*', sizeof(map));
```

---
