// Customer.cpp : Defines the exported functions for the DLL application.
// Compile by using: cl /EHsc /DCUSTOMER_EXPORTS /LD Customer.cpp

#include "stdafx.h"
#include "Customer.h"
#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

class CUSTOMER {
public:

	string CUSTOMER::getVorname() {
		return Vorname;
	}
	void CUSTOMER::setVorname(string _Vorname) {
		this->Vorname = _Vorname;
	}

	string CUSTOMER::getNachname() {
		return Nachname;
	}
	void CUSTOMER::setNachname(string _Nachname) {
		this->Nachname = _Nachname;
	}

	string CUSTOMER::getGeburtsdatum() {
		return Geburtsdatum;
	}
	void CUSTOMER::setGeburtsdatum(string _Geburtsdatum) {
		this->Geburtsdatum = _Geburtsdatum;
	}

	string CUSTOMER::getWohnort() {
		return Wohnort;
	}
	void CUSTOMER::setWohnort(string _Wohnort) {
		this->Wohnort = _Wohnort;
	}

	string CUSTOMER::getadresse() {
		return adresse;
	}
	void CUSTOMER::setadresse(string _adresse) {
		this->adresse = _adresse;
	}

	string CUSTOMER::gethausnummer() {
		return hausnummer;
	}
	void CUSTOMER::sethausnummer(string _hausnummer) {
		this->hausnummer = _hausnummer;
	}

	string CUSTOMER::getPostleitzahl() {
		return Postleitzahl;
	}
	void CUSTOMER::setPostleitzahl(string _Postleitzahl) {
		this->Postleitzahl = _Postleitzahl;
	}

	string CUSTOMER::getTelefon() {
		return Telefon;
	}
	void CUSTOMER::setTelefon(string _Telefon) {
		this->Telefon = _Telefon;
	}

private:
	string Vorname;
	string Nachname;
	string Geburtsdatum;
	string adresse;
	string hausnummer;
	string Postleitzahl;
	string Wohnort;
	string Telefon;
};
class SparKonto {
public:
	CUSTOMER SparKonto::getVerf�ger() {
		return *Kontoverf�ger;
	}
	void SparKonto::setVerf�ger(CUSTOMER* _Kontoverf�ger) {
		this->Kontoverf�ger = _Kontoverf�ger;
	}
	CUSTOMER SparKonto::getoptVerf�ger1() {
		return *optKontoverf�ger1;
	}
	void SparKonto::setoptVerf�ger1(CUSTOMER* _optKontoverf�ger) {
		this->optKontoverf�ger1 = _optKontoverf�ger;
	}
	CUSTOMER SparKonto::getoptVerf�ger2() {
		return *optKontoverf�ger2;
	}
	void SparKonto::setoptVerf�ger2(CUSTOMER* _optKontoverf�ger) {
		this->optKontoverf�ger2 = _optKontoverf�ger;
	}
	CUSTOMER SparKonto::getoptVerf�ger3() {
		return *optKontoverf�ger3;
	}
	void SparKonto::setoptVerf�ger3(CUSTOMER* _optKontoverf�ger) {
		this->optKontoverf�ger3 = _optKontoverf�ger;
	}

	double SparKonto::getKontostand() {
		return Kontostand;
	}
	void SparKonto::setKontostand(double _Kontostand) {
		this->Kontostand = _Kontostand;
	}
	double SparKonto::getKontonummer() {
		return Kontonummer;
	}
	void SparKonto::setKontonummer(double _Kontonummer) {
		this->Kontonummer = _Kontonummer;
	}
	
