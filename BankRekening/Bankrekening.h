#pragma once
#include "Transactie.h"
#include <ostream>
#include <list>

class Bankrekening
{

public:
	Bankrekening(int saldo, std::list<Transactie> transactieLijst);
	virtual ~Bankrekening();
	Bankrekening(const Bankrekening& other);

	int GetSaldo();
	std::list<Transactie> AddTransactionToList(Transactie& transactie);
	std::list<Transactie> GetTransactieList();

	Bankrekening operator+(Transactie& transactie);
	Bankrekening operator-(Transactie& transactie) ;

	friend std::ostream& operator<<(std::ostream& os, Bankrekening& bankrekening);

private:
	int saldo = 0;
	std::list<Transactie> transactieList;

};

