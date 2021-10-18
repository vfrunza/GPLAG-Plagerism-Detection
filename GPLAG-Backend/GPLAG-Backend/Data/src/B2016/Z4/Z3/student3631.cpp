/B 2016/2017, Zadaća 4, Zadatak 3
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <string>
#include <iomanip>
#include <stdexcept>
#include <initializer_list>
#include <algorithm>
#include <vector>

using namespace std;

class Datum
{
    int dan, mjesec, godina;
    friend class Prodaja;
    public:
        Datum(int dan, int mjesec, int godina) { Postavi(dan, mjesec, godina); }
        void Postavi(int dan, int mjesec, int godina);
        int DajDan() const { return dan; }
        int DajMjesec() const { return mjesec; }
        int DajGodinu() const { return godina; }
        void Ispisi() const { cout << dan << "/" << mjesec << "/" << godina; }
};

class Kupac
{
    string ime_i_prezime;
    Datum datum_rodjenja;
    public:    
        Kupac(const string &ime_i_prezime, const Datum &datum_rodjenja) : datum_rodjenja(datum_rodjenja) { Postavi(ime_i_prezime, datum_rodjenja); }
        void Postavi(const string &ime_i_prezime, const Datum &datum_rodjenja);
        string DajImePrezime() const { return ime_i_prezime; }
        Datum DajDatumRodjenja() const { return datum_rodjenja; }
        void Ispisi() const { cout << DajImePrezime() << " (" << datum_rodjenja.DajDan() << "/" << datum_rodjenja.DajMjesec() << "/" << datum_rodjenja.DajGodinu() << ")" << endl; }
};

class Stan
{
    string adresa;
    int sprat, broj_soba;
    bool namjesten;
    double kvadratura;
    public:    
        Stan(const string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura) { Postavi(adresa, sprat, broj_soba, namjesten, kvadratura); }
        void Postavi(const string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura);
        string DajAdresu() const { return adresa; }
        int DajSprat() const { return sprat; }
        int DajBrojSoba() const { return broj_soba; }
        bool DajNamjesten() const { return namjesten; }
        double DajKvadraturu() const { return kvadratura; }
        void Ispisi() const;
};

class Prodaja
{
    string ime_agenta_prodaje;
    double cijena_stana;
    Datum datum_prodaje;
    Kupac kupac_stana;
    Stan kupljeni_stan;
    public:    
        Prodaja(const string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan);
        Prodaja(const string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, string &ime_kupca, const Datum &datum_rodjenja_kupca, 
            const string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata);
        void PromijeniKupca(const Kupac &novi_kupac) { kupac_stana=novi_kupac; } 
        void PromijeniStan(const Stan &novi_stan) { kupljeni_stan=novi_stan; }
        void PromijeniImeAgentaProdaje(const string &novo_ime) { ime_agenta_prodaje=novo_ime; }
        void PromijeniDatumKupovine(const Datum &novi_datum) { datum_prodaje=novi_datum; }
        void PromijeniCijenuProdaje(const double &nova_cijena) { cijena_stana=nova_cijena; }
        void PomjeriDanUnaprijed();
        void PomjeriDanUnazad();
        string DajImeAgenta() const { return ime_agenta_prodaje; }
        string DajImeKupca() const { return kupac_stana.DajImePrezime(); }
        Datum DajDatumProdaje() const { return datum_prodaje; }
        double DajCijenuStana() const { return cijena_stana; }
        friend bool ProdatPrije(const Prodaja &p1, const Prodaja &p2);
        friend bool SkupljiStan(const Prodaja &p1, const Prodaja &p2);
        void Ispisi() const;
};

class Prodaje
{
    const int max_broj_prodaja;
    int broj_prodaja;
    Prodaja** prodaje;
    
    public:
        explicit Prodaje(int max_broj_prodaja) : max_broj_prodaja(max_broj_prodaja), broj_prodaja(0), prodaje(new Prodaja*[max_broj_prodaja]) {}
        Prodaje(initializer_list<Prodaja> spisak_prodaja);
        ~Prodaje();
        Prodaje(const Prodaje &prodaje);
        Prodaje(Prodaje &&prodaje);
        Prodaje &operator =(const Prodaje &prodaje);
        Prodaje &operator =(Prodaje &&prodaje);
        void RegistrirajProdaju(const string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan);
        void RegistrirajProdaju(const string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, string &ime_kupca, 
            const Datum &datum_rodjenja_kupca, const string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata);
        void RegistrirajProdaju(Prodaja *prodaja);
        int DajBrojProdaja() const { return broj_prodaja; }
        int DajBrojProdajaNaDatum(const Datum &datum) const;
        int DajBrojProdajaOdAgenta(const string &ime_agenta) const;
        Prodaja &DajProdaju(int indeks);
        Prodaja &DajNajranijuProdaju();
        Prodaja DajNajranijuProdaju() const;
        Prodaja &DajNajskupljuProdaju();
        Prodaja DajNajskupljuProdaju() const;
        void IsprazniKolekciju();
        void ObrisiNajranijuProdaju();
        void ObrisiProdajeAgenta(const string &ime_agenta);
        void ObrisiProdajeNaDatum(const Datum &datum);
        void IspisiProdajeNaDatum(const Datum &datum) const;
        void IspisiSveProdaje() const;
};

void Datum::Postavi(int dan, int mjesec, int godina)
{
    int broj_dana[12]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if((godina % 4 == 0 && godina % 100 != 0) || godina % 400 == 0) broj_dana[1]++;
    if(godina < 1 || dan < 1 || mjesec < 1 || mjesec > 12 || dan > broj_dana[mjesec - 1]) throw std::domain_error("Neispravan datum");
    Datum::dan = dan; Datum::mjesec = mjesec; Datum::godina = godina;
}

void Kupac::Postavi(const string &ime_i_prezime, const Datum &datum_rodjenja)
{
    for(int i=0; i<ime_i_prezime.length(); i++)
    {
        if(!((ime_i_prezime[i]>='A' && ime_i_prezime[i]<='Z') || (ime_i_prezime[i]>='a' && ime_i_prezime[i]<='z') || (ime_i_prezime[i]>='0' && ime_i_prezime[i]<='9') || ime_i_prezime[i]=='-' || ime_i_prezime[i]==' ' || ime_i_prezime[i]=='\''))
            throw std::domain_error("Neispravno ime i prezime");
    }
    Kupac::datum_rodjenja=datum_rodjenja;
    Kupac::ime_i_prezime=ime_i_prezime;
}

