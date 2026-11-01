
#include "Livre.h"
#include "Bibliotheque.h"
#include "Date.h"
#include <iostream>
using namespace std;

int main()
{
    
    Date d1(1, 1, 2027);
    Date d2(15, 5, 2025);
    Date d3(20, 10, 2024);

    
    Livre L1("Black", "Jack Morso", d1, 5);
    Livre L2("Harry Potter", "J.K. Rowling", d2, 5);
    Livre L3("Le Petit Prince", "Antoine de Saint-Exupery", d3, 5);

    Bibliotheque B("Bibliotheque FSTM", nullptr, 0, 10);

    B.ajouterLivre(&L1);
    B.ajouterLivre(&L2);
    B.ajouterLivre(&L3);

    L1.ajouterNote(15);
    L1.ajouterNote(18);
    L1.ajouterNote(12);

    L2.ajouterNote(17);
    L2.ajouterNote(16);

    L3.ajouterNote(14);
    L3.ajouterNote(19);
    L3.ajouterNote(16);


    cout << "\n LIVRE 1 \n";
    L1.consultation();

    cout << "\n LIVRE 2 \n";
    L2.consultation();

    cout << "\n LIVRE 3\n";
    L3.consultation();

   
    cout << "\ RECHERCHE PAR ID\n";
    B.rechercher(L1.getid());

   
    cout << "\n RECHERCHE PAR TITRE\n";
    B.rechercher("Harry Potter");

    
    cout << "\n RECHERCHE INFRUCTUEUSE\n";
    B.rechercher("Livre inexistant");

    
    cout << "\nNombre de livres existants : "
        << Livre::getNbInstances() << endl;

    return 0;
}
