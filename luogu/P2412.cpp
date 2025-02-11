// #include <bits/stdc++.h>

// #if __GNUC__
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/priority_queue.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/rope>
// template <class _KEY, class _Compare = std::less<_KEY>>
// using pbds_set =
//     __gnu_pbds::tree<_KEY, __gnu_pbds::null_type, _Compare,
//                      __gnu_pbds::rb_tree_tag,
//                      __gnu_pbds::tree_order_statistics_node_update>;
// template <class _KEY, class _VALUE, class _Compare = std::less<_KEY>>
// using pbds_map =
//     __gnu_pbds::tree<_KEY, _VALUE, _Compare, __gnu_pbds::rb_tree_tag,
//                      __gnu_pbds::tree_order_statistics_node_update>;
// template <class T, class Comp = std::less<T>>
// using pbds_heap =
//     __gnu_pbds::priority_queue<T, Comp, __gnu_pbds::pairing_heap_tag>;
// template <class T>
// using rope = __gnu_cxx::rope<T>;
// #endif
// template <class K, class V>
// std::istream &operator>>(std::istream &in, std::pair<K, V> &v);
// template <class K, class V>
// std::ostream &operator<<(std::ostream &out, const std::pair<K, V> &v);
// template <class T>
// std::istream &operator>>(std::istream &in, std::vector<T> &v);
// template <class T>
// std::ostream &operator<<(std::ostream &out, const std::vector<T> &v);
// template <class T, size_t size>
// std::istream &operator>>(std::istream &in, std::array<T, size> &v);
// template <class T, size_t size>
// std::ostream &operator<<(std::ostream &out, const std::array<T, size> &v);
// template <class T>
// std::ostream &operator<<(std::ostream &out, const std::set<T> &s);
// template <class K, class V>
// std::ostream &operator<<(std::ostream &out, const std::map<K, V> &mp);
// #if __SIZEOF_POINTER__ == 8 && __GNUC__ && __cplusplus >= 202002L
// using i128 = __int128;
// std::istream &operator>>(std::istream &in, __int128 &value) {
//     std::string s;
//     in >> s;
//     value = 0;
//     bool op = 0;
//     std::ranges::reverse(s);
//     if (s.back() == '-') {
//         op = 1;
//         s.pop_back();
//     }
//     while (!s.empty()) value = value * 10 + s.back() - '0', s.pop_back();
//     if (op) value = -value;
//     return in;
// }
// std::ostream &operator<<(std::ostream &out, const __int128 &value) {
//     __int128 x = (value < 0 ? -value : value);
//     if (value < 0) out << '-';
//     std::string s;
//     while (x) {
//         s += (char)(x % 10 + '0');
//         x /= 10;
//     }
//     std::ranges::reverse(s);
//     if (s.empty()) s += '0';
//     out << s;
//     return out;
// }
// #endif
// template <class T, class A = std::allocator<T>>
// class vector : public std::vector<T, A> {
//    public:
//     constexpr vector() noexcept(noexcept(A())) : std::vector<T, A>() {}
//     constexpr explicit vector(const A &alloc) noexcept
//         : std::vector<T, A>(alloc) {}
//     constexpr vector(size_t count, const T &value = T(), const A &alloc =
//     A())
//         : std::vector<T, A>(count, value, alloc) {}
//     template <class InputIt>
//     constexpr vector(InputIt first, InputIt last, const A &alloc = A())
//         : std::vector<T, A>(first, last, alloc) {}
//     constexpr vector(const vector &other, const A &alloc = A())
//         : std::vector<T, A>(other, alloc) {}
//     constexpr vector(vector &&other, const A &alloc = A())
//         : std::vector<T, A>(other, alloc) {}
//     constexpr vector(std::initializer_list<T> init, const A &alloc = A())
//         : std::vector<T, A>(init, alloc) {}
//     constexpr T &operator[](size_t pos) { return this->at(pos); }
//     constexpr const T &operator[](size_t pos) const { return this->at(pos); }
// };
// #define RETURN(x)         \
//     do {                  \
//         return x, void(); \
//     } while (0)
// #define All(x) x.begin(), x.end()
// #define pb(x) push_back(x)
// #define eb(x...) emplace_back(x)
// #define fmt(x...) std::format(x)
// #define logs(x...) Print_log(#x " ::", x) << std::endl
// #define ensure(x)                                                        \
//     if (!(x)) {                                                          \
//         std::cerr << "ensure error:(" << #x << ")->at line:" << __LINE__ \
//                   << std::endl;                                          \
//         exit(-1);                                                        \
//     }
// constexpr int inf = INT_MAX;
// constexpr long long INF = LONG_LONG_MAX;
// template <class T>
// using vec = std::vector<T>;
// using str = std::string;
// template <class K, class V>
// using umap = std::unordered_map<K, V>;
// template <class T>
// using uset = std::unordered_set<T>;
// using Pii = std::pair<int, int>;
// template <class T>
// using vvec = std::vector<std::vector<T>>;
// template <class T>
// using min_heap = std::priority_queue<T, std::vector<T>, std::greater<T>>;
// template <class T>
// using max_heap = std::priority_queue<T>;
// template <class T, size_t S>
// using arr = std::array<T, S>;
// template <class K, class V>
// std::istream &operator>>(std::istream &in, std::pair<K, V> &v) {
//     in >> v.first >> v.second;
//     return in;
// }
// template <class K, class V>
// std::ostream &operator<<(std::ostream &out, const std::pair<K, V> &v) {
//     out << '{' << v.first << "," << v.second << '}';
//     return out;
// }
// template <class T>
// std::istream &operator>>(std::istream &in, std::vector<T> &v) {
//     for (auto &i : v) in >> i;
//     return in;
// }
// template <class T>
// std::ostream &operator<<(std::ostream &out, const std::vector<T> &v) {
//     for (auto i = v.begin(); i != v.end(); ++i)
//         out << *i << " \n"[i == v.end()];
//     return out;
// }
// template <class T, size_t size>
// std::istream &operator>>(std::istream &in, std::array<T, size> &v) {
//     for (auto &i : v) in >> i;
//     return in;
// }
// template <class T, size_t size>
// std::ostream &operator<<(std::ostream &out, const std::array<T, size> &v) {
//     for (auto i = v.begin(); i != v.end(); ++i)
//         out << *i << " \n"[i == v.end()];
//     return out;
// }
// template <class T>
// std::ostream &operator<<(std::ostream &out, const std::set<T> &s) {
//     out << "\nsize:" << s.size() << '\n';
//     for (auto i = s.begin(); i != s.end(); ++i)
//         out << *i << " \n"[i == s.end()];
//     return out;
// }
// template <class K, class V>
// std::ostream &operator<<(std::ostream &out, const std::map<K, V> &mp) {
//     out << "\nsize:" << mp.size() << '\n';
//     for (auto i = mp.begin(); i != mp.end(); ++i)
//         out << '{' << i->first << "," << i->second << "}\n";
//     return out;
// }
// template <class K, class V>
// struct std::hash<std::pair<K, V>> {
//     size_t operator()(const std::pair<K, V> &p) const {
//         return std::hash<K>{}(p.first) ^ std::hash<V>{}(p.second);
//     }
// };
// template <bool print = false>
// class Timer {
//    private:
//     std::chrono::system_clock::time_point begin;

