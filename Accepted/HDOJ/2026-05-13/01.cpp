#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long 
#define ll long long
const int N=1e6+100;
int fa[N]={0},a[N]={0};
int find(int x)
{
    if(x!=fa[x])
    {
        return fa[x]=find(fa[x]);
    }
    return fa[x];
}
void solve()
{
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        fa[i]=i;
        a[i]=0;
    }
    string s;
    cin>>s;
    for(int i=0;i<n;i++)
    {
        int x=i,y=(x+k)%n;
        while(find(x)!=find(y))
        {
            fa[find(y)]=x;
            x=y;
            y=(x+k)%n;
        }
    }
    
    for(int i=0;i<n;i++)
    {
        if(n-i<=i)
        break;
        fa[find(n-i-1)]=find(i);
    }
    //cout<<1<<'\n';return;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='1')
        {
            a[find(i)]^=1;
        }
    }
    int f=1;
    for(int i=0;i<n;i++)
    {
        if(a[find(i)])
        {
            if(n%2==1&&find(i)==find(n/2))
            continue;
            f=0;
        }
    }
    if(f)
    {
        cout<<"YES\n";
    }
    else
    {
        cout<<"NO\n";
    }
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
