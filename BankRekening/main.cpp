#include <iostream>
#include "Transactie.h"
#include "Bankrekening.h"

using namespace std;

int main()
{

	std::list<Transactie> transactieLijst;
	Bankrekening account(1000, transactieLijst);

	Transactie transaction1 = Transactie(1000, 19, 7, 2001);
	Transactie transaction2 = Transactie(700, 12, 3, 2003);
	Transactie transaction3 = Transactie(150, 23, 5, 2005);
	Transactie transaction4 = Transactie(300, 8, 9, 2009);

	account = account + transaction1;
	account = account - transaction2;
	account = account + transaction3;
	account = account - transaction4;

	cout << account << std::endl;
}