#include <iostream>
#include <stdexcept>
#include <string>
#include <iomanip>
#include <initializer_list>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

class Datum {
		int d, m, g;
	public:
		static bool IspravanDatum (int dan, int mjesec, int godina)  {
			int dani[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
			if((godina % 4 == 0 && godina % 100 != 0) || godina % 400 == 0) dani[1]++;
			if(dan<=0 || mjesec <=0 || godina<=0 || godina>2017 || mjesec>12 || dan>dani[mjesec-1]) return false;
			return true;
		}
		Datum(int dan, int mjesec, int godina) {
			if(IspravanDatum(dan, mjesec, godina)==false) throw domain_error("Neispravan datum");
			d=dan; m=mjesec; g=godina;
		}
		void Postavi(int dan, int mjesec, int godina) {
			if(IspravanDatum(dan, mjesec, godina)==false) throw domain_error("Neispravan datum");
			d=dan; m=mjesec; g=godina;
		}
		int DajDan() const {
			return d;
		}
		int DajMjesec() const {
			return m;
		}
		int DajGodinu() const {
			return g;
		}
		void Ispisi() const {
			cout << d << "/" << m << "/" << g;
		}
};

class Kupac {
		string i_i_p;
		Datum d_r=Datum(1, 1, 1);
	public:
		static bool IspravnoImeIPrezime (string test) {
			for(auto it=test.begin(); it!= test.end(); it++) {
				if((*it>='A' && *it<='Z') || (*it>='a' && *it<='z') || (*it>='0' && *it<='9')) continue;
				else if(*it==' ' || *it=='-' || *it==39) continue;
				else return false;
			}
			return true;
		}
		Kupac(const string &ime_i_prezime, const Datum &datum_rodjenja) {
			if(IspravnoImeIPrezime(ime_i_prezime)==false) throw domain_error("Neispravno ime i prezime");
			if(Datum::IspravanDatum(datum_rodjenja.DajDan(), datum_rodjenja.DajMjesec(), datum_rodjenja.DajGodinu())==false)
				throw domain_error("Neispravan datum");
			i_i_p=ime_i_prezime; d_r=Datum(datum_rodjenja.DajDan(), datum_rodjenja.DajMjesec(), datum_rodjenja.DajGodinu());
		}
		void Postavi(const string &ime_i_prezime, const Datum &datum_rodjenja) {
			if(IspravnoImeIPrezime(ime_i_prezime)==false) throw domain_error("Neispravno ime i prezime");
			if(Datum::IspravanDatum(datum_rodjenja.DajDan(), datum_rodjenja.DajMjesec(), datum_rodjenja.DajGodinu())==false)
				throw domain_error("Neispravan datum");
			i_i_p=ime_i_prezime; d_r=Datum(datum_rodjenja.DajDan(), datum_rodjenja.DajMjesec(), datum_rodjenja.DajGodinu());
		}
		string DajImePrezime() const {
			return i_i_p;
		}
		Datum DajDatumRodjenja() const {
			return d_r;
		}
		void Ispisi() const {
			cout << i_i_p << " (";
			d_r.Ispisi();
			cout << ")";
		}

};

class Stan {
	string adr;
	int spr, br_s;
	bool nmj;
	double kvd;
	public:
		Stan(const string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura) {
			if(sprat<=0 || broj_soba<=0 || kvadratura<=0 || (namjesten!=1 && namjesten!=0)) throw domain_error("Neispravan unos podataka");
			adr=adresa; spr=sprat; br_s=broj_soba; nmj=namjesten; kvd=kvadratura;
		}
		void Postavi(const string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura) {
			if(sprat<=0 || broj_soba<=0 || kvadratura<=0) throw domain_error("Neispravan unos podataka");
			adr=adresa; spr=sprat; br_s=broj_soba; nmj=namjesten; kvd=kvadratura;
		}
		string DajAdresu() const {
			return adr;
		}
		int DajSprat() const {
			return spr;
		}
		int DajBrojSoba() const {
			return br_s;
		}
		bool DajNamjesten() const {
			return nmj;
		}
		double DajKvadraturu() const {
			return kvd;
		}
		void Ispisi() const {
			cout << "Stan se nalazi na adresi " << DajAdresu() << " na "
				<< DajSprat() << " spratu i ima " << DajBrojSoba();
				if(DajBrojSoba()==1) cout << " sobu. ";
				else if(DajBrojSoba()==2 || DajBrojSoba()==3 || DajBrojSoba()==4) cout << " sobe. ";
				else cout << " soba. ";
				cout << "Kvadratura stana je " << DajKvadraturu() << " (m^2) i stan ";
				if(DajNamjesten()==true) cout << "je namjesten.";
				else cout << "nije namjesten.";
		}
};

class Prodaja {
		string ime_agenta_prodaje;
		double cijena_stana;
		Datum datum_prodaje=Datum(1,1,1);
		Kupac kupac_stana=Kupac("\0",datum_prodaje);
		Stan kupljeni_stan=Stan("\0",1,1,1,1);
	public:
		Prodaja(const string &ime_agenta_prodaje, double cijena_stana,
			const Datum &datum_prodaje, const Kupac &kupac_stana,
			const Stan &kupljeni_stan) {
				Prodaja::ime_agenta_prodaje=ime_agenta_prodaje;
				Prodaja::cijena_stana=cijena_stana;
				Prodaja::datum_prodaje=Datum(datum_prodaje.DajDan(), datum_prodaje.DajMjesec(), datum_prodaje.DajGodinu());
				Prodaja::kupac_stana=Kupac(kupac_stana.DajImePrezime(), kupac_stana.DajDatumRodjenja());
				Prodaja::kupljeni_stan=Stan(kupljeni_stan.DajAdresu(), kupljeni_stan.DajSprat(), kupljeni_stan.DajBrojSoba(),
				kupljeni_stan.DajNamjesten(), kupljeni_stan.DajKvadraturu());
		}
		Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana,
 			int dan_prodaje, int mjesec_prodaje, int godina_prodaje,
 			std::string &ime_kupca, const Datum &datum_rodjenja_kupca,
 			const std::string &adresa_stana, int sprat_stana, int broj_soba,
 			bool namjesten_stan, double broj_kvadrata) {
 				Prodaja::ime_agenta_prodaje=ime_agenta_prodaje;
 				Prodaja::cijena_stana=cijena_stana;
 				Prodaja::datum_prodaje=Datum(dan_prodaje,mjesec_prodaje,godina_prodaje);
 				Prodaja::kupac_stana=Kupac(ime_kupca,datum_rodjenja_kupca);
 				Prodaja::kupljeni_stan=Stan(adresa_stana,sprat_stana,broj_soba,namjesten_stan,broj_kvadrata);
 		}
 		void PromijeniKupca(const Kupac &novi_kupac) {
 			kupac_stana.Postavi(novi_kupac.DajImePrezime(),novi_kupac.DajDatumRodjenja());
 		}
 		void PromijeniStan(const Stan &novi_stan) {
 			kupljeni_stan.Postavi(novi_stan.DajAdresu(),novi_stan.DajSprat(),
 				novi_stan.DajBrojSoba(),novi_stan.DajNamjesten(),novi_stan.DajKvadraturu());
 		}
 		void PromijeniDatumKupovine(const Datum &novi_datum) {
 			datum_prodaje.Postavi(novi_datum.DajDan(),novi_datum.DajMjesec(),novi_datum.DajGodinu());
 		}
 		void PromijeniCijenuProdaje(const double &nova_cijena) {
 			cijena_stana=nova_cijena;
 		}
 		void PomjeriDanUnaprijed() {
 			int dani_u_mjesecu[]{31,28,31,30,31,30,31,31,30,31,30,31};
 			int dan=datum_prodaje.DajDan(), mjesec=datum_prodaje.DajMjesec(), godina=datum_prodaje.DajGodinu();
 			dan++;
 			if((godina % 4 == 0 && godina % 100 != 0) || godina % 400 == 0) dani_u_mjesecu[1]++;
 			if(dan>dani_u_mjesecu[mjesec-1]) {
 				dan=1;
 				mjesec++;
 			}
 			if(mjesec>12) {
 				godina++;
 				mjesec=1;
 				dan=1;
 			}
 			datum_prodaje.Postavi(dan,mjesec,godina);
 		}
 		void PomjeriDanUnazad() {
 			int dani_u_mjesecu[]{31,28,31,30,31,30,31,31,30,31,30,31};
 			int dan=datum_prodaje.DajDan(), mjesec=datum_prodaje.DajMjesec(), godina=datum_prodaje.DajGodinu();
 			dan--;
 			if((godina % 4 == 0 && godina % 100 != 0) || godina % 400 == 0) dani_u_mjesecu[1]++;
 			if(dan<dani_u_mjesecu[mjesec-1]) {
 				mjesec--;
 				dan=dani_u_mjesecu[mjesec];
 			}
 			if(mjesec<1) {
 				godina--;
 				mjesec=12;
 				dan=31;
 			}
 			datum_prodaje.Postavi(dan,mjesec,godina);
 		}
 		string DajImeAgenta() const {
 			return ime_agenta_prodaje;
 		}
 		string DajImeKupca() const {
 			return kupac_stana.DajImePrezime();
 		}
 		Datum DajDatumProdaje() const {
 			return datum_prodaje;
 		}
 		double DajCijenuStana() const {
 			return cijena_stana;
 		}
 		friend bool ProdatPrije(const Prodaja &p1, const Prodaja &p2);
		friend bool SkupljiStan(const Prodaja &p1, const Prodaja &p2);
		void Ispisi() const {
			cout << left << setw(32) << "Ime agenta: ";
			cout << ime_agenta_prodaje << endl;
			cout << left << setw(32) << "Ime kupca: ";
			kupac_stana.Ispisi();
			cout << endl;
			cout << left << setw(32) << "Zakazani datum prodaje: ";
			datum_prodaje.Ispisi();
			cout << endl;
			cout << left << setw(32) << "Cijena stana: ";
			cout << cijena_stana << endl;
			cout << "Informacije o stanu: " << endl;
			kupljeni_stan.Ispisi();
		}
};

