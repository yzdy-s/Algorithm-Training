#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int a, b;cin >> a >> b;
    int ming = b - a;
    if (ming < 0) {
        cout << "hai sheng ma?";
    } else if (ming <= 250) {
        cout << "nin tai cong ming le!";
    } else {
        cout << "jiu ting tu ran de...";
    }

}