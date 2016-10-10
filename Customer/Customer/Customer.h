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
	
	CUSTOMER_API CUSTOMER* NeuerKunde();
	CUSTOMER_API CUSTOMER* Kundendaten�nderung(CUSTOMER *Kunde);
	CUSTOMER_API void Kundeentfernen(CUSTOMER* Kunde);
	CUSTOMER_API SPARKONTO* NeuesSparkonto(CUSTOMER* Kunde, int verf�geranzahl);
	CUSTOMER_API KREDITKONTO* NeuesKreditkonto(CUSTOMER* Kunde, int verf�geranzahl);
	CUSTOMER_API void Sparkontoentfernen(SPARKONTO* Konto);
	CUSTOMER_API void Kreditkontoentfernen(KREDITKONTO* Konto);

#ifdef __cplusplus
}
#endif