//
// Created by tygzy on 12/6/23.
//

#include "main.h"

Game::Game() {
    this->play_values[1] = "Rock";
    this->play_values[2] = "Paper";
    this->play_values[3] = "Scissors";
}

int Game::get_pc_input() {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(1, 3);

    this->pc_input = dist6(rng);

    return dist6(rng);
}

int Game::get_player_input() {
    std::cout << "Please enter Rock: 1, Paper: 2 or Scissors: 3" << std::endl;
    std::cin >> this->player_input;
    return this->player_input;
}

std::string Game::get_played_input(int input) {
    auto search = this->play_values.find(input);
    if(search != this->play_values.end()) {
        return search->second;
    } else {
        std::cout << "No value found for that key" << std::endl;
    }
}

void Game::check_winner() {
    if(this->pc_input > this->player_input) {
        std::cout << "PC wins by playing: " << this->get_played_input(this->pc_input) << std::endl;
    } else if(this->pc_input == this->player_input) {
        std::cout << "Draw!" << std::endl;
    } else {
        std::cout << "PC loses by playing: " << this->get_played_input(this->pc_input) << std::endl;
    }
}

void Game::run() {
    this->running = true;

    while(this->running) {
        this->get_pc_input();
        std::cout << "Welcome to rock, paper, scissors!" << std::endl;
        this->get_player_input();
        check_winner();
        this->running = false;
    }
}