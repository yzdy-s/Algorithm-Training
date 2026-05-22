#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n;cin >> n;
    
    vector<int> arr(50 * n + 7);
    int idx = 1;
    int fr = 0;
    vector<int> res;
    res.push_back(0);
    for (int i = 1; i <= n; i++) {
        while (arr[idx]) idx++;
        cout << idx << ' ';
        // res.push_back(idx);
        arr[idx] = 1;
        if (idx + fr <= 50*n) arr[idx + fr] = 1;
        fr = idx;
    }
    // set<int> st;
    // for (int i = 1; i <= n; i++) {
    //     int x = res[i];
    //     if (st.count(x)) cout << "-----";
    //     st.insert(x);
    //     x = res[i] + res[i - 1];
    //     if (st.count(x)) cout << "-----";
    //     st.insert(x);
    // }
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
