#include<stdlib.h>
#include<stdio.h>
int main(){
    int M,N;
    scanf("%d%d",&M,&N);
    int weight[M];
    for(int i = 0;i < M ;i++)
    scanf("%d",&weight[i]);
    int value[M];
    for(int i = 0;i < M ;i++)
    scanf("%d",&value[i]);
    int dp[M][N+1];
    for(int i = 0;i < M;i++)
    dp[i][0] = 0;
    for(int j = 1;j < N + 1;j++){
        if(j >= weight[0]){
            dp[0][j] = value[0];
        }else{
            dp[0][j] = 0;
        }
    }
    for(int i = 1;i < M;i++){
        for(int j = 1;j <= N;j++){
            if(j < weight[i])dp[i][j] = dp[i - 1][j];
            else{
                dp[i][j] = fmax(dp[i - 1][j],dp[i - 1][j - weight[i]] + value[i]);
            }
        }
    }
    
    for(int i = 0;i < M;i++){
    for(int j = 0;j <= N;j++)
    printf("%d\t",dp[i][j]);
    printf("\n");
    }
    printf("%d",dp[M - 1][N]);
    return 0;
}
