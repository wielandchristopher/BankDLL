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
FILE* umrechnungsFile;
FILE* kursverwaltungsFile;
char* USER_FILE = "customer.json";
char* KREDITKONTO_FILE = "kreditkonten.json";
char* SPARKONTO_FILE = "sparkonten.json";

char* SPARKONTO_ROOT = "sparkonten";
char* KREDITKONTO_ROOT = "kreditkonten";
char* USER_ROOT = "users";

CUSTOMER* readUser(int id);
bool userExist(int id);
bool kreditkontoExist(int ktnr);
bool sparkontoExist(int ktnr);
void writeCount(int);
int readCount();
int readUserCount();
void writeUserCount(int);


//generateKtnr erstellt eine Kontonummer und incrementiert immer um 1 hoch
int generateKtnnr() {

	//static int Kontonummernpool = 10000000;
	int actNr = readCount();
	actNr++;
	writeCount(actNr);

	return actNr;
	//Kontonummernpool++;
	//return Kontonummernpool;
}
//generateUserid erstellt eine neue UserID für jeden neuen User
int generateUserid() {


	int actNr = readUserCount();
	actNr++;

	writeUserCount(actNr);
	return actNr;

/*
	static int Userid = 0;

	Userid++;
	return Userid;*/
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

	// WAEHRUNG UNNÖTIG
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

bool createUserCountFile() {
	cJSON* saveObj = cJSON_CreateObject();
	cJSON_AddItemToObject(saveObj, "userct", cJSON_CreateNumber(10000000));

	if (writeJsonFile("User.json", saveObj)) {
		return true;
	}
	else {
		return false;
	}
}

bool createCreditNumberCountFile() {
	cJSON* saveObj = cJSON_CreateObject();
	cJSON_AddItemToObject(saveObj, "kontoct", cJSON_CreateNumber(10000000));

	if (writeJsonFile("konten.json", saveObj)) {
		return true;
	}
	else {
		return false;
	}
}
int readCount() {


	cJSON* jsn = readJsonFile_cJson("Konten.json");
	if (jsn == NULL) {
		createCreditNumberCountFile();
		jsn = readJsonFile_cJson("Konten.json");
	}

	return cJSON_GetObjectItem(jsn, "kontoct")->valueint;
}
void writeCount(int ct) {
	cJSON* jsn = readJsonFile_cJson("Konten.json");
	if (jsn == NULL) {
		createCreditNumberCountFile();
		jsn = readJsonFile_cJson("Konten.json");
	}
	cJSON* newitem = cJSON_CreateNumber(ct);
	cJSON_ReplaceItemInObject(jsn, "kontoct", newitem);
	writeJsonFile("Konten.json", jsn);
}

int readUserCount() {


	cJSON* jsn = readJsonFile_cJson("User.json");
	if (jsn == NULL) {
		createUserCountFile();
		jsn = readJsonFile_cJson("User.json");
	}

	return cJSON_GetObjectItem(jsn, "userct")->valueint;
}
void writeUserCount(int ct) {
	cJSON* jsn = readJsonFile_cJson("User.json");
	if (jsn == NULL) {
		createUserCountFile();
		jsn = readJsonFile_cJson("User.json");
	}
	cJSON* newitem = cJSON_CreateNumber(ct);
	cJSON_ReplaceItemInObject(jsn, "userct", newitem);
	writeJsonFile("User.json", jsn);
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
		cJSON_AddItemToObject(kontoObject, "VerfügerID", cJSON_CreateNumber(sk->getVerfüger().getID()));
		//CUSTOMER c = sk->getoptVerfüger1();
		/*int id;
		
		if (c.getID() == NULL) {
			cout << c.getID() << endl;
		}*/
		

		//if (sk->getoptVerfüger1().getID() == NULL) {
		//	cJSON_AddItemToObject(kontoObject, "optVerfüger1ID", cJSON_CreateNumber(0));
		//}
		//else {
		//	cJSON_AddItemToObject(kontoObject, "optVerfüger1ID", cJSON_CreateNumber(sk->getoptVerfüger1().getID()));
		//}
	
		//if (sk->getoptVerfüger2().getID() == NULL) {
		//	cJSON_AddItemToObject(kontoObject, "optVerfüger2ID", cJSON_CreateNumber(0));
		//}
		//else {
		//	cJSON_AddItemToObject(kontoObject, "optVerfüger2ID", cJSON_CreateNumber(sk->getoptVerfüger2().getID()));
		//}
		//if (sk->getoptVerfüger3().getID() == NULL) {
		//	cJSON_AddItemToObject(kontoObject, "optVerfüger3ID", cJSON_CreateNumber(0));
		//}
		//else {
		//	cJSON_AddItemToObject(kontoObject, "optVerfüger3ID", cJSON_CreateNumber(sk->getoptVerfüger3().getID()));
		//}
		

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
		newktObj->setoptVerfüger1(readUser(cJSON_GetObjectItem(skItem, "optVerfüger1ID")->valueint));
		newktObj->setoptVerfüger2(readUser(cJSON_GetObjectItem(skItem, "optVerfüger2ID")->valueint));
		newktObj->setoptVerfüger3(readUser(cJSON_GetObjectItem(skItem, "optVerfüger3ID")->valueint));

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
		cJSON_AddItemToObject(kontoObject, "VerfügerID", cJSON_CreateNumber(sk->getVerfüger().getID()));
		//cout << "failss" << endl;
		//if ((sk->getoptVerfüger1().getID()) == NULL) {
		//	cJSON_AddItemToObject(kontoObject, "optVerfüger1ID", cJSON_CreateNumber(0));
		//	cout << "fail" << endl;
		//}
		//else {
		//	cJSON_AddItemToObject(kontoObject, "optVerfüger1ID", cJSON_CreateNumber(sk->getoptVerfüger1().getID()));
		//	cout << "fail" << endl;
		//}

		//if ((sk->getoptVerfüger2().getID()) == NULL) {
		//	cJSON_AddItemToObject(kontoObject, "optVerfüger2ID", cJSON_CreateNumber(0));
		//}
		//else {
		//	cJSON_AddItemToObject(kontoObject, "optVerfüger2ID", cJSON_CreateNumber(sk->getoptVerfüger2().getID()));
		//}
		//if ((sk->getoptVerfüger3().getID()) == NULL) {
		//	cJSON_AddItemToObject(kontoObject, "optVerfüger3ID", cJSON_CreateNumber(0));
		//}
		//else {
		//	cJSON_AddItemToObject(kontoObject, "optVerfüger3ID", cJSON_CreateNumber(sk->getoptVerfüger3().getID()));
		//}
		//cout << "fail" << endl;
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
		newktObj->setVerfüger(readUser(cJSON_GetObjectItem(skItem, "VerfügerID")->valueint));
		newktObj->setoptVerfüger1(readUser(cJSON_GetObjectItem(skItem, "optVerfüger1ID")->valueint));
		newktObj->setoptVerfüger2(readUser(cJSON_GetObjectItem(skItem, "optVerfüger2ID")->valueint));
		newktObj->setoptVerfüger3(readUser(cJSON_GetObjectItem(skItem, "optVerfüger3ID")->valueint));

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
	cJSON_AddItemToObject(saveObj, "users", cJSON_CreateArray());

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
		cJSON * arr = cJSON_GetObjectItem(fileObj, USER_ROOT); 
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
	else {
		cout << "user exist" << endl;
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
		cout << "konto nicht gefunden" << endl;
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
		cout << "konto existiert nicht" << endl; //@@ schreiben in log files!!
	}
	return false; // wenn file = NULL dann kann er nichts schreiben somit false
}

// Sparkonto hinzufügen wenn noch nicht vorhanden
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
			printObject(saveObj);
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

// Sparkonto mit kontonr löschen
bool removeSparKonto(int ktnr) {
	cJSON * fileObj = readJsonFile_cJson(SPARKONTO_FILE);

	if (fileObj != NULL) {
		cJSON * arr = cJSON_GetObjectItem(fileObj, SPARKONTO_ROOT);

		int size = cJSON_GetArraySize(arr);

		for (int x = 0; x < size; x++) {
			cJSON * item = cJSON_GetArrayItem(arr, x);

			if (checkKtItem(item, ktnr)) {
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

/*  ---------------------  */
/*       KREDITKONTO       */
/*  ---------------------  */
// Sparkonto einlesen 
SPARKONTO* readKreditKonto(int ktnr) {
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
				return cJSONToSparkonto(item);
			}
		}
		cout << "konto nicht gefunden" << endl;
	}
	return NULL; // wenn file leer dann kann er nichts lesen -> somit NULL
}

// Sparkonto eintragen
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
		cout << "konto existiert nicht" << endl; //@@ schreiben in log files!!
	}
	return false; // wenn file = NULL dann kann er nichts schreiben somit false
}

