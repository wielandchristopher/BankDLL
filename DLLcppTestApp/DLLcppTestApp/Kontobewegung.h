#ifndef KONTOBEWEGUNG_H
#define KONTOBEWEGUNG_H
#include "stdafx.h"
#include "Kontoverwaltung.h"

class Kontobewegung
{
public:
	Kontobewegung(bool abheben, char *verwendungszweck, double betrag, Kontoverwaltung *kontoverwaltung);
	double abhebenOderEinzahlen(bool abheben, double betrag, Kontoverwaltung *kontoverwaltung);
	void showBewegung(Kontoverwaltung *kontoverwaltung);
	char *getDatum();
	double getBetrag();
	char *getVerwendungszweck();

private:
	void setDatum();		// Gemeinsam nutzen -> vlt in Kontoverwaltung und als Parameter mitgeben

	char *datum;
	char *verwendungszweck;
	double betrag;

	// wenn abheben true = ABHEBEN, wenn false = EINZAHLEN
	bool abheben;
};

#endif