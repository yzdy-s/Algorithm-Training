#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve() {
    int counts[3];
    cin >> counts[0] >> counts[1] >> counts[2];
    char colors[3] = {'R', 'G', 'B'};
    
    string s = "";

    
    while (true) {
        int best_c = -1;
        int max_count = -1;
        int n = s.length();
        

        for (int c = 0; c < 3; ++c) {
            if (counts[c] == 0) continue;
            if (n >= 1 && s[n - 1] == colors[c]) continue;
            if (n >= 3 && s[n - 3] == colors[c]) continue;
            

            bool is_tie_breaker = (n >= 2 && s[n - 2] == colors[c]);
            

            if (counts[c] > max_count) {
                max_count = counts[c];
                best_c = c;
            } else if (counts[c] == max_count) {
                if (is_tie_breaker) {
                    best_c = c;
                }
            }
        }
        

        if (best_c == -1) {
            break;
        }
        
        s += colors[best_c];
        counts[best_c]--;
    }
    
    cout << s << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}