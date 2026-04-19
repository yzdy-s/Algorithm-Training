#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n;cin >> n;
    string s;cin >> s;
    s = '#' + s;
    vector<char> st;
    for (int i = 1; i <= n; i++) {
        st.push_back(s[i]);
        if (st.size() >= 3 && (st[st.size()-1] == 'u' && st[st.size()-2] == 'i' && st[st.size()-3] == 'n')) {
            st.pop_back();
            st.pop_back();
            st.pop_back();
        }
        if (st.size() >= 2 && (st[st.size() - 1] == 'o' && st[st.size()-2] == 'm')) {
            st.pop_back();
            st.pop_back();
        }
    }
    if (st.size() == 0) cout << "Yes" << endl;
    else cout << "No" << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;//cin >> T;
    while (T--) solve();
}
