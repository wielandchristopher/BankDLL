#ifndef UEBERWEISUNG_H
#define UEBERWEISUNG_H
#include <iostream>
#include "Kontoverwaltung.h"
#include <list>

class Ueberweisung
{
public:
	Ueberweisung(char *verwendungszweck, double betrag, int kontonummer, char *empfaengername, Kontoverwaltung *kontoverwaltung);

	Ueberweisung();
	void showUeberweisung();
	string getDatum() {

		return datum;
	}
	char *getVerwendungszweck();
	double getBetrag();

private:
	void setDatum();

	string datum;
	double betrag;
	int kontonummer;
	char* empfaengername;
	char* verwendungszweck;
};

#endif