	SparKonto();

private:
	int Kontonummer;
	double Kontostand = 0;
	CUSTOMER* Kontoverf�ger;
	CUSTOMER* optKontoverf�ger1;
	CUSTOMER* optKontoverf�ger2;
	CUSTOMER* optKontoverf�ger3;
};
class KreditKonto{
public:
	CUSTOMER KreditKonto::getVerf�ger() {
		return *Kontoverf�ger;
	}
	void KreditKonto::setVerf�ger(CUSTOMER* _Kontoverf�ger) {
		this->Kontoverf�ger = _Kontoverf�ger;
	}
	CUSTOMER KreditKonto::getoptVerf�ger1() {
		return *optKontoverf�ger1;
	}
	void KreditKonto::setoptVerf�ger1(CUSTOMER* _optKontoverf�ger) {
		this->optKontoverf�ger1 = _optKontoverf�ger;
	}
	CUSTOMER KreditKonto::getoptVerf�ger2() {
		return *optKontoverf�ger2;
	}
	void KreditKonto::setoptVerf�ger2(CUSTOMER* _optKontoverf�ger) {
		this->optKontoverf�ger2 = _optKontoverf�ger;
	}
	CUSTOMER KreditKonto::getoptVerf�ger3() {
		return *optKontoverf�ger3;
	}
	void KreditKonto::setoptVerf�ger3(CUSTOMER* _optKontoverf�ger) {
		this->optKontoverf�ger3 = _optKontoverf�ger;
	}
	
	double KreditKonto::getKontostand() {
		return Kontostand;
	}
	void KreditKonto::setKontostand(double _Kontostand) {
		this->Kontostand = _Kontostand;
	}
	
	double KreditKonto::getKontonummer() {
		return Kontonummer;
	}
	void KreditKonto::setKontonummer(double _Kontonummer) {
		this->Kontonummer = _Kontonummer;
	}

	KreditKonto();

private:
	int Kontonummer;
	double Kontostand = 0;
	CUSTOMER* Kontoverf�ger;
	CUSTOMER* optKontoverf�ger1;
	CUSTOMER* optKontoverf�ger2;
	CUSTOMER* optKontoverf�ger3;
};

