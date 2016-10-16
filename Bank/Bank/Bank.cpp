/*
Bei NeuesKonto muss ein Verweis zum Kunden hergestellt werden.
Customer braucht eine Liste, in welcher alle evtl. Konten aufgelistet sind. 
Liste wird �ber JSON geregelt, sobald WriteUser etc vom Martin funktioniert. 

Wenn implementiert, kann man vor dem L�schen eines USers auf evtl noch ge�ffneten Konten pr�fen. 

Funktionen: 

KreditKonto kann bisher noch nicht persistent erstellt werden - nur SparKonto
Funktion �berweisung �berweist nur an ein ziel, hebt aber nicht von einem QuellKonto ab.
users.json und konten.json wird nicht bearbeitet. es bleibt beim aller ersten eintrag. 
*/

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
char* USER_FILE = "users.json";
char* KONTO_FILE = "konten.json";

CUSTOMER* readUser(int id);
bool userExist(int id);
bool kontoExist(int ktnr);

//generateKtnr erstellt eine Kontonummer und incrementiert immer um 1 hoch
int generateKtnnr() {

	static int Kontonummernpool = 10000000;

	Kontonummernpool++;
	return Kontonummernpool;
}
//generateUserid erstellt eine neue UserID f�r jeden neuen User
int generateUserid() {

	static int Userid = 0;

	Userid++;
	return Userid;
}

/* ----------------- */
/* Ben�tigte Klassen */
/* ----------------- */

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
	int CUSTOMER::getID() {
		return id;
	};
	void CUSTOMER::setID(int _id) {
		this->id = _id;
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
	int id = generateUserid();
};
class SPARKONTO {
public:
	SPARKONTO::SPARKONTO()
	{
		this->sparkonto = "sparkonto";
		setKontonummer(generateKtnnr());
		this->Kontostand = 0;
		this->Kontoverf�ger = NULL;
		this->optKontoverf�ger1 = NULL;
		this->optKontoverf�ger2 = NULL;
		this->optKontoverf�ger3 = NULL;

	}

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
	char* SPARKONTO::getClassId() {

		return sparkonto;
	}

private:
	char* sparkonto;
	int Kontonummer;
	double Kontostand;
	CUSTOMER* Kontoverf�ger;
	CUSTOMER* optKontoverf�ger1;
	CUSTOMER* optKontoverf�ger2;
	CUSTOMER* optKontoverf�ger3;
};
class KREDITKONTO {
public:
	KREDITKONTO::KREDITKONTO()
	{
		this->kreditkonto = "kreditkonto";
		setKontonummer(generateKtnnr());
		this->Kontostand = 0;
		this->Kontoverf�ger = NULL;
		this->optKontoverf�ger1 = NULL;
		this->optKontoverf�ger2 = NULL;
		this->optKontoverf�ger3 = NULL;

	}

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
	char* getClassId() {

		return kreditkonto;
	}

private:
	char* kreditkonto;
	int Kontonummer;
	double Kontostand;
	CUSTOMER* Kontoverf�ger;
	CUSTOMER* optKontoverf�ger1;
	CUSTOMER* optKontoverf�ger2;
	CUSTOMER* optKontoverf�ger3;
};
class KONTOAUSZUG {
public:
	KONTOAUSZUG::KONTOAUSZUG()
	{

	}

};
class UEBERWEISUNG {
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

		if (!json) { printf("Error before: [%s]\n", cJSON_GetErrorPtr()); }
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
	cJSON *json;

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
		printf("Fehler beim oeffnen der Datei.");
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
		printf("Error before: [%s]\n", cJSON_GetErrorPtr());
		return false;
	}
	else
	{
		FILE *datei;
		datei = fopen(filename, "r+");
		if (datei == NULL)
		{
			printf("Fehler beim oeffnen der Datei.");
			return false;
		}
		fprintf(datei, cJSON_Print(newjobj));
		fclose(datei);
	}
	return true;
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
		return userObject;
	}
	return NULL;

}

/* Hilfsfunktion - Umwandlung SPARKONTO to JSON */
cJSON* kontoTocJSON(SPARKONTO* sk) {

	if (sk != NULL) {
		cJSON* kontoObject = cJSON_CreateObject();

		cJSON_AddItemToObject(kontoObject, "Kontonummer", cJSON_CreateNumber(sk->getKontonummer()));
		cJSON_AddItemToObject(kontoObject, "Kontostand", cJSON_CreateNumber(sk->getKontostand()));
		cJSON_AddItemToObject(kontoObject, "Verf�gerID", cJSON_CreateNumber(sk->getVerf�ger().getID()));

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
		newktObj->setVerf�ger(readUser(cJSON_GetObjectItem(skItem, "Verf�gerID")->valueint));

		return newktObj;
	}

	return NULL;
}

/* ---------------------------- */
/*        Hilfsfunktonen        */
/* ---------------------------- */

/* Hilfsfunktion - cJSON Object ausgeben*/
void printObject(cJSON* obj) {
	if (obj != NULL) {
		cout << cJSON_Print(obj) << endl;
	}
	else {
		cout << "Auszugebenes cJSON objekt : NULL" << endl;
	}
}

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

