#include <iostream>
#include <string>

using namespace std;

// Declare player class
class Player {
public:
    string name;
    int health;
    int attack;
    int defense;

    // Constructor
    Player(string n, int h, int a, int d) {
        name = n;
        health = h;
        attack = a;
        defense = d;
    }

    // Attack method
    void attackEnemy(Player& enemy) {
        int damage = attack - enemy.defense;
        if (damage > 0) {
            enemy.health -= damage;
            cout << name << " attacks " << enemy.name << " for " << damage << " damage." << endl;
        }
        else {
            cout << name << " attacks " << enemy.name << " but it has no effect." << endl;
        }
    }
};

int main() {
    // Create player and enemy objects
    Player player("Player", 100, 10, 5);
    Player enemy("Enemy", 50, 8, 3);

    // Game loop
    while (true) {
        // Print player and enemy stats
        cout << player.name << " (Health: " << player.health << ", Attack: " << player.attack << ", Defense: " << player.defense << ")" << endl;
        cout << enemy.name << " (Health: " << enemy.health << ", Attack: " << enemy.attack << ", Defense: " << enemy.defense << ")" << endl;

        // Ask player for action
        cout << "What do you want to do? (1 = Attack, 2 = Run)" << endl;
        int choice;
        cin >> choice;

        // Perform action based on player choice
        if (choice == 1) {
            player.attackEnemy(enemy);
        }
        else if (choice == 2) {
            cout << "You run away from the enemy." << endl;
            break;
        }
        else {
            cout << "Invalid choice." << endl;
        }

        // Check if enemy is defeated
        if (enemy.health <= 0) {
            cout << "You have defeated the enemy!" << endl;
            break;
        }

        // Enemy attacks player
        enemy.attackEnemy(player);

        // Check if player is defeated
        if (player.health <= 0) {
            cout << "You have been defeated." << endl;
            break;
        }
    }

    return 0;
}
