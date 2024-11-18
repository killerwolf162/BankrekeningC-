#include "Transactie.h"

Transactie::Transactie(int amount, int day, int month, int year)
{
	this->type = type;
	this->amount = amount;
	this->day = day;
	this->month = month;
	this->year = year;
	datum = { day, month, year };
}

Transactie::~Transactie()
{
}

std::string Transactie::GetType()
{
	return type;
}

int Transactie::GetAmount() const
{
	return amount;
}

std::list<int> Transactie::GetDatum()
{
	return datum;
}