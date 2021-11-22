#include <iostream>
#include <windows.h>
#include <string>

void HUD();
void Combat();
void CombatHUD();
void Moving();
void CreateMonster();

std::string name = " ", race = " ", sex = " ";
int level = 0, xp = 0, health = 0, totalHealth = 0, maxHealth = 0, nextLevel = 0, heal = 0;
int monsterHp = 0, monsterXp = 0, monsterLevel = 0;

std::string monsterName[] = { "Goblin", "Dwarf", "Orge", "Witch", "Thief", "Wizard" };
int currentMonsterNames = 5;
std::string currentMonster = " ";

int main()
{

	level = 1;
	xp = 0;
	nextLevel = 50;
	health = 100;
	totalHealth = health;
	maxHealth = totalHealth;



	//Basic character creation
	std::cout << "Enter Characters Name: " << std::endl;
	std::cin >> name;

	std::cout << "Enter Characters Race:" << std::endl;
	std::cin >> race;

	std::cout << "Enter Characters Sex:" << std::endl;
	std::cin >> sex;

	//Creative creation
	std::cout << "Creating Character.\n";
	Sleep(200);
	system("cls");

	std::cout << "Creating Character.\n";
	Sleep(200);
	system("cls");

	std::cout << "Creating Character.\n";
	Sleep(200);
	system("cls");

	HUD();
	Moving();

	system("pause");

	return 0;

}

void HUD()
{
	Sleep(500);
	system("cls");
	std::cout << "Name: " << name << "		Health: " << totalHealth << "\nRace: " << race
		<< "\nSex: " << sex << "\nLevel: " << level << "\nXp: " << xp << "\nXp to Level: " << nextLevel << std::endl;

	Moving();
}

void CombatHUD() {
	Sleep(500);
	system("cls");
	std::cout << "Name: " << name << "			|		Monster Name: " << currentMonster << "\nHealth: " << totalHealth << "		|		Monster Health: " <<
		monsterHp << "\nLevel: " << level << "		|		Monster Level: " << monsterLevel << std::endl;
}

void Combat() {

	CombatHUD();

	int playerAttack;
	int playerDamage = 8 * level / 2 * rand() % 100 + 1;
	int monsterAttack = 6 * monsterLevel / 2 * rand() % 50 + 1;

	if (totalHealth >= 1 && monsterHp >= 1)
	{
		std::cout << "\n";
		std::cout << "1. Attack\n";
		std::cout << "2. Block\n";
		std::cout << "3. RUN\n";
		std::cout << "\n";
		std::cin >> playerAttack;

		if (playerAttack == 1)
		{
			//Attack
			std::cout << "Attacking... you did " << playerDamage << " to the " << currentMonster << std::endl;
			monsterHp = monsterHp - playerDamage;
			Sleep(1000);
			CombatHUD();
			if (monsterHp >= 1)
			{
				std::cout << "\n";
				std::cout << "Monster is attacking..\n";
				totalHealth = totalHealth - monsterAttack;
				std::cout << "You suffered " << monsterAttack << " hp " << totalHealth << std::endl;
				// Change to function.
				if (totalHealth <= 0)
				{
					totalHealth = 0;
				}
			}
			else if (monsterHp <= 0) {
				monsterHp = 0;
			}
			Sleep(1000);
			Combat();
		}
		else if (playerAttack == 2)
		{
			//Block
			std::cout << "Blocking\n";
			int i = rand() % 100 + 1;
			if (i >= 50) {
				std::cout << "You Blocked the incoming attack\n";
				heal = level * 10 / 2;
				std::cout << "You have been healed for " << heal << std::endl;
				Sleep(2000);
				Combat();
			}
			else {
				std::cout << "You failed to block the lethal attack!\n";
				totalHealth -= monsterAttack;
				std::cout << "You were stabbed in the back for " << monsterAttack << " current hp " << totalHealth << std::endl;
				Sleep(2000);
				Combat();
			}
		}
		else if (playerAttack == 3)
		{
			//Run
			std::cout << "You try to run\n";
			int x = rand() % 100 + 1;
			if (x >= 50)
			{
				std::cout << "You run away\n";
				HUD();
			}
			else {
				std::cout << "you failed to run away\n";
				std::cout << "Monster drags you back as you SCREAM!\n";
				totalHealth -= monsterAttack = 10;
				std::cout << "You suffered  " << monsterAttack + 10 << "Your current Health is " << totalHealth << std::endl;
				Sleep(2000);
				Combat();
			}
		}
		else
		{
			std::cout << "Invalid Number\n";
			Sleep(500);
			Combat();
		}
	}
}

void Moving()
{
	int choice; 

	std::cout << "\n\n";
	std::cout << "1. Move Forward\n" << std::endl;
	std::cout << "2. Relax\n" << std::endl;
	std::cout << "3. Move Backwards\n" << std::endl;
	std::cout << "\n" << std::endl;

	std::cin >> choice;

	if (choice == 1)
	{
		int temp = rand() % 100 + 1; //pick a number between 100 and Mod divides by 50
		std::cout << "You begin moving forward...\n" << std::endl;
		if (temp >= 50) {
			//Encounter a monster
			CreateMonster();
			std::string tempName = monsterName[rand() % currentMonsterNames];
			std::cout << "A " << tempName << "| Prepare to FIGHT! |\n";
			currentMonster = tempName;
			Sleep(1000);
			Combat();
		}
		std::cout << "You find nothing of interest\n";
		Sleep(1000);
		HUD();
		
	}
	else if (choice == 2)
	{
		std::cout << "You want to set up camp for the evening\n" << std::endl;
		if (totalHealth <=99) 
		{
			totalHealth += 10 * level;
		}
		std::cout << "You healed by resting. Health is now" << totalHealth << std::endl;
		Sleep(1000);
		HUD();
	}
	else if (choice == 3)
	{
		int temp = rand() % 100 + 1; //pick a number between 100 and Mod divides by 50
		std::cout << "You begin moving backwards...\n" << std::endl;
		if (temp >= 50) {
			//Encounter a monster
			CreateMonster();
			std::string tempName = monsterName[rand() % currentMonsterNames];
			std::cout << "A " << tempName << "| Prepare to FIGHT! |\n";
			currentMonster = tempName;
			Sleep(1000);
			Combat();
		}
		std::cout << "You find nothing of interest\n";
		Sleep(1000);
		HUD();
	}
	else {
		std::cout << "Invalid Number\n";
		Sleep(500);
		Moving();
	}

}

void CreateMonster()
{
	monsterHp = 30;
	monsterLevel = (rand() % 3) + level;

	//if (monsterLevel == 0) {
	//	monsterLevel = (rand() % 3) + level;
	//}

	//May need to fix this value.
	monsterHp = (rand() % 10) * totalHealth;

	//if (monsterHp == 0) {
	//	monsterHp = (rand() % 30) * monsterLevel;
	//}
	
	monsterXp = monsterHp;

	if (monsterHp == 0)
		CreateMonster();
	if (monsterLevel == 0)
		CreateMonster();
}