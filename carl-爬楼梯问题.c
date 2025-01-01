#include<stdio.h>
#include<stdlib.h>

int main(){
    int m,n;
    scanf("%d%d",&n,&m);
    int dp[n + 1];
    dp[0] = 1;
    for(int i = 1;i <= n;i++)
    dp[i] = 0;
    for(int j = 1;j <= n;j++){
        for(int i = 1;i <=m;i++){
            if(i > j){
                continue;
            }
            dp[j] += dp[j - i];
        }
    }
    printf("%d",dp[n]);
}
