#pragma once

	class CUSTOMER {
	public:

		//Getter und Setter der Kundendaten
		char* CUSTOMER::getVorname() {
			return Vorname;
		};
		void CUSTOMER::setVorname(char* _Vorname) {
			this->Vorname = _Vorname;
		};
		char* CUSTOMER::getNachname() {
			return Nachname;
		};
		void CUSTOMER::setNachname(char* _Nachname) {
			this->Nachname = _Nachname;
		};
		char* CUSTOMER::getGeburtsdatum() {
			return Geburtsdatum;
		};
		void CUSTOMER::setGeburtsdatum(char* _Geburtsdatum) {
			this->Geburtsdatum = _Geburtsdatum;
		};
		char* CUSTOMER::getWohnort() {
			return Wohnort;
		};
		void CUSTOMER::setWohnort(char* _Wohnort) {
			this->Wohnort = _Wohnort;
		};
		char* CUSTOMER::getAdresse() {
			return Adresse;
		};
		void CUSTOMER::setAdresse(char* _Adresse) {
			this->Adresse = _Adresse;
		};
		char* CUSTOMER::getTelefon() {
			return Telefon;
		};
		void CUSTOMER::setTelefon(char* _Telefon) {
			this->Telefon = _Telefon;
		};
		int CUSTOMER::getID() {
			return id;
		};
		void CUSTOMER::setID(int _id) {
			this->id = _id;
		};
		//Typidentifizierer
		char* getClassId() {

			return customer;
		};

	private:
		char* customer = "customer";
		char* Vorname = "";
		char* Nachname = "";
		char* Geburtsdatum = "";
		char* Adresse = "";
		char* Wohnort = "";
		char* Telefon = "";
		int id = 0;
	};


