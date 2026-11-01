#pragma once
class Date
{
	int jour;
	int mois;
	int annee;
public:
	Date();
	Date(int, int, int);
	static bool estBissextile(int a);
	static  bool estValide(int j, int m, int a);
	void afficher() const;
	bool operator==(const Date& D) const;
	bool operator<(const Date& D) const;

};

