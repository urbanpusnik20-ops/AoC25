#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

struct Shape {
    std::vector<std::pair<int,int>> cells;
};

std::vector<Shape> shapes;
std::vector<std::vector<Shape>> variants;

int W, H;
std::vector<std::vector<int>> grid;
std::vector<Shape> pieces;

Shape normalize(const Shape& s) {
    int minx = 1e9, miny = 1e9;
    for (auto& c : s.cells) {
        minx = std::min(minx, c.first);
        miny = std::min(miny, c.second);
    }
    Shape r;
    for (auto& c : s.cells)
        r.cells.push_back({c.first - minx, c.second - miny});
    std::sort(r.cells.begin(), r.cells.end());
    return r;
}

Shape rotate90(const Shape& s) {
    Shape r;
    for (auto& c : s.cells)
        r.cells.push_back({-c.second, c.first});
    return normalize(r);
}

Shape flipH(const Shape& s) {
    Shape r;
    for (auto& c : s.cells)
        r.cells.push_back({-c.first, c.second});
    return normalize(r);
}

bool sameShape(const Shape& a, const Shape& b) {
    return a.cells == b.cells;
}

bool canPlace(const Shape& s, int x, int y) {
    for (auto& c : s.cells) {
        int nx = x + c.first;
        int ny = y + c.second;
        if (nx < 0 || ny < 0 || nx >= W || ny >= H) return false;
        if (grid[ny][nx]) return false;
    }
    return true;
}

void place(const Shape& s, int x, int y, int v) {
    for (auto& c : s.cells)
        grid[y + c.second][x + c.first] = v;
}

bool dfs(int idx) {
    if (idx == (int)pieces.size()) return true;

    int empty = 0;
    for (int y = 0; y < H; y++)
        for (int x = 0; x < W; x++)
            if (!grid[y][x]) empty++;

    int need = 0;
    for (int i = idx; i < (int)pieces.size(); i++)
        need += pieces[i].cells.size();

    if (empty < need) return false;

    for (auto& v : variants[idx]) {
        for (int y = 0; y < H; y++) {
            for (int x = 0; x < W; x++) {
                if (canPlace(v, x, y)) {
                    place(v, x, y, idx + 1);
                    if (dfs(idx + 1)) return true;
                    place(v, x, y, 0);
                }
            }
        }
    }
    return false;
}

int main() {
    std::ifstream f("input.txt");
    std::string line;

    while (std::getline(f, line)) {
        if (line.empty()) break;
        Shape s;
        std::getline(f, line);
        int y = 0;
        while (!line.empty()) {
            for (int x = 0; x < (int)line.size(); x++)
                if (line[x] == '#')
                    s.cells.push_back({x, y});
            if (!std::getline(f, line)) break;
            y++;
        }
        shapes.push_back(normalize(s));
    }

    for (auto& s : shapes) {
        std::vector<Shape> v;
        Shape cur = s;
        for (int r = 0; r < 4; r++) {
            Shape n = cur;
            for (int f = 0; f < 2; f++) {
                Shape nn = normalize(n);
                bool ok = true;
                for (auto& e : v)
                    if (sameShape(e, nn)) ok = false;
                if (ok) v.push_back(nn);
                n = flipH(n);
            }
            cur = rotate90(cur);
        }
        variants.push_back(v);
    }

    int result = 0;

    while (std::getline(f, line)) {
        if (line.empty()) continue;

        int x = line.find('x');
        W = std::stoi(line.substr(0, x));
        H = std::stoi(line.substr(x + 1));

        std::vector<int> cnt(shapes.size());
        for (int i = 0; i < (int)cnt.size(); i++)
            f >> cnt[i];
        f.ignore();

        pieces.clear();
        for (int i = 0; i < (int)cnt.size(); i++)
            for (int k = 0; k < cnt[i]; k++)
                pieces.push_back(shapes[i]);

        std::sort(pieces.begin(), pieces.end(),
            [](const Shape& a, const Shape& b) {
                return a.cells.size() > b.cells.size();
            });

        std::vector<std::vector<Shape>> newVars;
        for (auto& p : pieces) {
            for (int i = 0; i < (int)shapes.size(); i++) {
                if (sameShape(p, shapes[i])) {
                    newVars.push_back(variants[i]);
                    break;
                }
            }
        }
        variants = newVars;

        grid.assign(H, std::vector<int>(W, 0));

        if (dfs(0)) result++;
    }

    std::cout << result << std::endl;
    return 0;
}
