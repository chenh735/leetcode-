//����һ������n������k����n��ֳ�ÿ����������k���� ��n��k <= 100�� 

#include<stdio.h>

int dp[101][101];		// �ⲿ��������ʼ��Ϊ0�� 

int main(){
	int n , k;
	
//	��������Ϊ4��5����Ҫ��','ȥ�� 
	scanf("%d",&n);
	getchar();
	scanf("%d",&k);
	
	if(k > n) k = n;		//�����ͬ
	 
	for(int i = 1;i <= n;i++){			// nΪ�У�kΪ�� 
		dp[i][1] = dp[1][i] = 1;
	}
	for(int i = 2;i <= n;i++){
		for(int j = 2;j <= k;j++){
			if(i < j){
				dp[i][j] = dp[i][i];
			}else if(i == j){
				dp[i][j] = 1 + dp[i][j - 1];
			}else{
				dp[i][j] = dp[i - j][j] + dp[i][j - 1];  		// ����k�벻����k�����ַ�ʽ 
			}
		}
	}
	printf("%d",dp[n][k]);
}
