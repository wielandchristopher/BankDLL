#include "stdafx.h"
#include "Customer.h"
#include <string>
#include <iostream>
#include <time.h>
#include <typeinfo>
#include <exception>

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
void LOGGING(char* Errortext, char* LEVEL) {

	char *Errortxt = Errortext;
	string stringtime = time_to_string();
	const char *time = stringtime.c_str();
	char *lvl = LEVEL;

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
	char* CUSTOMER::getVorname() {
		return Vorname;
	}
	void CUSTOMER::setVorname(char* _Vorname) {
		this->Vorname = _Vorname;
	}
	char* CUSTOMER::getNachname() {
		return Nachname;
	}
	void CUSTOMER::setNachname(char* _Nachname) {
		this->Nachname = _Nachname;
	}
	char* CUSTOMER::getGeburtsdatum() {
		return Geburtsdatum;
	}
	void CUSTOMER::setGeburtsdatum(char* _Geburtsdatum) {
		this->Geburtsdatum = _Geburtsdatum;
	}
	char* CUSTOMER::getWohnort() {
		return Wohnort;
	}
	void CUSTOMER::setWohnort(char* _Wohnort) {
		this->Wohnort = _Wohnort;
	}
	char* CUSTOMER::getAdresse() {
		return Adresse;
	}
	void CUSTOMER::setAdresse(char* _Adresse) {
		this->Adresse = _Adresse;
	}
	char* CUSTOMER::getPostleitzahl() {
		return Postleitzahl;
	}
	void CUSTOMER::setPostleitzahl(char* _Postleitzahl) {
		this->Postleitzahl = _Postleitzahl;
	}
	char* CUSTOMER::getTelefon() {
		return Telefon;
	}
	void CUSTOMER::setTelefon(char* _Telefon) {
		this->Telefon = _Telefon;
	}
	//Typidentifizierer
	string getClassId() {
		
		return customer;
	}

private:
	string customer = "customer";
	char* Vorname;
	char* Nachname;
	char* Geburtsdatum;
	char* Adresse;
	char* Postleitzahl;
	char* Wohnort;
	char* Telefon;
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
	int SPARKONTO::getKontonummer() {
		return Kontonummer;
	}
	void SPARKONTO::setKontonummer(int _Kontonummer) {
		this->Kontonummer = _Kontonummer;
	}
	//Typidentifizierer
	string getClassId() {
		
		return sparkonto;
	}

	//Konstruktor zur Erstellung des Kontos mit Kontonummer 
	SPARKONTO();

private:
	string sparkonto = "sparkonto";
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
	int KREDITKONTO::getKontonummer() {
		return Kontonummer;
	}
	void KREDITKONTO::setKontonummer(int _Kontonummer) {
		this->Kontonummer = _Kontonummer;
	}
	//Typidentifizierer
	string getClassId() {
		
		return kreditkonto;
	}

	//Konstruktor zur Erstellung des Kontos mit Kontonummer 
	KREDITKONTO();

private:
	string kreditkonto = "kreditkonto";
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


	string Vorname(_Vorname);
	string Nachname(_Nachname);
	string Geburtsdatum(_Geburtsdatum);
	string Adresse(_Adresse);
	string Postleitzahl(_Postleitzahl);
	string Wohnort(_Wohnort);
	string Telefon(_Telefon);

	CUSTOMER *Kunde = new CUSTOMER();

	Kunde->setVorname(_Vorname);
	Kunde->setNachname(_Nachname);
	Kunde->setGeburtsdatum(_Geburtsdatum);
	Kunde->setAdresse(_Adresse);
	Kunde->setWohnort(_Wohnort);
	Kunde->setPostleitzahl(_Postleitzahl);
	Kunde->setTelefon(_Telefon);
		
	LOGGING("Der Kunde wurde erfolgreich angelegt.", "OK");

	return Kunde;
}
//Mit der Funktion Kundendaten�nderung k�nnen fast alle Daten (Geburtsdatum wird sich nie �ndern) eines bestehenden Kunden ge�ndert werden.

