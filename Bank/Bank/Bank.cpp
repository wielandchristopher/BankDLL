#include "Bank.h"
#include <string>
#include <time.h>

using namespace std;
FILE* buchungsfile;
FILE* logfile;

//generateKtnr erstellt eine Kontonummer und iteriert immer um 1 hoch
int generateKtnnr() {

	static int Kontonummernpool = 10000000;

	Kontonummernpool++;
	return Kontonummernpool;
}

class CUSTOMER {
public:

	//Getter und Setter der Kundendaten
	char* CUSTOMER::getVorname() {
		return Vorname;
	};
	void CUSTOMER::setVorname(char* _Vorname) {
		this->Vorname = _Vorname;
	};
	char* CUSTOMER::getNachname() {
		return Nachname;
	};
	void CUSTOMER::setNachname(char* _Nachname) {
		this->Nachname = _Nachname;
	};
	char* CUSTOMER::getGeburtsdatum() {
		return Geburtsdatum;
	};
	void CUSTOMER::setGeburtsdatum(char* _Geburtsdatum) {
		this->Geburtsdatum = _Geburtsdatum;
	};
	char* CUSTOMER::getWohnort() {
		return Wohnort;
	};
	void CUSTOMER::setWohnort(char* _Wohnort) {
		this->Wohnort = _Wohnort;
	};
	char* CUSTOMER::getAdresse() {
		return Adresse;
	};
	void CUSTOMER::setAdresse(char* _Adresse) {
		this->Adresse = _Adresse;
	};
	char* CUSTOMER::getTelefon() {
		return Telefon;
	};
	void CUSTOMER::setTelefon(char* _Telefon) {
		this->Telefon = _Telefon;
	};
	//Typidentifizierer
	char* getClassId() {

		return customer;
	};

private:
	char* customer = "customer";
	char* Vorname = "";
	char* Nachname = "";
	char* Geburtsdatum = "";
	char* Adresse = "";
	char* Wohnort = "";
	char* Telefon = "";
};
class SPARKONTO {
public:
	SPARKONTO::SPARKONTO()
	{
		this->sparkonto = "sparkonto";
		setKontonummer(generateKtnnr());
		this->Kontostand = 0;
		this->Kontoverfüger = NULL;
		this->optKontoverfüger1 = NULL;
		this->optKontoverfüger2 = NULL;
		this->optKontoverfüger3 = NULL;

	}
	
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
	int SPARKONTO::getKontonummer() {
		return Kontonummer;
	}
	void SPARKONTO::setKontonummer(int _Kontonummer) {
		this->Kontonummer = _Kontonummer;
	}
	//Typidentifizierer
	char* SPARKONTO::getClassId() {

		return sparkonto;
	}

private:
	char* sparkonto;
	int Kontonummer;
	double Kontostand;
	CUSTOMER* Kontoverfüger;
	CUSTOMER* optKontoverfüger1;
	CUSTOMER* optKontoverfüger2;
	CUSTOMER* optKontoverfüger3;
};
class KREDITKONTO {
public:
	KREDITKONTO::KREDITKONTO()
	{
		this->kreditkonto = "kreditkonto";
		setKontonummer(generateKtnnr());
		this->Kontostand = 0;
		this->Kontoverfüger = NULL;
		this->optKontoverfüger1 = NULL;
		this->optKontoverfüger2 = NULL;
		this->optKontoverfüger3 = NULL;

	}
	
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
	int KREDITKONTO::getKontonummer() {
		return Kontonummer;
	}
	void KREDITKONTO::setKontonummer(int _Kontonummer) {
		this->Kontonummer = _Kontonummer;
	}
	//Typidentifizierer
	char* getClassId() {

		return kreditkonto;
	}

private:
	char* kreditkonto;
	int Kontonummer;
	double Kontostand;
	CUSTOMER* Kontoverfüger;
	CUSTOMER* optKontoverfüger1;
	CUSTOMER* optKontoverfüger2;
	CUSTOMER* optKontoverfüger3;
};
class KONTOAUSZUG {
public:
	KONTOAUSZUG::KONTOAUSZUG()
	{

	}

};
class UEBERWEISUNG
{
public:
	UEBERWEISUNG::UEBERWEISUNG()
	{
		this->betrag = 0;
		this->empfaengername = "";
		this->kontonummer = 0;
		this->kontostand = 0;
		this->verwendungszweck = "";

	}

