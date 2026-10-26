#include <bits/stdc++.h>
using namespace std;
#define int long long


void solve() {
    int n, m;cin >> n >> m;
    vector<vector<int>> a(n + 1, vector<int>(m + 1)),b(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) cin >> a[i][j];
    }
    int ans=0;
    for(int j=m;j>=1;j--)
    {
        int x=0;
        for(int i=n;i>=1;i--)
        {
            x+=b[i][j];
            if(a[i][j])
            {
                int y=min(max(x,(int)0),a[i][j]);
                ans+=a[i][j]-y;
                x-=y;

                if(j>1)
                b[i][j-1]+=a[i][j];
            }
            
        }
        
    }
    cout << ans << endl;
}

signed main() {
    int T = 1;
    //cin >> T;
    while (T--) solve();
}