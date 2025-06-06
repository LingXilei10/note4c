[细说new与malloc的10点区别 - melonstreet - 博客园](https://www.cnblogs.com/QG-whz/p/5140930.html)

1、 **new/delete是C++关键字**，需要编译器支持。**malloc/free是库函数**，需要头文件支持；

2、 使用new操作符申请内存分配时无须指定内存块的大小，编译器会根据类型信息自行计算。而**malloc则需要显式地指出所需内存的尺寸**。

3、 new操作符内存分配成功时，返回的是对象类型的指针，类型严格与对象匹配，无须进行类型转换，故new是符合类型安全性的操作符。而**malloc内存分配成功则是返回void * ，需要通过强制类型转换将void*指针转换成我们需要的类型**。

4、 new内存分配失败时，会抛出bac_alloc异常。malloc分配内存失败时返回NULL。

5、 new会先调用operator new函数，申请足够的内存（通常底层使用malloc实现）。然后调用类型的构造函数，初始化成员变量，最后返回自定义类型指针。delete**先调用析构函数，然后调用operator delete函数释放内存**（通常底层使用free实现）。malloc/free是库函数，只能动态的申请和释放内存，无法强制要求其做自定义类型对象构造和析构工作。