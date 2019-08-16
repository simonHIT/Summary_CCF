#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n;
    scanf("%d",&n);
    int temp1,temp2,total;
    temp1=temp2=n;
    total=0;
    printf("%d%c",temp1,',');
    int length=0;
    while(temp1>9){
        temp1=temp1/10;
        length++;
    }
    length++;
    int array[length];
    for(int j=length-1;j>=0;j--){
        int temp=temp2%10;
        temp2=temp2/10;
        array[j]=temp;
    }
    for(int j=0;j<length;j++){
        printf("%d%c",array[j],'!');
        if(j!=length-1){
            printf("%c",'+');
        }
        int arrayIndex=1;
        int m=array[j];
        while(m>=1){
            arrayIndex*=m;
            m--;
        }
        total+=arrayIndex;
    }
    printf("%c%d",'=',total);
    printf("%c",'\n');
    if(total==n){
        printf("%s","yes");
    }else{
        printf("%s","no");
    }
    return 0;
}
