#include <stdio.h>
#include <stdlib.h>
void sort(int* array,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(array[j]>array[j+1]){
                int temp=array[j];
                array[j]=array[j+1];
                array[j+1]=temp;
            }
        }
    }
}
void selectSort(int *array,int n){
    for(int i=0;i<n-1;i++){
        int k,min;
        min=array[i];
        k=i;
        for(int j=i;j<n;j++){
            if(array[j]<min){
                min=array[j];
                k=j;
            }
        }
        int temp=array[i];
        array[i]=min;
        array[k]=temp;
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    int array[n];
    for(int i=0;i<n;i++){
        scanf("%d",&array[i]);
    }
    selectSort(array,n);
    if(n%2==0){
        int kmiddle1=n/2;
        int kmiddle2=n/2-1;
        printf("%d %d",array[kmiddle2],array[kmiddle1]);
    }else{
        int kmiddle=n/2;
        printf("%d",array[kmiddle]);
    }
    return 0;
}
