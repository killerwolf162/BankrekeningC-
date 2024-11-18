#pragma once
#include <string>
#include <list>

class Transactie
{

public:

	Transactie(int hoeveelheid, int dag, int maand, int jaar);
	~Transactie();
	std::string GetType();
	int GetAmount() const;
	std::list<int> GetDatum();

	std::string type;

private:

	std::list<int> datum;
	int amount = 0;
	int day = 0;
	int month = 0;
	int year = 0;
};

