#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::string line;
    std::ifstream ifstr("./d1p1.txt");

    int first, last = INT_MIN;
    int total {}; 

    while(std::getline(ifstr, line)) {
        first = -1;
        last = -1;
        for (const auto& ch : line) {
            if (ch - '0' >= 0 && ch - '0' <= 9) {
                first = first < 0 ? ch - '0' : first;
                last = ch - '0';
            }
        }
        total += first*10 + last;
    }

    std::cout << total << std::endl;
}