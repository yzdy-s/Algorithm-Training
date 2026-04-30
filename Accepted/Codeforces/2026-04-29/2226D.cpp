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
    int f = 1;
    int odd = 0, even = 0;
    for (int i = 1; i <= n; i++) {
        if (arr[i] & 1) odd++;
        else even++; 
        if (i < n && arr[i + 1] < arr[i]) {
            f = 0;
        }
    }
    if (f) {
        cout << "YES" << endl;
        return;
    }
    if (odd == 0 || even == 0) {
        cout << "NO" << endl;
        return;
    }

    // cout << "+" << endl;
    
    int mxOdd = 0, mnOdd = LNF;
    int mxEven = 0, mnEven = LNF;
    for (int i = 1; i <= n; i++) {
        if (arr[i] & 1) {
            mxOdd = max(mxOdd, arr[i]);
            mnOdd = min(mnOdd, arr[i]);
        } else {
            mxEven = max(mxEven, arr[i]);
            mnEven = min(mnEven, arr[i]);
        }
    }
    int a = n + 1, b = 0;
    for (int i = 1; i <= n; i++) {
        if (arr[i] % 2 == 0) {
            if (arr[i] > mxOdd) {
                a = i;
                break;
            }
        }
    }
    for (int i = n; i >= 1; i--) {
        if (arr[i] % 2 == 0 && arr[i] < mnOdd) {
            b = i;
            break;
        }
    }

    if (a < b) {
        cout << "NO" << endl;
        return;
    }
    


    a = n + 1, b = 0;
    for (int i = 1; i <= n; i++) {
        if (arr[i] & 1) {
            if (arr[i] > mxEven) {
                a = i;
                break;
            }
        }
    }

    for (int i = n; i >= 1; i--) {
        if (arr[i] & 1) {
            if (arr[i] < mnEven) {
                b = i;
                break;
            }
        }
    }

    if (a < b) {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
