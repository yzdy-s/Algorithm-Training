#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>
bool cmp(int a,int b)
{
    return a>b;
}
void solve(){
    int n,q;
    cin>>n;
    vector<int>a(n+1),b(n+1),sum1(n+1),sum2(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
    }
    sort(a.begin()+1,a.end(),cmp);
    sort(b.begin()+1,b.end());
    for(int i=1;i<=n;i++)
    {
        sum1[i]=sum1[i-1]+a[i];
        sum2[i]=sum2[i-1]+b[i];
    }
    cin>>q;
    while(q--)
    {
        int l=1,r=n,ans=0;
        int x;
        cin>>x;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(a[mid]-x*b[mid]>=0)
            {
                l=mid+1;
                ans=mid;
            }
            else
            {
                r=mid-1;
            }
            
        }
        cout<<sum1[ans]-x*sum2[ans]<<' ';
    }
    cout<<'\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}