bool ProdatPrije(const Prodaja &p1, const Prodaja &p2) {
	if(p1.datum_prodaje.DajGodinu()<p2.datum_prodaje.DajGodinu()) return true;
	else if(p1.datum_prodaje.DajGodinu()>p2.datum_prodaje.DajGodinu()) return false;
	else {
		if(p1.datum_prodaje.DajMjesec()<p2.datum_prodaje.DajMjesec()) return true;
		else if(p1.datum_prodaje.DajMjesec()>p2.datum_prodaje.DajMjesec()) return false;
		else {
			if(p1.datum_prodaje.DajDan()<p2.datum_prodaje.DajDan()) return true;
			else if(p1.datum_prodaje.DajMjesec()>p2.datum_prodaje.DajMjesec()) return false;
		}
	}
	return false;
}

bool SkupljiStan(const Prodaja &p1, const Prodaja &p2) {
	if(p1.cijena_stana>p2.cijena_stana) return true;
	return false;
}

class Prodaje {
		int max_broj_prodaja, broj_prodaja;
		Prodaja **prod;
	public:
		explicit Prodaje(int max_broj_prodaja);
		Prodaje(std::initializer_list<Prodaja> spisak_prodaja);
		~Prodaje() {
			for(int i=0; i<broj_prodaja; i++) delete prod[i];
			delete [] prod;
		}
		Prodaje(const Prodaje &prodaje);
		Prodaje(Prodaje &&prodaje);
		Prodaje &operator =(const Prodaje &prodaje);
		Prodaje &operator =(Prodaje &&prodaje);
		void RegistrirajProdaju(const string &ime_agenta_prodaje,
 			double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana,
			const Stan &kupljeni_stan); 
		void RegistrirajProdaju(const string &ime_agenta_prodaje, double cijena_stana, 
			int dan_prodaje, int mjesec_prodaje, int godina_prodaje, string &ime_kupca, 
			const Datum &datum_rodjenja_kupca, const string &adresa_stana,
 			int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata);
 		void RegistrirajProdaju(Prodaja *prodaja);
 		int DajBrojProdaja() const {
 			return broj_prodaja;
 		}
 		int DajBrojProdajaNaDatum(const Datum &datum) const;
 		int DajBrojProdajaOdAgenta(const std::string &ime_agenta) const;
 		Prodaja &DajNajranijuProdaju(); 
 		Prodaja DajNajranijuProdaju() const;
 		Prodaja &DajNajskupljuProdaju();
		Prodaja DajNajskupljuProdaju() const;
		void IsprazniKolekciju() {
			for(int i=0; i<broj_prodaja; i++) delete prod[i];
			broj_prodaja=0;
		};
		void ObrisiNajranijuProdaju();
		void ObrisiProdajeAgenta(const string &ime_agenta);
		void ObrisiProdajeNaDatum(const Datum &datum);
		void IspisiProdajeNaDatum(const Datum &datum) const;
		void IspisiSveProdaje() const;
		Prodaja &DajProdaju(int redni_broj_prodaje) {
			if(redni_broj_prodaje>broj_prodaja || redni_broj_prodaje<=0) throw range_error("Neispravan redni broj");
			return *prod[redni_broj_prodaje-1];
		}
};	