	char* UEBERWEISUNG::getempfaengername() {
		return empfaengername;
	}
	void UEBERWEISUNG::setempfaengername(char* empfänger) {
		empfaengername = empfänger;
	}
	char* UEBERWEISUNG::getVerwendungszweck() {
		return verwendungszweck;
	}
	void UEBERWEISUNG::setVerwendungszweck(char* verwendung) {
		verwendungszweck = verwendung;
	}
	double UEBERWEISUNG::getBetrag() {
		return betrag;
	}
	void UEBERWEISUNG::setBetrag(double betrg) {
		betrag = betrg;
	}
	double UEBERWEISUNG::getkontostand() {
		return kontostand;
	}
	void UEBERWEISUNG::setkontostand(double betrg) {
		kontostand = betrg;
	}
	int UEBERWEISUNG::getkontonummer() {
		return kontonummer;
	}
	void UEBERWEISUNG::setkontonummer(int kntnr) {
		kontonummer = kntnr;
	}

private:
	double betrag;
	double kontostand;
	int kontonummer;
	char* empfaengername;
	char* verwendungszweck;
};

string time_to_string() {

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

	fopen_s(&logfile, "Customer_log.txt", "a");
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
void BUCHUNGEN(char* Buchungstext, char* LEVEL) {

	char *Buchung = Buchungstext;
	string stringtime = time_to_string();
	const char *time = stringtime.c_str();
	char *lvl = LEVEL;

	fopen_s(&buchungsfile, "Buchungen.txt", "a");
	if (buchungsfile == NULL)
	{
		printf("Die Abbuchungsdatei konnte nicht erstellt werden");
	}

	//Hier soll noch die Zeit drinnen stehen 
	fprintf(buchungsfile, time);
	fprintf(buchungsfile, " - ");
	fprintf(buchungsfile, lvl);
	fprintf(buchungsfile, ": ");
	fprintf(buchungsfile, Buchung);
	fprintf(buchungsfile, "\n");

	fclose(buchungsfile);

}

//NeuerKunde legt einen neuen Kunden an 
//Es werden 6 Parameter in der Reihenfolge angegeben: Vorname, Nachname, Geburtsdatum, Adresse, Wohnort, Telefon
CUSTOMER* NeuerKunde(char* _Vorname, char* _Nachname, char* _Geburtsdatum, char* _Adresse, char* _Wohnort, char* _Telefon) {

	string Vorname(_Vorname);
	string Nachname(_Nachname);
	string Geburtsdatum(_Geburtsdatum);
	string Adresse(_Adresse);
	string Wohnort(_Wohnort);
	string Telefon(_Telefon);

	CUSTOMER *Kunde = new CUSTOMER();

	Kunde->setVorname(_Vorname);
	Kunde->setNachname(_Nachname);
	Kunde->setGeburtsdatum(_Geburtsdatum);
	Kunde->setAdresse(_Adresse);
	Kunde->setWohnort(_Wohnort);
	Kunde->setTelefon(_Telefon);

	LOGGING("Der Kunde wurde erfolgreich angelegt.", "OK");

	return Kunde;
}
//Mit der Funktion Kundendatenänderung können fast alle Daten (Geburtsdatum wird sich nie ändern) eines bestehenden Kunden geändert werden.

void Kundenvornamenänderung(CUSTOMER *Kunde, char* _Vorname) {

	if (Kunde == NULL) {
		LOGGING("Es existiert kein Kunde, dessen Vorname geändert werden könnte.", "ERROR");
		return;
	}
	if (Kunde->getClassId() != "customer") {
		LOGGING("Es wurde kein Kunde übergeben.", "ERROR");
		return;
	}
	if (_Vorname == "") {
		LOGGING("Es wurden keine Änderungen eingegeben.", "ERROR");
		return;
	}

	Kunde->setVorname(_Vorname);
	LOGGING("Der Vorname wurde erfolgreich geändert.", "OK");
	return;
}
void Kundennachnamenänderung(CUSTOMER *Kunde, char* _Nachname) {

	if (Kunde == NULL) {
		LOGGING("Es existiert kein Kunde, dessen Nachname geändert werden könnte.", "ERROR");
		return;
	}

	if (Kunde->getClassId() != "customer") {
		LOGGING("Es wurde kein Kunde übergeben.", "ERROR");
		return;
	}

	if (_Nachname == "") {
		LOGGING("Es wurden keine Änderungen eingegeben.", "ERROR");
		return;
	}

	string Nachname(_Nachname);
	Kunde->setNachname(_Nachname);
	LOGGING("Der Nachname wurde erfolgreich geändert.", "OK");
	return;
}
void Kundenadressänderung(CUSTOMER *Kunde, char* _Adresse) {

	if (Kunde == NULL) {
		LOGGING("Es existiert kein Kunde, dessen Adresse geändert werden könnte.", "ERROR");
		return;
	}

	if (Kunde->getClassId() != "customer") {
		LOGGING("Es wurde kein Kunde übergeben.", "ERROR");
		return;
	}


	if (_Adresse == "") {
		LOGGING("Es wurden keine Änderungen eingegeben.", "ERROR");
		return;
	}

	string Adresse(_Adresse);
	Kunde->setAdresse(_Adresse);
	LOGGING("Die Adresse wurde erfolgreich geändert.", "OK");
	return;
}
void Kundenwohnortsänderung(CUSTOMER *Kunde, char* _Wohnort) {

	if (Kunde == NULL) {
		LOGGING("Es existiert kein Kunde, dessen Wohnort geändert werden könnte.", "ERROR");
		return;
	}

	if (Kunde->getClassId() != "customer") {
		LOGGING("Es wurde kein Kunde übergeben.", "ERROR");
		return;
	}


	if (_Wohnort == "") {
		LOGGING("Es wurden keine Änderungen eingegeben.", "ERROR");
		return;
	}

	string Wohnort(_Wohnort);
	Kunde->setWohnort(_Wohnort);
	LOGGING("Der Wohnort wurde erfolgreich geändert.", "OK");
	return;
}
void Kundentelefonänderung(CUSTOMER *Kunde, char* _Telefon) {

	if (Kunde == NULL) {
		LOGGING("Es existiert kein Kunde, dessen Telefonnummer geändert werden könnte.", "ERROR");
		return;
	}

	if (Kunde->getClassId() != "customer") {
		LOGGING("Es wurde kein Kunde übergeben.", "ERROR");
		return;
	}


	if (_Telefon == "") {
		LOGGING("Es wurden keine Änderungen eingegeben.", "ERROR");
		return;
	}

	string Telefon(_Telefon);
	Kunde->setTelefon(_Telefon);
	LOGGING("Die Telefonnummer wurde erfolgreich geändert.", "OK");
	return;
}
void Kundendatenabfrage(CUSTOMER * Kunde) {

	LOGGING("Das ist der Vorname des übergebenen Kunden:", "OK");
	LOGGING(Kunde->getVorname(), "OK");
	LOGGING("Das ist der Nachname des übergebenen Kunden:", "OK");
	LOGGING(Kunde->getNachname(), "OK");
	LOGGING("Das ist das Geburtsdatum des übergebenen Kunden:", "OK");
	LOGGING(Kunde->getGeburtsdatum(), "OK");
	LOGGING("Das ist die Adresse des übergebenen Kunden:", "OK");
	LOGGING(Kunde->getAdresse(), "OK");
	LOGGING("Das ist der Wohnort des übergebenen Kunden:", "OK");
	LOGGING(Kunde->getWohnort(), "OK");
	LOGGING("Das ist die Telefonnummer des übergebenen Kunden:", "OK");
	LOGGING(Kunde->getTelefon(), "OK");
}
//Die Funktion Kundeentfernen entfernt mithilfe von delete den übergebenen Kunden
void Kundeentfernen(CUSTOMER *Kunde) {

	if (Kunde->getClassId() != "customer") {
		LOGGING("Es wurde kein Kunde übergeben.", "ERROR");
		return;
	}

	if (Kunde == NULL) {
		LOGGING("Der übergebene Kunde existiert nicht oder ist NULL.", "OK");
		return;
	}
	else {
		delete Kunde;
		LOGGING("Der Kunde wurde erfolgreich entfernt.", "OK");
	}
}

//Die Funktionen für ein neues Konto erstellt ein neues Kredit-/Sparkonto und weißt das dem übergebenen Kunden zu. der 2. parameter lässt zu, 
//dass mehrere Kunden ein Konto besitzen können. Es können maximal 4 Kunden über ein Konto verfügen. Übergeben wird hier 1-4. 
SPARKONTO* NeuesSparkonto(CUSTOMER* Kunde) {

	if (Kunde == NULL) {
		LOGGING("Es existiert kein Kunde, welcher auf das Konto zugewiesen werden kann.", "ERROR");
		return NULL;
	}
	if (Kunde->getClassId() != "customer") {
		LOGGING("Es wurde kein Kunde übergeben.", "ERROR");
		return NULL;
	}
	SPARKONTO *Konto = new SPARKONTO();
	int SparKontonummer = Konto->getKontonummer();
	Konto->setVerfüger(Kunde);
	LOGGING("Das SparKonto wurde erfolgreich erstellt.", "OK");

	return Konto;
};
SPARKONTO* NeuesSparkonto2(CUSTOMER* Kunde, CUSTOMER* Kunde2) {

	if ((Kunde == NULL) || (Kunde2 == NULL)) {
		LOGGING("Es existiert kein Kunde, welcher auf das Konto zugewiesen werden kann.", "ERROR");
		return NULL;
	}

	if ((Kunde->getClassId() != "customer") || (Kunde2->getClassId() != "customer")) {
		LOGGING("Es wurde kein Kunde übergeben.", "ERROR");
		return NULL;
	}

	SPARKONTO *Konto = new SPARKONTO();
	int SparKontonummer = Konto->getKontonummer();

	Konto->setVerfüger(Kunde);
	Konto->setoptVerfüger1(Kunde2);
	LOGGING("Das SparKonto wurde erfolgreich erstellt.", "OK");

	return Konto;
};
SPARKONTO* NeuesSparkonto3(CUSTOMER* Kunde, CUSTOMER* Kunde2, CUSTOMER* Kunde3) {

	if ((Kunde == NULL) || (Kunde2 == NULL) || (Kunde3 == NULL)) {
		LOGGING("Es existiert kein Kunde, welcher auf das Konto zugewiesen werden kann.", "ERROR");
		return NULL;
	}
	if ((Kunde->getClassId() != "customer") || (Kunde2->getClassId() != "customer") || (Kunde3->getClassId() != "customer")) {
		LOGGING("Es wurde kein Kunde übergeben.", "ERROR");
		return NULL;
	}

	SPARKONTO *Konto = new SPARKONTO();
	int SparKontonummer = Konto->getKontonummer();

	Konto->setVerfüger(Kunde);
	Konto->setoptVerfüger1(Kunde2);
	Konto->setoptVerfüger2(Kunde3);
	LOGGING("Das SparKonto wurde erfolgreich erstellt.", "OK");

	return Konto;
};
SPARKONTO* NeuesSparkonto4(CUSTOMER* Kunde, CUSTOMER* Kunde2, CUSTOMER* Kunde3, CUSTOMER* Kunde4) {

	if ((Kunde == NULL) || (Kunde2 == NULL) || (Kunde3 == NULL) || (Kunde4 == NULL)) {
		LOGGING("Es existiert kein Kunde, welcher auf das Konto zugewiesen werden kann.", "ERROR");
		return NULL;
	}
	if ((Kunde->getClassId() != "customer") || (Kunde2->getClassId() != "customer") || (Kunde3->getClassId() != "customer") || (Kunde4->getClassId() != "customer")) {
		LOGGING("Es wurde kein Kunde übergeben.", "ERROR");
		return NULL;
	}

	SPARKONTO *Konto = new SPARKONTO();
	int SparKontonummer = Konto->getKontonummer();

	Konto->setVerfüger(Kunde);
	Konto->setoptVerfüger1(Kunde2);
	Konto->setoptVerfüger2(Kunde3);
	Konto->setoptVerfüger3(Kunde4);
	LOGGING("Das SparKonto wurde erfolgreich erstellt.", "OK");

	return Konto;
};
KREDITKONTO* NeuesKreditkonto(CUSTOMER* Kunde) {

	if (Kunde == NULL) {
		LOGGING("\nEs existiert kein Kunde, welcher auf das Konto zugewiesen werden kann", "ERROR");
		return NULL;
	}

	if (Kunde->getClassId() != "customer") {
		LOGGING("Es wurde kein Kunde übergeben.", "ERROR");
		return NULL;
	}

	KREDITKONTO *Konto = new KREDITKONTO();
	int KreditKontonummer = Konto->getKontonummer();
	Konto->setVerfüger(Kunde);
	LOGGING("Das KreditKonto wurde erfolgreich erstellt.", "OK");

	return Konto;
};
KREDITKONTO* NeuesKreditkonto2(CUSTOMER* Kunde, CUSTOMER* Kunde2) {

	if ((Kunde == NULL) || (Kunde2 == NULL)) {
		LOGGING("Es existiert kein Kunde, welcher auf das Konto zugewiesen werden kann.", "ERROR");
		return NULL;
	}
	if ((Kunde->getClassId() != "customer") || (Kunde2->getClassId() != "customer")) {
		LOGGING("Es wurde kein Kunde übergeben.", "ERROR");
		return NULL;
	}

	KREDITKONTO *Konto = new KREDITKONTO();
	int SparKontonummer = Konto->getKontonummer();

	Konto->setVerfüger(Kunde);
	Konto->setoptVerfüger1(Kunde2);
	LOGGING("Das KreditKonto wurde erfolgreich erstellt.", "OK");

	return Konto;
};
KREDITKONTO* NeuesKreditkonto3(CUSTOMER* Kunde, CUSTOMER* Kunde2, CUSTOMER* Kunde3) {

	if ((Kunde == NULL) || (Kunde2 == NULL) || (Kunde3 == NULL)) {
		LOGGING("Es existiert kein Kunde, welcher auf das Konto zugewiesen werden kann.", "ERROR");
		return NULL;
	}
	if ((Kunde->getClassId() != "customer") || (Kunde2->getClassId() != "customer") || (Kunde3->getClassId() != "customer")) {
		LOGGING("Es wurde kein Kunde übergeben.", "ERROR");
		return NULL;
	}

	KREDITKONTO *Konto = new KREDITKONTO();
	int SparKontonummer = Konto->getKontonummer();

	Konto->setVerfüger(Kunde);
	Konto->setoptVerfüger1(Kunde2);
	Konto->setoptVerfüger2(Kunde3);
	LOGGING("Das KreditKonto wurde erfolgreich erstellt.", "OK");

	return Konto;
};
KREDITKONTO* NeuesKreditkonto4(CUSTOMER* Kunde, CUSTOMER* Kunde2, CUSTOMER* Kunde3, CUSTOMER* Kunde4) {

	if ((Kunde == NULL) || (Kunde2 == NULL) || (Kunde3 == NULL) || (Kunde4 == NULL)) {
		LOGGING("Es existiert kein Kunde, welcher auf das Konto zugewiesen werden kann.", "ERROR");
		return NULL;
	}
	if ((Kunde->getClassId() != "customer") || (Kunde2->getClassId() != "customer") || (Kunde3->getClassId() != "customer") || (Kunde4->getClassId() != "customer")) {
		LOGGING("Es wurde kein Kunde übergeben.", "ERROR");
		return NULL;
	}

	KREDITKONTO *Konto = new KREDITKONTO();
	int SparKontonummer = Konto->getKontonummer();

	Konto->setVerfüger(Kunde);
	Konto->setoptVerfüger1(Kunde2);
	Konto->setoptVerfüger2(Kunde3);
	Konto->setoptVerfüger3(Kunde4);
	LOGGING("Das KreditKonto wurde erfolgreich erstellt.", "OK");

	return Konto;
};
//Die Funktion Sparkontoentfernen entfernt das übergebene SparKonto mit der Funktion delete
void Sparkontoentfernen(SPARKONTO* Konto) {

	if (Konto->getClassId() != "sparkonto") {
		LOGGING("Es wurde kein SparKonto übergeben.", "ERROR");
		return;
	}

	if (Konto == NULL) {
		LOGGING("Das übergebene Konto existiert nicht.", "ERROR");
		return;
	}
	delete Konto;
	LOGGING("Das Konto wurde erfolgreich entfernt.", "OK");
}
//Die Funktion Kreditkontoentfernen entfernt das übergebene KreditKonto mit der Funktion delete
void Kreditkontoentfernen(KREDITKONTO* Konto) {

	if (Konto->getClassId() != "kreditkonto") {
		LOGGING("Es wurde kein KreditKonto übergeben.", "ERROR");
		return;
	}

	if (Konto == NULL) {
		LOGGING("Das übergebene Konto existiert nicht", "ERROR");
		return;
	}
	delete Konto;
	LOGGING("Das Konto wurde erfolgreich entfernt.", "OK");
}
//Funktion, um die Getätigte Buchung/Überweisung in ein Logfile zu schreiben "Buchungen.txt"
void Buchen(KREDITKONTO* zielkonto, char* verwendungszweck, double betrag, int art) {

	if (art == 1) {
		BUCHUNGEN("Der Betrag wurde erfolgreich eingezahlt. Unterhalb die getätigten eingaben:", "UEBERWEISUNG");
		BUCHUNGEN("Momentaner Kontostand:", "UEBERWEISUNG");
		BUCHUNGEN((char*)to_string(zielkonto->getKontostand()).c_str(), "UEBERWEISUNG");
		BUCHUNGEN("Verwendungszweck:", "UEBERWEISUNG");
		BUCHUNGEN(verwendungszweck, "UEBERWEISUNG");
		BUCHUNGEN("Betrag:", "UEBERWEISUNG");
		BUCHUNGEN((char*)to_string(betrag).c_str(), "UEBERWEISUNG");
	}
	else if (art == 2) {
		BUCHUNGEN("Der Betrag wurde erfolgreich eingezahlt. Unterhalb die getätigten eingaben:", "ABHEBUNG");
		BUCHUNGEN("Momentaner Kontostand:", "ABHEBUNG");
		BUCHUNGEN((char*)to_string(zielkonto->getKontostand()).c_str(), "ABHEBUNG");
		BUCHUNGEN("Betrag:", "ABHEBUNG");
		BUCHUNGEN((char*)to_string(betrag).c_str(), "ABHEBUNG");
	}
	else if (art == 3) {
		BUCHUNGEN("Der Betrag wurde erfolgreich eingezahlt. Unterhalb die getätigten eingaben:", "EINZAHLUNG");
		BUCHUNGEN("Momentaner Kontostand:", "EINZAHLUNG");
		BUCHUNGEN((char*)to_string(zielkonto->getKontostand()).c_str(), "EINZAHLUNG");
		BUCHUNGEN("Verwendungszweck:", "EINZAHLUNG");
		BUCHUNGEN(verwendungszweck, "EINZAHLUNG");
		BUCHUNGEN("Betrag:", "EINZAHLUNG");
		BUCHUNGEN((char*)to_string(betrag).c_str(), "EINZAHLUNG");
	}
}
//Funktionen zum Überweisen, Einzahlen und Abheben
void doAbheben(KREDITKONTO* zielkonto, double betrag) {

	double newKontostand = zielkonto->getKontostand() - betrag;
	zielkonto->setKontostand(newKontostand);
	char* verwendungszweck = "";

	LOGGING("Eine Abhebung wurde getaetigt.", "OK");
	Buchen(zielkonto, verwendungszweck, betrag, 2);
}
void doEinzahlen(KREDITKONTO* zielkonto, char* verwendungszweck, double betrag) {

	double newKontostand = zielkonto->getKontostand() + betrag;
	zielkonto->setKontostand(newKontostand);

	LOGGING("Eine Einzahlung wurde getaetigt.", "OK");
	Buchen(zielkonto, verwendungszweck, betrag, 3);
}
UEBERWEISUNG* NeueUeberweisung(KREDITKONTO* zielkonto, double betrag, char* verwendungszweck) {

	string Verfügervorname = zielkonto->getVerfüger().getVorname();
	string Verfügernachname = zielkonto->getVerfüger().getNachname();
	string Verfügername = Verfügervorname + Verfügernachname;
	char* cVerfügername = (char*)Verfügername.c_str();

	double newKontostand = zielkonto->getKontostand() + betrag;
	zielkonto->setKontostand(newKontostand);

	UEBERWEISUNG* ueberweisung = new UEBERWEISUNG();
	ueberweisung->setempfaengername(cVerfügername);
	ueberweisung->setkontonummer(zielkonto->getKontonummer());
	ueberweisung->setkontostand(newKontostand);
	ueberweisung->setVerwendungszweck(verwendungszweck);
	ueberweisung->setBetrag(betrag);

	LOGGING("Eine Überweisung wurde getaetigt.", "OK");
	Buchen(zielkonto, verwendungszweck, betrag, 1);
	return ueberweisung;
}