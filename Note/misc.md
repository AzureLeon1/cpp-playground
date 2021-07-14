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

但是如果填充其他数据结构如int数组，最好用0或-1填充，因为memset是按一个字节为单位填充的，而int有四个字节，所以是填充了四次，如果填充的不是0或-1，填充后的值是不正确的。

总而言之，memset()是一种填充内存的手段，它以一个字节为单位填充成所给的字符，并不关心要填充的数据结构具体是什么。如果要填充的对象不是char[]，最好都用0进行填充。

int数组最好用fill函数进行填充，fill需要的参数与memset不同。

```c++
memset()要include头文件 <cstring>，因为本身就是给cstring初始化用的函数

// 用 memset 填充 char[]
char str[80];
memset(str, '@', sizeof(str));

// 用 memset 填充 int[] 只能填充0或-1z
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

使用getline可能需要先用getchar()吸收换行符

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
- ~~`string s = itoa(a)`(非C/C++标准，移植性不好)~~

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

**树的BFS**

树的BFS有两个模板，用于不同的情况：

1. 如果不需要确定当前遍历到了哪一层，BFS模板如下。

    ```
    while queue 不空：
        cur = queue.pop()
        for 节点 in cur的所有相邻节点：
            if 该节点有效且未访问过：
                queue.push(该节点)
    ```

2. 如果要确定当前遍历到了哪一层，BFS模板如下。
    这里增加了level表示当前遍历到二叉树中的哪一层了，也可以理解为在一个图中，现在已经走了多少步了。size表示在当前遍历层有多少个元素，也就是队列中的元素数，我们把这些元素一次性遍历完，即把当前层的所有元素都向外走了一步。

    ```
    level = 0
    while queue 不空：
        size = queue.size()
        while (size --) {
            cur = queue.pop()
            for 节点 in cur的所有相邻节点：
                if 该节点有效且未被访问过：
                    queue.push(该节点)
        }
        level ++;
    ```

总结：区别在于，对于场景2，遍历的过程不是一个while循环，而是要按层再分，每层的循环的次数用queue.size()得到

---

**构造整数时判断是否越界**

例题：

- LeetCode 8：my atoi
- LeetCode 7：整数翻转

方法一：用long long计算，然后取max or min

```c++
if (sign==1)
    res = min((long long)INT_MAX, res * 10 + sign * (long long)cur_digit);
if (sign==-1)
    res = max((long long)INT_MIN, res * 10 + sign * (long long)cur_digit);

if (res==INT_MAX || res==INT_MIN)
    return res;
```

方法二：用int计算，就是把 res*10+cur_digit>INT_MAX 或者 res\*1-cur_digit<INT_MIN转换一下形式

```c++
if (res > (INT_MAX - cur_digit)/10)
    return INT_MAX;
else if (res < (INT_MIN + cur_digit)/10) 
    return INT_MIN;
```

---

**C++中的堆与优先级队列**

http://c.biancheng.net/view/481.html

priority_queue的底层实现是堆

prioity_queue的优势： priority_queue 可以提供堆没有的优势，它可以自动保持元素的顺序；但我们不能打乱 priority_queue 的有序状态，因为除了第一个元素，我们无法直接访问它的其他元素。如果需要的是一个优先级队列，这一点非常有用。

堆的优势：从另一方面来说，使用 make_heap() 创建的堆可以提供一些 priority_queue 没有的优势：

1. 可以访问堆中的任意元素，而不限于最大的元素，因为元素被存储在一个容器中，就像是我们自己的 vector。这也提供了偶然破坏元素顺序的可能，但是总可以调用 make_heap() 来还原堆。
2. 可以在任何提供随机访问迭代器的序列容器中创建堆。这些序列容器包括普通数组、string 对象、自定义容器。这意味着无论什么时候需要，都可以用这些序列容器的元素创建堆，必要时，可以反复创建。甚至还可以为元素的子集创建堆。

总结：区别有两点：1. 是否允许当前的有序状态被破坏 2. 是否允许随机访问非队首/堆顶的元素

---

**优先级队列**

> 注意：需要自己实现cmp，其中大于号对应最小优先级队列（最小堆）
>
> 另外，cmp需要是一个struct，然后重载()运算符，不能直接创建一个cmp()函数

```c++
#include<queue>
using namespace std;

struct Ele {
    int x;
    int y;
    int val;
    Ele () {}
    Ele(int x, int y, int val) : x(x), y(y), val(val) {}
};

struct cmp
{
    bool operator() (Ele& e1, Ele& e2) {
        return e1.val > e2.val;
    }
};

int main() {
  //...
  priority_queue<Ele, vector<Ele>, cmp> pq;
}
```

---

**struct 与 class**

C++ 中保留了C语言的 struct 关键字，并且加以扩充。在C语言中，struct 只能包含成员变量，不能包含成员函数。而在C++中，struct 类似于 class，既可以包含成员变量，又可以包含成员函数。

C++中的 struct 和 class 基本是通用的，唯有几个细节不同：

- 使用 class 时，类中的成员默认都是 private 属性的；而使用 struct 时，结构体中的成员默认都是 public 属性的。
- class 继承默认是 private 继承，而 struct 继承默认是 public 继承。
- class 可以使用模板，而 struct 不能。

---

