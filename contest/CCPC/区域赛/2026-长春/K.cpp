#include <bits/stdc++.h>
using namespace std;
#define int long long

/*
5 4 3
0 3
1 2
0 5
1 4
1 4
2 3
1 2

2
1
2

*/

void solve() {
    int n,m,q;
    cin>>n>>m>>q;
    deque<int>dq[2];
    vector<int>op(m+1),a(m+1),ans(q+1);
    map<int,vector<pair<int,int>>>mp;
    for(int i=1;i<=m;i++)
    {
        cin>>op[i];
        cin>>a[i];
    }
    for(int i=1;i<=q;i++)
    {
        int l,r;
        cin>>l>>r;
        mp[r].push_back({l,i});
    }
    for(int i=1;i<=m;i++)
    {
        if(op[i]==0)
        {
            while(dq[0].size()&&a[dq[0].back()]<=a[i])
            {
                dq[0].pop_back();
            }
            dq[0].push_back(i);
            {
                if(a[i]==n)
                {
                    while(dq[1].size()) dq[1].pop_back();
                }
                while(dq[1].size())
                {
                    if(a[dq[1].front()]>a[i])break;
                    a[dq[1].front()]=a[i]+1;
                    if(dq[1].size()>1)
                    {
                        if(a[dq[1].at(1)]<=a[dq[1].front()])dq[1].pop_front();
                    }
                }
            }
        }
        else
        {
            while(dq[1].size()&&a[dq[1].back()]>=a[i])
            {
                dq[1].pop_back();
            }
            dq[1].push_back(i);
            {
                if(a[i]==1)
                {
                    while(dq[0].size()) dq[0].pop_back();
                }
                while(dq[0].size())
                {
                    if(a[dq[0].front()]<a[i])break;
                    a[dq[0].front()]=a[i]-1;
                    if(dq[0].size()>1)
                    {
                        if(a[dq[0].at(1)]>=a[dq[0].front()])dq[0].pop_front();
                    }
                }
            }
        }
        for(auto [x,id]:mp[i])
        {
            if(dq[0].size())
            {
                int l=0,r=dq[0].size()-1,w=-1;
                while(l<=r)
                {
                    int mid=(l+r)/2;
                    if(dq[0].at(mid)<x)
                    {
                        l=mid+1;
                        w=mid;
                    }
                    else
                    {
                        r=mid-1;
                    }
                    
                }
                ans[id]+=dq[0].size()-w-1;
            }
            if(dq[1].size())
            {
                int l=0,r=dq[1].size()-1,w=-1;
                while(l<=r)
                {
                    int mid=(l+r)/2;
                    if(dq[1].at(mid)<x)
                    {
                        l=mid+1;
                        w=mid;
                    }
                    else
                    {
                        r=mid-1;
                    }
                    
                }
                ans[id]+=dq[1].size()-w-1;
            }
        }
    }
    for(int i=1;i<=q;i++)
    {
        cout<<ans[i]<<'\n';
    }
}

signed main() {
    int T = 1;
    //cin >> T;
    while (T--) solve();
}