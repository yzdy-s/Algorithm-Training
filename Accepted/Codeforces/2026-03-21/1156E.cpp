#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n;cin >> n;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) cin >> arr[i];
    vector<int> L(n + 1), R(n + 1);
    stack<PII> sc;
    sc.push({LNF, 0});
    for (int i = 1; i <= n; i++) {
        while (sc.size() && sc.top().first < arr[i]) sc.pop();
        L[i] = sc.top().second;
        sc.push({arr[i], i});
    }
    while (sc.size()) sc.pop();
    sc.push({LNF, n + 1});
    for (int i = n; i >= 1; i--) {
        while (sc.size() && sc.top().first < arr[i]) sc.pop();
        R[i] = sc.top().second;
        sc.push({arr[i], i});
    }
    // for (int i = 1; i <= n; i++) cout << L[i] << " \n"[i == n];
    vector<int> pos(n + 1);
    for (int i = 1; i <= n; i++) {
        pos[arr[i]] = i;
    }

    int res = 0;
    for (int i = 1; i <= n; i++) {
        int l = L[i], r = R[i];
        int lLen = i - l + 1;
        int rLen = r - i + 1;
        if (lLen < rLen) {
            for (int j = l + 1; j < i; j++) {
                int aid = arr[i] - arr[j];
                if (pos[aid] > i && pos[aid] < r) res++;
            }
        } else {
            for (int j = i + 1; j < r; j++) {
                int aid = arr[i] - arr[j];
                if (pos[aid] < i && pos[aid] > l) res++;
            }
        }
    }

    cout << res << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;//cin >> T;
    while (T--) solve();
}
