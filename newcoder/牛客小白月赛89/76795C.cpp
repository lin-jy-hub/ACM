#include <bits/stdc++.h>

#if defined (_WIN64)
#define LOG(x) if(!(x)){std::cout<<"error at:"<<__LINE__<<std::endl;exit(-1);}
#else
#define LOG(x)
#endif
#define int long long
#define rep(i,b,e) for(int i=b;i<(int)(e);++i)
#define range(i,b,e,step) for(int i=b;(b<e?i<e:i>e);i+=(b<e?step:-step))
#define RETURN(x) do{return x,void();}while(0);
#define All(x) x.begin(),x.end()
#define pb(x) push_back(x)
#define eb(x) emplace_back(x)
#define inf INT_MAX
#define INF LONG_LONG_MAX;
template <class T>using vec=std::vector<T>;
template<class K,class V> using umap=std::unordered_map<K,V>;
template<class T>std::istream& operator>>(std::istream&in,std::vector<T>&v) 
{for(auto &i:v)in>>i;return in;}template<class T>std::ostream& 
operator<<(std::ostream&out,const std::vector<T>&v) {
for(auto i=v.begin();i!=v.end();++i)out<<*i<<" \n"[i==v.end()];
return out;}template<class T,class FUN>void foreach
(std::vector<T>&v,FUN fun){for(int i=0;i<v.size();++i)fun(v[i],i);}
template <class T>void sort(std::vector<T>&v) {std::sort(v.begin(),v.end());}
template <class T,class FUN>void sort(std::vector<T>&v,FUN fun) 
{std::sort(v.begin(),v.end(),fun);}template<class T>void input
(T begin,T end){while(begin!=end)std::cin>>*begin++;}
using Pii = std::pair<int, int>;

int px[] = {0, 1, 0, -1};
int py[] = {1, 0, -1, 0};
int n, m;
int count(vec<std::string> &v) {
    int sum = 0;
    for(auto i:v) sum += std::count(All(i), '#');
    return sum;
}

void solve() {
    std::cin >> n >> m;
    vec<std::string> v(n);
    std::cin >> v;
    int sum = count(v);
    if(sum == n * m) RETURN(std::cout << "Red\n");
    if(sum == 0) RETURN(std::cout << "Blue\n");
    vec<std::string> cv = v;
    vec<vec<bool>> vis(n, vec<bool>(m));
    rep(i, 0, n) {
        rep(j, 0, m) {
            if(vis[i][j]) continue;
            if(v[i][j] == '#') {
                std::queue<Pii> q;
                q.push({i, j});
                int K = 0;
                std::set<Pii> S;
                while(!q.empty()) {
                    Pii p = q.front(); q.pop();
                    if(vis[p.first][p.second]) continue;
                    vis[p.first][p.second] = 1;
                    rep(P, 0, 4) {
                        int x = p.first + px[P];
                        int y = p.second + py[P];
                        if(x < 0 or x >= n or y < 0 or y >= m) continue;
                        if(v[x][y] == '.' and !S.count({x, y})) ++K, S.insert({x, y});
                        else if(v[x][y] == '#')q.push({x, y});
                    } 
                }
                // std::cout << K << '\n';
                if(sum + K == n * m) RETURN(std::cout << "Red\n");
            }
        }
    }
    std::cout << "Draw\n";

}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while(T--) solve();
    return 0;
}
