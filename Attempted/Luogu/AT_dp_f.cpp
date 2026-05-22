#include<bits/stdc++.h>
using namespace std;
int dp[3010][3010];
char s[3010],t[3010],ans[3010];

int main(){
	scanf("%s%s",s+1,t+1);
	int n=strlen(s+1),m=strlen(t+1);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(s[i]==t[j]) dp[i][j]=dp[i-1][j-1]+1;
			else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
	int i=n,j=m;
	while(dp[i][j]>0){
		if(s[i]==t[j]) ans[dp[i][j]]=s[i],i--,j--;
		else if(dp[i-1][j]>dp[i][j-1]) i--;
		else j--;
	}
	for(int i=1;i<=dp[n][m];i++) printf("%c",ans[i]);
	return 0;
}