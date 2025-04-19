在C++中，`this` 是一个指向当前对象的指针。在你提供的代码中：

```cpp
LRUCache(int capacity) {
    this->cap = capacity;
}
```

`this->cap` 表示访问当前对象的成员变量 `cap`，并将参数 `capacity` 的值赋给它。

### 为什么需要 `this`？

1. **解决命名冲突**：当**成员变量和参数名称相同时**（虽然这里不是这种情况），可以用 `this` 区分。
2. **明确性**：显式表明正在访问对象的成员变量，而**非局部变量或参数**。

### 等价写法

以下写法是等价的（更简洁，推荐）：

```cpp
LRUCache(int capacity) : cap(capacity) {}
```

这里使用成员初始化列表（member initializer list）直接初始化 `cap`，避免了 `this` 的使用。