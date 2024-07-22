#include <bits/stdc++.h>

template <size_t base = 26>
class Automaton {
private:
    int sum = 0, tot = 0;
    std::array<std::vector<int>, base> tr;
    std::vector<int> count;
    std::vector<int> fail;
public:
    Automaton(int Sum):sum(Sum),count(Sum),fail(Sum){
        for(int i = 0; i < base; ++i) tr[i].resize(Sum);
    }
    void insert(const std::string &s, int id) {
        int u = 0;
        for(int i = 0; i < s.size(); i++) {
            int c = s[i] - 'a';
            if(!tr[c][u]) tr[c][u] = ++tot;
            u = tr[c][u];
        }
        count[u] = id;
    }

    void build() {
        std::queue<int>q;
        for(int i = 0; i < base; i++) if(tr[i][0]) q.push(tr[i][0]);
        while(!q.empty()) {
            int u = q.front(); q.pop();
            for(int i = 0; i < base; i++) {
                if(tr[i][u]) {
                    fail[tr[i][u]] = tr[i][fail[u]];
                    q.push(tr[i][u]);
                }
                else tr[i][u] = tr[i][fail[u]];
            }
        }
    }

    std::vector<int> query(const std::string &t) {
        int u = 0;
        std::vector<int> ans;
        for(int i = 0; i < t.size(); i++) {
            u = tr[t[i] - 'a'][u];
            for(int j = u; j; j = fail[j]) {
                if(count[j]) ans.push_back(count[j]);
            }
        }
        return ans;
    }
};

int main(){
    int n;
    while(std::cin >> n) {
        if(n == 0) return 0;
        Automaton T(1e6 + 5);
        std::vector<std::string> s(n + 1);
        for(int i = 1; i <= n; ++i) {
            std::cin >> s[i];
            T.insert(s[i], i);
        }
        T.build();
        std::string t;
        std::cin >> t;
        std::vector<int> cnt(n + 1);
        // auto it = T.query(t);
        for(auto i:T.query(t)) cnt[i]++;
        int mx = *std::max_element(cnt.begin() + 1, cnt.end());
        std::cout << mx << '\n';
        for(int i = 1; i <= n; ++i) {
            if(cnt[i] == mx) std::cout << s[i] << '\n';
        }
    }
    return 0;
}