void Stan::Postavi(const string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura)
{
    if(sprat<0 || broj_soba<0 || kvadratura<0) throw std::domain_error("Neispravan unos podataka");
    Stan::adresa=adresa; Stan::sprat=sprat; Stan::broj_soba=broj_soba; Stan::namjesten=namjesten; Stan::kvadratura=kvadratura;
}

void Stan::Ispisi() const
{
    if(broj_soba==1 || broj_soba>=5) cout << "Stan se nalazi na adresi " << DajAdresu() << " na " << DajSprat() << ". spratu i ima " << DajBrojSoba() << " soba.";
    else if(broj_soba>=2 && broj_soba<=4) cout << "Stan se nalazi na adresi " << DajAdresu() << " na " << DajSprat() << ". spratu i ima " << DajBrojSoba() << " sobe.";
    if(namjesten) cout << " Kvadratura stana je " << kvadratura << " (m^2) i stan je namjesten." << endl;
    else cout << " Kvadratura stana je " << kvadratura << " (m^2) i stan nije namjesten." << endl;
}

Prodaja::Prodaja(const string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan) : datum_prodaje(datum_prodaje), kupac_stana(kupac_stana), kupljeni_stan(kupljeni_stan)
{ Prodaja::ime_agenta_prodaje=ime_agenta_prodaje; Prodaja::cijena_stana=cijena_stana; }

Prodaja::Prodaja(const string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, string &ime_kupca, const Datum &datum_rodjenja_kupca, 
            const string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata) :datum_prodaje(dan_prodaje, mjesec_prodaje, godina_prodaje), kupac_stana(ime_kupca, datum_rodjenja_kupca), kupljeni_stan(adresa_stana, sprat_stana, broj_soba, namjesten_stan, broj_kvadrata)
{ Prodaja::ime_agenta_prodaje=ime_agenta_prodaje; Prodaja::cijena_stana=cijena_stana; }            

void Prodaja::PomjeriDanUnaprijed()
{
    int broj_dana[12]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if((datum_prodaje.DajGodinu() % 4 == 0 && datum_prodaje.DajGodinu() % 100 != 0) || datum_prodaje.DajGodinu() % 400 == 0) broj_dana[1]++;
    
    datum_prodaje.dan++;
    
    if(datum_prodaje.dan>broj_dana[datum_prodaje.mjesec-1])
    {
        datum_prodaje.dan=1;
        datum_prodaje.mjesec++;
    }
    if(datum_prodaje.mjesec>12)
    {
        datum_prodaje.mjesec=1;
        datum_prodaje.godina++;
    }
}

void Prodaja::PomjeriDanUnazad()
{
    int broj_dana[12]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if((datum_prodaje.godina % 4 == 0 && datum_prodaje.godina % 100 != 0) || datum_prodaje.godina % 400 == 0) broj_dana[1]++;
    
    datum_prodaje.dan--;
    
    if(datum_prodaje.dan<1)
    {
        datum_prodaje.mjesec--;
        if(datum_prodaje.mjesec<1) datum_prodaje.mjesec=12, datum_prodaje.godina--;
        datum_prodaje.dan=broj_dana[datum_prodaje.mjesec-1];
    }
    if(datum_prodaje.mjesec<1)
    {
        datum_prodaje.mjesec=12;
        datum_prodaje.godina--;
    }
}

bool ProdatPrije(const Prodaja &p1, const Prodaja &p2)
{
    if(p1.datum_prodaje.DajGodinu()<p2.datum_prodaje.DajGodinu()) return true;
    else if(p1.datum_prodaje.DajGodinu()==p2.datum_prodaje.DajGodinu() && p1.datum_prodaje.DajMjesec()<p2.datum_prodaje.DajMjesec()) return true;
    else if(p1.datum_prodaje.DajGodinu()==p2.datum_prodaje.DajGodinu() && p1.datum_prodaje.DajMjesec()==p2.datum_prodaje.DajMjesec() && p1.datum_prodaje.DajDan()<p2.datum_prodaje.DajDan()) return true;
    
    return false;
}

bool SkupljiStan(const Prodaja &p1, const Prodaja &p2)
{
    if(p1.cijena_stana>p2.cijena_stana) return true;
    return false;
}

void Prodaja::Ispisi() const
{
    cout << "Ime agenta:                     " << DajImeAgenta() << endl;
    cout << "Ime kupca:                      "; kupac_stana.Ispisi();
    cout << "Zakazani datum prodaje:         "; datum_prodaje.Ispisi(); cout << endl;
    cout << "Cijena stana:                   " << DajCijenuStana() << endl;
    cout << "Informacije o stanu:            " << endl; kupljeni_stan.Ispisi();
}

Prodaje::Prodaje(initializer_list<Prodaja> spisak_prodaja) : max_broj_prodaja(spisak_prodaja.size()), broj_prodaja(spisak_prodaja.size()), prodaje(new Prodaja*[spisak_prodaja.size()])
{
    int brojac(0);
    for(auto it=spisak_prodaja.begin(); it!=spisak_prodaja.end(); it++)
    {
        prodaje[brojac]=new Prodaja(*it);
        brojac++;
    }   
}

Prodaje::~Prodaje()
{
    for(int i=0; i<broj_prodaja; i++)
    {
        delete prodaje[i];
        prodaje[i]=nullptr;
    }
    delete[] prodaje;
    prodaje=nullptr;
}

Prodaje::Prodaje(const Prodaje &prodaje) :  max_broj_prodaja(prodaje.max_broj_prodaja), broj_prodaja(prodaje.broj_prodaja), prodaje(new Prodaja*[prodaje.max_broj_prodaja])
{
    try 
	{
		for(int i = 0; i < prodaje.broj_prodaja; i++)
			Prodaje::prodaje[i] = new Prodaja(*prodaje.prodaje[i]);
	}
	catch(...) 
	{
		for(int i = 0; i < prodaje.broj_prodaja; i++) 
		{
			delete Prodaje::prodaje[i]; 
			Prodaje::prodaje[i] = nullptr;
		}
		delete[] Prodaje::prodaje;
		throw;
	}
}

