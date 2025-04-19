![image-20250417170440456](E:\076lxl\work\note4c\labuladong\assets\image-20250417170440456.png)

哈希表+链表

清晰使用key索引

o2c[p]->next 查询对应的clone，并构造他的next指针连接

= oct[p->next] 连接到p->next的clone

## labuladong

这道题目，就属于会者不难，难者不会的那类题，后面他还可以给你变出更多花样，比如克隆带随机指针的二叉树，你会不会？那再让你克隆图，你会不会？

**对于数据结构复制，甭管他怎么变，你就记住最简单的方式：一个哈希表 + 两次遍历**。

第一次遍历专门克隆节点，借助哈希表把原始节点和克隆节点的映射存储起来；第二次专门组装节点，照着原数据结构的样子，把克隆节点的指针组装起来。

题目如果让你克隆带随机指针的二叉树，或者克隆图，都是一样的，只不过是遍历的方式从 for 循环迭代遍历变成 `traverse` 递归函数遍历罢了。

**详细题解**：

- [【强化练习】哈希表更多习题](https://labuladong.online/algo/problem-set/hash-table/)

## 解法代码

 cpp🤖 go🤖 java🟢 javascript🤖 python🤖 

Copy

```cpp
// 注意：cpp 代码由 chatGPT🤖 根据我的 java 代码翻译。
// 本代码的正确性已通过力扣验证，如有疑问，可以对照 java 代码查看。

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> originToClone;
        // 第一次遍历，先把所有节点克隆出来
        for (Node* p = head; p != nullptr; p = p->next) {
            if (originToClone.find(p) == originToClone.end()) {
                originToClone[p] = new Node(p->val);
            }
        }
        // 第二次遍历，把克隆节点的结构连接好
        for (Node* p = head; p != nullptr; p = p->next) {
            if (p->next != nullptr) {
                originToClone[p]->next = originToClone[p->next];
            }
            if (p->random != nullptr) {
                originToClone[p]->random = originToClone[p->random];
            }
        }
        // 返回克隆之后的头结点
        return originToClone[head];
    }
};

// 用递归的方式进行遍历
class Solution2 {
public:
    Node* copyRandomList(Node* head) {
        traverse(head);
        return originToClone[head];
    }

private:
    // 记录 DFS 遍历过的节点，防止走回头路
    unordered_set<Node*> visited;
    // 记录原节点到克隆节点的映射
    unordered_map<Node*, Node*> originToClone;

    // DFS 图遍历框架
    void traverse(Node* node) {
        if (node == nullptr) {
            return;
        }
        if (visited.find(node) != visited.end()) {
            return;
        }
        // 前序位置，标记为已访问
        visited.insert(node);
        // 前序位置，克隆节点
        if (originToClone.find(node) == originToClone.end()) {
            originToClone[node] = new Node(node->val);
        }
        Node* cloneNode = originToClone[node];

        // 递归遍历邻居节点，并构建克隆图
        // 递归之后，邻居节点一定存在 originToClone 中

        traverse(node->next);
        cloneNode->next = originToClone[node->next];

        traverse(node->random);
        cloneNode->random = originToClone[node->random];
    }
};
```