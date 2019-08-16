#include <iostream>
#include <vector>
using namespace std;
long getNumber(string index){
    int size=index.size();
    int i=0;
    long number=0;
    while(i<index.size()){
        number=number*10+(index[i]-'0');
        i++;
    }
    return number;
}
int main()
{
    string enumString;
    getline(cin,enumString);
    vector<long> enums;
    int pre=enumString.find('{');
    int next=enumString.find('}');
    enumString=enumString.substr(pre+1,next-pre-1);
    while(enumString.size()>0){
        int sign=-1;
        sign=enumString.find(',');
        string index;
        if(sign>-1){
            index=enumString.substr(0,sign);
            enumString=enumString.substr(sign+1,enumString.size()-sign-1);
        }else{
            index=enumString;
            enumString="";
        }
        int equalIndex=-1;
        equalIndex=index.find('=');
        if(equalIndex>-1){
            string numberS=index.substr(equalIndex+1,index.size()-equalIndex-1);
            long number=getNumber(numberS);
            enums.push_back(number);
        }else{
            int enumsSize=enums.size();
            long number;
            if(enumsSize>0){
                number=enums[enumsSize-1]+1;
            }else{
                number=0;
            }
            enums.push_back(number);
        }
    }
    for(int i=0;i<enums.size();i++){
        cout<<enums[i];
        if(i!=enums.size()-1){
            cout<<" ";
        }
    }
    return 0;
}