Prodaje &Prodaje::operator =(const Prodaje &prodaje)
{
	if(max_broj_prodaja!=prodaje.max_broj_prodaja) throw std::range_error("Kapaciteti nisu isti");
	if(prodaje.broj_prodaja>broj_prodaja)
	{
		try 
		{
			for(int i=broj_prodaja; i<prodaje.broj_prodaja; i++)
				Prodaje::prodaje[i] = new Prodaja(*prodaje.Prodaje::prodaje[i]);
		}
		catch(...) 
		{
			for(int i=broj_prodaja; i<prodaje.broj_prodaja; i++) 
			{
				delete Prodaje::prodaje[i]; 
				Prodaje::prodaje[i] = nullptr;
			}
			throw;
		}
	}
	else 
	{
		for(int i=prodaje.broj_prodaja; i<broj_prodaja; i++) 
		{
			delete Prodaje::prodaje[i]; 
			Prodaje::prodaje[i] = nullptr; 
		}
	}
	broj_prodaja=prodaje.broj_prodaja;
	for(int i=0; i<broj_prodaja; i++) 
		*Prodaje::prodaje[i] = *prodaje.Prodaje::prodaje[i];
		
	return *this;
}

Prodaje &Prodaje::operator =(Prodaje &&prodaje) 
{
    if(prodaje.max_broj_prodaja != max_broj_prodaja) throw std::range_error("Kapaciteti nisu isti");
    swap(broj_prodaja, prodaje.broj_prodaja);
    swap(Prodaje::prodaje, prodaje.Prodaje::prodaje);
    return *this;
}

Prodaje::Prodaje(Prodaje &&prodaje) : max_broj_prodaja(prodaje.max_broj_prodaja), broj_prodaja(prodaje.broj_prodaja), prodaje(prodaje.Prodaje::prodaje)
{   prodaje.Prodaje::prodaje = nullptr; prodaje.broj_prodaja = 0; }


void Prodaje::RegistrirajProdaju(const string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan)
{
    if(broj_prodaja>=max_broj_prodaja) throw std::range_error("Dostignut maksimalni broj prodaja");
    try
    {
        prodaje[broj_prodaja++]=new Prodaja(Prodaja(ime_agenta_prodaje, cijena_stana, datum_prodaje, kupac_stana, kupljeni_stan));
    }
    catch(...)
    {
        cout << "Nedovoljno memorije" << endl;
    }
}

void Prodaje::RegistrirajProdaju(const string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, string &ime_kupca, const Datum &datum_rodjenja_kupca, const string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata)
{
    if(broj_prodaja>=max_broj_prodaja) throw std::range_error("Dostignut maksimalni broj prodaja");
    try
    {
        prodaje[broj_prodaja++]=new Prodaja(Prodaja(ime_agenta_prodaje, cijena_stana, Datum(dan_prodaje, mjesec_prodaje, godina_prodaje), Kupac(ime_kupca, datum_rodjenja_kupca), Stan(adresa_stana, sprat_stana, broj_soba, namjesten_stan, broj_kvadrata)));
    }
    catch(...)
    {
        cout << "Nedovoljno memorije" << endl;
    }
}

void Prodaje::RegistrirajProdaju(Prodaja *prodaja)
{
    if(broj_prodaja>=max_broj_prodaja) throw std::range_error("Dostignut maksimalni broj prodaja");
    try
    {
        prodaje[broj_prodaja++]=new Prodaja(*prodaja);
    }
    catch(...)
    {
        cout << "Nedovoljno memorije" << endl;
    }
}

int Prodaje::DajBrojProdajaNaDatum(const Datum &datum) const
{
    return count_if(prodaje, prodaje+broj_prodaja, [datum](Prodaja* p) {  if(p->DajDatumProdaje().DajDan()==datum.DajDan() && p->DajDatumProdaje().DajMjesec()==datum.DajMjesec() && p->DajDatumProdaje().DajGodinu()==datum.DajGodinu()) return true; return false; });
}

int Prodaje::DajBrojProdajaOdAgenta(const string &ime_agenta) const
{
    return count_if(prodaje, prodaje+broj_prodaja, [ime_agenta](Prodaja* p) {  if(ime_agenta==p->DajImeAgenta()) return true; return false; });
}

Prodaja &Prodaje::DajProdaju(int redni_broj)
{
    if(redni_broj<=0 || redni_broj>broj_prodaja) throw std::range_error("Ne postoji prodaja pod tim rednim brojem!");
    return *prodaje[redni_broj-1];
}

Prodaja &Prodaje::DajNajranijuProdaju()
{
    return **min_element(prodaje, prodaje+broj_prodaja, [](Prodaja* p1, Prodaja* p2) { if(ProdatPrije(*p1, *p2)) return true;  return false;});
}

Prodaja Prodaje::DajNajranijuProdaju() const
{
    return **min_element(prodaje, prodaje+broj_prodaja, [](Prodaja* p1, Prodaja* p2) { if(ProdatPrije(*p1, *p2)) return true;  return false;});
}

Prodaja &Prodaje::DajNajskupljuProdaju()
{
    return **max_element(prodaje, prodaje+broj_prodaja, [](Prodaja* p1, Prodaja* p2) { if(SkupljiStan(*p2, *p1)) return true;  return false;});
}

Prodaja Prodaje::DajNajskupljuProdaju() const
{
    return **max_element(prodaje, prodaje+broj_prodaja, [](Prodaja* p1, Prodaja* p2) { if(SkupljiStan(*p2, *p1)) return true;  return false;});
}

void Prodaje::IsprazniKolekciju()
{
    for(int i=0; i<broj_prodaja; i++)
    {
        delete prodaje[i];
        prodaje[i]=nullptr;
    }
    broj_prodaja=0;
}

void Prodaje::ObrisiNajranijuProdaju()
{
    if(broj_prodaja==0) throw std::range_error("Prazna kolekcija");
   
    auto pok(min_element(prodaje, prodaje+broj_prodaja, [](Prodaja* p1, Prodaja* p2) { if(ProdatPrije(*p1, *p2)) return true;  return false;}));
    delete *pok;
    *pok=nullptr;
    broj_prodaja--;
}

void Prodaje::ObrisiProdajeAgenta(const string &ime_agenta)
{
    for(int i=0; i<broj_prodaja; i++)
    {
        if(prodaje[i]->DajImeAgenta()==ime_agenta)
        {
            delete prodaje[i];
            prodaje[i]=nullptr;
            for(int j=i; j<broj_prodaja-1; j++)
                prodaje[j]=prodaje[j+1];
            
            prodaje[broj_prodaja-1]=nullptr;
            broj_prodaja--;
            i--;
        }
    }
}

