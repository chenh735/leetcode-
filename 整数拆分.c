//给定一个整数n和整数k，将n拆分成每个数不超过k的数 ，n，k <= 100。 

#include<stdio.h>

int dp[101][101];		// 外部变量，初始化为0。 

int main(){
	int n , k;
	
//	举例输入为4，5，需要把','去掉 
	scanf("%d",&n);
	getchar();
	scanf("%d",&k);
	
	if(k > n) k = n;		//情况相同
	 
	for(int i = 1;i <= n;i++){			// n为行，k为列 
		dp[i][1] = dp[1][i] = 1;
	}
	for(int i = 2;i <= n;i++){
		for(int j = 2;j <= k;j++){
			if(i < j){
				dp[i][j] = dp[i][i];
			}else if(i == j){
				dp[i][j] = 1 + dp[i][j - 1];
			}else{
				dp[i][j] = dp[i - j][j] + dp[i][j - 1];  		// 包含k与不包含k的两种方式 
			}
		}
	}
	printf("%d",dp[n][k]);
}


//	滚动一维数组
#include<stdio.h>

int dp[101];		// 外部变量，初始化为0。 

int main(){
	int n , k;
	
//	举例输入为4，5，需要把','去掉 
	scanf("%d",&n);
	getchar();
	scanf("%d",&k);
	
	if(k > n) k = n;		//情况相同
	 
	dp[0] = 0;

	for(int i = 1;i <= k;i++){
		for(int j = i;j <= n;j++){
			dp[i] += dp[j - i];
		}
	}
	printf("%d",dp[n]);
}

