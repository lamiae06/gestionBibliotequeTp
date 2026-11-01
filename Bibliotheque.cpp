#include "Bibliotheque.h"

int Bibliotheque::nbBibliotheques = 0;
Bibliotheque::Bibliotheque(string n, Livre**, int nb,int c)
{
	this->nom = n;
	this->nbLivres = nb;
	this->capacitemax = c;
	this->livres = new Livre*[capacitemax];
	nbBibliotheques++;


}

Bibliotheque::Bibliotheque(const Bibliotheque&B)
{
	this->nom = B.nom;
	this->nbLivres = B.nbLivres;
	this->capacitemax = B.capacitemax;
	this->livres = new Livre * [B.capacitemax];
	for (int i = 0;i < nbLivres;i++) {
		livres[i] = (B.livres[i]);
	}
	nbBibliotheques++;
}

Bibliotheque Bibliotheque::operator=(const Bibliotheque&B)
{
	this->nom = B.nom;
	this->nbLivres = B.nbLivres;
	this->capacitemax = B.capacitemax;
	Livre ** nouveau;
	nouveau = new Livre * [B.capacitemax];
	for (int i = 0;i < nbLivres;i++) {
		nouveau[i] = (B.livres[i]);
	}
	delete[]livres;
	livres = nouveau;
	nbLivres = B.nbLivres;

	return *this;
}

Bibliotheque::~Bibliotheque()
{
	delete[]livres;
	livres = nullptr;
}

Livre& Bibliotheque::ajouterLivre(Livre* L)
{
	if (nbLivres < capacitemax) {
		livres[nbLivres] = L;
		nbLivres++;
	}
	return *L;
}
Bibliotheque& Bibliotheque::operator+=(const Livre& L)
{
	if (nbLivres < capacitemax)
	{
		livres[nbLivres] = new Livre(L);
		nbLivres++;
	}

	return *this;
}

void Bibliotheque::rechercher(int v)
{
	for (int i = 0; i < nbLivres; i++) {
		if (livres[i]->getid() == v) {
			livres[i]->consultation();
			return;
		}
	}
	cout << "Livre introuvable." << endl;
}

void Bibliotheque::rechercher(string v)
{
	for (int i = 0; i < nbLivres; i++) {
		if (livres[i]->gettitre() == v) {
			livres[i]->consultation();
			return;
		}
	}
	cout << "Livre introuvable." << endl;
}
