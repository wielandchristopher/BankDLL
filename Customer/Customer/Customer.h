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
	typedef struct SparKonto SparKonto;
	typedef struct KreditKonto KreditKonto;
	
	CUSTOMER_API CUSTOMER* NeuerKunde();
	CUSTOMER_API CUSTOMER* Kundendatenänderung(CUSTOMER *Kunde);
	CUSTOMER_API void Kundeentfernen(CUSTOMER* Kunde);
	CUSTOMER_API SparKonto* NeuesSparkonto(CUSTOMER* Kunde);
	CUSTOMER_API KreditKonto* NeuesKreditkonto(CUSTOMER* Kunde);
	CUSTOMER_API SparKonto* Sparkontoverwaltung(SparKonto* Konto);
	CUSTOMER_API KreditKonto* Kreditkontoverwaltung(KreditKonto* Konto);
	CUSTOMER_API void Sparkontoentfernen(SparKonto* Konto);
	CUSTOMER_API void Kreditkontoentfernen(KreditKonto* Konto);

#ifdef __cplusplus
}
#endif