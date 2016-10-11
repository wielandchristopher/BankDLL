//Zum definieren, welche FUnktion exportiert wird
#ifdef CUSTOMER_EXPORTS
#define CUSTOMER_API   __declspec( dllexport ) 
#else
#define CUSTOMER_API __declspec(dllimport) 
#endif

//Hier wird die Sprache angegeben, welche in C konvertiert werden muss
#ifdef __cplusplus
extern "C" {
#endif

	//Hier werden alle Funktionsdefinitionen reingeschrieben, 
	//welche �ber die Schnittstelle �bertragen werden sollen.
	typedef struct CUSTOMER CUSTOMER;
	typedef struct SPARKONTO SPARKONTO;
	typedef struct KREDITKONTO KREDITKONTO;
	
	CUSTOMER_API CUSTOMER* NeuerKunde(char* _Vorname, char* _Nachname, char* _Geburtsdatum, char* _adresse, char* _Wohnort, char* _Telefon);
	CUSTOMER_API void Kundenvornamen�nderung(CUSTOMER *Kunde, char* Vorname);
	CUSTOMER_API void Kundennachnamen�nderung(CUSTOMER *Kunde, char* _Nachname);
	CUSTOMER_API void Kundenadress�nderung(CUSTOMER *Kunde, char* _Adresse);
	CUSTOMER_API void Kundenwohnorts�nderung(CUSTOMER *Kunde, char* _Wohnort);
	CUSTOMER_API void Kundentelefon�nderung(CUSTOMER *Kunde, char* _Telefon);
	CUSTOMER_API void Kundendatenabfrage(CUSTOMER * Kunde);
	CUSTOMER_API void Kundeentfernen(CUSTOMER* Kunde);
	CUSTOMER_API SPARKONTO* NeuesSparkonto(CUSTOMER* Kunde);
	CUSTOMER_API SPARKONTO* NeuesSparkonto2(CUSTOMER* Kunde, CUSTOMER* Kunde2);
	CUSTOMER_API SPARKONTO* NeuesSparkonto3(CUSTOMER* Kunde, CUSTOMER* Kunde2, CUSTOMER* Kunde3);
	CUSTOMER_API SPARKONTO* NeuesSparkonto4(CUSTOMER* Kunde, CUSTOMER* Kunde2, CUSTOMER* Kunde3, CUSTOMER* Kunde4);
	CUSTOMER_API KREDITKONTO* NeuesKreditkonto(CUSTOMER* Kunde);
	CUSTOMER_API KREDITKONTO* NeuesKreditkonto2(CUSTOMER* Kunde, CUSTOMER* Kunde2);
	CUSTOMER_API KREDITKONTO* NeuesKreditkonto3(CUSTOMER* Kunde, CUSTOMER* Kunde2, CUSTOMER* Kunde3);
	CUSTOMER_API KREDITKONTO* NeuesKreditkonto4(CUSTOMER* Kunde, CUSTOMER* Kunde2, CUSTOMER* Kunde3, CUSTOMER* Kunde4);
	CUSTOMER_API void Sparkontoentfernen(SPARKONTO* Konto);
	CUSTOMER_API void Kreditkontoentfernen(KREDITKONTO* Konto);
	
#ifndef CUSTOMER__H_
#define CUSTOMER__H_

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
		//Typidentifizierer
		char* getClassId() {

			return customer;
		};

	private:
		char* customer = "customer";
		char* Vorname;
		char* Nachname;
		char* Geburtsdatum;
		char* Adresse;
		char* Wohnort;
		char* Telefon;
	};
	class SPARKONTO {
	public:
		//Getter und Setter der Daten
		CUSTOMER SPARKONTO::getVerf�ger() {
			return *Kontoverf�ger;
		}
		void SPARKONTO::setVerf�ger(CUSTOMER* _Kontoverf�ger) {
			this->Kontoverf�ger = _Kontoverf�ger;
		}
		CUSTOMER SPARKONTO::getoptVerf�ger1() {
			return *optKontoverf�ger1;
		}
		void SPARKONTO::setoptVerf�ger1(CUSTOMER* _optKontoverf�ger) {
			this->optKontoverf�ger1 = _optKontoverf�ger;
		}
		CUSTOMER SPARKONTO::getoptVerf�ger2() {
			return *optKontoverf�ger2;
		}
		void SPARKONTO::setoptVerf�ger2(CUSTOMER* _optKontoverf�ger) {
			this->optKontoverf�ger2 = _optKontoverf�ger;
		}
		CUSTOMER SPARKONTO::getoptVerf�ger3() {
			return *optKontoverf�ger3;
		}
		void SPARKONTO::setoptVerf�ger3(CUSTOMER* _optKontoverf�ger) {
			this->optKontoverf�ger3 = _optKontoverf�ger;
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
		char* getClassId() {

			return sparkonto;
		}

		//Konstruktor zur Erstellung des Kontos mit Kontonummer 
		SPARKONTO();

	private:
		char* sparkonto = "sparkonto";
		int Kontonummer;
		double Kontostand = 0;
		CUSTOMER* Kontoverf�ger;
		CUSTOMER* optKontoverf�ger1;
		CUSTOMER* optKontoverf�ger2;
		CUSTOMER* optKontoverf�ger3;
	};
	class KREDITKONTO {
	public:
		//Getter und Setter der Daten
		CUSTOMER KREDITKONTO::getVerf�ger() {
			return *Kontoverf�ger;
		}
		void KREDITKONTO::setVerf�ger(CUSTOMER* _Kontoverf�ger) {
			this->Kontoverf�ger = _Kontoverf�ger;
		}
		CUSTOMER KREDITKONTO::getoptVerf�ger1() {
			return *optKontoverf�ger1;
		}
		void KREDITKONTO::setoptVerf�ger1(CUSTOMER* _optKontoverf�ger) {
			this->optKontoverf�ger1 = _optKontoverf�ger;
		}
		CUSTOMER KREDITKONTO::getoptVerf�ger2() {
			return *optKontoverf�ger2;
		}
		void KREDITKONTO::setoptVerf�ger2(CUSTOMER* _optKontoverf�ger) {
			this->optKontoverf�ger2 = _optKontoverf�ger;
		}
		CUSTOMER KREDITKONTO::getoptVerf�ger3() {
			return *optKontoverf�ger3;
		}
		void KREDITKONTO::setoptVerf�ger3(CUSTOMER* _optKontoverf�ger) {
			this->optKontoverf�ger3 = _optKontoverf�ger;
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

		//Konstruktor zur Erstellung des Kontos mit Kontonummer 
		KREDITKONTO();

	private:
		char* kreditkonto = "kreditkonto";
		int Kontonummer;
		double Kontostand = 0;
		CUSTOMER* Kontoverf�ger;
		CUSTOMER* optKontoverf�ger1;
		CUSTOMER* optKontoverf�ger2;
		CUSTOMER* optKontoverf�ger3;
	};

#endif /* CUSTOMER__H_ */

#ifdef __cplusplus
}
#endif