Prodaje::Prodaje(int max_broj_prodaja) : max_broj_prodaja(max_broj_prodaja), broj_prodaja(0),
	prod(new Prodaja*[max_broj_prodaja]) {}
	
Prodaje::Prodaje(std::initializer_list<Prodaja> spisak_prodaja) : max_broj_prodaja(spisak_prodaja.size()), 
	broj_prodaja(spisak_prodaja.size()), prod(new Prodaja*[spisak_prodaja.size()]) {
		int i(0);
		for(auto p=spisak_prodaja.begin(); p!=spisak_prodaja.end(); p++, i++) prod[i]=new Prodaja(*p);
	}

Prodaje::Prodaje(const Prodaje &prodaje) : max_broj_prodaja(prodaje.max_broj_prodaja),
	broj_prodaja(prodaje.broj_prodaja), prod(new Prodaja*[max_broj_prodaja]) {
		for(int i=0; i<broj_prodaja; i++) prod[i]=new Prodaja(*prodaje.prod[i]);
	}

Prodaje::Prodaje(Prodaje &&prodaje) : max_broj_prodaja(prodaje.max_broj_prodaja),
	broj_prodaja(prodaje.broj_prodaja), prod(prodaje.prod) {
		prodaje.prod=nullptr;
	}
	
Prodaje &Prodaje::operator =(const Prodaje &prodaje) {
	for(int i=broj_prodaja; i<prodaje.broj_prodaja; i++) prod[i]=new Prodaja(*prodaje.prod[i]);
	broj_prodaja=prodaje.broj_prodaja;
	for(int i=0; i<prodaje.broj_prodaja; i++) {
		*prod[i]=*prodaje.prod[i];
	}
	return *this;
}

