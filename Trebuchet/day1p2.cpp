#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

auto main() -> int {
    int sum {};
    std::vector<std::string> list = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    std::fstream fptr;
    fptr.open("day1p1.txt", std::ios::in);
    std::string token {}, updated_line {};
    while(std::getline(fptr, token)) {
        std::string updated_line = token;
        for (auto i = 0u; i < 10;) {

            size_t index = updated_line.find(list[i]);

            index != std::string::npos 
                ? updated_line[index+1] = (char)('0' + i)
                : i++;
        }
        int first = -1, last = -1;

        for (char ch : updated_line) 
            if(isdigit(ch)) {
                first < 0 ? first = (int)(ch) - 48 : 0;
                last = (int)(ch) - 48;
            }
            
        sum += first*10 + last;
    }
    std::cout << sum << std::endl;
}