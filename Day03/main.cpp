#include <iostream>
#include <fstream>
#include <string>

long long bestKDigits(const std::string &s, int k) {
    int n = (int)s.size();
    if (k >= n) {
        long long res = 0;
        for (char c : s) res = res * 10 + (c - '0');
        return res;
    }

    std::string chosen;
    chosen.reserve(k);
    int start = 0;

    for (int pos = 0; pos < k; pos++) {
        int remaining = k - pos;
        char bestDigit = '0';
        int bestIndex = start;
        int limit = n - remaining;
        for (int i = start; i <= limit; i++) {
            if (s[i] > bestDigit) {
                bestDigit = s[i];
                bestIndex = i;
            }
        }
        chosen.push_back(bestDigit);
        start = bestIndex + 1;
    }

    long long res = 0;
    for (char c : chosen) res = res * 10 + (c - '0');
    return res;
}

int main() {
    std::ifstream file("input.txt");
    if (!file) {
        std::cerr << "Cannot open input.txt\n";
        return 1;
    }

    long long totalPart1 = 0;
    long long totalPart2 = 0;
    std::string line;

    while (std::getline(file, line)) {
        if (line.empty()) continue;
        totalPart1 += bestKDigits(line, 2);
        totalPart2 += bestKDigits(line, 12);
    }

    std::cout << totalPart1 << "\n";
    std::cout << totalPart2 << "\n";
    return 0;
}
