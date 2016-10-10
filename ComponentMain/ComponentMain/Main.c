#include "Customer.h"
#include <stdlib.h>

int main(){

	//Führt die Funktion aus der Customer.dll aus 
	CUSTOMER* Spezi = NULL;
	CUSTOMER* Mallory = NULL;
	SPARKONTO* Sparen;
	KREDITKONTO* Giro;
	
	Spezi = NeuerKunde("Vorname", "Nachname", "11.03.1993", "Adresse test", "Postleitzahl", "Wohnort", "Telefonnummer");
	Kundenvornamenänderung(Spezi, "Christopher");
	Kundennachnamenänderung(Mallory, "Wieland");
	Kundenadressänderung(Spezi, "Irma-von-Troll Straße 26");
	Kundenplzänderung(Mallory, "5020");
	Kundenwohnortsänderung(Spezi, "Salzburg");
	Kundentelefonänderung(Mallory, "+436606954909");
	Giro = NeuesKreditkonto(Spezi,1);
	Sparen = NeuesSparkonto(Spezi,1);
	//BAD
	Kundeentfernen(Giro);

	Kreditkontoentfernen(Giro);
	Sparkontoentfernen(Sparen);

	//Führt die Funktionen der anderen .dll aus
}