CUSTOMER* NeuerKunde() {

	string Vorname;
	string Nachname;
	string Geburtsdatum;
	string adresse;
	string hausnummer;
	string Wohnort;
	string Postleitzahl;
	string Telefon;
	CUSTOMER *Kunde = new CUSTOMER();

	cout << "Geben Sie den Vorname des Kunden ein:\n" << endl;
	cin >> Vorname;
	Kunde->setVorname(Vorname);
	cout << "\nGeben Sie den Nachnamen des Kunden ein:\n" << endl;
	cin >> Nachname;
	Kunde->setNachname(Nachname);
	cout << "\nGeben Sie das Geburtsdatum des Kunden ein:\n" << endl;
	cin >> Geburtsdatum;
	Kunde->setGeburtsdatum(Geburtsdatum);
	cout << "\nGeben Sie die Adresse des Kunden ein:\n" << endl;
	cin >> adresse;
	Kunde->setadresse(adresse);
	cout << "\nGeben Sie die Hausnummer zur Adresse ein:\n" << endl;
	cin >> hausnummer;
	Kunde->sethausnummer(hausnummer);
	cout << "\nGeben Sie den Wohnort des Kunden ein:\n" << endl;
	cin >> Wohnort;
	Kunde->setWohnort(Wohnort);
	cout << "\nGeben Sie die Postleitzahl des Kunden ein:\n" << endl;
	cin >> Postleitzahl;
	Kunde->setPostleitzahl(Postleitzahl);
	cout << "\nGeben Sie die Telefonnummer des Kunden ein:\n" << endl;
	cin >> Telefon;
	Kunde->setTelefon(Telefon);

	cout << "\n\n\nEs wurden folgende Eingaben gemacht:\n " << "\n\t" << Kunde->getVorname() << " " << Kunde->getNachname() << "\n\t" << Kunde->getGeburtsdatum() << "\n\t" << Kunde->getadresse() << " " << Kunde->gethausnummer() << "\n\t" << Kunde->getPostleitzahl() << " " << Kunde->getWohnort() << "\n\t" << Kunde->getTelefon() << endl;
	cout << "Der Kunde wurde erfolgreich angelegt!\n" << endl;

	return Kunde;
}
CUSTOMER* Kundendaten�nderung(CUSTOMER *Kunde) {

	string optionenauswahl;
	string Vorname;
	string Nachname;
	string adresse;
	string hausnummer;
	string Wohnort;
	string Postleitzahl;
	string Telefon;

start:
	cout << "KUNDENDATEN AENDERN:\nBitte waehlen Sie eine Option aus:\n 1 - Vorname aendern\n 2 - Nachname aendern\n 3 - Adresse aendern\n 4 - Hausnummer aendern\n 5 - Postleitzahl aendern\n 6 - Wohnort aendern\n 7 - Telefonnummer aendern\n" << endl;
	cin >> optionenauswahl;

	if (optionenauswahl == "1") {
		cout << "\nBitte geben Sie einen neuen Vornamen ein:" << endl;
		cin >> Vorname;
		Kunde->setVorname(Vorname);
		cout << "\nDie Kundendaten lauten nun wiefolgt:\n " << "\n\t" << Kunde->getVorname() << " " << Kunde->getNachname() << "\n\t" << Kunde->getGeburtsdatum() << "\n\t" << Kunde->getadresse() << " " << Kunde->gethausnummer() << "\n\t" << Kunde->getPostleitzahl() << " " << Kunde->getWohnort() << "\n\t" << Kunde->getTelefon() << endl;
		cout << "\nDie aenderungen wurden erfolgreich eingetragen" << endl;
		return Kunde;
		goto start;
	}
	else if (optionenauswahl == "2") {
		cout << "\nBitte geben Sie einen neuen Nachnamen ein:" << endl;
		cin >> Nachname;
		Kunde->setNachname(Nachname);
		cout << "\nDie Kundendaten lauten nun wiefolgt:\n " << "\n\t" << Kunde->getVorname() << " " << Kunde->getNachname() << "\n\t" << Kunde->getGeburtsdatum() << "\n\t" << Kunde->getadresse() << " " << Kunde->gethausnummer() << "\n\t" << Kunde->getPostleitzahl() << " " << Kunde->getWohnort() << "\n\t" << Kunde->getTelefon() << endl;
		cout << "\nDie aenderungen wurden erfolgreich eingetragen" << endl;
		return Kunde;
		goto start;
	}
	else if (optionenauswahl == "3") {
		cout << "\nBitte geben Sie einen neue Adresse ein:" << endl;
		cin >> adresse;
		Kunde->setadresse(adresse);
		cout << "\nDie Kundendaten lauten nun wiefolgt:\n " << "\n\t" << Kunde->getVorname() << " " << Kunde->getNachname() << "\n\t" << Kunde->getGeburtsdatum() << "\n\t" << Kunde->getadresse() << " " << Kunde->gethausnummer() << "\n\t" << Kunde->getPostleitzahl() << " " << Kunde->getWohnort() << "\n\t" << Kunde->getTelefon() << endl;
		cout << "\nDie aenderungen wurden erfolgreich eingetragen" << endl;
		return Kunde;
		goto start;
	}
	else if (optionenauswahl == "4") {
		cout << "\nBitte geben Sie einen neue Hausnummer ein:" << endl;
		cin >> hausnummer;
		Kunde->sethausnummer(hausnummer);
		cout << "\nDie Kundendaten lauten nun wiefolgt:\n " << "\n\t" << Kunde->getVorname() << " " << Kunde->getNachname() << "\n\t" << Kunde->getGeburtsdatum() << "\n\t" << Kunde->getadresse() << " " << Kunde->gethausnummer() << "\n\t" << Kunde->getPostleitzahl() << " " << Kunde->getWohnort() << "\n\t" << Kunde->getTelefon() << endl;
		cout << "\nDie aenderungen wurden erfolgreich eingetragen" << endl;
		return Kunde;
		goto start;
	}
	else if (optionenauswahl == "5") {
		cout << "\nBitte geben Sie einen neue Postleitzahl ein:" << endl;
		cin >> Postleitzahl;
		Kunde->setPostleitzahl(Postleitzahl);
		cout << "\nDie Kundendaten lauten nun wiefolgt:\n " << "\n\t" << Kunde->getVorname() << " " << Kunde->getNachname() << "\n\t" << Kunde->getGeburtsdatum() << "\n\t" << Kunde->getadresse() << " " << Kunde->gethausnummer() << "\n\t" << Kunde->getPostleitzahl() << " " << Kunde->getWohnort() << "\n\t" << Kunde->getTelefon() << endl;
		cout << "\nDie aenderungen wurden erfolgreich eingetragen" << endl;
		return Kunde;
		goto start;
	}
	else if (optionenauswahl == "6") {
		cout << "\nBitte geben Sie einen neuen Wohnort ein:" << endl;
		cin >> Wohnort;
		Kunde->setWohnort(Wohnort);
		cout << "\nDie Kundendaten lauten nun wiefolgt:\n " << "\n\t" << Kunde->getVorname() << " " << Kunde->getNachname() << "\n\t" << Kunde->getGeburtsdatum() << "\n\t" << Kunde->getadresse() << " " << Kunde->gethausnummer() << "\n\t" << Kunde->getPostleitzahl() << " " << Kunde->getWohnort() << "\n\t" << Kunde->getTelefon() << endl;
		cout << "\nDie aenderungen wurden erfolgreich eingetragen" << endl;
		return Kunde;
		goto start;
	}
	else if (optionenauswahl == "7") {
		cout << "\nBitte geben Sie einee neue Telefonnummer ein:" << endl;
		cin >> Telefon;
		Kunde->setTelefon(Telefon);
		cout << "\nDie Kundendaten lauten nun wiefolgt:\n " << "\n\t" << Kunde->getVorname() << " " << Kunde->getNachname() << "\n\t" << Kunde->getGeburtsdatum() << "\n\t" << Kunde->getadresse() << " " << Kunde->gethausnummer() << "\n\t" << Kunde->getPostleitzahl() << " " << Kunde->getWohnort() << "\n\t" << Kunde->getTelefon() << endl;
		cout << "\nDie aenderungen wurden erfolgreich eingetragen" << endl;
		return Kunde;
		goto start;
	}
	else {
		cout << "\nBitte waehlen Sie nur eine verfuegbare Option!\n\n" << endl;
		goto start;
	}
}
void Kundeentfernen(CUSTOMER* Kunde) {
	if (Kunde != NULL) {
		delete Kunde;
	}
	cout << "\nDer Kunde wurde erfolgreich entfernt." << endl;
}

