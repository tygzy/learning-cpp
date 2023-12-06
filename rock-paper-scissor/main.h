//
// Created by tygzy on 12/6/23.
//

#ifndef LEARNING_CPP_MAIN_H
#define LEARNING_CPP_MAIN_H

#include <iostream>
#include <random>
#include <map>

class Game {
private:
    int rock = 1;
    int paper = 2;
    int scissors = 3;

    std::map<int,std::string> play_values;

    int player_input;
    int pc_input;

    bool running = false;
public:
    Game();

    int get_pc_input();
    int get_player_input();

    std::string get_played_input(int);

    void check_winner();
    void run();
protected:
};


#endif //LEARNING_CPP_MAIN_H
