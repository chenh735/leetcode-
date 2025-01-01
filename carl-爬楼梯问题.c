/*假设你正在爬楼梯。需要 n 阶你才能到达楼顶。 

每次你可以爬至多m (1 <= m < n)个台阶。你有多少种不同的方法可以爬到楼顶呢？ 

注意：给定 n 是一个正整数。
*/

#include<stdio.h>
#include<stdlib.h>

int main(){
    int m,n;
    scanf("%d%d",&n,&m);      //输入为n m，1 <= m <= n <= 32
    
    int dp[n + 1];            //滚动一维数组
    
    dp[0] = 1;                //初始化
    for(int i = 1;i <= n;i++)
    dp[i] = 0;
    
    for(int j = 1;j <= n;j++){        //先遍历背包再遍历物品，求排列数，121与112为两种不同的组合
        for(int i = 1;i <=m;i++){
            if(i > j){
                continue;
            }
            dp[j] += dp[j - i];
        }
    }
    printf("%d",dp[n]);            //dp[n]为所求
}