//    public:
//     Timer() { begin = std::chrono::system_clock::now(); }
//     ~Timer() {
//         if constexpr (print) {
//             auto end = std::chrono::system_clock::now();
//             auto time =
//                 std::chrono::duration<double, std::nano>(end -
//                 begin).count();
//             std::clog << "\nThe program takes: " << time / 1e9 << " s\n";
//         }
//     }
//     double get() {
//         auto end = std::chrono::system_clock::now();
//         auto time =
//             std::chrono::duration<double, std::nano>(end - begin).count();
//         return time / 1e9;
//     }
// };
// template <class... Ts>
// auto &Print_log(Ts... ts) {
//     return ((std::clog << ts << " "), ...);
// }
// using std::map;  // NOLINT(misc-unused-using-decls)
// using std::set;  // NOLINT(misc-unused-using-decls)
// void solve();

// signed main() {
//     std::ios::sync_with_stdio(false);
//     std::cin.tie(nullptr);
//     int T = 1;
//     // std::cin >> T;
//     while (T--) solve();
//     return 0;
// }

// int size;
// struct Query {
//     int l, r, id;
//     friend bool operator<(const Query &x, const Query &y) {
//         if (x.l / size != y.l / size) return x.l < y.l;
//         if ((x.l / size) & 1) return x.r < y.r;
//         return x.r > y.r;
//     }
// };

