#pragma once
#include"Livre.h"
#include<stdio.h>
#include<iostream>
#include"Date.h"
using namespace std;
class Bibliotheque
{
	string nom;
	Livre ** livres;
	int nbLivres;
	int capacitemax;
	static int nbBibliotheques;
public:
	Bibliotheque(string, Livre**, int,int);
	Bibliotheque(const Bibliotheque&);
	Bibliotheque operator=(const Bibliotheque&);
	~Bibliotheque();
	Livre& ajouterLivre(Livre*);
	Bibliotheque& operator+=(const Livre& L);
	void rechercher( int v);
	void rechercher( string v);
};

