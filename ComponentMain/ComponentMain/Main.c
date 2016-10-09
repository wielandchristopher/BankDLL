#include "Customer.h"

int main(){

	//Führt die Funktion aus der Customer.dll aus 
	CUSTOMER* Kunde;
	SparKonto* Sparen;
	KreditKonto* Giro;
	
	Kunde = NeuerKunde();
	Kundendatenänderung(Kunde);
	Sparen = NeuesSparkonto(Kunde);
	Giro = NeuesKreditkonto(Kunde);
	Sparkontoverwaltung(Sparen);
	Kreditkontoverwaltung(Giro);
	Sparkontoentfernen(Sparen);
	Kreditkontoentfernen(Giro);
	Kundeentfernen(Kunde);

	//Führt die Funktionen der anderen .dll aus
}