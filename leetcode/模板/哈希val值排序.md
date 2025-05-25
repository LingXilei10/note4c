

将哈希表按照val值从小到大排序

```cpp
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

int main() {
    std::unordered_map<int, int> umap = {{1, 3}, {2, 1}, {3, 2}};

    // 将 unordered_map 转换为 vector<pair<int, int>>，以便排序
    std::vector<std::pair<int, int>> vec(umap.begin(), umap.end());

    // 使用 sort 对 vector 进行排序
    std::sort(vec.begin(), vec.end(), [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
        return a.second < b.second; // 按照 value 升序排序
    });

    // 输出排序后的结果
    for (const auto& p : vec) {
        std::cout << "{" << p.first << ", " << p.second << "} ";
    }

    return 0;
}
```

