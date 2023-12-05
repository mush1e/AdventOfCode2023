#include <iostream>
#include <fstream>
#include <string>

auto main() -> int {
    std::fstream fptr;
    fptr.open("day1p1.txt", std::ios::in);
    std::string token {};
    int sum {};
    while(std::getline(fptr, token)) {
        int first = -1, last = -1;
        for (char ch : token) {
            if(isdigit(ch)) {
                first < 0 ? first = (int)(ch) - 48 : 0;
                last = (int)(ch) - 48;
            }
        }
        sum += first*10 + last;
    }
    std::cout << sum;
}