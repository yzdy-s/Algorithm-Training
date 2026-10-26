#include <bits/stdc++.h>
using namespace std;
#define int long long 

typedef long long ll;


void solve() {
    int n,m,x,y,z;
    cin>>n>>m>>x>>y>>z;
    vector<vector<int>>dp(m+1,vector<int>(n+1));
    vector<int>a(n+1),b(m+1);
    for(int i=1;i<=n;i++)   cin>>a[i];
    for(int i=1;i<=m;i++)   cin>>b[i];
    for(int i=1;i<=n;i++)
    {
        dp[0][i]=i*z;
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            dp[i][j]=5e18;
        }
        int mn=5e18;
        if(i==1)mn=0;
        for(int j=1;j<=n;j++)
        {
            dp[i][j]=min(dp[i][j],mn);
            mn=min(mn+z,dp[i-1][j]);
        }
        mn+=x;
        for(int j=1;j<=n;j++)
        {
            dp[i][j]=min(dp[i][j],mn);
            mn=min(mn+z,dp[i-1][j]);
        }
        for(int j=1;j<=n;j++)
        {
            dp[i][j]+=abs(b[i]-a[j])*y;
        }
    }
    int ans=5e18;
    for(int i=1;i<=n;i++)
    {
        ans=min(ans,dp[m][i]+(n-i)*z);
    }
    // for(int i=1;i<=m;i++)
    // {
    //     for(int j=1;j<=n;j++)
    //     {
    //         cout<<dp[i][j]<<' ';
    //     }
    //     cout<<'\n';
    // }
    cout<<ans+x<<'\n';
}

signed main() {
    int T;cin >> T;
    while (T--) solve();
}