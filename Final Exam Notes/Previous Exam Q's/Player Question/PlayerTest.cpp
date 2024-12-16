// Main.cpp (Player Test Code)
#include <iostream>
#include <string>
#include "Player.h"

template<typename T>
void swap(T &one, T &two){
    if constexpr (std::is_same_v<T, Player>){
        int temp = one.getHealth();
        one.health = two.getHealth();
        two.health = temp;
    }
    
}

template<typename T>
void display(T &player, std::string message){
    std::cout << player.getName() << message << std::endl;
}

std::ostream &operator<<(std::ostream &os, const Player &p) {
    os << p.getName();
    return os;
}

int main() {
    Player player1("Player1", 90);
    Player player2("Player2", 10);

    std::cout << "---Testing the display function template---" << std::endl;
    display(player1, " is winning"); // Output: Player1 is winning.

    std::cout << "---Swapping players---" << std::endl;
    swap(player1, player2);
    std::cout << player1.getName() << " has " << player1.getHealth() << " health points" << std::endl;
    // Output: Player1 has 10 health points

    return 0;
}