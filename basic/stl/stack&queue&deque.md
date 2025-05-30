## 栈

栈先进后出，如图所示：

![栈与队列理论2](E:\076lxl\work\note4c\basic\stl\assets\20210104235434905.png)

栈提供push 和 pop 等等接口，所有元素必须符合先进后出规则，所以栈不提供走访功能，也不提供迭代器(iterator)。 不像是set 或者map 提供迭代器iterator来遍历所有元素。

**栈是以底层容器完成其所有的工作，对外提供统一的接口，底层容器是可插拔的（也就是说我们可以控制使用哪种容器来实现栈的功能）。**

所以STL中栈往往不被归类为容器，而被归类为**container adapter（容器适配器）**。

栈的内部结构，栈的底层实现可以是vector，deque，list 都是可以的， 主要就是数组和链表的底层实现。

![栈与队列理论3](E:\076lxl\work\note4c\basic\stl\assets\20210104235459376.png)

**我们常用的SGI STL，如果没有指定底层实现的话，默认是以deque为缺省情况下栈的底层结构。**

**deque是一个双向队列，只要封住一段，只开通另一端就可以实现栈的逻辑了**。

## 队列

**SGI STL中 队列底层实现缺省情况下一样使用deque实现的。**

我们也可以指定vector为栈的底层实现，初始化语句如下：

```cpp
std::stack<int, std::vector<int> > third;  // 使用vector为底层容器的栈
```

队列中先进先出的数据结构，同样不允许有遍历行为，不提供迭代器, **SGI STL中队列一样是以deque为缺省情况下的底部结构。**

也可以指定list 为起底层实现，初始化queue的语句如下：

```cpp
std::queue<int, std::list<int>> third; // 定义以list为底层容器的队列
```

所以STL 队列也不被归类为容器，而被归类为container adapter（ 容器适配器）。

队列在计算机领域中应用也十分广泛，比如在网络通信中，**请求和响应通常以队列的形式进行排队，以确保数据按照正确的顺序进行传输，又比如说不同进程可以通过消息队列来传递数据和消息**。

## 底层适配器

容器适配器（Container Adapter）是C++标准库中的一种特殊容器，它们基于其他底层容器（如`vector`、`deque`或`list`）实现，但提供简化的接口以支持特定操作。常见的容器适配器包括：

1. **`stack`**
   - 后进先出（LIFO）结构，默认基于`deque`实现。
   - 核心操作：`push()`、`pop()`、`top()`。
2. **`queue`**
   - 先进先出（FIFO）结构，默认基于`deque`实现。
   - 核心操作：`push()`、`pop()`、`front()`、`back()`。
3. **`priority_queue`**
   - 元素按优先级排序（默认最大堆 降序），默认基于`vector`实现。
   - 核心操作：`push()`、`pop()`、`top()`。

### 特点：

- **不直接管理内存**，依赖底层容器存储数据。
- **接口受限**，仅暴露特定操作（如`stack`不提供迭代器）。
- **可指定底层容器**（例如`stack<string, list<string>>`）。

### 示例代码：

```cpp
#include <stack>
#include <queue>

std::stack<int> s;  // 默认使用deque
s.push(1);
int top = s.top();  // 获取栈顶元素

std::priority_queue<int> pq;  // 默认最大堆
pq.push(3);
pq.push(1);
int highest = pq.top();  // 获取最大值（3）
```

### 适用场景：

- 需要特定数据结构行为（如栈/队列）时。
- 避免手动实现底层逻辑，提升代码简洁性。

## 无迭代器

栈提供push 和 pop 等等接口，**所有元素必须符合先进后出规则，所以栈不提供走访功能，也不提供迭代器(iterator)**。 不像是set 或者map 提供迭代器iterator来遍历所有元素。

**栈是以底层容器完成其所有的工作，对外提供统一的接口，底层容器是可插拔的（也就是说我们可以控制使用哪种容器来实现栈的功能）。**

所以STL中栈往往不被归类为容器，而被归类为**container adapter（容器适配器）**。

### 详细解释：

在C++的**SGI STL**（Standard Template Library，标准模板库）实现中，`stack`（栈）是一种**容器适配器**，它**基于其他容器来实现其功能**。如果没有显式指定`stack`的底层容器，**默认情况下**，`stack`会使用`deque`（**双端队列）作为其底层数据结构**。

---

### 1. **为什么选择`deque`作为默认底层容器？**
`deque`具有以下特点，使其非常适合作为`stack`的底层实现：

- **动态扩展**：`deque`的内存空间是分段连续的，可以动态扩展，不需要像`vector`那样在扩容时复制整个容器。
- **高效操作**：`deque`在两端（头部和尾部）的插入和删除操作都是 **O(1)** 时间复杂度，适合栈的操作需求。
- **灵活性**：`deque`既支持从头部操作，也支持从尾部操作，而栈只需要在一端操作即可。

---

