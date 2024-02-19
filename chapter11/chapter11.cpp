#include "chapter11.h"

#include <iostream>
#include <random>

#include "task2/Apple.h"
#include "task2/Banana.h"
#include "task2/GrannySmith.h"

#include "task3/Monster.h"
#include "task3/Creature.h"
#include "task3/Player.h"

#include "../URNG.h"

void chapter11Task2() {
    Apple a("red");
    Banana b;
    GrannySmith c;

    std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
    std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
    std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";
}

Player spawnPlayer() {
    std::cout << "Enter your name:";
    std::string name;
    std::cin >> name;

    Player player(name);

    std::cout << "Welcome, " << player.getName() << ".\n";

    return player;
}

Monster spawnMonster() {
    Monster monster = Monster::getRandomMonster();
    std::cout << "You've encountered the " << monster.getName() << " (" << monster.getSymbol()
            << ").\n";

    return monster;
}

void playerAttack(Player &player, Monster &monster) {
    std::cout << "You hit the " << monster.getName() << " for " << player.getDamage() <<
            " damage.\n";
    monster.reduceHealth(player.getDamage());

    if (monster.isDead()) {
        std::cout << "You've killed the " << monster.getName() << ".\n";
        player.levelUp();
        std::cout << "You are now level " << player.getLevel() << ".\n";
        std::cout << "You've found " << monster.getGold() << " gold.\n";
        player.addGold(monster.getGold());
    }
}

void monsterAttack(Player &player, Monster &monster) {
    std::cout << "The " << monster.getName() << " hits you for " << monster.getDamage() <<
            " damage.\n";
    player.reduceHealth(monster.getDamage());
}

void fightMonster(Player &player, Monster &monster) {
    while (!monster.isDead()) {
        std::cout << "(R)un or F(ight):";
        char choice;
        std::cin >> choice;

        if (choice == 'R' || choice == 'r') {
            URNG urng;
            if (urng.flipTheCoin()) {
                std::cout << "You've successfully fled.\n";
                return;
            }
            else {
                std::cout << "You didn't have luck to flee.\n";
                monsterAttack(player, monster);
                if (player.isDead()) return;
            }
        }
        else if (choice == 'F' || choice == 'f') {
            playerAttack(player, monster);
            if (!monster.isDead()) {
                monsterAttack(player, monster);
                if (player.isDead()) return;
            }
        }
    }
}

bool playGame() {
    Player player = spawnPlayer();

    while (!player.isDead()) {
        Monster monster = spawnMonster();

        fightMonster(player, monster);

        if (player.hasWon()) {
            std::cout << "Congratulations, you won!\nYou've looted " << player.getGold() <<
                    " gold!\n";
            return true;
        }
    }
    std::cout << "You died at level " << player.getLevel() << " with " << player.getGold() <<
            " gold.\nToo bad you can't take it with you!\n";

    return false;
}

void chapter11Task3() {
    playGame();
    std::cout << "Thank you for playing!";
}

void chapter11() {
    // chapter11Task2();
    chapter11Task3();
}
