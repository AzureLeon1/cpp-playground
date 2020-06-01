# 字符串

[TOC]

## 定义与初始化

```c++
#include <string>
string str;            // 定义
string str = "hello world";   // 初始化
```

## 长度

size() 和 length()，二者功能基本相同

## 元素操作

### 访问

1. 下标访问

    ```c++
    string str = "hello world";
    for (int i = 0; i < str.size(); ++i) {
    	printf("%c ", str[i])
    }
    ```

2. 迭代器访问

    ```c++
    string str = "hello world";
    for (string::iterator it = str.begin(); it != str.end; ++it) {
      printf("%c ", *it);
    }
    ```

### 插入

在任意位置插入元素（字符串）：`str.insert(pos, str2);`

```c++
string str = "hello";
str.insert(str.size(), " world");
```

### 删除

删除任意位置的元素：`str.erase(pos, len);` 会产出从pos位置开始往后长度为len的字符串，如果不指定len，则会删除从pos开始到结尾的所有元素

```c++
str.erase(3);        // 删除从下标为3直到结尾的所有元素
str.erase(3, 2);     // 删除从下表为3开始的2个元素
```

### 清空

```c++
str.clear()
```

## 拼接

"+" 与 "+=" 运算符

## 比较

按照字典序比较：<, >, <=, >=

判断字符串是否相等：==, !=

## 常用函数

### 寻找字符或字符串

str.find(c)

str.find(sub_str)

str.find(c, pos)

str.find(sub_str, pos)

第二个参数pos是可选的，表示从pos的位置开始find

如果找到，返回下标；如果找不到，返回`string::npos`

```c++
string str = "hello world";
int found = str.find("world");    // 寻找子串
if (found != string::npos) {
	printf("'world' found at: %d\n", found);
}
found = str.find('e');           // 寻找字符
if (found != string::npos) {
	printf("'e' found at: %d\n", found);
}
```

### 取子串

str.substr(pos, len)

## 读取整行

```c++
#include <iostream>
#include <string>
...
	string str;
	getline(cin, str);
```

## 字符串匹配

KMP算法

重点是next数组的生成

主要是用于类子串匹配的问题，因为字符串问题可以用find()来找，不确定find的效率和KMP的效率谁高