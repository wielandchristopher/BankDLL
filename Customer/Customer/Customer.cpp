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
//Mit der Funktion Kundendatenänderung können fast alle Daten (Geburtsdatum wird sich nie ändern) eines bestehenden Kunden geändert werden.

CUSTOMER* Kundenvornamenänderung(CUSTOMER *Kunde, char* _Vorname) {

	if (Kunde == NULL) {
		LOGGING("Es existiert kein Kunde, dessen Vorname geändert werden könnte", "ERROR");
		return NULL;
	}

	if (_Vorname == "") {
		LOGGING("Es wurden keine Änderungen eingegeben", "ERROR");
		return Kunde;
	}

	string Vorname(_Vorname);
	Kunde->setVorname(Vorname);
	LOGGING("Der Vorname wurde erfolgreich geändert","OK");
	return Kunde;
}
CUSTOMER* Kundennachnamenänderung(CUSTOMER *Kunde, char* _Nachname) {
	
	if (Kunde == NULL) {
		LOGGING("Es existiert kein Kunde, dessen Nachname geändert werden könnte", "ERROR");
		return NULL;
	}

	if (_Nachname == "") {
		LOGGING("Es wurden keine Änderungen eingegeben", "ERROR");
		return Kunde;
	}

	string Nachname(_Nachname);
	Kunde->setNachname(Nachname);
	LOGGING("Der Nachname wurde erfolgreich geändert", "OK");
	return Kunde;
}
CUSTOMER* Kundenadressänderung(CUSTOMER *Kunde, char* _Adresse) {

	if (Kunde == NULL) {
		LOGGING("Es existiert kein Kunde, dessen Adresse geändert werden könnte", "ERROR");
		return NULL;
	}
	
	if (_Adresse == "") {
		LOGGING("Es wurden keine Änderungen eingegeben", "ERROR");
		return Kunde;
	}

	string Adresse(_Adresse);
	Kunde->setAdresse(Adresse);
	LOGGING("Die Adresse wurde erfolgreich geändert", "OK");
	return Kunde;
}
CUSTOMER* Kundenplzänderung(CUSTOMER *Kunde, char* _Postleitzahl) {

	if (Kunde == NULL) {
		LOGGING("Es existiert kein Kunde, dessen PLZ geändert werden könnte", "ERROR");
		return NULL;
	}
	
	if (_Postleitzahl == "") {
		LOGGING("Es wurden keine Änderungen eingegeben", "ERROR");
		return Kunde;
	}

	string Postleitzahl(_Postleitzahl);
	Kunde->setPostleitzahl(Postleitzahl);
	LOGGING("Die Postleitzahl wurde erfolgreich geändert", "OK");
	return Kunde;
}
CUSTOMER* Kundenwohnortsänderung(CUSTOMER *Kunde, char* _Wohnort) {

	if (Kunde == NULL) {
		LOGGING("Es existiert kein Kunde, dessen Wohnort geändert werden könnte", "ERROR");
		return NULL;
	}
	
	if (_Wohnort == "") {
		LOGGING("Es wurden keine Änderungen eingegeben", "ERROR");
		return Kunde;
	}

	string Wohnort(_Wohnort);
	Kunde->setWohnort(Wohnort);
	LOGGING("Der Wohnort wurde erfolgreich geändert", "OK");
	return Kunde;
}
CUSTOMER* Kundentelefonänderung(CUSTOMER *Kunde, char* _Telefon) {

	if (Kunde == NULL) {
		LOGGING("Es existiert kein Kunde, dessen Telefonnummer geändert werden könnte", "ERROR");
		return NULL;
	}
	
	if (_Telefon == "") {
		LOGGING("Es wurden keine Änderungen eingegeben", "ERROR");
		return Kunde;
	}

	string Telefon(_Telefon);
	Kunde->setTelefon(Telefon);
	LOGGING("Die Telefonnummer wurde erfolgreich geändert", "OK");
	return Kunde;
}