// struct node {
//     str s;
//     int pro;
//     friend bool operator<(const node &a, const node &b) {
//         str tmp1 = a.s;
//         str tmp2 = b.s;
//         for (auto &i : tmp1)
//             if (i >= 'A' and i <= 'Z') i = 'A' - 'a';
//         for (auto &i : tmp2)
//             if (i >= 'A' and i <= 'Z') i = 'A' - 'a';
//         if (tmp1 == tmp2) return a.pro > b.pro;
//         else return tmp1 > tmp2;
//     }
// };
// node c[50005];

// std::multiset<node> s;
// void add(node &val) { s.insert(val); }
// void del(node &val) { s.erase(s.find(val)); }

// void solve() {
//     int n, m;
//     std::cin >> n >> m;
//     std::vector<str> ans(m + 1);
//     std::vector<Query> q;
//     size = std::sqrt(n);
//     for (int i = 1; i <= n; ++i) std::cin >> c[i].s, c[i].pro = i;
//     for (int i = 1; i <= m; ++i) {
//         int l, r;
//         std::cin >> l >> r;
//         q.eb(l, r, i);
//     }

//     std::sort(q.begin(), q.end());

//     int L = 1, R = 0;
//     for (auto [l, r, id] : q) {
//         while (L > l) add(c[--L]);
//         while (R < r) add(c[++R]);
//         while (L < l) del(c[L++]);
//         while (R > r) del(c[R--]);
//         ans[id] = s.begin()->s;
//     }
//     for (int i = 1; i <= m; ++i) {
//         std::cout << ans[i] << '\n';
//     }
// }

#include <bits/stdc++.h>

#if __GNUC__
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
template <class _KEY, class _Compare = std::less<_KEY>>
using pbds_set =
    __gnu_pbds::tree<_KEY, __gnu_pbds::null_type, _Compare,
                     __gnu_pbds::rb_tree_tag,
                     __gnu_pbds::tree_order_statistics_node_update>;
template <class _KEY, class _VALUE, class _Compare = std::less<_KEY>>
using pbds_map =
    __gnu_pbds::tree<_KEY, _VALUE, _Compare, __gnu_pbds::rb_tree_tag,
                     __gnu_pbds::tree_order_statistics_node_update>;
template <class T, class Comp = std::less<T>>
using pbds_heap =
    __gnu_pbds::priority_queue<T, Comp, __gnu_pbds::pairing_heap_tag>;
