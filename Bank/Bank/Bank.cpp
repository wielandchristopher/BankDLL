#include "Bank.h"
#include <string>
#include <time.h>
#include <iostream>
#include "cJSON.h"

#pragma warning( disable: 4996 )

using namespace std;

/* --------- */
/* Variablen */
/* --------- */

FILE* buchungsfile;
FILE* logfile;
FILE* umrechnungsFile;
FILE* kursverwaltungsFile;
char* USER_FILE = "customer.json";
char* KREDITKONTO_FILE = "kreditkonten.json";
char* SPARKONTO_FILE = "sparkonten.json";

char* SPARKONTO_ROOT = "sparkonten";
char* KREDITKONTO_ROOT = "kreditkonten";
char* USER_ROOT = "users";
char* Kontocounterfilename = "Kontencounter.json";
char* Usercounterfilename = "Usercounter.json";

//initialisierungen
CUSTOMER* readUser(int id);
bool userExist(int id);
bool kreditkontoExist(int ktnr);
bool sparkontoExist(int ktnr);
void writeCount(int);
int readCount();
int readUserCount();
void writeUserCount(int);
void LOGGING(char* Errortext, char* LEVEL);

bool writeSparKonto(SPARKONTO*);
bool writeKreditKonto(KREDITKONTO*);
bool deleteKontoUserEntrys(cJSON *item, int ktnr);

//generateKtnr erstellt eine Kontonummer und incrementiert immer um 1 hoch
int generateKtnnr() {

	int actNr = readCount();
	actNr++;
	writeCount(actNr);

	return actNr;
}
//generateUserid erstellt eine neue UserID f�r jeden neuen User
int generateUserid() {

	int actNr = readUserCount();
	actNr++;

	writeUserCount(actNr);
	return actNr;
}


/* ----------------- */
/* Ben�tigte Klassen */
/* ----------------- */

class CUSTOMER {
public:

	//Getter / Setter
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
	int CUSTOMER::getID() {
		return id;
	};
	void CUSTOMER::setID(int _id) {
		this->id = _id;
	};
	void CUSTOMER::setKtnr1(int nr) {
		this->ktnr1 = nr;
	}
	void CUSTOMER::setKtnr2(int nr) {
		this->ktnr2 = nr;
	}
	void CUSTOMER::setKtnr3(int nr) {
		this->ktnr3 = nr;
	}
	void CUSTOMER::setKtnr4(int nr) {
		this->ktnr4 = nr;
	}
	void CUSTOMER::setKtnr5(int nr) {
		this->ktnr5 = nr;
	}
	int CUSTOMER::getKtnr1() {
		return this->ktnr1;
	}
	int CUSTOMER::getKtnr2() {
		return this->ktnr2;
	}
	int CUSTOMER::getKtnr3() {
		return this->ktnr3;
	}
	int CUSTOMER::getKtnr4() {
		return this->ktnr4;
	}
	int CUSTOMER::getKtnr5() {
		return this->ktnr5;
	}

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
	int id = generateUserid();
	int ktnr1 = 0;
	int ktnr2 = 0;
	int ktnr3 = 0;
	int ktnr4 = 0;
	int ktnr5 = 0;
};
class SPARKONTO {
public:
	//F�gt dem Konto einen neuen/zus�tzlichen Verf�ger hinzu
	bool SPARKONTO::addKontoverf�ger(int id) {
		if (ktvf1 == 0) {
			this->ktvf1 = id;
		}
		else if (ktvf2 == 0) {
			this->ktvf2 = id;
		}
		else if (ktvf3 == 0) {
			this->ktvf3 = id;
		}
		else if (ktvf4 == 0) {
			this->ktvf4 = id;
		}
		else if (ktvf5 == 0) {
			this->ktvf5 = id;
		}
		else {
			LOGGING("Verf�ger konnte nicht hinzugef�gt werden da max 5 m�glich.", "ERROR");
			return false;
		}
		return true;
	}
	
	SPARKONTO::SPARKONTO()
	{
		this->sparkonto = "sparkonto";
		setKontonummer(generateKtnnr());
		this->Kontostand = 0;
		this->Kontoverf�ger = NULL;
		this->ktvf1 = 0;
		this->ktvf2 = 0;
		this->ktvf3 = 0;
		this->ktvf4 = 0;
		this->ktvf5 = 0;
	}
	//Getter / Setter
	void SPARKONTO::setKontoverf�ger(int ct, int id) {
		switch (ct) {
		case 1:
			this->ktvf1 = id;
			break;
		case 2:
			this->ktvf2 = id;
			break;
		case 3:
			this->ktvf3 = id;
			break;
		case 4:
			this->ktvf4 = id;
			break;
		case 5:
			this->ktvf5 = id;
			break;
		default:
			break;
		}
	}
	int SPARKONTO::getKontoverf�ger(int ct) {
		switch (ct) {
		case 1:
			return this->ktvf1;
		case 2:
			return this->ktvf2;
		case 3:
			return this->ktvf3;
		case 4:
			return this->ktvf4;
		case 5:
			return this->ktvf5;
		default:
			break;
		}
	}
	void SPARKONTO::setVerf�ger(CUSTOMER* _Kontoverf�ger) {
		this->Kontoverf�ger = _Kontoverf�ger;
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
	CUSTOMER* Kontoverf�ger;
	int ktvf1, ktvf2, ktvf3, ktvf4, ktvf5;
};
class KREDITKONTO {
public:
	KREDITKONTO::KREDITKONTO()
	{
		this->kreditkonto = "kreditkonto";
		setKontonummer(generateKtnnr());
		this->Kontostand = 0;
		this->Kontoverf�ger = NULL;
		this->ktvf1 = 0;
		this->ktvf2 = 0;
		this->ktvf3 = 0;
		this->ktvf4 = 0;
		this->ktvf5 = 0;
	}
	//F�gt einen neuen Verf�ger zum Konto hinzu
	bool KREDITKONTO::addKontoverf�ger(int id) {
		if (ktvf1 == 0) {
			this->ktvf1 = id;
		}
		else if (ktvf2 == 0) {
			this->ktvf2 = id;
		}
		else if (ktvf3 == 0) {
			this->ktvf3 = id;
		}
		else if (ktvf4 == 0) {
			this->ktvf4 = id;
		}
		else if (ktvf5 == 0) {
			this->ktvf5 = id;
		}
		else {
			LOGGING("Verf�ger konnte nicht hinzugef�gt werden da max 5 m�glich.", "ERROR");
			return false;
		}
		return true;
	}

