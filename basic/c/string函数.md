标准库函数（strcpy、strcmp、memcpy、memcmp）

## strcspn

`strcspn` 是 C 语言标准库中的一个字符串处理函数，用于计算一个字符串中不包含指定字符集合的第一个字符的子串长度。它的名字来源于 "string complement span"，即计算字符串中与指定字符集合互补的部分的跨度。

### 函数原型
```c
size_t strcspn(const char *s1, const char *s2);
```

### 参数
- `s1`：需要检查的源字符串。
- `s2`：包含要排除的字符的字符串。

### 返回值
返回 `s1` 中从开头开始到第一个出现在 `s2` 中的字符为止的子串长度。如果 `s1` 中没有字符出现在 `s2` 中，则返回 `s1` 的长度。

### 作用
`strcspn` 的作用是找到 `s1` 中第一个出现在 `s2` 中的字符的位置，并返回该位置之前的子串长度。换句话说，它**计算 `s1` 中不包含 `s2` 中任何字符的最长前缀的长度**。

### 示例
假设我们有以下代码：
```c
#include <stdio.h>
#include <string.h>

int main() {
    const char *s1 = "hello world";
    const char *s2 = "abcde";
    size_t result = strcspn(s1, s2);

    printf("Result: %zu\n", result);
    return 0;
}
```

在这个例子中：
- `s1` 是 `"hello world"`。
- `s2` 是 `"abcde"`。
- `strcspn` 会检查 `s1` 中的第一个字符 `'h'` 是否在 `s2` 中，发现不在。
- 继续检查 `'e'`，也不在。
- 继续检查 `'l'`，也不在。
- 依次检查，直到遇到 `'o'`，`'o'` 不在 `s2` 中。
- 继续检查 `' '`（空格），空格不在 `s2` 中。
- 继续检查 `'w'`，也不在。
- 继续检查 `'o'`，也不在。
- 继续检查 `'r'`，也不在。
- 继续检查 `'l'`，也不在。
- 继续检查 `'d'`，发现 `'d'` 在 `s2` 中。

因此，`strcspn` 返回从 `s1` 的开头到 `'d'` 之前的子串长度，即 `"hello worl"` 的长度，结果为 `10`。

### 常见用途
1. **去掉字符串末尾的换行符**：
   ```c
   char str[100];
   fgets(str, sizeof(str), stdin); // 读取一行，可能包含换行符
   str[strcspn(str, "\n")] = '\0'; // 去掉换行符
   ```
   在这个例子中，`strcspn(str, "\n")` 返回 `str` 中第一个换行符之前的部分的长度，然后通过将该位置的字符设置为 `\0`，去掉换行符。

2. **分割字符串**：
   `strcspn` 可以用于分割字符串，例如在解析 CSV 文件时，可以用来找到第一个逗号的位置。

3. **字符串过滤**：
   可以用来过滤掉某些字符。例如，如果想过滤掉字符串中的所有数字，可以使用 `strcspn`。

### 注意事项
- `strcspn` 只返回子串的长度，不会修改原字符串。
- 如果 `s1` 中没有字符出现在 `s2` 中，`strcspn` 返回 `s1` 的长度。
- `s2` 中的字符可以重复，但重复的字符不会影响结果。



在 C 语言中，`strcpy`、`strcmp`、`memcpy` 和 `memcmp` 是标准库 `<string.h>` 中的常用函数。虽然这些函数在标准库中已经高度优化，但理解它们的实现方式可以帮助我们更好地理解字符串和内存操作的底层机制。以下是这些函数的简单实现方式。

## strcpy
`strcpy` 函数用于将一个字符串复制到另一个字符串中。

**函数原型：**

```c
char *strcpy(char *dest, const char *src);
```

**实现：**
```c
char* strcpy_custom(char *dest, const char *src) {
    char *original_dest = dest; // 保存目标字符串的起始地址

    // 遍历源字符串并逐个复制字符
    while ((*dest++ = *src++) != '\0') {
        // 空操作，循环会自动处理
    }
    // =>实际上就是
	while(*src!='\0'){
        *dest=*src;
        dest++;
        src++;
    }
    return original_dest; // 返回目标字符串的起始地址
}
```

