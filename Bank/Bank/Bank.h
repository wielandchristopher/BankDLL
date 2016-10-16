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

	BANK_API CUSTOMER* NeuerKunde(char* _Vorname, char* _Nachname, char* _Geburtsdatum, char* _adresse, char* _Wohnort, char* _Telefon);
	BANK_API void Kundenvornamen�nderung(CUSTOMER *Kunde, char* Vorname);
	BANK_API void Kundennachnamen�nderung(CUSTOMER *Kunde, char* _Nachname);
	BANK_API void Kundenadress�nderung(CUSTOMER *Kunde, char* _Adresse);
	BANK_API void Kundenwohnorts�nderung(CUSTOMER *Kunde, char* _Wohnort);
	BANK_API void Kundentelefon�nderung(CUSTOMER *Kunde, char* _Telefon);
	BANK_API void Kundendatenabfrage(CUSTOMER * Kunde);
	BANK_API void Kundeentfernen(CUSTOMER* Kunde);
	BANK_API SPARKONTO* NeuesSparkonto(CUSTOMER* Kunde);
	BANK_API SPARKONTO* NeuesSparkonto2(CUSTOMER* Kunde, CUSTOMER* Kunde2);
	BANK_API SPARKONTO* NeuesSparkonto3(CUSTOMER* Kunde, CUSTOMER* Kunde2, CUSTOMER* Kunde3);
	BANK_API SPARKONTO* NeuesSparkonto4(CUSTOMER* Kunde, CUSTOMER* Kunde2, CUSTOMER* Kunde3, CUSTOMER* Kunde4);
	BANK_API KREDITKONTO* NeuesKreditkonto(CUSTOMER* Kunde);
	BANK_API KREDITKONTO* NeuesKreditkonto2(CUSTOMER* Kunde, CUSTOMER* Kunde2);
	BANK_API KREDITKONTO* NeuesKreditkonto3(CUSTOMER* Kunde, CUSTOMER* Kunde2, CUSTOMER* Kunde3);
	BANK_API KREDITKONTO* NeuesKreditkonto4(CUSTOMER* Kunde, CUSTOMER* Kunde2, CUSTOMER* Kunde3, CUSTOMER* Kunde4);
	BANK_API void Sparkontoentfernen(SPARKONTO* Konto);
	BANK_API void Kreditkontoentfernen(KREDITKONTO* Konto);
	BANK_API void doEinzahlen(KREDITKONTO* zielkonto, char* verwendungszweck, double betrag);
	BANK_API void doAbheben(KREDITKONTO* zielkonto, double betrag);
	BANK_API UEBERWEISUNG* NeueUeberweisung(KREDITKONTO* quellkonto, KREDITKONTO* zielkonto, double betrag, char* verwendungszweck);
	BANK_API void doUmrechnung(WAEHRUNGSMODUL* waehrungsmmodul, char* waehrung);
	BANK_API void doKursverwaltung(WAEHRUNGSMODUL* waehrungsmodul);
	BANK_API WAEHRUNGSMODUL* NeuesWaehrungsmodul(KREDITKONTO* konto);

#ifdef __cplusplus
}
#endif

#endif /* BANK__H_ */