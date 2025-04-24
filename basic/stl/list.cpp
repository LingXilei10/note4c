//==================initialization==================

#include <list>

int n = 7;

// 初始化一个空的双向链表 lst
std::list<int> lst;

// 初始化一个大小为 n 的链表 lst，链表中的值默认都为 0
std::list<int> lst(n);

// 初始化一个包含元素 1, 3, 5 的链表 lst
std::list<int> lst{1, 3, 5};

// 初始化一个大小为 n 的链表 lst，其中值都为 2
std::list<int> lst(n, 2);


//============================func===============================

#include <iostream>
#include <list>
using namespace std;

int main() {
    // 初始化链表
    list<int> lst{1, 2, 3, 4, 5};

    // 检查链表是否为空，输出：false
    cout << lst.empty() << endl;

    // 获取链表的大小，输出：5
    cout << lst.size() << endl;

    // 在链表头部插入元素 0
    lst.push_front(0);
    // 在链表尾部插入元素 6
    lst.push_back(6);

    // 获取链表头部和尾部元素，输出：0 6
    cout << lst.front() << " " << lst.back() << endl;

    // 删除链表头部元素
    lst.pop_front();
    // 删除链表尾部元素
    lst.pop_back();

    // 在链表中插入元素
    auto it = lst.begin();
    // 移动到第三个位置
    advance(it, 2);
    // 在第三个位置插入 99
    lst.insert(it, 99);

    // 删除链表中某个元素
    it = lst.begin();
    // 移动到第二个位置
    advance(it, 1);
    // 删除第二个位置的元素
    lst.erase(it);

    // 遍历链表
    // 输出：1 99 3 4 5
    for (int val : lst) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}


//===================origin===================
struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x): val(x),next(nullptr) {}
};

ListNode *dummynode = new ListNode(0);
ListNode *cur = dummynode;
int val;
cin>>val;
for(int i=0;i<n;i++){
    ListNode *newnode = new ListNode(val);
    cur->next = newnode;
    cur = cur->next;
}

void printnode(ListNode *head){
    ListNode *cur =head;
    while(cur->next!=NULL){
        cout<<cur->next->val<<" ";
        cur = cur->next;
    }
}



//===================create===================
ListNode *createLinkedList(vector<int> arr){
    if(arr.empty()){
        return nullptr;   //  head = nullptr;
    }
    else{
        ListNode *head = new ListNode(arr[0]);
        ListNode *cur = head;
        for(int i=1; i<arr.size(); i++){
            cur->next = new ListNode(arr[i]);
            cur = cur->next;
        }
        return head;
    }
}
//=================遍历=====================
for(ListNode *p=head;p!=nullptr; p=p->next){
    cout<<p->val;
}
//====={1,2,3,4,5}========
//===================增删=====================
//在第3个后、第4个之前加一个 指向第3个 
head = createLinkedList({1,2,3,4,5});
ListNode *cur = head;
for(int i=0;i<2;i++){
    cur = cur->next;
}
ListNode *newnode = new ListNode(0);
newnode->next = cur->next;
cur->next = newnode;

//删去第4个  还是指向第3个

cur->next = cur->next->next;

