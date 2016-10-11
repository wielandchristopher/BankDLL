#include "stdafx.h"
#include "Customer.h"
#include "Kontofunktionen.h"

#include <string>
#include <iostream>
#include <time.h>
#include <typeinfo>

using namespace std;
FILE* logfile;

string time_to_string() {

	struct tm newtime;
	__time64_t long_time;
	char timebuf[26];
	errno_t err;

	// Get time as 64-bit integer.
	_time64(&long_time);
	err = _localtime64_s(&newtime, &long_time);
	err = asctime_s(timebuf, 26, &newtime);
	strftime(timebuf, sizeof(timebuf), "%d %m %Y %H:%M:%S", &newtime);
	string str(timebuf);
	return str;
}
void LOGGING(char* Errortext, char* LEVEL) {

	char *Errortxt = Errortext;
	string stringtime = time_to_string();
	const char *time = stringtime.c_str();
	char *lvl = LEVEL;

	fopen_s(&logfile, "Customer_log.txt", "a");
	if (logfile == NULL)
	{
		printf("Das Logfile konnte nicht erstellt werden");
	}

	//Hier soll noch die Zeit drinnen stehen 
	fprintf(logfile, time);
	fprintf(logfile, " - ");
	fprintf(logfile, lvl);
	fprintf(logfile, ": ");
	fprintf(logfile, Errortxt);
	fprintf(logfile, "\n");

	fclose(logfile);

}

class KONTOAUSZUG {
public: 
	KONTOAUSZUG();

private:

};
class UEBERWEISUNG
{
public:
	char* getempfaengername() {
		return empfaengername;
	}
	void setempfaengername(char* empfänger) {
		empfaengername = empfänger;
	}	
	char* getVerwendungszweck() {
		return verwendungszweck;
	}
	void setVerwendungszweck(char* verwendung) {
		verwendungszweck = verwendung;
	}
	double getBetrag() {
		return betrag;
	}
	void setBetrag(double betrg) {
		betrag = betrg;
	}
	double getkontostand() {
		return kontostand;
	}
	void setkontostand(double betrg) {
		kontostand = betrg;
	}
	int getkontonummer() {
		return kontonummer;
	}
	void setkontonummer(int kntnr) {
		kontonummer = kntnr;
	}
private:
	double betrag;
	double kontostand;
	int kontonummer;
	char* empfaengername;
	char* verwendungszweck;
};

void doAbheben(KREDITKONTO* zielkonto, char* verwendungszweck, double betrag) {
	
	double newKontostand = zielkonto->getKontostand() - betrag;
	zielkonto->setKontostand(newKontostand);

	char buffer[100];
	LOGGING("Der Betrag wurde erfolgreich abgehoben. Unterhalb die getätigten eingaben:", "OK");
	LOGGING("Momentaner Kontostand:", "OK");
	LOGGING((char*)to_string(zielkonto->getKontostand()).c_str(), "OK");
	LOGGING("Verwendungszweck:", "OK");
	LOGGING(verwendungszweck, "OK");
	LOGGING("Betrag:", "OK");
	LOGGING((char*)to_string(betrag).c_str(), "OK");
}
void doEinzahlen(KREDITKONTO* zielkonto, char* verwendungszweck, double betrag) {


	double newKontostand = zielkonto->getKontostand() + betrag;
	zielkonto->setKontostand(newKontostand);

	char buffer[100];
	LOGGING("Der Betrag wurde erfolgreich eingezahlt. Unterhalb die getätigten eingaben:", "OK");
	LOGGING("Momentaner Kontostand:", "OK");
	LOGGING((char*)to_string(zielkonto->getKontostand()).c_str(), "OK");
	LOGGING("Verwendungszweck:", "OK");
	LOGGING(verwendungszweck, "OK");
	LOGGING("Betrag:", "OK");
	LOGGING((char*)to_string(betrag).c_str(), "OK");
}

UEBERWEISUNG* newUeberweisung(KREDITKONTO* zielkonto, double betrag, char* verwendungszweck) {


	UEBERWEISUNG* ueberweisung = new UEBERWEISUNG();
	ueberweisung->setempfaengername(zielkonto->getVerfüger());
	ueberweisung->setkontonummer(zielkonto->getKontostand());
	ueberweisung->setkontostand(zielkonto->getKontostand());
	ueberweisung->setVerwendungszweck(verwendungszweck);
	ueberweisung->setBetrag(betrag);

	LOGGING("Die Überweisung wurde erfolgreich durchgeführt.", "OK");
	return ueberweisung;
}

KONTOAUSZUG::KONTOAUSZUG()
{

}
