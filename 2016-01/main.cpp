#include <iostream>
typedef unsigned long long ull;
using namespace std;
ull getNumber1(string index){
    int size=index.size();
    int i=0;
    ull number=0;
    while(i<index.size()){
        number=number*10+(index[i]-'0');
        i++;
    }
    return number;
}
ull getNumber2(string index){
    int size=index.size();
    int i=size-1;
    ull number=0;
    while(i>=0){
        number=number*10+(index[i]-'0');
        i--;
    }
    return number;
}
int main()
{
    string source;
    cin>>source;
    ull n,m;
    n=getNumber1(source);
    m=getNumber2(source);
    if(m%n==0&&m>=n){
        cout<<n<<"*"<<m/n<<"="<<m;
    }else{
        cout<<n<<" "<<m;
    }
    return 0;
}
