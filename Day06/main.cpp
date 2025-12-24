#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::string trim(const std::string &s) {
    int i = 0, j = (int)s.size() - 1;
    while (i <= j && s[i] == ' ') i++;
    while (j >= i && s[j] == ' ') j--;
    if (i > j) return "";
    return s.substr(i, j - i + 1);
}

int main() {
    std::ifstream file("input.txt");
    if (!file) return 1;

    std::vector<std::string> rows;
    std::string line;

    while (std::getline(file, line)) {
        if (!line.empty() && line.back() == '\r') line.pop_back();
        rows.push_back(line);
    }

    int H = rows.size();
    if (H == 0) {
        std::cout << 0 << "\n" << 0 << "\n";
        return 0;
    }

    int W = 0;
    for (auto &r : rows) if ((int)r.size() > W) W = r.size();
    for (auto &r : rows) r.resize(W, ' ');

    std::vector<std::pair<int,int>> blocks;
    int c = 0;
    while (c < W) {
        bool emptyCol = true;
        for (int r = 0; r < H; r++) {
            if (rows[r][c] != ' ') { emptyCol = false; break; }
        }
        if (emptyCol) { c++; continue; }

        int start = c;
        while (c < W) {
            bool empty2 = true;
            for (int r = 0; r < H; r++) {
                if (rows[r][c] != ' ') { empty2 = false; break; }
            }
            if (empty2) break;
            c++;
        }
        blocks.push_back({start, c - 1});
    }

    long long totalPart1 = 0;
    long long totalPart2 = 0;

    for (auto &B : blocks) {
        int L = B.first;
        int R = B.second;

        char op = '+';
        for (int x = L; x <= R; x++) {
            if (rows[H-1][x] == '*' || rows[H-1][x] == '+') {
                op = rows[H-1][x];
                break;
            }
        }

        long long res1 = (op == '*') ? 1 : 0;
        for (int r = 0; r < H - 1; r++) {
            std::string part = trim(rows[r].substr(L, R - L + 1));
            if (part.empty()) continue;
            long long val = std::stoll(part);
            if (op == '*') res1 *= val;
            else res1 += val;
        }
        totalPart1 += res1;

        long long res2 = (op == '*') ? 1 : 0;
        for (int col = L; col <= R; col++) {
            std::string s;
            for (int r = 0; r < H - 1; r++) {
                char ch = rows[r][col];
                if (ch >= '0' && ch <= '9') s.push_back(ch);
            }
            if (s.empty()) continue;
            long long val = std::stoll(s);
            if (op == '*') res2 *= val;
            else res2 += val;
        }
        totalPart2 += res2;
    }

    std::cout << totalPart1 << "\n";
    std::cout << totalPart2 << "\n";
    return 0;
}
