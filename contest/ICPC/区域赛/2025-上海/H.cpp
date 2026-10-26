#include<bits/stdc++.h>
using namespace std;

#define int long long 

void solve() {
    int n;
    cin>>n;
    map<int,int>mp;
    for(int i=1;i<=2*n;i++)
    {
        int x;
        cin>>x;
        mp[x]++;
    }
    int ans=0,f=0;
    for(auto[l,r]:mp)
    {
        r%=4;
        ans^=l*(r/2);
        if(r%2)
        {
            f++;
        }
    }
    if(f==0)
    {
        if(ans==0)
        {
            cout<<"Menji\n";
        }
        else
        {
            cout<<"Bot\n";
        }
        
    }
    else if(f==2)
    {
        if(mp[ans]%2)
        {
            cout<<"Menji\n";
        }
        else
        {
            cout<<"Bot\n";
        }
    }
    else
    {
        cout<<"Bot\n";
    }
    
}

signed main() {
    int T = 1; cin >> T;
    while (T--) solve();
}