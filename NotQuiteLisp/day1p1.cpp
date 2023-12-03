#include <iostream>
#include <fstream>

auto main() -> int {
    int count {}, i {};
    char ch {};
    std::fstream fptr;
    fptr.open("Day1-p1.txt", std::ios::in);
    while(fptr >> ch) {
        ch == '(' ? count += 1 : count -= 1;
        i++;
        if (count == -1) 
            break;
    }
    std::cout << i << std::endl;
    fptr.close();
}