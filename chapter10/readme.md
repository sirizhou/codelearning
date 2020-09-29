# chapter 10
## 单步执行和跟踪函数调用

```c
#include <stdio.h>

int add_range(int low, int heigh) {
    int i, sum;
    for (i = low; i <= heigh; i ++) {
        sum = sum + i;
    }
    return sum;
}

int main(void)
{
    int result[100];
    result[0] = add_range(1, 10);
    result[1] = add_range(1, 100);
    printf("result[0]=%d\nresult[1]=%d\n", result[0], result[1]);
    return 0;
}
```
编辑加上-g选项

```shell
gcc -g lear_gdb.c -o main
```
使用gdb调试
```shell
gdb main
```

从第一行开始列出源代码
```shell
list 1
```
一次只列10行，从第11行继续列出源代码可以输入
```shell
list
```
也可以直接敲回车
回车表示适当的参数重复上一条指令


list可以写为l，要列一个函数的源代码也可以好似用函数名作为参数
```shell
l add_range
```
退出gdb
```shell
quit
```

**使用next指令（简写为n）控制语句一句一句执行**

**使用start指令重新开始运行**

**使用step命令（简写为s）进入函数中去**

**使用finish跳出函数**

使用backtrace（bt）查看函数调用的栈

**使用info命令查看局部变量值，简写为i**
```shell
i locals
```
使用frame（简写f）切换帧栈，然后使用i locals查看局部变量值

使用print（简写p）打印变量值
```shell
p sum
```

跟改变量的值
```shell
set var sum=0
```


## 断点

display : 每次停下来都现实值
```shell
display sum
```
undisplay 取消跟踪

设置断点 break命令（简写为b）
```shell
b 9
```
break命令的参数也可以是函数名，表示在某一个函数开头设断点

**使用continue指令连续运行（简写c），程序遇到断点自动停下**

i breakpoints 显示设置的断点

停用断点 
```shell
disable breakpoints 3
```
启用
```shell
enable breakpoints 2
```
删除断点
```shell
delete breakpoints
```
## 观察点
x命令打印存储器中的内容
```shell
x/7b
```
7b是打印格式，b表示每个字节一组，7表示7组

条件断点设置
```shell
b 12 if i == 4
```
当i==4时在12行打断点

watch观察点进行跟踪，当程序访问某一内存单元时中断
```shell
watch i
```
使用c继续
当i发生变化时中断

删除断点
```shell
delete breakpoints 4
```
