#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n, k;cin >> n >> k;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];

    vector<set<int>> st1(k), st2(k);
    for (int i = 1; i <= n; i++) {
        int idx = i % k;
        st1[idx].insert(a[i]);
        if (b[i] != -1) st2[idx].insert(b[i]);
    }

    for (int i = 1; i <= n; i++) {
        int idx = i % k;
        if (st1[idx].size() > 1) {
            if (b[i] != -1 && b[i] != a[i]) {
                cout << "NO" << endl;
                return;
            }
            b[i] = a[i];
            st2[idx].insert(b[i]);
        } else if (st1[idx].size() == 1) {
            if (st2[idx].size() > 1) {
                cout << "NO" << endl;
                return;
            }
            int x;
            for (auto &i : st2[idx]) {
                x = i;
                break;
            }
            if (st2[idx].size()) b[i] = x;
        }
    }

    map<int, int> A, B;
    for (int i = 1; i <= k; i++) {
        A[a[i]]++;
        B[b[i]]++;
    }

    for (auto &[num, cnt] : B) {
        if (num == -1) continue;
        if (cnt > A[num]) {
            cout << "NO" << endl;
            return;
        }
    }


    for (int i = k+1; i <= n; i++) {
        A[a[i-k]]--;
        B[b[i-k]]--;
        A[a[i]]++;
        B[b[i]]++;
        if (a[i-k] != -1 && B[a[i-k]] > A[a[i-k]]) {
            cout << "NO" << endl;
            return;
        }
        if (b[i] != -1 && B[b[i]] > A[b[i]]) {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
