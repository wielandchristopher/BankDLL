#include "Bank.h"
#include <stdlib.h>
#include <stdio.h>



int main(){

	CUSTOMER* hias = NeuerKunde("Stephanie", "test", "10.10.10", "adrr", "wohnort", "telefon");
	CUSTOMER* hias1 = NeuerKunde("Christoper", "test", "10.10.10", "adrr", "wohnort", "telefon");
	CUSTOMER* hias2 = NeuerKunde("Martin", "test", "10.10.10", "adrr", "wohnort", "telefon");
	CUSTOMER* hias3 = NeuerKunde("Thomas", "test", "10.10.10", "adrr", "wohnort", "telefon");
	CUSTOMER* hias4 = NeuerKunde("Hans", "test", "10.10.10", "adrr", "wohnort", "telefon");

	SPARKONTO* sk = NeuesSparkonto(hias);
	addSparKontoverf�ger(sk, hias1);
	addSparKontoverf�ger(sk, hias2);
	addSparKontoverf�ger(sk, hias3);
	addSparKontoverf�ger(sk, hias4);

	system("pause");

}