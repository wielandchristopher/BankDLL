#include "Customer.h"
#include "Kontofunktionen.h"
#include <stdlib.h>
#include <stdio.h>

int main(){
	//Customer.dll
	CUSTOMER* Karl = NeuerKunde("Vorname", "NAchname", "11.10.2016", "Musterstraße 10", "5020 Salzburg", "06601234567");
	KREDITKONTO* Giro = NeuesKreditkonto(Karl);

	//Kontofunktionen.dll
	UEBERWEISUNG* erstueberweisung = newUeberweisung(Giro, 500, "Testbetragüberweisung");

}