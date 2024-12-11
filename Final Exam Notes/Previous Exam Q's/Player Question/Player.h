// Player.h
#include <string>

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

    friend std::ostream &operator<<(std::ostream &os, const Player &p) {
        os << p.getName();
        return os;
    }
};