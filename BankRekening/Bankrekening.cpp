#include "Bankrekening.h"
#include <iostream>

Bankrekening::Bankrekening(int saldo, std::list<Transactie> transactieList)
{
	this->saldo = saldo;
	this->transactieList = transactieList;
}

Bankrekening::~Bankrekening()
{
}

Bankrekening::Bankrekening(const Bankrekening& other)
{
}

std::list<Transactie> Bankrekening::AddTransactionToList(Transactie& transactie)
{
	transactieList.push_back(transactie);
	return transactieList;
}

int Bankrekening::GetSaldo()
{
	return saldo;
}

std::list<Transactie> Bankrekening::GetTransactieList()
{
	return transactieList;
}

Bankrekening Bankrekening::operator+(Transactie& transactie) // data in transactie wordt nu niet meegenomen binnen de lijst
{
	transactie.type = "Bijschrift";
	return Bankrekening(saldo + transactie.GetAmount(), AddTransactionToList(transactie));
}

Bankrekening Bankrekening::operator-(Transactie& transactie)
{
	transactie.type = "Afschrift";
	return Bankrekening(saldo - transactie.GetAmount(), AddTransactionToList(transactie));
}

std::ostream& operator<<(std::ostream& os, Bankrekening& account) 
{
	os << "saldo: " << account.GetSaldo()
		<< " , "
		<< "amount of transactions: " << account.transactieList.size()
		<< std::endl;

	for (int i = 0; i < account.transactieList.size(); i++)
	{
		os << "Soort: " << account.transactieList.front().GetType() << " , "
			<< "Hoeveelheid: " << account.transactieList.front().GetAmount() << " , "
			<< "datum: ";
			for (int date : account.transactieList.front().GetDatum() )
			{
				os << date << "/";
			}
			os << std::endl;
	}


		return os;
}