void Kundenvornamen�nderung(CUSTOMER *Kunde, char* _Vorname) {

	if (Kunde == NULL) {
		LOGGING("Es existiert kein Kunde, dessen Vorname ge�ndert werden k�nnte.", "ERROR");
		return;
	}
	if (Kunde->getClassId() != "customer") {
		LOGGING("Es wurde kein Kunde �bergeben.", "ERROR");
		return;
	}
	if (_Vorname == "") {
		LOGGING("Es wurden keine �nderungen eingegeben.", "ERROR");
		return;
	}

	Kunde->setVorname(_Vorname);
	LOGGING("Der Vorname wurde erfolgreich ge�ndert.","OK");
	return;
}
void Kundennachnamen�nderung(CUSTOMER *Kunde, char* _Nachname) {
	
	if (Kunde == NULL) {
		LOGGING("Es existiert kein Kunde, dessen Nachname ge�ndert werden k�nnte.", "ERROR");
		return;
	}
	
	if (Kunde->getClassId() != "customer") {
		LOGGING("Es wurde kein Kunde �bergeben.", "ERROR");
		return;
	}

	if (_Nachname == "") {
		LOGGING("Es wurden keine �nderungen eingegeben.", "ERROR");
		return;
	}

	string Nachname(_Nachname);
	Kunde->setNachname(_Nachname);
	LOGGING("Der Nachname wurde erfolgreich ge�ndert.", "OK");
	return;
}
void Kundenadress�nderung(CUSTOMER *Kunde, char* _Adresse) {

	if (Kunde == NULL) {
		LOGGING("Es existiert kein Kunde, dessen Adresse ge�ndert werden k�nnte.", "ERROR");
		return;
	}
	
	if (Kunde->getClassId() != "customer") {
		LOGGING("Es wurde kein Kunde �bergeben.", "ERROR");
		return;
	}

	
	if (_Adresse == "") {
		LOGGING("Es wurden keine �nderungen eingegeben.", "ERROR");
		return;
	}

	string Adresse(_Adresse);
	Kunde->setAdresse(_Adresse);
	LOGGING("Die Adresse wurde erfolgreich ge�ndert.", "OK");
	return;
}
void Kundenplz�nderung(CUSTOMER *Kunde, char* _Postleitzahl) {

	if (Kunde == NULL) {
		LOGGING("Es existiert kein Kunde, dessen PLZ ge�ndert werden k�nnte.", "ERROR");
		return;
	}
	if (Kunde->getClassId() != "customer") {
		LOGGING("Es wurde kein Kunde �bergeben.", "ERROR");
		return;
	}

	
	if (_Postleitzahl == "") {
		LOGGING("Es wurden keine �nderungen eingegeben.", "ERROR");
		return;
	}

	string Postleitzahl(_Postleitzahl);
	Kunde->setPostleitzahl(_Postleitzahl);
	LOGGING("Die Postleitzahl wurde erfolgreich ge�ndert.", "OK");
	return;
}
void Kundenwohnorts�nderung(CUSTOMER *Kunde, char* _Wohnort) {

	if (Kunde == NULL) {
		LOGGING("Es existiert kein Kunde, dessen Wohnort ge�ndert werden k�nnte.", "ERROR");
		return;
	}
	
	if (Kunde->getClassId() != "customer") {
		LOGGING("Es wurde kein Kunde �bergeben.", "ERROR");
		return;
	}

	
	if (_Wohnort == "") {
		LOGGING("Es wurden keine �nderungen eingegeben.", "ERROR");
		return;
	}

	string Wohnort(_Wohnort);
	Kunde->setWohnort(_Wohnort);
	LOGGING("Der Wohnort wurde erfolgreich ge�ndert.", "OK");
	return;
}
void Kundentelefon�nderung(CUSTOMER *Kunde, char* _Telefon) {

	if (Kunde == NULL) {
		LOGGING("Es existiert kein Kunde, dessen Telefonnummer ge�ndert werden k�nnte.", "ERROR");
		return;
	}
	
	if (Kunde->getClassId() != "customer") {
		LOGGING("Es wurde kein Kunde �bergeben.", "ERROR");
		return;
	}

	
	if (_Telefon == "") {
		LOGGING("Es wurden keine �nderungen eingegeben.", "ERROR");
		return;
	}

	string Telefon(_Telefon);
	Kunde->setTelefon(_Telefon);
	LOGGING("Die Telefonnummer wurde erfolgreich ge�ndert.", "OK");
	return;
}
void Kundendatenabfrage(CUSTOMER * Kunde) {

	LOGGING("Das ist der Vorname des �bergebenen Kunden:","OK");
	LOGGING(Kunde->getVorname(), "OK");
	LOGGING("Das ist der Nachname des �bergebenen Kunden:", "OK");
	LOGGING(Kunde->getNachname(), "OK");
	LOGGING("Das ist das Geburtsdatum des �bergebenen Kunden:", "OK");
	LOGGING(Kunde->getGeburtsdatum(), "OK");
	LOGGING("Das ist die Adresse des �bergebenen Kunden:", "OK");
	LOGGING(Kunde->getAdresse(), "OK");
	LOGGING("Das ist die Postleitzahl des �bergebenen Kunden:", "OK");
	LOGGING(Kunde->getPostleitzahl(), "OK");
	LOGGING("Das ist der Wohnort des �bergebenen Kunden:", "OK");
	LOGGING(Kunde->getWohnort(), "OK");
	LOGGING("Das ist die Telefonnummer des �bergebenen Kunden:", "OK");
	LOGGING(Kunde->getTelefon(), "OK");
}
//Die Funktion Kundeentfernen entfernt mithilfe von delete den �bergebenen Kunden
void Kundeentfernen(CUSTOMER *Kunde) {

	if (Kunde->getClassId() != "customer") {
		LOGGING("Es wurde kein Kunde �bergeben.", "ERROR");
		return;
	}

	if (Kunde == NULL) {		
		LOGGING("Der �bergebene Kunde existiert nicht oder ist NULL.", "OK");
		return;
	}
	else {
		delete Kunde;
		LOGGING("Der Kunde wurde erfolgreich entfernt.", "OK");
	}
}

