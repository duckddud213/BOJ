#include<stdio.h>
#include<stdlib.h>

int compare(const void *x,const void *y){
    int a = *(int *)x;
    int b = *(int *)y;

    if(a>b){
        return 1;
    }
    else if(a<b){
        return -1;
    }
    else{
        return 0;
    }
}

int main(){
    int N,i;
    int *arr;

    scanf("%d",&N);
    arr=(int *)malloc(sizeof(int)*N);

    for(i=0;i<N;i++){
        scanf("%d",arr+i);
    }

    qsort(arr,N,sizeof(int),compare);

    printf("%d ",arr[0]);
    for(i=1;i<N;i++){
        if(arr[i-1]!=arr[i]){
            printf("%d ",arr[i]);
        }
    }
    
}