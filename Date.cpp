#include "Date.h"
#include<stdio.h>
#include<iostream>
using namespace std;
Date::Date()
	: jour(1), mois(1), annee(2000)
{
}
Date::Date(int j, int m, int a)
{
	if (estValide(j, m, a))
	{
		jour = j;
		mois = m;
		annee = a;
	}
	else
	{
		cout << "Date invalide. Remplacement par 01/01/2000."
			<< endl;

		jour = 1;
		mois = 1;
		annee = 2000;
	}
}

bool Date::estBissextile(int a)
{
	return (a % 4 == 0 && a % 100 != 0)
		|| (a % 400 == 0);
}

bool Date::estValide(int j, int m, int a)
{
	if (a < 1 || m < 1 || m > 12 || j < 1)
	{
		return false;
	}
	int tab[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if (estBissextile(a)) {
		tab[1] = 29;
	}
	if (j > tab[m - 1])
	{
		return false;
	}

	return true;
	
}

void Date::afficher() const
{
	cout << jour << "/" << mois << "/" << annee << endl;
}

bool Date::operator==(const Date& D) const
{
	return jour == D.jour
		&& mois == D.mois
		&& annee == D.annee;
}


bool Date::operator<(const Date& D) const
{
	if (annee != D.annee)
		return annee < D.annee;

	if (mois != D.mois)
		return mois < D.mois;

	return jour < D.jour;
}