void Prodaje::ObrisiProdajeNaDatum(const Datum &datum)
{
    for(int i=0; i<broj_prodaja; i++)
    {
        if(prodaje[i]->DajDatumProdaje().DajDan()==datum.DajDan() && prodaje[i]->DajDatumProdaje().DajMjesec()==datum.DajMjesec() && prodaje[i]->DajDatumProdaje().DajGodinu()==datum.DajGodinu())
        {
            delete prodaje[i];
            prodaje[i]=nullptr;
            for(int j=i; j<broj_prodaja-1; j++)
                prodaje[j]=prodaje[j+1];
            
            prodaje[broj_prodaja-1]=nullptr;
            broj_prodaja--;
            i--;
        }
    }
}

void Prodaje::IspisiProdajeNaDatum(const Datum &datum) const
{
    Prodaje pom(max_broj_prodaja);
    int brojac(0);
    for(int i=0; i<broj_prodaja; i++)
    {
        if(prodaje[i]->DajDatumProdaje().DajDan()==datum.DajDan() && prodaje[i]->DajDatumProdaje().DajMjesec()==datum.DajMjesec() && prodaje[i]->DajDatumProdaje().DajGodinu()==datum.DajGodinu())
        {
            pom.prodaje[brojac++]=new Prodaja(*prodaje[i]);
        }
    }
    sort(pom.prodaje, pom.prodaje+brojac, [] (Prodaja* p1, Prodaja *p2) { if(p1->DajImeKupca() < p2->DajImeKupca()) return true; return false; });
    for(int i=0; i<brojac; i++)
        pom.prodaje[i]->Ispisi();
}

void Prodaje::IspisiSveProdaje() const
{
    Prodaje pom(max_broj_prodaja);
    int brojac(0);
    for(int i=0; i<broj_prodaja; i++)
        pom.prodaje[brojac++]=new Prodaja(*prodaje[i]);
        
    sort(pom.prodaje, pom.prodaje+brojac, [] (Prodaja* p1, Prodaja *p2) 
    { 
        if(p1->DajDatumProdaje().DajGodinu()<p2->DajDatumProdaje().DajGodinu()) return true;
        else if(p1->DajDatumProdaje().DajGodinu()==p2->DajDatumProdaje().DajGodinu() && p1->DajDatumProdaje().DajMjesec()<p2->DajDatumProdaje().DajMjesec()) return true;
        else if(p1->DajDatumProdaje().DajGodinu()==p2->DajDatumProdaje().DajGodinu() && p1->DajDatumProdaje().DajMjesec()==p2->DajDatumProdaje().DajMjesec() && p1->DajDatumProdaje().DajDan()<p2->DajDatumProdaje().DajDan()) return true;
        else if(p1->DajDatumProdaje().DajGodinu()==p2->DajDatumProdaje().DajGodinu() && p1->DajDatumProdaje().DajMjesec()==p2->DajDatumProdaje().DajMjesec() && p1->DajDatumProdaje().DajDan()==p2->DajDatumProdaje().DajDan() && p1->DajImeKupca()<p2->DajImeKupca()) return true;
        
        return false;
    });
    
    pom.broj_prodaja=brojac;
    
    for(int i=0; i<brojac; i++)
    {
        pom.prodaje[i]->Ispisi();
        cout << endl;
    }
}

