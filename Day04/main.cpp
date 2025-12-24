#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main() {
    std::ifstream file("input.txt");
    if (!file) {
        std::cerr << "Cannot open input.txt\n";
        return 1;
    }

    std::vector<std::string> grid;
    std::string line;
    while (std::getline(file, line)) {
        if (!line.empty() && line.back() == '\r') line.pop_back();
        if (!line.empty()) grid.push_back(line);
    }

    if (grid.empty()) {
        std::cout << 0 << "\n" << 0 << "\n";
        return 0;
    }

    int h = (int)grid.size();
    int w = (int)grid[0].size();

    int dx[8] = {-1,-1,-1,0,0,1,1,1};
    int dy[8] = {-1,0,1,-1,1,-1,0,1};

    int part1 = 0;

    for (int r = 0; r < h; r++) {
        for (int c = 0; c < w; c++) {
            if (grid[r][c] != '@') continue;
            int count = 0;
            for (int k = 0; k < 8; k++) {
                int nr = r + dx[k];
                int nc = c + dy[k];
                if (nr >= 0 && nr < h && nc >= 0 && nc < w) {
                    if (grid[nr][nc] == '@') count++;
                }
            }
            if (count < 4) part1++;
        }
    }

    std::vector<std::string> g = grid;
    long long part2 = 0;

    while (true) {
        std::vector<std::pair<int,int>> rem;
        for (int r = 0; r < h; r++) {
            for (int c = 0; c < w; c++) {
                if (g[r][c] != '@') continue;
                int count = 0;
                for (int k = 0; k < 8; k++) {
                    int nr = r + dx[k];
                    int nc = c + dy[k];
                    if (nr >= 0 && nr < h && nc >= 0 && nc < w) {
                        if (g[nr][nc] == '@') count++;
                    }
                }
                if (count < 4) rem.push_back({r, c});
            }
        }
        if (rem.empty()) break;
        part2 += (long long)rem.size();
        for (std::size_t i = 0; i < rem.size(); i++) {
            int r = rem[i].first;
            int c = rem[i].second;
            g[r][c] = '.';
        }
    }

    std::cout << part1 << "\n";
    std::cout << part2 << "\n";
    return 0;
}