// Sparkonto hinzufügen wenn noch nicht vorhanden
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

			printObject(saveObj);
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

// Sparkonto mit kontonr löschen
bool removeKreditKonto(int ktnr) {
	cJSON * fileObj = readJsonFile_cJson(KREDITKONTO_FILE);

	if (fileObj != NULL) {
		cJSON * arr = cJSON_GetObjectItem(fileObj, KREDITKONTO_ROOT);

		int size = cJSON_GetArraySize(arr);

		for (int x = 0; x < size; x++) {
			cJSON * item = cJSON_GetArrayItem(arr, x);

			if (checkKtItem(item, ktnr)) {
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

//Prüft die Existenz eines angegebenen Kontos, bei existenz = true
bool sparkontoExist(int ktnr) {
	cJSON * fileObj = readJsonFile_cJson(SPARKONTO_FILE);

	if (fileObj != NULL) {
		cJSON * arr = cJSON_GetObjectItem(fileObj, "sparkonten");
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

// Initialisierung: Header für das Buchungs File wird erstellt
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
	fprintf(buchungsfile, "%s \t %s \t \t \t \t \t %s \n", time, verwendungszweck, betrag);
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
	Kunde->setKtnr1(0);
	Kunde->setKtnr2(0);
	Kunde->setKtnr3(0);
	Kunde->setKtnr4(0);
	Kunde->setKtnr5(0);

	/* gibt false zurück wenn user nicht geadded werden konnte*/
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

	// TODO für andere methoden
	//CUSTOMER* cust = readUser(Kunde->getID());
	if (Kunde->getKtnr1() == 0) {
		Kunde->setKtnr1(Konto->getKontonummer()); // ACHTUNG vorher überprüfen ob KTNR vorher 0 sonst wird etwas bestehendes überschrieben
	}
	else {
		Kunde->setKtnr2(Konto->getKontonummer());
	}
	writeUser(Kunde);

	LOGGING("Das KreditKonto wurde erfolgreich erstellt.", "OK");
	addKreditKonto(Konto);
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
	addKreditKonto(Konto);
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
	addKreditKonto(Konto);
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
	addKreditKonto(Konto);
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
	removeKreditKonto(Konto->getKontonummer());
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
UEBERWEISUNG* NeueUeberweisung(KREDITKONTO* quellkonto, KREDITKONTO* zielkonto, double betrag, char* verwendungszweck)
{
	string Verfügervorname = zielkonto->getVerfüger().getVorname();
	string Verfügernachname = zielkonto->getVerfüger().getNachname();
	string Verfügername = Verfügervorname + Verfügernachname;
	char* cVerfügername = (char*)Verfügername.c_str();

	//double newKontostand = zielkonto->getKontostand() + betrag;
	//zielkonto->setKontostand(newKontostand);

	// Mit doEinzahlen - scheint am anderen Konto im Kontoauszug auf
	doEinzahlen(zielkonto, verwendungszweck, betrag);

	UEBERWEISUNG* ueberweisung = new UEBERWEISUNG();
	ueberweisung->setempfaengername(cVerfügername);
	ueberweisung->setkontonummer(zielkonto->getKontonummer());
	// ueberweisung->setkontostand(newKontostand);	
	ueberweisung->setVerwendungszweck(verwendungszweck);
	ueberweisung->setBetrag(betrag);

	// Betrag vom Quellkonto abbuchen
	double quellKontostand = quellkonto->getKontostand();
	quellkonto->setKontostand(quellKontostand - betrag);

	LOGGING("Eine Überweisung wurde getaetigt.", "OK");
	Buchen(quellkonto, verwendungszweck, betrag, 1);
	return ueberweisung;
}

void createUmrechnungsFile(string textFileName, char* waehrung, double kontostand, double waehrungsKontostand)
{
	const char* fileName = textFileName.c_str();
	fopen_s(&umrechnungsFile, fileName, "a");
	if (umrechnungsFile == NULL)
	{
		printf("Die Abbuchungsdatei konnte nicht erstellt werden HIER");
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
		// 1€ = 1.0971 USD
		double waehrungsKontostand = kontostand * 1.0971;
		createUmrechnungsFile(textFileName, "USD", kontostand, waehrungsKontostand);
	}
	else if (waehrungsstring == "CHF")
	{
		// 1€ = 1.0866 CHF
		double waehrungsKontostand = kontostand * 1.0866;
		createUmrechnungsFile(textFileName, "CHF", kontostand, waehrungsKontostand);
	}
	else if (waehrungsstring == "GBP")
	{
		// 1€ = 0.9003 GBP
		double waehrungsKontostand = kontostand * 0.9003;
		createUmrechnungsFile(textFileName, "GBP", kontostand, waehrungsKontostand);
	}
	else if (waehrungsstring == "JPY")
	{
		// 1€ = 114.315 JPY
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
		printf("Die Abbuchungsdatei konnte nicht erstellt werden HIER");
	}

	fprintf(kursverwaltungsFile, "Kursverwaltung \n \n");
	fprintf(kursverwaltungsFile, "1 € \t = \t 1.0971 USD \n1 € \t = \t 1.0866 CHF \n1 € \t = \t 0.9003 GBP \n1 € \t = \t 114.315 JPY \n");
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

// Funktionen für die C-Schnittstelle
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