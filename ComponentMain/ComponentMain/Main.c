#include "Customer.h"
#include <stdlib.h>

int main(){

	//F�hrt die Funktion aus der Customer.dll aus 
	CUSTOMER* Spezi = NULL;
	CUSTOMER* Mallory = NULL;
	SPARKONTO* Sparen;
	KREDITKONTO* Giro;
	
	Spezi = NeuerKunde("Vorname", "Nachname", "11.03.1993", "Adresse test", "Postleitzahl", "Wohnort", "Telefonnummer");
	Kundenvornamen�nderung(Spezi, "Christopher");
	Kundennachnamen�nderung(Mallory, "Wieland");
	Kundenadress�nderung(Spezi, "Irma-von-Troll Stra�e 26");
	Kundenplz�nderung(Mallory, "5020");
	Kundenwohnorts�nderung(Spezi, "Salzburg");
	Kundentelefon�nderung(Mallory, "+436606954909");
	Giro = NeuesKreditkonto(Spezi,1);
	Sparen = NeuesSparkonto(Spezi,1);
	//BAD
	Kundeentfernen(Giro);

	Kreditkontoentfernen(Giro);
	Sparkontoentfernen(Sparen);

	//F�hrt die Funktionen der anderen .dll aus
}