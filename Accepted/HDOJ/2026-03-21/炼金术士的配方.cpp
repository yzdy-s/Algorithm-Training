#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

static mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());

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
    unordered_map<int, unsigned int> hash;
    for (auto &p : primes) hash[p] = rnd();

    int n, x;cin >> n >> x;
    vector<int> arr(n + 1);
    vector<unsigned int> val(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        int t = arr[i];
        while (t != 1) {
            int c = 0;
            int mn = minp[t];
            while (t % mn == 0) {
                c++;
                t /= mn;
            }
            if (c & 1) val[i] ^= hash[mn];
        }
    }

    unsigned int cur = 0;
    unsigned int aid = 0;
    while (x != 1) {
        int c = 0;
        int mn = minp[x];
        while (x % mn == 0) {
            c++;
            x /= mn;
        }
        if (c & 1) aid ^= hash[mn];
    }

    map<unsigned int, int> cnt;
    cnt[0] = 1;
    int res = 0;
    for (int r = 1; r <= n; r++) {
        cur ^= val[r];
        unsigned int q = aid ^ cur;
        res += cnt[q];
        cnt[cur]++;
    }

    cout << res << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    sieve(1e6 + 7);
    int T = 1;//cin >> T;
    while (T--) solve();
}
