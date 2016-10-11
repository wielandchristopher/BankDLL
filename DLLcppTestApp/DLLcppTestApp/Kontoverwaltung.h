#ifndef KONTOVERWALTUNG_H
#define KONTOVERWALTUNG_H
#include <iostream>

using namespace std;

class Kontoverwaltung
{
public:
	Kontoverwaltung(int kontonummer, double kontostand);

	double getKontostand();
	int getKontonummer();
	void setKontostand(double kontostand);
	void setKontonummer(int kontonummer);
	void startVerwaltung();

private:
	double Kontostand;
	int Kontonummer;
};

#endif