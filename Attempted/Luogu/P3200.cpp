#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

int n, p;

const int maxN = 1e6 + 7;
vector<int> Catalan(maxN);
void pre(int n) {
    Catalan[1] = 1;
    for (int i = 2; i <= n; i++) {
        // Catalan[i] = Catalan[i - 1] * 2 * (2*i - 1) % MOD * inv(i + 1) % MOD;
        Catalan[i] = Catalan[i - 1] * 2 * (2*i - 1) / (i + 1);
    }
}
void solve(){
    cin >> n >> p;
    pre(n);

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;//cin >> T;
    while (T--) solve();
}