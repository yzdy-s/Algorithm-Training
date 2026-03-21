#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>
#define PIP pair<int, PII>
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

    sc.push({LNF, n+1});
    for (int i = n; i >= 1; i--) {
        while (sc.size() && sc.top().first < arr[i]) sc.pop();
        R[i] = sc.top().second;
        sc.push({arr[i], i});
    }

    vector<PIP> query; // 闭区间
    for (int i = 1; i <= n; i++) {
        int num = arr[i];
        int l = L[i], r = R[i];
        int lLen = i - l + 1;
        int rLen = r - i + 1;
        int aid = 0;
        if (lLen < rLen) {
            for (int j = l + 1; j < i; j--) {
                aid = max(aid, arr[i] / arr[j]);
            }
            query.push_back({aid, {i+1, r-1}});
        } else {
            for (int j = i + 1; j < r; j++) {
                aid = max(aid, arr[i] / arr[j]);
            }
            query.push_back({aid, {l+1, i-1}});
        }
    }

    sort(query.begin(), query.end());

    map<int, vector<int>> mp;
    for (int i = 1; i <= n; i++) {
        int num = arr[i];
        mp[num].push_back(i);
    }

    vector<int> cur;
    int res = 0;
    for (auto &q : query) {
        for (auto &m : mp) {
            if (m.first <= q.first) {
                vector<int> t;
                for ()
            } else break;
        }
    }

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;//cin >> T;
    while (T--) solve();
}