SparKonto* NeuesSparkonto(CUSTOMER* Kunde, int verf�geranzahl) {

	SparKonto *Konto = new SparKonto();
	int SparKontonummer = Konto->getKontonummer();
	if (verf�geranzahl == 1) {
		Konto->setVerf�ger(Kunde);
		cout << "\nDas SparKonto wurde erfolgreich erstellt.\n" << endl;
		cout << "Die Kontonummer lautet: " << SparKontonummer << "\n" << endl;
		return Konto;
	}
	if (verf�geranzahl == 2) {
		Konto->setVerf�ger(Kunde);
		CUSTOMER* optKunde1 = NeuerKunde();
		Konto->setoptVerf�ger1(optKunde1);
		cout << "\nDas SparKonto wurde erfolgreich erstellt.\n" << endl;
		cout << "Die Kontonummer lautet: " << SparKontonummer << "\n" << endl;
		return Konto;
	}
	if (verf�geranzahl == 3) {
		Konto->setVerf�ger(Kunde);
		CUSTOMER* optKunde1 = NeuerKunde();
		CUSTOMER* optKunde2 = NeuerKunde();
		Konto->setoptVerf�ger1(optKunde1);
		Konto->setoptVerf�ger2(optKunde2);
		cout << "\nDas SparKonto wurde erfolgreich erstellt.\n" << endl;
		cout << "Die Kontonummer lautet: " << SparKontonummer << "\n" << endl;
		return Konto;
	}
	if (verf�geranzahl == 4) {
		Konto->setVerf�ger(Kunde);
		CUSTOMER* optKunde1 = NeuerKunde();
		CUSTOMER* optKunde2 = NeuerKunde();
		CUSTOMER* optKunde3 = NeuerKunde();
		Konto->setoptVerf�ger1(optKunde1);
		Konto->setoptVerf�ger2(optKunde2);
		Konto->setoptVerf�ger3(optKunde3);
		cout << "\nDas SparKonto wurde erfolgreich erstellt.\n" << endl;
		cout << "Die Kontonummer lautet: " << SparKontonummer << "\n" << endl;
		return Konto;
	}
};
KreditKonto* NeuesKreditkonto(CUSTOMER* Kunde, int verf�geranzahl) {

	KreditKonto *Konto = new KreditKonto();
	int KreditKontonummer = Konto->getKontonummer();
	if (verf�geranzahl == 1) {
		Konto->setVerf�ger(Kunde);
		cout << "\nDas KreditKonto wurde erfolgreich erstellt.\n" << endl;
		cout << "Die Kontonummer lautet: " << KreditKontonummer << "\n" << endl;
		return Konto;
	}
	if (verf�geranzahl == 2) {
		Konto->setVerf�ger(Kunde);
		CUSTOMER* optKunde1 = NeuerKunde();
		Konto->setoptVerf�ger1(optKunde1);
		cout << "\nDas KreditKonto wurde erfolgreich erstellt.\n" << endl;
		cout << "Die Kontonummer lautet: " << KreditKontonummer << "\n" << endl;
		return Konto;
	}
	if (verf�geranzahl == 3) {
		Konto->setVerf�ger(Kunde);
		CUSTOMER* optKunde1 = NeuerKunde();
		CUSTOMER* optKunde2 = NeuerKunde();
		Konto->setoptVerf�ger1(optKunde1);
		Konto->setoptVerf�ger2(optKunde2);
		cout << "\nDas KreditKonto wurde erfolgreich erstellt.\n" << endl;
		cout << "Die Kontonummer lautet: " << KreditKontonummer << "\n" << endl;
		return Konto;
	}
	if (verf�geranzahl == 4) {
		Konto->setVerf�ger(Kunde);
		CUSTOMER* optKunde1 = NeuerKunde();
		CUSTOMER* optKunde2 = NeuerKunde();
		CUSTOMER* optKunde3 = NeuerKunde();
		Konto->setoptVerf�ger1(optKunde1);
		Konto->setoptVerf�ger2(optKunde2);
		Konto->setoptVerf�ger3(optKunde3);
		cout << "\nDas KreditKonto wurde erfolgreich erstellt.\n" << endl;
		cout << "Die Kontonummer lautet: " << KreditKontonummer << "\n" << endl;
		return Konto;
	}
};

void Sparkontoentfernen(SparKonto* Konto) {
	if (Konto != NULL) {
		delete Konto;
	}
	cout << "\nDas Konto wurde erfolgreich entfernt." << endl;
}
void Kreditkontoentfernen(KreditKonto* Konto) {
	if (Konto != NULL) {
		delete Konto;
	}
	cout << "\nDas Konto wurde erfolgreich entfernt." << endl;
}

int generateKtnnr() {

	static int Kontonummernpool = 10000000;

	Kontonummernpool++;
	return Kontonummernpool;
}
KreditKonto::KreditKonto()
{
	setKontonummer(generateKtnnr());

}
SparKonto::SparKonto()
{
	setKontonummer(generateKtnnr());

}