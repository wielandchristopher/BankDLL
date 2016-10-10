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
	//welche über die Schnittstelle übertragen werden sollen.
	typedef struct CUSTOMER CUSTOMER;
	typedef struct SPARKONTO SPARKONTO;
	typedef struct KREDITKONTO KREDITKONTO;
	
	CUSTOMER_API CUSTOMER* NeuerKunde(char* _Vorname, char* _Nachname, char* _Geburtsdatum, char* _adresse, char* _Postleitzahl, char* _Wohnort, char* _Telefon);
	CUSTOMER_API CUSTOMER* Kundenvornamenänderung(CUSTOMER *Kunde, char* Vorname);
	CUSTOMER_API CUSTOMER* Kundennachnamenänderung(CUSTOMER *Kunde, char* _Nachname);
	CUSTOMER_API CUSTOMER* Kundenadressänderung(CUSTOMER *Kunde, char* _Adresse);
	CUSTOMER_API CUSTOMER* Kundenplzänderung(CUSTOMER *Kunde, char* _Postleitzahl);
	CUSTOMER_API CUSTOMER* Kundenwohnortsänderung(CUSTOMER *Kunde, char* _Wohnort);
	CUSTOMER_API CUSTOMER* Kundentelefonänderung(CUSTOMER *Kunde, char* _Telefon);
	CUSTOMER_API void Kundeentfernen(CUSTOMER* Kunde);
	CUSTOMER_API SPARKONTO* NeuesSparkonto(CUSTOMER* Kunde);
	CUSTOMER_API SPARKONTO* NeuesSparkonto2(CUSTOMER* Kunde, CUSTOMER* Kunde2);
	CUSTOMER_API SPARKONTO* NeuesSparkonto3(CUSTOMER* Kunde, CUSTOMER* Kunde2, CUSTOMER* Kunde3);
	CUSTOMER_API SPARKONTO* NeuesSparkonto4(CUSTOMER* Kunde, CUSTOMER* Kunde2, CUSTOMER* Kunde3, CUSTOMER* Kunde4);
	CUSTOMER_API KREDITKONTO* NeuesKreditkonto(CUSTOMER* Kunde);
	CUSTOMER_API KREDITKONTO* NeuesKreditkonto2(CUSTOMER* Kunde, CUSTOMER* Kunde2);
	CUSTOMER_API KREDITKONTO* NeuesKreditkonto3(CUSTOMER* Kunde, CUSTOMER* Kunde2, CUSTOMER* Kunde3);
	CUSTOMER_API KREDITKONTO* NeuesKreditkonto4(CUSTOMER* Kunde, CUSTOMER* Kunde2, CUSTOMER* Kunde3, CUSTOMER* Kunde4);
	CUSTOMER_API void Sparkontoentfernen(SPARKONTO* Konto);
	CUSTOMER_API void Kreditkontoentfernen(KREDITKONTO* Konto);

#ifdef __cplusplus
}
#endif