int main()
{
	vector<Stan> stanovi;
	vector<Kupac> kupci;
	Prodaje prod(20);
	
	cout << "Dobrodosli!";
	cout << endl;
	cout << endl;
	
	while(1)
	{
        int opcija;
        cout << endl << "Izaberite opciju:" << endl;
        cout << " 0 - kraj" << endl << " 1 - uredjivanje stanova" << endl << " 2 - uredjivanje kupaca" << endl << " 3 - uredjivanje prodaja" << endl;
        cin >> opcija;
        
        if(opcija==1)
        {
            while(1)
            {
                int opcija1;
                cout << "Izaberite opciju:" << endl;
                cout << " 0 - nazad" << endl << " 1 - dodavanje stana" << endl << " 2 - uredjivanje stanova" << endl << " 3 - ispis svih stanova" << endl << " 4 - kraj" << endl;
                cin >> opcija1;
                if(opcija1==0) break;
                else if(opcija1==1)
                {
                    if(!cin) cin.clear();
                    cin.ignore(1000, '\n');
                    ponovo:
                    try
                    {
                        string adresa;
                        int broj_soba, sprat, namjesten;
                        double kvadratura;
                        bool namjesten_stan;
                        
                        cout << "Unesite adresu: ";
                        getline(cin, adresa);
                        cout << "Unesite sprat: ";
                        cin >> sprat;
                        cout << "Unesite broj soba: ";
                        cin >> broj_soba;
                        cout << "Da li je stan namjesten (1 - da, 0 - ne): ";
                        cin >> namjesten;
                        cout << "Unesite kvadraturu: ";
                        cin >> kvadratura;
                        if(namjesten==1) namjesten_stan=true;
                        else if(namjesten==0) namjesten_stan=false;
                        else throw std::domain_error("Neispravan unos podataka");
                        
                        Stan s(adresa, sprat, broj_soba, namjesten_stan, kvadratura);
                        stanovi.push_back(s);
                        cout << "Stan je uspjesno dodan!\n" << endl;
                        if(!cin) cin.clear();
                        cin.ignore(1000, '\n');
                    }
                    catch(std::domain_error izuzetak)
                    {
                        cout << "Izuzetak: " << izuzetak.what() << ". Molimo unesite opet." << endl;
                        if(!cin) cin.clear();
                        cin.ignore(1000, '\n');
                        goto ponovo;
                    }
                }
                else if(opcija1==2)
                {
                    cout << "Odaberite stan. Dostupni stanovi su:" << endl;
                    if(stanovi.size()==0) break;
                    for(int i=0; i<stanovi.size(); i++)
                    {
                        cout << " " << i+1 << " - ";
                        stanovi[i].Ispisi();
                    }
                    cout << endl;
                    int broj_stana;
                    cin >> broj_stana;
                    while(1)
                    {
                        cout << "Odaberite polje koje zelite urediti:" << endl << " 0 - nazad" << endl << " 1 - adresa" << endl << " 2 - sprat" << endl << " 3 - broj soba" << endl << " 4 - da li je stan namjesten" << endl << " 5 - kvadratura" << endl << " 6 - sve" << endl;
                        int opcija_1_2;
                        cin >> opcija_1_2;
                        ponovo1:
                        try
                        {
                            string adresa;
                            int broj_soba, sprat, namjesten;
                            double kvadratura;
                            bool namjesten_stan;
                            if(opcija_1_2==0) break;
                            else if(opcija_1_2==1)
                            {
                                if(!cin) cin.clear();
                                cin.ignore(1000, '\n');
                                cout << "Unesite adresu: ";
                                getline(cin, adresa);
                                stanovi[broj_stana-1].Postavi(adresa, stanovi[broj_stana-1].DajSprat(), stanovi[broj_stana-1].DajBrojSoba(), stanovi[broj_stana-1].DajNamjesten(), stanovi[broj_stana-1].DajKvadraturu());
                            }
                            else if(opcija_1_2==2)
                            {
                                cout << "Unesite sprat: ";
                                cin >> sprat;
                                stanovi[broj_stana-1].Postavi(stanovi[broj_stana-1].DajAdresu(), sprat, stanovi[broj_stana-1].DajBrojSoba(), stanovi[broj_stana-1].DajNamjesten(), stanovi[broj_stana-1].DajKvadraturu());
                            }
                            else if(opcija_1_2==3)
                            {
                                cout << "Unesite broj soba: ";
                                cin >> broj_soba;
                                stanovi[broj_stana-1].Postavi(stanovi[broj_stana-1].DajAdresu(), stanovi[broj_stana-1].DajSprat(), broj_soba, stanovi[broj_stana-1].DajNamjesten(), stanovi[broj_stana-1].DajKvadraturu());
                            }
                            else if(opcija_1_2==4)
                            {
                                cout << "Da li je stan namjesten (1 - da, 0 - ne): ";
                                cin >> namjesten;
                                if(namjesten==1) namjesten_stan=true;
                                else if(namjesten==0) namjesten_stan=false;
                                else throw std::domain_error("Neispravan unos podataka.");
                                stanovi[broj_stana-1].Postavi(stanovi[broj_stana-1].DajAdresu(), stanovi[broj_stana-1].DajSprat(), stanovi[broj_stana-1].DajBrojSoba(), namjesten_stan, stanovi[broj_stana-1].DajKvadraturu());
                            }
                            else if(opcija_1_2==5)
                            {
                                cout << "Unesite kvadraturu: ";
                                cin >> kvadratura;
                                stanovi[broj_stana-1].Postavi(stanovi[broj_stana-1].DajAdresu(), stanovi[broj_stana-1].DajSprat(), stanovi[broj_stana-1].DajBrojSoba(), stanovi[broj_stana-1].DajNamjesten(), kvadratura);
                            }
                            else if(opcija_1_2==6)
                            {
                                if(!cin) cin.clear();
                                cin.ignore(1000, '\n');
                                cout << "Unesite adresu: ";
                                getline(cin, adresa);
                                cout << "Unesite sprat: ";
                                cin >> sprat;
                                cout << "Unesite broj soba: ";
                                cin >> broj_soba;
                                cout << "Da li je stan namjesten (1 - da, 0 - ne): ";
                                cin >> namjesten;
                                cout << "Unesite kvadraturu: ";
                                cin >> kvadratura;
                                if(namjesten==1) namjesten_stan=true;
                                else if(namjesten==0) namjesten_stan=false;
                                else throw std::domain_error("Neispravan unos podataka.");
                                stanovi[broj_stana-1].Postavi(adresa, sprat, broj_soba, namjesten_stan, kvadratura);
                            }
                            cout << "Stan je uspjesno izmijenjen!" << endl << endl;
                            if(!cin) cin.clear();
                            cin.ignore(1000, '\n');
                            break;
                        }
                        catch(std::domain_error izuzetak)
                        {
                            cout << "Izuzetak: " << izuzetak.what() << ". Molimo unesite opet." << endl;
                            if(!cin) cin.clear();
                            cin.ignore(1000, '\n');
                            goto ponovo1;
                        }
                    }
                }
                else if(opcija1==3)
                {
                    for(int i=0; i<stanovi.size(); i++)
                    {
                        cout << i+1 << ". ";
                        stanovi[i].Ispisi();
                    }
                    
                    cout << endl;
                }
                else if(opcija1==4) { cout << endl << endl << "Dovidjenja!"; return 0; };
            }
        }
        else if(opcija==2)
        {
            while(1)
            {
                int opcija2;
                cout << "Izaberite opciju:" << endl;
                cout << " 0 - nazad" << endl << " 1 - dodavanje kupca" << endl << " 2 - uredjivanje kupaca" << endl << " 3 - ispis svih kupaca" << endl << " 4 - kraj" << endl;
                cin >> opcija2;
                if(opcija2==0) break;
                else if(opcija2==1)
                {
                    if(!cin) cin.clear();
                    cin.ignore(1000, '\n');
                    ponovo2:
                    try
                    {
                        string ime_i_prezime;
                        
                        cout << "Unesite ime i prezime kupca: ";
                        getline(cin, ime_i_prezime);
                        cout << "Unesite datum rodjenja (formata d/m/g): ";
                        char znak;
                        int dan, mjesec, godina;
                        cin >> dan >> znak >> mjesec >> znak >> godina;
                        
                        Kupac k(ime_i_prezime, Datum(dan, mjesec, godina));
                        kupci.push_back(k);
                        cout << "Kupac je uspjesno dodan!" << endl << endl;
                        if(!cin) cin.clear();
                        cin.ignore(1000, '\n');
                    }
                    catch(std::domain_error izuzetak)
                    {
                        cout << "Izuzetak: " << izuzetak.what() << ". Molimo unesite opet." << endl;
                        if(!cin) cin.clear();
                        cin.ignore(1000, '\n');
                        goto ponovo2;
                    }
                }
                else if(opcija2==2)
                {
                    cout << "Odaberite kupca kojeg zelite urediti. Dostupni kupci su: " << endl;
                    if(kupci.size()==0) break;
                    for(int i=0; i<kupci.size(); i++)
                    {
                        cout << " " << i+1 << " - ";
                        kupci[i].Ispisi();
                    }
                    int broj_kupca;
                    cin >> broj_kupca;
                    if(!cin) cin.clear();
                    cin.ignore(1000, '\n');
                    ponovo3:
                    try
                    {
                        string ime_i_prezime;
                        cout << "Unesite ime i prezime kupca: ";
                        getline(cin, ime_i_prezime);
                        cout << "Unesite datum rodjenja (formata d/m/g): ";
                        char znak;
                        int dan, mjesec, godina;
                        cin >> dan >> znak >> mjesec >> znak >> godina;
                            
                        kupci[broj_kupca-1].Postavi(ime_i_prezime, Datum(dan, mjesec, godina));
                        cout << "Kupac je uspjesno izmijenjen!" << endl << endl;
                        if(!cin) cin.clear();
                        cin.ignore(1000, '\n');
                    }
                    catch(std::domain_error izuzetak)
                    {
                        cout << "Izuzetak: " << izuzetak.what() << ". Molimo unesite opet." << endl;
                        if(!cin) cin.clear();
                        cin.ignore(1000, '\n');
                        goto ponovo3;
                    }
                }
                else if(opcija2==3)
                {
                    for(int i=0; i<kupci.size(); i++)
                        kupci[i].Ispisi();
                    cout << endl;
                }
                else if(opcija2==4) { cout << endl << endl << "Dovidjenja!"; return 0; };
            }
        }
        else if(opcija==3)
        {
            while(1)
            {
                ponovi_prodaju:
                int opcija3;
                cout << "Izaberite opciju:" << endl;
                cout << " 0 - nazad" << endl << " 1 - dodavanje prodaje" << endl << " 2 - uredjivanje prodaje" << endl << " 3 - ispis prodaja" << endl << " 4 - brisanje prodaja" << endl << " 5 - kraj" << endl;
                cin >> opcija3;
                if(opcija3==0) break;
                else if(opcija3==1)
                {
                    while(1)
                    {
                        int opcija_3_1;
                        cout << "Izaberite opciju:" << endl;
                        cout << " 0 - nazad" << endl << " 1 - dodavanje potpuno nove prodaje" << endl << " 2 - dodavanje nove prodaje na osnovu arhive" << endl << " 3 - kraj" << endl;
                        cin >> opcija_3_1;
                        if(!cin) cin.clear();
                        cin.ignore(1000, '\n');
                        if(opcija_3_1==0) break;
                        else if(opcija_3_1==1)
                        {
                            string ime_agenta_prodaje, ime_i_prezime_kupca, adresa;
                            double cijena_stana, kvadratura;
                            int sprat, broj_soba, namjesten, dan1, mjesec1, godina1, dan2, mjesec2, godina2;
                            bool namjesten_stan;
                            ponovo4:
                            try
                            {
                                cout << "Unesite ime i prezime agenta prodaje: ";
                                getline(cin, ime_agenta_prodaje);
                                cout << "Unesite datum prodaje (formata d/m/g): ";
                                char znak;
                                cin >> dan1 >> znak >> mjesec1 >> znak >> godina1;
                                
                                cout << "Unesite cijenu stana: ";
                                cin >> cijena_stana;
                                cin.ignore(1000, '\n');
                                cout << "Unesite ime kupca: ";
                                getline(cin, ime_i_prezime_kupca);
                                
                                cout << "Unesite datum rodjenja kupca (formata d/m/g): ";
                                cin >> dan2 >> znak >> mjesec2 >> znak >> godina2;
                                
                                cin.ignore(10000, '\n');
                                cout << "Unesite adresu: ";
                                getline(cin, adresa);
                                
                                cout << "Unesite sprat: ";
                                cin >> sprat;
                                cout << "Unesite broj soba: ";
                                cin >> broj_soba;
                                cout << "Da li je stan namjesten (1 - da, 0 - ne): ";
                                cin >> namjesten;
                                cout << "Unesite kvadraturu: ";
                                cin >> kvadratura;
                                if(namjesten==1) namjesten_stan=true;
                                else if(namjesten==0) namjesten_stan=false;
                                else throw std::domain_error("Neispravan unos podataka.");
                                
                                kupci.push_back(Kupac(ime_i_prezime_kupca, Datum(dan2, mjesec2, godina2)));
                                stanovi.push_back(Stan(adresa, sprat, broj_soba, namjesten_stan, kvadratura));
                                prod.RegistrirajProdaju(ime_agenta_prodaje, cijena_stana, Datum(dan1, mjesec1, godina1), kupci[kupci.size()-1], stanovi[stanovi.size()-1]);
                                
                                cout << "Prodaja uspjesno dodana!" << endl;
                                if(!cin) cin.clear();
                                cin.ignore(1000, '\n');
                                
                            }
                            catch(std::domain_error izuzetak)
                            {
                                cout << "Izuzetak: " << izuzetak.what() << ". Molimo unesite opet." << endl;
                                if(!cin) cin.clear();
                                cin.ignore(1000, '\n');
                                goto ponovo4;
                            }
                        }
                        else if(opcija_3_1==2)
                        {
                            string ime_agenta_prodaje;
                            double cijena_stana;
                            int dan1, mjesec1, godina1;
                                
                            cout << "Unesite ime i prezime agenta prodaje: ";
                            getline(cin, ime_agenta_prodaje);
                            cout << "Unesite datum prodaje (formata d/m/g): ";
                            char znak;
                            cin >> dan1 >> znak >> mjesec1 >> znak >> godina1;
                                
                            cout << "Unesite cijenu stana: ";
                            cin >> cijena_stana;
                            cin.ignore(1000, '\n');
                                
                            cout << "Odaberite kupca. Dostupni kupci su:" << endl;
                            for(int i=0; i<kupci.size(); i++)
                            {
                                cout << " " << i+1 << " - ";
                                kupci[i].Ispisi();
                            }
                                
                            int broj_kupca;
                            cin >> broj_kupca;
                                 
                            cout << "Odaberite stan. Dostupni stanovi su:" << endl;
                            for(int i=0; i<stanovi.size(); i++)
                            {
                                cout << " " << i+1 << " - ";
                                stanovi[i].Ispisi();
                            }
                                
                            int broj_stana;
                            cin >> broj_stana;
                                
                            prod.RegistrirajProdaju(ime_agenta_prodaje, cijena_stana, Datum(dan1, mjesec1, godina1), kupci[broj_kupca-1], stanovi[broj_stana-1]);
                                
                            cout << "Prodaja uspjesno dodana!" << endl;
                            if(!cin) cin.clear();
                            cin.ignore(1000, '\n');
                        }
                        else if(opcija_3_1==3) { cout << endl << endl << "Dovidjenja!"; return 0; };
                    }
                }
                else if(opcija3==2)
                {
                    cout << "Odaberite prodaju koju želite urediti. Dostupne prodaje su:" << endl;
                    for(int i=0; i<prod.DajBrojProdaja(); i++)
                    {
                        cout << i+1 << "." << endl;
                        prod.DajProdaju(i+1).Ispisi();
                        cout << endl;
                    }
                    
                    int broj_prodaje;
                    cin >> broj_prodaje;
                    if(!cin) cin.clear();
                    cin.ignore(1000, '\n');
                    while(1)
                    {
                        int opcija_3_2;
                        cout << endl << "Izaberite opciju:" << endl;
                        cout << " 0 - nazad" << endl << " 1 - izmjena agenta" << endl << " 2 - izmjena datuma prodaje" << endl << " 3 - izmjena kupca" << endl << " 4 - izmjena stana" << endl << " 5 - izmjena cijene stana" << endl;
                        cin >> opcija_3_2;
                        if(!cin) cin.clear();
                        cin.ignore(1000, '\n');
                        if(opcija_3_2==0) break;
                        else if(opcija_3_2==1)
                        {
                            string ime_i_prezime;
                            cout << "Unesite ime i prezime agenta prodaje: ";
                            getline(cin, ime_i_prezime);
                            prod.DajProdaju(broj_prodaje).PromijeniImeAgentaProdaje(ime_i_prezime);
                            cout << "Prodaja je uspjesno izmijenjena!" << endl;
                            goto ponovi_prodaju;
                        }
                        else if(opcija_3_2==2)
                        {
                            int dan1, mjesec1, godina1;
                            
                            cout << "Unesite datum prodaje (formata d/m/g): ";
                            char znak;
                            cin >> dan1 >> znak >> mjesec1 >> znak >> godina1;
                            
                            prod.DajProdaju(broj_prodaje).PromijeniDatumKupovine(Datum(dan1, mjesec1, godina1));
                            cout << "Prodaja je uspjesno izmijenjena!" << endl;
                            goto ponovi_prodaju;
                        }
                        else if(opcija_3_2==3)
                        {
                            while(1)
                            {
                                int opcija_3_2_3;
                                cout << endl << "Izaberite opciju:" << endl;
                                cout << " 0 - nazad" << endl << " 1 - odabir postojeceg kupca" << endl << " 2 - dodavanje novog kupca" << endl;
                                cin >> opcija_3_2_3;
                                if(!cin) cin.clear();
                                cin.ignore(1000, '\n');
                                if(opcija_3_2_3==0) break;
                                else if(opcija_3_2_3==1)
                                {
                                    cout << "Odaberite kupca. Dostupni kupci su: " << endl;
                                    for(int i=0; i<kupci.size(); i++)
                                    {
                                        cout << " " << i+1 << " - ";
                                        kupci[i].Ispisi();
                                    }
                                    int broj_kupca;
                                    cin >> broj_kupca;
                                    prod.DajProdaju(broj_prodaje).PromijeniKupca(kupci[broj_kupca-1]);
                                    cout << "Prodaja je uspjesno izmijenjena!" << endl;
                                }
                                else if(opcija_3_2_3==2)
                                {
                                    string ime_i_prezime;
                                    char znak1;
                                    int dan3, mjesec3, godina3;
                                    if(!cin) cin.clear();
                                    cin.ignore(1000, '\n');
                                    ponovo6:
                                    try
                                    {
                                        cout << "Unesite ime i prezime kupca: ";
                                        getline(cin, ime_i_prezime);
                                        cout << "Unesite datum rodjenja (formata d/m/g): ";
                                        
                                        cin >> dan3 >> znak1 >> mjesec3 >> znak1 >> godina3;
                                      
                                        kupci.push_back(Kupac(ime_i_prezime, Datum(dan3, mjesec3, godina3)));
                                        prod.DajProdaju(broj_prodaje).PromijeniKupca(kupci[kupci.size()-1]);
                                        cout << "Prodaja je uspjesno izmijenjena!" << endl;
                                        if(!cin) cin.clear();
                                        cin.ignore(1000, '\n');
                                    }
                                    catch(std::domain_error izuzetak)
                                    {
                                        cout << "Izuzetak: " << izuzetak.what() << ". Molimo unesite opet." << endl;
                                        if(!cin) cin.clear();
                                        cin.ignore(1000, '\n');
                                        goto ponovo6;
                                    }
                                }
                            }
                        }
                        else if(opcija_3_2==4)
                        {
                            while(1)
                            {
                                int opcija_3_2_4;
                                cout << "Izaberite opciju:" << endl;
                                cout << " 0 - nazad" << endl << " 1 - odabir postojeceg stana" << endl << " 2 - dodavanje novog stana" << endl;
                                cin >> opcija_3_2_4;
                                if(!cin) cin.clear();
                                cin.ignore(1000, '\n');
                                if(opcija_3_2_4==0) break;
                                else if(opcija_3_2_4==1)
                                {
                                    cout << "Odaberite stan. Dostupni stanovi su: " << endl;
                                    for(int i=0; i<stanovi.size(); i++)
                                    {
                                        cout << " " << i+1 << " - ";
                                        stanovi[i].Ispisi();
                                    }
                                    
                                    int broj_stana;
                                    cin >> broj_stana;
                                    prod.DajProdaju(broj_prodaje).PromijeniStan(stanovi[broj_stana-1]);
                                    cout << "Prodaja je uspjesno izmijenjena!" << endl;
                                }
                                else if(opcija_3_2_4==2)
                                {
                                    if(!cin) cin.clear();
                                    cin.ignore(1000, '\n');
                                    string adresa;
                                    double kvadratura;
                                    int sprat, broj_soba, namjesten;;
                                    bool namjesten_stan;
                                    ponovo8:
                                    try
                                    {
                                        cin.ignore(10000, '\n');
                                        cout << "Unesite adresu: ";
                                        getline(cin, adresa);
                                        
                                        cout << "Unesite sprat: ";
                                        cin >> sprat;
                                        cout << "Unesite broj soba: ";
                                        cin >> broj_soba;
                                        cout << "Da li je stan namjesten (1 - da, 0 - ne): ";
                                        cin >> namjesten;
                                        cout << "Unesite kvadraturu: ";
                                        cin >> kvadratura;
                                        if(namjesten==1) namjesten_stan=true;
                                        else if(namjesten==0) namjesten_stan=false;
                                        else throw std::domain_error("Neispravan unos podataka.");
                                        
                                        stanovi.push_back(Stan(adresa, sprat, broj_soba, namjesten_stan, kvadratura));
                                        prod.DajProdaju(broj_prodaje).PromijeniStan(stanovi[stanovi.size()-1]);
                                        cout << "Prodaja je uspjesno izmijenjena!" << endl;
                                        if(!cin) cin.clear();
                                        cin.ignore(1000, '\n');
                                    }
                                    catch(std::domain_error izuzetak)
                                    {
                                        cout << "Izuzetak: " << izuzetak.what() << ". Molimo unesite opet." << endl;
                                        if(!cin) cin.clear();
                                        cin.ignore(1000, '\n');
                                        goto ponovo8;
                                    }
                                }
                            }
                        }
                        else if(opcija_3_2==5)
                        {
                            double cijena_stana;
                            cout << "Unesite cijenu stana: ";
                            cin >> cijena_stana;
                            prod.DajProdaju(broj_prodaje).PromijeniCijenuProdaje(cijena_stana);
                            cout << "Prodaja je uspjesno izmijenjena!" << endl;
                        }
                    }
                }
                else if(opcija3==3)
                {
                    while(1)
                    {
                        int opcija_3_3;
                        cout << "Izaberite opciju:" << endl;
                        cout << " 0 - nazad" << endl << " 1 - ispis svih prodaja" << endl << " 2 - ispis prodaja na datum" << endl << " 3 - ispis najranije prodaje" << endl << " 4 - ispis najskuplje prodaje" << endl << " 5 - ispis broja prodaja" << endl << " 6 - ispis broja prodaja po datumu" << endl << " 7 - ispis broja prodaja po agentu" << endl << " 8 - kraj" << endl;
                        cin >> opcija_3_3;
                        if(opcija_3_3==0) break;
                        else if(opcija_3_3==1) prod.IspisiSveProdaje();
                        else if(opcija_3_3==2)
                        {
                            if(!cin) cin.clear();
                            cin.ignore(1000, '\n');
                            cout << "Unesite datum prodaje (d/m/g): ";
                            int dan1, mjesec1, godina1;
                            char znak;
                            cin >> dan1 >> znak >> mjesec1 >> znak >> godina1;
                            cout << "Prodaje na datum " << dan1 << "/" << mjesec1 << "/" << godina1 << " su:" <<endl;
                            prod.IspisiProdajeNaDatum(Datum(dan1, mjesec1, godina1));
                        }
                        else if(opcija_3_3==3) prod.DajNajranijuProdaju().Ispisi();
                        else if(opcija_3_3==4) prod.DajNajskupljuProdaju().Ispisi();
                        else if(opcija_3_3==5) cout << "Broj prodaja: " << prod.DajBrojProdaja() << endl;
                        else if(opcija_3_3==6)
                        {
                            if(!cin) cin.clear();
                            cin.ignore(1000, '\n');
                            cout << "Unesite datum prodaje (d/m/g): ";
                            int dan1, mjesec1, godina1;
                            char znak;
                            cin >> dan1 >> znak >> mjesec1 >> znak >> godina1;
                            cout << "Broj prodaja na uneseni datum: " << prod.DajBrojProdajaNaDatum(Datum(dan1, mjesec1, godina1)) << endl;
                        }
                        else if(opcija_3_3==7)
                        {
                            if(!cin) cin.clear();
                            cin.ignore(1000, '\n');
                            string ime_agenta_prodaje;
                            cout << "Unesite ime agenta: ";
                            getline(cin, ime_agenta_prodaje);
                            cout << "Broj prodaja: " << prod.DajBrojProdajaOdAgenta(ime_agenta_prodaje) << endl;
                        }
                        else if(opcija_3_3==8) { cout << endl << endl << "Dovidjenja!"; return 0; };
                    }
                }
                else if(opcija3==4)
                {
                    while(1)
                    {
                        ponovo7: 
                        try
                        {
                            int opcija_3_4;
                            cout << endl << "Izaberite opciju:" << endl;
                            cout << " 0 - nazad" << endl << " 1 - brisanje najranije prodaje" << endl << " 2 - brisanje prodaja agenta" << endl << " 3 - brisanje prodaja po datumu" << endl << " 4 - brisanje svih prodaja" << endl;
                            cin >> opcija_3_4;
                            if(opcija_3_4==0) break;
                            else if(opcija_3_4==1)
                            {
                                prod.ObrisiNajranijuProdaju();
                                cout << "Najranija prodaja je obrisana!" << endl;
                            }
                            else if(opcija_3_4==2)
                            {
                                if(!cin) cin.clear();
                                cin.ignore(1000, '\n');
                                string ime_agenta_prodaje;
                                cout << "Unesite ime agenta: ";
                                getline(cin, ime_agenta_prodaje);
                                prod.ObrisiProdajeAgenta(ime_agenta_prodaje);
                                cout << "Sve prodaje tog agenta su obrisane." << endl;
                            }
                            else if(opcija_3_4==3)
                            {
                                if(!cin) cin.clear();
                                cin.ignore(1000, '\n');
                                cout << "Unesite datum: ";
                                int dan1, mjesec1, godina1;
                                char znak;
                                cin >> dan1 >> znak >> mjesec1 >> znak >> godina1;
                                prod.ObrisiProdajeNaDatum(Datum(dan1, mjesec1, godina1));
                                cout << "Sve prodaje na taj datum su obrisane." << endl;
                            }
                            else if(opcija_3_4==4)
                            {
                                prod.IsprazniKolekciju();
                                cout << "Sve prodaje su obrisane." << endl;
                            }
                        }
                        catch(std::range_error izuzetak)
                        {
                            cout << "Izuzetak: " << izuzetak.what() << endl;
                            if(!cin) cin.clear();
                            cin.ignore(1000, '\n');
                            goto ponovo7;
                        }
                    }
                }
                else if(opcija3==5) { cout << endl << endl << "Dovidjenja!"; return 0; };
            }
        }
        else if(opcija==0) { cout << endl << endl << "Dovidjenja!"; return 0; };
	}
	
	return 0;
}
