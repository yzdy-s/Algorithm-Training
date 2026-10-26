/* 


3
5
CCCCC
JJJJJ
AAAAA
MMMMM
10
HCJAMHCJAM
CHCHCHCHCH
JAMJAMJAMJ
MAJHAMMACH
103
MMMMMMMMMMCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC
HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
CJCJCJCJHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHJJJCJCJCJCJCJCJCJCJCJCJCJCJCJCJCJCJCJC
HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHAHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH



*/


#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve() {
    int n;cin >> n;
    vector<string> arr(5);
    for (int i = 1; i <= 4; i++) {
        string s;cin >> s;
        arr[i] = "#" + s;
        // cout << s.size() << endl;
    }

    vector<int> b(5, 2000), c(5, 0), live(5, 1);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 4; j++) {
            if (arr[j][i] == 'H') {
                c[j]++;
            } else if (arr[j][i] == 'C') {
                c[j] = 0;
            } else if (arr[j][i] == 'J') {
                c[j] = 0;
                b[j] -= 50;
            } else if (arr[j][i] == 'A') {
                c[j] = 0;
                b[j] -= 100;
            } else if (arr[j][i] == 'M') {
                c[j] = 0;
                b[j] -= 200;
            }
        }

        for (int j = 1; j <= 4; j++) {
            if (c[j] == 100) {
                c[j] = 0;
                // if (live[j] == 0) continue;
                for (int x = 1; x <= 4; x++) {
                    if (x == j) continue;
                    b[x] = min(2000ll, b[x] + 30);
                }
            }
        }

        for (int j = 1; j <= 4; j++) {
            if (b[j] <= 0) {
                live[j] = 0;
            }
        }
    }

    for (int i = 1; i <= 4; i++) cout << live[i] * b[i] << " \n"[i == 4];

}

signed main() {
    int T;cin >> T;
    while (T--) solve();
}