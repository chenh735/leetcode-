/**/

#include<stdio.h>
#include<stdlib.h>

int main(){
    int c,n;
    scanf("%d%d",&c,&n);
    int w[n];
    for(int i = 0;i < n;i++)
    scanf("%d",w + i);
    int v[n];
    for(int i = 0;i < n;i++)
    scanf("%d",v + i);
    int w1[1000],v1[1000],k[n];
    int cnt = 0;
    for(int i = 0;i < n;i++){
        scanf("%d",k+i);
        int j = 1;
        for(;j <= k[i];j <<= 1){
            w1[cnt] = w[i] * j;
            v1[cnt++] = v[i] * j;
            k[i] -= j;
        }
        if(k[i]){
            w1[cnt] = w[i] * k[i];
            v1[cnt++] = v[i] * k[i];
        }
    }
    int dp[c + 1];
    for(int j = 0;j <= c;j++)
    dp[j] = 0;
    for(int i = 0;i < cnt;i++){
        if(w1[i] > c)continue;
        for(int j = c;j >= w1[i];j--){
            dp[j] = fmax(dp[j],dp[j - w1[i]] + v1[i]);
        }
    }
    printf("%d",dp[c]);
}
