#include <bits/stdc++.h>
using namespace std;
#define ll long long
int a[1000]={0};
ll n,k;
void cjp(int x)
{
    a[x]^=1;
    for(int y=x+x;y<=n;y+=x)
    {
        cjp(y);
    }
}
void solve() {
    
    cin>>n>>k;
    if(k==1)
    {
        cout<<"YES\n";
    }
    else
    {
        cout<<"NO\n";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;cin >> T;
    while (T--) solve();
}