	//Getter und Setter der Daten
	CUSTOMER KREDITKONTO::getVerf�ger() {
		return *Kontoverf�ger;
	}
	void KREDITKONTO::setVerf�ger(CUSTOMER* _Kontoverf�ger) {
		this->Kontoverf�ger = _Kontoverf�ger;
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
	void KREDITKONTO::setKontoverf�ger(int ct, int id) {
		switch (ct) {
		case 1:
			this->ktvf1 = id;
			break;
		case 2:
			this->ktvf2 = id;
			break;
		case 3:
			this->ktvf3 = id;
			break;
		case 4:
			this->ktvf4 = id;
			break;
		case 5:
			this->ktvf5 = id;
			break;
		default:
			break;
		}
	}
	int KREDITKONTO::getKontoverf�ger(int ct) {
		switch (ct) {
		case 1:
			return this->ktvf1;
		case 2:
			return this->ktvf2;
		case 3:
			return this->ktvf3;
		case 4:
			return this->ktvf4;
		case 5:
			return this->ktvf5;
		default:
			break;
		}
	}
	//Typidentifizierer
	char* getClassId() {

		return kreditkonto;
	}

private:
	char* kreditkonto;
	int Kontonummer;
	double Kontostand;
	CUSTOMER* Kontoverf�ger;
	int ktvf1, ktvf2, ktvf3, ktvf4, ktvf5;
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
	void UEBERWEISUNG::setempfaengername(char* empf�nger) {
		empfaengername = empf�nger;
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
class WAEHRUNGSMODUL
{
public:
	// Daweil nur als Waehrung USD, CHF, GBP, JPY
	WAEHRUNGSMODUL::WAEHRUNGSMODUL()
	{
		this->waehrung = "";
		this->kontostand = 0;
		this->kontonummer = 0;
	}

	double WAEHRUNGSMODUL::getkontostand()
	{
		return kontostand;
	}

	void WAEHRUNGSMODUL::setkontostand(double betrag)
	{
		kontostand = betrag;
	}

	void WAEHRUNGSMODUL::setKontonummer(int kontonr)
	{
		kontonummer = kontonr;
	}

	int WAEHRUNGSMODUL::getKontonummer()
	{
		return kontonummer;
	}

	// WAEHRUNG UNN�TIG
	char* WAEHRUNGSMODUL::getWaehrung()
	{
		return waehrung;
	}

	void WAEHRUNGSMODUL::setWaehrung(char* _waehrung)
	{
		waehrung = _waehrung;
	}

private:
	char* waehrung;
	double kontostand;
	int kontonummer;
};

/* ----------------------------------- */
/*   Funktionen zum Loggen der Daten   */
/* ----------------------------------- */

//Gibt die aktuelle Zeit in einem String aus
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
// Loggt jeden Schritt mit.
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
// Testen, ob das besagte File schon existiert
int fileExist(string name)
{
	const char* file = name.c_str();
	struct stat buffer;
	return (stat(file, &buffer) == 0);
}

// Initialisierung: Header f�r das Buchungs File wird erstellt
void initializeBuchungen(int kontonummer, string textFileName)
{
	const char* fileName = textFileName.c_str();
	fopen_s(&buchungsfile, fileName, "a");
	if (buchungsfile == NULL)
	{
		LOGGING("Die Abbuchungsdatei konnte nicht erstellt werden", "ERROR");
	}

	fprintf(buchungsfile, "Kontoauszug \n \n");
	fprintf(buchungsfile, "Kontonummer: %d \t BankSST \n", kontonummer);
	fprintf(buchungsfile, "Datum \t \t \t Verwendungszweck \t \t \t \t \t Betrag \n \n");

	fclose(buchungsfile);
}
void insertBuchungToFile(string textFileName, char* verwendungszweck, char* betrag)
{
	string stringtime = time_to_string();
	const char *time = stringtime.c_str();

	const char* fileName = textFileName.c_str();
	fopen_s(&buchungsfile, fileName, "a");
	if (buchungsfile == NULL)
	{
		LOGGING("Die Abbuchungsdatei konnte nicht erstellt werden", "ERROR");
	}
	fprintf(buchungsfile, "%s \t %s \t \t \t \t \t %s \n", time, verwendungszweck, betrag);
	fclose(buchungsfile);
}
//Hilftsfunktion - f�r die Buchungsfunktion
void BUCHUNGEN(char* verwendungszweck, char* betrag, string kontonummer)
{
	string textFileName = kontonummer.append("_Buchungen.txt");

	if (!fileExist(textFileName))
	{
		initializeBuchungen(stoi(kontonummer), textFileName);

		insertBuchungToFile(textFileName, verwendungszweck, betrag);
	}
	else
	{
		insertBuchungToFile(textFileName, verwendungszweck, betrag);
	}
}
//Funktion, um die Get�tigte Buchung/�berweisung in ein Logfile zu schreiben "Buchungen.txt"
void Buchen(KREDITKONTO* zielkonto, char* verwendungszweck, double betrag, int art)
{
	if (art == 1)
	{
		string betragString = to_string(betrag);
		betragString.insert(0, "-");
		BUCHUNGEN(verwendungszweck, (char*)betragString.c_str(), to_string(zielkonto->getKontonummer()));

	}
	else if (art == 2)
	{
		string betragString = to_string(betrag);
		betragString.insert(0, "-");
		BUCHUNGEN(verwendungszweck, (char*)betragString.c_str(), to_string(zielkonto->getKontonummer()));
	}
	else if (art == 3)
	{
		string betragString = to_string(betrag);
		betragString.insert(0, "+");
		BUCHUNGEN(verwendungszweck, (char*)betragString.c_str(), to_string(zielkonto->getKontonummer()));

	}
}
void Sparnachweis(SPARKONTO* zielkonto, char* verwendungszweck, double betrag, int art)
{
	if (art == 1)
	{
		string betragString = to_string(betrag);
		betragString.insert(0, "-");
		BUCHUNGEN(verwendungszweck, (char*)betragString.c_str(), to_string(zielkonto->getKontonummer()));

	}
	else if (art == 2)
	{
		string betragString = to_string(betrag);
		betragString.insert(0, "-");
		BUCHUNGEN(verwendungszweck, (char*)betragString.c_str(), to_string(zielkonto->getKontonummer()));
	}
	else if (art == 3)
	{
		string betragString = to_string(betrag);
		betragString.insert(0, "+");
		BUCHUNGEN(verwendungszweck, (char*)betragString.c_str(), to_string(zielkonto->getKontonummer()));

	}
}

/* --------------------------- */
/* JSON -> File-I/O Funktionen */
/* --------------------------- */

/* Read a file and return the string */
cJSON* readJsonFile_cJson(char *filename)
{
	FILE *f;
	long len;
	char *data;
	cJSON *json;

	f = fopen(filename, "rb");

	if (f != NULL) {
		fseek(f, 0, SEEK_END);
		len = ftell(f);
		fseek(f, 0, SEEK_SET);
		data = (char*)malloc(len + 1);
		fread(data, 1, len, f);
		data[len] = '\0';

		fclose(f);
		json = cJSON_Parse(data);

		if (!json) { LOGGING("Fehler beim oeffnen der JSON Datei.", "ERROR"); }
		else
		{
			free(data);
			return json;
		}

	}

	return NULL;
}
/* Read a file and return the string - NOT USED (IMO) */
char* readJsonFile_char(char *filename)
{
	FILE *f;
	long len;
	char *data;

	f = fopen(filename, "rb");
	fseek(f, 0, SEEK_END);
	len = ftell(f);
	fseek(f, 0, SEEK_SET);
	data = (char*)malloc(len + 1);
	fread(data, 1, len, f);
	data[len] = '\0';

	fclose(f);
	return data;
}

/* Write a json file with a filename and an cJSON element*/
bool writeJsonFile(char *filename, cJSON * jobj) {
	FILE *datei;
	datei = fopen(filename, "w");
	if (datei == NULL)
	{
		LOGGING("Fehler beim oeffnen der JSON Datei.", "ERROR");
		return 1;
	}
	fprintf(datei, cJSON_Print(jobj));
	fclose(datei);
	return true;
}
/* Write a json file with a filename and a char* element - NOT USED (IMO)*/
bool writeJsonFile(char *filename, char* jobj) {

	cJSON * newjobj = cJSON_Parse(jobj);

	if (!newjobj)
	{
		LOGGING("Fehler beim oeffnen der JSON Datei.", "ERROR");
		return false;
	}
	else
	{
		FILE *datei;
		datei = fopen(filename, "r+");
		if (datei == NULL)
		{
			LOGGING("Fehler beim oeffnen der JSON Datei.","ERROR");
			return false;
		}
		fprintf(datei, cJSON_Print(newjobj));
		fclose(datei);
	}
	return true;
}
//Erstellt eine Datei zum z�hlen der bereits angelegten Kunden
bool createUserCountFile() {
	cJSON* saveObj = cJSON_CreateObject();
	cJSON_AddItemToObject(saveObj, "userct", cJSON_CreateNumber(0));

	if (writeJsonFile(Usercounterfilename, saveObj)) {
		return true;
	}
	else {
		return false;
	}
}
int readUserCount() {

	cJSON* jsn = readJsonFile_cJson(Usercounterfilename);
	if (jsn == NULL) {
		createUserCountFile();
		jsn = readJsonFile_cJson(Usercounterfilename);
	}

	return cJSON_GetObjectItem(jsn, "userct")->valueint;
}
void writeUserCount(int ct) {
	cJSON* jsn = readJsonFile_cJson(Usercounterfilename);
	if (jsn == NULL) {
		createUserCountFile();
		jsn = readJsonFile_cJson(Usercounterfilename);
	}
	cJSON* newitem = cJSON_CreateNumber(ct);
	cJSON_ReplaceItemInObject(jsn, "userct", newitem);
	writeJsonFile(Usercounterfilename, jsn);
}
//Erstellt eine Datei zum z�hlen der bereits angelegten Konten
bool createCreditNumberCountFile() {
	cJSON* saveObj = cJSON_CreateObject();
	cJSON_AddItemToObject(saveObj, "kontoct", cJSON_CreateNumber(10000000));

	if (writeJsonFile(Kontocounterfilename, saveObj)) {
		return true;
	}
	else {
		return false;
	}
}
int readCount() {


	cJSON* jsn = readJsonFile_cJson(Kontocounterfilename);
	if (jsn == NULL) {
		createCreditNumberCountFile();
		jsn = readJsonFile_cJson(Kontocounterfilename);
	}

	return cJSON_GetObjectItem(jsn, "kontoct")->valueint;
}
void writeCount(int ct) {
	cJSON* jsn = readJsonFile_cJson(Kontocounterfilename);
	if (jsn == NULL) {
		createCreditNumberCountFile();
		jsn = readJsonFile_cJson(Kontocounterfilename);
	}
	cJSON* newitem = cJSON_CreateNumber(ct);
	cJSON_ReplaceItemInObject(jsn, "kontoct", newitem);
	writeJsonFile(Kontocounterfilename, jsn);
}

/* ---------------------------- */
/*      JSON - Obj Mapping      */
/* ---------------------------- */

/* Hilfsfunktion - Umwandlung cJSON to Customer */
CUSTOMER* cJSONToCustomer(cJSON* customerItem) {

	if (customerItem != NULL) {
		CUSTOMER* newCUObj = new CUSTOMER();
		newCUObj->setVorname(cJSON_GetObjectItem(customerItem, "vorname")->valuestring);
		newCUObj->setNachname(cJSON_GetObjectItem(customerItem, "nachname")->valuestring);
		newCUObj->setID(cJSON_GetObjectItem(customerItem, "id")->valueint);
		newCUObj->setGeburtsdatum(cJSON_GetObjectItem(customerItem, "geb")->valuestring);
		newCUObj->setAdresse(cJSON_GetObjectItem(customerItem, "addr")->valuestring);
		newCUObj->setWohnort(cJSON_GetObjectItem(customerItem, "ort")->valuestring);
		newCUObj->setTelefon(cJSON_GetObjectItem(customerItem, "tel")->valuestring);

		/* konten */
		newCUObj->setKtnr1(cJSON_GetObjectItem(customerItem, "konto1")->valueint);
		newCUObj->setKtnr2(cJSON_GetObjectItem(customerItem, "konto2")->valueint);
		newCUObj->setKtnr3(cJSON_GetObjectItem(customerItem, "konto3")->valueint);
		newCUObj->setKtnr4(cJSON_GetObjectItem(customerItem, "konto4")->valueint);
		newCUObj->setKtnr5(cJSON_GetObjectItem(customerItem, "konto5")->valueint);


		return newCUObj;
	}
	return NULL;
}
/* Hilfsfunktion - Umwandlung Customer to JSON */
cJSON* customerTocJSON(CUSTOMER* cust) {

	if (cust != NULL) {
		cJSON* userObject = cJSON_CreateObject();

		cJSON_AddItemToObject(userObject, "vorname", cJSON_CreateString(cust->getVorname()));
		cJSON_AddItemToObject(userObject, "nachname", cJSON_CreateString(cust->getNachname()));
		cJSON_AddItemToObject(userObject, "id", cJSON_CreateNumber(cust->getID()));
		cJSON_AddItemToObject(userObject, "geb", cJSON_CreateString(cust->getGeburtsdatum()));
		cJSON_AddItemToObject(userObject, "addr", cJSON_CreateString(cust->getAdresse()));
		cJSON_AddItemToObject(userObject, "ort", cJSON_CreateString(cust->getWohnort()));
		cJSON_AddItemToObject(userObject, "tel", cJSON_CreateString(cust->getTelefon()));
		cJSON_AddItemToObject(userObject, "konto1", cJSON_CreateNumber(cust->getKtnr1()));
		cJSON_AddItemToObject(userObject, "konto2", cJSON_CreateNumber(cust->getKtnr2()));
		cJSON_AddItemToObject(userObject, "konto3", cJSON_CreateNumber(cust->getKtnr3()));
		cJSON_AddItemToObject(userObject, "konto4", cJSON_CreateNumber(cust->getKtnr4()));
		cJSON_AddItemToObject(userObject, "konto5", cJSON_CreateNumber(cust->getKtnr5()));
		return userObject;
	}
	return NULL;

}
/* Hilfsfunktion - Umwandlung SPARKONTO to JSON */
cJSON* sparkontoTocJSON(SPARKONTO* sk) {

	if (sk != NULL) {
		cJSON* kontoObject = cJSON_CreateObject();

		cJSON_AddItemToObject(kontoObject, "Kontonummer", cJSON_CreateNumber(sk->getKontonummer()));
		cJSON_AddItemToObject(kontoObject, "Kontostand", cJSON_CreateNumber(sk->getKontostand()));


		cJSON_AddItemToObject(kontoObject, "Verf�gerID", cJSON_CreateNumber(sk->getKontoverf�ger(1)));
		cJSON_AddItemToObject(kontoObject, "Verf�gerID2", cJSON_CreateNumber(sk->getKontoverf�ger(2)));
		cJSON_AddItemToObject(kontoObject, "Verf�gerID3", cJSON_CreateNumber(sk->getKontoverf�ger(3)));
		cJSON_AddItemToObject(kontoObject, "Verf�gerID4", cJSON_CreateNumber(sk->getKontoverf�ger(4)));
		cJSON_AddItemToObject(kontoObject, "Verf�gerID5", cJSON_CreateNumber(sk->getKontoverf�ger(5)));

		return kontoObject;
	}
	return NULL;
}
/* Hilfsfunktion - Umwandlung cJSON to SPARKONTO */
SPARKONTO* cJSONToSparkonto(cJSON* skItem) {

	if (skItem != NULL) {
		SPARKONTO* newktObj = new SPARKONTO();
		newktObj->setKontonummer(cJSON_GetObjectItem(skItem, "Kontonummer")->valueint);
		newktObj->setKontostand(cJSON_GetObjectItem(skItem, "Kontostand")->valueint);
		//newktObj->setVerf�ger(readUser(cJSON_GetObjectItem(skItem, "Verf�gerID")->valueint));
		newktObj->setKontoverf�ger(1, cJSON_GetObjectItem(skItem, "Verf�gerID")->valueint);
		newktObj->setKontoverf�ger(2, cJSON_GetObjectItem(skItem, "Verf�gerID2")->valueint);
		newktObj->setKontoverf�ger(3, cJSON_GetObjectItem(skItem, "Verf�gerID3")->valueint);
		newktObj->setKontoverf�ger(4, cJSON_GetObjectItem(skItem, "Verf�gerID4")->valueint);
		newktObj->setKontoverf�ger(5, cJSON_GetObjectItem(skItem, "Verf�gerID5")->valueint);
		
		return newktObj;
	}

	return NULL;
}
/* Hilfsfunktion - Umwandlung Kreditkonto to JSON */
cJSON* kreditkontoTocJSON(KREDITKONTO* sk) {

	if (sk != NULL) {
		cJSON* kontoObject = cJSON_CreateObject();

		cJSON_AddItemToObject(kontoObject, "Kontonummer", cJSON_CreateNumber(sk->getKontonummer()));
		cJSON_AddItemToObject(kontoObject, "Kontostand", cJSON_CreateNumber(sk->getKontostand()));
		cJSON_AddItemToObject(kontoObject, "Verf�gerID", cJSON_CreateNumber(sk->getKontoverf�ger(1)));
		cJSON_AddItemToObject(kontoObject, "Verf�gerID2", cJSON_CreateNumber(sk->getKontoverf�ger(2)));
		cJSON_AddItemToObject(kontoObject, "Verf�gerID3", cJSON_CreateNumber(sk->getKontoverf�ger(3)));
		cJSON_AddItemToObject(kontoObject, "Verf�gerID4", cJSON_CreateNumber(sk->getKontoverf�ger(4)));
		cJSON_AddItemToObject(kontoObject, "Verf�gerID5", cJSON_CreateNumber(sk->getKontoverf�ger(5)));

		return kontoObject;
	}
	return NULL;
}
/* Hilfsfunktion - Umwandlung cJSON to kreditkonto */
KREDITKONTO* cJSONToKreditkonto(cJSON* skItem) {

	if (skItem != NULL) {
		KREDITKONTO* newktObj = new KREDITKONTO();
		newktObj->setKontonummer(cJSON_GetObjectItem(skItem, "Kontonummer")->valueint);
		newktObj->setKontostand(cJSON_GetObjectItem(skItem, "Kontostand")->valueint);
		//newktObj->setVerf�ger(readUser(cJSON_GetObjectItem(skItem, "Verf�gerID")->valueint));
		newktObj->setKontoverf�ger(1, cJSON_GetObjectItem(skItem, "Verf�gerID")->valueint);
		newktObj->setKontoverf�ger(2, cJSON_GetObjectItem(skItem, "Verf�gerID2")->valueint);
		newktObj->setKontoverf�ger(3, cJSON_GetObjectItem(skItem, "Verf�gerID3")->valueint);
		newktObj->setKontoverf�ger(4, cJSON_GetObjectItem(skItem, "Verf�gerID4")->valueint);
		newktObj->setKontoverf�ger(5, cJSON_GetObjectItem(skItem, "Verf�gerID5")->valueint);

		return newktObj;
	}

	return NULL;
}

/* ---------------------------- */
/*        Hilfsfunktonen        */
/* ---------------------------- */

/* Hilfsfunktion - Vergleich der ID werte */
bool checkItem(cJSON * item, int id) {

	cJSON * iditem = cJSON_GetObjectItem(item, "id");

	if (iditem->valueint == id) {
		return true;
	}
	else {
		return false;
	}
}
/* Hilfsfunktion - Vergleich der ID werte von konten */
bool checkKtItem(cJSON * item, int id) {

	cJSON * iditem = cJSON_GetObjectItem(item, "Kontonummer");

	if (iditem->valueint == id) {
		return true;
	}
	else {
		return false;
	}
}
/* Hilfsfunktion - wenn Userfile nicht existiert */
bool createUserFile() {
	cJSON* saveObj = cJSON_CreateObject();
	cJSON_AddItemToObject(saveObj, USER_ROOT, cJSON_CreateArray());

	if (writeJsonFile(USER_FILE, saveObj)) {
		return true;
	}
	else {
		return false;
	}
}
/* Hilfsfunktion - wenn sparKontofile nicht existiert */
bool createSparKontoFile() {
	cJSON* saveObj = cJSON_CreateObject();
	cJSON_AddItemToObject(saveObj, SPARKONTO_ROOT, cJSON_CreateArray());

	if (writeJsonFile(SPARKONTO_FILE, saveObj)) {
		return true;
	}
	else {
		return false;
	}
}
/* Hilfsfunktion - wenn kreditKontofile nicht existiert */
bool createKreditKontoFile() {
	cJSON* saveObj = cJSON_CreateObject();
	cJSON_AddItemToObject(saveObj, KREDITKONTO_ROOT, cJSON_CreateArray());

	if (writeJsonFile(KREDITKONTO_FILE, saveObj)) {
		return true;
	}
	else {
		return false;
	}
}

/* ----------------------------------------------- */
/*   Funktionen f�r persistente Datenspeicherung   */
/* ----------------------------------------------- */

/*  ----------------  */
/*      CUSTOMER      */
/*  ----------------  */

/* Liest vorhandenen user mit ID aus. NULL wenn nicht vorhanden */
CUSTOMER* readUser(int id) {

	cJSON * fileObj = readJsonFile_cJson(USER_FILE);

	if (fileObj == NULL) {
		createUserFile();
	}
	else
	{
		cJSON * arr = cJSON_GetObjectItem(fileObj, USER_ROOT); 
		int size = cJSON_GetArraySize(arr);

		for (int x = 0; x < size; x++) {
			cJSON * item = cJSON_GetArrayItem(arr, x);

			if (checkItem(item, id)) {
				return cJSONToCustomer(item);
			}
		}
		LOGGING("user nicht gefunden", "ERROR");
	}
	return NULL; // return NULL wenn file leer
}
/* �berschreibt user, false wenn user nicht vorhanden (sollte nicht m�glich sein) */
bool writeUser(CUSTOMER* cust) {

	if (userExist(cust->getID())) {
		cJSON * fileObj = readJsonFile_cJson(USER_FILE);

		if (fileObj != NULL) {
			cJSON * arr = cJSON_GetObjectItem(fileObj, USER_ROOT);
			int size = cJSON_GetArraySize(arr);

			for (int x = 0; x < size; x++) {
				cJSON * item = cJSON_GetArrayItem(arr, x);
				if (checkItem(item, cust->getID())) {
					cJSON_ReplaceItemInArray(arr, x, customerTocJSON(cust));
					cJSON* saveObj = cJSON_CreateObject();
					cJSON_AddItemToObject(saveObj, USER_ROOT, arr);

					if (writeJsonFile(USER_FILE, saveObj)) {
						return true;
					}
					else {
						return false;
					}
				}
			}
		}
	}
	else {
		LOGGING("user existiert nicht. deshalb nicht �berschreibbar", "ERROR");
	}
	return false; // wenn file = NULL dann kann er nichts schreiben somit false
}
/* User hinzuf�gen wenn noch nicht vorhanden */
bool addUser(CUSTOMER* cu) {

	// @@ wenn konto auf customer gespeichert muss getestet werden ob es das konto auch gibt das angelegt werden soll!!!

	if (!userExist(cu->getID())) {
		cJSON * fileObj = readJsonFile_cJson(USER_FILE);

		if (fileObj == NULL) {
			createUserFile();
			fileObj = readJsonFile_cJson(USER_FILE);
		}

		if (fileObj != NULL) {
			cJSON * arr = cJSON_GetObjectItem(fileObj, USER_ROOT);
			int size = cJSON_GetArraySize(arr);

			cJSON_AddItemToArray(arr, customerTocJSON(cu));
			cJSON* saveObj = cJSON_CreateObject();
			cJSON_AddItemToObject(saveObj, USER_ROOT, arr);

			//printObject(saveObj);
			if (writeJsonFile(USER_FILE, saveObj)) {
				return true;
			}
			else {
				return false;
			}
		}
	}
	else {
		LOGGING("user exist", "OK");
	}
	return false;
}
/* user mit id l�schen - achtung noch aktive konten?*/
bool removeUser(int id) {

	cJSON * fileObj = readJsonFile_cJson(USER_FILE);

	if (fileObj != NULL) {
		cJSON * arr = cJSON_GetObjectItem(fileObj, USER_ROOT);

		int size = cJSON_GetArraySize(arr);

		for (int x = 0; x < size; x++) {
			cJSON * item = cJSON_GetArrayItem(arr, x);

			if (checkItem(item, id)) {
				cJSON_DeleteItemFromArray(arr, x);
				cJSON* saveObj = cJSON_CreateObject();
				cJSON_AddItemToObject(saveObj, USER_ROOT, arr);

				if (writeJsonFile(USER_FILE, saveObj)) {
					return true;
				}
				else {
					return false;
				}
			}
		}
	}
	return false; // wenn file null dann false weil nicht removable
}
/* True wenn User vorhanden */
bool userExist(int id) {
	cJSON * fileObj = readJsonFile_cJson(USER_FILE);

	if (fileObj != NULL) {
		cJSON * arr = cJSON_GetObjectItem(fileObj, USER_ROOT);
		int size = cJSON_GetArraySize(arr);

		for (int x = 0; x < size; x++) {
			cJSON * item = cJSON_GetArrayItem(arr, x);
			if (checkItem(item, id)) {
				return true;
			}
		}
	}
	return false;
}

bool checkUserItem(cJSON* item, char* vorname, char* nachname, char* geb) {

	char* vornameItem = cJSON_GetObjectItem(item, "vorname")->valuestring;
	char* nachnameItem = cJSON_GetObjectItem(item, "nachname")->valuestring;
	char* gebItem = cJSON_GetObjectItem(item, "geb")->valuestring;


	if (!strcmp(vorname, vornameItem) && !strcmp(nachname, nachnameItem) && !strcmp(geb, gebItem)) {
		return true;
	}

	return false;
}
int searchUser(char* vorname, char* nachname, char* geb) {

	cJSON * fileObj = readJsonFile_cJson(USER_FILE);

	if (fileObj == NULL) {
		createUserFile();
	}
	else
	{
		cJSON * arr = cJSON_GetObjectItem(fileObj, USER_ROOT);
		int size = cJSON_GetArraySize(arr);

		for (int x = 0; x < size; x++) {
			cJSON * item = cJSON_GetArrayItem(arr, x);

			if (checkUserItem(item, vorname, nachname, geb)) {
				return cJSON_GetObjectItem(item, "id")->valueint;			
			}
		}
		LOGGING("user nicht gefunden", "ERROR");
	}
	return -1; // return -1 wenn user nicht vorhanden

}
/*  -------------------  */
/*       SPARKONTO       */
/*  -------------------  */

// Sparkonto einlesen 
SPARKONTO* readSparKonto(int ktnr) {

	cJSON * fileObj = readJsonFile_cJson(SPARKONTO_FILE);

	if (fileObj == NULL) {
		createSparKontoFile();
	}
	else {
		cJSON * arr = cJSON_GetObjectItem(fileObj, SPARKONTO_ROOT);
		int size = cJSON_GetArraySize(arr);

		for (int x = 0; x < size; x++) {
			cJSON * item = cJSON_GetArrayItem(arr, x);

			if (checkKtItem(item, ktnr)) {
				return cJSONToSparkonto(item);
			}
		}
		LOGGING("Sparkonto nicht gefunden", "ERROR");
	}
	return NULL; // wenn file leer dann kann er nichts lesen -> somit NULL
}
// Sparkonto eintragen
bool writeSparKonto(SPARKONTO* kt) {

	if (sparkontoExist(kt->getKontonummer())) {
		cJSON * fileObj = readJsonFile_cJson(SPARKONTO_FILE);

		if (fileObj != NULL) {
			cJSON * arr = cJSON_GetObjectItem(fileObj, SPARKONTO_ROOT);
			int size = cJSON_GetArraySize(arr);

			for (int x = 0; x < size; x++) {
				cJSON * item = cJSON_GetArrayItem(arr, x);
				if (checkKtItem(item, kt->getKontonummer())) {
					cJSON_ReplaceItemInArray(arr, x, sparkontoTocJSON(kt));
					cJSON* saveObj = cJSON_CreateObject();
					cJSON_AddItemToObject(saveObj, SPARKONTO_ROOT, arr);

					if (writeJsonFile(SPARKONTO_FILE, saveObj)) {
						return true;
					}
					else {
						return false;
					}
				}
			}
		}
	}
	else {
		LOGGING("konto existiert nicht", "ERROR"); //@@ schreiben in log files!!
	}
	return false; // wenn file = NULL dann kann er nichts schreiben somit false
}
// Sparkonto hinzuf�gen wenn noch nicht vorhanden
bool addSparKonto(SPARKONTO* kt) {
	if (!sparkontoExist(kt->getKontonummer())) {
		cJSON * fileObj = readJsonFile_cJson(SPARKONTO_FILE);
		if (fileObj == NULL) {
			createSparKontoFile();
			fileObj = readJsonFile_cJson(SPARKONTO_FILE);
		}

		if (fileObj != NULL) {
			cJSON * arr = cJSON_GetObjectItem(fileObj, SPARKONTO_ROOT);
			cJSON_AddItemToArray(arr, sparkontoTocJSON(kt));
			cJSON* saveObj = cJSON_CreateObject();
			cJSON_AddItemToObject(saveObj, SPARKONTO_ROOT, arr);
			//printObject(saveObj);
			if (writeJsonFile(SPARKONTO_FILE, saveObj)) {
				return true;
			}
			else {
				return false;
			}
		}
	}
	return false;
}
// Sparkonto mit kontonr l�schen
bool removeSparKonto(int ktnr) {
	cJSON * fileObj = readJsonFile_cJson(SPARKONTO_FILE);

	if (fileObj != NULL) {
		cJSON * arr = cJSON_GetObjectItem(fileObj, SPARKONTO_ROOT);

		int size = cJSON_GetArraySize(arr);

		for (int x = 0; x < size; x++) {
			cJSON * item = cJSON_GetArrayItem(arr, x);

			if (checkKtItem(item, ktnr)) {
				deleteKontoUserEntrys(item, ktnr);
				cJSON_DeleteItemFromArray(arr, x);
				cJSON* saveObj = cJSON_CreateObject();
				cJSON_AddItemToObject(saveObj, SPARKONTO_ROOT, arr);

				if (writeJsonFile(SPARKONTO_FILE, saveObj)) {
					return true;
				}
				else {
					return false;
				}
			}
		}
	}
	return false;
}
//Pr�ft, ob das angegebene SparKonto existiert
bool sparkontoExist(int ktnr) {
	cJSON * fileObj = readJsonFile_cJson(SPARKONTO_FILE);

	if (fileObj != NULL) {
		cJSON * arr = cJSON_GetObjectItem(fileObj, SPARKONTO_ROOT);
		int size = cJSON_GetArraySize(arr);

		for (int x = 0; x < size; x++) {
			cJSON * item = cJSON_GetArrayItem(arr, x);
			if (checkKtItem(item, ktnr)) {
				return true;
			}
		}
	}
	return false;
}
//F�gt dem Sparkonto einen neuen Verf�ger hinzu


bool addCustomerKontoEntry(int ktnr, int userid) {
	
	if (userid != 0) {
		CUSTOMER* cust = readUser(userid);

		if (cust->getKtnr1() == 0) {
			cust->setKtnr1(ktnr);
		}
		else if (cust->getKtnr2() == 0) {
			cust->setKtnr2(ktnr);
		}
		else if (cust->getKtnr3() == 0) {
			cust->setKtnr3(ktnr);
		}
		else if (cust->getKtnr4() == 0) {
			cust->setKtnr4(ktnr);
		}
		else if (cust->getKtnr5() == 0) {
			cust->setKtnr5(ktnr);
		}
		writeUser(cust);
		return true;
	}
	return false;
}

int addSparKontoverf�ger(SPARKONTO* sk, CUSTOMER* cust) {

	int userid = cust->getID();
	if (sk->addKontoverf�ger(userid)) {
		writeSparKonto(sk);
		addCustomerKontoEntry(sk->getKontonummer(), cust->getID());
		return 1;
	}
	return 0;
}

/*  ---------------------  */
/*       KREDITKONTO       */
/*  ---------------------  */

// Kreditkonto einlesen 
KREDITKONTO* readKreditKonto(int ktnr) {
	cJSON * fileObj = readJsonFile_cJson(KREDITKONTO_FILE);

	if (fileObj == NULL) {
		createKreditKontoFile();
	}
	else {
		cJSON * arr = cJSON_GetObjectItem(fileObj, KREDITKONTO_ROOT);
		int size = cJSON_GetArraySize(arr);

		for (int x = 0; x < size; x++) {
			cJSON * item = cJSON_GetArrayItem(arr, x);

			if (checkKtItem(item, ktnr)) {
				return cJSONToKreditkonto(item);
			}
		}
		LOGGING("Kreditkonto nicht gefunden", "ERROR");
	}
	return NULL; // wenn file leer dann kann er nichts lesen -> somit NULL
}
// Kreditkonto eintragen
bool writeKreditKonto(KREDITKONTO* kt) {

	if (kreditkontoExist(kt->getKontonummer())) {
		cJSON * fileObj = readJsonFile_cJson(KREDITKONTO_FILE);

		if (fileObj != NULL) {
			cJSON * arr = cJSON_GetObjectItem(fileObj, KREDITKONTO_ROOT);
			int size = cJSON_GetArraySize(arr);

			for (int x = 0; x < size; x++) {
				cJSON * item = cJSON_GetArrayItem(arr, x);
				if (checkKtItem(item, kt->getKontonummer())) {
					cJSON_ReplaceItemInArray(arr, x, kreditkontoTocJSON(kt));
					cJSON* saveObj = cJSON_CreateObject();
					cJSON_AddItemToObject(saveObj, KREDITKONTO_ROOT, arr);

					if (writeJsonFile(KREDITKONTO_FILE, saveObj)) {
						return true;
					}
					else {
						return false;
					}
				}
			}
		}
	}
	else {
		LOGGING("konto existiert nicht", "ERROR"); //@@ schreiben in log files!!
	}
	return false; // wenn file = NULL dann kann er nichts schreiben somit false
}
// Kreditkonto hinzuf�gen wenn noch nicht vorhanden
bool addKreditKonto(KREDITKONTO* kt) {
	if (!kreditkontoExist(kt->getKontonummer())) {
		cJSON * fileObj = readJsonFile_cJson(KREDITKONTO_FILE);

		if (fileObj == NULL) {
			createKreditKontoFile();
			fileObj = readJsonFile_cJson(KREDITKONTO_FILE);
		}

		if (fileObj != NULL) {
			cJSON * arr = cJSON_GetObjectItem(fileObj, KREDITKONTO_ROOT);

			cJSON_AddItemToArray(arr, kreditkontoTocJSON(kt));
			cJSON* saveObj = cJSON_CreateObject();
			cJSON_AddItemToObject(saveObj, KREDITKONTO_ROOT, arr);

			//printObject(saveObj);
			if (writeJsonFile(KREDITKONTO_FILE, saveObj)) {
				return true;
			}
			else {
				return false;
			}
		}
	}
	return false;
}

bool removeKontofromUser(int userid,int ktnr) {
	if (userid != 0) {

		CUSTOMER* cust = readUser(userid);

		if (cust->getKtnr1() == ktnr) {
			cust->setKtnr1(0);
			writeUser(cust);
		}
		else if (cust->getKtnr2() == ktnr) {
			cust->setKtnr2(0);
			writeUser(cust);
		}
		else if (cust->getKtnr3() == ktnr) {
			cust->setKtnr3(0);
			writeUser(cust);
		}
		else if (cust->getKtnr4() == ktnr) {
			cust->setKtnr4(0);
			writeUser(cust);
		}
		else if (cust->getKtnr5() == ktnr) {
			cust->setKtnr5(0);
			writeUser(cust);
		}

	}
	return false;
}

bool deleteKontoUserEntrys(cJSON *item, int ktnr) {
	
	removeKontofromUser(cJSON_GetObjectItem(item, "Verf�gerID")->valueint, ktnr);
	removeKontofromUser(cJSON_GetObjectItem(item, "Verf�gerID2")->valueint, ktnr);
	removeKontofromUser(cJSON_GetObjectItem(item, "Verf�gerID3")->valueint, ktnr);
	removeKontofromUser(cJSON_GetObjectItem(item, "Verf�gerID4")->valueint, ktnr);
	removeKontofromUser(cJSON_GetObjectItem(item, "Verf�gerID5")->valueint, ktnr);
	return true;
}

// Kreditkonto mit kontonr l�schen
bool removeKreditKonto(int ktnr) {
	cJSON * fileObj = readJsonFile_cJson(KREDITKONTO_FILE);

	if (fileObj != NULL) {
		cJSON * arr = cJSON_GetObjectItem(fileObj, KREDITKONTO_ROOT);

		int size = cJSON_GetArraySize(arr);

		for (int x = 0; x < size; x++) {
			cJSON * item = cJSON_GetArrayItem(arr, x);

			if (checkKtItem(item, ktnr)) {
				deleteKontoUserEntrys(item,ktnr);
				cJSON_DeleteItemFromArray(arr, x);
				cJSON* saveObj = cJSON_CreateObject();
				cJSON_AddItemToObject(saveObj, KREDITKONTO_ROOT, arr);

				if (writeJsonFile(KREDITKONTO_FILE, saveObj)) {
					return true;
				}
				else {
					return false;
				}
			}
		}
	}
	return false;
}
//Pr�ft die Existenz eines angegebenen Kontos, bei existenz = true
bool kreditkontoExist(int ktnr) {
	cJSON * fileObj = readJsonFile_cJson(KREDITKONTO_FILE);

	if (fileObj != NULL) {
		cJSON * arr = cJSON_GetObjectItem(fileObj, KREDITKONTO_ROOT);
		int size = cJSON_GetArraySize(arr);

		for (int x = 0; x < size; x++) {
			cJSON * item = cJSON_GetArrayItem(arr, x);
			if (checkKtItem(item, ktnr)) {
				return true;
			}
		}
	}
	return false;
}
//F�gt dem KreditKonto einen neuen Verf�ger hinzu
int addKreditKontoverf�ger(KREDITKONTO* kk, CUSTOMER* cust) {
	int userid = cust->getID();
	if (kk->addKontoverf�ger(userid)) {
		writeKreditKonto(kk);
		addCustomerKontoEntry(kk->getKontonummer(), cust->getID());
		return 1;
	}
	return 0;
}

/* ------------------------- */
/*   Funktionen der Kunden   */
/* ------------------------- */

//NeuerKunde legt einen neuen Kunden an 
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
	Kunde->setKtnr1(0);
	Kunde->setKtnr2(0);
	Kunde->setKtnr3(0);
	Kunde->setKtnr4(0);
	Kunde->setKtnr5(0);

	/* gibt false zur�ck wenn user nicht geadded werden konnte*/
	if (addUser(Kunde) == true) {
		LOGGING("Der Kunde wurde erfolgreich angelegt.", "OK");
	}
	else {
		LOGGING("Bei der Erstellung des Kunden ist ein Fehler aufgetreten.", "ERROR");
	}
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
	writeUser(Kunde);
	LOGGING("Der Vorname wurde erfolgreich ge�ndert.", "OK");
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
	writeUser(Kunde);
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
	writeUser(Kunde);
	LOGGING("Die Adresse wurde erfolgreich ge�ndert.", "OK");
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
	writeUser(Kunde);
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
	writeUser(Kunde);
	LOGGING("Die Telefonnummer wurde erfolgreich ge�ndert.", "OK");
	return;
}
//Hier k�nnen die Kundendaten erneut abgefragt werden
void Kundendatenabfrage(CUSTOMER * Kunde) {

	LOGGING("Das ist der Vorname des �bergebenen Kunden:", "OK");
	LOGGING(Kunde->getVorname(), "OK");
	LOGGING("Das ist der Nachname des �bergebenen Kunden:", "OK");
	LOGGING(Kunde->getNachname(), "OK");
	LOGGING("Das ist das Geburtsdatum des �bergebenen Kunden:", "OK");
	LOGGING(Kunde->getGeburtsdatum(), "OK");
	LOGGING("Das ist die Adresse des �bergebenen Kunden:", "OK");
	LOGGING(Kunde->getAdresse(), "OK");
	LOGGING("Das ist der Wohnort des �bergebenen Kunden:", "OK");
	LOGGING(Kunde->getWohnort(), "OK");
	LOGGING("Das ist die Telefonnummer des �bergebenen Kunden:", "OK");
	LOGGING(Kunde->getTelefon(), "OK");
}
//Die Funktion Kundeentfernen entfernt mithilfe von delete den �bergebenen Kunden
void Kundeentfernen(CUSTOMER *Kunde) {

	if (Kunde == NULL) {
		LOGGING("Der �bergebene Kunde existiert nicht oder ist NULL.", "OK");
		return;
	}
	if (Kunde->getClassId() != "customer") {
		LOGGING("Es wurde das falsche Objekt �bergeben.", "ERROR");
		return;
	}

	else {
		removeUser(Kunde->getID());
		delete Kunde;
		LOGGING("Der Kunde wurde erfolgreich entfernt.", "OK");
	}
}

/* ------------------------- */
/*   Funktionen der Konten   */
/* ------------------------- */

//Die Funktionen f�r ein neues Konto erstellt ein neues Kredit-/Sparkonto und wei�t das dem �bergebenen Kunden zu.
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

	Konto->addKontoverf�ger(Kunde->getID());
	
	if (Kunde->getKtnr1() == 0) {
		Kunde->setKtnr1(Konto->getKontonummer());
	}
	else if(Kunde->getKtnr2() == 0){
		Kunde->setKtnr2(Konto->getKontonummer());
	}
	else if (Kunde->getKtnr3() == 0) {
		Kunde->setKtnr3(Konto->getKontonummer());
	}
	else if (Kunde->getKtnr4() == 0) {
		Kunde->setKtnr4(Konto->getKontonummer());
	}
	else if (Kunde->getKtnr5() == 0) {
		Kunde->setKtnr5(Konto->getKontonummer());
	}
	else{
		LOGGING("Ein Kunde kann nur maximal 5 Konten besitzen.","ERROR");
	}
	writeUser(Kunde);

	if (addSparKonto(Konto) == true) {
		LOGGING("Das SparKonto wurde erfolgreich erstellt.", "OK");
	}
	else {
		LOGGING("Bei der Erstellung des Sparkontos ist ein Fehler aufgetreten.", "ERROR");
	}
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

	Konto->addKontoverf�ger(Kunde->getID());

	if (Kunde->getKtnr1() == 0) {
		Kunde->setKtnr1(Konto->getKontonummer());
	}
	else if (Kunde->getKtnr2() == 0) {
		Kunde->setKtnr2(Konto->getKontonummer());
	}
	else if (Kunde->getKtnr3() == 0) {
		Kunde->setKtnr3(Konto->getKontonummer());
	}
	else if (Kunde->getKtnr4() == 0) {
		Kunde->setKtnr4(Konto->getKontonummer());
	}
	else if (Kunde->getKtnr5() == 0) {
		Kunde->setKtnr5(Konto->getKontonummer());
	}
	else {
		LOGGING("Ein Kunde kann nur maximal 5 Konten besitzen.", "ERROR");
	}
	writeUser(Kunde);

	if (addKreditKonto(Konto) == true) {
		LOGGING("Das SparKonto wurde erfolgreich erstellt.", "OK");
	}
	else {
		LOGGING("Bei der Erstellung des Sparkontos ist ein Fehler aufgetreten.", "ERROR");
	}
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

	// wird im Persistance komponente erledigt

	//if (Verf�ger->getKtnr1() == Konto->getKontonummer()) {
	//	Verf�ger->setKtnr1(0);
	//	writeUser(Verf�ger);
	//}
	//else if (Verf�ger->getKtnr2() == Konto->getKontonummer()) {
	//	Verf�ger->setKtnr2(0);
	//	writeUser(Verf�ger);
	//}
	//else if (Verf�ger->getKtnr3() == Konto->getKontonummer()) {
	//	Verf�ger->setKtnr3(0);
	//	writeUser(Verf�ger);
	//}
	//else if (Verf�ger->getKtnr4() == Konto->getKontonummer()) {
	//	Verf�ger->setKtnr4(0);
	//	writeUser(Verf�ger);
	//}
	//else if (Verf�ger->getKtnr5() == Konto->getKontonummer()) {
	//	Verf�ger->setKtnr5(0);
	//	writeUser(Verf�ger);
	//}

	if (removeSparKonto(Konto->getKontonummer()) == true) {
		delete Konto;
		
		LOGGING("Das Konto wurde erfolgreich entfernt.", "OK");
	}
	else {
		LOGGING("Bei der L�schung des Kontos ist ein Fehler aufgetreten", "ERROR");
	}
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

	// wird im persistance teil erledigt

	//if (Verf�ger->getKtnr1() == Konto->getKontonummer()) {
	//	Verf�ger->setKtnr1(0);
	//	writeUser(Verf�ger);
	//}
	//else if (Verf�ger->getKtnr2() == Konto->getKontonummer()) {
	//	Verf�ger->setKtnr1(0);
	//	writeUser(Verf�ger);
	//}
	//else if (Verf�ger->getKtnr3() == Konto->getKontonummer()) {
	//	Verf�ger->setKtnr1(0);
	//	writeUser(Verf�ger);
	//}
	//else if (Verf�ger->getKtnr4() == Konto->getKontonummer()) {
	//	Verf�ger->setKtnr1(0);
	//	writeUser(Verf�ger);
	//}
	//else if (Verf�ger->getKtnr5() == Konto->getKontonummer()) {
	//	Verf�ger->setKtnr1(0);
	//	writeUser(Verf�ger);
	//}

	if (removeKreditKonto(Konto->getKontonummer()) == true) {
		delete Konto;
		LOGGING("Das Konto wurde erfolgreich entfernt.", "OK");
	}
	else {
		LOGGING("Bei der L�schung des Kontos ist ein Fehler aufgetreten", "ERROR");
	}
}

int removeSparKontoverf�ger(int userid, SPARKONTO* kk) {
	if (kk != NULL) {
		if (kk->getKontoverf�ger(1) == userid) {
			kk->setKontoverf�ger(1, 0);
			removeKontofromUser(userid, kk->getKontonummer());
			writeSparKonto(kk);
		}
		else if (kk->getKontoverf�ger(2) == userid) {
			kk->setKontoverf�ger(2, 0);
			removeKontofromUser(userid, kk->getKontonummer());
			writeSparKonto(kk);
		}
		else if (kk->getKontoverf�ger(3) == userid) {
			kk->setKontoverf�ger(3, 0);
			removeKontofromUser(userid, kk->getKontonummer());
			writeSparKonto(kk);
		}
		else if (kk->getKontoverf�ger(4) == userid) {
			kk->setKontoverf�ger(4, 0);
			removeKontofromUser(userid, kk->getKontonummer());
			writeSparKonto(kk);
		}
		else if (kk->getKontoverf�ger(5) == userid) {
			kk->setKontoverf�ger(5, 0);
			removeKontofromUser(userid, kk->getKontonummer());
			writeSparKonto(kk);
		}
		return 1;
	}
	return 0;
}
int removeKreditKontoverf�ger(int userid, KREDITKONTO* kk) {

	if (kk != NULL) {
		if (kk->getKontoverf�ger(1) == userid) {
			kk->setKontoverf�ger(1, 0);
			removeKontofromUser(userid, kk->getKontonummer());
			writeKreditKonto(kk);
		}
		else if (kk->getKontoverf�ger(2) == userid) {
			kk->setKontoverf�ger(2, 0);
			removeKontofromUser(userid, kk->getKontonummer());
			writeKreditKonto(kk);
		}
		else if (kk->getKontoverf�ger(3) == userid) {
			kk->setKontoverf�ger(3, 0);
			removeKontofromUser(userid, kk->getKontonummer());
			writeKreditKonto(kk);
		}
		else if (kk->getKontoverf�ger(4) == userid) {
			kk->setKontoverf�ger(4, 0);
			removeKontofromUser(userid, kk->getKontonummer());
			writeKreditKonto(kk);
		}
		else if (kk->getKontoverf�ger(5) == userid) {
			kk->setKontoverf�ger(5, 0);
			removeKontofromUser(userid, kk->getKontonummer());
			writeKreditKonto(kk);
		}
		return 1;
	}
	return 0;
}
/* ------------------ */
/*  Kontofunktionen   */
/* ------------------ */

//Funktionen zum �berweisen, Einzahlen und Abheben
void doAbheben(KREDITKONTO* zielkonto, double betrag) {

	if (zielkonto == NULL) {
		LOGGING("das �bergebene Konto existiert nicht.", "ERROR");
		return;
	}

	double newKontostand = zielkonto->getKontostand() - betrag;
	zielkonto->setKontostand(newKontostand);
	char* verwendungszweck = "";
	writeKreditKonto(zielkonto);
	LOGGING("Eine Abhebung wurde getaetigt.", "OK");
	Buchen(zielkonto, verwendungszweck, betrag, 2);
}
void doEinzahlen(KREDITKONTO* zielkonto, char* verwendungszweck, double betrag) {

	if (zielkonto == NULL) {
		LOGGING("das �bergebene Konto existiert nicht.", "ERROR");
		return;
	}


	double newKontostand = zielkonto->getKontostand() + betrag;
	zielkonto->setKontostand(newKontostand);
	writeKreditKonto(zielkonto);
	LOGGING("Eine Einzahlung wurde getaetigt.", "OK");
	Buchen(zielkonto, verwendungszweck, betrag, 3);
}
void doSparen(SPARKONTO* zielkonto, char* verwendungszweck, double betrag) {
	
	if (zielkonto == NULL) {
		LOGGING("das �bergebene Konto existiert nicht.", "ERROR");
		return;
	}
	
	double newKontostand = zielkonto->getKontostand() + betrag;
	zielkonto->setKontostand(newKontostand);
	writeSparKonto(zielkonto);
	LOGGING("Eine Einzahlung wurde getaetigt.", "OK");
	Sparnachweis(zielkonto, verwendungszweck, betrag, 3);
}
UEBERWEISUNG* NeueUeberweisung(KREDITKONTO* quellkonto, KREDITKONTO* zielkonto, double betrag, char* verwendungszweck) {
	
	string Verf�gervorname = zielkonto->getVerf�ger().getVorname();
	string Verf�gernachname = zielkonto->getVerf�ger().getNachname();
	string Verf�gername = Verf�gervorname + Verf�gernachname;
	char* cVerf�gername = (char*)Verf�gername.c_str();

	// Mit doEinzahlen - scheint am anderen Konto im Kontoauszug auf
	doEinzahlen(zielkonto, verwendungszweck, betrag);

	UEBERWEISUNG* ueberweisung = new UEBERWEISUNG();
	ueberweisung->setempfaengername(cVerf�gername);
	ueberweisung->setkontonummer(zielkonto->getKontonummer());
	// ueberweisung->setkontostand(newKontostand);	
	ueberweisung->setVerwendungszweck(verwendungszweck);
	ueberweisung->setBetrag(betrag);

	// Betrag vom Quellkonto abbuchen
	doAbheben(quellkonto, betrag);
	LOGGING("Eine �berweisung wurde getaetigt.", "OK");
	return ueberweisung;
}

/* ---------------- */
/*  W�hrungsmodul   */
/* ---------------- */

void createUmrechnungsFile(string textFileName, char* waehrung, double kontostand, double waehrungsKontostand)
{
	const char* fileName = textFileName.c_str();
	fopen_s(&umrechnungsFile, fileName, "a");
	if (umrechnungsFile == NULL)
	{
		LOGGING("Die Abbuchungsdatei konnte nicht erstellt werden HIER","ERROR");
	}

	fprintf(umrechnungsFile, "Umrechnung von Euro zu %s \n \n", waehrung);
	fprintf(umrechnungsFile, "Kontostand in Euro: \t %f \n", kontostand);
	fprintf(umrechnungsFile, "Kontostand in %s: \t %f", waehrung, waehrungsKontostand);
	fclose(umrechnungsFile);
}
void umrechnung(WAEHRUNGSMODUL* waehrungsmodul, char* waehrung)
{
	double kontostand = waehrungsmodul->getkontostand();
	int kontonummer = waehrungsmodul->getKontonummer();
	string kontonummerString = to_string(kontonummer);
	string textFileName = kontonummerString.append("_Umrechnung.txt");
	string waehrungsstring(waehrung);

	if (fileExist(textFileName))
	{
		// Delete File
		remove(textFileName.c_str());
	}

	if (waehrungsstring == "USD")
	{
		// 1� = 1.0971 USD
		double waehrungsKontostand = kontostand * 1.0971;
		createUmrechnungsFile(textFileName, "USD", kontostand, waehrungsKontostand);
	}
	else if (waehrungsstring == "CHF")
	{
		// 1� = 1.0866 CHF
		double waehrungsKontostand = kontostand * 1.0866;
		createUmrechnungsFile(textFileName, "CHF", kontostand, waehrungsKontostand);
	}
	else if (waehrungsstring == "GBP")
	{
		// 1� = 0.9003 GBP
		double waehrungsKontostand = kontostand * 0.9003;
		createUmrechnungsFile(textFileName, "GBP", kontostand, waehrungsKontostand);
	}
	else if (waehrungsstring == "JPY")
	{
		// 1� = 114.315 JPY
		double waehrungsKontostand = kontostand * 114.315;
		createUmrechnungsFile(textFileName, "JPY", kontostand, waehrungsKontostand);
	}
	else
	{
		LOGGING("Waehrungsmodul: Falscher Input.", "ERROR");
	}
}
void createKursverwaltungsFile(string textFileName)
{
	const char* fileName = textFileName.c_str();
	fopen_s(&kursverwaltungsFile, fileName, "a");
	if (kursverwaltungsFile == NULL)
	{
		LOGGING("Die Abbuchungsdatei konnte nicht erstellt werden HIER", "ERROR");
	}

	fprintf(kursverwaltungsFile, "Kursverwaltung \n \n");
	fprintf(kursverwaltungsFile, "1 � \t = \t 1.0971 USD \n1 � \t = \t 1.0866 CHF \n1 � \t = \t 0.9003 GBP \n1 � \t = \t 114.315 JPY \n");
	fclose(kursverwaltungsFile);
}
void kursverwaltung(WAEHRUNGSMODUL* waehrungsmodul)
{
	int kontonummer = waehrungsmodul->getKontonummer();
	string kontonummerString = to_string(kontonummer);
	string textFileName = kontonummerString.append("_Kursverwaltung.txt");

	if (fileExist(textFileName))
	{
		// Delete File
		remove(textFileName.c_str());
	}

	createKursverwaltungsFile(textFileName);
}
// Funktionen f�r die C-Schnittstelle
// USD, CHF, GBP, JPY
void doUmrechnung(WAEHRUNGSMODUL* waehrungsmmodul, char* waehrung)
{
	umrechnung(waehrungsmmodul, waehrung);
}
void doKursverwaltung(WAEHRUNGSMODUL* waehrungsmodul)
{
	kursverwaltung(waehrungsmodul);
}
WAEHRUNGSMODUL* NeuesWaehrungsmodul(KREDITKONTO* konto)
{
	double kontostand = konto->getKontostand();
	int kontonummer = konto->getKontonummer();

	WAEHRUNGSMODUL* waehrungsmodul = new WAEHRUNGSMODUL();
	waehrungsmodul->setkontostand(kontostand);
	waehrungsmodul->setKontonummer(kontonummer);
	
	LOGGING("Ein Waehrungsmodul wurde getaetigt.", "OK");
	return waehrungsmodul;
}