#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include <string>
#include <set>

std::map<std::string, std::vector<std::string>> g;
long long part1 = 0;
long long part2 = 0;

void dfs1(const std::string& node, std::set<std::string>& visited) {
    if (visited.count(node)) return;
    visited.insert(node);

    if (node == "out") {
        part1++;
        visited.erase(node);
        return;
    }

    for (auto& n : g[node])
        dfs1(n, visited);

    visited.erase(node);
}

void dfs2(const std::string& node, bool has_dac, bool has_fft, std::set<std::string>& visited) {
    if (visited.count(node)) return;
    visited.insert(node);

    if (node == "dac") has_dac = true;
    if (node == "fft") has_fft = true;

    if (node == "out") {
        if (has_dac && has_fft) part2++;
        visited.erase(node);
        return;
    }

    for (auto& n : g[node])
        dfs2(n, has_dac, has_fft, visited);

    visited.erase(node);
}

int main() {
    std::ifstream f("input.txt");
    std::string line;
    while (std::getline(f, line)) {
        std::stringstream ss(line);
        std::string from, to;
        ss >> from;
        from.pop_back();
        while (ss >> to)
            g[from].push_back(to);
    }

    std::set<std::string> visited;
    dfs1("you", visited);
    dfs2("svr", false, false, visited);

    std::cout << "Part 1: " << part1 << std::endl;
    std::cout << "Part 2: " << part2 << std::endl;
}
