// Customer.cpp : Defines the exported functions for the DLL application.
// Compile by using: cl /EHsc /DCUSTOMER_EXPORTS /LD Customer.cpp

#include "stdafx.h"
#include "Customer.h"
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <sstream>
#include <time.h>

#define __STDC_WANT_LIB_EXT1__ 1

using namespace std;
FILE* logfile;


string time_to_string(){
	
	struct tm newtime;
	__time64_t long_time;
	char timebuf[26];
	errno_t err;

	// Get time as 64-bit integer.
	_time64(&long_time);
	err = _localtime64_s(&newtime, &long_time); 
	err = asctime_s(timebuf, 26, &newtime);
	strftime(timebuf, sizeof(timebuf), "%d %m %Y %H:%M:%S", &newtime);
	string str(timebuf);
	cout << timebuf << endl;
	cout << str << endl;
	return str;
}
void LOGGING(string Errortext, string LEVEL) {

	const char *Errortxt = Errortext.c_str();
	string stringtime = time_to_string();
	const char *time = stringtime.c_str();
	const char *lvl = LEVEL.c_str();

	fopen_s(&logfile,"Customer_log.txt", "a");
	if (logfile == NULL)
	{
		printf("Das Logfile konnte nicht erstellt werden");
	}

	//Hier soll noch die Zeit drinnen stehen 
	fprintf(logfile, time);
	fprintf(logfile, " - ");
	fprintf(logfile, lvl);
	fprintf(logfile, ": ");
	fprintf(logfile, Errortxt);
	fprintf(logfile, "\n");

}

class CUSTOMER {
public:

	//Getter und Setter der Kundendaten
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
class SPARKONTO {
public:
	//Getter und Setter der Daten
	CUSTOMER SPARKONTO::getVerfüger() {
		return *Kontoverfüger;
	}
	void SPARKONTO::setVerfüger(CUSTOMER* _Kontoverfüger) {
		this->Kontoverfüger = _Kontoverfüger;
	}
	CUSTOMER SPARKONTO::getoptVerfüger1() {
		return *optKontoverfüger1;
	}
	void SPARKONTO::setoptVerfüger1(CUSTOMER* _optKontoverfüger) {
		this->optKontoverfüger1 = _optKontoverfüger;
	}
	CUSTOMER SPARKONTO::getoptVerfüger2() {
		return *optKontoverfüger2;
	}
	void SPARKONTO::setoptVerfüger2(CUSTOMER* _optKontoverfüger) {
		this->optKontoverfüger2 = _optKontoverfüger;
	}
	CUSTOMER SPARKONTO::getoptVerfüger3() {
		return *optKontoverfüger3;
	}
	void SPARKONTO::setoptVerfüger3(CUSTOMER* _optKontoverfüger) {
		this->optKontoverfüger3 = _optKontoverfüger;
	}
	double SPARKONTO::getKontostand() {
		return Kontostand;
	}
	void SPARKONTO::setKontostand(double _Kontostand) {
		this->Kontostand = _Kontostand;
	}
	double SPARKONTO::getKontonummer() {
		return Kontonummer;
	}
	void SPARKONTO::setKontonummer(double _Kontonummer) {
		this->Kontonummer = _Kontonummer;
	}
	
