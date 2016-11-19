#include "Bank.h"
#include <stdlib.h>
#include <stdio.h>







int main(){

	CUSTOMER* customer = NeuerKunde("b", "b", "a", "a", "a", "a");
	CUSTOMER* customer2 = NeuerKunde("b", "c", "a", "a", "a", "a");
	CUSTOMER* customer3 = NeuerKunde("b", "d", "a", "a", "a", "a");

	// siehe in kontonrvergabe -> FAIL 
	////SPARKONTO* sk3 = NeuesSparkonto(customer3);	
	KREDITKONTO* kk1 = NeuesKreditkonto(customer3);
	KREDITKONTO* kk2 = NeuesKreditkonto(customer3);
	KREDITKONTO* kk3 = NeuesKreditkonto(customer3);
	KREDITKONTO* kk4 = NeuesKreditkonto(customer3);
	SparkontoVerfügerHinzufügen(kk3, customer);
	KreditkontoVerfügerHinzufügen(NeuesKreditkonto(customer), customer);
	SPARKONTO* sk2 = NeuesSparkonto(customer);
	KreditkontoVerfügerLoeschen(kk1, customer3);
	SPARKONTO* sk = NeuesSparkonto(customer2);

	printf(getUserKonten(getUserId(customer3)));

	


	system("pause");

}