排好序的数据 -> 联想到二分查找


极限：

```c++
#include <limits>
numeric_limits<T>::min()
numeric_limits<T>::max()

or

#include <limits>
INT_MIN
INT_MAX
```



进行二分时要注意 low 和 high的值，不要越界



翻转数组

```c++
string s = "test String"
reverse(copy.begin(), copy.end());
```



C++中可以用 == 比较两个数组的值是否相等



c++ 中 string 的 length() 和 size() 是完全一样的，但是与 C 中 string 的strlen() 不同，strlen() 统计到 '\0' 的长度，而length和size获得的是完整字符串的长度。