	//Konstruktor zur Erstellung des Kontos mit Kontonummer 
	SPARKONTO();

private:
	int Kontonummer;
	double Kontostand = 0;
	CUSTOMER* Kontoverfüger;
	CUSTOMER* optKontoverfüger1;
	CUSTOMER* optKontoverfüger2;
	CUSTOMER* optKontoverfüger3;
};
class KREDITKONTO{
public:
	//Getter und Setter der Daten
	CUSTOMER KREDITKONTO::getVerfüger() {
		return *Kontoverfüger;
	}
	void KREDITKONTO::setVerfüger(CUSTOMER* _Kontoverfüger) {
		this->Kontoverfüger = _Kontoverfüger;
	}
	CUSTOMER KREDITKONTO::getoptVerfüger1() {
		return *optKontoverfüger1;
	}
	void KREDITKONTO::setoptVerfüger1(CUSTOMER* _optKontoverfüger) {
		this->optKontoverfüger1 = _optKontoverfüger;
	}
	CUSTOMER KREDITKONTO::getoptVerfüger2() {
		return *optKontoverfüger2;
	}
	void KREDITKONTO::setoptVerfüger2(CUSTOMER* _optKontoverfüger) {
		this->optKontoverfüger2 = _optKontoverfüger;
	}
	CUSTOMER KREDITKONTO::getoptVerfüger3() {
		return *optKontoverfüger3;
	}
	void KREDITKONTO::setoptVerfüger3(CUSTOMER* _optKontoverfüger) {
		this->optKontoverfüger3 = _optKontoverfüger;
	}
	double KREDITKONTO::getKontostand() {
		return Kontostand;
	}
	void KREDITKONTO::setKontostand(double _Kontostand) {
		this->Kontostand = _Kontostand;
	}	
	double KREDITKONTO::getKontonummer() {
		return Kontonummer;
	}
	void KREDITKONTO::setKontonummer(double _Kontonummer) {
		this->Kontonummer = _Kontonummer;
	}

