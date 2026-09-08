#include <bits/stdc++.h>
#include <random>
#include <random>
using namespace std;
typedef long long ll;

constexpr int N = 5e5+5;

ll a[N];
static mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());
ll rnd_ll(ll a, ll b) {
    uniform_int_distribution<ll> dist(a, b);
    return dist(rnd);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    int T = 1;
    cout << T << '\n';
    for (int i = 1; i <= 5; i++) {
        cout << rnd_ll(0, 1e4) << ' ';
    }
    return 0;
}