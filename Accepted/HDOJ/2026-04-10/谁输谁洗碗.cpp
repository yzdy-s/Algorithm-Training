#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

map<int, vector<string>> mp;

int cnt(string a, string b) {
    int res = 0;
    for (int i = 0; i < 4; i++) {
        if (a[i] == b[i]) res++;
    }
    return res;
}

bool check(string s) {
    for (auto &[c, vec] : mp) {
        for (auto &k : vec) {
            int t = cnt(s, k);
            if (t != c) return false;
        }
    }
    return true;
}

void solve(){
    int n;cin >> n;
    mp.clear();
    string ans = "";
    int mx = 0;
    for (int i = 1; i <= n; i++) {
        string s;cin >> s;
        int x;cin >> x;
        mp[x].push_back(s);
        if (x > mx) {
            mx = x;
            ans = s;
        }
    }
    if (mx == 4) {
        cout << ans << endl;
        return;
    }

    if (mx == 3) {
        for (int bit = 0; bit < 4; bit++) {
            string a = ans;
            for (int i = 0; i < 10; i++) {
                char cur = '0' + i;
                if (cur == ans[bit]) continue;
                a[bit] = cur;
                if (check(a)) {
                    cout << a << endl;
                    return;
                }
            }
        }
    }

    if (mx == 2) {
        vector<int> choose = {12, 10, 9, 6, 5, 3};
        for (auto &st : choose) {
            string a = ans;
            for (int i = 0; i <= 99; i++) {
                int f = 0;
                for (int bit = 0; bit < 4; bit++) {
                    if (((st >> bit) & 1) == 0) {
                        if (f == 0) {
                            a[bit] = ('0' + i % 10);
                            f = 1;
                        } else a[bit] = ('0' + i / 10);
                    }
                }
                if (check(a)) {
                    cout << a << endl;
                    return;
                }
            }
            
        }
    }



    if (mx == 1) {
        vector<int> choose = {1, 2, 4, 8};
        for (auto &st : choose) {
            string a = ans;
            // set<string> A;
            for (int i = 0; i <= 999; i++) {
                int f = 0;
                for (int bit = 0; bit < 4; bit++) {
                    if (((st >> bit) & 1) == 0) {
                        if (f == 0) {
                            a[bit] = ('0' + i % 10);
                            f++;
                        } else if (f == 1) {
                            a[bit] = ('0' + i / 10 % 10);
                            f++;
                        } else if (f == 2){
                            a[bit] = ('0' + i /100 % 10);
                        }
                    }
                }
                // cout << a << endl;
                // A.insert(a);
                if (check(a)) {
                    cout << a << endl;
                    return;
                }
            }
        }

    }

    if (mx == 0) {
        vector<set<char>> cuo(4);
        for (auto &s : mp[0]) {
            for (int bit = 0; bit < 4; bit++) {
                cuo[bit].insert(s[bit]);
            }
        }
        for (int bit = 0; bit < 4; bit++) {
            for (char i = '0'; i <= '9'; i++) {
                if (cuo[bit].count(i)) continue;
                else {
                    cout << i;
                    break;
                }
            }
        }

        cout << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
