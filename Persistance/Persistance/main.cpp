//#include "main.h"
#include <iostream>
#include <stdio.h>
#include <string>
#include "cJSON.h"
#include "KONTO.h"
#include "USTOMER.h"
#pragma warning (disable : 4996)


using namespace std;
//using namespace Persistance;


char* USER_FILE			= "users.json";
char* KONTO_FILE		= "konten.json";

CUSTOMER*	readUser(int id);
bool		userExist(int id);
bool		kontoExist(int ktnr);

	/* --------------------------- */
	/* JSON -> File-I/O Funktionen */
	/* --------------------------- */


	/* Read a file and return the string */
	cJSON*	readJsonFile_cJson(char *filename)
	{
		FILE *f; 
		long len; 
		char *data;
		cJSON *json;

		f = fopen(filename, "rb"); 

		if (f != NULL){
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
	char*	readJsonFile_char(char *filename)
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
	bool	writeJsonFile(char *filename, cJSON * jobj){
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
	bool	writeJsonFile(char *filename, char* jobj){

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
	CUSTOMER*	cJSONToCustomer(cJSON* customerItem){
	
		if (customerItem != NULL){
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
	cJSON*		customerTocJSON(CUSTOMER* cust){

		if (cust != NULL){
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
	cJSON*		kontoTocJSON(SPARKONTO* sk){

		if (sk != NULL){
			cJSON* kontoObject = cJSON_CreateObject();

			cJSON_AddItemToObject(kontoObject, "Kontonummer", cJSON_CreateNumber(sk->getKontonummer()));
			cJSON_AddItemToObject(kontoObject, "Kontostand", cJSON_CreateNumber(sk->getKontostand()));
			cJSON_AddItemToObject(kontoObject, "VerfügerID", cJSON_CreateNumber(sk->getVerfüger().getID()));

			return kontoObject;
		}
		return NULL;
	}

	/* Hilfsfunktion - Umwandlung cJSON to SPARKONTO */
	SPARKONTO*	cJSONToSparkonto(cJSON* skItem){

		if (skItem != NULL){
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
	void printObject(cJSON* obj){
		if (obj != NULL){
			cout << cJSON_Print(obj) << endl;
		}
		else{
			cout << "Auszugebenes cJSON objekt : NULL" << endl;
		}
	}

	/* Hilfsfunktion - Vergleich der ID werte */
	bool checkItem(cJSON * item, int id)  {

		cJSON * iditem = cJSON_GetObjectItem(item, "id");

		if (iditem->valueint == id){
			return true;
		}
		else{
			return false;
		}
	}

	/* Hilfsfunktion - Vergleich der ID werte */
	bool checkKtItem(cJSON * item, int id)  {

		cJSON * iditem = cJSON_GetObjectItem(item, "Kontonummer");

		if (iditem->valueint == id){
			return true;
		}
		else{
			return false;
		}
	}

	/* Hilfsfunktion - wenn Userfile nicht existiert */
	bool createUserFile(){
		cJSON* saveObj = cJSON_CreateObject();
		cJSON_AddItemToObject(saveObj, "users", cJSON_CreateArray());

		if (writeJsonFile(USER_FILE, saveObj)){
			return true;
		}
		else{
			return false;
		}
	}

	/* Hilfsfunktion - wenn Kontofile nicht existiert */
	bool createKontoFile(){
		cJSON* saveObj = cJSON_CreateObject();
		cJSON_AddItemToObject(saveObj, "konten", cJSON_CreateArray());

		if (writeJsonFile(KONTO_FILE, saveObj)){
			return true;
		}
		else{
			return false;
		}
	}


	/* ------------------------------------------- */
	/*   Verarbeitungsfunktionen für DLL zugriff   */
	/* ------------------------------------------- */

	/*  ----------------  */
	/*      CUSTOMER      */
	/*  ----------------  */


	/* Liest vorhandenen user mit ID aus. NULL wenn nicht vorhanden */
	CUSTOMER*	readUser(int id){

		cJSON * fileObj = readJsonFile_cJson(USER_FILE);

		if (fileObj == NULL){
			createUserFile();
		}else
		{
			cJSON * arr = cJSON_GetObjectItem(fileObj, "users");
			int size = cJSON_GetArraySize(arr);
		
			for (int x = 0; x < size; x++){
				cJSON * item = cJSON_GetArrayItem(arr, x);
			
				if (checkItem(item, id)){
					return cJSONToCustomer(item);
				}
			}		
			cout << "user nicht gefunden" << endl;
		}
		return NULL; // return NULL wenn file leer
	}

	/* Überschreibt user, false wenn user nicht vorhanden (sollte nicht möglich sein) */
	bool		writeUser(CUSTOMER* cust){

		if (userExist(cust->getID())){
			cJSON * fileObj = readJsonFile_cJson(USER_FILE);

			if (fileObj != NULL){
				cJSON * arr = cJSON_GetObjectItem(fileObj, "users");
				int size = cJSON_GetArraySize(arr);

				for (int x = 0; x < size; x++){
					cJSON * item = cJSON_GetArrayItem(arr, x);
					if (checkItem(item, cust->getID())){
						cJSON_ReplaceItemInArray(arr, x, customerTocJSON(cust));
						cJSON* saveObj = cJSON_CreateObject();
						cJSON_AddItemToObject(saveObj, "users", arr);

						if (writeJsonFile(USER_FILE, saveObj)){
							return true;
						}
						else{
							return false;
						}
					}
				}
			}
		}
		else{
			cout << "user existiert nicht. deshalb nicht überschreibbar" << endl;
		}
		return false; // wenn file = NULL dann kann er nichts schreiben somit false
	}

	/* User hinzufügen wenn noch nicht vorhanden */
	bool		addUser(CUSTOMER* cu){
		
		// @@ wenn konto auf customer gespeichert muss getestet werden ob es das konto auch gibt das angelegt werden soll!!!
		
		if (!userExist(cu->getID())){
			cJSON * fileObj = readJsonFile_cJson(USER_FILE);

			if (fileObj == NULL){
				createUserFile();
				fileObj = readJsonFile_cJson(USER_FILE);
			}

			if (fileObj != NULL){
				cJSON * arr = cJSON_GetObjectItem(fileObj, "users");
				int size = cJSON_GetArraySize(arr);

				cJSON_AddItemToArray(arr, customerTocJSON(cu));
				cJSON* saveObj = cJSON_CreateObject();
				cJSON_AddItemToObject(saveObj, "users", arr);

				printObject(saveObj);
				if (writeJsonFile(USER_FILE, saveObj)){
					return true;
				}
				else{
					return false;
				}
			}
		}
		return false;
	}

	/* user mit id löschen - achtung noch aktive konten?*/
	bool		removeUser(int id){

		cJSON * fileObj = readJsonFile_cJson(USER_FILE);

		if (fileObj != NULL){
			cJSON * arr = cJSON_GetObjectItem(fileObj, "users");

			int size = cJSON_GetArraySize(arr);

			for (int x = 0; x < size; x++){
				cJSON * item = cJSON_GetArrayItem(arr, x);

				if (checkItem(item, id)){
					cJSON_DeleteItemFromArray(arr, x);
					cJSON* saveObj = cJSON_CreateObject();
					cJSON_AddItemToObject(saveObj, "users", arr);

					if (writeJsonFile(USER_FILE, saveObj)){
						return true;
					}
					else{
						return false;
					}
				}
			}
		}
		return false; // wenn file null dann false weil nicht removable
	}
		
	/* True wenn User vorhanden */
	bool		userExist(int id){
		cJSON * fileObj = readJsonFile_cJson(USER_FILE);

		if (fileObj != NULL){
			cJSON * arr = cJSON_GetObjectItem(fileObj, "users");
			int size = cJSON_GetArraySize(arr);

			for (int x = 0; x < size; x++){
				cJSON * item = cJSON_GetArrayItem(arr, x);
				if (checkItem(item, id)){
					return true;
				}
			}
		}
		return false;
	}


	/*  ---------------  */
	/*       KONTO       */
	/*  ---------------  */


	/* Sparkonto einlesen */
	SPARKONTO*	readKonto(int ktnr){
		cJSON * fileObj = readJsonFile_cJson(KONTO_FILE);

		if (fileObj == NULL){
			createKontoFile();
		}else{
			cJSON * arr = cJSON_GetObjectItem(fileObj, "konten");
			int size = cJSON_GetArraySize(arr);

			for (int x = 0; x < size; x++){
				cJSON * item = cJSON_GetArrayItem(arr, x);

				if (checkKtItem(item, ktnr)){
					return cJSONToSparkonto(item);
				}
			}
			cout << "konto nicht gefunden" << endl;
		}
		return NULL; // wenn file leer dann kann er nichts lesen -> somit NULL
	}

	/* Sparkonto eintragen*/
	bool		writeKonto(SPARKONTO* kt){

		if (kontoExist(kt->getKontonummer())){
			cJSON * fileObj = readJsonFile_cJson(KONTO_FILE);

			if (fileObj != NULL){
				cJSON * arr = cJSON_GetObjectItem(fileObj, "konten");
				int size = cJSON_GetArraySize(arr);

				for (int x = 0; x < size; x++){
					cJSON * item = cJSON_GetArrayItem(arr, x);
					if (checkKtItem(item, kt->getKontonummer())){
						cJSON_ReplaceItemInArray(arr, x, kontoTocJSON(kt));
						cJSON* saveObj = cJSON_CreateObject();
						cJSON_AddItemToObject(saveObj, "konten", arr);

						if (writeJsonFile(KONTO_FILE, saveObj)){
							return true;
						}
						else{
							return false;
						}
					}
				}
			}
		}
		else{
			cout << "konto existiert nicht" << endl; //@@ schreiben in log files!!
		}
		return false; // wenn file = NULL dann kann er nichts schreiben somit false
	}
	
	/* Sparkonto hinzufügen wenn noch nicht vorhanden*/
	bool		addKonto(SPARKONTO* kt){
		if (!kontoExist(kt->getKontonummer())){
			cJSON * fileObj = readJsonFile_cJson(KONTO_FILE);

			if (fileObj == NULL){
				createKontoFile();
				fileObj = readJsonFile_cJson(KONTO_FILE);
			}

			if (fileObj != NULL){
				cJSON * arr = cJSON_GetObjectItem(fileObj, "konten");
				int size = cJSON_GetArraySize(arr);

				cJSON_AddItemToArray(arr, kontoTocJSON(kt));
				cJSON* saveObj = cJSON_CreateObject();
				cJSON_AddItemToObject(saveObj, "konten", arr);

				printObject(saveObj);
				if (writeJsonFile(KONTO_FILE, saveObj)){
					return true;
				}
				else{
					return false;
				}
			}
		}
		return false;
	}

	/* Sparkonto mit kontonr löschen*/
	bool		removeKonto(int ktnr){
		cJSON * fileObj = readJsonFile_cJson(KONTO_FILE);

		if (fileObj != NULL){
			cJSON * arr = cJSON_GetObjectItem(fileObj, "konten");

			int size = cJSON_GetArraySize(arr);

			for (int x = 0; x < size; x++){
				cJSON * item = cJSON_GetArrayItem(arr, x);

				if (checkKtItem(item, ktnr)){
					cJSON_DeleteItemFromArray(arr, x);
					cJSON* saveObj = cJSON_CreateObject();
					cJSON_AddItemToObject(saveObj, "konten", arr);

					if (writeJsonFile(KONTO_FILE, saveObj)){
						return true;
					}
					else{
						return false;
					}
				}
			}
		}
		return false;
	}

	/* True wenn konto vorhanden */
	bool		kontoExist(int ktnr){
		cJSON * fileObj = readJsonFile_cJson(KONTO_FILE);

		if (fileObj != NULL){
			cJSON * arr = cJSON_GetObjectItem(fileObj, "konten");
			int size = cJSON_GetArraySize(arr);

			for (int x = 0; x < size; x++){
				cJSON * item = cJSON_GetArrayItem(arr, x);
				if (checkKtItem(item, ktnr)){
					return true;
				}
			}
		}
		return false;
	}

int main(){

	CUSTOMER* newcu = new CUSTOMER();

	newcu->setID(15);
	newcu->setAdresse("Moosallee 15");
	newcu->setGeburtsdatum("11.10.1991");
	newcu->setNachname("Wieser");
	newcu->setTelefon("06644586980");
	newcu->setVorname("Martin");
	newcu->setWohnort("Radstadt");

	addUser(newcu);

	SPARKONTO* newsk = new SPARKONTO();
	newsk->generateKtnnr();
	newsk->setKontostand(500);
	newsk->setVerfüger(newcu);
	addKonto(newsk);

	//printObject(kontoTocJSON(readKonto(465564654)));	// ausgabe des kontos
	//printObject(customerTocJSON(readUser(readKonto(465564654)->getVerfüger().getID()))); // ausgabe des zum konto gehörigen verfügers
	readUser(15);
	SPARKONTO* tmp = readKonto(465564654);
	CUSTOMER* cu = NULL;
	if (tmp != NULL){
		 cu = readUser(tmp->getVerfüger().getID()); // user holen
	}
	if (cu != NULL){
		cu->setWohnort("Altenmarkt"); // user bearbeiten
		writeUser(cu); // user speichern

		if (!addUser(cu)){ // bereits vergebene id hinzufügen probieren
			cout << "USER GIBT ES SCHON" << endl;
		}
	}


	SPARKONTO* invalidAccount = new SPARKONTO(); // neues konto anlegen und mit writekonto hinzufügen probieren

	invalidAccount->setKontonummer(9999999);
	invalidAccount->setKontostand(99999999);
	invalidAccount->setVerfüger(cu);
	writeKonto(invalidAccount); // soll nicht gehen. nur mit ADD . es können nur bestehende accounts überschrieben werden

	SPARKONTO* sk = readKonto(465564654); // konto holen
	if (sk != NULL){
		sk->setKontostand(sk->getKontostand() - 100.0); // konto bearbeiten
		writeKonto(sk); // konto speichern
	}




	if (kontoExist(465564654)){ // gibt es konto mit der kontonr?
		cout << "Konto gefunden." << endl;
	}
	else{ 
		cout << "Konto nicht gefunden." << endl;
	}

	if (userExist(27)){ // gibt es user mit der id?
		cout << "User gefunden." << endl;
	}
	else{
		cout << "User nicht gefunden." << endl;
	}

	system("pause");

	return 0;
}