### 2. **`deque`如何实现栈的逻辑？**
`stack`是一种**后进先出（LIFO）**的数据结构，只允许在一端（通常称为栈顶）进行插入和删除操作。`deque`本身是一个**双向队列**，支持在两端进行操作。为了实现栈的逻辑，只需**封住`deque`的一端**，只允许在另一端进行操作：
- **插入（push）**：在`deque`的尾部插入元素。
- **删除（pop）**：从`deque`的尾部移除元素。
- **访问栈顶（top）**：访问`deque`的尾部元素。

通过这种方式，`deque`可以完美模拟栈的行为。

---

### 3. **代码示例**
以下是一个使用`deque`作为底层容器的`stack`示例：
```cpp
#include <stack>
#include <deque>

int main() {
    // 默认使用deque作为底层容器
    std::stack<int> myStack;

    // 插入元素
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);

    // 访问栈顶元素
    std::cout << "Top element: " << myStack.top() << std::endl; // 输出 3

    // 删除栈顶元素
    myStack.pop();

    // 再次访问栈顶元素
    std::cout << "Top element after pop: " << myStack.top() << std::endl; // 输出 2

    return 0;
}
```

---

### 4. **总结**
- **SGI STL**中，`stack`默认使用`deque`作为底层容器。
- `deque`是一个双向队列，通过封住一端，只允许在另一端操作，可以实现栈的逻辑。
- `deque`的动态扩展和高效操作使其成为`stack`的理想底层实现。



## deque

我们可以发现在stack和queue实现的过程中，模板参数容器部分有一个缺省参数deque。

<img src="E:\076lxl\work\note4c\basic\stl\assets\1d5c3451dfd8a794a6118a7e37f95c48.png" alt="img" style="zoom:33%;" />


deque(双端队列)：是一种**双开口的"连续"空间的数据结构**，双开口的含义是：可以在头尾两端进行插入和 删除操作，且时间复杂度为O(1)，**与vector比较，头插效率高，不需要搬移元素；与list比较，空间利用率比较高**。

<img src="E:\076lxl\work\note4c\basic\stl\assets\e5bb7a041c60deecf20a60a29d3798ea.png" alt="img" style="zoom:50%;" />

**deque并不是真正连续的空间，而是由一段段连续的小空间拼接而成的**，实际deque类似于一个**动态的二维数组**，其底层结构如下图所示：

<img src="E:\076lxl\work\note4c\basic\stl\assets\12572e8fa8e6a7fe507258b977b318bf.png" alt="img" style="zoom:50%;" />

<img src="E:\076lxl\work\note4c\basic\stl\assets\e9a3fc33a294c2dac2d0184d957259e3.png" alt="img" style="zoom:33%;" />

双端队列底层是一段假象的连续空间，实际是分段连续的，为了维护其“整体连续”以及随机访问的假象，落在了deque的迭代器身上，因此deque的迭代器设计就比较复杂。

如下图所示：

<img src="E:\076lxl\work\note4c\basic\stl\assets\26be0b76b87408ac1e855d24a47f5bad.png" alt="img" style="zoom:50%;" />

那deque是如何借助其迭代器维护其假想连续的结构呢？

![img](E:\076lxl\work\note4c\basic\stl\assets\648fdce712731ff39ca7a83deef1d945.png)

![img](E:\076lxl\work\note4c\basic\stl\assets\2cf2fa40b7f8775cebe53ea70dc9cc2d.png)

### deque的缺陷

与vector比较，deque的优势是：头部插入和删除时，不需要搬移元素，效率特别高，而且在扩容时，也不需要搬移大量的元素，因此其效率是必vector高的。
与list比较，其底层是连续空间，空间利用率比较高，不需要存储额外字段。
但是，deque有一个致命缺陷：不适合遍历，因为在遍历时，deque的迭代器要频繁的去检测其是否移动到某段小空间的边界，导致效率低下，而序列式场景中，可能需要经常遍历，因此在实际中，需要线性结构时，大多数情况下优先考虑vector和list，deque的应用并不多，而目前能看到的一个应用就是，STL用其作为stack和queue的底层数据结构。

5.3.3【选择deque作为底层默认容器的原因】
stack是一种后进先出的特殊线性数据结构，因此只要具有push_back()和pop_back()操作的线性结构，都可以作为stack的底层容器，比如vector和list都可以；queue是先进先出的特殊线性数据结构，只要具有push_back和pop_front操作的线性结构，都可以作为queue的底层容器，比如list。但是STL中对stack和queue默认选择deque作为其底层容器。

主要是因为：

1. stack和queue不需要遍历(因此stack和queue没有迭代器)，只需要在固定的一端或者两端进行操作。
2. 在stack中元素增长时，deque比vector的效率高(扩容时不需要搬移大量数据)；queue中的元素增长时，deque不仅效率高，而且内存使用率高。结合了deque的优点，而完美的避开了其缺陷。

总结：

虽然stack和queue中也可以存放元素，但在STL中并没有将其划分在容器的行列，而是将其称为容器适配器，这是因为stack和队列只是对其他容器的接口进行了包装，STL中stack和queue默认使用deque：



```cpp
priority_queue <int,vector<int>,less<int> > p;  // 大顶堆
priority_queue <int,vector<int>,greater<int> > q;  // 小顶堆

auto cmp = [](ListNode* a, ListNode* b) { return a->val > b->val; };
priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp); 
```



