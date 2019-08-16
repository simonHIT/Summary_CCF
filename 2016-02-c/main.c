#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    int value;
    char *name;
}enumNode;
int find(char * src,char target,int n){
    int result=-1;
    for(int i=0;i<n;i++){
        if(src[i]==target){
            result=i;
            break;
        }
    }
    return result;
}
int getValue(char * src,int n){
    int result=0;
    for(int i=0;i<n;i++){
        result=result*10+(src[i]-'0');
    }
    return result;
}
char * substr(char* src,int begin,int length){
    int srcLength=strlen(src);
    int realLength=((srcLength-begin)>=length)?(length+1):(srcLength-begin+1);
    char * temp=(char*)malloc(realLength*sizeof(char));
    if(NULL!=temp){
        strncpy(temp,src+begin,realLength-1);
        temp[realLength-1]='\0';
    }else{
        exit(0);
    }
    return temp;
}
int main()
{
    char source[10000];
    gets(source);
    int size=strlen(source);
    int pre=find(source,'{',size);
    int next=find(source,'}',size);
    char* temp=substr(source,pre+1,next-pre-1);
    enumNode enums[1000];
    int count=0;
    while(strlen(temp)>0){
        int len=find(temp,',',strlen(temp));
        char *current;
        if(len>-1){
            current=substr(temp,0,len);
            temp=substr(temp,len+1,strlen(temp)-len-1);
        }else{
            current=temp;
            temp=(char*)malloc(sizeof(char));
            strcpy(temp,"\0");
        }
        int equal=find(current,'=',strlen(current));
            int value;
            if(equal>-1){
                char *valueString=substr(current,equal+1,strlen(current)-equal-1);
                value=getValue(valueString,strlen(valueString));
                current=substr(current,0,equal);
            }else{
                if(count>0){
                    enumNode preNode=*(enums+count-1);
                    value=preNode.value+1;
                }else{
                    value=0;
                }
            }
            enumNode tempEnum;
            tempEnum.value=value;
            tempEnum.name=current;
            *(enums+count)=tempEnum;
            count++;

    }
    for(int i=0;i<count;i++){
        enumNode index=*(enums+i);
        printf("%s %d",index.name,index.value);
        if(i!=count-1){
            printf("%c",' ');
        }
    }
    return 0;
}
