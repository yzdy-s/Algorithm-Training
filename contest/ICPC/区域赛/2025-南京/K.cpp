#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>
int dx[]={2,2,-2,-2,1,1,-1,-1};
int dy[]={1,-1,1,-1,2,-2,2,-2};
void solve(){
    int x[3],y[3];
    cin>>x[1]>>y[1]>>x[2]>>y[2];
    
    for(int i=0;i<8;i++)
    {
        int a=x[1]+dx[i],b=y[1]+dy[i];
        if(a>=1&&a<=9&&b>=1&&b<=10)
        {
            if(dx[i]==2&&x[1]+1==x[2]&&y[1]==y[2])
            {
                continue;
            }
            if(dx[i]==-2&&x[1]-1==x[2]&&y[1]==y[2])
            {
                continue;
            }
            if(dy[i]==2&&y[1]+1==y[2]&&x[1]==x[2])
            {
                continue;
            }
            if(dy[i]==-2&&y[1]-1==y[2]&&x[1]==x[2])
            {
                continue;
            }
            if(a==x[2]&&b==y[2])
            {
                cout<<"NO\n";
                return;
            }
            if(a!=x[2]&&b!=y[2])
            {
                cout<<"NO\n";
                return;
            }
        }
    }
    cout<<"YES\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}