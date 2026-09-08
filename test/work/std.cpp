#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long 
#define ll long long
const int N=0;
void solve()
{
    ll a[6]={0};
    for(int i=1;i<=5;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+5);
    ll ans=0;
    ll x=a[1]+a[2]+a[3];
    
    if(a[4]-x>0)
    {
        ans+=(a[4]-x+1)/2;
        a[4]-=(a[4]-x+1)/2*2;
    }
    if(a[5]-x>0)
    {
        ans+=(a[5]-x+1)/2;
        a[5]-=(a[5]-x+1)/2*2;
    }
    ll sum=x+a[4]+a[5];
    priority_queue<ll>q;
    for(int i=1;i<=5;i++)
    {
        q.push(a[i]);
    }
    // cout<<a[5]<<'\n';
    // cout<<ans<<'\n';
    // cout<<sum<<'\n';
    //int cnt=0;
    while((sum%3!=0||q.top()*3>sum)&&sum>=0)
    {
        ll y=q.top();
        q.pop();
        ll z=1;
        q.push(y-z*2);
        sum-=2*z;
        ans+=z;
        // cout<<sum<<'\n';
        // cout<<q.top()<<'\n';
        //cnt++;
    }
    //cout<<cnt<<'\n';
    if(sum<0)
    {
        cout<<-1<<'\n';
        return;
    }
    ans+=sum/3;
    cout<<ans<<'\n';
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}