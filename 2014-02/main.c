#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct {
    int x;
    int y;
}point;
bool check(int sign,int array[][19],point* vectory){
    bool flag=false;
    for(int i=0;i<19;i++){
        for(int j=0;j<15;j++){
            if(array[i][j]==sign&&array[i][j+1]==sign&&array[i][j+2]==sign&&array[i][j+3]==sign&&array[i][j+4]==sign){
                flag=true;
                vectory->x=i;
                vectory->y=j;
                break;
            }
        }
    }
    if(!flag){
        for(int i=0;i<19;i++){
            for(int j=0;j<15;j++){
                if(array[j][i]==sign&&array[j+1][i]==sign&&array[j+2][i]==sign&&array[j+3][i]==sign&&array[j+4][i]==sign){
                flag=true;
                vectory->x=i;
                vectory->y=j;
                break;
                }
            }
        }
    }

    if(!flag){
        for(int j=0;j<15;j++){
            int length=19-j;
            int max=length-4;
            int count=0;
            while(count<max){
                if(array[0+count][j+count]==sign&&array[0+count+1][j+count+1]==sign&&array[0+count+2][j+count+2]==sign&&
                   array[0+count+3][j+count+3]==sign&&array[0+count+4][j+count+4]==sign){
                    flag=true;
                    vectory->x=0+count;
                    vectory->y=j+count;
                    break;
                   }
                   count++;
            }
        }
        for(int i=1;i<15;i++){
            int length=19-i;
            int max=length-4;
            int count=0;
            while(count<max){
                if(array[i+count][0+count]==sign&&array[i+count+1][0+count+1]==sign&&array[i+count+2][0+count+2]==sign&&
                   array[i+count+3][0+count+3]==sign&&array[i+count+4][0+count+4]==sign){
                    flag=true;
                    vectory->x=i+count;
                    vectory->y=0+count;
                    break;
                   }
                   count++;
            }
        }
        return flag;
    }
    if(!flag){
        for(int j=4;j<19;j++){
            int length=j+1;
            int max=length-4;
            int count=0;
            while(count<max){
                if(array[0+count][j-count]==sign&&array[0+count+1][j-count-1]==sign&&array[0+count+2][j-count-2]==sign&&
                   array[0+count+3][j-count-3]==sign&&array[0+count+4][j-count-4]==sign){
                    flag=true;
                    vectory->x=0+count;
                    vectory->y=j-count;
                    break;
                   }
                   count++;
            }
        }
        for(int i=1;i<15;i++){
            int length=19-i;
            int max=length-4;
            int count=0;
            while(count<max){
                if(array[i+count][18-count]==sign&&array[i+count+1][18-count-1]==sign&&array[i+count+2][18-count-2]==sign&&
                   array[i+count+3][18-count-3]==sign&&array[i+count+4][18-count-4]==sign){
                    flag=true;
                    vectory->x=i+count;
                    vectory->y=18-count;
                    break;
                   }
                   count++;
            }
        }
        return flag;
    }
}
int main()
{
    int cheer[19][19];
    for(int i=0;i<19;i++){
        for(int j=0;j<19;j++){
            int index;
            scanf("%d",&index);
            cheer[i][j]=index;
        }
    }
    point pointV={-1,-1};
    printf("%s","test");
    printf("%c",'\n');
    if(check(1,cheer,&pointV)&&!check(2,cheer,&pointV)){
        printf("%d%c",1,':');
        printf("%d %d",pointV.x,pointV.y);
    }else if(check(2,cheer,&pointV)&&!check(1,cheer,&pointV)){
        printf("%d%c",2,':');
        printf("%d %d",pointV.x,pointV.y);
    }else{
        printf("%s","no");
    }
    return 0;
}

