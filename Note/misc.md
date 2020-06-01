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

两个问题：

1. 正负

    这段代码完美处理了正负的问题，不需要特别考虑

2. 溢出

    有可能还要考虑翻转后会溢出的问题

```c++
int reverse(int x) {
    int result = 0;
    int last;         // 当前x的最低位
    while (x != 0) {
        if(result > INT_MAX / 10) return 0;        // 这两句判断溢出是可选的，根据实际情况判断是否需要
        if(result < INT_MIN / 10) return 0;  
      
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

**填充：memset()、fill()**

注意参数的顺序

memset()的头文件：`<cstring>`

虽然头文件是cstring，但是memset()不仅可以用于char[]，还可以用于其他数据结构。

但是如果填充其他数据结构如int数组，最好用0填充，因为memset是按一个字节为单位填充的，而int有四个字节，所以是填充了四次，如果填充的不是0，填充后的值是不正确的。

总而言之，memset()是一种填充内存的手段，它以一个字节为单位填充成所给的字符，并不关心要填充的数据结构具体是什么。如果要填充的对象不是char[]，最好都用0进行填充。

int数组最好用fill函数进行填充，fill需要的参数与memset不同。

```c++
// 用 memset 填充 char[]
char str[80];
memset(str, '@', sizeof(str));

// 用 memset 填充 int[] 只能填充0
int arr[80];
memset(arr, 0, sizeof(arr));

// 用 fill 填充 int[] 可以填充任意整数值
int arr2[80];
fill(arr2, arr2+80, 7);
```

---
**使用变量作为数组长度**

C++中一般是不能使用变量作为一个数组的长度的，必须使用常量。
这是因为数组作为C++的内置数据类型，其空间分配在栈内存中，这部分空间的大小在编译时就要确定，不能等到运行时再分配。常量的值在编译时就能得到，而变量的值在运行时才能确定。
但是仍然有办法使用变量作为数组的长度：绕过栈内存，将数组空间开辟在堆空间内：

```c++
int *d = new int[n];
```

这样这块内存就是自己开辟的了，可以使用变量初始化数组的长度，内存空间会在运行时动态分配。

```c++
char** temp = new char* [n];
for (int i = 0; i < n; i++) {
    temp[i] = new char[n];
}
```

创建n*n的二维数组

注意：

使用完这个数组后要delete掉，防止内存泄漏。
如果可能的话，使用STL容器替代内置的数组类型，能得到更好的性能和撸代码体验。

---

**输入数据的组数**

注意题目要求多少组输入

```c++
while(cin>>n) {

}
while(scanf("%d", &n)!=EOF) {
  
}
```

scanf()的返回值是成功赋值的变量个数，如上述语句如果成功为变量n赋值，则scanf的返回值是1

cin>>n的返回值要更复杂一点：cin>>n返回的是一个cin对象，当一个cin对象作为条件选择、循环等的控制表达式时，编译器会将其转换为真值表达式，如果cin的iostate为goodbit，则这个真值表达式的结果为真，否则为假。

输入一个非数字可以置位failbit，从而结束循环，当然这是一个非正常退出。

正常退出可以用键盘模拟产生EOF，表示流输入结束了。在windows中可以输入ctrl+z，unix/linux中则为ctrl+d。

---

**大数组写在main()之外，防止栈溢出**

大的数组比如`map[3000][3000]`请写在main()之外，这样数组分配到Data Segment（全局/静态数据区），如果在main()内部，则会分配到Stack（栈区），导致栈溢出。

而且的区别在于：

- Data Segment的大小取决去剩余内存的大小
- Stack的大小通常是固定的，比如2M。因此容易导致栈溢出

> [C++ 初始化数组过大，如何解决开大数组内存溢出的问题](https://blog.csdn.net/qq_36770641/article/details/88852924)

---

**输入字符串：get, getline, gets**

https://blog.csdn.net/JIEJINQUANIL/article/details/50802902

~~读取整行时，尽量用cin.getline()，不要用gets()，gets()不安全~~

~~使用cin.getline可能需要先用getchar()吸收换行符~~

~~但是注意cin.getline的第二个参数，表示接收字符的个数，最后一个是'\n'，实际上只接受n-1个字符~~

~~开辟char[]的时候多开一个位置，存放'\0'~~

读取整行时，用 `getline(cin, str);`，需要 include 两个头文件：`<iostream>`和`<string>`

---

**stl容器的erase方法**

vector不要用循环来erase。对于vector来说，每次erase之后，iterator会自动指向下一个元素。
vector直接传两个参数，起点索引和终点索引来erase。

---

**map与unordered_map**

unordered_map比map要快。
map基于红黑树实现，unordered_map基于哈希表。

---

**树**

TODO:
map
自定义
```c++
struct tree {
    tree* _parent;
    tree* _sibling;
    tree* _child;
    ...
}
```

---

**精度问题**

cout输出比较大的整数时，会自动变成科学计数法如1e6。如果要保持格式，应该写清楚

```c++
#include <iomanip>
cout << setprecision (1); 
cout.setf(ios::fixed,ios::floatfield);
```

---

---

**int 与 string 转换**

int 转 string

- `string s = to_string(a)`
- `string s = itoa(a)`(非C/C++标准，移植性不好)

string 转 int

- `int a = atoi(s.c_str())`atoi接受const char *类型的参数，所以要先把string转成c格式的字符串

---

**i++ 与 ++i**

++i 是左值，理论上效率比 i++ 高一点。但实际上效率区别不明显，而且实际还要取决于编译器

---

**负数取余的结果是负数**

负数取余最后是负数

比如 (-3) % 10 等于 -3，不是7

---

