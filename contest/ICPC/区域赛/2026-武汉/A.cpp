#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve() {
    int n;
    cin>>n;
    map<string,int>mp;
    int ans=1;
    int f=0;
    mp["yeshenle"]=1;
    mp["zaoshanghao"]=2;
    while(n--)
    {
        string s;
        cin>>s;
        if(mp[s]==0)
        {
            continue;
        }
        if(f)
        {
            if(f==2&&mp[s]==1)
            {
                ans++;
            }
        }
        f=mp[s];
        
    }
    cout<<ans<<'\n';
}

signed main() {
    int T = 1;//cin >> T;
    while (T--) solve();
}