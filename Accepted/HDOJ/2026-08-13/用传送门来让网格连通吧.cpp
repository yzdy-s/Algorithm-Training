#include <bits/stdc++.h>
using namespace std;
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

#define fr(i,l,r) for(ll i=(l);i<=(r);i++)
#define rf(i,r,l) for(ll i=(r);i>=(l);i--)
#define all(x) (x).begin(),(x).end()

#define FAST_IO
namespace fin{const int SIZE=1<<16;char buf[SIZE],*S,*T;inline char getchar(){if(S==T){T=(S=buf)+fread(buf,1,SIZE,stdin);if(S==T)return'\n';}return*S++;}}namespace fout{const int SIZE=1<<12;char buf[SIZE],*S=buf,*T=buf+SIZE;inline void flush(){fwrite(buf,1,S-buf,stdout);S=buf;}inline void putchar(char c){*S++=c;if(S==T)flush();}struct Flusher{~Flusher(){flush();}}_;}
#define getchar fin::getchar
#define putchar fout::putchar
namespace fio{struct Reader{template<typename T>Reader&operator>>(T&x){char c=getchar();T f=1;while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}x=0;while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}x*=f;return*this;}Reader&operator>>(char&c){c=getchar();while(c==' '||c=='\n'||c=='\r')c=getchar();return*this;}Reader&operator>>(char*str){int len=0;char c=getchar();while(c==' '||c=='\n'||c=='\r')c=getchar();while(c!=' '&&c!='\n'&&c!='\r'){str[len++]=c;c=getchar();}str[len]='\0';return*this;}Reader&operator>>(std::string&str){str.clear();char c=getchar();while(c==' '||c=='\n'||c=='\r')c=getchar();while(c!=' '&&c!='\n'&&c!='\r'){str.push_back(c);c=getchar();}return*this;}}cin;const char endl='\n';struct Writer{template<typename T>Writer&operator<<(T x){if(x==0){putchar('0');return*this;}if(x<0){putchar('-');x=-x;}static int sta[45];int top=0;while(x){sta[++top]=x%10;x/=10;}while(top){putchar(sta[top]|48);--top;}return*this;}Writer&operator<<(char c){putchar(c);return*this;}Writer&operator<<(char*str){int cur=0;while(str[cur])putchar(str[cur++]);return*this;}Writer&operator<<(const char*str){int cur=0;while(str[cur])putchar(str[cur++]);return*this;}Writer&operator<<(const std::string&str){for(char c:str)putchar(c);return*this;}}cout;}
#define cin fio::cin
#define cout fio::cout
#define endl fio::endl

int n, m;
vector<PII> d = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool isGood(int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= m;
}

int tim = 0, cnt = 0;
const int maxN = 5e4 + 7;
stack<int> sc;
vector<int> adj[maxN];
vector<int> scc[maxN];
int dfn[maxN], low[maxN], belong[maxN];

void init(int N) {
    tim = cnt = 0;
    while (!sc.empty()) sc.pop();
    for (int i = 0; i <= N; i++) {
        scc[i].clear();
        dfn[i] = low[i] = belong[i] = 0;
    }
}

void trajan(int x) {
    sc.push(x);
    low[x] = dfn[x] = ++tim;
    for (auto &son : adj[x]) {
        if (!dfn[son]) {
            trajan(son);
            low[x] = min(low[x], low[son]);
        } else if (!belong[son]) {
            low[x] = min(low[x], low[son]);
        }
    }


    if (dfn[x] == low[x]) {
        cnt++;
        while (1) {
            int v = sc.top();sc.pop();
            belong[v] = cnt;
            if (v == x) break;
        }
    }
}

int fa[maxN][18], deep[maxN];
void dfs(int x, int y)
{
	deep[x] = deep[y] + 1;
	fa[x][0] = y;
	for (int i = 1; (1 << i) <= deep[x]; i++)
	{
		fa[x][i] = fa[fa[x][i - 1]][i - 1];
	}
	for (int i = 0; i < scc[x].size(); i++)
	{
		int a = scc[x][i];
		if (a != y)
		{
			dfs(a, x);
		}
	}
}
int lca(int a,int b)
{
    if (deep[a] < deep[b])
	{
		swap(a, b);
	}
	int x = deep[a] - deep[b];
	for (int i = 17; i >= 0; i--)
	{
		if ((1 << i) & x)
		{
			a = fa[a][i];
		}
	}
	if (a == b)
	{
		return a;
	}
	else
	{
		for (int i = 20; i >= 0; i--)
		{
			if (fa[a][i] != fa[b][i])
			{
				a = fa[a][i];
				b = fa[b][i];
			}
		}
        return fa[a][0];
	}
}

void solve(){
    cin >> n >> m;
    for (int i = 1; i <= n * m; i++) {
        adj[i].clear();
    }
    vector<vector<int>> res(n + 7, vector<int>(m + 7));
    vector<string> arr(n + 7);
    
    int k, q;cin >> k >> q;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            res[i][j] = 0;
        }
    }
    
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        arr[i] = "#" + arr[i];
    }
    int flag = 0;
    int a = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (res[i][j] == 0 && arr[i][j] == '.') {
                flag++;
                queue<PII> q;
                q.push({i, j});
                while (q.size()) {
                    a++;
                    auto [x, y] = q.front(); q.pop();
                    if (res[x][y] != 0) continue;
                    res[x][y] = flag;
                    for (int i = 0; i < 4; i++) {
                        int nx = x + d[i].first, ny = y + d[i].second;
                        if (isGood(nx, ny) && res[nx][ny] == 0 && arr[nx][ny] == '.') q.push({nx, ny});
                    }
                }
            }
        }
    }
    for (int i = 1; i <= k; i++) {
        int stX, stY, edX, edY;cin >> stX >> stY >> edX >> edY;
        int u = res[stX][stY], v = res[edX][edY];
        if (u != v) adj[u].push_back(v);
    }
    
    init(flag);
    for (int i = 1; i <= flag; i++) {
        if (!dfn[i]) trajan(i);
    }
    // for (int i = 1; i <= flag; i++) cout << belong[i] << " \n"[i == flag];
    for (int i = 1; i <= flag; i++) {
        belong[i]++;
    }
    // for (int i = 1; i <= flag; i++) cout << belong[i] << " \n"[i == flag];
    vector<int> root(cnt + 7, 1);
    for (int x = 1; x <= flag; x++) {
        for (auto &son : adj[x]) {
            if (belong[x] != belong[son]) {
                scc[belong[x]].push_back(belong[son]);
                root[belong[son]] = 0;
            }
        }
    }

    // 加虚根
    for (int i = 2; i <= cnt + 1; i++) if (root[i]) scc[1].push_back(i);
    // 邻接表去重
	for (int i = 1; i <= cnt + 1; i++) {
    	sort(scc[i].begin(), scc[i].end());
    	scc[i].erase(unique(scc[i].begin(), scc[i].end()), scc[i].end());
	}
    
    dfs(1,0);
    while (q--) {
        int a, b, c, d;cin >> a >> b >> c >> d;
        int u = res[a][b], v = res[c][d];
        // cout << u << ' ' << v << ' ';
        u = belong[u], v = belong[v];
        // cout << u << ' ' << v << endl;
        int lc = lca(u, v);
        // cout << lca << ' ';
        if (lc == u) cout << 1 << endl;
        else cout << 0 << endl;
    }
    for(int i=1;i<=cnt+1;i++)
    {
        for(int j=0;j<=17;j++)
        {
            fa[i][j]=0;
        }
    }
}

signed main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
