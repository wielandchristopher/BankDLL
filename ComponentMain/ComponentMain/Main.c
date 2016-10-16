#include "Bank.h"
#include <stdlib.h>
#include <stdio.h>

int main(){

	SPARKONTO* spare = NULL;
	KREDITKONTO* giro = NULL;

	CUSTOMER* Sepp = NeuerKunde("Vorname", "Hias", "11.10.2016", "Musterstraﬂe 10", "5020 Salzburg", "06601234567");
	spare = NeuesSparkonto(Sepp);

	doEinzahlen(spare, "erste Einzahlung aufs Konto", 1000);
	doAbheben(spare, 200);

}