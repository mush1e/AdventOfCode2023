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

            size_t index_found = updated_line.find(list[i]);

            if (index_found != std::string::npos) 
                updated_line[index_found+1] = (char)('0' + i);
            else    
                i++;
        }
        int first_num = -1, last_num = -1;

        for (char ch : updated_line) 
            if(isdigit(ch)) {
                first_num < 0 ? first_num = (int)(ch) - 48 : 0;
                last_num = (int)(ch) - 48;
            }
            
        sum += first_num*10 + last_num;
    }
    std::cout << sum << std::endl;
}