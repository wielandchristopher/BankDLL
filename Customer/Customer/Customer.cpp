// Customer.cpp : Defines the exported functions for the DLL application.
// Compile by using: cl /EHsc /DCUSTOMER_EXPORTS /LD Customer.cpp

#include "stdafx.h"
#include "Customer.h"
#include <string>
#include <iostream>
#include <time.h>

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
		return Adresse;
	}
	void CUSTOMER::setadresse(string _Adresse) {
		this->Adresse = _Adresse;
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
	string Adresse;
	string Postleitzahl;
	string Wohnort;
	string Telefon;
};
class SPARKONTO {
public:
	//Getter und Setter der Daten
	CUSTOMER SPARKONTO::getVerf�ger() {
		return *Kontoverf�ger;
	}
	void SPARKONTO::setVerf�ger(CUSTOMER* _Kontoverf�ger) {
		this->Kontoverf�ger = _Kontoverf�ger;
	}
	CUSTOMER SPARKONTO::getoptVerf�ger1() {
		return *optKontoverf�ger1;
	}
	void SPARKONTO::setoptVerf�ger1(CUSTOMER* _optKontoverf�ger) {
		this->optKontoverf�ger1 = _optKontoverf�ger;
	}
	CUSTOMER SPARKONTO::getoptVerf�ger2() {
		return *optKontoverf�ger2;
	}
	void SPARKONTO::setoptVerf�ger2(CUSTOMER* _optKontoverf�ger) {
		this->optKontoverf�ger2 = _optKontoverf�ger;
	}
	CUSTOMER SPARKONTO::getoptVerf�ger3() {
		return *optKontoverf�ger3;
	}
	void SPARKONTO::setoptVerf�ger3(CUSTOMER* _optKontoverf�ger) {
		this->optKontoverf�ger3 = _optKontoverf�ger;
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
	CUSTOMER* Kontoverf�ger;
	CUSTOMER* optKontoverf�ger1;
	CUSTOMER* optKontoverf�ger2;
	CUSTOMER* optKontoverf�ger3;
};
class KREDITKONTO{
public:
	//Getter und Setter der Daten
	CUSTOMER KREDITKONTO::getVerf�ger() {
		return *Kontoverf�ger;
	}
	void KREDITKONTO::setVerf�ger(CUSTOMER* _Kontoverf�ger) {
		this->Kontoverf�ger = _Kontoverf�ger;
	}
	CUSTOMER KREDITKONTO::getoptVerf�ger1() {
		return *optKontoverf�ger1;
	}
	void KREDITKONTO::setoptVerf�ger1(CUSTOMER* _optKontoverf�ger) {
		this->optKontoverf�ger1 = _optKontoverf�ger;
	}
	CUSTOMER KREDITKONTO::getoptVerf�ger2() {
		return *optKontoverf�ger2;
	}
	void KREDITKONTO::setoptVerf�ger2(CUSTOMER* _optKontoverf�ger) {
		this->optKontoverf�ger2 = _optKontoverf�ger;
	}
	CUSTOMER KREDITKONTO::getoptVerf�ger3() {
		return *optKontoverf�ger3;
	}
	void KREDITKONTO::setoptVerf�ger3(CUSTOMER* _optKontoverf�ger) {
		this->optKontoverf�ger3 = _optKontoverf�ger;
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
	CUSTOMER* Kontoverf�ger;
	CUSTOMER* optKontoverf�ger1;
	CUSTOMER* optKontoverf�ger2;
	CUSTOMER* optKontoverf�ger3;
};

//NeuerKunde legt einen neuen Kunden an 
//Es werden 7 Parameter in der Reihenfolge angegeben: Vorname, Nachname, Geburtsdatum, Adresse, Postleitzahl, Wohnort, Telefon
CUSTOMER* NeuerKunde(char* _Vorname, char* _Nachname, char* _Geburtsdatum, char* _Adresse, char* _Postleitzahl, char* _Wohnort, char* _Telefon) {

	if ((_Vorname || _Nachname || _Geburtsdatum || _Adresse || _Postleitzahl || _Wohnort || _Telefon) == NULL) {
		LOGGING("Einer der Parameter bei der erstellung eines neuen Kunden ist NULL","ERROR");
		return NULL;
	}

	string Vorname(_Vorname);
	string Nachname(_Nachname);
	string Geburtsdatum(_Geburtsdatum);
	string Adresse(_Adresse);
	string Postleitzahl(_Postleitzahl);
	string Wohnort(_Wohnort);
	string Telefon(_Telefon);
	CUSTOMER *Kunde = new CUSTOMER();

	Kunde->setVorname(Vorname);
	Kunde->setNachname(Nachname);
	Kunde->setGeburtsdatum(Geburtsdatum);
	Kunde->setadresse(Adresse);
	Kunde->setWohnort(Wohnort);
	Kunde->setPostleitzahl(Postleitzahl);
	Kunde->setTelefon(Telefon);

	LOGGING("Der Kunde wurde erfolgreich angelegt.", "OK");

	return Kunde;
}
//Mit der Funktion Kundendaten�nderung k�nnen fast alle Daten (Geburtsdatum wird sich nie �ndern) eines bestehenden Kunden ge�ndert werden.
CUSTOMER* Kundendaten�nderung(CUSTOMER *Kunde) {

	if (Kunde == NULL) {		
		LOGGING("Es existiert kein Kunde, dessen Daten ge�ndert werden koennte", "ERROR");
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
	cout << "KUNDENDATEN AENDERN:\nBitte waehlen Sie eine Option aus:\n 1 - Vorname aendern\n 2 - Nachname aendern\n 3 - Adresse aendern\n 4 - Postleitzahl aendern\n 5 - Wohnort aendern\n 6 - Telefonnummer aendern\n" << endl;
	cin >> optionenauswahl;

	if (optionenauswahl == "1") {
		cout << "\nBitte geben Sie einen neuen Vornamen ein:" << endl;
		cin >> Vorname;
		Kunde->setVorname(Vorname);
		cout << "\nDie Kundendaten lauten nun wiefolgt:\n " << "\n\t" << Kunde->getVorname() << " " << Kunde->getNachname() << "\n\t" << Kunde->getGeburtsdatum() << "\n\t" << Kunde->getadresse() << "\n\t" << Kunde->getPostleitzahl() << " " << Kunde->getWohnort() << "\n\t" << Kunde->getTelefon() << endl;
		cout << "\nDie aenderungen wurden erfolgreich eingetragen" << endl;
		return Kunde;
		goto start;
	}
	else if (optionenauswahl == "2") {
		cout << "\nBitte geben Sie einen neuen Nachnamen ein:" << endl;
		cin >> Nachname;
		Kunde->setNachname(Nachname);
		cout << "\nDie Kundendaten lauten nun wiefolgt:\n " << "\n\t" << Kunde->getVorname() << " " << Kunde->getNachname() << "\n\t" << Kunde->getGeburtsdatum() << "\n\t" << Kunde->getadresse() << "\n\t" << Kunde->getPostleitzahl() << " " << Kunde->getWohnort() << "\n\t" << Kunde->getTelefon() << endl;
		cout << "\nDie aenderungen wurden erfolgreich eingetragen" << endl;
		return Kunde;
		goto start;
	}
	else if (optionenauswahl == "3") {
		cout << "\nBitte geben Sie einen neue Adresse ein:" << endl;
		cin >> adresse;
		Kunde->setadresse(adresse);
		cout << "\nDie Kundendaten lauten nun wiefolgt:\n " << "\n\t" << Kunde->getVorname() << " " << Kunde->getNachname() << "\n\t" << Kunde->getGeburtsdatum() << "\n\t" << Kunde->getadresse() << "\n\t" << Kunde->getPostleitzahl() << " " << Kunde->getWohnort() << "\n\t" << Kunde->getTelefon() << endl;
		cout << "\nDie aenderungen wurden erfolgreich eingetragen" << endl;
		return Kunde;
		goto start;
	}
	else if (optionenauswahl == "4") {
		cout << "\nBitte geben Sie einen neue Postleitzahl ein:" << endl;
		cin >> Postleitzahl;
		Kunde->setPostleitzahl(Postleitzahl);
		cout << "\nDie Kundendaten lauten nun wiefolgt:\n " << "\n\t" << Kunde->getVorname() << " " << Kunde->getNachname() << "\n\t" << Kunde->getGeburtsdatum() << "\n\t" << Kunde->getadresse() << "\n\t" << Kunde->getPostleitzahl() << " " << Kunde->getWohnort() << "\n\t" << Kunde->getTelefon() << endl;
		cout << "\nDie aenderungen wurden erfolgreich eingetragen" << endl;
		return Kunde;
		goto start;
	}
	else if (optionenauswahl == "5") {
		cout << "\nBitte geben Sie einen neuen Wohnort ein:" << endl;
		cin >> Wohnort;
		Kunde->setWohnort(Wohnort);
		cout << "\nDie Kundendaten lauten nun wiefolgt:\n " << "\n\t" << Kunde->getVorname() << " " << Kunde->getNachname() << "\n\t" << Kunde->getGeburtsdatum() << "\n\t" << Kunde->getadresse() << "\n\t" << Kunde->getPostleitzahl() << " " << Kunde->getWohnort() << "\n\t" << Kunde->getTelefon() << endl;
		cout << "\nDie aenderungen wurden erfolgreich eingetragen" << endl;
		return Kunde;
		goto start;
	}
	else if (optionenauswahl == "6") {
		cout << "\nBitte geben Sie einee neue Telefonnummer ein:" << endl;
		cin >> Telefon;
		Kunde->setTelefon(Telefon);
		cout << "\nDie Kundendaten lauten nun wiefolgt:\n " << "\n\t" << Kunde->getVorname() << " " << Kunde->getNachname() << "\n\t" << Kunde->getGeburtsdatum() << "\n\t" << Kunde->getadresse() << "\n\t" << Kunde->getPostleitzahl() << " " << Kunde->getWohnort() << "\n\t" << Kunde->getTelefon() << endl;
		cout << "\nDie aenderungen wurden erfolgreich eingetragen" << endl;
		return Kunde;
		goto start;
	}
	else {
		cout << "\nBitte waehlen Sie nur eine verfuegbare Option!\n\n" << endl;
		goto start;
	}
}
//Die Funktion Kundeentfernen entfernt mithilfe von delete den �bergebenen Kunden
void Kundeentfernen(CUSTOMER* Kunde) {
	if (Kunde != NULL) {
		delete Kunde;
	}
	LOGGING("\nDer Kunde wurde erfolgreich entfernt.", "OK");
}

//Die Funktionen f�r ein neues Konto erstellt ein neues Kredit-/Sparkonto und wei�t das dem �bergebenen Kunden zu. der 2. parameter l�sst zu, 
//dass mehrere Kunden ein Konto besitzen k�nnen. Es k�nnen maximal 4 Kunden �ber ein Konto verf�gen. �bergeben wird hier 1-4. 
SPARKONTO* NeuesSparkonto(CUSTOMER* Kunde, int verf�geranzahl) {

	if (Kunde == NULL) {
		LOGGING("\nEs existiert kein Kunde, welcher auf das Konto zugewiesen werden kann", "ERROR");
		return NULL;
	}

	SPARKONTO *Konto = new SPARKONTO();
	int SparKontonummer = Konto->getKontonummer();
	if (verf�geranzahl == 1) {
		Konto->setVerf�ger(Kunde);
		LOGGING("\nDas SparKonto wurde erfolgreich erstellt.\n", "OK");
		return Konto;
	}
	if (verf�geranzahl == 2) {
		Konto->setVerf�ger(Kunde);
		CUSTOMER* optKunde1 = NeuerKunde("Test", "Test", "Test", "Test", "Test", "Test", "Test");
		Konto->setoptVerf�ger1(optKunde1);
		LOGGING("\nDas SparKonto wurde erfolgreich erstellt.\n", "OK");
		return Konto;
	}
	if (verf�geranzahl == 3) {
		Konto->setVerf�ger(Kunde);
		CUSTOMER* optKunde1 = NeuerKunde("Test", "Test", "Test", "Test", "Test", "Test", "Test");
		CUSTOMER* optKunde2 = NeuerKunde("Test", "Test", "Test", "Test", "Test", "Test", "Test");
		Konto->setoptVerf�ger1(optKunde1);
		Konto->setoptVerf�ger2(optKunde2);
		LOGGING("\nDas SparKonto wurde erfolgreich erstellt.\n", "OK");
		return Konto;
	}
	if (verf�geranzahl == 4) {
		Konto->setVerf�ger(Kunde);
		CUSTOMER* optKunde1 = NeuerKunde("Test", "Test", "Test", "Test", "Test", "Test", "Test");
		CUSTOMER* optKunde2 = NeuerKunde("Test", "Test", "Test", "Test", "Test", "Test", "Test");
		CUSTOMER* optKunde3 = NeuerKunde("Test", "Test", "Test", "Test", "Test", "Test", "Test");
		Konto->setoptVerf�ger1(optKunde1);
		Konto->setoptVerf�ger2(optKunde2);
		Konto->setoptVerf�ger3(optKunde3);
		LOGGING("\nDas SparKonto wurde erfolgreich erstellt.\n", "OK");
		return Konto;
	}
};
KREDITKONTO* NeuesKreditkonto(CUSTOMER* Kunde, int verf�geranzahl) {

	if (Kunde == NULL) {
		LOGGING("\nEs existiert kein Kunde, welcher auf das Konto zugewiesen werden kann", "ERROR");
		return NULL;
	}

	KREDITKONTO *Konto = new KREDITKONTO();
	int KreditKontonummer = Konto->getKontonummer();
	if (verf�geranzahl == 1) {
		Konto->setVerf�ger(Kunde);
		LOGGING("\nDas KreditKonto wurde erfolgreich erstellt.\n", "OK");
		return Konto;
	}
	if (verf�geranzahl == 2) {
		Konto->setVerf�ger(Kunde);
		CUSTOMER* optKunde1 = NeuerKunde("Test", "Test", "Test", "Test", "Test", "Test", "Test");
		Konto->setoptVerf�ger1(optKunde1);
		LOGGING("\nDas KreditKonto wurde erfolgreich erstellt.\n", "OK");
		return Konto;
	}
	if (verf�geranzahl == 3) {
		Konto->setVerf�ger(Kunde);
		CUSTOMER* optKunde1 = NeuerKunde("Test", "Test", "Test", "Test", "Test", "Test", "Test");
		CUSTOMER* optKunde2 = NeuerKunde("Test", "Test", "Test", "Test", "Test", "Test", "Test");
		Konto->setoptVerf�ger1(optKunde1);
		Konto->setoptVerf�ger2(optKunde2);
		LOGGING("\nDas KreditKonto wurde erfolgreich erstellt.\n", "OK");
		return Konto;
	}
	if (verf�geranzahl == 4) {
		Konto->setVerf�ger(Kunde);
		CUSTOMER* optKunde1 = NeuerKunde("Test", "Test", "Test", "Test", "Test", "Test", "Test");
		CUSTOMER* optKunde2 = NeuerKunde("Test", "Test", "Test", "Test", "Test", "Test", "Test");
		CUSTOMER* optKunde3 = NeuerKunde("Test", "Test", "Test", "Test", "Test", "Test", "Test");
		Konto->setoptVerf�ger1(optKunde1);
		Konto->setoptVerf�ger2(optKunde2);
		Konto->setoptVerf�ger3(optKunde3);
		LOGGING("\nDas KreditKonto wurde erfolgreich erstellt.\n", "OK");
		return Konto;
	}
};

//Die Funktion Sparkontoentfernen entfernt das �bergebene SparKonto mit der Funktion delete
void Sparkontoentfernen(SPARKONTO* Konto) {
	
	if (Konto == NULL) {
		LOGGING("\nDas �bergebene Konto existiert nicht.", "ERROR");
		return;
	}
	delete Konto;
	LOGGING("\nDas Konto wurde erfolgreich entfernt.", "OK");
}
//Die Funktion Kreditkontoentfernen entfernt das �bergebene KreditKonto mit der Funktion delete
void Kreditkontoentfernen(KREDITKONTO* Konto) {
	
	if (Konto == NULL) {
		LOGGING("\nDas �bergebene Konto existiert nicht", "ERROR");
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
