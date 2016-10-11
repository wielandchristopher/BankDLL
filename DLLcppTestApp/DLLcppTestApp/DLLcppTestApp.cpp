// DLLcppTestApp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Kontoverwaltung.h"

using namespace std;

int main()
{
	double _kontonummer = 123456;
	int _kontostand = 100;;
	Kontoverwaltung Verwaltung = Kontoverwaltung(_kontonummer, _kontostand);

	cout << Verwaltung.getKontostand() << endl;
	cout << Verwaltung.getKontonummer() << endl;

	Verwaltung.startVerwaltung();

	cout << Verwaltung.getKontostand() << endl;
	cout << Verwaltung.getKontonummer() << endl;

	getchar();

	return 0;
}

