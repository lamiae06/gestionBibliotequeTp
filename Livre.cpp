#include "Livre.h"
int Livre::compteurid = 0;
int Livre::nbinstances = 0;
Livre::Livre(string t, string a, Date p, int n)
	:id(compteurid + 1)
{
	this->titre = t;
	this->auteur = a;
	this->parution = p;
	this->nbNotes = 0;
	this->capaciteNotes = n;
	this->disponible = true;
	if (capaciteNotes > 0) {
		notes = new int[capaciteNotes];
	}
	else{
		notes = nullptr;
}
	compteurid++;
	nbinstances++;
}

Livre::Livre(const Livre&L):id(compteurid + 1)
{
	this->titre = L.titre;
	this->auteur = L.auteur;
	this->parution =L.parution;
	this->nbNotes = L.nbNotes;
	this->capaciteNotes = L.capaciteNotes;
	this->disponible = L.disponible;
	if (capaciteNotes > 0)
	{
		this->notes = new int[capaciteNotes];

		for (int i = 0; i < nbNotes; i++)
		{
			this->notes[i] = L.notes[i];
		}
	}
	else
	{
		this->notes = nullptr;
	}
	compteurid++;
	nbinstances++;
}

Livre Livre::operator=(const Livre&L)
{
	int* nouveau = nullptr;
	this->titre = L.titre;
	this->auteur = L.auteur;
	this->parution = L.parution;
	if (L.capaciteNotes > 0)
	{
		nouveau = new int[L.capaciteNotes];

		for (int i = 0; i < L.nbNotes; i++)
		{
			nouveau[i] = L.notes[i];
		}
	}
	delete[] notes;

	notes = nouveau;
	nbNotes = L.nbNotes;
	capaciteNotes = L.capaciteNotes;
	disponible = L.disponible;
	return *this;
}

Livre::~Livre()
{
	delete[] notes;
	notes = nullptr;

	nbinstances--;
}

bool Livre::ajouterNote(int note)
{
	if (note < 0 || note > 20) {
		cout << "Note invalide : elle doit etre entre 0 et 20."
			<< endl;
		return false;
	}
	if (nbNotes >= capaciteNotes) {
		cout << "Capacite de notes atteinte." << endl;
		return false;
	}
	notes[nbNotes] = note;
	nbNotes++;

	return true;
}

double Livre::moyenne() const
{
	double somme = 0;
	if (nbNotes == 0) return 0;
	for (int i = 0;i < nbNotes;i++) {
		somme += notes[i];
	}

	return somme/nbNotes;
}

void Livre::consultation() const
{
	cout << "ID : " << id << endl;
	cout << "Titre : " << titre << endl;
	cout << "Auteur : " << auteur << endl;

	parution.afficher();

	cout << "Notes : ";

	for (int i = 0; i < nbNotes; i++) {
		cout << notes[i] << " ";
	}

	cout << "\nMoyenne : " << moyenne() << endl;
}
int Livre::getNbInstances()
{
	return nbinstances;
}
int Livre::getid() const {
	return id;
}
string Livre::gettitre() const {
	return titre;
}
string Livre::getauteur() const {
	return auteur;
}
Date Livre::getdate() const {
	return parution;
}











