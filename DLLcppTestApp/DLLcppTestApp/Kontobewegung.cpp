#include "stdafx.h"
#include <iostream>
#include "Kontobewegung.h"
#include <time.h>
#include "Kontoverwaltung.h"

using namespace std;

Kontobewegung::Kontobewegung(bool abheben, char *verwendungszweck, double betrag, Kontoverwaltung *kontoverwaltung)
{
	this->verwendungszweck = verwendungszweck;
	this->betrag = abhebenOderEinzahlen(abheben, betrag, kontoverwaltung);
	this->setDatum();
}

double Kontobewegung::abhebenOderEinzahlen(bool abheben, double betrag, Kontoverwaltung *kontoverwaltung)
{
	if (abheben == true)
	{
		// Abheben -> gleich abziehen 
		// TODO: Betrag für Kontoauszug
		double newKontostand = kontoverwaltung->getKontostand() - betrag;
		kontoverwaltung->setKontostand(newKontostand);

		return betrag;
	}
	else
	{
		// Einzahlen
		// TODO wie oben
		double newKontostand = kontoverwaltung->getKontostand() + betrag;
		kontoverwaltung->setKontostand(newKontostand);

		return betrag;
	}
}

char *Kontobewegung::getDatum()
{
	return datum;
}

char *Kontobewegung::getVerwendungszweck()
{
	return verwendungszweck;
}

double Kontobewegung::getBetrag()
{
	return betrag;
}

void Kontobewegung::setDatum()
{
	struct tm newtime;
	__time64_t long_time;
	char timebuf[26];
	errno_t err;

	// Get time as 64-bit integer.
	_time64(&long_time);

	// Convert to local time.
	err = _localtime64_s(&newtime, &long_time);
	if (err)
	{
		printf("Invalid argument to _localtime64_s.");
		exit(1);
	}

	// Convert to an ASCII representation. 
	err = asctime_s(timebuf, 26, &newtime);
	if (err)
	{
		printf("Invalid argument to asctime_s.");
		exit(1);
	}

	// Darstellung ändern (dd.mm.yyyy hh.mm.ss)
	strftime(timebuf, sizeof(timebuf), "%d %m %Y %H:%M:%S", &newtime);
	cout << "TIME TEST: " << timebuf << endl;

	this->datum = timebuf;
}

void Kontobewegung::showBewegung(Kontoverwaltung *kontoverwaltung)
{
	// Daweil nur mit cout -> vlt umschreiben
	cout << "Eigene Kontonummer: " << kontoverwaltung->getKontonummer() << endl;
	cout << "Verwendungszweck: " << this->verwendungszweck << endl;
	cout << "Betrag: " << this->betrag << endl;
	cout << "Datum: " << this->datum << endl;
}