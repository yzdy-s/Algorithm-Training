#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

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

bool isprime(int n) {
    return minp[n] == n;
}

void solve(){
    int n;cin >> n;
    vector<int> d1(n + 1, -1), d2(n + 1, -1);
    for (int i = 1; i <= n; i++) {
        int x;cin >> x;
        int d = minp[x];
        int a = 1;
        while (x % d == 0) {
            x /= d;
            a *= d;
        }
        if (x != 1) {
            d1[i] = a;
            d2[i] = x;
        }
    }

    for (int i = 1; i <= n; i++) cout << d1[i] <<  " \n"[i == n];
    for (int i = 1; i <= n; i++) cout << d2[i] <<  " \n"[i == n];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    sieve(1e7 + 7);
    int T = 1;//cin >> T;
    while (T--) solve();
}
