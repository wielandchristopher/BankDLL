/*
Bei NeuesKonto muss ein Verweis zum Kunden hergestellt werden.
Customer braucht eine Liste, in welcher alle evtl. Konten aufgelistet sind. 
Liste wird über JSON geregelt, sobald WriteUser etc vom Martin funktioniert. 

Wenn implementiert, kann man vor dem Löschen eines USers auf evtl noch geöffneten Konten prüfen. 

Funktionen: 

KreditKonto kann bisher noch nicht persistent erstellt werden - nur SparKonto
Funktion Überweisung überweist nur an ein ziel, hebt aber nicht von einem QuellKonto ab.
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
//generateUserid erstellt eine neue UserID für jeden neuen User
int generateUserid() {

	static int Userid = 0;

	Userid++;
	return Userid;
}

/* ----------------- */
/* Benötigte Klassen */
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
		cJSON_AddItemToObject(kontoObject, "VerfügerID", cJSON_CreateNumber(sk->getVerfüger().getID()));

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
		newktObj->setVerfüger(readUser(cJSON_GetObjectItem(skItem, "VerfügerID")->valueint));

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
/*   Funktionen für persistente Datenspeicherung   */
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

/* Überschreibt user, false wenn user nicht vorhanden (sollte nicht möglich sein) */
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
		cout << "user existiert nicht. deshalb nicht überschreibbar" << endl;
	}
	return false; // wenn file = NULL dann kann er nichts schreiben somit false
}

/* User hinzufügen wenn noch nicht vorhanden */
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

/* user mit id löschen - achtung noch aktive konten?*/
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

// Sparkonto hinzufügen wenn noch nicht vorhanden
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

// Sparkonto mit kontonr löschen
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



//Prüft die Existenz eines angegebenen Kontos, bei existenz = true
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

//Hilftsfunktion - für die Buchungsfunktion
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

//Funktion, um die Getätigte Buchung/Überweisung in ein Logfile zu schreiben "Buchungen.txt"
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
	writeUser(Kunde);
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
	writeUser(Kunde);
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
	writeUser(Kunde);
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
	writeUser(Kunde);
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
	writeUser(Kunde);
	LOGGING("Die Telefonnummer wurde erfolgreich geändert.", "OK");
	return;
}
//Hier können die Kundendaten erneut abgefragt werden
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
		removeUser(Kunde->getID());
		delete Kunde;
		LOGGING("Der Kunde wurde erfolgreich entfernt.", "OK");
	}
}

/* ------------------------- */
/*   Funktionen der Konten   */
/* ------------------------- */

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
	addSparKonto(Konto);
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
	addSparKonto(Konto);
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
	addSparKonto(Konto);
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
	addSparKonto(Konto);
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
	removeSparKonto(Konto->getKontonummer());
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

//Funktionen zum Überweisen, Einzahlen und Abheben
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