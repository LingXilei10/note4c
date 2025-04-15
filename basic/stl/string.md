`s.substr()` 是 C++ 标准库中 `std::string` 类的成员函数，用于**提取字符串的子串**。它的作用是**从原字符串中截取一部分内容，返回一个新的字符串**。

------

### 基本语法

```cpp
string substr(size_t pos = 0, size_t len = npos) const;
```

- **pos**：起始位置（从0开始索引）
- **len**：要截取的长度（默认到字符串末尾）
- **返回值**：新的子字符串

------

### 常见用法示例

1. **截取从位置2到末尾**：

   ```cpp
   string s = "Hello World";
   string sub = s.substr(2); // 得到 "llo World"
   ```

2. **截取从位置2开始的3个字符**：

   ```cpp
   string sub = s.substr(2, 3); // 得到 "llo"
   ```

3. **截取最后5个字符**：

   ```cpp
   string sub = s.substr(s.size() - 5); // 得到 "World"
   ```

------

### 典型应用场景

1. 解析文件路径：

   ```cpp
   string path = "/home/user/file.txt";
   string filename = path.substr(path.find_last_of('/') + 1);
   ```

2. 处理CSV数据：

   ```cpp
   string data = "apple,orange,banana";
   string fruit = data.substr(0, data.find(',')); // 得到 "apple"
   ```

3. 文本处理：

   ```cpp
   string msg = "Error: 404 Not Found";
   string code = msg.substr(6, 3); // 提取错误码 "404"
   ```

如果需要处理大量子串且关注性能，可考虑 `string_view` (C++17)。