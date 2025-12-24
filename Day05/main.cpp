#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
    std::ifstream file("input.txt");
    if (!file) {
        std::cerr << "Cannot open input.txt\n";
        return 1;
    }

    std::vector<std::pair<long long,long long>> ranges;
    std::string line;

    while (std::getline(file, line)) {
        if (!line.empty() && line.back() == '\r') line.pop_back();
        if (line.empty()) break;
        std::size_t dash = line.find('-');
        if (dash == std::string::npos) continue;
        long long a = std::stoll(line.substr(0, dash));
        long long b = std::stoll(line.substr(dash + 1));
        ranges.push_back({a, b});
    }

    long long part1 = 0;

    while (std::getline(file, line)) {
        if (!line.empty() && line.back() == '\r') line.pop_back();
        if (line.empty()) continue;
        long long id = std::stoll(line);
        bool fresh = false;
        for (std::size_t i = 0; i < ranges.size(); i++) {
            if (id >= ranges[i].first && id <= ranges[i].second) {
                fresh = true;
                break;
            }
        }
        if (fresh) part1++;
    }

    std::sort(ranges.begin(), ranges.end());

    long long part2 = 0;

    long long curL = ranges[0].first;
    long long curR = ranges[0].second;

    for (std::size_t i = 1; i < ranges.size(); i++) {
        long long a = ranges[i].first;
        long long b = ranges[i].second;

        if (a > curR + 1) {
            part2 += (curR - curL + 1);
            curL = a;
            curR = b;
        } else {
            if (b > curR) curR = b;
        }
    }

    part2 += (curR - curL + 1);

    std::cout << part1 << "\n";
    std::cout << part2 << "\n";
    return 0;
}
