#include "Customer.h"

int main(){

	//F�hrt die Funktion aus der Customer.dll aus 
	CUSTOMER* Kunde;
	SparKonto* Sparen;
	KreditKonto* Giro;
	
	Kunde = NeuerKunde();
	Sparen = NeuesSparkonto(Kunde,1);
	Giro = NeuesKreditkonto(Kunde,1);
	Sparkontoentfernen(Sparen);
	Kreditkontoentfernen(Giro);
	Kundeentfernen(Kunde);

	//F�hrt die Funktionen der anderen .dll aus
}