#include "Customer.h"
#include <stdlib.h>

int main(){

	//Führt die Funktion aus der Customer.dll aus 
	CUSTOMER* Kunde = NULL;
	SPARKONTO* Sparen;
	KREDITKONTO* Giro;
	
	Kunde = NeuerKunde("Vorname", "Nachname", "Geburtsdatum", "Adresse test", "Postleitzahl", "Wohnort", "Telefonnummer");

	//Führt die Funktionen der anderen .dll aus
}