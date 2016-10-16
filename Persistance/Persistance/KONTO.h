#pragma once
#include "USTOMER.h"
#include <stdio.h>



//generateKtnr erstellt eine Kontonummer und incrementiert immer um 1 hoch


class SPARKONTO {
public:
	SPARKONTO::SPARKONTO()
	{
		this->sparkonto = "sparkonto";
		setKontonummer(generateKtnnr());
		this->Kontostand = 0;
		this->Kontoverfüger = NULL;
		this->optKontoverfüger1 = NULL;
		this->optKontoverfüger2 = NULL;
		this->optKontoverfüger3 = NULL;

	}

	int SPARKONTO::generateKtnnr() {

		static int Kontonummernpool = 10000000;

		Kontonummernpool++;
		return Kontonummernpool;
	}

	//Getter und Setter der Daten
	CUSTOMER SPARKONTO::getVerfüger() {
		return *Kontoverfüger;
	}
	void SPARKONTO::setVerfüger(CUSTOMER* _Kontoverfüger) {
		this->Kontoverfüger = _Kontoverfüger;
	}
	CUSTOMER SPARKONTO::getoptVerfüger1() {
		return *optKontoverfüger1;
	}
	void SPARKONTO::setoptVerfüger1(CUSTOMER* _optKontoverfüger) {
		this->optKontoverfüger1 = _optKontoverfüger;
	}
	CUSTOMER SPARKONTO::getoptVerfüger2() {
		return *optKontoverfüger2;
	}
	void SPARKONTO::setoptVerfüger2(CUSTOMER* _optKontoverfüger) {
		this->optKontoverfüger2 = _optKontoverfüger;
	}
	CUSTOMER SPARKONTO::getoptVerfüger3() {
		return *optKontoverfüger3;
	}
	void SPARKONTO::setoptVerfüger3(CUSTOMER* _optKontoverfüger) {
		this->optKontoverfüger3 = _optKontoverfüger;
	}
	double SPARKONTO::getKontostand() {
		return Kontostand;
	}
	void SPARKONTO::setKontostand(double _Kontostand) {
		this->Kontostand = _Kontostand;
	}
	int SPARKONTO::getKontonummer() {
		return Kontonummer;
	}
	void SPARKONTO::setKontonummer(int _Kontonummer) {
		this->Kontonummer = _Kontonummer;
	}
	//Typidentifizierer
	char* SPARKONTO::getClassId() {

		return sparkonto;
	}

private:
	char* sparkonto;
	int Kontonummer;
	double Kontostand;
	CUSTOMER* Kontoverfüger;
	CUSTOMER* optKontoverfüger1;
	CUSTOMER* optKontoverfüger2;
	CUSTOMER* optKontoverfüger3;
};

class KREDITKONTO {
public:
	KREDITKONTO::KREDITKONTO()
	{
		this->kreditkonto = "kreditkonto";
		setKontonummer(generateKtnnr());
		this->Kontostand = 0;
		this->Kontoverfüger = NULL;
		this->optKontoverfüger1 = NULL;
		this->optKontoverfüger2 = NULL;
		this->optKontoverfüger3 = NULL;

	}

	int KREDITKONTO::generateKtnnr() {

		static int Kontonummernpool = 10000000;

		Kontonummernpool++;
		return Kontonummernpool;
	}

	//Getter und Setter der Daten
	CUSTOMER KREDITKONTO::getVerfüger() {
		return *Kontoverfüger;
	}
	void KREDITKONTO::setVerfüger(CUSTOMER* _Kontoverfüger) {
		this->Kontoverfüger = _Kontoverfüger;
	}
	CUSTOMER KREDITKONTO::getoptVerfüger1() {
		return *optKontoverfüger1;
	}
	void KREDITKONTO::setoptVerfüger1(CUSTOMER* _optKontoverfüger) {
		this->optKontoverfüger1 = _optKontoverfüger;
	}
	CUSTOMER KREDITKONTO::getoptVerfüger2() {
		return *optKontoverfüger2;
	}
	void KREDITKONTO::setoptVerfüger2(CUSTOMER* _optKontoverfüger) {
		this->optKontoverfüger2 = _optKontoverfüger;
	}
	CUSTOMER KREDITKONTO::getoptVerfüger3() {
		return *optKontoverfüger3;
	}
	void KREDITKONTO::setoptVerfüger3(CUSTOMER* _optKontoverfüger) {
		this->optKontoverfüger3 = _optKontoverfüger;
	}
	double KREDITKONTO::getKontostand() {
		return Kontostand;
	}
	void KREDITKONTO::setKontostand(double _Kontostand) {
		this->Kontostand = _Kontostand;
	}
	int KREDITKONTO::getKontonummer() {
		return Kontonummer;
	}
	void KREDITKONTO::setKontonummer(int _Kontonummer) {
		this->Kontonummer = _Kontonummer;
	}
	//Typidentifizierer
	char* getClassId() {

		return kreditkonto;
	}

private:
	char* kreditkonto;
	int Kontonummer;
	double Kontostand;
	CUSTOMER* Kontoverfüger;
	CUSTOMER* optKontoverfüger1;
	CUSTOMER* optKontoverfüger2;
	CUSTOMER* optKontoverfüger3;
};