//Die Funktionen f�r ein neues Konto erstellt ein neues Kredit-/Sparkonto und wei�t das dem �bergebenen Kunden zu. der 2. parameter l�sst zu, 
//dass mehrere Kunden ein Konto besitzen k�nnen. Es k�nnen maximal 4 Kunden �ber ein Konto verf�gen. �bergeben wird hier 1-4. 
SPARKONTO* NeuesSparkonto(CUSTOMER* Kunde) {
	
	if (Kunde == NULL) {
		LOGGING("Es existiert kein Kunde, welcher auf das Konto zugewiesen werden kann.", "ERROR");
		return NULL;
	}
	if (Kunde->getClassId() != "customer") {
		LOGGING("Es wurde kein Kunde �bergeben.", "ERROR");
		return NULL;
	}
	SPARKONTO *Konto = new SPARKONTO();
	int SparKontonummer = Konto->getKontonummer();
		Konto->setVerf�ger(Kunde);
		LOGGING("Das SparKonto wurde erfolgreich erstellt.", "OK");

return Konto;
};
SPARKONTO* NeuesSparkonto2(CUSTOMER* Kunde, CUSTOMER* Kunde2) {

	if ((Kunde == NULL) || (Kunde2 == NULL)) {
		LOGGING("Es existiert kein Kunde, welcher auf das Konto zugewiesen werden kann.", "ERROR");
		return NULL;
	}

	if ((Kunde->getClassId() != "customer") || (Kunde2->getClassId() != "customer")) {
		LOGGING("Es wurde kein Kunde �bergeben.", "ERROR");
		return NULL;
	}

	SPARKONTO *Konto = new SPARKONTO();
	int SparKontonummer = Konto->getKontonummer();

	Konto->setVerf�ger(Kunde);
	Konto->setoptVerf�ger1(Kunde2);
	LOGGING("Das SparKonto wurde erfolgreich erstellt.", "OK");
		
return Konto;
};
SPARKONTO* NeuesSparkonto3(CUSTOMER* Kunde, CUSTOMER* Kunde2, CUSTOMER* Kunde3) {

	if ((Kunde == NULL) || (Kunde2 == NULL) || (Kunde3 == NULL)) {
		LOGGING("Es existiert kein Kunde, welcher auf das Konto zugewiesen werden kann.", "ERROR");
		return NULL;
	}	
	if ((Kunde->getClassId() != "customer") || (Kunde2->getClassId() != "customer") || (Kunde3->getClassId() != "customer")) {
		LOGGING("Es wurde kein Kunde �bergeben.", "ERROR");
		return NULL;
	}

	SPARKONTO *Konto = new SPARKONTO();
	int SparKontonummer = Konto->getKontonummer();

	Konto->setVerf�ger(Kunde);
	Konto->setoptVerf�ger1(Kunde2);
	Konto->setoptVerf�ger2(Kunde3);
	LOGGING("Das SparKonto wurde erfolgreich erstellt.", "OK");

	return Konto;
};
SPARKONTO* NeuesSparkonto4(CUSTOMER* Kunde, CUSTOMER* Kunde2, CUSTOMER* Kunde3, CUSTOMER* Kunde4) {

	if ((Kunde == NULL) || (Kunde2 == NULL) || (Kunde3 == NULL) || (Kunde4 == NULL)) {
		LOGGING("Es existiert kein Kunde, welcher auf das Konto zugewiesen werden kann.", "ERROR");
		return NULL;
	}
	if ((Kunde->getClassId() != "customer") || (Kunde2->getClassId() != "customer") || (Kunde3->getClassId() != "customer") || (Kunde4->getClassId() != "customer")) {
		LOGGING("Es wurde kein Kunde �bergeben.", "ERROR");
		return NULL;
	}

	SPARKONTO *Konto = new SPARKONTO();
	int SparKontonummer = Konto->getKontonummer();

	Konto->setVerf�ger(Kunde);
	Konto->setoptVerf�ger1(Kunde2);
	Konto->setoptVerf�ger2(Kunde3);
	Konto->setoptVerf�ger3(Kunde4);
	LOGGING("Das SparKonto wurde erfolgreich erstellt.", "OK");

	return Konto;
};
KREDITKONTO* NeuesKreditkonto(CUSTOMER* Kunde) {

	if (Kunde == NULL) {
		LOGGING("\nEs existiert kein Kunde, welcher auf das Konto zugewiesen werden kann", "ERROR");
		return NULL;
	}

	if (Kunde->getClassId() != "customer") {
		LOGGING("Es wurde kein Kunde �bergeben.", "ERROR");
		return NULL;
	}

	KREDITKONTO *Konto = new KREDITKONTO();
	int KreditKontonummer = Konto->getKontonummer();
	Konto->setVerf�ger(Kunde);
	LOGGING("Das KreditKonto wurde erfolgreich erstellt.", "OK");

return Konto;
};
KREDITKONTO* NeuesKreditkonto2(CUSTOMER* Kunde, CUSTOMER* Kunde2) {

	if ((Kunde == NULL) || (Kunde2 == NULL)) {
		LOGGING("Es existiert kein Kunde, welcher auf das Konto zugewiesen werden kann.", "ERROR");
		return NULL;
	}
	if ((Kunde->getClassId() != "customer") || (Kunde2->getClassId() != "customer")) {
		LOGGING("Es wurde kein Kunde �bergeben.", "ERROR");
		return NULL;
	}

	KREDITKONTO *Konto = new KREDITKONTO();
	int SparKontonummer = Konto->getKontonummer();

	Konto->setVerf�ger(Kunde);
	Konto->setoptVerf�ger1(Kunde2);
	LOGGING("Das KreditKonto wurde erfolgreich erstellt.", "OK");

	return Konto;
};
KREDITKONTO* NeuesKreditkonto3(CUSTOMER* Kunde, CUSTOMER* Kunde2, CUSTOMER* Kunde3) {

	if ((Kunde == NULL) || (Kunde2 == NULL) || (Kunde3 == NULL)) {
		LOGGING("Es existiert kein Kunde, welcher auf das Konto zugewiesen werden kann.", "ERROR");
		return NULL;
	}
	if ((Kunde->getClassId() != "customer") || (Kunde2->getClassId() != "customer") || (Kunde3->getClassId() != "customer")) {
		LOGGING("Es wurde kein Kunde �bergeben.", "ERROR");
		return NULL;
	}

	KREDITKONTO *Konto = new KREDITKONTO();
	int SparKontonummer = Konto->getKontonummer();

	Konto->setVerf�ger(Kunde);
	Konto->setoptVerf�ger1(Kunde2);
	Konto->setoptVerf�ger2(Kunde3);
	LOGGING("Das KreditKonto wurde erfolgreich erstellt.", "OK");

	return Konto;
};
KREDITKONTO* NeuesKreditkonto4(CUSTOMER* Kunde, CUSTOMER* Kunde2, CUSTOMER* Kunde3, CUSTOMER* Kunde4) {

	if ((Kunde == NULL) || (Kunde2 == NULL) || (Kunde3 == NULL) || (Kunde4 == NULL)) {
		LOGGING("Es existiert kein Kunde, welcher auf das Konto zugewiesen werden kann.", "ERROR");
		return NULL;
	}
	if ((Kunde->getClassId() != "customer") || (Kunde2->getClassId() != "customer") || (Kunde3->getClassId() != "customer") || (Kunde4->getClassId() != "customer")) {
		LOGGING("Es wurde kein Kunde �bergeben.", "ERROR");
		return NULL;
	}

	KREDITKONTO *Konto = new KREDITKONTO();
	int SparKontonummer = Konto->getKontonummer();

	Konto->setVerf�ger(Kunde);
	Konto->setoptVerf�ger1(Kunde2);
	Konto->setoptVerf�ger2(Kunde3);
	Konto->setoptVerf�ger3(Kunde4);
	LOGGING("Das KreditKonto wurde erfolgreich erstellt.", "OK");

	return Konto;
};
//Die Funktion Sparkontoentfernen entfernt das �bergebene SparKonto mit der Funktion delete
void Sparkontoentfernen(SPARKONTO* Konto) {
	
	if (Konto->getClassId() != "sparkonto") {
		LOGGING("Es wurde kein SparKonto �bergeben.", "ERROR");
		return;
	}

	if (Konto == NULL) {
		LOGGING("Das �bergebene Konto existiert nicht.", "ERROR");
		return;
	}
	delete Konto;
	LOGGING("Das Konto wurde erfolgreich entfernt.", "OK");
}
//Die Funktion Kreditkontoentfernen entfernt das �bergebene KreditKonto mit der Funktion delete
void Kreditkontoentfernen(KREDITKONTO* Konto) {
	
	if (Konto->getClassId() != "kreditkonto") {
		LOGGING("Es wurde kein KreditKonto �bergeben.", "ERROR");
		return;
	}

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
