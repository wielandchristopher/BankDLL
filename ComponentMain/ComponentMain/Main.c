#include "Customer.h"
#include <stdlib.h>
#include <stdio.h>

int main(){

	//Führt die Funktion aus der Customer.dll aus 
	CUSTOMER* Spezi = NULL;
	CUSTOMER* Mallory = NULL;
	SPARKONTO* Sparen;
	KREDITKONTO* Giro = NULL;

	Spezi = NeuerKunde("VORNAME", "Nachname", "11.03.1993", "Adresse test", "Postleitzahl", "Wohnort", "Telefonnummer");
	Giro = NeuesKreditkonto(Spezi);
	Kundenvornamenänderung(Giro, "Test");
	Kundendatenabfrage(Spezi);
	Kundeentfernen(Spezi);

	//Führt die Funktionen der anderen .dll aus
}