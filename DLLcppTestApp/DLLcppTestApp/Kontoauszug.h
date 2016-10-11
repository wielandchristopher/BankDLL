#ifndef KONTOAUSZUG_H
#define KONTOAUSZUG_H

#include "stdafx.h"
#include "Ueberweisung.h"
#include "Kontobewegung.h"
#include "Kontoverwaltung.h"
#include <list>

class Kontoauszug
{
public:
	Kontoauszug(list<Ueberweisung> ueberweisungsListe, list<Kontobewegung> kontobewegungsListe);

	void showKontoauszug();
	//void setUeberweisungsListe(list<Ueberweisung> ueberweisungsListe);
	//void setKontobewegungsListe(list<Kontobewegung> kontobewegungsListe);


private:
	void prepareList();
	list<Ueberweisung> ueberweisungsListe;
	list<Kontobewegung> kontobewegungsListe;
	list<char*> praeperierteListe;
};
#endif