**解析：**
- 使用 `while` 循环逐个复制字符，直到遇到源字符串的终止符 `\0`。
- 返回目标字符串的起始地址，以便可以链式调用。
- **while((* dest++=* src++)!='\0')**

## strcmp
`strcmp` 函数用于比较两个字符串。

**函数原型：**
```c
int strcmp(const char *s1, const char *s2);
```

**实现：**

```c
int strcmp_custom(const char *s1, const char *s2) {
    while (*s1 != '\0' && *s2 != '\0') {
        if (*s1 != *s2) {
            return *s1 - *s2; // 返回字符的差值
        }
        s1++;
        s2++;
    }

    // 如果一个字符串结束，返回剩余字符的 ASCII 值差
    return *s1 - *s2;
}
```

**解析：**
- 逐个比较字符，直到遇到不同的字符或字符串结束。
- 如果字符不同，返回它们的 ASCII 值差。
- 如果一个字符串结束，返回剩余字符的 ASCII 值差。

## memcpy
`memcpy` 函数用于将一块内存的内容复制到另一块内存中。

**函数原型：**
```c
void *memcpy(void *dest, const void *src, size_t n);
```

**实现：**
```c
void* memcpy_custom(void *dest, const void *src, size_t n) {
    unsigned char *d = (unsigned char *)dest;
    const unsigned char *s = (const unsigned char *)src;

    for (size_t i = 0; i < n; i++) {
        d[i] = s[i]; // 逐字节复制
    }

    return dest; // 返回目标内存的起始地址
}
```

**解析：**
- 使用 `unsigned char` 指针来逐字节访问内存。
- 逐字节复制内存内容。
- 返回目标内存的起始地址。

## memcmp
`memcmp` 函数用于比较两块内存的内容。

**函数原型：**
```c
int memcmp(const void *s1, const void *s2, size_t n);
```

**实现：**
```c
int memcmp_custom(const void *s1, const void *s2, size_t n) {
    const unsigned char *p1 = (const unsigned char *)s1;
    const unsigned char *p2 = (const unsigned char *)s2;

    for (size_t i = 0; i < n; i++) {
        if (p1[i] != p2[i]) {
            return p1[i] - p2[i]; // 返回字节的差值
        }
    }

    return 0; // 如果所有字节都相等，返回 0
}
```

**解析：**
- 使用 `unsigned char` 指针来逐字节访问内存。
- 逐字节比较内存内容。
- 如果字节不同，返回它们的差值。
- 如果所有字节都相等，返回 0。

## **完整示例代码**
以下是一个完整的示例代码，包含上述四个函数的实现和测试代码：

```c
#include <stdio.h>
#include <string.h>
#include <stddef.h>

// strcpy 的实现
char* strcpy_custom(char *dest, const char *src) {
    char *original_dest = dest;
    while ((*dest++ = *src++) != '\0') {
        // 空操作
    }
    return original_dest;
}

// strcmp 的实现
int strcmp_custom(const char *s1, const char *s2) {
    while (*s1 != '\0' && *s2 != '\0') {
        if (*s1 != *s2) {
            return *s1 - *s2;
        }
        s1++;
        s2++;
    }
    return *s1 - *s2;
}

// memcpy 的实现
void* memcpy_custom(void *dest, const void *src, size_t n) {
    unsigned char *d = (unsigned char *)dest;
    const unsigned char *s = (const unsigned char *)src;

    for (size_t i = 0; i < n; i++) {
        d[i] = s[i];
    }

    return dest;
}

// memcmp 的实现
int memcmp_custom(const void *s1, const void *s2, size_t n) {
    const unsigned char *p1 = (const unsigned char *)s1;
    const unsigned char *p2 = (const unsigned char *)s2;

    for (size_t i = 0; i < n; i++) {
        if (p1[i] != p2[i]) {
            return p1[i] - p2[i];
        }
    }
    return 0;
}

// 测试代码
int main() {
    char dest[50] = "Hello, ";
    const char *src = "World!";
    printf("strcpy: %s\n", strcpy_custom(dest, src)); // 输出 "World!"

    const char *str1 = "apple";
    const char *str2 = "banana";
    printf("strcmp: %d\n", strcmp_custom(str1, str2)); // 输出负值

    int arr1[5] = {1, 2, 3, 4, 5};
    int arr2[5] = {0};
    memcpy_custom(arr2, arr1, sizeof(arr1));
    printf("memcpy: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr2[i]); // 输出 "1 2 3 4 5"
    }
    printf("\n");

    int arr3[5] = {1, 2, 3, 4, 5};
    int arr4[5] = {1, 2, 3, 4, 6};
    printf("memcmp: %d\n", memcmp_custom(arr3, arr4, sizeof(arr3))); // 输出负值

    return 0;
}
```

