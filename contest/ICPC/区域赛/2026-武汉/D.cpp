#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+100;
int n,m;
vector<int>tree[N];
int a[N];
int vis[N];
int flag=1;
void dfs(int u)
{
    if(flag==0)return;
    vis[u]=1;
    for(int v:tree[u])
    {
        if(vis[v])continue;
        if(a[v]==a[u]+1)
        {
            dfs(v);
        }
        else
        {
            flag=0;
        }
        
    }
}
void solve() {
    cin>>n>>m;
    int root=0,f=1;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]==0)
        {
            if(root)
            {
                f=0;
            }
            else
            {
                root=i;
            }
            
        }
    }
    for(int i=1;i<=n;i++)
    {
        int q;
        cin>>q;
        vector<int>v;
        while(q--)
        {
            int x;
            cin>>x;
            if(a[x]!=a[i]+1) v.push_back(x);
            else    tree[i].push_back({x});
        }
        for(int x:v)
        {
            tree[i].push_back({x});
        }
    }
    if(f==0||root==0){cout<<-1;return;}
    dfs(root);
    if(flag==0){cout<<-1;return;}
    cout<<root<<'\n';
    for(int i=1;i<=n;i++)
    {
        for(int x:tree[i])
        {
            cout<<x<<' ';
        }
        cout<<'\n';
    }
}

signed main() {
    int T = 1;//cin >> T;
    while (T--) solve();
}