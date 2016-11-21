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
	//welche über die Schnittstelle übertragen werden sollen.
	typedef struct CUSTOMER CUSTOMER;
	typedef struct SPARKONTO SPARKONTO;
	typedef struct KREDITKONTO KREDITKONTO;
	typedef struct KONTOAUSZUG KONTOAUSZUG;
	typedef struct UEBERWEISUNG UEBERWEISUNG;
	typedef struct WAEHRUNGSMODUL WAEHRUNGSMODUL;

	BANK_API int getBIC();	//gibt BIC der Bank zurück

	/*   CUSTOMER   */
	BANK_API CUSTOMER* NeuerKunde(char* _Vorname,							
		char* _Nachname, char* _Geburtsdatum, 
		char* _adresse, char* _Wohnort, char* _Telefon);					// Neuen Kunden Anlegen
	BANK_API void Kundenvornamenänderung(CUSTOMER *Kunde, char* Vorname);	// Customeränderung
	BANK_API void Kundennachnamenänderung(CUSTOMER *Kunde, char* _Nachname);// Customeränderung
	BANK_API void Kundenadressänderung(CUSTOMER *Kunde, char* _Adresse);	// Customeränderung
	BANK_API void Kundenwohnortsänderung(CUSTOMER *Kunde, char* _Wohnort);	// Customeränderung
	BANK_API void Kundentelefonänderung(CUSTOMER *Kunde, char* _Telefon);   // Customeränderung
	BANK_API void Kundendatenabfrage(CUSTOMER * Kunde);						// -> Logging output			
	BANK_API void Kundeentfernen(CUSTOMER* Kunde);							// Entfernt den Kunden

	BANK_API int searchUser(char* vorname, char* nachname, char* geb);		// rückgabe userid
	BANK_API CUSTOMER* readUser(int id);									// rückgabe des users mit der id
	BANK_API int UserKontoExists(int userid, char* ktnr);					// gibt es ein userkonto?
	BANK_API int rmvKontofromUser(int userid, char* ktnr);					// löscht einen kontoeintrag von einem user
	BANK_API int addKontotoUser(int userid, char* ktnr);					// fügt einen kontoeintrag einem user hinzu
	BANK_API char* getUserKonten(int id);									// gibt ein JSON Array Zurück für kontozugriff
	BANK_API int getUserId(CUSTOMER* cust);									// gibt die userid zurück -> übergabe von Customer Struktur
	
	/*   SPARKONTO   */
	BANK_API SPARKONTO* NeuesSparkonto(CUSTOMER* Kunde);					// Neues Sparkonto anlegen
	BANK_API SPARKONTO* readSparKonto(char* ktnr);							// Lesen und Rückgabe der Sparkontostruktur
	BANK_API void Sparkontoentfernen(SPARKONTO* Konto);						// Entfernen des Sparkontoeintrages
	BANK_API double getSparkontostand(SPARKONTO* konto);					// Sparkontostand holen
	BANK_API char* getSparKontonummer(SPARKONTO* konto);					// Sparkontonummer holen
	BANK_API int addSparkontoVerfüger(int userid, char* ktnr);				// Sparkontoverfüger Hinzufügen zum Sparkonto
	BANK_API int skverfügerExists(char* ktnr, int userid);					// Ist die CustomerID in diesem Konto vermerkt? 
	BANK_API int removeSparKontoVerfüger(int userid, char* ktnr);			// Löscht einen Verfügereintrag vom Sparkonto
	BANK_API void doSparbuchabheben(SPARKONTO* zielkonto, double betrag);	// Einen Betrag vom Sparbuch abheben
	BANK_API void SparkontoVerfügerHinzufügen								// overloaded - Sparkontoverfüger Hinzufügen zum Sparkonto
		(SPARKONTO* Konto, CUSTOMER* cust);
	BANK_API void SparkontoVerfügerLoeschen									
		(SPARKONTO* Konto, CUSTOMER* cust);									// overloaded - Löscht einen Verfügereintrag vom Sparkonto
	BANK_API void doSparen(SPARKONTO* zielkonto,							
		char* verwendungszweck, double betrag);								// Zahlt einen Betrag ein -> spart

	/*   KREDITKONTO   */
	BANK_API KREDITKONTO* NeuesKreditkonto(CUSTOMER* Kunde);				// Neues Kreditkonto anlegen
	BANK_API KREDITKONTO* readKreditKonto(char* ktnr);						// Lesen und Rückgabe der Kreditkontostruktur
	BANK_API void doAbheben(KREDITKONTO* zielkonto, double betrag);			// einen Betrag vom Kreditkonto abheben
	BANK_API void Kreditkontoentfernen(KREDITKONTO* Konto);					// Ein Kreditkontoeintrag Entfernen
	BANK_API void doEinzahlen(KREDITKONTO* zielkonto,
		char* verwendungszweck, double betrag);								// Zahlt auf das Konto ein
	BANK_API char* getKreditKontonummer(KREDITKONTO* konto);				// holt die Kreditkontonummer
	BANK_API double getKreditkontostand(KREDITKONTO* konto);				// holt den Kreditkontostand
	BANK_API int removeKreditKontoVerfüger(int userid, char* ktnr);			// entfernt einen Verfügereintrag von einem Kreditkonto
	BANK_API int addKreditkontoVerfüger(int userid, char* ktnr);			// fügt einen Verfügereintrag zum Kreditkonto hinzu
	BANK_API int kkverfügerExists(char* ktnr, int userid);					// überprüft ob ein Usereintrag in einem Kreditkonto ist
	BANK_API void KreditkontoVerfügerLoeschen
		(KREDITKONTO* Konto, CUSTOMER* cust);								// overloaded - Löscht einen Verfügereintrag vom Kreditkonto
	BANK_API void KreditkontoVerfügerHinzufügen
		(KREDITKONTO* Konto, CUSTOMER* cust);								// overloaded - Sparkontoverfüger Hinzufügen zum Kreditkonto

	/*   ÜBERWEISUNG   */
	BANK_API UEBERWEISUNG* NeueUeberweisung
		(KREDITKONTO* quellkonto, KREDITKONTO* zielkonto, 
			double betrag, char* verwendungszweck);							// Überweisung von einem zum anderen Konto

	/*   WÄHRUNGSMODUL   */
	BANK_API void doUmrechnung
		(WAEHRUNGSMODUL* waehrungsmmodul, char* waehrung);					// Umrechnungen
	BANK_API void doKursverwaltung(WAEHRUNGSMODUL* waehrungsmodul);			// Kurs Verwalten
	BANK_API WAEHRUNGSMODUL* NeuesWaehrungsmodul(KREDITKONTO* konto);		// Währungsmodul erstellen
	BANK_API double waehrungsumrechnung(int _currency, double _value);		// Umrechnung der währung 0 = EUR, 1 = USD, 2 = GBG
	
	/* Konten */
	BANK_API int getAccountType(char* kontonummer);							// gibt den Kontotyp zurück


#ifdef __cplusplus
}
#endif

#endif /* BANK__H_ */