### **输出示例**
运行上述代码，输出如下：
```
strcpy: World!
strcmp: -1
memcpy: 1 2 3 4 5 
memcmp: -1
```

### **总结**
- **`strcpy`**：逐字符复制字符串。
- **`strcmp`**：逐字符比较字符串。
- **`memcpy`**：逐字节复制内存。
- **`memcmp`**：逐字节比较内存。

这些实现是基于简单的逐字节操作，实际的标准库实现可能会使用更高效的算法（如 SIMD 指令优化）。



## strstr

`strstr()` 是 C 语言标准库中的一个函数，用于在一个字符串中查找另一个字符串的首次出现位置。它的原型定义在 `<string.h>` 中，函数原型为：

```c
char *strstr(const char *haystack, const char *needle);
```

- `haystack` 是被搜索的主字符串。
- `needle` 是要查找的子字符串。
- 如果找到了子字符串，函数返回子字符串在主字符串中的首次出现位置的指针；如果未找到，则返回 `NULL`。

以下是 `strstr()` 函数的实现代码：

```c
#include <stdio.h>
#include <string.h>

char* strstr_custom(const char* haystack, const char* needle) {
    // 如果子字符串为空，直接返回主字符串的起始位置
    if (*needle == '\0') {
        return (char*)haystack;
    }

    // 遍历主字符串
    for (const char* current = haystack; *current != '\0'; ++current) {
        // 检查主字符串的当前子串是否与子字符串匹配
        const char* temp_haystack = current;  // 当前以tmp_haystack作为开头
        const char* temp_needle = needle;

        while (*temp_haystack != '\0' && *temp_needle != '\0' && *temp_haystack == *temp_needle) {
            temp_haystack++;
            temp_needle++;
        }

        // 如果子字符串完全匹配（temp_needle 指向子字符串的末尾）
        if (*temp_needle == '\0') {
            return (char*)current;   // 返回current（指向头部位置
        }
    }

    // 如果没有找到匹配的子字符串，返回 NULL
    return NULL;
}

int main() {
    const char* haystack = "This is a test string.";
    const char* needle = "test";

    char* result = strstr_custom(haystack, needle);

    if (result != NULL) {
        printf("Substring found at: %s\n", result);
    } else {
        printf("Substring not found.\n");
    }

    return 0;
}
```

### 代码解析：

1. **空字符串的处理**：
   - 如果 `needle` 是空字符串（`*needle == '\0'`），按照标准库的定义，返回 `haystack` 的起始位置。

2. **主字符串遍历**：
   - 遍历主字符串 `haystack` 的每个字符，尝试从每个位置开始匹配子字符串 `needle`。

3. **子字符串匹配**：
   - 使用两个指针 `temp_haystack` 和 `temp_needle` 分别指向当前主字符串的位置和子字符串的起始位置。
   - 逐字符比较，如果字符不匹配或子字符串结束（`*temp_needle == '\0'`），停止匹配。

4. **匹配成功**：
   - 如果子字符串完全匹配（`*temp_needle == '\0'`），返回当前主字符串的起始位置（`current`）。

5. **匹配失败**：
   - 如果遍历完主字符串仍未找到匹配的子字符串，返回 `NULL`。

