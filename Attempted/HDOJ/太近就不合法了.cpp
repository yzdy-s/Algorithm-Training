#include <bits/stdc++.h>
using namespace std;
#define int long long
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

#define FAST_IO
namespace fin{const int SIZE=1<<16;char buf[SIZE],*S,*T;inline char getchar(){if(S==T){T=(S=buf)+fread(buf,1,SIZE,stdin);if(S==T)return'\n';}return*S++;}}namespace fout{const int SIZE=1<<12;char buf[SIZE],*S=buf,*T=buf+SIZE;inline void flush(){fwrite(buf,1,S-buf,stdout);S=buf;}inline void putchar(char c){*S++=c;if(S==T)flush();}struct Flusher{~Flusher(){flush();}}_;}
#define getchar fin::getchar
#define putchar fout::putchar
namespace fio{struct Reader{template<typename T>Reader&operator>>(T&x){char c=getchar();T f=1;while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}x=0;while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}x*=f;return*this;}Reader&operator>>(char&c){c=getchar();while(c==' '||c=='\n'||c=='\r')c=getchar();return*this;}Reader&operator>>(char*str){int len=0;char c=getchar();while(c==' '||c=='\n'||c=='\r')c=getchar();while(c!=' '&&c!='\n'&&c!='\r'){str[len++]=c;c=getchar();}str[len]='\0';return*this;}Reader&operator>>(std::string&str){str.clear();char c=getchar();while(c==' '||c=='\n'||c=='\r')c=getchar();while(c!=' '&&c!='\n'&&c!='\r'){str.push_back(c);c=getchar();}return*this;}}cin;const char endl='\n';struct Writer{template<typename T>Writer&operator<<(T x){if(x==0){putchar('0');return*this;}if(x<0){putchar('-');x=-x;}static int sta[45];int top=0;while(x){sta[++top]=x%10;x/=10;}while(top){putchar(sta[top]|48);--top;}return*this;}Writer&operator<<(char c){putchar(c);return*this;}Writer&operator<<(char*str){int cur=0;while(str[cur])putchar(str[cur++]);return*this;}Writer&operator<<(const char*str){int cur=0;while(str[cur])putchar(str[cur++]);return*this;}Writer&operator<<(const std::string&str){for(char c:str)putchar(c);return*this;}}cout;}
#define cin fio::cin
#define cout fio::cout
#define endl fio::endl

void solve(){
    int n, q;cin >> n >> q;
    while (q--) {
        int x, k;cin >> x >> k;
        vector<int> dp(n + 1);
        vector<int> sum(n + 1);
        for (int i = 1; i <= n; i++) {
            dp[i] = 1;
            if (i - k > 0) dp[i] += sum[i - k];
            if (i == x) dp[i] = 0;
            sum[i] = sum[i - 1] + dp[i];
        }
        cout << sum[n] + 1 << endl;
    }
}

signed main() {
    int T = 1;cin >> T;
    while (T--) solve();
}