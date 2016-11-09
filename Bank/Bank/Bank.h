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

	BANK_API int getBIC();

	BANK_API CUSTOMER* NeuerKunde(char* _Vorname, char* _Nachname, char* _Geburtsdatum, char* _adresse, char* _Wohnort, char* _Telefon);
	BANK_API void Kundenvornamenänderung(CUSTOMER *Kunde, char* Vorname);
	BANK_API void Kundennachnamenänderung(CUSTOMER *Kunde, char* _Nachname);
	BANK_API void Kundenadressänderung(CUSTOMER *Kunde, char* _Adresse);
	BANK_API void Kundenwohnortsänderung(CUSTOMER *Kunde, char* _Wohnort);
	BANK_API void Kundentelefonänderung(CUSTOMER *Kunde, char* _Telefon);
	BANK_API void Kundendatenabfrage(CUSTOMER * Kunde);
	BANK_API void Kundeentfernen(CUSTOMER* Kunde);
	
	BANK_API SPARKONTO* NeuesSparkonto(CUSTOMER* Kunde);
	BANK_API KREDITKONTO* NeuesKreditkonto(CUSTOMER* Kunde);
	BANK_API int removeKreditKontoverfüger(int userid, KREDITKONTO* kk);
	BANK_API int removeSparKontoverfüger(int userid, SPARKONTO* kk);
	BANK_API void Sparkontoentfernen(SPARKONTO* Konto);
	BANK_API void Kreditkontoentfernen(KREDITKONTO* Konto);
	BANK_API void doEinzahlen(KREDITKONTO* zielkonto, char* verwendungszweck, double betrag);
	BANK_API void doSparen(SPARKONTO* zielkonto, char* verwendungszweck, double betrag);
	BANK_API void doAbheben(KREDITKONTO* zielkonto, double betrag);
	BANK_API UEBERWEISUNG* NeueUeberweisung(KREDITKONTO* quellkonto, KREDITKONTO* zielkonto, double betrag, char* verwendungszweck);
	BANK_API void doUmrechnung(WAEHRUNGSMODUL* waehrungsmmodul, char* waehrung);
	BANK_API void doKursverwaltung(WAEHRUNGSMODUL* waehrungsmodul);
	BANK_API WAEHRUNGSMODUL* NeuesWaehrungsmodul(KREDITKONTO* konto);
	BANK_API int addSparKontoverfüger(SPARKONTO* sk, CUSTOMER* cust);
	BANK_API int addKreditKontoverfüger(KREDITKONTO* kk, CUSTOMER* cust);
	
	BANK_API int searchUser(char* vorname, char* nachname, char* geb);
	BANK_API SPARKONTO* readSparKonto(long ktnr);
	BANK_API KREDITKONTO* readKreditKonto(long ktnr);
	BANK_API CUSTOMER* readUser(int id);

	BANK_API long getKreditKontonummer(KREDITKONTO* konto);
	BANK_API long getSparKontonummer(SPARKONTO* konto);
	BANK_API long getKontonummer(CUSTOMER* kunde, int whichKonto);
	BANK_API int getAccountType(long kontonummer);
	BANK_API double getSparkontostand(SPARKONTO* konto);
	BANK_API int getSparkontoverfüger(SPARKONTO* konto, int whichcust);
	BANK_API double getKreditkontostand(KREDITKONTO* konto);
	BANK_API int getKreditkontoverfüger(KREDITKONTO* konto, int whichcust);
	BANK_API int deleteKreditkontoVerfüger(KREDITKONTO* kk, CUSTOMER* cust);
	BANK_API int deleteSparkontoVerfüger(SPARKONTO* sk, CUSTOMER* cust);
	BANK_API void doSparbuchabheben(SPARKONTO* zielkonto, double betrag);
	BANK_API double waehrungsumrechnung(int _currency, double _value);

#ifdef __cplusplus
}
#endif

#endif /* BANK__H_ */