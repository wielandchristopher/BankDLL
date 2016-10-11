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
	//welche über die Schnittstelle übertragen werden sollen.
	typedef struct CUSTOMER CUSTOMER;
	typedef struct SPARKONTO SPARKONTO;
	typedef struct KREDITKONTO KREDITKONTO;
	
	CUSTOMER_API CUSTOMER* NeuerKunde(char* _Vorname, char* _Nachname, char* _Geburtsdatum, char* _adresse, char* _Wohnort, char* _Telefon);
	CUSTOMER_API void Kundenvornamenänderung(CUSTOMER *Kunde, char* Vorname);
	CUSTOMER_API void Kundennachnamenänderung(CUSTOMER *Kunde, char* _Nachname);
	CUSTOMER_API void Kundenadressänderung(CUSTOMER *Kunde, char* _Adresse);
	CUSTOMER_API void Kundenwohnortsänderung(CUSTOMER *Kunde, char* _Wohnort);
	CUSTOMER_API void Kundentelefonänderung(CUSTOMER *Kunde, char* _Telefon);
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
		char* getClassId() {

			return sparkonto;
		}

		//Konstruktor zur Erstellung des Kontos mit Kontonummer 
		SPARKONTO();

	private:
		char* sparkonto = "sparkonto";
		int Kontonummer;
		double Kontostand = 0;
		CUSTOMER* Kontoverfüger;
		CUSTOMER* optKontoverfüger1;
		CUSTOMER* optKontoverfüger2;
		CUSTOMER* optKontoverfüger3;
	};
	class KREDITKONTO {
	public:
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

		//Konstruktor zur Erstellung des Kontos mit Kontonummer 
		KREDITKONTO();

	private:
		char* kreditkonto = "kreditkonto";
		int Kontonummer;
		double Kontostand = 0;
		CUSTOMER* Kontoverfüger;
		CUSTOMER* optKontoverfüger1;
		CUSTOMER* optKontoverfüger2;
		CUSTOMER* optKontoverfüger3;
	};

#endif /* CUSTOMER__H_ */

#ifdef __cplusplus
}
#endif
