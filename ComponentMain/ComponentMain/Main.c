#include "Bank.h"
#include <stdlib.h>
#include <stdio.h>

int main(){

	CUSTOMER* hias = readUser(7);
	SPARKONTO* sparmeister = readSparKonto(10000009);

	doSparen(sparmeister, "Sparen", 100);
	//Laut Debugger ist das "wiederhergeholte Konto" NULL  == BLÖD
	Sparkontoentfernen(sparmeister, hias);
}