#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>
const int FULL = (1 << 12) + 7;
const int MAXN = 1e3 + 7;
vector<vector<int>> fa(FULL, vector<int>(MAXN));


#define FAST_IO
namespace fin{const int SIZE=1<<16;char buf[SIZE],*S,*T;inline char getchar(){if(S==T){T=(S=buf)+fread(buf,1,SIZE,stdin);if(S==T)return'\n';}return*S++;}}namespace fout{const int SIZE=1<<12;char buf[SIZE],*S=buf,*T=buf+SIZE;inline void flush(){fwrite(buf,1,S-buf,stdout);S=buf;}inline void putchar(char c){*S++=c;if(S==T)flush();}struct Flusher{~Flusher(){flush();}}_;}
#define getchar fin::getchar
#define putchar fout::putchar
namespace fio{struct Reader{template<typename T>Reader&operator>>(T&x){char c=getchar();T f=1;while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}x=0;while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}x*=f;return*this;}Reader&operator>>(char&c){c=getchar();while(c==' '||c=='\n'||c=='\r')c=getchar();return*this;}Reader&operator>>(char*str){int len=0;char c=getchar();while(c==' '||c=='\n'||c=='\r')c=getchar();while(c!=' '&&c!='\n'&&c!='\r'){str[len++]=c;c=getchar();}str[len]='\0';return*this;}Reader&operator>>(std::string&str){str.clear();char c=getchar();while(c==' '||c=='\n'||c=='\r')c=getchar();while(c!=' '&&c!='\n'&&c!='\r'){str.push_back(c);c=getchar();}return*this;}}cin;const char endl='\n';struct Writer{template<typename T>Writer&operator<<(T x){if(x==0){putchar('0');return*this;}if(x<0){putchar('-');x=-x;}static int sta[45];int top=0;while(x){sta[++top]=x%10;x/=10;}while(top){putchar(sta[top]|48);--top;}return*this;}Writer&operator<<(char c){putchar(c);return*this;}Writer&operator<<(char*str){int cur=0;while(str[cur])putchar(str[cur++]);return*this;}Writer&operator<<(const char*str){int cur=0;while(str[cur])putchar(str[cur++]);return*this;}Writer&operator<<(const std::string&str){for(char c:str)putchar(c);return*this;}}cout;}
#define cin fio::cin
#define cout fio::cout
#define endl fio::endl


int find(int k, int x) {
    if (fa[k][x] == x) return x;
    fa[k][x] = find(k, fa[k][x]);
    return fa[k][x];
}

void dfs(int u, int v, int st) {
    int u_fa = find(st, fa[st][u]);
    int v_fa = find(st, fa[st][v]);
    if (u_fa == v_fa) return;
    
    fa[st][u_fa] = v_fa;

    for (int bit = 0; bit <= 11; bit++) {
        if (((st >> bit) & 1) == 0) continue;
        dfs(u, v, st ^ (1 << bit));
    }
}
void solve(){
    int n, q;cin >> n >> q;
    for (int i = 0; i < FULL; i++) {
        for (int j = 1; j <= n; j++) fa[i][j] = j;
    }

    long long ans = 0;
    while (q--) {
        char op;cin >> op;
        int u, v;cin >> u >> v;
        if (op == '+') {
            int w;cin >> w;
            dfs(u, v, w);
        } else {
            int res = 0;
            for (int bit = 11; bit >= 0; bit--) {
                int t = res | (1 << bit);
                if (find(t, fa[t][u]) == find(t, fa[t][v])) res |= (1 << bit);
            }
            if (!res && find(0, fa[0][u]) != find(0, fa[0][v])) ans--;
            else ans += res;
            // cout << t << endl;
        }
    }
    
    cout << ans << endl;
}

signed main() {
    int T = 1;cin >> T;
    while (T--) solve();
}