Prodaje &Prodaje::operator =(Prodaje &&prodaje) {
	broj_prodaja=prodaje.broj_prodaja;
	prod=prodaje.prod;
	prodaje.broj_prodaja=0;
	prodaje.prod=nullptr;
	return *this;
}

void Prodaje::RegistrirajProdaju(const string &ime_agenta_prodaje,
	double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana,
	const Stan &kupljeni_stan) {
		if(broj_prodaja+1>max_broj_prodaja) throw range_error("Dostignut maksimalni broj prodaja");
		prod[broj_prodaja]=new Prodaja(ime_agenta_prodaje,cijena_stana,datum_prodaje,kupac_stana,kupljeni_stan);
		broj_prodaja++;
	}
	
void Prodaje::RegistrirajProdaju(const string &ime_agenta_prodaje, double cijena_stana, 
	int dan_prodaje, int mjesec_prodaje, int godina_prodaje, string &ime_kupca, 
	const Datum &datum_rodjenja_kupca, const string &adresa_stana,
 	int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata) {
 		if(broj_prodaja+1>max_broj_prodaja) throw range_error("Dostignut maksimalni broj prodaja");
		prod[broj_prodaja]=new Prodaja(ime_agenta_prodaje,cijena_stana,Datum(dan_prodaje,mjesec_prodaje,godina_prodaje),
			Kupac(ime_kupca,datum_rodjenja_kupca),Stan(adresa_stana,sprat_stana,broj_soba,namjesten_stan,broj_kvadrata));
		broj_prodaja++;
 	}

