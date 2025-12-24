#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <sstream>
#include <algorithm>
#include <climits>
#include <cctype>

struct hash_vector {
    size_t operator()(const std::vector<int>& v) const {
        size_t h = 0;
        for (int x : v) h = h * 31 + x;
        return h;
    }
};

static std::vector<int> parse_brace_list(const std::string& line) {
    size_t lb = line.find('{');
    size_t rb = line.find('}');
    std::vector<int> t;
    if (lb == std::string::npos || rb == std::string::npos || rb <= lb) return t;
    std::stringstream ss(line.substr(lb + 1, rb - lb - 1));
    std::string num;
    while (std::getline(ss, num, ',')) {
        if (!num.empty() && num.back() == '\r') num.pop_back();
        if (!num.empty()) t.push_back(std::stoi(num));
    }
    return t;
}

static void parse_paren_list(const std::string& s, size_t& i, std::vector<int>& out) {
    out.clear();
    i++; // '('
    while (i < s.size() && s[i] != ')') {
        while (i < s.size() && (s[i] == ' ' || s[i] == ',')) i++;
        if (i < s.size() && std::isdigit((unsigned char)s[i])) {
            int v = 0;
            while (i < s.size() && std::isdigit((unsigned char)s[i])) {
                v = v * 10 + (s[i] - '0');
                i++;
            }
            out.push_back(v);
        } else {
            i++;
        }
    }
    if (i < s.size() && s[i] == ')') i++;
}

// ---------- Part 1: meet-in-the-middle min #presses for XOR target ----------
static int solve_part1(unsigned long long target, const std::vector<unsigned long long>& btn) {
    int M = (int)btn.size();
    int A = M / 2;
    int B = M - A;

    std::unordered_map<unsigned long long, int> bestA;
    bestA.reserve(1u << std::min(A, 20));

    for (int s = 0; s < (1 << A); s++) {
        unsigned long long cur = 0;
        int cnt = 0;
        for (int i = 0; i < A; i++) {
            if (s & (1 << i)) { cur ^= btn[i]; cnt++; }
        }
        auto it = bestA.find(cur);
        if (it == bestA.end() || cnt < it->second) bestA[cur] = cnt;
    }

    int ans = INT_MAX;
    for (int s = 0; s < (1 << B); s++) {
        unsigned long long cur = 0;
        int cnt = 0;
        for (int i = 0; i < B; i++) {
            if (s & (1 << i)) { cur ^= btn[A + i]; cnt++; }
        }
        unsigned long long need = target ^ cur;
        auto it = bestA.find(need);
        if (it != bestA.end()) ans = std::min(ans, cnt + it->second);
    }
    return ans;
}

// ---------- Part 2: BFS on vector state (no encoding) ----------
static int solve_part2(const std::vector<int>& target,
                       const std::vector<std::vector<int>>& buttons) {
    int K = (int)target.size();
    if (K == 0) return 0;

    // remove buttons that do nothing
    std::vector<std::vector<int>> btn;
    btn.reserve(buttons.size());
    for (auto b : buttons) {
        bool any = false;
        for (int x : b) if (x) { any = true; break; }
        if (any) btn.push_back(std::move(b));
    }

    // quick impossible check
    for (int i = 0; i < K; i++) {
        if (target[i] == 0) continue;
        bool ok = false;
        for (auto& b : btn) if (b[i]) { ok = true; break; }
        if (!ok) return -1;
    }

    std::unordered_map<std::vector<int>, int, hash_vector> dist;
    std::queue<std::vector<int>> q;
    std::vector<int> start(K, 0);
    dist[start] = 0;
    q.push(start);

    std::vector<int> cur, nxt;

    while (!q.empty()) {
        cur = q.front(); q.pop();
        int d = dist[cur];
        if (cur == target) return d;

        for (auto& b : btn) {
            nxt = cur;
            bool ok = true;
            for (int i = 0; i < K; i++) {
                nxt[i] += b[i];
                if (nxt[i] > target[i]) { ok = false; break; }
            }
            if (ok && dist.find(nxt) == dist.end()) {
                dist[nxt] = d + 1;
                q.push(nxt);
            }
        }
    }

    return -1;
}

int main() {
    std::ifstream file("input.txt");
    if (!file) return 1;

    long long sum1 = 0;
    long long sum2 = 0;

    std::string line;
    std::vector<int> idxs;

    while (std::getline(file, line)) {
        if (!line.empty() && line.back() == '\r') line.pop_back();
        if (line.empty()) continue;

        // lights target mask
        size_t rbr = line.find(']');
        unsigned long long targetMask = 0;
        int Nlights = 0;
        for (size_t i = 1; i < rbr; i++, Nlights++) {
            if (line[i] == '#') targetMask |= (1ULL << Nlights); // 1ULL fixes warning
        }

        // joltage target
        std::vector<int> target = parse_brace_list(line);
        int K = (int)target.size();

        // buttons from (...) used for both parts
        std::vector<unsigned long long> btnMask;
        std::vector<std::vector<int>> btnAdd;

        for (size_t i = 0; i < line.size(); ) {
            if (line[i] == '(') {
                parse_paren_list(line, i, idxs);

                unsigned long long m = 0;
                for (int id : idxs) {
                    if (id >= 0 && id < 64) m ^= (1ULL << id); // 1ULL fixes warning
                }
                btnMask.push_back(m);

                std::vector<int> add(K, 0);
                for (int id : idxs) {
                    if (id >= 0 && id < K) add[id] += 1;
                }
                btnAdd.push_back(add);
            } else i++;
        }

        int p1 = solve_part1(targetMask, btnMask);
        sum1 += p1;

        int p2 = solve_part2(target, btnAdd);
        if (p2 < 0) {
            // če tole vidiš, mi samo napiši max(target) in K in rešimo drugače
            std::cerr << "Part2 failed/too large on a line\n";
            return 1;
        }
        sum2 += p2;
    }

    std::cout << sum1 << "\n" << sum2 << "\n";
    return 0;
}
