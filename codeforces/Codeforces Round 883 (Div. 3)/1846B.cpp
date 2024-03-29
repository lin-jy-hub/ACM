#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    std::string s[3];
    for (int i = 0; i < 3; i++) {
        std::cin >> s[i];
    }
    
    for (int i = 0; i < 3; i++) {
        if (s[i][0] == s[i][1] && s[i][1] == s[i][2] && s[i][0] != '.') {
            std::cout << s[i][0] << "\n";
            return;
        }
        if (s[0][i] == s[1][i] && s[1][i] == s[2][i] && s[0][i] != '.') {
            std::cout << s[0][i] << "\n";
            return;
        }
    }
    if (s[0][0] == s[1][1] && s[1][1] == s[2][2] && s[0][0] != '.') {
        std::cout << s[0][0] << "\n";
        return;
    }
    if (s[2][0] == s[1][1] && s[1][1] == s[0][2] && s[2][0] != '.') {
        std::cout << s[2][0] << "\n";
        return;
    }
    std::cout << "DRAW\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}
