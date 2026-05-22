#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>
#define inv(x) (ksm(x, MOD - 2))

const int MOD = 1e9 + 7;

int ksm(int x, int n) {
    int ans = 1;
    x  %= MOD;
    while (n) {
        if (n & 1) ans = (ans * x) % MOD;
        x = (x * x) % MOD;
        n >>= 1;
    }
    return ans;
}

struct node {
    int x;
    vector<int> p;
    bool operator < (const node &other) const &{
        for (int i = 0; i < min(p.size(), other.p.size()); i++) {
            if (p[i] != other.p[i]) return p[i] < other.p[i];
        }
        return x < other.x;
    }
};



std::vector<int> minp, primes, phi;
void sieve(int n) {
    minp.assign(n + 1, 0);
    primes.clear();
    phi.resize(n + 1);
    phi[1] = 1;
    
    for (int i = 2; i <= n; i++) {
        if (minp[i] == 0) {
            minp[i] = i;
            primes.push_back(i);
            phi[i] = i - 1;
        }
        
        for (auto p : primes) {
            if (i * p > n) break;
            minp[i * p] = p;
            if (p == minp[i]) {
                phi[i * p] = phi[i] * p;
                break;
            }
            phi[i * p] = phi[i] * (p - 1);
        }
    }
}

void solve(){
    int n, m;cin >> n >> m;
    vector<int> A(n + 1), B(m + 1);
    for (int i = 1; i <= n; i++) cin >> A[i];
    for (int i = 1; i <= m; i++) cin >> B[i];

    priority_queue<node> a, b;
    for (int i = 1; i <= n; i++) {
        int x = A[i];
        vector<int> p;
        int t = x;
        int mn = minp[t];
        while (t != 1) {
            p.push_back(mn);
            while (t % mn == 0) t /= mn;
            mn = minp[t];
        }
        p.push_back(1);
        node k;
        k.x = x;
        k.p = p;
        a.push(k);
    }
    for (int i = 1; i <= m; i++) {
        int x = B[i];
        vector<int> p;
        int t = x;
        int mn = minp[t];
        while (t != 1) {
            p.push_back(mn);
            while (t % mn == 0) t /= mn;
            mn = minp[t];
        }
        p.push_back(1);
        node k;
        k.x = x;
        k.p = p;
        b.push(k);
    }

    while (a.size()) {
        int x = a.top().x;
        auto p = a.top().p;
        a.pop();
        cout << x << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    sieve(1e6 + 9);
    int T = 1;cin >> T;
    while (T--) solve();
}