### 示例输出：

对于输入：

```c
const char* haystack = "This is a test string.";
const char* needle = "test";
```

输出：

```
Substring found at: test string.
```

这个实现与标准库的 `strstr()` 行为一致，适用于查找子字符串的首次出现位置。





### 处理stdin

在 ACM 比赛中，通常需要从标准输入（`stdin`）读取数据，并将结果输出到标准输出（`stdout`）。以下是一个完整的示例代码，展示如何在 `main` 函数中处理用户输入的 `haystack` 和 `needle`，并调用自定义的 `strstr_acm` 函数来查找子字符串。

### 示例代码

```c
#include <stdio.h>

// 自定义 strstr 函数
char* strstr_acm(const char* haystack, const char* needle) {
    // 如果子字符串为空，直接返回主字符串的起始位置
    if (*needle == '\0') {
        return (char*)haystack;
    }

    // 遍历主字符串
    while (*haystack != '\0') {
        // 保存主字符串当前匹配的起始位置
        const char* temp_haystack = haystack;
        const char* temp_needle = needle;

        // 尝试匹配子字符串
        while (*temp_haystack != '\0' && *temp_needle != '\0' && *temp_haystack == *temp_needle) {
            temp_haystack++;
            temp_needle++;
        }

        // 如果子字符串完全匹配（temp_needle 指向子字符串的末尾）
        if (*temp_needle == '\0') {
            return (char*)haystack;
        }

        // 移动主字符串的指针，继续下一次匹配
        haystack++;
    }

    // 如果没有找到匹配的子字符串，返回 NULL
    return NULL;
}

// 主函数
int main() {
    // 定义足够大的缓冲区来存储输入的字符串
    char haystack[1000];
    char needle[100];

    // 从标准输入读取主字符串和子字符串
    printf("Enter the main string (haystack): ");
    fgets(haystack, sizeof(haystack), stdin); // 读取一行输入
    haystack[strcspn(haystack, "\n")] = '\0'; // 去掉换行符

    printf("Enter the substring (needle): ");
    fgets(needle, sizeof(needle), stdin); // 读取一行输入
    needle[strcspn(needle, "\n")] = '\0'; // 去掉换行符

    // 调用自定义的 strstr 函数
    char* result = strstr_acm(haystack, needle);

    // 输出结果
    if (result != NULL) {
        printf("Substring found at index: %ld\n", result - haystack);
        printf("Substring found in the string: %s\n", result);
    } else {
        printf("Substring not found.\n");
    }

    return 0;
}
```

### 代码解析

1. **输入处理**：
   - 使用 `fgets` 从标准输入读取字符串，避免使用 `scanf`，因为 `scanf` 在处理字符串时可能会忽略换行符。
   - 使用 `strcspn` 去掉字符串末尾的换行符（`fgets` 会保留换行符）。

2. **调用自定义的 `strstr_acm` 函数**：
   - 将用户输入的 `haystack` 和 `needle` 传递给 `strstr_acm` 函数。

3. **输出结果**：
   - 如果找到子字符串，计算子字符串在主字符串中的索引（`result - haystack`）。
   - 输出子字符串在主字符串中的位置。
   - 如果未找到子字符串，输出相应的提示信息。

### 示例运行

假设用户输入以下内容：

```
Enter the main string (haystack): This is a test string.
Enter the substring (needle): test
```

程序输出：

```
Substring found at index: 10
Substring found in the string: test string.
```

### 注意事项

1. **缓冲区大小**：
   - 确保缓冲区大小足够大，以避免溢出。在这个示例中，`haystack` 的大小为 1000 字符，`needle` 的大小为 100 字符。

2. **输入有效性**：
   - 在实际比赛中，可能需要对输入进行额外的验证，例如检查输入是否为空字符串等。

3. **换行符处理**：
   - 使用 `strcspn` 去掉换行符是一个常见的技巧，确保输入的字符串不会包含多余的换行符。

这种输入输出处理方式在 ACM 比赛中非常常见，能够帮助选手快速读取和处理用户输入的数据。