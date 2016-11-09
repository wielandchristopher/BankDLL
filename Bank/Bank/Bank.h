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

	BANK_API int getBIC();

	BANK_API CUSTOMER* NeuerKunde(char* _Vorname, char* _Nachname, char* _Geburtsdatum, char* _adresse, char* _Wohnort, char* _Telefon);
	BANK_API void Kundenvornamen�nderung(CUSTOMER *Kunde, char* Vorname);
	BANK_API void Kundennachnamen�nderung(CUSTOMER *Kunde, char* _Nachname);
	BANK_API void Kundenadress�nderung(CUSTOMER *Kunde, char* _Adresse);
	BANK_API void Kundenwohnorts�nderung(CUSTOMER *Kunde, char* _Wohnort);
	BANK_API void Kundentelefon�nderung(CUSTOMER *Kunde, char* _Telefon);
	BANK_API void Kundendatenabfrage(CUSTOMER * Kunde);
	BANK_API void Kundeentfernen(CUSTOMER* Kunde);
	
	BANK_API SPARKONTO* NeuesSparkonto(CUSTOMER* Kunde);
	BANK_API KREDITKONTO* NeuesKreditkonto(CUSTOMER* Kunde);
	BANK_API int removeKreditKontoverf�ger(int userid, KREDITKONTO* kk);
	BANK_API int removeSparKontoverf�ger(int userid, SPARKONTO* kk);
	BANK_API void Sparkontoentfernen(SPARKONTO* Konto);
	BANK_API void Kreditkontoentfernen(KREDITKONTO* Konto);
	BANK_API void doEinzahlen(KREDITKONTO* zielkonto, char* verwendungszweck, double betrag);
	BANK_API void doSparen(SPARKONTO* zielkonto, char* verwendungszweck, double betrag);
	BANK_API void doAbheben(KREDITKONTO* zielkonto, double betrag);
	BANK_API UEBERWEISUNG* NeueUeberweisung(KREDITKONTO* quellkonto, KREDITKONTO* zielkonto, double betrag, char* verwendungszweck);
	BANK_API void doUmrechnung(WAEHRUNGSMODUL* waehrungsmmodul, char* waehrung);
	BANK_API void doKursverwaltung(WAEHRUNGSMODUL* waehrungsmodul);
	BANK_API WAEHRUNGSMODUL* NeuesWaehrungsmodul(KREDITKONTO* konto);
	BANK_API int addSparKontoverf�ger(SPARKONTO* sk, CUSTOMER* cust);
	BANK_API int addKreditKontoverf�ger(KREDITKONTO* kk, CUSTOMER* cust);
	
	BANK_API int searchUser(char* vorname, char* nachname, char* geb);
	BANK_API SPARKONTO* readSparKonto(long ktnr);
	BANK_API KREDITKONTO* readKreditKonto(long ktnr);
	BANK_API CUSTOMER* readUser(int id);

	BANK_API long getKreditKontonummer(KREDITKONTO* konto);
	BANK_API long getSparKontonummer(SPARKONTO* konto);
	BANK_API long getKontonummer(CUSTOMER* kunde, int whichKonto);
	BANK_API int getAccountType(long kontonummer);
	BANK_API double getSparkontostand(SPARKONTO* konto);
	BANK_API int getSparkontoverf�ger(SPARKONTO* konto, int whichcust);
	BANK_API double getKreditkontostand(KREDITKONTO* konto);
	BANK_API int getKreditkontoverf�ger(KREDITKONTO* konto, int whichcust);
	BANK_API int deleteKreditkontoVerf�ger(KREDITKONTO* kk, CUSTOMER* cust);
	BANK_API int deleteSparkontoVerf�ger(SPARKONTO* sk, CUSTOMER* cust);
	BANK_API void doSparbuchabheben(SPARKONTO* zielkonto, double betrag);
	BANK_API double waehrungsumrechnung(int _currency, double _value);

#ifdef __cplusplus
}
#endif

#endif /* BANK__H_ */