//Die Funktion Kundeentfernen entfernt mithilfe von delete den übergebenen Kunden
void Kundeentfernen(CUSTOMER* Kunde) {
	//BAD
	if (typeid(Kunde) != typeid(CUSTOMER*)) {

		LOGGING("\nDer übergebene Parameter ist kein Customer.", "ERROR");
		return;
	}
	
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
		LOGGING("Das SparKonto wurde erfolgreich erstellt.", "OK");
		return Konto;
	}
	if (verfügeranzahl == 2) {
		Konto->setVerfüger(Kunde);
		CUSTOMER* optKunde1 = NeuerKunde("Test", "Test", "Test", "Test", "Test", "Test", "Test");
		Konto->setoptVerfüger1(optKunde1);
		LOGGING("Das SparKonto wurde erfolgreich erstellt.", "OK");
		return Konto;
	}
	if (verfügeranzahl == 3) {
		Konto->setVerfüger(Kunde);
		CUSTOMER* optKunde1 = NeuerKunde("Test", "Test", "Test", "Test", "Test", "Test", "Test");
		CUSTOMER* optKunde2 = NeuerKunde("Test", "Test", "Test", "Test", "Test", "Test", "Test");
		Konto->setoptVerfüger1(optKunde1);
		Konto->setoptVerfüger2(optKunde2);
		LOGGING("Das SparKonto wurde erfolgreich erstellt.", "OK");
		return Konto;
	}
	if (verfügeranzahl == 4) {
		Konto->setVerfüger(Kunde);
		CUSTOMER* optKunde1 = NeuerKunde("Test", "Test", "Test", "Test", "Test", "Test", "Test");
		CUSTOMER* optKunde2 = NeuerKunde("Test", "Test", "Test", "Test", "Test", "Test", "Test");
		CUSTOMER* optKunde3 = NeuerKunde("Test", "Test", "Test", "Test", "Test", "Test", "Test");
		Konto->setoptVerfüger1(optKunde1);
		Konto->setoptVerfüger2(optKunde2);
		Konto->setoptVerfüger3(optKunde3);
		LOGGING("Das SparKonto wurde erfolgreich erstellt.", "OK");
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
		LOGGING("Das KreditKonto wurde erfolgreich erstellt.", "OK");
		return Konto;
	}
	if (verfügeranzahl == 2) {
		Konto->setVerfüger(Kunde);
		CUSTOMER* optKunde1 = NeuerKunde("Test", "Test", "Test", "Test", "Test", "Test", "Test");
		Konto->setoptVerfüger1(optKunde1);
		LOGGING("Das KreditKonto wurde erfolgreich erstellt.", "OK");
		return Konto;
	}
	if (verfügeranzahl == 3) {
		Konto->setVerfüger(Kunde);
		CUSTOMER* optKunde1 = NeuerKunde("Test", "Test", "Test", "Test", "Test", "Test", "Test");
		CUSTOMER* optKunde2 = NeuerKunde("Test", "Test", "Test", "Test", "Test", "Test", "Test");
		Konto->setoptVerfüger1(optKunde1);
		Konto->setoptVerfüger2(optKunde2);
		LOGGING("Das KreditKonto wurde erfolgreich erstellt.", "OK");
		return Konto;
	}
	if (verfügeranzahl == 4) {
		Konto->setVerfüger(Kunde);
		CUSTOMER* optKunde1 = NeuerKunde("Test", "Test", "Test", "Test", "Test", "Test", "Test");
		CUSTOMER* optKunde2 = NeuerKunde("Test", "Test", "Test", "Test", "Test", "Test", "Test");
		CUSTOMER* optKunde3 = NeuerKunde("Test", "Test", "Test", "Test", "Test", "Test", "Test");
		Konto->setoptVerfüger1(optKunde1);
		Konto->setoptVerfüger2(optKunde2);
		Konto->setoptVerfüger3(optKunde3);
		LOGGING("Das KreditKonto wurde erfolgreich erstellt.", "OK");
		return Konto;
	}
};

//Die Funktion Sparkontoentfernen entfernt das übergebene SparKonto mit der Funktion delete
void Sparkontoentfernen(SPARKONTO* Konto) {
	
	if (Konto == NULL) {
		LOGGING("Das übergebene Konto existiert nicht.", "ERROR");
		return;
	}
	delete Konto;
	LOGGING("Das Konto wurde erfolgreich entfernt.", "OK");
}
//Die Funktion Kreditkontoentfernen entfernt das übergebene KreditKonto mit der Funktion delete
void Kreditkontoentfernen(KREDITKONTO* Konto) {
	
	if (Konto == NULL) {
		LOGGING("Das übergebene Konto existiert nicht", "ERROR");
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
