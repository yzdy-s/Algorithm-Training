#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve() {
    int n;
    cin>>n;
    map<int,int>mp1,mp2;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        mp1[x]++;
    }
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        mp2[x]++;
    }
    priority_queue<int>q;
    for(auto [l,r]:mp2)
    {
        q.push(l);
    }
    int a=n,f=0,b=0;
    while(q.size())
    {
        int x=q.top();
        q.pop();
        if(f==0&&mp2[x]<=mp1[x])
        {
            
        }
        else if(b>=mp2[x])
        {
            b-=mp2[x];
        }
        else if(x<=a)
        {
            if(mp2[x]>=x)
            {
                cout<<"YES\n";
                return;
            }
            b=max(b-mp2[x],a-x);
            f=1;
        }
        else
        { 
            cout<<"NO\n";return;
        }
        
        a-=mp2[x];
    }
    cout<<"YES\n";
}

signed main() {
    int T = 1;cin >> T;
    while (T--) solve();
}