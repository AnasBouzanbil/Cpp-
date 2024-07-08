#include "ScavTrap.hpp"

int main()
{
    {
        std::cout << "---------------------" << std::endl;
        ScavTrap enemy("Enemy");
        ScavTrap player("Player");
        ScavTrap copy(player);
        copy.attack("Enemy");
        enemy.takeDamage(20);
        enemy.beRepaired(20);
        enemy.attack("Player");
        enemy.guardGate();
        player.attack("Enemy");
        enemy.takeDamage('l');
        enemy.beRepaired(20);
        enemy.attack("Player");
        enemy.guardGate();
    }
    {
        std::cout << "---------------------" << std::endl;
        ClapTrap player1("Player");
        ScavTrap enemy("Enemy");
        ClapTrap player1friend = player1;
        ScavTrap enemyfriend;
        std::cout << "---------------------" << std::endl;
        enemy.attack("Player");
        player1.takeDamage(20);
        player1.attack("Enemy");
        enemy.takeDamage(0);
        enemyfriend = enemy;
        enemyfriend.attack("Player");
        player1.takeDamage(20);
        player1.attack("Enemy");
        player1friend.attack("Enemy");
        enemy.takeDamage(0);
        enemyfriend.attack("player1friend");
        player1friend.takeDamage(20);
        player1friend.attack("Enemy");
        std::cout << "---------------------" << std::endl;
    }

} 