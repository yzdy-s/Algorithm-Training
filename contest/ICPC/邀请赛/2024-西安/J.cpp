#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double

void solve() {
    int a, b;cin >> a >> b;
    if (a < b) swap(a, b);
    int res = 0;
    
    for (double x = 1; x <= b; x++) {
        double h2 = a * 1.0 - a * x / b;
        res += (int)h2 + 1;
    }
    // for(int i=1;i<=a;i++)
    // {
    //     int x,y,z;
    //     int p=res;
    //     x=-(i-1)*b+a*b;
    //     y=-(i)*b+a*b;
    //     z=x+y;
    //     res+=z/(a*2);
    //     z%=2*a;
    //     if(z>=a)res++;
    //     //cout<<res-p<<'\n';
    // }
    cout << res << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;// cin >> T;
    while (T--) solve();
}