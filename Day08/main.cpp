#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

struct Point {
    long long x, y, z;
};

struct Edge {
    long long d2;
    int a;
    int b;
};

int find_root(std::vector<int> &parent, int x) {
    while (parent[x] != x) {
        parent[x] = parent[parent[x]];
        x = parent[x];
    }
    return x;
}

bool unite(std::vector<int> &parent, std::vector<int> &sz, int a, int b) {
    int ra = find_root(parent, a);
    int rb = find_root(parent, b);
    if (ra == rb) return false;
    if (sz[ra] < sz[rb]) {
        parent[ra] = rb;
        sz[rb] += sz[ra];
    } else {
        parent[rb] = ra;
        sz[ra] += sz[rb];
    }
    return true;
}

int main() {
    std::ifstream file("input.txt");
    if (!file) return 1;

    std::vector<Point> pts;
    std::string line;

    while (std::getline(file, line)) {
        if (!line.empty() && line.back() == '\r') line.pop_back();
        if (line.empty()) continue;
        std::size_t p1 = line.find(',');
        if (p1 == std::string::npos) continue;
        std::size_t p2 = line.find(',', p1 + 1);
        if (p2 == std::string::npos) continue;
        long long x = std::stoll(line.substr(0, p1));
        long long y = std::stoll(line.substr(p1 + 1, p2 - p1 - 1));
        long long z = std::stoll(line.substr(p2 + 1));
        Point p;
        p.x = x;
        p.y = y;
        p.z = z;
        pts.push_back(p);
    }

    int n = (int)pts.size();
    if (n == 0) {
        std::cout << 0 << "\n" << 0 << "\n";
        return 0;
    }

    std::vector<Edge> edges;
    edges.reserve((long long)n * (n - 1) / 2);

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            long long dx = pts[i].x - pts[j].x;
            long long dy = pts[i].y - pts[j].y;
            long long dz = pts[i].z - pts[j].z;
            long long d2 = dx * dx + dy * dy + dz * dz;
            Edge e;
            e.d2 = d2;
            e.a = i;
            e.b = j;
            edges.push_back(e);
        }
    }

    std::sort(edges.begin(), edges.end(), [](const Edge &e1, const Edge &e2) {
        return e1.d2 < e2.d2;
    });

    std::vector<int> parent(n);
    std::vector<int> sz(n, 1);
    for (int i = 0; i < n; i++) parent[i] = i;

    long long part1 = 0;
    long long part2 = 0;
    bool havePart1 = false;
    bool havePart2 = false;
    int components = n;

    for (int i = 0; i < (int)edges.size(); i++) {
        Edge &e = edges[i];

        bool merged = unite(parent, sz, e.a, e.b);
        if (merged) components--;

        if (i == 999 && !havePart1) {
            std::vector<long long> sizes;
            sizes.reserve(n);
            for (int v = 0; v < n; v++) {
                int r = find_root(parent, v);
                if (r == v) sizes.push_back(sz[v]);
            }
            std::sort(sizes.begin(), sizes.end(), [](long long a, long long b) {
                return a > b;
            });
            while (sizes.size() < 3) sizes.push_back(1);
            part1 = sizes[0] * sizes[1] * sizes[2];
            havePart1 = true;
        }

        if (!havePart2 && components == 1) {
            part2 = pts[e.a].x * pts[e.b].x;
            havePart2 = true;
        }

        if (havePart1 && havePart2) break;
    }

    if (!havePart1) {
        std::vector<long long> sizes;
        sizes.reserve(n);
        for (int v = 0; v < n; v++) {
            int r = find_root(parent, v);
            if (r == v) sizes.push_back(sz[v]);
        }
        std::sort(sizes.begin(), sizes.end(), [](long long a, long long b) {
            return a > b;
        });
        while (sizes.size() < 3) sizes.push_back(1);
        part1 = sizes[0] * sizes[1] * sizes[2];
    }

    std::cout << part1 << "\n";
    std::cout << part2 << "\n";

    return 0;
}
