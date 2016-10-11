#include <iostream>
#include "stdafx.h"
#include <string.h>
#include "Kontoverwaltung.h"
#include "Ueberweisung.h"
#include "Kontobewegung.h"
#include "Kontoauszug.h"
#include <list>

using namespace std;

Kontoverwaltung::Kontoverwaltung(int kontonummer, double kontostand)
{
	this->setKontonummer(kontonummer);
	this->setKontostand(kontostand);
}
 
// Getter
double Kontoverwaltung::getKontostand()
{
	return Kontostand;
}
	
int Kontoverwaltung::getKontonummer()
{
	return Kontonummer;
}

// Setter
void Kontoverwaltung::setKontostand(double kontostand)
{
	this->Kontostand = kontostand;
}

void Kontoverwaltung::setKontonummer(int kontonummer)
{
	this->Kontonummer = kontonummer;
}

// Funktionen
// Um cin zu Umgehen -> Parameter mitgeben (Wenn nur funktionen erwünscht wären)
// Exit bedingung -> sonst fortlaufend
void Kontoverwaltung::startVerwaltung()
{
	int verwaltungsMoeglichkeit;
	bool exit = true;
	double betrag;
	int kontonummer;
	char empfaengername[30];
	char verwendungszweck[50];
	
	list<Ueberweisung> ueberweisungsListe;
	list<Kontobewegung> kontobewegungsListe;

	while (exit)
	{
		cout << "Nummer 1: Ueberweisung / Nummer 2: Abheben / Nummer 3: Einzahlen / Nummer 4: Exit" << endl;
		cin >> verwaltungsMoeglichkeit;
		cin.ignore();

		// Ueberweisung
		if (verwaltungsMoeglichkeit == 1)
		{
			cout << "Empfaengername eingeben: " << endl;
			cin.getline(empfaengername, 30);
			cout << "Kontonummer eingeben: " << endl;
			cin >> kontonummer;
			cin.ignore();				// Sonst wird cin.getline() übersprungen
			cout << "Verwendungszweck eingeben: " << endl;
			cin.getline(verwendungszweck, 50);
			cout << "Betrag eingeben: " << endl;
			cin >> betrag;
			cin.ignore();

			Ueberweisung ueberweisung = Ueberweisung(verwendungszweck, betrag, kontonummer, empfaengername, this);
			ueberweisung.showUeberweisung();
			

			//kontoauszugsBetrag[0] = '-';
			//_itoa_s(betrag, kontoauszugsBetrag, 10);
			// - davor setzen

			//kontoauszugsBetrag = "-" + (char)betrag;

			// In Kontoauszug addToList

			ueberweisungsListe.push_back(ueberweisung);
		}
		// Abheben
		else if (verwaltungsMoeglichkeit == 2)
		{	
			cout << "Verwendungszweck eingeben: " << endl;
			cin.getline(verwendungszweck, 50);
			cout << "Betrag eingeben: " << endl;
			cin >> betrag;
			cin.ignore();

			// bool abheben, char *verwendungszweck, int betrag, Kontoverwaltung *kontoverwaltung
			Kontobewegung kontobewegung = Kontobewegung(true, verwendungszweck, betrag, this);
			kontobewegung.showBewegung(this);

			kontobewegungsListe.push_back(kontobewegung);
		}
		// Einzahlen
		else if (verwaltungsMoeglichkeit == 3)
		{
			cout << "Verwendungszweck eingeben: " << endl;
			cin.getline(verwendungszweck, 50);
			cout << "Betrag eingeben: " << endl;
			cin >> betrag;
			cin.ignore();

			// bool abheben, char *verwendungszweck, int betrag, Kontoverwaltung *kontoverwaltung
			Kontobewegung kontobewegung = Kontobewegung(false, verwendungszweck, betrag, this);
			kontobewegung.showBewegung(this);

			kontobewegungsListe.push_back(kontobewegung);
		}
		// Kontoauszug
		else if (verwaltungsMoeglichkeit == 4)
		{
			// cout << "LISTE:" << endl;
			Kontoauszug kontoauszug = Kontoauszug(ueberweisungsListe, kontobewegungsListe);
		}
		else
		{
			exit = false;
		}
	}
}