#pragma once

#define LOG(l) std::cout << "LOG: " << l << std::endl;
#define NEWLINE std::cout<<std::endl;

static const int values[26] = { 0, 1, 5, 10, 25, 50, 75, 100, 200, 300, 400, 500, 750, 1000, 5000, 10000,
25000, 50000, 75000, 100000, 200000, 300000, 400000, 500000, 750000, 1000000 };

static char board[4][15] = { 
	{ '|', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-',  '|' },
	{ '|', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '|' },
	{ '|', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '|' },
	{ '|', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '|' } };

enum Status {PLAY, OVER};

#include "Player.h"
#include "Case.h"
#include "time.h"
#include <vector>
#include <string>
#include <iostream>
#include <iomanip>

class Game
{
	std::vector<Case*> cases;
	std::vector<int> remaining;
	Player* player;
	Status status;
	int caseRemaining;
	int offer;
	int selection;
public:
	Game();
	~Game()
	{
		for (auto i : cases) delete i;
		delete player;
	}
	int select(int choice);
	int generateOffer();
	Case* chooseCase(int);
	void randomizeCases();
	void run();
	void display() const;
};
