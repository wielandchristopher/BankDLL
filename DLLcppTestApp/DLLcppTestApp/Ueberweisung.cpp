#include "Ueberweisung.h"
#include "Kontoverwaltung.h"
#include "stdafx.h"
#include <time.h>

using namespace std;


Ueberweisung::Ueberweisung(char *verwendungszweck, double betrag, int kontonummer, char *empfaengername, Kontoverwaltung *kontoverwaltung)
{
	this->verwendungszweck = verwendungszweck;
	this->betrag = betrag;
	this->kontonummer = kontonummer;
	this->empfaengername = empfaengername;
	// this->datum = this->setDatum();				// TODO: Problem bei Übergabe (in showUeberweisung)
	this->setDatum();
	//kontoverwaltung.setKontostand -= betrag;
	double newKontostand = kontoverwaltung->getKontostand() - betrag;
	kontoverwaltung->setKontostand(newKontostand);
}

char *Ueberweisung::getDatum()
{
	return datum;
}

char *Ueberweisung::getVerwendungszweck()
{
	return verwendungszweck;
}

double Ueberweisung::getBetrag()
{
	return betrag;
}

// PRIVATE
void Ueberweisung::setDatum()
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
	// return timebuf;
}

void Ueberweisung::showUeberweisung()
{
	// Daweil nur mit cout -> vlt umschreiben
	cout << "An Kontonummer: " << this->kontonummer << endl;
	cout << "Verwendungszweck: " << this->verwendungszweck << endl;
	cout << "Betrag: " << this->betrag << endl;
	cout << "Empfaengername: " << this->empfaengername << endl;
	//cout << "Datum: " << this->datum << endl;
	cout << "Datum: " << this->datum << endl;
}