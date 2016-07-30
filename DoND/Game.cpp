#include "Game.h"

/* This function will make sure that 26 cases are generated for the game. 
   They will be generated sequentially and each receive a random value based off
   the values remaining. 
*/
void Game::randomizeCases()
{
	Case* temp;
	int t = 26;
	for (int i = 0; i < caseRemaining; i++)
	{
		srand(time(NULL));
		int ran = rand() % t;
		temp = new Case(remaining[ran], i + 1);
		remaining.erase(remaining.begin() + ran);
		cases.push_back(temp);
		t--;
	}
}

/* This function will generate an offer to the player based on the cases chosen, and those still available.*/
int Game::generateOffer()
{
	return 0;
}


/*Constructor will initialize the game, gathering the players information and storing it into the player object*/
Game::Game() : caseRemaining(26), offer(0), status(PLAY), selection(0)
{
	remaining = std::vector<int>(values, values + sizeof(values) / sizeof(int));
	std::string nm;
	std::cout << "Please Enter Your Name: ";
	std::cin >> nm;
	player = new Player(nm);
	std::cout << "Thank You!" << std::endl;
}

/* This function will be used to display the remaining cases, X marks cases already chosen. */
void Game::display() const
{
	int count = 0;
	for (int i = 0; i < 4; i++)
	{
		if (i % 2 == 0)
		{
			for (int k = 0; k < 15; k++)
			{
				if (k % 2 == 0)
					std::cout << board[i][k];
				else
				{
					if (cases.at(count)->isSelected())
						std::cout << "XX";
					else
						std::cout << std::setw(2) << std::setfill('0') << cases.at(count)->getNum();
					count++;
				}
			}
		}
		else
		{
			std::cout << " ";
			for (int k = 0; k < 13; k++)
			{
				if (k % 2 == 0)
					std::cout << board[i][k];
				else
				{
					if (cases.at(count)->isSelected())
						std::cout << "XX";
					else
						std::cout << std::setw(2) << std::setfill('0') << cases.at(count)->getNum();
					count++;
				}
			}
		}
		std::cout << std::endl;
	}
}

Case* Game::chooseCase(int select)
{
	for (auto i : cases)
		if (i->getNum() == select)
		{
			if (!i->isSelected())
			{
				i->select();
				caseRemaining--;
				return i;
			}
		}
}

/*This function runs the game, and will stay in a game loop until status is set to OVER.*/
void Game::run()
{
	randomizeCases();
	int x;
	std::cout << "Please Select Your Case: ";
	std::cin >> selection;
	NEWLINE
	player->pickCase(chooseCase(selection));

	while (status == PLAY)
	{
		display();
		NEWLINE
		std::cout << "Type 1 To Exit: ";
		std::cin >> x;
		if (x == 1) status = OVER;
	}
}