/* Hilfsfunktion - Vergleich der ID werte */
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
	cJSON_AddItemToObject(saveObj, "users", cJSON_CreateArray());

	if (writeJsonFile(USER_FILE, saveObj)) {
		return true;
	}
	else {
		return false;
	}
}

/* Hilfsfunktion - wenn Kontofile nicht existiert */
bool createKontoFile() {
	cJSON* saveObj = cJSON_CreateObject();
	cJSON_AddItemToObject(saveObj, "konten", cJSON_CreateArray());

	if (writeJsonFile(KONTO_FILE, saveObj)) {
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
		cJSON * arr = cJSON_GetObjectItem(fileObj, "users");
		int size = cJSON_GetArraySize(arr);

		for (int x = 0; x < size; x++) {
			cJSON * item = cJSON_GetArrayItem(arr, x);

			if (checkItem(item, id)) {
				return cJSONToCustomer(item);
			}
		}
		cout << "user nicht gefunden" << endl;
	}
	return NULL; // return NULL wenn file leer
}

/* �berschreibt user, false wenn user nicht vorhanden (sollte nicht m�glich sein) */
bool writeUser(CUSTOMER* cust) {

	if (userExist(cust->getID())) {
		cJSON * fileObj = readJsonFile_cJson(USER_FILE);

		if (fileObj != NULL) {
			cJSON * arr = cJSON_GetObjectItem(fileObj, "users");
			int size = cJSON_GetArraySize(arr);

			for (int x = 0; x < size; x++) {
				cJSON * item = cJSON_GetArrayItem(arr, x);
				if (checkItem(item, cust->getID())) {
					cJSON_ReplaceItemInArray(arr, x, customerTocJSON(cust));
					cJSON* saveObj = cJSON_CreateObject();
					cJSON_AddItemToObject(saveObj, "users", arr);

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
		cout << "user existiert nicht. deshalb nicht �berschreibbar" << endl;
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
			cJSON * arr = cJSON_GetObjectItem(fileObj, "users");
			int size = cJSON_GetArraySize(arr);

			cJSON_AddItemToArray(arr, customerTocJSON(cu));
			cJSON* saveObj = cJSON_CreateObject();
			cJSON_AddItemToObject(saveObj, "users", arr);

			printObject(saveObj);
			if (writeJsonFile(USER_FILE, saveObj)) {
				return true;
			}
			else {
				return false;
			}
		}
	}
	return false;
}

/* user mit id l�schen - achtung noch aktive konten?*/
bool removeUser(int id) {

	cJSON * fileObj = readJsonFile_cJson(USER_FILE);

	if (fileObj != NULL) {
		cJSON * arr = cJSON_GetObjectItem(fileObj, "users");

		int size = cJSON_GetArraySize(arr);

		for (int x = 0; x < size; x++) {
			cJSON * item = cJSON_GetArrayItem(arr, x);

			if (checkItem(item, id)) {
				cJSON_DeleteItemFromArray(arr, x);
				cJSON* saveObj = cJSON_CreateObject();
				cJSON_AddItemToObject(saveObj, "users", arr);

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
		cJSON * arr = cJSON_GetObjectItem(fileObj, "users");
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

/*  -------------------  */
/*       SPARKONTO       */
/*  -------------------  */

// Sparkonto einlesen 
SPARKONTO* readSparKonto(int ktnr) {
	cJSON * fileObj = readJsonFile_cJson(KONTO_FILE);

	if (fileObj == NULL) {
		createKontoFile();
	}
	else {
		cJSON * arr = cJSON_GetObjectItem(fileObj, "konten");
		int size = cJSON_GetArraySize(arr);

		for (int x = 0; x < size; x++) {
			cJSON * item = cJSON_GetArrayItem(arr, x);

			if (checkKtItem(item, ktnr)) {
				return cJSONToSparkonto(item);
			}
		}
		cout << "konto nicht gefunden" << endl;
	}
	return NULL; // wenn file leer dann kann er nichts lesen -> somit NULL
}

// Sparkonto eintragen
bool writeSparKonto(SPARKONTO* kt) {

	if (kontoExist(kt->getKontonummer())) {
		cJSON * fileObj = readJsonFile_cJson(KONTO_FILE);

		if (fileObj != NULL) {
			cJSON * arr = cJSON_GetObjectItem(fileObj, "konten");
			int size = cJSON_GetArraySize(arr);

			for (int x = 0; x < size; x++) {
				cJSON * item = cJSON_GetArrayItem(arr, x);
				if (checkKtItem(item, kt->getKontonummer())) {
					cJSON_ReplaceItemInArray(arr, x, kontoTocJSON(kt));
					cJSON* saveObj = cJSON_CreateObject();
					cJSON_AddItemToObject(saveObj, "konten", arr);

					if (writeJsonFile(KONTO_FILE, saveObj)) {
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
		cout << "konto existiert nicht" << endl; //@@ schreiben in log files!!
	}
	return false; // wenn file = NULL dann kann er nichts schreiben somit false
}

// Sparkonto hinzuf�gen wenn noch nicht vorhanden
bool addSparKonto(SPARKONTO* kt) {
	if (!kontoExist(kt->getKontonummer())) {
		cJSON * fileObj = readJsonFile_cJson(KONTO_FILE);

		if (fileObj == NULL) {
			createKontoFile();
			fileObj = readJsonFile_cJson(KONTO_FILE);
		}

		if (fileObj != NULL) {
			cJSON * arr = cJSON_GetObjectItem(fileObj, "konten");
			int size = cJSON_GetArraySize(arr);

			cJSON_AddItemToArray(arr, kontoTocJSON(kt));
			cJSON* saveObj = cJSON_CreateObject();
			cJSON_AddItemToObject(saveObj, "konten", arr);

			printObject(saveObj);
			if (writeJsonFile(KONTO_FILE, saveObj)) {
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
	cJSON * fileObj = readJsonFile_cJson(KONTO_FILE);

	if (fileObj != NULL) {
		cJSON * arr = cJSON_GetObjectItem(fileObj, "konten");

		int size = cJSON_GetArraySize(arr);

		for (int x = 0; x < size; x++) {
			cJSON * item = cJSON_GetArrayItem(arr, x);

			if (checkKtItem(item, ktnr)) {
				cJSON_DeleteItemFromArray(arr, x);
				cJSON* saveObj = cJSON_CreateObject();
				cJSON_AddItemToObject(saveObj, "konten", arr);

				if (writeJsonFile(KONTO_FILE, saveObj)) {
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

/*  ---------------------  */
/*       KREDITKONTO       */
/*  ---------------------  */

/* Noch in Bearbeitung */



//Pr�ft die Existenz eines angegebenen Kontos, bei existenz = true
bool kontoExist(int ktnr) {
	cJSON * fileObj = readJsonFile_cJson(KONTO_FILE);

	if (fileObj != NULL) {
		cJSON * arr = cJSON_GetObjectItem(fileObj, "konten");
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
	const char* test = name.c_str();
	struct stat buffer;
	return (stat(test, &buffer) == 0);
}

void initializeBuchungen(int kontonummer, string textFileName)
{
	const char* fileName = textFileName.c_str();
	fopen_s(&buchungsfile, fileName, "a");
	if (buchungsfile == NULL)
	{
		printf("Die Abbuchungsdatei konnte nicht erstellt werden HIER");
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
		printf("Die Abbuchungsdatei konnte nicht erstellt werden");
	}
	fprintf(buchungsfile, "%s \t %s \t \t \t \t \t %s \n", time, verwendungszweck, betrag); // Tabelle ?
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

	addUser(Kunde);
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

	if (Kunde->getClassId() != "customer") {
		LOGGING("Es wurde kein Kunde �bergeben.", "ERROR");
		return;
	}

	if (Kunde == NULL) {
		LOGGING("Der �bergebene Kunde existiert nicht oder ist NULL.", "OK");
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
	addSparKonto(Konto);
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
	addSparKonto(Konto);
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
	addSparKonto(Konto);
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
	addSparKonto(Konto);
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
	removeSparKonto(Konto->getKontonummer());
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

//Funktionen zum �berweisen, Einzahlen und Abheben
void doAbheben(KREDITKONTO* zielkonto, double betrag) 
{

	double newKontostand = zielkonto->getKontostand() - betrag;
	zielkonto->setKontostand(newKontostand);
	char* verwendungszweck = "";

	LOGGING("Eine Abhebung wurde getaetigt.", "OK");
	Buchen(zielkonto, verwendungszweck, betrag, 2);
}
void doEinzahlen(KREDITKONTO* zielkonto, char* verwendungszweck, double betrag)
{

	double newKontostand = zielkonto->getKontostand() + betrag;
	zielkonto->setKontostand(newKontostand);

	LOGGING("Eine Einzahlung wurde getaetigt.", "OK");
	Buchen(zielkonto, verwendungszweck, betrag, 3);
}
UEBERWEISUNG* NeueUeberweisung(KREDITKONTO* zielkonto, double betrag, char* verwendungszweck) 
{
	string Verf�gervorname = zielkonto->getVerf�ger().getVorname();
	string Verf�gernachname = zielkonto->getVerf�ger().getNachname();
	string Verf�gername = Verf�gervorname + Verf�gernachname;
	char* cVerf�gername = (char*)Verf�gername.c_str();

	double newKontostand = zielkonto->getKontostand() + betrag;
	zielkonto->setKontostand(newKontostand);

	UEBERWEISUNG* ueberweisung = new UEBERWEISUNG();
	ueberweisung->setempfaengername(cVerf�gername);
	ueberweisung->setkontonummer(zielkonto->getKontonummer());
	ueberweisung->setkontostand(newKontostand);
	ueberweisung->setVerwendungszweck(verwendungszweck);
	ueberweisung->setBetrag(betrag);

	LOGGING("Eine �berweisung wurde getaetigt.", "OK");
	Buchen(zielkonto, verwendungszweck, betrag, 1);
	return ueberweisung;
}