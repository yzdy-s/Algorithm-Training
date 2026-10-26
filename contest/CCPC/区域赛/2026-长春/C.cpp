#include <bits/stdc++.h>
using namespace std;
#define int long long
/*
8
6 3
2 3 1 2 3 1
5 3
1 2 3 1 3
5 4
4 3 2 1 4
6 3
1 3 1 3 1 3
5 2
1 1 1 1 1
6 4
1 2 3 4 5 6
6 2
172 723 593 904 219 576
5 3
3 1 1000000000 999999999 1

0
1
2
4
2
2
6
2

*/

void solve() {
    int n,k;
    cin>>n>>k;
    map<int,int>mp;
    int mx=0;
    for(int i=1;i<=n;i++)
    {
        int j=i-1;
        j%=k;
        int x;
        cin>>x;
        if(x>k) continue;
        x-=j;
        x=(x+k)%k;
        mp[x]++;
        mx=max(mx,mp[x]);
    }
    cout<<n-mx<<'\n';
}

signed main() {
    int T = 1;
    cin >> T;
    while (T--) solve();
}