#include<bits/stdc++.h>
using namespace std;
#define int long long


void solve() {
    int n;
    cin>>n;
    vector<int>l(n+1),r(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>l[i]>>r[i];
    }
    int mx0=-1e10,mx1=-1e10,ans=0;
    for(int i=1;i<=n;i++)
    {
        mx1=max(mx1,r[i]);
        if(mx0<l[i])
        {
            ans++;
            mx0=mx1;
        }

    }
    cout<<ans<<'\n';
}

signed main() {
    int T = 1;
    cin >> T;
    while (T--) solve();
}