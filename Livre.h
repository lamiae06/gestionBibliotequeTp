#pragma once
#include<stdio.h>
#include "Date.h"
#include<iostream>
using namespace std;
class Livre
{
	const int id;
	string titre;
	string auteur;
	Date parution;
	int* notes;
	int nbNotes;
	int capaciteNotes;
	bool disponible;
	static int compteurid;
	static int nbinstances;
public:
	Livre(string, string, Date , int );
	Livre(const Livre&);
	Livre operator=(const Livre&);
	~Livre();
	bool ajouterNote(int);
	double moyenne() const;
	void consultation() const;
	static int getNbInstances();
	int getid() const;
	string gettitre() const;
	string getauteur() const;
	Date getdate() const;
};
