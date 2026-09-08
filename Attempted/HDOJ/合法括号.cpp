#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long 
#define ll long long
const int N=0;
void solve()
{
    ll n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    s=' '+s;
    ll cnt=0;
    int l=n+1;
    for(int i=1;i<=n;i++)
    {
        if(s[i]=='?')
        {
            l=i;
            break;
        }
        cout<<s[i];
        if(s[i]=='(')
        {
            cnt++;
        }
        else
        {
            m-=cnt;
            cnt--;
        }
    }
    int r=n;
    ll cnt2=0;
    for(int i=n;i>=1;i--)
    {
        if(s[i]=='?')
        {
            r=i+1;
            break;
        }
        if(s[i]==')')
        {
            cnt2++;
        }
        else
        {
            cnt2--;
        }
    }
    for(int i=r;i<=n;i++)
    {
        if(s[i]=='(')
        {
            cnt2++;
        }
        else
        {
            m-=cnt2;
            cnt2--;
        }
    }
    //cout<<m<<'\n';
    r--;
    ll a=n/2,b=n/2;
    for(int i=1;i<=n;i++)
    {
        if(s[i]=='(')
        {
            a--;
        }
        else if(s[i]==')')
        {
            b--;
        }
    }

    while(1)
    {
        ll x=b*(a+cnt+a+cnt-b+1)/2;
        x-=m;
        //cout<<x<<'\n';return;
        if(x==0)
        {
            for(int j=1;j<=a;j++)cout<<'(';
            for(int j=1;j<=b;j++)cout<<')';
            break;
        }
        while(x>0)
        {
            if(x>a)
            {
                if(cnt>0)
                {
                    x-=a;
                    cnt--;
                    cout<<")";
                }
                else
                {
                    a--;
                    x-=a;
                    cout<<"()";
                }
                b--;
            }
            else
            {
                for(int j=1;j<=a-x;j++)cout<<'(';
                cout<<')';
                for(int j=a-x+1;j<=a;j++)cout<<'(';
                b--;
                x=0;
            }
        }
        for(int j=1;j<=b;j++)cout<<')';
        break;
    }
    for(int i=r+1;i<=n;i++)cout<<s[i];
    cout<<'\n';
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}