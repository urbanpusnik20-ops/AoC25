#include <iostream>
#include <fstream>
#include <string>

bool isInvalidPart1(long long x) {
    std::string s = std::to_string(x);
    int len = (int)s.size();
    if (len % 2 != 0) return false;
    int half = len / 2;
    for (int i = 0; i < half; i++) {
        if (s[i] != s[i + half]) return false;
    }
    return true;
}

bool isInvalidPart2(long long x) {
    std::string s = std::to_string(x);
    int n = (int)s.size();
    for (int d = 1; d <= n / 2; d++) {
        if (n % d != 0) continue;
        int k = n / d;
        if (k < 2) continue;
        bool ok = true;
        for (int i = d; i < n; i++) {
            if (s[i] != s[i % d]) {
                ok = false;
                break;
            }
        }
        if (ok) return true;
    }
    return false;
}

int main() {
    std::ifstream file("input.txt");
    if (!file) {
        std::cerr << "Cannot open input.txt\n";
        return 1;
    }

    std::string line;
    if (!std::getline(file, line)) {
        return 0;
    }

    long long sumPart1 = 0;
    long long sumPart2 = 0;

    std::size_t i = 0;
    while (i < line.size()) {
        std::size_t comma = line.find(',', i);
        if (comma == std::string::npos) comma = line.size();
        std::string token = line.substr(i, comma - i);

        while (!token.empty() && (token.back() == ' ' || token.back() == '\r' || token.back() == '\n'))
            token.pop_back();
        std::size_t start = 0;
        while (start < token.size() && token[start] == ' ')
            start++;
        if (start > 0) token = token.substr(start);

        if (!token.empty()) {
            std::size_t dash = token.find('-');
            if (dash != std::string::npos) {
                long long a = std::stoll(token.substr(0, dash));
                long long b = std::stoll(token.substr(dash + 1));
                for (long long x = a; x <= b; x++) {
                    if (isInvalidPart1(x)) {
                        sumPart1 += x;
                    }
                    if (isInvalidPart2(x)) {
                        sumPart2 += x;
                    }
                }
            }
        }

        i = comma + 1;
    }

    std::cout << sumPart1 << "\n";
    std::cout << sumPart2 << "\n";
    return 0;
}
