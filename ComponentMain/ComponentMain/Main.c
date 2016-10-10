#include "Customer.h"

int main(){

	//Führt die Funktion aus der Customer.dll aus 
	CUSTOMER* Kunde;
	SparKonto* Sparen;
	KreditKonto* Giro;
	
	Kunde = NeuerKunde();
	Sparen = NeuesSparkonto(Kunde,1);
	Giro = NeuesKreditkonto(Kunde,1);
	Sparkontoentfernen(Sparen);
	Kreditkontoentfernen(Giro);
	Kundeentfernen(Kunde);

	//Führt die Funktionen der anderen .dll aus
}