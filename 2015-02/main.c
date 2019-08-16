#include<stdio.h>
#include<stdlib.h>
typedef struct window{
    int number;
    int x1;
    int y1;
    int x2;
    int y2;
}window;
int main(){
    int n;
    scanf("%d",&n);
    window windows[n];
    for(int i=0;i<n;i++){
        int number,x1,y1,x2,y2;
        scanf("%d %d %d %d %d",&number,&x1,&y1,&x2,&y2);
        windows[i].number=number;
        windows[i].x1=x1;
        windows[i].y1=y1;
        windows[i].x2=x2;
        windows[i].y2=y2;
    }
    int k;
    scanf("%d",&k);
    for(int i=0;i<k;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        window temp;
        for(int j=0;j<n;j++){
            if(x<=windows[j].x2&&y<=windows[j].y1){
                temp=windows[j];
                int index=j;
                while(index>0){
                    windows[index]=windows[index-1];
                    index--;
                }
                windows[0]=temp;
                break;
            }
        }
    }
    for(int i=0;i<n;i++){
        printf("%d",windows[i].number);
        if(i!=n-1){
            printf("%c",' ');
        }
    }
    return 0;
}
