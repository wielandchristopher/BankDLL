#include "Bank.h"
#include <stdlib.h>
#include <stdio.h>

int main(){

	SPARKONTO* spare = NULL;
	KREDITKONTO* giro = NULL;
	KREDITKONTO* giro2 = NULL;
	UEBERWEISUNG* erstueberweisung = NULL;
	WAEHRUNGSMODUL* modul = NULL;

	CUSTOMER* Sepp = NeuerKunde("Vorname", "Hias", "11.10.2016", "Musterstraße 10", "5020 Salzburg", "06601234567");
	spare = NeuesSparkonto(Sepp);
	giro2 = NeuesKreditkonto(Sepp);

	CUSTOMER* Karl = NeuerKunde("Karl", "Lama", "11.10.1994", "Musterstraße 12", "5020 Salzburg", "06601234477");
	giro = NeuesKreditkonto(Karl);

	doEinzahlen(spare, "erste Einzahlung aufs Konto", 1000);
	doAbheben(spare, 200);

	erstueberweisung = NeueUeberweisung(giro, spare, 500, "Testbetragüberweisung");

	// Waehrungsmodul test
	modul = NeuesWaehrungsmodul(giro);
	doUmrechnung(modul, "USD");
	doKursverwaltung(modul);
}