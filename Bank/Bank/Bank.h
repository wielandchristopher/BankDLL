#ifndef BANK__H_
#define BANK__H_

//Zum definieren, welche FUnktion exportiert wird
#ifdef BANK_EXPORTS
#define BANK_API   __declspec( dllexport ) 
#else
#define BANK_API __declspec(dllimport) 
#endif

//Hier wird die Sprache angegeben, welche in C konvertiert werden muss
#ifdef __cplusplus
extern "C" {
#endif

	//Hier werden alle Funktionsdefinitionen reingeschrieben, 
	//welche �ber die Schnittstelle �bertragen werden sollen.
	typedef struct CUSTOMER CUSTOMER;
	typedef struct SPARKONTO SPARKONTO;
	typedef struct KREDITKONTO KREDITKONTO;
	typedef struct KONTOAUSZUG KONTOAUSZUG;
	typedef struct UEBERWEISUNG UEBERWEISUNG;
	typedef struct WAEHRUNGSMODUL WAEHRUNGSMODUL;

	BANK_API int getBIC();	//gibt BIC der Bank zur�ck

	/*   CUSTOMER   */
	BANK_API CUSTOMER* NeuerKunde(char* _Vorname,							
		char* _Nachname, char* _Geburtsdatum, 
		char* _adresse, char* _Wohnort, char* _Telefon);					// Neuen Kunden Anlegen
	BANK_API void Kundenvornamen�nderung(CUSTOMER *Kunde, char* Vorname);	// Customer�nderung
	BANK_API void Kundennachnamen�nderung(CUSTOMER *Kunde, char* _Nachname);// Customer�nderung
	BANK_API void Kundenadress�nderung(CUSTOMER *Kunde, char* _Adresse);	// Customer�nderung
	BANK_API void Kundenwohnorts�nderung(CUSTOMER *Kunde, char* _Wohnort);	// Customer�nderung
	BANK_API void Kundentelefon�nderung(CUSTOMER *Kunde, char* _Telefon);   // Customer�nderung
	BANK_API void Kundendatenabfrage(CUSTOMER * Kunde);						// -> Logging output			
	BANK_API void Kundeentfernen(CUSTOMER* Kunde);							// Entfernt den Kunden

	BANK_API int searchUser(char* vorname, char* nachname, char* geb);		// r�ckgabe userid
	BANK_API CUSTOMER* readUser(int id);									// r�ckgabe des users mit der id
	BANK_API int UserKontoExists(int userid, char* ktnr);					// gibt es ein userkonto?
	BANK_API int rmvKontofromUser(int userid, char* ktnr);					// l�scht einen kontoeintrag von einem user
	BANK_API int addKontotoUser(int userid, char* ktnr);					// f�gt einen kontoeintrag einem user hinzu
	BANK_API char* getUserKonten(int id);									// gibt ein JSON Array Zur�ck f�r kontozugriff
	BANK_API int getUserId(CUSTOMER* cust);									// gibt die userid zur�ck -> �bergabe von Customer Struktur
	
	/*   SPARKONTO   */
	BANK_API SPARKONTO* NeuesSparkonto(CUSTOMER* Kunde);					// Neues Sparkonto anlegen
	BANK_API SPARKONTO* readSparKonto(char* ktnr);							// Lesen und R�ckgabe der Sparkontostruktur
	BANK_API void Sparkontoentfernen(SPARKONTO* Konto);						// Entfernen des Sparkontoeintrages
	BANK_API double getSparkontostand(SPARKONTO* konto);					// Sparkontostand holen
	BANK_API char* getSparKontonummer(SPARKONTO* konto);					// Sparkontonummer holen
	BANK_API int addSparkontoVerf�ger(int userid, char* ktnr);				// Sparkontoverf�ger Hinzuf�gen zum Sparkonto
	BANK_API int skverf�gerExists(char* ktnr, int userid);					// Ist die CustomerID in diesem Konto vermerkt? 
	BANK_API int removeSparKontoVerf�ger(int userid, char* ktnr);			// L�scht einen Verf�gereintrag vom Sparkonto
	BANK_API void doSparbuchabheben(SPARKONTO* zielkonto, double betrag);	// Einen Betrag vom Sparbuch abheben
	BANK_API void SparkontoVerf�gerHinzuf�gen								// overloaded - Sparkontoverf�ger Hinzuf�gen zum Sparkonto
		(SPARKONTO* Konto, CUSTOMER* cust);
	BANK_API void SparkontoVerf�gerLoeschen									
		(SPARKONTO* Konto, CUSTOMER* cust);									// overloaded - L�scht einen Verf�gereintrag vom Sparkonto
	BANK_API void doSparen(SPARKONTO* zielkonto,							
		char* verwendungszweck, double betrag);								// Zahlt einen Betrag ein -> spart

	/*   KREDITKONTO   */
	BANK_API KREDITKONTO* NeuesKreditkonto(CUSTOMER* Kunde);				// Neues Kreditkonto anlegen
	BANK_API KREDITKONTO* readKreditKonto(char* ktnr);						// Lesen und R�ckgabe der Kreditkontostruktur
	BANK_API void doAbheben(KREDITKONTO* zielkonto, double betrag);			// einen Betrag vom Kreditkonto abheben
	BANK_API void Kreditkontoentfernen(KREDITKONTO* Konto);					// Ein Kreditkontoeintrag Entfernen
	BANK_API void doEinzahlen(KREDITKONTO* zielkonto,
		char* verwendungszweck, double betrag);								// Zahlt auf das Konto ein
	BANK_API char* getKreditKontonummer(KREDITKONTO* konto);				// holt die Kreditkontonummer
	BANK_API double getKreditkontostand(KREDITKONTO* konto);				// holt den Kreditkontostand
	BANK_API int removeKreditKontoVerf�ger(int userid, char* ktnr);			// entfernt einen Verf�gereintrag von einem Kreditkonto
	BANK_API int addKreditkontoVerf�ger(int userid, char* ktnr);			// f�gt einen Verf�gereintrag zum Kreditkonto hinzu
	BANK_API int kkverf�gerExists(char* ktnr, int userid);					// �berpr�ft ob ein Usereintrag in einem Kreditkonto ist
	BANK_API void KreditkontoVerf�gerLoeschen
		(KREDITKONTO* Konto, CUSTOMER* cust);								// overloaded - L�scht einen Verf�gereintrag vom Kreditkonto
	BANK_API void KreditkontoVerf�gerHinzuf�gen
		(KREDITKONTO* Konto, CUSTOMER* cust);								// overloaded - Sparkontoverf�ger Hinzuf�gen zum Kreditkonto

	/*   �BERWEISUNG   */
	BANK_API UEBERWEISUNG* NeueUeberweisung
		(KREDITKONTO* quellkonto, KREDITKONTO* zielkonto, 
			double betrag, char* verwendungszweck);							// �berweisung von einem zum anderen Konto

	/*   W�HRUNGSMODUL   */
	BANK_API void doUmrechnung
		(WAEHRUNGSMODUL* waehrungsmmodul, char* waehrung);					// Umrechnungen
	BANK_API void doKursverwaltung(WAEHRUNGSMODUL* waehrungsmodul);			// Kurs Verwalten
	BANK_API WAEHRUNGSMODUL* NeuesWaehrungsmodul(KREDITKONTO* konto);		// W�hrungsmodul erstellen
	BANK_API double waehrungsumrechnung(int _currency, double _value);		// Umrechnung der w�hrung 0 = EUR, 1 = USD, 2 = GBG
	
	/* Konten */
	BANK_API int getAccountType(char* kontonummer);							// gibt den Kontotyp zur�ck


#ifdef __cplusplus
}
#endif

#endif /* BANK__H_ */