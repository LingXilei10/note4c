一直输入很多行

```cpp
# include<iostream>
using namespace std;
int main(){
    int a,b;
    while(cin>>a>>b){
        cout<<a+b<<endl;
    }
    return 0;
}
```

告知t组

```cpp
# include<iostream>
using namespace std;
int main(){
    int a,b,t;
    cin>>t;
    while(t--){
        cin>>a>>b;
        cout<<a+b<<endl;
    }
    return 0;
}
```

读取一行

```cpp
#include <iostream>
#include <cstring> // 用于 std::strcat

int main() {
    const int MAX_LINE_LENGTH = 1024;
    char line[MAX_LINE_LENGTH];

    std::cout << "Enter a line of text: ";
    std::cin.getline(line, MAX_LINE_LENGTH); // 从标准输入读取一整行

    std::cout << "You entered: " << line << std::endl;
    return 0;
}


#include <iostream>
#include <string>

int main() {
    std::string line;
    char ch;

    std::cout << "Enter a line of text: ";
    while (std::cin.get(ch) && ch != '\n') { // 逐个字符读取，直到换行符
        line += ch;
    }

    std::cout << "You entered: " << line << std::endl;
    return 0;
}



while(geline(cin,s)){
    if(s.empty()) break;
    istringstream iss(s);
    string ss;
    while(iss>>ss){
        if()
    }
}
```





```cpp
while(getline(cin,s)){
    if(s.empty()) break;
    //处理...
}
```

输入：

```cpp
2
[[10,30],[30,200]]
```

读取：

```cpp
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

int main() {
    int M;
    cin >> M;
    cin.ignore(); // 忽略换行符

    string line;
    getline(cin, line); // 读取整行，如 "[[10,30],[30,200]]"

    vector<pair<int, int>> cost;
    istringstream iss(line);
    char discard; // 用于丢弃 '[', ',', ']' 等字符
    int a, b;

    while (iss >> discard) { // 读取 '['
        if (discard == ']') break; // 结束
        iss >> discard >> a >> discard >> b >> discard; // 读取格式如 [10,30]
        cost.emplace_back(a, b);
    }

    // 输出检查
    for (const auto& p : cost) {
        cout << p.first << " " << p.second << endl;
    }
    return 0;
}
```

