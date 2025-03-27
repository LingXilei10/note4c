## auto

**C++11中的auto关键字**是用来自动推导表达式或变量的实际类型的。使用auto关键字做类型自动推导时，依次施加一下规则：如果初始化表达式是引用，则去除引用语义。

### 补充

auto在C++11中是一种新的类型说明符,它可以根据初始化表达式自动推导出变量的类型。

auto的工作原理是:

- 编译器看到auto,会查看初始化表达式的类型,并将该类型作为auto变量的类型。
- 如果初始化表达式的类型可以确定,则使用该类型。如果初始化表达式包含了多个类型,则使用与初始化表达式兼容的共同类型。
- 如果无法确定类型,则报错。

例如:

```
auto x = 5; // x是int类型 
auto y = 1.5; // y是double类型 
auto z = x + y; // z是double类型 

std::vector&lt;int&gt; 
vec; auto itr = vec.begin(); // itr是std::vector&lt;int&gt;::iterator类型 
```

在上面例子中,编译器通过查看初始化表达式的类型,推导出auto变量的实际类型。

需要注意的是,auto只在声明时确定一次变量类型,之后变量类型不再改变，并且**auto变量必须初始化,才能推导出类型**。

## 模板

模板是一种通用的编程技术，可以用于实现泛型编程，即编写一个通用的类或函数，可以适用于多种不同的数据类型。在C++中，模板是通过模板参数来实现的。模板参数可以是一个类型、一个整数或者一个枚举类型。在使用模板时，需要为每个要使用的类型提供一个对应的模板参数。

## 参考代码

```
template <typename T>
class MyClass {
public:
    void setValue(T value) {
        this->value = value;
    }

    T getValue() const {
        return value;
    }

private:
    T value;
};
```