# redis 学习笔记



## typedef

为类型取一个新名字。为单字节数字定义一个术语BYTE

```c
typedef unsigned char BYTE;
```

定义unsigned char变量可写为：

```c
BYTE b1, b2;
```

注意有分号结尾

```
typedef int * int_ptr;
与#define int_ptr int * 
作用都是用int_ptr代表 int * 
```



typedef char* a[3]

定义一个数据类型a,这种类型的变量是有3个char* 类型元素的一个数组.



可以为定义的数据类型取一个新名字

```c
#include <stdio.h>
#include <string.h>
 
typedef struct Books
{
   char  title[50];
   char  author[50];
   char  subject[100];
   int   book_id;
} Book;
 
int main( )
{
   Book book;
 
   strcpy( book.title, "C 教程");
   strcpy( book.author, "Runoob"); 
   strcpy( book.subject, "编程语言");
   book.book_id = 12345;
 
   printf( "书标题 : %s\n", book.title);
   printf( "书作者 : %s\n", book.author);
   printf( "书类目 : %s\n", book.subject);
   printf( "书 ID : %d\n", book.book_id);
 
   return 0;
}
```

## typedef vs #define

**#define** 是 C 指令，用于为各种数据类型定义别名，与 **typedef** 类似，但是它们有以下几点不同：

- **typedef** 仅限于为类型定义符号名称，**#define** 不仅可以为类型定义别名，也能为数值定义别名，比如您可以定义 1 为 ONE。
- **typedef** 是由编译器执行解释的，**#define** 语句是由预编译器进行处理的。