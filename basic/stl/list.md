## 定义

```cpp
class ListNode{
    public:
        int val;
        ListNode *next;
        ListNode(int x): val(x),next(nullptr) {} //记得加int x
};

private:
    template <typename E>   //  ?
    class Node {
    public:
        E val;
        Node* next;
        Node* prev;

        Node(Node* prev, E element, Node* next) {
            this->val = element;    // this->  ??
            this->next = next;
            this->prev = prev;
        }
    };

```

## 创建

```cpp
class ListNode {
public:
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 输入一个数组，转换为一条单链表
ListNode* createLinkedList(std::vector<int> arr) {
    if (arr.empty()) {
        return nullptr;
    }
    ListNode* head = new ListNode(arr[0]);
    ListNode* cur = head;
    for (int i = 1; i < arr.size(); i++) {
        cur->next = new ListNode(arr[i]);
        cur = cur->next;
    }
    return head;
}
```

## 查改

```cpp
// 创建一条单链表
ListNode* head = createLinkedList({1, 2, 3, 4, 5});

// 遍历单链表
for (ListNode* p = head; p != nullptr; p = p->next) {
    std::cout << p->val << std::endl;
}
```

经典遍历链表循环体！！

```cpp
// 我的
ListNode *dummyhead = new ListNode(0);
ListNode *cur =dummyhead;
for(int i=0;i<arr.size();i++){
    ListNode *newnode = new ListNode(arr[i]);
    cur->next = newnode;   // cur->next = new ListNode(arr[i]);
    cur = cur->next;
}
return dummyhead->next;

ListNode *cur=dummyhead;
while(cur!=nullptr){
    cout<<cur->val<<endl;
    cur=cur->next;
}
```

