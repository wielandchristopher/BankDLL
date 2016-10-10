#include "Customer.h"
#include <stdlib.h>

int main(){

	//Führt die Funktion aus der Customer.dll aus 
	CUSTOMER* Spezi = NULL;
	CUSTOMER* Mallory = NULL;
	SPARKONTO* Sparen;
	KREDITKONTO* Giro;
	char* test = "Test";
	
	Spezi = NeuerKunde("Vorname", "Nachname", "11.03.1993", "Adresse test", "Postleitzahl", "Wohnort", "Telefonnummer");
	//BAD
	Sparen = NeuesSparkonto(test);

	Kundeentfernen(Spezi);

	//Führt die Funktionen der anderen .dll aus
}