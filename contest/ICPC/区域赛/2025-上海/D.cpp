#include<bits/stdc++.h>
using namespace std;

#define int long long
const int MAXN = (1 << 16) + 9;

int n;
vector<int> arr(MAXN);
vector<int> val(5e7 + 7);
vector<int> pow3(20);

void dfs(int x) {
    for (int bit = 0; bit < n; bit++) {
        int cur;
        if (bit > 0) cur = x / pow3[bit - 1] % 3;
        else cur = x % 3;
        if (cur == 2) continue;
        int nx = cur + (2 - cur) * pow3[bit];
        val[nx] = val[nx - pow3[bit]] + val[nx - 2 * pow3[bit]];
        dfs(nx);
    }
}

void solve() {
    cin >> n;
    for (int i2 = 0; i2 < (1 << n); i2++){
        int i3 = 0;
        for (int bit = 0; bit < n; bit++) {
            i3 += ((i2 >> bit) & 1) * pow3[bit];
        }
        // cout << i3 << ' ';
        cin >> val[i3];
    }
    // cout << endl;
    // dfs(0);
    for(int i=0;i<pow3[n];i++)
    {
        int x=1;
        for(int j=1;j<=pow3[n+1];j*=3)
        {
            if((i/j)%3==2)
            {
                val[i]=val[i-j]+val[i-2*j];
                break;
            }
        }
    }
    int ans = 0;
    // for (int i = 0; i < (pow3[n]); i++) cout << val[i] << ' ';
    // cout << endl;
    for (int i = 0; i < (pow3[n]); i++) ans ^= val[i];
    cout << ans << endl;
}

signed main() {
    pow3[0] = 1;
    
    for (int i = 1; i <= 17; i++) pow3[i] = pow3[i - 1] * 3;
    int T = 1; // cin >> T;
    while (T--) solve();
}