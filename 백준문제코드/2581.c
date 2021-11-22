#include<stdio.h>
#include<math.h>

int main(){
    int M,N,i,j,cnt,tmp;
    int sum=0;

    scanf("%d %d",&M,&N);

    for(i=M;i<=N;i++){
        cnt=0;
        if(i==1) continue;
        for(j=2;j<=sqrt(i);j++){
            if(i%j==0){
                cnt++;
                break;
            }
        }
        if(cnt==0){
            if(sum==0){
                tmp=i;
            }
            sum+=i;
        }
    }

    if(sum==0) printf("%d",-1);
    else{
        printf("%d\n%d",sum,tmp);
    }
}