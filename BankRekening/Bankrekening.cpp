#include "Bankrekening.h"
#include <iostream>

Bankrekening::Bankrekening(int saldo, std::list<Transactie> transactionList)
{
	this->saldo = saldo;
	this->transactionList = transactionList;
}

Bankrekening::~Bankrekening()
{
}

Bankrekening::Bankrekening(const Bankrekening& other)
{
}

std::list<Transactie> Bankrekening::AddTransactionToList(Transactie& transactie) // data in transactie wordt nu niet meegenomen binnen de lijst
{
	std::cout << "Amount before added to list: " << transactie.GetAmount() << std::endl;
	transactionList.push_back(transactie);
	std::cout << "Amount after added to list: " << transactionList.front().GetAmount() << std::endl;
	return transactionList;
}

int Bankrekening::GetSaldo()
{
	return saldo;
}

std::list<Transactie> Bankrekening::GetTransactionList()
{
	return transactionList;
}

Bankrekening Bankrekening::operator+(Transactie& transactie) 
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
		<< "amount of transactions: " << account.transactionList.size()
		<< std::endl;

	for (int i = 0; i < account.transactionList.size(); i++)
	{
		os << "Soort: " << account.transactionList.front().GetType() << " , "
			<< "Hoeveelheid: " << account.transactionList.front().GetAmount() << " , "
			<< "datum: ";
			for (int date : account.transactionList.front().GetDatum() )
			{
				os << date << "/";
			}
			os << std::endl;
	}


		return os;
}
