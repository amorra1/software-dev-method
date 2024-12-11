// Main.cpp (Player Test Code)
#include <iostream>
#include <string>
#include "Player.h"


int main() {
    Player player1("Player1", 90);
    Player player2("Player2", 10);

    std::cout << "---Testing the display function template---" << std::endl;
    display(player1, player2); // Output: Player1 is winning.

    std::cout << "---Swapping players---" << std::endl;
    swap(player1, player2);
    std::cout << player1.getName() << " has " << player1.getHealth() << " health points" << std::endl;
    // Output: Player1 has 10 health points

    return 0;
}