#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream file("input.txt");
    if (!file) {
        std::cerr << "Cannot open input.txt\n";
        return 1;
    }

    int position = 50;
    long long part1 = 0;
    long long part2 = 0;
    std::string line;

    while (std::getline(file, line)) {
        if (line.empty()) continue;

        char dir = line[0];
        long long dist = std::stoll(line.substr(1));
        int step = static_cast<int>(dist % 100);

        if (dir == 'L') {
            long long first;
            if (position == 0) first = 100;
            else first = position;
            if (dist >= first) {
                long long zerosThis = 1 + (dist - first) / 100;
                part2 += zerosThis;
            }
            position = (position - step + 100) % 100;
        } else if (dir == 'R') {
            long long first;
            if (position == 0) first = 100;
            else first = 100 - position;
            if (dist >= first) {
                long long zerosThis = 1 + (dist - first) / 100;
                part2 += zerosThis;
            }
            position = (position + step) % 100;
        }

        if (position == 0) {
            part1++;
        }
    }

    std::cout << part1 << "\n";
    std::cout << part2 << "\n";

    return 0;
}
