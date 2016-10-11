#ifndef UEBERWEISUNG_H
#define UEBERWEISUNG_H
#include <iostream>
#include "Kontoverwaltung.h"
#include <list>

class Ueberweisung
{
public:
	Ueberweisung(char *verwendungszweck, double betrag, int kontonummer, char *empfaengername, Kontoverwaltung *kontoverwaltung);

	void showUeberweisung();
	char *getDatum();
	char *getVerwendungszweck();
	double getBetrag();

private:
	void setDatum();

	char* datum;
	double betrag;
	int kontonummer;
	char* empfaengername;
	char* verwendungszweck;
};

#endif