template <class T>
using rope = __gnu_cxx::rope<T>;
#endif
template <class K, class V>
std::istream &operator>>(std::istream &in, std::pair<K, V> &v);
template <class K, class V>
std::ostream &operator<<(std::ostream &out, const std::pair<K, V> &v);
template <class T>
std::istream &operator>>(std::istream &in, std::vector<T> &v);
template <class T>
std::ostream &operator<<(std::ostream &out, const std::vector<T> &v);
template <class T, size_t size>
std::istream &operator>>(std::istream &in, std::array<T, size> &v);
template <class T, size_t size>
std::ostream &operator<<(std::ostream &out, const std::array<T, size> &v);
template <class T>
std::ostream &operator<<(std::ostream &out, const std::set<T> &s);
template <class K, class V>
std::ostream &operator<<(std::ostream &out, const std::map<K, V> &mp);
#if __SIZEOF_POINTER__ == 8 && __GNUC__ && __cplusplus >= 202002L
using i128 = __int128;
std::istream &operator>>(std::istream &in, __int128 &value) {
    std::string s;
    in >> s;
    value = 0;
    bool op = 0;
    std::ranges::reverse(s);
    if (s.back() == '-') {
        op = 1;
        s.pop_back();
    }
    while (!s.empty()) value = value * 10 + s.back() - '0', s.pop_back();
    if (op) value = -value;
    return in;
}
std::ostream &operator<<(std::ostream &out, const __int128 &value) {
    __int128 x = (value < 0 ? -value : value);
    if (value < 0) out << '-';
    std::string s;
    while (x) {
        s += (char)(x % 10 + '0');
        x /= 10;
    }
    std::ranges::reverse(s);
    if (s.empty()) s += '0';
    out << s;
    return out;
}
#endif
template <class T, class A = std::allocator<T>>
class vector : public std::vector<T, A> {
   public:
    constexpr vector() noexcept(noexcept(A())) : std::vector<T, A>() {}
    constexpr explicit vector(const A &alloc) noexcept
        : std::vector<T, A>(alloc) {}
    constexpr vector(size_t count, const T &value = T(), const A &alloc = A())
        : std::vector<T, A>(count, value, alloc) {}
    template <class InputIt>
    constexpr vector(InputIt first, InputIt last, const A &alloc = A())
        : std::vector<T, A>(first, last, alloc) {}
    constexpr vector(const vector &other, const A &alloc = A())
        : std::vector<T, A>(other, alloc) {}
    constexpr vector(vector &&other, const A &alloc = A())
        : std::vector<T, A>(other, alloc) {}
    constexpr vector(std::initializer_list<T> init, const A &alloc = A())
        : std::vector<T, A>(init, alloc) {}
    constexpr T &operator[](size_t pos) { return this->at(pos); }
    constexpr const T &operator[](size_t pos) const { return this->at(pos); }
};
#define RETURN(x)         \
    do {                  \
        return x, void(); \
    } while (0)
#define All(x) x.begin(), x.end()
#define pb(x) push_back(x)
#define eb(x...) emplace_back(x)
#define fmt(x...) std::format(x)
#define logs(x...) Print_log(#x " ::", x) << std::endl
#define ensure(x)                                                        \
    if (!(x)) {                                                          \
        std::cerr << "ensure error:(" << #x << ")->at line:" << __LINE__ \
                  << std::endl;                                          \
        exit(-1);                                                        \
    }
constexpr int inf = INT_MAX;
constexpr long long INF = LONG_LONG_MAX;
template <class T>
using vec = std::vector<T>;
using str = std::string;
template <class K, class V>
using umap = std::unordered_map<K, V>;
template <class T>
using uset = std::unordered_set<T>;
using Pii = std::pair<int, int>;
template <class T>
using vvec = std::vector<std::vector<T>>;
template <class T>
using min_heap = std::priority_queue<T, std::vector<T>, std::greater<T>>;
template <class T>
using max_heap = std::priority_queue<T>;
template <class T, size_t S>
using arr = std::array<T, S>;
template <class K, class V>
std::istream &operator>>(std::istream &in, std::pair<K, V> &v) {
    in >> v.first >> v.second;
    return in;
}
template <class K, class V>
std::ostream &operator<<(std::ostream &out, const std::pair<K, V> &v) {
    out << '{' << v.first << "," << v.second << '}';
    return out;
}
template <class T>
std::istream &operator>>(std::istream &in, std::vector<T> &v) {
    for (auto &i : v) in >> i;
    return in;
}
template <class T>
std::ostream &operator<<(std::ostream &out, const std::vector<T> &v) {
    for (auto i = v.begin(); i != v.end(); ++i)
        out << *i << " \n"[i == v.end()];
    return out;
}
template <class T, size_t size>
std::istream &operator>>(std::istream &in, std::array<T, size> &v) {
    for (auto &i : v) in >> i;
    return in;
}
template <class T, size_t size>
std::ostream &operator<<(std::ostream &out, const std::array<T, size> &v) {
    for (auto i = v.begin(); i != v.end(); ++i)
        out << *i << " \n"[i == v.end()];
    return out;
}
template <class T>
std::ostream &operator<<(std::ostream &out, const std::set<T> &s) {
    out << "\nsize:" << s.size() << '\n';
    for (auto i = s.begin(); i != s.end(); ++i)
        out << *i << " \n"[i == s.end()];
    return out;
}
template <class K, class V>
std::ostream &operator<<(std::ostream &out, const std::map<K, V> &mp) {
    out << "\nsize:" << mp.size() << '\n';
    for (auto i = mp.begin(); i != mp.end(); ++i)
        out << '{' << i->first << "," << i->second << "}\n";
    return out;
}
template <class K, class V>
struct std::hash<std::pair<K, V>> {
    size_t operator()(const std::pair<K, V> &p) const {
        return std::hash<K>{}(p.first) ^ std::hash<V>{}(p.second);
    }
};
template <bool print = false>
class Timer {
   private:
    std::chrono::system_clock::time_point begin;

