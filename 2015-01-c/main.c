#include <stdio.h>
#include <stdlib.h>
int main()
{
    int x,y;
    scanf("%d %d",&x,&y);
    printf("%d",x);
    printf("%c",',');
    int temp=x;
    int total1=0;
    for(int i=x-1;i>0;i--){
        if(temp%i==0){
            total1+=i;
            if(i!=1){
                printf("%d%c",i,'+');
            }else{
                printf("%d%c",i,'=');
            }
        }
    }
    printf("%d",total1);
    printf("%c",'\n');
    printf("%d",y);
    printf("%c",',');
    int total2=0;
    temp=y;
    for(int i=y-1;i>0;i--){
        if(temp%i==0){
            total2+=i;
            if(i!=1){
                printf("%d%c",i,'+');
            }else{
                printf("%d%c",i,'=');
            }
        }
    }
    printf("%d",total2);
    printf("%c",'\n');
    if(total1==y&&total2==x){
        printf("%d",1);
    }else{
        printf("%d",0);
    }
    return 0;
}
