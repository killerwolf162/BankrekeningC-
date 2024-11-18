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

std::list<Transactie> Bankrekening::AddTransactionToList(Transactie& transactie)
{
	transactionList.push_back(transactie);
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
	int listStartSize = account.transactionList.size();

	for (int i = 0; i < listStartSize; i++)
	{
		os << "Soort: " << account.transactionList.front().GetType() << " , "
			<< "Hoeveelheid: " << account.transactionList.front().GetAmount() << " , "
			<< "datum: ";
			for (int date : account.transactionList.front().GetDatum() )
			{
				os << date << "/";
			}
			os << std::endl;
			account.transactionList.pop_front();
	}

	os << "eind saldo: " << account.GetSaldo()
		<< " , "
		<< "amount of transactions: " << listStartSize
		<< std::endl;


		return os;
}
