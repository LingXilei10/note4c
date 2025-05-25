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
```





```cpp
while(getline(cin,s)){
    if(s.empty()) break;
    //处理...
}
```

