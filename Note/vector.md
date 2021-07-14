# STL vector

[TOC]

## 创建、初始化

### 创建和初始化

在vector名的后面，要么加`{列表}`进行列表初始化，要么加`(参数)`初始化。

1. `vector<int> ilist1;`

    创建空vector，不初始化

2. ` vector<int> ilist {1,2,3.0,4,5,6,7};`

    `vector<int> ilist = {1,2,3.0,4,5,6,7};`

    **列表初始化（Initializer list, C++11特性）**

    如果不支持列表初始化，可以用array创建：
    ```c++
    string msg_array[5] = {"Hello", "C++", "World", "from", "VS Code!"};
    vector<string> msg(msg_array, msg_array+5);
    ```

3. `vector<int> ilist2(ilist);`

    `vector<int> ilist2  = ilist; `

    拷贝初始化

4. `vector<int> ilist3(ilist.begin()+2,ilist.end()-1);`

    通过迭代器

5. `vector<int> ilist4(7);`

    指定size

6. `vector<int> ilist5(7,3);`

    指定size和元素值



### 创建二维数组

`vector<vector<int> > dp(len, vector<int>(len, 0));`

第一个参数是长度，第二个参数是每个元素的值

C++11标准下 >> 之间可以没有空格



## 分配内存

采用第一种方式创建的vector，此时是没有分配内存的，当增加第一个元素时自动分配内存，也可以采用下面的语句进行分配：

`ilist1.reserve(20);`

即使vector中已经有元素了，也可以用上面的语句来增加分配的内存。

这条语句不影响vector内元素的情况，只影响分配的内存的大小。

但是如果执行前vector已经有内存了，那么原来的迭代器会失效，需要重新创建迭代器。