void Prodaje::RegistrirajProdaju(Prodaja *prodaja) {
	if(broj_prodaja+1>max_broj_prodaja) throw range_error("Dostignut maksimalni broj prodaja");
		prod[broj_prodaja]=new Prodaja(*prodaja);
		broj_prodaja++;
}

int Prodaje::DajBrojProdajaNaDatum(const Datum &datum) const {
	return count_if(prod, prod+broj_prodaja, [datum](Prodaja *prod) -> bool {
		if(prod->DajDatumProdaje().DajGodinu()==datum.DajGodinu() &&
		   prod->DajDatumProdaje().DajMjesec()==datum.DajMjesec() &&
		   prod->DajDatumProdaje().DajDan()==datum.DajDan()) return true;
		return false;
	});
}
	
int Prodaje::DajBrojProdajaOdAgenta(const std::string &ime_agenta) const {
	return count_if(prod, prod+broj_prodaja, [ime_agenta](Prodaja *prod) -> bool {
		if(prod->DajImeAgenta()==ime_agenta) return true;
		return false;
	});
}

Prodaja Prodaje::DajNajranijuProdaju() const {
	if(broj_prodaja==0) throw domain_error("Nema registriranih prodaja");
	return **min_element(prod, prod+broj_prodaja, [](Prodaja *prod_1, Prodaja *prod_2) {
		if(ProdatPrije(*prod_1,*prod_2)==true) return true;
		return false;
	});
}

Prodaja &Prodaje::DajNajranijuProdaju() {
	if(broj_prodaja==0) throw domain_error("Nema registriranih prodaja");
	return **min_element(prod, prod+broj_prodaja, [](Prodaja *prod_1, Prodaja *prod_2) {
		if(ProdatPrije(*prod_1,*prod_2)==true) return true;
		return false;
	});
}

Prodaja Prodaje::DajNajskupljuProdaju() const {
	if(broj_prodaja==0) throw domain_error("Nema registriranih prodaja");
	return **max_element(prod, prod+broj_prodaja, [](Prodaja *prod_1, Prodaja *prod_2) {
		if(SkupljiStan(*prod_1,*prod_2)==true) return true;
		return false;
	});
}

Prodaja &Prodaje::DajNajskupljuProdaju() {
	if(broj_prodaja==0) throw domain_error("Nema registriranih prodaja");
	return **max_element(prod, prod+broj_prodaja, [](Prodaja *prod_1, Prodaja *prod_2) {
		if(SkupljiStan(*prod_1,*prod_2)==true) return true;
		return false;
	});
}

void Prodaje::ObrisiNajranijuProdaju() {
	Prodaja za_brisanje=DajNajranijuProdaju();
	for(int i=0; i<broj_prodaja; i++) {
		if((*prod[i]).DajImeAgenta()==za_brisanje.DajImeAgenta() &&
		   (*prod[i]).DajImeKupca()==za_brisanje.DajImeKupca() && 
		   abs((*prod[i]).DajCijenuStana()-za_brisanje.DajCijenuStana())<0.0001 && 
		   (*prod[i]).DajDatumProdaje().DajGodinu()==za_brisanje.DajDatumProdaje().DajGodinu() && 
		   (*prod[i]).DajDatumProdaje().DajMjesec()==za_brisanje.DajDatumProdaje().DajMjesec() && 
		   (*prod[i]).DajDatumProdaje().DajDan()==za_brisanje.DajDatumProdaje().DajDan()) {
		   		for(int j=i; j<broj_prodaja-1; j++) {
				delete prod[j];
				prod[j]=prod[j+1];
				}
		}
	}
	delete prod[broj_prodaja-1];
	broj_prodaja--;
}

