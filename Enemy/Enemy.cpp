//
// Created by AmbarPC on 13/03/2024.
//

#include "Enemy.h"
#include <iostream>


using namespace std;

bool playerSpeed(Player *a) {
    return a->getSpeed();
}

//TODO: Check the circular dependency
int getRolledAttack(int attack) {
    int lowerLimit = attack * .80;
    return (rand() % (attack - lowerLimit)) + lowerLimit;
}

Enemy::Enemy(string name, int health, int attack, int defense, int speed) : Character(name, health, attack, defense, speed, false, maxHealth) {
}

void Enemy::doAttack(Character *target) {
    int rolledAttack = getRolledAttack(getAttack());
    int trueDamage = target->getDefense() > rolledAttack ? 0 : rolledAttack - target->getDefense();
    target->takeDamage(trueDamage);
}

void Enemy::takeDamage(int damage) {
    setHealth(getHealth() - damage);
    if(getHealth() <= 0) {
        cout<<getName()<<" has died"<<endl;
    }
    else {
        cout<<getName()<<" has taken " << damage << " damage" << endl;
    }
}

Character* Enemy::getTarget(vector<Player *> teamMembers) {
    // Obtiene el miembro del equipo con menos vida
    int targetIndex = 0;
    int lowestHealth = INT_MAX;
    for(int i=0; i < teamMembers.size(); i++) {
        if(teamMembers[i]->getHealth() < lowestHealth) {
            lowestHealth = teamMembers[i]->getHealth();
            targetIndex = i;
        }
    }

    return teamMembers[targetIndex];
}



void Enemy::enemyFlee(vector<Player*> player) {
    Player* fastestPlayer = player[0];
    bool fleed = false;
    if(this->getSpeed() > fastestPlayer->getSpeed()) {
        fleed =  true;
    }
    else {
        srand(time(NULL));
        int chance = rand() % 100;
        cout<< "chance: " << chance << endl;
        fleed = chance > 95;
    }
    if (fleed== true){
        cout<<"El "<<name<<" logró escapar"<< endl;
    }
    else{
        cout<<"El "<<name<<" logró escapar"<< endl;
    }

    this->fleed = fleed;
}

Action Enemy::takeAction(vector<Player *> player) {
    Action myAction;
    myAction.speed = getSpeed();
    myAction.subscriber = this;
    Character* target = getTarget(
            player);
    myAction.target = target;

        if (health <= maxHealth*0.15){
            myAction.action = [this,player](){
            enemyFlee(player);
            };
        }

        else {
            myAction.action = [this, target]()
        { doAttack(target);
        };
        }

    return myAction;
    }

