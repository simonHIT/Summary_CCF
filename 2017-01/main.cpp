#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
bool cmp(long a,long b){
    return a<=b;
}
int main()
{
    long n;
    cin>>n;
    vector<long> arrays;
    long sources[n]={0};
    for(int i=0;i<n;i++){
        long index;
        cin>>index;
        sources[i]=index;
        arrays.push_back(index);
    }
    sort(arrays.begin(),arrays.end(),cmp);
    if(arrays.size()%2==0){
        long middle1,middle2;
        middle1=arrays[arrays.size()/2-1];
        middle2=arrays[arrays.size()/2];
        cout<<middle1<<" "<<middle2;
    }else{
        long middle;
        middle=arrays[arrays.size()/2];
        cout<<middle;
    }
    return 0;
}