void Prodaje::ObrisiProdajeAgenta(const string &ime_agenta) {
	for(int i=0; i<broj_prodaja; i++) {
		if((*prod[i]).DajImeAgenta()==ime_agenta) {
		   	for(int j=i; j<broj_prodaja-1; j++) {
			delete prod[j];
			prod[j]=prod[j+1];
			}
		delete prod[broj_prodaja-1];
		broj_prodaja--;
		}
	}
}

void Prodaje::ObrisiProdajeNaDatum(const Datum &datum) {
	for(int i=0; i<broj_prodaja; i++) {
		if((*prod[i]).DajDatumProdaje().DajGodinu()==datum.DajGodinu() && 
		   (*prod[i]).DajDatumProdaje().DajMjesec()==datum.DajMjesec() && 
		   (*prod[i]).DajDatumProdaje().DajDan()==datum.DajDan()) {
		   	for(int j=i; j<broj_prodaja-1; j++) {
			delete prod[j];
			prod[j]=prod[j+1];
			}
		delete prod[broj_prodaja-1];
		broj_prodaja--;
		}
	}
}

void Prodaje::IspisiProdajeNaDatum(const Datum &datum) const {
	vector <int> indeksi;
	for(int i=0; i<broj_prodaja; i++) {
		if((*prod[i]).DajDatumProdaje().DajGodinu()==datum.DajGodinu() && 
		   (*prod[i]).DajDatumProdaje().DajMjesec()==datum.DajMjesec() && 
		   (*prod[i]).DajDatumProdaje().DajDan()==datum.DajDan())
		   	indeksi.push_back(i);
	}
	sort(indeksi.begin(), indeksi.end(), [this](int prvi, int drugi) ->bool {
		if((*prod[prvi]).DajImeKupca()<(*prod[drugi]).DajImeKupca()) return true;
		return false;
	});
	for(int i=0; i<indeksi.size(); i++) {
		(*prod[indeksi[i]]).Ispisi();
		cout << endl;
	}
}

void Prodaje::IspisiSveProdaje() const {
	vector <int> indeksi;
	for(int i=0; i<broj_prodaja; i++) {
		   	indeksi.push_back(i);
	}
	sort(indeksi.begin(), indeksi.end(), [this](int prvi, int drugi) ->bool {
		if((*prod[prvi]).DajDatumProdaje().DajGodinu()<(*prod[drugi]).DajDatumProdaje().DajGodinu()) return true;
		else if((*prod[prvi]).DajDatumProdaje().DajGodinu()>(*prod[drugi]).DajDatumProdaje().DajGodinu()) return false;
		else {
			if((*prod[prvi]).DajDatumProdaje().DajMjesec()<(*prod[drugi]).DajDatumProdaje().DajMjesec()) return true;
			else if((*prod[prvi]).DajDatumProdaje().DajMjesec()>(*prod[drugi]).DajDatumProdaje().DajMjesec()) return false;
			else {
				if((*prod[prvi]).DajDatumProdaje().DajDan()<(*prod[drugi]).DajDatumProdaje().DajDan()) return true;
				else if((*prod[prvi]).DajDatumProdaje().DajDan()>(*prod[drugi]).DajDatumProdaje().DajDan()) return false;
				else {
					if((*prod[prvi]).DajImeKupca()<(*prod[drugi]).DajImeKupca()) return true;
					return false;
				}
			}
		}
	});
	for(int i=0; i<indeksi.size(); i++) {
		(*prod[indeksi[i]]).Ispisi();
		cout << endl;
	}
}

bool f(int x) {
	if(x==0) return false;
	else if(x==1) return true;
	throw domain_error("Neispravan unos podataka");
} 
 
