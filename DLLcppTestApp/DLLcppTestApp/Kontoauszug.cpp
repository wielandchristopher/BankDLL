#include "Kontoauszug.h"
#include "Ueberweisung.h"
#include "Kontobewegung.h"
#include <stdio.h>
#include <string>

using namespace std;

Kontoauszug::Kontoauszug(list<Ueberweisung> ueberweisungsListe, list<Kontobewegung> kontobewegungsListe)
{
	this->ueberweisungsListe = ueberweisungsListe;
	this->kontobewegungsListe = kontobewegungsListe;
}

void Kontoauszug::showKontoauszug()
{
	// List prepare -> dann wiedergeben [nach Datum]

	cout << '\n';
	cout << "Kontoauszug " << endl;
	cout << "Kontonummer: " << endl; // TODO
}

void Kontoauszug::prepareList()
{
	// 2 for -> in neue char liste speichern
	list<Ueberweisung>::iterator itUe;
	list<Kontobewegung>::iterator itKo;

	for (itUe = this->ueberweisungsListe.begin(); itUe != this->ueberweisungsListe.end(); itUe++)
	{
		for (itKo = this->kontobewegungsListe.begin(); itKo != this->kontobewegungsListe.end(); itKo++)
		{
			// TODO Datum vergleichen? wie?
			if ((*itKo).getDatum() < (*itUe).getDatum())
			{
				// itKo in liste hinzufügen --> GETTER, vergleich mim zweiten
				// neues char array erstellen und einfügen
				//char newChar[10] = { (*itKo).getDatum(), (*itKo). }
				
				/*char *newChar;
				newChar = new char[3];
				newChar[0] = (*itKo).getDatum();
				newChar[1] = (*itKo).getVerwendungszweck();
				newChar[2] = (*itKo).getBetrag(); */

				// TODO checken ob getVerwendungszweck 0 ist
				string str((*itKo).getVerwendungszweck());
				string newString = (*itKo).getDatum() + ', ' + str + ', ' + (*itKo).getBetrag() + '; ';
				
			}
			else
			{

			}
		}
	}
}

/*
void Kontoauszug::setUeberweisungsListe(list<Ueberweisung> ueberweisungsListe)
{

}

void Kontoauszug::setKontobewegungsListe(list<Kontobewegung> kontobewegungsListe)
{

}
*/
