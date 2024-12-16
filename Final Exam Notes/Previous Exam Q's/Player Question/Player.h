// Player.h
#include <string>
#include <iostream>

class Player {
private:
    std::string name;
    int health;

public:
    Player() = default;
    Player(std::string name, int health) : name(name), health(health) {}
    Player(std::string name) : name(name), health(0) {}

    int getHealth() const {
        return this->health;
    }

    std::string getName() const {
        return this->name;
    }

    template<typename T>
    friend void swap(T &one, T &two);
    template<typename T>
    void display(T &player, std::string message);
    
};

