#include<bits/stdc++.h>
using namespace std;

#define int long long
int b[100];
void insert(int x)
{
    for(int i=60;i>=0;i--)
    {
        
        if(x>>i&1)
        {
            if(b[i])
            {
                x^=b[i];
            }
            else
            {
                b[i]=x;
                return;
            }
            
        }
    }
}
void solve() {
    int n;cin >> n;
    vector<int> arr(n + 1);
    int sum = 0;
    vector<int> cnt(67, 0);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        sum ^= arr[i];
        for (int bit = 0; bit <= 60; bit++) {
            if ((arr[i] >> bit) & 1) cnt[bit]++;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int bit = 60; bit >= 0; bit--) {
            if ((cnt[bit] & 1) && ((arr[i] >> bit) & 1)) arr[i] ^= (1 << bit);
        }
        insert(arr[i]);
    }
    int mx = 0;
    for(int i=60;i>=0;i--)
    {
        mx=max(mx,mx^b[i]);
    }
    int other = sum ^ mx;
    cout << max(sum, other & mx) << endl;


    for(int i=60;i>=0;i--)
    {
        b[i]=0;
    }
}

signed main() {
    int T = 1;cin >> T;
    while (T--) solve();
}