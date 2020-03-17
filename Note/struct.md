struct的使用



定义：

```c++
sturct Stu {
  string name;
  int score;
}
```

创建：

```c++
Stu stu = {"Wang Liang", 60};
```

注意要用大括号

C++11之后好像可以用类的构造函数的方式（即使在没有显示写出构造函数的情况下，会调用默认的构造函数）来创建，但C++11好像还不行。