   public:
    Timer() { begin = std::chrono::system_clock::now(); }
    ~Timer() {
        if constexpr (print) {
            auto end = std::chrono::system_clock::now();
            auto time =
                std::chrono::duration<double, std::nano>(end - begin).count();
            std::clog << "\nThe program takes: " << time / 1e9 << " s\n";
        }
    }
    double get() {
        auto end = std::chrono::system_clock::now();
        auto time =
            std::chrono::duration<double, std::nano>(end - begin).count();
        return time / 1e9;
    }
};
template <class... Ts>
auto &Print_log(Ts... ts) {
    return ((std::clog << ts << " "), ...);
}
using std::map;  // NOLINT(misc-unused-using-decls)
using std::set;  // NOLINT(misc-unused-using-decls)
void solve();

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    // std::cin >> T;
    while (T--) solve();
    return 0;
}

template <class T>
class sparseTable {
   private:
    std::vector<std::vector<T>> ST;
    std::function<T(const T &, const T &)> _func;
    static T default_func(const T &t1, const T &t2) { return std::max(t1, t2); }

   public:
    sparseTable(const std::vector<T> &v, auto func = default_func) {
        _func = func;
        int len = v.size();
        int L1 = std::__lg(len) + 1;
        ST.assign(len, std::vector<T>(L1));
        for (int i = 0; i < len; ++i) ST[i][0] = v[i];

        for (int j = 1; j < L1; ++j) {
            int pj = (1 << (j - 1));
            for (int i = 0; i + pj < len; ++i) {
                ST[i][j] = func(ST[i][j - 1], ST[i + (1 << (j - 1))][j - 1]);
            }
        }
    }
    T operator()(int l, int r) {
        int q = std::__lg(r - l + 1);
        return _func(ST[l][q], ST[r - (1 << q) + 1][q]);
    }
};

struct node {
    str s;
    int pro;
};

void solve() {
    int n, m;
    std::cin >> n >> m;
    vec<node> v(n);
    for (int i = 0; i < n; ++i) std::cin >> v[i].s, v[i].pro = i;
    sparseTable<node> ST(v, [](const node &a, const node &b) -> node {
        str tmp1 = a.s;
        str tmp2 = b.s;
        for (auto &i : tmp1)
            if (i >= 'A' and i <= 'Z') i -= 'A' - 'a';
        for (auto &i : tmp2)
            if (i >= 'A' and i <= 'Z') i -= 'A' - 'a';
        if (tmp1 == tmp2) {
            if (a.pro > b.pro) return a;
            else return b;
        } else {
            if (tmp1 > tmp2) return a;
            else return b;
        }
    });
    while (m--) {
        int l, r;
        std::cin >> l >> r;
        std::cout << ST(l - 1, r - 1).s << '\n';
    }
}