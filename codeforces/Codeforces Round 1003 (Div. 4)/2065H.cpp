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
#define int long long
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
    std::cin >> T;
    while (T--) solve();
    return 0;
}

template <class T>
concept checkTreeNode = requires(T t, T ls, T rs, int l, int r, int d) {
    { t.pushUp(ls, rs) };
    { t.pushDown(ls, rs, l, r) };
    { t.rangeChange(l, r, d) };
    { t.update(rs) };
    { t = ls };
    { t.get() };
};
template <checkTreeNode T>
class SegmentTree {
#define getmid ((l + r) >> 1)
#define ls(p) (p << 1)
#define rs(p) (p << 1 | 1)
#define lsArgs ls(p), l, mid
#define rsArgs rs(p), mid + 1, r

   private:
    void pushUp(int p) { data[p].pushUp(data[ls(p)], data[rs(p)]); }
    void pushDown(int p, int l, int r) {
        data[p].pushDown(data[ls(p)], data[rs(p)], l, r);
    }
    template <class X>
    void build(int p, int l, int r, const std::vector<X> &v) {
        if (l == r) {
            data[p] = v[l];
            return;
        }
        int mid = getmid;
        build(lsArgs, v);
        build(rsArgs, v);
        pushUp(p);
    }
    void update(int p, int l, int r, int i, int j, int d) {
        if (i <= l && j >= r) {
            data[p].rangeChange(l, r, d);
            return;
        }
        pushDown(p, l, r);
        int mid = getmid;
        if (i <= mid) update(lsArgs, i, j, d);
        if (j > mid) update(rsArgs, i, j, d);
        pushUp(p);
    }

    void set(int p, int l, int r, int pos, int d) {
        if (l == r) return data[p] = d, void();
        pushDown(p, l, r);
        int mid = getmid;
        if (pos <= mid) set(lsArgs, pos, d);
        else set(rsArgs, pos, d);
        pushUp(p);
    }

    T query(int p, int l, int r, int i, int j) {
        if (i <= l && j >= r) return data[p];
        pushDown(p, l, r);
        int mid = getmid;
        T x;
        if (i <= mid) x.update(query(lsArgs, i, j));
        if (j > mid) x.update(query(rsArgs, i, j));
        return x;
    }

   public:
    SegmentTree() = default;

    SegmentTree(int n) : data(n << 2) {}

    template <class X>
    SegmentTree(const std::vector<X> &v) : n(v.size()), data(v.size() << 2) {
        build(1, 1, n, v);
    }

    void update(int l, int r, int d) { update(1, 1, n, l, r, d); }
    auto query(int l, int r) { return query(1, 1, n, l, r).get(); }
    void set(int pos, int d) { set(1, 1, n, pos, d); }

   private:
    std::vector<T> data;
    int n;
};

struct node {
    int sum = 0, tag = 0;
    void pushUp(const node &ls, const node &rs) { sum = ls.sum + rs.sum; }
    void pushDown(node &ls, node &rs, int l, int r) {
        if (!tag) return;
        int mid = (l + r) >> 1;
        ls.sum += (mid - l + 1) * tag;
        rs.sum += (r - mid) * tag;
        ls.tag += tag;
        rs.tag += tag;
        tag = 0;
    }
    void rangeChange(int l, int r, int d) {  // update
        sum += (r - l + 1) * d;
        tag += d;
    }
    void operator=(int x) { sum = x; }            // build赋值
    void update(const node &x) { sum += x.sum; }  // query
    int get() { return sum; }                     // query
};

void solve() {
    str s;
    std::cin >> s;
    int n = s.size();
    s = '#' + s + '@';
    vec<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        a[i] = a[i - 1];
        if (s[i] != s[i - 1]) a[i]++;
    }
    SegmentTree<node> seg(a);
    int q;
    std::cin >> q;
    while (q--) {
        int pos;
        std::cin >> pos;
        bool op1 = s[pos] == s[pos - 1];
        bool op2 = s[pos] == s[pos + 1];
        if (op1 && op2) seg.update(pos, n, 1);
        else if (!op1 && !op2) seg.update(pos, n, -1);
        else if (op1 && !op2) seg.update(pos, pos, 1);
        else if (!op1 && op2) seg.update(pos, pos, -1);
        s[pos] = (s[pos] == '1' ? '0' : '1');
        std::cout << seg.query(1, n) << ' ';
    }
    std::cout << '\n';
}
