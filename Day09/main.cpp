#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstdlib>

struct P {
    long long x, y;
};

int main() {
    std::ifstream file("input.txt");
    if (!file) return 1;

    std::vector<P> pts;
    std::string line;
    while (std::getline(file, line)) {
        if (!line.empty() && line.back() == '\r') line.pop_back();
        if (line.empty()) continue;
        std::size_t p = line.find(',');
        if (p == std::string::npos) continue;
        long long x = std::stoll(line.substr(0, p));
        long long y = std::stoll(line.substr(p + 1));
        pts.push_back({x, y});
    }

    int n = (int)pts.size();
    if (n < 2) {
        std::cout << 0 << "\n" << 0 << "\n";
        return 0;
    }

    // --------------------
    // PART 1
    // --------------------
    long long best1 = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            long long dx = std::llabs(pts[i].x - pts[j].x) + 1;
            long long dy = std::llabs(pts[i].y - pts[j].y) + 1;
            long long area = dx * dy;
            if (area > best1) best1 = area;
        }
    }

    // --------------------
    // KOORDINATNA KOMPRESIJA ZA PART 2
    // --------------------
    std::vector<long long> xs, ys;
    xs.reserve(n);
    ys.reserve(n);
    for (int i = 0; i < n; i++) {
        xs.push_back(pts[i].x);
        ys.push_back(pts[i].y);
    }

    std::sort(xs.begin(), xs.end());
    xs.erase(std::unique(xs.begin(), xs.end()), xs.end());

    std::sort(ys.begin(), ys.end());
    ys.erase(std::unique(ys.begin(), ys.end()), ys.end());

    int XN = (int)xs.size();
    int YN = (int)ys.size();

    // mapiranje originalnih koordinat v kompresirane indekse
    std::vector<int> ix(n), iy(n);
    for (int i = 0; i < n; i++) {
        ix[i] = (int)(std::lower_bound(xs.begin(), xs.end(), pts[i].x) - xs.begin());
        iy[i] = (int)(std::lower_bound(ys.begin(), ys.end(), pts[i].y) - ys.begin());
    }

    // dodamo rob okoli: +2, indeksiramo 0..XN+1 in 0..YN+1
    int W = XN + 2;
    int H = YN + 2;

    std::vector<std::vector<bool>> boundary(H, std::vector<bool>(W, false));

    // narišemo poligon (zaprt ortogonalen) na kompresiranem gridu
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;

        int x1 = ix[i] + 1;
        int y1 = iy[i] + 1;
        int x2 = ix[j] + 1;
        int y2 = iy[j] + 1;

        if (x1 == x2) {
            int step = (y1 < y2) ? 1 : -1;
            for (int y = y1; ; y += step) {
                boundary[y][x1] = true;
                if (y == y2) break;
            }
        } else if (y1 == y2) {
            int step = (x1 < x2) ? 1 : -1;
            for (int x = x1; ; x += step) {
                boundary[y1][x] = true;
                if (x == x2) break;
            }
        }
    }

    // --------------------
    // FLOOD-FILL ZUNANJOSTI
    // --------------------
    std::vector<std::vector<bool>> outside(H, std::vector<bool>(W, false));
    std::queue<std::pair<int,int>> q;

    for (int x = 0; x < W; x++) {
        if (!boundary[0][x] && !outside[0][x]) {
            outside[0][x] = true;
            q.push({0, x});
        }
        if (!boundary[H-1][x] && !outside[H-1][x]) {
            outside[H-1][x] = true;
            q.push({H-1, x});
        }
    }
    for (int y = 0; y < H; y++) {
        if (!boundary[y][0] && !outside[y][0]) {
            outside[y][0] = true;
            q.push({y, 0});
        }
        if (!boundary[y][W-1] && !outside[y][W-1]) {
            outside[y][W-1] = true;
            q.push({y, W-1});
        }
    }

    int dx4[4] = {1, -1, 0, 0};
    int dy4[4] = {0, 0, 1, -1};

    while (!q.empty()) {
        auto p = q.front();
        q.pop();
        int cy = p.first;
        int cx = p.second;
        for (int k = 0; k < 4; k++) {
            int ny = cy + dy4[k];
            int nx = cx + dx4[k];
            if (ny < 0 || ny >= H || nx < 0 || nx >= W) continue;
            if (boundary[ny][nx]) continue;
            if (outside[ny][nx]) continue;
            outside[ny][nx] = true;
            q.push({ny, nx});
        }
    }

    // --------------------
    // allowed = boundary + notranjost (v kompresiranem gridu)
    // --------------------
    std::vector<std::vector<int>> allowed(H, std::vector<int>(W, 0));
    for (int y = 0; y < H; y++) {
        for (int x = 0; x < W; x++) {
            if (boundary[y][x]) allowed[y][x] = 1;
            else if (!outside[y][x]) allowed[y][x] = 1;
        }
    }

    // --------------------
    // 2D PREFIX SUM NA allowed
    // --------------------
    std::vector<std::vector<long long>> pref(H + 1, std::vector<long long>(W + 1, 0));
    for (int y = 1; y <= H; y++) {
        long long rowSum = 0;
        for (int x = 1; x <= W; x++) {
            rowSum += allowed[y-1][x-1];
            pref[y][x] = pref[y-1][x] + rowSum;
        }
    }

    // --------------------
    // PART 2
    // --------------------
    long long best2 = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int x1c = ix[i] + 1;
            int y1c = iy[i] + 1;
            int x2c = ix[j] + 1;
            int y2c = iy[j] + 1;

            int lx = (x1c < x2c) ? x1c : x2c;
            int rx = (x1c > x2c) ? x1c : x2c;
            int ty = (y1c < y2c) ? y1c : y2c;
            int by = (y1c > y2c) ? y1c : y2c;

            int cellsW = rx - lx + 1;
            int cellsH = by - ty + 1;
            long long cellsArea = (long long)cellsW * (long long)cellsH;

            long long sum = pref[by+1][rx+1] - pref[ty][rx+1] - pref[by+1][lx] + pref[ty][lx];

            if (sum == cellsArea) {
                long long dx = std::llabs(pts[i].x - pts[j].x) + 1;
                long long dy = std::llabs(pts[i].y - pts[j].y) + 1;
                long long realArea = dx * dy;
                if (realArea > best2) best2 = realArea;
            }
        }
    }

    std::cout << best1 << "\n";
    std::cout << best2 << "\n";
    return 0;
}
