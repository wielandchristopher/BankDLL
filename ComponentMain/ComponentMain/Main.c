#include "Customer.h"

int main(){

	//F�hrt die Funktion aus der Customer.dll aus 
	CUSTOMER* Kunde;
	SparKonto* Sparen;
	KreditKonto* Giro;
	
	Kunde = NeuerKunde();
	Kundendaten�nderung(Kunde);
	Sparen = NeuesSparkonto(Kunde);
	Giro = NeuesKreditkonto(Kunde);
	Sparkontoentfernen(Sparen);
	Kreditkontoentfernen(Giro);
	Kundeentfernen(Kunde);

	//F�hrt die Funktionen der anderen .dll aus
}