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
	addSparKontoverfüger(sk, hias1);
	addSparKontoverfüger(sk, hias2);
	addSparKontoverfüger(sk, hias3);
	addSparKontoverfüger(sk, hias4);

	system("pause");

}