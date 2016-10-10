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

	fclose(logfile);

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
	string CUSTOMER::getAdresse() {
		return Adresse;
	}
	void CUSTOMER::setAdresse(string _Adresse) {
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
	Kunde->setAdresse(Adresse);
	Kunde->setWohnort(Wohnort);
	Kunde->setPostleitzahl(Postleitzahl);
	Kunde->setTelefon(Telefon);

	LOGGING("Der Kunde wurde erfolgreich angelegt.", "OK");

	return Kunde;
}
//Mit der Funktion Kundendaten�nderung k�nnen fast alle Daten (Geburtsdatum wird sich nie �ndern) eines bestehenden Kunden ge�ndert werden.

CUSTOMER* Kundenvornamen�nderung(CUSTOMER *Kunde, char* _Vorname) {

	if (Kunde == NULL) {
		LOGGING("Es existiert kein Kunde, dessen Vorname ge�ndert werden k�nnte", "ERROR");
		return NULL;
	}

	if (_Vorname == "") {
		LOGGING("Es wurden keine �nderungen eingegeben", "ERROR");
		return Kunde;
	}

	string Vorname(_Vorname);
	Kunde->setVorname(Vorname);
	LOGGING("Der Vorname wurde erfolgreich ge�ndert","OK");
	return Kunde;
}
CUSTOMER* Kundennachnamen�nderung(CUSTOMER *Kunde, char* _Nachname) {
	
	if (Kunde == NULL) {
		LOGGING("Es existiert kein Kunde, dessen Nachname ge�ndert werden k�nnte", "ERROR");
		return NULL;
	}

	if (_Nachname == "") {
		LOGGING("Es wurden keine �nderungen eingegeben", "ERROR");
		return Kunde;
	}

	string Nachname(_Nachname);
	Kunde->setNachname(Nachname);
	LOGGING("Der Nachname wurde erfolgreich ge�ndert", "OK");
	return Kunde;
}
CUSTOMER* Kundenadress�nderung(CUSTOMER *Kunde, char* _Adresse) {

	if (Kunde == NULL) {
		LOGGING("Es existiert kein Kunde, dessen Adresse ge�ndert werden k�nnte", "ERROR");
		return NULL;
	}
	
	if (_Adresse == "") {
		LOGGING("Es wurden keine �nderungen eingegeben", "ERROR");
		return Kunde;
	}

	string Adresse(_Adresse);
	Kunde->setAdresse(Adresse);
	LOGGING("Die Adresse wurde erfolgreich ge�ndert", "OK");
	return Kunde;
}
CUSTOMER* Kundenplz�nderung(CUSTOMER *Kunde, char* _Postleitzahl) {

	if (Kunde == NULL) {
		LOGGING("Es existiert kein Kunde, dessen PLZ ge�ndert werden k�nnte", "ERROR");
		return NULL;
	}
	
	if (_Postleitzahl == "") {
		LOGGING("Es wurden keine �nderungen eingegeben", "ERROR");
		return Kunde;
	}

	string Postleitzahl(_Postleitzahl);
	Kunde->setPostleitzahl(Postleitzahl);
	LOGGING("Die Postleitzahl wurde erfolgreich ge�ndert", "OK");
	return Kunde;
}
CUSTOMER* Kundenwohnorts�nderung(CUSTOMER *Kunde, char* _Wohnort) {

	if (Kunde == NULL) {
		LOGGING("Es existiert kein Kunde, dessen Wohnort ge�ndert werden k�nnte", "ERROR");
		return NULL;
	}
	
	if (_Wohnort == "") {
		LOGGING("Es wurden keine �nderungen eingegeben", "ERROR");
		return Kunde;
	}

	string Wohnort(_Wohnort);
	Kunde->setWohnort(Wohnort);
	LOGGING("Der Wohnort wurde erfolgreich ge�ndert", "OK");
	return Kunde;
}
CUSTOMER* Kundentelefon�nderung(CUSTOMER *Kunde, char* _Telefon) {

	if (Kunde == NULL) {
		LOGGING("Es existiert kein Kunde, dessen Telefonnummer ge�ndert werden k�nnte", "ERROR");
		return NULL;
	}
	
	if (_Telefon == "") {
		LOGGING("Es wurden keine �nderungen eingegeben", "ERROR");
		return Kunde;
	}

	string Telefon(_Telefon);
	Kunde->setTelefon(Telefon);
	LOGGING("Die Telefonnummer wurde erfolgreich ge�ndert", "OK");
	return Kunde;
}

