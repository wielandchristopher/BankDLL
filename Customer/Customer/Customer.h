//Zum definieren, welche FUnktion exportiert wird
#ifdef CUSTOMER_EXPORTS
#define CUSTOMER_API   __declspec( dllexport ) 
#else
#define CUSTOMER_API __declspec(dllimport) 
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
	
	CUSTOMER_API CUSTOMER* NeuerKunde(char* _Vorname, char* _Nachname, char* _Geburtsdatum, char* _adresse, char* _Postleitzahl, char* _Wohnort, char* _Telefon);
	CUSTOMER_API CUSTOMER* Kundenvornamen�nderung(CUSTOMER *Kunde, char* Vorname);
	CUSTOMER_API CUSTOMER* Kundennachnamen�nderung(CUSTOMER *Kunde, char* _Nachname);
	CUSTOMER_API CUSTOMER* Kundenadress�nderung(CUSTOMER *Kunde, char* _Adresse);
	CUSTOMER_API CUSTOMER* Kundenplz�nderung(CUSTOMER *Kunde, char* _Postleitzahl);
	CUSTOMER_API CUSTOMER* Kundenwohnorts�nderung(CUSTOMER *Kunde, char* _Wohnort);
	CUSTOMER_API CUSTOMER* Kundentelefon�nderung(CUSTOMER *Kunde, char* _Telefon);
	CUSTOMER_API void Kundeentfernen(CUSTOMER* Kunde);
	CUSTOMER_API SPARKONTO* NeuesSparkonto(CUSTOMER* Kunde, int verf�geranzahl);
	CUSTOMER_API KREDITKONTO* NeuesKreditkonto(CUSTOMER* Kunde, int verf�geranzahl);
	CUSTOMER_API void Sparkontoentfernen(SPARKONTO* Konto);
	CUSTOMER_API void Kreditkontoentfernen(KREDITKONTO* Konto);

#ifdef __cplusplus
}
#endif