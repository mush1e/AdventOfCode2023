#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <unordered_map>

class GameValues {
private:
    std::unordered_map<std::string, size_t> values;

public:
    GameValues() {
        values["red"] = 0;
        values["blue"] = 0;
        values["green"] = 0;
    }

    size_t& operator[](const std::string& key) {
        return values[key];
    }

    void reset() {
        values["red"] = 0;
        values["blue"] = 0;
        values["green"] = 0;
    }
}game;

auto main() -> int {
    size_t sum {}, game_id {}, val {};
    std::ifstream fptr;
    fptr.open("day2p1.txt");
    std::string token {}, str {};
    
    while(std::getline(fptr, token)) {
        
        game.reset();
        std::replace(token.begin(), token.end(), ',', ' ');
        std::replace(token.begin(), token.end(), ';', ' ');
        std::replace(token.begin(), token.end(), ':', ' ');

        std::istringstream iss(token);
        iss >> str >> game_id;

        while (iss >> val >> str) 
            game[str] = std::max(game[str], val);
        
        if (game["red"] <= 12 && game["green"] <= 13 && game["blue"] <= 14) 
            sum += game_id;
        
    }
    std::cout << sum;

}