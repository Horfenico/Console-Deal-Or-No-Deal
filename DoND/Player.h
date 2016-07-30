#pragma once
#include <string>
#include "Case.h"
class Player
{
	std::string name;
	Case* playerCase;
	int currentOffer;
	bool deal;
public:
	Player() : name(""), currentOffer(0), deal(false) { playerCase = new Case(); }
	Player(std::string nm) : name(nm), currentOffer(0), deal(0){}
	~Player(){ }
	void setOffer(int off) { currentOffer = off; }
	void pickCase(Case* select) { playerCase = select; }
	Case* getCase() { return playerCase; }
	void setDeal(bool dl) { deal = dl; }
	bool getDeal() { return deal; }

};