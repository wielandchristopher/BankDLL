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
	typedef struct KONTOAUSZUG KONTOAUSZUG;
	typedef struct UEBERWEISUNG UEBERWEISUNG;

	KONTOFNK_API void doEinzahlen(KREDITKONTO* zielkonto, char* verwendungszweck, double betrag);
	KONTOFNK_API void doAbheben(KREDITKONTO* zielkonto, char* verwendungszweck, double betrag);
	KONTOFNK_API UEBERWEISUNG* NeueUeberweisung(KREDITKONTO* zielkonto, double betrag, char* verwendungszweck);

#ifndef KONTOFUNKTIONEN_H_
#define KONTOFUNKTIONEN_H_

	class KONTOAUSZUG {
	public:
		KONTOAUSZUG();

	private:

	};
	class UEBERWEISUNG
	{
	public:
		char* UEBERWEISUNG::getempfaengername() {
			return empfaengername;
		}
		void UEBERWEISUNG::setempfaengername(char* empfänger) {
			empfaengername = empfänger;
		}
		char* UEBERWEISUNG::getVerwendungszweck() {
			return verwendungszweck;
		}
		void UEBERWEISUNG::setVerwendungszweck(char* verwendung) {
			verwendungszweck = verwendung;
		}
		double UEBERWEISUNG::getBetrag() {
			return betrag;
		}
		void UEBERWEISUNG::setBetrag(double betrg) {
			betrag = betrg;
		}
		double UEBERWEISUNG::getkontostand() {
			return kontostand;
		}
		void UEBERWEISUNG::setkontostand(double betrg) {
			kontostand = betrg;
		}
		int UEBERWEISUNG::getkontonummer() {
			return kontonummer;
		}
		void UEBERWEISUNG::setkontonummer(int kntnr) {
			kontonummer = kntnr;
		}
	private:
		double betrag;
		double kontostand;
		int kontonummer;
		char* empfaengername;
		char* verwendungszweck;
	};

#endif /* KONTOFUNKTIONEN_H_ */





#ifdef __cplusplus
}
#endif