	//Konstruktor zur Erstellung des Kontos mit Kontonummer 
	KREDITKONTO();

private:
	int Kontonummer;
	double Kontostand = 0;
	CUSTOMER* Kontoverfüger;
	CUSTOMER* optKontoverfüger1;
	CUSTOMER* optKontoverfüger2;
	CUSTOMER* optKontoverfüger3;
};

//NeuerKunde legt einen neuen Kunden an 
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
//Mit der Funktion Kundendatenänderung können fast alle Daten (Geburtsdatum wird sich nie ändern) eines bestehenden Kunden geändert werden.
CUSTOMER* Kundendatenänderung(CUSTOMER *Kunde) {

	if (Kunde == NULL) {		
		LOGGING("Es existiert kein Kunde, dessen Daten geändert werden koennte", "ERROR");
		return NULL;
	}

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
//Die Funktion Kundeentfernen entfernt mithilfe von delete den übergebenen Kunden
void Kundeentfernen(CUSTOMER* Kunde) {
	if (Kunde != NULL) {
		delete Kunde;
	}
	LOGGING("\nDer Kunde wurde erfolgreich entfernt.", "OK");
}

//Die Funktionen für ein neues Konto erstellt ein neues Kredit-/Sparkonto und weißt das dem übergebenen Kunden zu. der 2. parameter lässt zu, 
//dass mehrere Kunden ein Konto besitzen können. Es können maximal 4 Kunden über ein Konto verfügen. Übergeben wird hier 1-4. 
SPARKONTO* NeuesSparkonto(CUSTOMER* Kunde, int verfügeranzahl) {

	if (Kunde == NULL) {
		LOGGING("\nEs existiert kein Kunde, welcher auf das Konto zugewiesen werden kann", "ERROR");
		return NULL;
	}

	SPARKONTO *Konto = new SPARKONTO();
	int SparKontonummer = Konto->getKontonummer();
	if (verfügeranzahl == 1) {
		Konto->setVerfüger(Kunde);
		LOGGING("\nDas SparKonto wurde erfolgreich erstellt.\n", "OK");
		return Konto;
	}
	if (verfügeranzahl == 2) {
		Konto->setVerfüger(Kunde);
		CUSTOMER* optKunde1 = NeuerKunde();
		Konto->setoptVerfüger1(optKunde1);
		LOGGING("\nDas SparKonto wurde erfolgreich erstellt.\n", "OK");
		return Konto;
	}
	if (verfügeranzahl == 3) {
		Konto->setVerfüger(Kunde);
		CUSTOMER* optKunde1 = NeuerKunde();
		CUSTOMER* optKunde2 = NeuerKunde();
		Konto->setoptVerfüger1(optKunde1);
		Konto->setoptVerfüger2(optKunde2);
		LOGGING("\nDas SparKonto wurde erfolgreich erstellt.\n", "OK");
		return Konto;
	}
	if (verfügeranzahl == 4) {
		Konto->setVerfüger(Kunde);
		CUSTOMER* optKunde1 = NeuerKunde();
		CUSTOMER* optKunde2 = NeuerKunde();
		CUSTOMER* optKunde3 = NeuerKunde();
		Konto->setoptVerfüger1(optKunde1);
		Konto->setoptVerfüger2(optKunde2);
		Konto->setoptVerfüger3(optKunde3);
		LOGGING("\nDas SparKonto wurde erfolgreich erstellt.\n", "OK");
		return Konto;
	}
};
KREDITKONTO* NeuesKreditkonto(CUSTOMER* Kunde, int verfügeranzahl) {

	if (Kunde == NULL) {
		LOGGING("\nEs existiert kein Kunde, welcher auf das Konto zugewiesen werden kann", "ERROR");
		return NULL;
	}

	KREDITKONTO *Konto = new KREDITKONTO();
	int KreditKontonummer = Konto->getKontonummer();
	if (verfügeranzahl == 1) {
		Konto->setVerfüger(Kunde);
		LOGGING("\nDas KreditKonto wurde erfolgreich erstellt.\n", "OK");
		return Konto;
	}
	if (verfügeranzahl == 2) {
		Konto->setVerfüger(Kunde);
		CUSTOMER* optKunde1 = NeuerKunde();
		Konto->setoptVerfüger1(optKunde1);
		LOGGING("\nDas KreditKonto wurde erfolgreich erstellt.\n", "OK");
		return Konto;
	}
	if (verfügeranzahl == 3) {
		Konto->setVerfüger(Kunde);
		CUSTOMER* optKunde1 = NeuerKunde();
		CUSTOMER* optKunde2 = NeuerKunde();
		Konto->setoptVerfüger1(optKunde1);
		Konto->setoptVerfüger2(optKunde2);
		LOGGING("\nDas KreditKonto wurde erfolgreich erstellt.\n", "OK");
		return Konto;
	}
	if (verfügeranzahl == 4) {
		Konto->setVerfüger(Kunde);
		CUSTOMER* optKunde1 = NeuerKunde();
		CUSTOMER* optKunde2 = NeuerKunde();
		CUSTOMER* optKunde3 = NeuerKunde();
		Konto->setoptVerfüger1(optKunde1);
		Konto->setoptVerfüger2(optKunde2);
		Konto->setoptVerfüger3(optKunde3);
		LOGGING("\nDas KreditKonto wurde erfolgreich erstellt.\n", "OK");
		return Konto;
	}
};

//Die Funktion Sparkontoentfernen entfernt das übergebene SparKonto mit der Funktion delete
void Sparkontoentfernen(SPARKONTO* Konto) {
	
	if (Konto == NULL) {
		LOGGING("\nDas übergebene Konto existiert nicht.", "ERROR");
		return;
	}
	delete Konto;
	LOGGING("\nDas Konto wurde erfolgreich entfernt.", "OK");
}
//Die Funktion Kreditkontoentfernen entfernt das übergebene KreditKonto mit der Funktion delete
void Kreditkontoentfernen(KREDITKONTO* Konto) {
	
	if (Konto == NULL) {
		LOGGING("\nDas übergebene Konto existiert nicht", "ERROR");
		return;
	}
	delete Konto;
	LOGGING("\nDas Konto wurde erfolgreich entfernt.", "OK");
}
//generateKtnr erstellt eine Kontonummer und iteriert immer um 1 hoch
int generateKtnnr() {

	static int Kontonummernpool = 10000000;

	Kontonummernpool++;
	return Kontonummernpool;
}

//In den Konstruktoren wird beim erstellen eines Kontos auch gleich die Kontonummer generiert
KREDITKONTO::KREDITKONTO()
{
	setKontonummer(generateKtnnr());

}
SPARKONTO::SPARKONTO()
{
	setKontonummer(generateKtnnr());

}
