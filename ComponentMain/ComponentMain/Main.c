#include "Customer.h"
#include <stdlib.h>

int main(){

	//F�hrt die Funktion aus der Customer.dll aus 
	CUSTOMER* Kunde = NULL;
	SPARKONTO* Sparen;
	KREDITKONTO* Giro;
	
	Kunde = NeuerKunde("Vorname", "Nachname", "Geburtsdatum", "Adresse test", "Postleitzahl", "Wohnort", "Telefonnummer");

	//F�hrt die Funktionen der anderen .dll aus
}