# 链表

```cpp
private:
    template <typename E>
    class Node {
    public:
        E val;
        Node* next;
        Node* prev;

        Node(Node* prev, E element, Node* next) {
            this->val = element;
            this->next = next;
            this->prev = prev;
        }
    };
```

这段代码定义了一个模板类 `Node`，它是一个双向链表节点（doubly linked list node）。我们来详细解释一下每个部分：

### 类的声明和访问控制

- `private:`：这行说明 `Node` 类是私有的，意味着它只能在其外层类（假设存在一个围绕该模板类的其它类）内部访问。这是为了封装，更好地控制访问权限。

### 模板类声明

- `template <typename E>`：这是一个模板声明，表示 `Node` 类是一个通用类，可以接受任何类型 `E` 作为其元素类型。在使用时，你可以用具体的数据类型（如 `int`、`string` 等）来替代 `E`。

### 节点成员

```cpp
public:
    E val;
    Node* next;
    Node* prev;
```
- `E val;`：这是节点中存储的值，类型为 `E`。每个 `Node` 对象可以存储一种类型的值（由使用模板时指定）。
  
- `Node* next;`：这是一个指向下一个节点的指针，类型为 `Node*`。这使得链表能够链接多个节点，每个节点知道其后继节点。

- `Node* prev;`：这是一个指向前一个节点的指针，类型也为 `Node*`。这使得链表能够反向链接，节点也可以访问其前驱节点。

### 构造函数

```cpp
Node(Node* prev, E element, Node* next) {
    this->val = element;
    this->next = next;
    this->prev = prev;
}
```

- 这是 `Node` 类的构造函数，它会在创建一个新的 `Node` 对象时被调用。构造函数接受三个参数：
  - `Node* prev`：指向前一个节点的指针，用于设置当前节点的前驱。
  - `E element`：当前节点的值，这个值将被存储在 `val` 中。
  - `Node* next`：指向下一个节点的指针，用于设置当前节点的后继。

- 在构造函数的主体中，通过 `this->` 关键字，分别将传入的 `element`、`next` 和 `prev` 指针赋值给 `val`、`next` 和 `prev` 成员变量。这使得每个新创建的节点都能正确地维护对其周围节点的引用。

### 总结

这个 `Node` 类用于双向链表的实现。每个节点持有一个值，并有指针指向其前后相邻的节点，使得链表的遍历和操作（如插入、删除）更加灵活。如果你有关于链表或模板的其他问题或想深入了解相关知识，随时告诉我！


## 函数
```cpp
std::list<int> lst(n);
// 增
lst.push_front();
lst.push_back();
auto it = lst.begin();
advance(it,2);
lst.insert(it,11);
//删
lst.pop_front();
lst.pop_back();
lst.erase(it+2);
//查
lst.front();
lst.back();
lst.empty();
lst.size();
//改
for (int val : lst) {
        cout << val << " ";
    }
```
`lst.begin()` 和 `lst.front()` 是 C++ 中 `std::list` 容器（或其他 STL 容器）上的两个不同的成员函数，它们的功能有所区别：

### `lst.begin()`
- **返回值**：返回一个**迭代器（iterator），指向列表的第一个元素**。
- **用途**：可以使用这个迭代器来遍历列表，进行更复杂的操作，比如在循环中访问每个元素，或者进行插入、删除等操作。
- **示例**：
  ```cpp
  std::list<int> lst = {1, 2, 3};
  auto it = lst.begin(); // it 是一个指向 lst 第一个元素的迭代器
  std::cout << *it; // 输出 1
  ```

### `lst.front()`
- **返回值**：返回列表中的第一个元素的引用。这个引用是**直接访问元素值**的，不需要通过迭代器。
- **用途**：适用于你想要直接访问第一个元素值的情况，非常简洁高效。
- **示例**：
  ```cpp
  std::list<int> lst = {1, 2, 3};
  int firstElement = lst.front(); // firstElement 是 1
  std::cout << firstElement; // 输出 1
  ```

### 总结
- `lst.begin()` 用于获取指向第一个元素的迭代器，可以用于**遍历**和其他容器操作。
- `lst.front()` 则是直接获取第一个元素的值，适合简单的**访问操作**。

如果你有更多问题或者需要进一步的解释，随时告诉我！
