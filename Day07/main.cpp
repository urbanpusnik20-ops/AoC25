#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main() {
    std::ifstream file("input.txt");
    if (!file) return 1;

    std::vector<std::string> g;
    std::string line;
    while (std::getline(file, line)) {
        if (!line.empty() && line.back() == '\r') line.pop_back();
        g.push_back(line);
    }

    if (g.empty()) {
        std::cout << 0 << "\n" << 0 << "\n";
        return 0;
    }

    int H = (int)g.size();
    int W = (int)g[0].size();

    int S_r = -1, S_c = -1;
    for (int r = 0; r < H; r++) {
        for (int c = 0; c < W; c++) {
            if (g[r][c] == 'S') {
                S_r = r;
                S_c = c;
                break;
            }
        }
        if (S_r != -1) break;
    }

    if (S_r == -1) {
        std::cout << 0 << "\n" << 0 << "\n";
        return 0;
    }

    // -----------------------------
    // PART 1 – klasični žarek
    // -----------------------------
    std::vector<int> present(W, 0);
    present[S_c] = 1;
    long long part1 = 0;

    for (int r = S_r + 1; r < H; r++) {
        std::vector<int> next(W, 0);
        for (int c = 0; c < W; c++) {
            if (!present[c]) continue;
            char ch = g[r][c];
            if (ch == '^') {
                part1++;
                if (c - 1 >= 0) next[c - 1] = 1;
                if (c + 1 < W) next[c + 1] = 1;
            } else {
                next[c] = 1;
            }
        }
        present.swap(next);
    }

    // -----------------------------
    // PART 2 – kvantni manifold, DP od spodaj navzgor
    // -----------------------------

    // dp[r][c] = št. timeline-ov, če vstopimo v celico (r,c) od zgoraj
    // Pot izven mreže (r == H ali c < 0 ali c >= W) = 1 timeline

    std::vector<std::vector<long long>> dp(H + 1, std::vector<long long>(W, 0));

    // Baza: r == H (tik pod spodnjo vrstico): izhod iz mreže -> 1 timeline
    for (int c = 0; c < W; c++) {
        dp[H][c] = 1;
    }

    for (int r = H - 1; r >= 0; r--) {
        for (int c = 0; c < W; c++) {
            char ch = g[r][c];
            if (ch == '^') {
                long long left  = (c - 1 >= 0) ? dp[r + 1][c - 1] : 1;
                long long right = (c + 1 < W) ? dp[r + 1][c + 1] : 1;
                dp[r][c] = left + right;
            } else {
                // '.', 'S', karkoli drugega: žarek gre samo dol
                dp[r][c] = dp[r + 1][c];
            }
        }
    }

    long long part2 = 0;
    if (S_r + 1 < H) part2 = dp[S_r + 1][S_c];
    else part2 = 1; // če je S v zadnji vrstici, takoj izhod

    std::cout << part1 << "\n";
    std::cout << part2 << "\n";
    return 0;
}
