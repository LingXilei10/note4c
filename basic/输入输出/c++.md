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

零尾模式

