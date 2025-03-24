``` c
string s("abcabcabc");
unordered_set<char> uset;
for(auto e:s){
    uset.insert(e);
}

// 定义uset不可以是string类型
// 使用string的迭代器区间进行构造。
unordered_set<char> uset(str.begin(), str.end()); 
// 构造string对象某段区间的复制品
 


```

## map

map支持键值的自动排序，底层机制是红黑树，红黑树的查询和维护时间复杂度均为$O(logn)$，但是空间占用比较大，因为每个节点要保持父节点、孩子节点及颜色的信息

## set

set与map类似，Set的底层实现通常也是红黑树。Set是一种特殊的Map，只有键没有值。

## unordered_map

unordered_map是C++ 11新添加的容器，底层机制是哈希表，通过hash函数计算元素位置，其查询时间复杂度为O(1)，维护时间与bucket桶所维护的list长度有关，但是建立hash表耗时较大.

## unordered_set

unordered_set: 与unordered_map类似，unordered_set的底层实现通常也是哈希表。unordered_set是一种特殊的unordered_map，只有键没有值。

从底层机制和特点可以看出：map适用于有序数据的应用场景，unordered_map适用于高效查询的应用场景.

