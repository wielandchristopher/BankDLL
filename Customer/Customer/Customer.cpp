// Customer.cpp : Defines the exported functions for the DLL application.
// Compile by using: cl /EHsc /DCUSTOMER_EXPORTS /LD Customer.cpp

#include "stdafx.h"
#include <stdio.h>
#include "Customer.h"
#include <iostream>

using namespace std;

//Diese Funktion ist f�r die interne Programmierung repr�sentant
int addieren() {

	int a = 3;
	int b = 3;
	cout << "Hallo, Du!\n" << endl;

	return a + b;

}

//Diese Testfunktion wird an die Main.c �bergeben
void print()
{
	int f = addieren();

	printf("Gib mir die Zahl von addieren: %d", f);
}
