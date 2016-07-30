#pragma once
#include <string>

class Case
{
	int value;
	int num;
	bool selected;
public:
	Case() : value(0), num(0), selected(false){}
	Case(int val, int nm) : value(val), num(nm), selected(false) {}
	~Case(){}
	void setValue(int val) { value = val; }
	void setNum(int nm) { num = nm; }
	int getValue() const { return value; }
	int getNum() const { return num; }
	void select() { selected = true; }
	bool isSelected() { return selected; }
	friend std::ostream& operator<<(std::ostream& ostr, const Case& cas);
};
std::ostream& operator<<(std::ostream& ostr, const Case& cas);