int main ()
{ 
	vector<Stan> stanovi;
	vector<Kupac> kupci;
	cout << "Dobrodosli!\n\n";
	pocetak:
	cout << "Izaberite opciju: \n";
	cout << " 0 - kraj\n";
	cout << " 1 - uredjivanje stanova\n";
	cout << " 2 - uredjivanje kupaca\n";
	cout << " 3 - uredjivanje prodaja\n";
	int opcija_1;
	cin >> opcija_1;
	if(opcija_1==0) { cout << "\nDovidjenja!"; return 0; }
	else if(opcija_1==1) {
		ponovo_1:
		cout << "Izaberite opciju: \n";
		cout << " 0 - nazad\n";
		cout << " 1 - dodavanje stanova\n";
		cout << " 2 - uredjivanje stanova\n";
		cout << " 3 - ispis svih stanova\n";
		cout << " 4 - kraj\n";
		int opcija_1_1;
		cin >> opcija_1_1;
		if(opcija_1_1==0) goto pocetak;
		if(opcija_1_1==1) {
			ponovo_1_1:
			cout << "Unesite adresu: ";
			string adresa;
			cin >> adresa;
			cout << "Unesite sprat: ";
			int sprat;
			cin >> sprat;
			cout << "Unesite broj soba: ";
			int br_soba;
			cin >> br_soba;
			cout << "Da li je stan namjesten (1 - da, 0 - ne): ";
			int nmj;
			cin>> nmj;
			cout << "Unesite kvadraturu: ";
			double kvadratura;
			cin >> kvadratura;
			try {
				bool n=f(nmj);
				Stan stan=Stan(adresa,sprat,br_soba,n,kvadratura);
				stanovi.push_back(stan);
				cout << "Stan je uspjesno dodan!\n\n";
				goto ponovo_1;
			}
			catch(domain_error err) {
				cout << "Izuzetak: " << err.what();
				cout << ". Molimo ponovite unos.\n\n";
				goto ponovo_1_1;
			}
		}
		if(opcija_1_1==3) {
			for(int i=0; i<stanovi.size(); i++) {
				cout << i+1 << ". ";
				stanovi[i].Ispisi();
				cout << endl;
			}
			cout << "\n";
			goto ponovo_1;
		}
		if(opcija_1_1==2) {
			cout << "Odaberite stan. Dostupni stanovi su:\n";
			for(int i=0; i<stanovi.size(); i++) {
				cout << i+1 << ". ";
				stanovi[i].Ispisi();
				cout << endl;
			}
			int koji_stan, opcija_1_1_2;
			cin >> koji_stan;
			cout << "Odaberite polje koji zelite urediti: ";
			cout << " 0 - nazad\n";
			cout << " 1 - adresa\n";
			cout << " 2 - sprat\n";
			cout << " 3 - broj_soba\n";
			cout << " 4 - da li je stan namjesten\n";
			cout << " 5 - kvadratura\n";
			cout << " 6 - sve\n";
			cin >> opcija_1_1_2;
			if(opcija_1_1_2==0) goto ponovo_1;
			else if(opcija_1_1_2==1) {
				ponovo_1_1_2_1:
				cout << "Unesite adresu: ";
				string adresa;
				cin >> adresa;
				try {
					stanovi[koji_stan].Postavi(adresa, stanovi[koji_stan].DajSprat(), stanovi[koji_stan].DajBrojSoba(), stanovi[koji_stan].DajNamjesten(), stanovi[koji_stan].DajKvadraturu());
					cout << "Stan je uspjesno izmijenjen!\n";
					goto ponovo_1;
				}
				catch(domain_error err) {
					cout << "Izuzetak: " << err.what();
					cout << ". Molimo unesite opet.\n";
					goto ponovo_1_1_2_1;
				}
			}
			else if(opcija_1_1_2==2) {
				ponovo_1_1_2_2:
				cout << "Unesite sprat: ";
				int sprat;
				cin >> sprat;
				try {
					stanovi[koji_stan].Postavi(stanovi[koji_stan].DajAdresu(), sprat, stanovi[koji_stan].DajBrojSoba(), stanovi[koji_stan].DajNamjesten(), stanovi[koji_stan].DajKvadraturu());
					cout << "Stan je uspjesno izmijenjen!\n";
					goto ponovo_1;
				}
				catch(domain_error err) {
					cout << "Izuzetak: " << err.what();
					cout << ". Molimo unesite opet.\n";
					goto ponovo_1_1_2_2;
				}
			}
			else if(opcija_1_1_2==3) {
				ponovo_1_1_2_3:
				cout << "Unesite broj soba: ";
				int broj_soba;
				cin >> broj_soba;
				try {
					stanovi[koji_stan].Postavi(stanovi[koji_stan].DajAdresu(), stanovi[koji_stan].DajSprat(), broj_soba, stanovi[koji_stan].DajNamjesten(), stanovi[koji_stan].DajKvadraturu());
					cout << "Stan je uspjesno izmijenjen!\n";
					goto ponovo_1;
				}
				catch(domain_error err) {
					cout << "Izuzetak: " << err.what();
					cout << ". Molimo unesite opet.\n";
					goto ponovo_1_1_2_3;
				}
			}
			else if(opcija_1_1_2==4) {
				ponovo_1_1_2_4:
				cout << "Da li je stan namjesten (1 - da, 0 - ne): ";
				int nmj;
				cin>> nmj;
				try {
					bool n=f(nmj);
					stanovi[koji_stan].Postavi(stanovi[koji_stan].DajAdresu(), stanovi[koji_stan].DajSprat(), stanovi[koji_stan].DajBrojSoba(), n, stanovi[koji_stan].DajKvadraturu());
					cout << "Stan je uspjesno izmijenjen!\n";
					goto ponovo_1;
				}
				catch(domain_error err) {
					cout << "Izuzetak: " << err.what();
					cout << ". Molimo unesite opet.\n";
					goto ponovo_1_1_2_4;
				}
			}
			else if(opcija_1_1_2==5) {
				ponovo_1_1_2_5:
				cout << "Unesite kvadraturu: ";
				double kvadratura;
				cin >> kvadratura;
				try {
					stanovi[koji_stan].Postavi(stanovi[koji_stan].DajAdresu(), stanovi[koji_stan].DajSprat(), stanovi[koji_stan].DajBrojSoba(), stanovi[koji_stan].DajNamjesten(), kvadratura);
					cout << "Stan je uspjesno izmijenjen!\n";
					goto ponovo_1;
				}
				catch(domain_error err) {
					cout << "Izuzetak: " << err.what();
					cout << ". Molimo unesite opet.\n";
					goto ponovo_1_1_2_5;
				}
			}
			else if(opcija_1_1_2==6) {
				ponovo_1_1_2_6:
				cout << "Unesite adresu: ";
				string adresa;
				cin >> adresa;
				cout << "Unesite sprat: ";
				int sprat;
				cin >> sprat;
				cout << "Unesite broj soba: ";
				int br_soba;
				cin >> br_soba;
				cout << "Da li je stan namjesten (1 - da, 0 - ne): ";
				int nmj;
				cin>> nmj;
				cout << "Unesite kvadraturu: ";
				double kvadratura;
				cin >> kvadratura;
				try {
					bool n=f(nmj);
					stanovi[koji_stan].Postavi(adresa,sprat,br_soba,n,kvadratura);
					cout << "Stan je uspjesno izmjenjen!\n\n";
					goto ponovo_1;
					}
				catch(domain_error err) {
					cout << "Izuzetak: " << err.what();
					cout << ". Molimo ponovite unos.\n\n";
					goto ponovo_1_1_2_6;
				}
			}
		}
		if(opcija_1_1==4) { cout << "\nDovidjenja!"; return 0; }
	}
	else if(opcija_1==2) {
		ponovo_2:
		cout << "Izaberite opciju: \n";
		cout << " 0 - nazad\n";
		cout << " 1 - dodavanje kupca\n";
		cout << " 2 - uredjivanje kupca\n";
		cout << " 3 - ispis svih kupaca\n";
		cout << " 4 - kraj\n";
		int opcija_1_2;
		cin >> opcija_1_2;
		if(opcija_1_2==1) {
			cout << "Unesite ime i prezime kupca: ";
			string iip;
			cin >> iip;
			cout << "Unesite datum rodjenja (formata dan/mjesec/godina):";
			int d,m,g;
			cin >> d >> m >> g;
			Kupac kupac=Kupac(iip, Datum(d,m,g));
			cout << "Kupac uspjesno dodan!";
		}
	}
	return 0;
}