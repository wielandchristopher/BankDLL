//Zum definieren, welche FUnktion exportiert wird
#ifdef KONTOFNK_EXPORTS
#define KONTOFNK_API   __declspec( dllexport ) 
#else
#define KONTOFNK_API __declspec(dllimport) 
#endif

//Hier wird die Sprache angegeben, welche in C konvertiert werden muss
#ifdef __cplusplus
extern "C" {
#endif

	typedef struct KONTOBEWEGUNG KONTOBEWEGUNG;
	typedef struct UEBERWEISUNG UEBERWEISUNG;

	KONTOFNK_API void doEinzahlen(KREDITKONTO* zielkonto, char* verwendungszweck, double betrag);
	KONTOFNK_API void doAbheben(KREDITKONTO* zielkonto, char* verwendungszweck, double betrag);
	KONTOFNK_API UEBERWEISUNG* newUeberweisung(KREDITKONTO* zielkonto, double betrag, char* verwendungszweck);

#ifdef __cplusplus
}
#endif

