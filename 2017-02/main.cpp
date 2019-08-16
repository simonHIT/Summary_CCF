#include <iostream>
#include <vector>
using namespace std;
bool cmp(char a){
    if(a>='0'&&a<='9'||a>='a'&&a<='z'||a>='A'&&a<='Z'||a=='_'){
        return true;
    }else{
        return false;
    }
}
int main()
{
    string s1,s2;
    getline(cin,s1);
    getline(cin,s2);
    vector<string> s1array;
    vector<string> s2array;
    int first=s1.find(' ');
    s1=s1.substr(first,s1.size()-first);
    for(int i=0;i<s1.size();i++){
        if(cmp(s1[i])){
            if(s1[i]<'0'||s1[i]>'9'){
                first=i;
                break;
            }
        }
    }
    s1=s1.substr(first,s1.size()-first);
    while(s1.size()>0){
        int index=0;
        first=-1;
        while(cmp(s1[index])&&(index<s1.size())){
            index++;
        }
        string indexemeter=s1.substr(0,index);
        s1=s1.substr(index,s1.size()-index);
        s1array.push_back(indexemeter);
        for(int i=0;i<s1.size();i++){
            if(cmp(s1[i])){
                if(s1[i]<'0'||s1[i]>'9'){
                    first=i;
                    break;
                }
            }
        }
        if(first>-1){
            s1=s1.substr(first,s1.size()-first);
        }else{
            s1="";
        }
    }
    /**
    s2 */
    first=-1;
    for(int i=0;i<s2.size();i++){
        if(cmp(s2[i])){
            if(s2[i]<'0'||s2[i]>'9'){
                first=i;
                break;
            }
        }
    }
    s2=s2.substr(first,s2.size()-first);
    while(s2.size()>0){
        first=-1;
        int index=0;
        while(cmp(s2[index])&&index<s2.size()){
            index++;
        }
        string indexemeter=s2.substr(0,index);
        s2=s2.substr(index,s2.size()-index);
        s2array.push_back(indexemeter);
        for(int i=0;i<s2.size();i++){
            if(cmp(s2[i])){
                if(s2[i]<'0'||s2[i]>'9'){
                first=i;
                break;
                }
            }
        }
        if(first>-1){
            s2=s2.substr(first,s2.size()-first);
        }else{
            s2="";
        }
    }
    for(int i=0;i<s2array.size();i++){
        bool flag=false;
        for(int j=0;j<s1array.size();j++){
            if(s1array[j]==s2array[i]){
                flag=true;
                break;
            }
        }
        if(!flag){
            cout<<s2array[i]<<" ";
        }
    }
    return 0;
}
