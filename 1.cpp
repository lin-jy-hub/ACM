#include <bits/stdc++.h>

#if defined (_WIN64)
#pragma GCC optimize(3,"Ofast","inline")
// #pragma GCC optimize(2)
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

struct node { int b, k, id; };
bool cmp(Pii L0, Pii L1, Pii R0, Pii R1) {
    return (L1.first - L0.first) * (R1.second - R0.second) > (L1.second - L0.second) * (R1.first - R0.first);
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m;
    std::cin >> n >> m;
    vec<int> a(n);
    std::cin >> a;
    vec<node> query(m);
    rep(i, 0, m) std::cin >> query[i].b >> query[i].k, query[i].id = i;
    if(n == 1) {
        rep(i, 0, m) std::cout << query[i].b - a[0] << '\n';
        return 0;
    }
    vec<node> Cquery = query;
    sort(query, [](node a, node b){return a.k < b.k;});
    vec<int> ans(m);
    vec<Pii> P;
    P.push_back({a[0], 0});
    P.push_back({a[1], 1});
    rep(i, 2, n) {
        while(P.size() >= 2 and cmp(P.back(), {a[i], i}, P[P.size() - 2], P.back())) P.pop_back();
        P.push_back({a[i], i});
    }
    rep(i, 0, P.size() - 1) {
        while(!query.empty() and query.back().k >= 1.0 * (P[i + 1].first - P[i].first) / (P[i + 1].second - P[i].second)) 
        ans[query.back().id] = P[i].second, query.pop_back();
    }
    while(!query.empty()) ans[query.back().id] = P.back().second, query.pop_back();
    rep(i, 0, m) std::cout << Cquery[i].b + ans[i] * Cquery[i].k - a[ans[i]] << '\n';
    return 0;
}