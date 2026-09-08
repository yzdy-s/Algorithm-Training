#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>
int n,a,b;
int calc(int x,int y)
{
    if(y>x)return 0;
    if(x>y)
    swap(x,y);
    
    return (y-x+1)*(y+x)/2;
}
int check(int len)
{
    int sum=0,x=0;
    for(int i=0;i<=len;i++)
    {
        if(sum+(len-i)*b+calc(x,max(0ll,x-len+i+1))>=n)
        {
            //cout<<sum<<' '<<(len-i)*b<<' '<<calc(x,max(0ll,x-len+i+1))<<'\n';
            return 1;
        }
        
        x+=a;
        sum+=x;
        x--;
    }
    return 0;
}
void solve(){
    
    cin>>n>>a>>b;
    if(a==1)
    {
        cout<<(n+b-1)/b;
        return;
    }
    // check(2);
    // return;
    int ans=2e5,l=1,r=2e5;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(check(mid))
        {
            ans=mid;
            r=mid-1;
        }
        else
        {
            l=mid+1;
        }
        
    }
    cout<<ans<<'\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;//cin >> T;
    while (T--) solve();
}
