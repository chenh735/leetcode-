/*你是一名宇航员，即将前往一个遥远的行星。在这个行星上，有许多不同类型的矿石资源，每种矿石都有不同的重要性和价值。你需要选择哪些矿石带回地球，但你的宇航舱有一定的容量限制。 

给定一个宇航舱，最大容量为 C。现在有 N 种不同类型的矿石，每种矿石有一个重量 w[i]，一个价值 v[i]，以及最多 k[i] 个可用。不同类型的矿石在地球上的市场价值不同。
你需要计算如何在不超过宇航舱容量的情况下，最大化你所能获取的总价值。*/

/*输入共包括四行，第一行包含两个整数 C 和 N，分别表示宇航舱的容量和矿石的种类数量。 

接下来的三行，每行包含 N 个正整数。具体如下： 

第二行包含 N 个整数，表示 N 种矿石的重量。 

第三行包含 N 个整数，表示 N 种矿石的价格。 

第四行包含 N 个整数，表示 N 种矿石的可用数量上限。
*/


#include<stdio.h>
#include<stdlib.h>

int main(){
    int c,n;
    scanf("%d%d",&c,&n);        //容量c与种类n
    int w[n];                    //实际重量
    for(int i = 0;i < n;i++)
    scanf("%d",w + i);
    int v[n];                    //实际容量
    for(int i = 0;i < n;i++)
    scanf("%d",v + i);
    int w1[1000],v1[1000];        //二进制优化后的重量，容量
    int cnt = 0;
    int k[n];
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
    
    int dp[c + 1];                //初始化
    for(int j = 0;j <= c;j++)
    dp[j] = 0;
    for(int i = 0;i < cnt;i++){        //滚动数组
        if(w1[i] > c)continue;
        for(int j = c;j >= w1[i];j--){
            dp[j] = fmax(dp[j],dp[j - w1[i]] + v1[i]);
        }
    }
    printf("%d",dp[c]);
}