//Die Funktion Kundeentfernen entfernt mithilfe von delete den �bergebenen Kunden
void Kundeentfernen(CUSTOMER* Kunde) {
	//BAD
	if (typeid(Kunde) != typeid(CUSTOMER*)) {

		LOGGING("\nDer �bergebene Parameter ist kein Customer.", "ERROR");
		return;
	}
	
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
		LOGGING("Das SparKonto wurde erfolgreich erstellt.", "OK");
		return Konto;
	}
	if (verf�geranzahl == 2) {
		Konto->setVerf�ger(Kunde);
		CUSTOMER* optKunde1 = NeuerKunde("Test", "Test", "Test", "Test", "Test", "Test", "Test");
		Konto->setoptVerf�ger1(optKunde1);
		LOGGING("Das SparKonto wurde erfolgreich erstellt.", "OK");
		return Konto;
	}
	if (verf�geranzahl == 3) {
		Konto->setVerf�ger(Kunde);
		CUSTOMER* optKunde1 = NeuerKunde("Test", "Test", "Test", "Test", "Test", "Test", "Test");
		CUSTOMER* optKunde2 = NeuerKunde("Test", "Test", "Test", "Test", "Test", "Test", "Test");
		Konto->setoptVerf�ger1(optKunde1);
		Konto->setoptVerf�ger2(optKunde2);
		LOGGING("Das SparKonto wurde erfolgreich erstellt.", "OK");
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
		LOGGING("Das SparKonto wurde erfolgreich erstellt.", "OK");
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
		LOGGING("Das KreditKonto wurde erfolgreich erstellt.", "OK");
		return Konto;
	}
	if (verf�geranzahl == 2) {
		Konto->setVerf�ger(Kunde);
		CUSTOMER* optKunde1 = NeuerKunde("Test", "Test", "Test", "Test", "Test", "Test", "Test");
		Konto->setoptVerf�ger1(optKunde1);
		LOGGING("Das KreditKonto wurde erfolgreich erstellt.", "OK");
		return Konto;
	}
	if (verf�geranzahl == 3) {
		Konto->setVerf�ger(Kunde);
		CUSTOMER* optKunde1 = NeuerKunde("Test", "Test", "Test", "Test", "Test", "Test", "Test");
		CUSTOMER* optKunde2 = NeuerKunde("Test", "Test", "Test", "Test", "Test", "Test", "Test");
		Konto->setoptVerf�ger1(optKunde1);
		Konto->setoptVerf�ger2(optKunde2);
		LOGGING("Das KreditKonto wurde erfolgreich erstellt.", "OK");
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
		LOGGING("Das KreditKonto wurde erfolgreich erstellt.", "OK");
		return Konto;
	}
};

//Die Funktion Sparkontoentfernen entfernt das �bergebene SparKonto mit der Funktion delete
void Sparkontoentfernen(SPARKONTO* Konto) {
	
	if (Konto == NULL) {
		LOGGING("Das �bergebene Konto existiert nicht.", "ERROR");
		return;
	}
	delete Konto;
	LOGGING("Das Konto wurde erfolgreich entfernt.", "OK");
}
//Die Funktion Kreditkontoentfernen entfernt das �bergebene KreditKonto mit der Funktion delete
void Kreditkontoentfernen(KREDITKONTO* Konto) {
	
	if (Konto == NULL) {
		LOGGING("Das �bergebene Konto existiert nicht", "ERROR");
		return;
	}
	delete Konto;
	LOGGING("Das Konto wurde erfolgreich entfernt.", "OK");
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
