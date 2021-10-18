/B 2016/2017, Zadaća 4, Zadatak 3
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>
#include <iomanip>
#include <initializer_list>
#include <algorithm>

using namespace std ; 

class Datum
{
    int dan, mjesec, godina ; 
    public : 
    Datum(int dan, int mjesec, int godina) { Postavi(dan,mjesec, godina) ; }
    void Postavi(int dan, int mjesec, int godina) ; 
    int DajDan() const { return dan ; }
    int DajMjesec() const { return mjesec ; }
    int DajGodinu() const { return godina ; }
    void Ispisi() const { cout << dan << "/" << mjesec << "/" << godina ; }
};

void Datum::Postavi(int dan, int mjesec, int godina)
{
    int broj_dana[] {31,28,31,30,31,30,31,31,30,31,30,31} ;
    if((godina%4 == 0 && godina%100!=0) || godina%400==0) broj_dana[1]++ ; 
    if(godina < 1  || dan < 1 || mjesec<1 || mjesec > 12 || dan > broj_dana[mjesec-1]) 
        throw domain_error("Neispravan datum!");
    this->dan = dan ; this->mjesec = mjesec ; this->godina = godina ; 
}

class Kupac
{
  string ime_prezime ; 
  Datum rodjenje ; 
  public : 
  Kupac(const std::string &ime_i_prezime, const Datum &datum_rodjenja);
  void Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja);
  std::string DajImePrezime() const { return ime_prezime ; }
  Datum DajDatumRodjenja() const { return rodjenje ; }
  void Ispisi() const { cout << ime_prezime << " (" ; rodjenje.Ispisi() ; cout << ")" ; }
};
Kupac::Kupac(const std::string &ime_i_prezime, const Datum &datum_rodjenja) 
            : rodjenje(datum_rodjenja.DajDan(), datum_rodjenja.DajMjesec(), datum_rodjenja.DajGodinu())
{
    for(char c : ime_i_prezime)
    {
        if(c!='\'' && (c<'a' || c>'z') && (c<'A' || c>'Z') && c!='-' && (c<'0' || c>'9') && c!=' ')
            throw domain_error("Neispravno ime i prezime") ; 
    }
    ime_prezime = ime_i_prezime ; 
}
void Kupac::Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja)
{
    for(char c : ime_i_prezime)
    {
        if(c!='\'' && (c<'a' || c>'z') && (c<'A' || c>'Z') && c!='-' && (c<'0' || c>'9') && c!=' ')
            throw domain_error("Neispravno ime i prezime") ;
    }
    ime_prezime = ime_i_prezime ; 
    rodjenje = datum_rodjenja ; 
}

class Stan
{
  string adresa ; 
  int sprat, broj_soba ; 
  bool namjesten ; 
  double kvadratura ; 
  public : 
  Stan(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura) { Postavi(adresa, sprat, broj_soba, namjesten, kvadratura) ;  }
  void Postavi(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura)
  {
      this->adresa = adresa ; 
      this->sprat = sprat ; 
      this->broj_soba = broj_soba ; 
      this->namjesten = namjesten ; 
      this->kvadratura = kvadratura ; 
  }
  string DajAdresu() const { return adresa ; }
  int DajSprat() const { return sprat ; }
  int DajBrojSoba() const { return broj_soba ; }
  bool DajNamjesten() const { return namjesten ; }
  bool DajKvadraturu() const { return kvadratura ; }
  void Ispisi() const ; 
};

void Stan::Ispisi() const 
{
    cout << "Stan se nalazi na adresi " << adresa << " na " << sprat << ". spratu i ima " << broj_soba << " " ; 
    string tekst ; 
    if(broj_soba%10 == 1 && broj_soba%100 !=11)
        tekst = "sobu" ; 
    else if(broj_soba%10>=2 && broj_soba%10<=4 && broj_soba%100 < 12 && broj_soba%100 > 14)
        tekst = "sobe" ; 
    else tekst = "soba" ; 
    cout << tekst << ". Kvadratura stana je " << kvadratura << " (m^2) i stan " ; 
    if(namjesten) tekst = "je namjesten." ; 
    else tekst = "nije namjesten" ; 
    cout << tekst << endl ; 
}

class Prodaja
{
  string agent ; 
  double cijena ; 
  Datum datum_prodaje ; 
  Kupac kupac ; 
  Stan stan ; 
  public : 
  Prodaja(const string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan)
        : datum_prodaje(datum_prodaje), kupac(kupac_stana), stan(kupljeni_stan)
  {
      agent = ime_agenta_prodaje ; 
      cijena = cijena_stana ; 
  }
  Prodaja(const string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, string &ime_kupca, const Datum &datum_rodjenja_kupca, const string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata)
        : datum_prodaje(dan_prodaje, mjesec_prodaje, godina_prodaje), kupac(ime_kupca, datum_rodjenja_kupca), stan(adresa_stana, sprat_stana, broj_soba, namjesten_stan, broj_kvadrata)
    {
        agent = ime_agenta_prodaje ; 
        cijena = cijena_stana ;
    }
    void PromijeniKupca(const Kupac &novi_kupac) { kupac = novi_kupac ; }
    void PromijeniStan(const Stan &novi_stan) { stan = novi_stan ; }
    void PromijniDatumKupovine(const Datum &novi_datum) { datum_prodaje = novi_datum ; }
    void PromijeniCijenuProdaje(const double &nova_cijena) { cijena = nova_cijena ; }
    void PomjeriDanUnaprijed() ;
    void PomjeriDanUnazad();
    string DajImeAgenta() const { return agent ; }
    string DajImeKupca() const { return kupac.DajImePrezime() ; }
    Datum DajDatumProdaje() const { return datum_prodaje ; }
    double DajCijenuStana() const { return cijena ; }
    bool ProdatPrije(const Prodaja &p1, const Prodaja &p2) ; 
    bool SkupljiStan(const Prodaja &p1, const Prodaja &p2) ; 
    void Ispisi() const ;
};
void Prodaja::PomjeriDanUnaprijed()
{
    int broj_dana[]{31,28,31,30,31,30,31,31,30,31,30,31};
    int godina = datum_prodaje.DajGodinu() ;
    int mjesec = datum_prodaje.DajMjesec() ; 
    int dan = datum_prodaje.DajDan() ;
    if((godina%4 ==0 && godina%100 !=0) || godina%400==0)
        broj_dana[1]++ ; 
    if(dan > broj_dana[mjesec-1]) { dan = 1 ; mjesec++ ; }
    if(mjesec>12) { mjesec = 1 ; godina++ ; }
    datum_prodaje = Datum(dan, mjesec, godina) ;
}
void Prodaja::PomjeriDanUnazad()
{
    int broj_dana[]{31,28,31,30,31,30,31,31,30,31,30,31} ; 
    int godina = datum_prodaje.DajGodinu() ; 
    int mjesec = datum_prodaje.DajMjesec() ;
    int dan = datum_prodaje.DajDan() ; 
    if((godina%4 == 0 && godina%100 !=0) || godina%400==0)
        broj_dana[1]++ ; 
    dan-- ;
    if(dan<1) { dan = broj_dana[mjesec-2] ; mjesec-- ; }
    if(mjesec <1) { mjesec = 12 ; godina -- ;  }
    datum_prodaje = Datum(dan, mjesec, godina) ; 
}

bool ProdatPrije(const Prodaja &p1, const Prodaja &p2)
{
    if(p1.DajDatumProdaje().DajGodinu() < p2.DajDatumProdaje().DajGodinu())
        return true ; 
    if(p1.DajDatumProdaje().DajMjesec() < p2.DajDatumProdaje().DajMjesec())
        return true ; 
    if(p1.DajDatumProdaje().DajDan() < p2.DajDatumProdaje().DajDan())
        return true ; 
    return false ; 
}

bool SkupljiStan(const Prodaja &p1, const Prodaja &p2)
{
    return p1.DajCijenuStana() > p2.DajCijenuStana() ; 
}
void Prodaja::Ispisi() const 
{
    cout << setw(30) << left << "Ime agenta:" ;
    cout << agent ; 
    cout << endl << setw(30) << left << "Ime kupca:" ;
    kupac.Ispisi() ; 
    cout << endl << setw(30) << left << "Zakazani datum prodaje:"  ; 
    datum_prodaje.Ispisi() ; 
    cout << endl << setw(30) << left << "Cijena stana:" ; 
    cout << cijena ; 
    cout << endl << setw(30) << left << "Informacije o stanu:" << endl ; 
    stan.Ispisi() ;
}

class Prodaje
{
  Prodaja** niz ; 
  int kapacitet ; 
  int stanje ; 
  public : 
  explicit Prodaje(int max_broj_prodaja) ; 
  Prodaje(std::initializer_list<Prodaja> spisak_prodaja) ; 
  ~Prodaje() ; 
  Prodaje(const Prodaje &prodaje) ; 
  Prodaje(Prodaje &&prodaje) ;
  Prodaje &operator = (const Prodaje &prodaje) ; 
  Prodaje &operator = (Prodaje &&prodaje) ;
  void RegistrirajProdaju(const string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan) ; 
  void RegistrirajProdaju(const string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje,int mjesec_prodaje, int godina_prodaje, string &ime_kupca, const Datum &datum_rodjenja_kupca, const string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata);
  void RegistrirajProdaju(Prodaja *prodaja) ; 
  int DajBrojProdaja() const ; 
  int DajBrojProdajaNaDatum(const Datum &datum) const ; 
  int DajBrojProdajaOdAgenta(const string &ime_agenta) const ; 
  Prodaja &DajNajranijuProdaju() ; 
  Prodaja DajNajranijuProdaju() const ; 
  Prodaja &DajNajskupljuProdaju() ; 
  Prodaja DajNajskupljuProdaju() const ; 
  void IsprazniKolekciju() ; 
  void ObrisiNajranijuProdaju() ;
  void ObrisiProdajeAgenta(const string &ime_agenta) ; 
  void ObrisiProdajeNaDatum(const Datum &datum) ;
  void IspisiProdajeNaDatum(const Datum &datum) const ; 
  void IspisiSveProdaje() const ; 
  Prodaja &DajProdaju(int broj) ;
};
Prodaje::Prodaje(int max_broj_prodaja)
{
    kapacitet = max_broj_prodaja ; 
    stanje = 0 ; 
    niz = new Prodaja*[kapacitet] ; 
}
Prodaja &Prodaje::DajProdaju(int broj)
{
    if(stanje<broj)
        throw range_error("Kapacitet je premal");
    return *niz[broj-1] ;
}
Prodaje::Prodaje(initializer_list<Prodaja> spisak_prodaja) : stanje(spisak_prodaja.size())
{
    niz = new Prodaja*[spisak_prodaja.size()] ; 
    int i = 0 ; 
    for(auto it = spisak_prodaja.begin() ; it!=spisak_prodaja.end() ; it++)
    {
           niz[i] = new Prodaja(*it) ;
           i++ ; 
    }
}
Prodaje::~Prodaje()
{
    for(int i=0 ; i<stanje ; i++)
        delete niz[i] ; 
    delete [] niz ; 
}
Prodaje::Prodaje(const Prodaje &prodaje)
{
    niz = new Prodaja*[prodaje.kapacitet] ; 
    kapacitet = prodaje.kapacitet ; 
    for(int i=0 ; i<prodaje.stanje ; i++)
        niz[i] = new Prodaja(*prodaje.niz[i]) ;
    stanje = prodaje.stanje ; 
}
Prodaje::Prodaje(Prodaje &&prodaje)
{
    stanje = prodaje.stanje ; 
    kapacitet = prodaje.kapacitet ; 
    niz = prodaje.niz ; 
    prodaje.niz = nullptr ; 
}
Prodaje &Prodaje::operator = (const Prodaje &prodaje)
{
    if(this == &prodaje) return *this ; 
    for(int i=0 ; i<stanje ; i++)
        delete niz[i] ; 
    delete []niz ;
    niz = new Prodaja*[prodaje.kapacitet] ; 
    kapacitet = prodaje.kapacitet ; 
    for(int i = 0 ; i<prodaje.stanje ; i++)
        niz[i] = new Prodaja(*prodaje.niz[i]) ; 
    stanje = prodaje.stanje ; 
    return *this ; 
}
Prodaje &Prodaje::operator =(Prodaje &&prodaje)
{
    if(this == &prodaje) return *this ; 
    for(int i=0 ; i<stanje ; i++)
        delete niz[i] ; 
    delete []niz ; 
    stanje = prodaje.stanje ; 
    kapacitet = prodaje.kapacitet ; 
    niz = prodaje.niz ; 
    prodaje.niz = nullptr ; 
    return *this ; 
}
void Prodaje::RegistrirajProdaju(const string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan)
{
    if(kapacitet == stanje)
        throw range_error("Dostignut maksimalni broj prodaja") ;
    niz[stanje] = new Prodaja(ime_agenta_prodaje, cijena_stana, datum_prodaje, kupac_stana, kupljeni_stan) ;
    stanje++ ; 
}
void Prodaje::RegistrirajProdaju(const string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, string &ime_kupca, const Datum &datum_rodjenja_kupca, const string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata)
{
    if(kapacitet == stanje)
        throw range_error("Dostignut maksimalni broj prodaja") ;
    Datum datum_prodaje = Datum(dan_prodaje, mjesec_prodaje, godina_prodaje) ; 
    Kupac kupac = Kupac(ime_kupca, datum_rodjenja_kupca) ; 
    Stan stan = Stan(adresa_stana, sprat_stana, broj_soba, namjesten_stan, broj_kvadrata);
    niz[stanje] = new Prodaja(ime_agenta_prodaje, cijena_stana, datum_prodaje, kupac, stan);
    stanje++ ;
}
void Prodaje::RegistrirajProdaju(Prodaja *prodaja)
{
    if(kapacitet == stanje)
        throw range_error("Dostignut maksimalni broj prodaja") ;
    niz[stanje] = prodaja ; 
    stanje++ ; 
}
int Prodaje::DajBrojProdaja() const 
{
    return stanje ; 
}
int Prodaje::DajBrojProdajaNaDatum(const Datum &datum) const 
{
    return count_if(niz, niz+stanje, [datum](Prodaja* i) 
            { if((*i).DajDatumProdaje().DajDan()==datum.DajDan() && (*i).DajDatumProdaje().DajMjesec()==datum.DajMjesec() && (*i).DajDatumProdaje().DajGodinu()==datum.DajGodinu()) return true ;  return false ; } ) ;
}
int Prodaje::DajBrojProdajaOdAgenta(const string &ime_agenta_prodaje) const 
{
    return count_if(niz, niz+stanje, [ime_agenta_prodaje](Prodaja* i)
            { if((*i).DajImeAgenta()==ime_agenta_prodaje) return true ;  return false ; } ) ;
}
Prodaja &Prodaje::DajNajranijuProdaju() 
{
    if(stanje==0) throw domain_error("Nema registriranih prodaja") ; 
    auto x =  min_element(niz, niz+stanje, [](Prodaja* i ,Prodaja* j)
            { return ProdatPrije((*i),(*j)) ;   }) ;
    return *(*x) ;
}
Prodaja Prodaje::DajNajranijuProdaju() const
{
    if(stanje==0) throw domain_error("Nema registriranih prodaja") ; 
    auto x = min_element(niz, niz+stanje, [](Prodaja* i, Prodaja* j)
            { return ProdatPrije((*i),(*j)) ; } ) ; 
    return *(*x) ; 
}
Prodaja &Prodaje::DajNajskupljuProdaju()
{
    if(stanje==0) throw domain_error("Nema registriranih prodaja") ; 
    auto x= max_element(niz, niz+stanje, [](Prodaja* i, Prodaja* j)
            { return SkupljiStan((*i),(*j)); } ) ; 
    return *(*x) ; 
}
Prodaja Prodaje::DajNajskupljuProdaju() const 
{
    if(stanje==0) throw domain_error("Nema registriranih prodaja") ; 
    auto x = max_element(niz,niz+stanje, [](Prodaja* i, Prodaja* j)
            { return SkupljiStan((*i),(*j)) ; }) ; 
    return *(*x) ;
}
void Prodaje::IsprazniKolekciju()
{
    for(int i = 0 ; i<stanje ; i++)
        niz[i] = nullptr ; 
    niz = nullptr ; 
    stanje = 0 ; 
    kapacitet = 0 ; 
}
void Prodaje::ObrisiNajranijuProdaju()
{
    if(stanje==0) throw range_error("Prazna kolekcija") ; 
    Prodaja najranije = DajNajranijuProdaju() ; 
    for(int i = 0 ; i<stanje ; i++)
    {
        if((*niz[i]).DajImeKupca()== najranije.DajImeKupca() && (*niz[i]).DajCijenuStana()==najranije.DajCijenuStana() && (*niz[i]).DajDatumProdaje().DajDan()==najranije.DajDatumProdaje().DajDan() && (*niz[i]).DajDatumProdaje().DajMjesec() == najranije.DajDatumProdaje().DajMjesec() && (*niz[i]).DajDatumProdaje().DajGodinu()==najranije.DajDatumProdaje().DajGodinu())
        {
            for(int j = i ; j<stanje ; j++)
                niz[j] = niz[j+1] ; 
            niz[stanje-1] = nullptr ; 
            stanje-- ; 
        }
    }
}
void Prodaje::ObrisiProdajeNaDatum(const Datum &datum)
{
    if(stanje==0) throw range_error("Prazna kolekcija");
    for(int i=0 ; i<stanje ; i++)
    {
        if((*niz[i]).DajDatumProdaje().DajDan() == datum.DajDan() && (*niz[i]).DajDatumProdaje().DajMjesec() == datum.DajMjesec() && (*niz[i]).DajDatumProdaje().DajGodinu() == datum.DajGodinu())
        {
            for(int j=i ; j<stanje ; j++)
                niz[j] = niz[j+1] ;
            niz[stanje-1] = nullptr ; 
            stanje-- ;
        }
    }
}
void Prodaje::IspisiProdajeNaDatum(const Datum &datum) const
{
    if(stanje==0) throw range_error("Prazna kolekcija");
    Prodaje priv = *this ; 
    sort(priv.niz, priv.niz+stanje, [](Prodaja* i, Prodaja* j)
    {
       return (*i).DajImeKupca() < (*j).DajImeKupca() ;
    });
    for(int i=0 ; i<stanje ; i++)
    {
        if(((*priv.niz[i]).DajDatumProdaje().DajDan()==datum.DajDan() && (*priv.niz[i]).DajDatumProdaje().DajMjesec() == datum.DajMjesec() && (*priv.niz[i]).DajDatumProdaje().DajGodinu()==datum.DajGodinu()))
            (*priv.niz[i]).Ispisi();
    }
}
void Prodaje::IspisiSveProdaje() const
{
    Prodaje priv = *this ; 
    sort(priv.niz, priv.niz+stanje, [](Prodaja* i, Prodaja*j)
    {
       if(i->DajDatumProdaje().DajDan() == j->DajDatumProdaje().DajDan() && i->DajDatumProdaje().DajMjesec() == j->DajDatumProdaje().DajMjesec() && i->DajDatumProdaje().DajGodinu() == j->DajDatumProdaje().DajGodinu())
        return (*i).DajImeKupca() < (*j).DajImeKupca() ;
       else return ProdatPrije(*i,*j) ; 
    });
    for(int i=0 ; i<stanje ; i++)
    {
        (*priv.niz[i]).Ispisi() ;
    }
}


int main ()
{
    /*string add, agent, kupac;
    int sprat, dan, mjesec, godina, dan2,mjesec2,godina2 ;
    int broj_soba ;
    bool namjesten_stan ;
    double broj_kvadrata ;
    int izbor = 0 ; 
    int opcija = 0 ; 
    vector<Prodaja> prodaje ;
    vector<Kupac> kupci ; 
    vector<Stan> stanovi ;
    cout << "Dobrodosli!" << endl << endl ;
    while(1)
    {
        cout << "Izaberite opciju:" << endl ;
        cout << "0 - kraj" << endl ;
        cout << "1 - uredjivanje stanova" << endl ; 
        cout << "2 - uredjivanje kupaca" << endl ; 
        cout << "3 - uredjivanje prodaja" << endl ;
        cin >> izbor ;
        if(!izbor) break ;
        else if(izbor == 1) 
        {
            while(1)
            {
                cout<<"Izaberite opciju:" << endl ;
                cout << " 0 - nazad" << endl ;
                cout << " 1 - dodavanje stana" << endl ;
                cout << " 2 - uredjivanje stanova" << endl ;
                cout << " 3 - ispis svih stanova" << endl ;
                cout << " 4 - kraj" << endl ; 
                cin >> opcija ;
                cin.clear(); 
                cin.ignore(10000,'\n');
                if(!opcija) break ;
                else if(opcija == 1) // pocetak stan
                {
                    bool potvrda ;
                    do
                    {
                        potvrda = false ;
                        cout << "Unesite adresu: " ;
                        getline(cin,add);
                        cout << "Unesite sprat: " ;
                        cin >> sprat ;
                        cout << "Unesite broj soba: " ;
                        cin >> broj_soba;
                        cout << "Da li je stan namjesten (1 - da, 0 - ne): " ;
                        cin >> namjesten_stan ;
                        cout << "Unesite kvadraturu: " ;
                        cin >> broj_kvadrata ;
                        try
                        {
                            Stan stan(add, sprat, broj_soba,namjesten_stan, broj_kvadrata) ;
                            stanovi.push_back(stan) ;
                            cout << "Stan je uspjesno dodan!" << endl ; 
                        }
                        catch(domain_error w)
                        {
                            cout << "Izuzetak: " << w.what() << ". Molimo unesite opet." << endl ;
                            potvrda = true ;
                        }
                    }while(potvrda==true);
                }
                else if(opcija==2)
                {
                    int stan_opcija ;
                    cout << "Odaberite stan. Dostupni stanovi su:" << endl ;
                    for(int i=0 ; i<stanovi.size() ; i++)
                    {
                        cout << i+1 << " - " ;
                        stanovi[i].Ispisi();
                    }
                    cin>>stan_opcija;
                    cout<<"Odaberite polje koje zelite urediti:" <<endl;
                    cout<<" 0 - nazad" <<endl;
                    cout<<" 1 - adresa" << endl ;
                    cout<<" 2 - sprat"<<endl;
                    cout<<" 3 - broj soba" << endl ;
                    cout<<" 4 - da li je stan namjesten" << endl ;
                    cout<<" 5 - kvadratura"<<endl;
                    cout << "6 - sve" << endl ;
                    int izbor_opet ;
                    cin>> izbor_opet;
                    if(izbor_opet==0) continue ;
                    else if(izbor_opet==1)
                    {
                        string adresa ;
                        bool ok ;
                        do
                        {
                            ok = false ;
                            cin.clear();
                            cin.ignore(10000,'\n');
                            cout << "Unesite adresu: " ;
                            getline(cin,adresa);
                            try
                            {
                                stanovi[stan_opcija-1].Postavi(adresa,sprat,broj_soba,namjesten_stan,broj_kvadrata);
                                cout << "Stan je uspjesno izmijenjen!" << endl ; 
                            }
                            catch(domain_error w)
                            {
                                cout << "Izuzetak: " << w.what() << ". Molimo unesite ponovo." ;
                                ok = true ;
                            }
                        }while(ok==true);
                    }
                    else if(izbor_opet==2)
                    {
                        int novi ; 
                        bool okk ;
                        do
                        {
                            okk = false ;
                            cout << "Unesite sprat: " ;
                            cin>>novi ;
                            try
                            {
                                stanovi[stan_opcija-1].Postavi(add,novi,broj_soba,namjesten_stan,broj_kvadrata);
                                cout << "Stan je uspjesno izmijenjen!" << endl ; 
                            }
                            catch(domain_error w)
                            {
                                cout << "Izuzetak: " << w.what() << ". Molimo unesite opet." << endl ;
                                okk = true ;
                            }
                            
                        }while(okk==true);
                    }
                    else if(izbor_opet==3)
                    {
                        int nove_sobe ; bool okok ;
                        do
                        {
                            okok = false ; 
                            cout << "Unesite broj soba: " ;
                            cin>>nove_sobe ; 
                            try
                            {
                                stanovi[stan_opcija-1].Postavi(add,sprat,nove_sobe,namjesten_stan,broj_kvadrata);
                                cout << "Stan uspjesno izmijenjen!" << endl ; 
                            }
                            catch(domain_error w)
                            {
                                cout << "Izuzetak: " << w.what() << ". Molimo unesite opet." <<endl ;
                                okok = true ; 
                            }
                            
                        }while(okok==true);
                    }
                    else if(izbor_opet==4)
                    {
                        bool namjestaj ; bool kontrola ;
                        do
                        {
                            kontrola = false ; 
                            cout << "Da li je stan namjesten (1 - da, 0 - ne): " ;
                            cin >> namjestaj;
                            try
                            {
                                stanovi[stan_opcija-1].Postavi(add,sprat, broj_soba, namjestaj, broj_kvadrata);
                                cout << "Stan uspjesno izmijenjen!" << endl ;
                            }
                            catch(domain_error w)
                            {
                                cout << "Izuzetak: " << w.what() << ". Molimo unesite opet." << endl ;
                                kontrola = true ; 
                            }
                        }while(kontrola==true);
                    }
                    else if(izbor_opet==5)
                    {
                        double kvadrati ; 
                        bool kon ; 
                        do
                        {
                            kon = false ; 
                            cout << "Unesite kvadraturu: " ; 
                            cin >> kvadrati ; 
                            try
                            {
                                stanovi[stan_opcija-1].Postavi(add,sprat,broj_soba,namjesten_stan,kvadrati);
                                cout << "Stan uspjesno izmijenjen!" << endl ;
                            }
                            catch(domain_error w)
                            {
                                cout << "Izuzetak: "<< w.what() << ". Molimo unesite opet." << endl ;
                                kon = true ; 
                            }
                        }while(kon==true);
                    }
                    else if(izbor_opet==6)
                    {
                        string adresa ;
                        int spratovi, broj ;
                        double kvad ;
                        bool nam ;
                        bool kont;
                        do
                        {
                            kont = false ; 
                            cout << "Unesite adresu: " ;
                            getline(cin, adresa);
                            cin.clear();
                            cin.ignore(10000,'\n');
                            cout << "Unesite sprat: ";
                            cin >> spratovi ;
                            cout << "Unesite broj soba: " ;
                            cin >> broj ; 
                            cout << "Da li je stan namjesten (1 - da, 0 - ne): " ;
                            cin >> nam ;
                            cout << "Unesite kvadraturu: " ;
                            cin >> kvad ; 
                            try 
                            {
                                stanovi[stan_opcija-1].Postavi(adresa,spratovi, broj,nam, kvad);
                                cout << "Stan uspjesno izmijenjen!" << endl ;
                            }
                            catch(domain_error w)
                            {
                                cout << "Izuzetak: " << w.what() << ". Molimo unesite ponovo." << endl ; 
                                kont = true ; 
                            }
                        }while(kont == true );
                    }
                }
                else if(opcija==3)
                {
                    for(int i=0 ; i<stanovi.size(); i++)
                    {
                        cout << i+1 << ". " ; 
                        stanovi[i].Ispisi();
                    }
                }
                else if(opcija==4)
                {
                    return 0 ; 
                }
            }
        }
            // pocetak kupci
            else if(izbor==2) 
            {
                while(1)
                {
                    int choice ; 
                    cout << "Izaberite opciju:" << endl ; 
                    cout << " 0 - nazad" << endl ;
                    cout << " 1 - dodavanje kupca" << endl ; 
                    cout << " 2 - uredjivanje kupca" <<endl ; 
                    cout << " 3 - ispis svih kupaca" <<endl ; 
                    cout << " 4 - kraj" << endl ;
                    cin>> choice ; 
                    if(!choice) break ; 
                    else if(choice ==1)
                    {
                        bool ist ;
                        do
                        {
                            try
                            {
                                ist = false ; 
                                char c = '/' ;
                                char x ; 
                                cout << "Unesite ime i prezime kupca: " ; 
                                getline(cin, kupac) ;
                                cout << "Unesite datum rodjenja (formata d/m/g): " ;
                                cin >> dan ; 
                                cin >> x ; 
                                if(x!=c) throw domain_error("Neispravan unos podataka") ;
                                cin >> mjesec ; 
                                cin >> x ; 
                                if(x!=c) throw domain_error("Neispravan unos podataka");
                                cin>>godina ;
                                Datum rodjendan(dan, mjesec, godina) ;
                                Kupac k(kupac, rodjendan) ;
                                kupci.push_back(k);
                                cout << "Kupac je uspjesno dodan!" << endl ;
                            }
                            catch(domain_error w)
                            {
                                cout << "Izuzetak:" << w.what() << ". Molimo unesite ponovo." << endl ;
                                ist = true ; 
                            }
                        }while(ist == true);
                    }
                    else if(choice==2)
                    {
                        cout << "Odaberite kupca kojeg zelite urediti. Dostupni kupci su:" << endl ; 
                        for(int i=0 ; i<kupci.size();i++)
                        {
                            cout << i+1 << " - ";
                            kupci[i].Ispisi();
                        }
                        int izbor_kupca ; 
                        cin >> izbor_kupca ; 
                        char c = '/' ; 
                        char x ;
                        bool bb ;
                        do
                        {
                            bb = false ; 
                            cout << "Unesite ime i prezime kupca: " ; 
                            string iime ; 
                            cin.ignore(10000,'\n') ;
                            getline(cin,iime);
                            cout << "Unesite datum rodjenja (formata d/m/g):" ;
                            try
                            {
                                int dd, mm, gg ; 
                                cin >> dd ; 
                                cin >> x ; 
                                if(x!=c) throw domain_error("Neispravan unos podataka");
                                cin>> mm ;
                                cin >> x ; 
                                if(x!=c) throw domain_error("Neispravan unos podataka") ;
                                cin >> gg ; 
                                Datum novii(dd,mm,gg) ;
                                kupci[izbor_kupca-1].Postavi(iime, novii) ;
                                cout << "Kupac je uspjesno izmijenjen!" << endl ; 
                            }
                            catch(domain_error w)
                            {
                                cout << "Izuzetak: "<< w.what() << ". Molimo unesite ponovo." << endl ; 
                                bb = true ; 
                            }
                        }while(bb==true) ;
                    }
                    else if(choice==3)
                    {
                        for(int i=0 ; i<kupci.size() ; i++)
                            kupci[i].Ispisi();
                    }
                    else if(choice==4) return 0 ; 
                }//zavrseni kupci
            }
            else if(izbor == 3)
            {
                while(1)
                {
                    int cc ; 
                    cout << "Izaberite opciju: " << endl ; 
                    cout << " 0 - nazad" << endl ; 
                    cout << " 1 - dodavanje prodaje"<<endl;
                    cout << " 2 - uredjivanje prodaje"<<endl;
                    cout << " 3 - ispis prodaja"<<endl ;
                    cout << " 4 - brisanje prodaja"<<endl;
                    cout << " 5 - kraj" << endl;
                    cin>> cc ;
                    if(!cc) break ; 
                    else if(cc==5) return 0 ;
                    else if(cc==1)
                    {
                        int kl ;
                        cout << "Izaberite opciju:" << endl ; 
                        cout << " 0 - nazad" << endl ;
                        cout<<" 1 - dodavanje potpuno nove prodaje"<<endl;
                        cout <<" 2- dodavanje nove prodaje na osnovu arhive"<< endl;
                        cout << " 3 - kraj"<<endl ;
                        cin>>kl ; 
                        if(!kl) continue ;
                        else if(kl==3) return 0 ; 
                        else if(kl==1)
                        {
                            bool unosenje ;
                            do
                            {
                                try
                                {
                                    unosenje = false ; 
                                    char x ;
                                    cin.ignore(10000,'\n') ;
                                    cout << "Unestie ime i prezime agenta prodaje: ";
                                    getline(cin,agent);
                                    cout << "Unesite datum prodaje (formata d/m/g): " ;
                                    cin >> dan2 ; 
                                    cin >> x ; 
                                    if(x!='/') throw domain_error("Neispravan unos podataka");
                                    cin >> mjesec2;
                                    cin >> x ; 
                                    if(x!='/') throw domain_error("Neispravan unos podataka");
                                    cin >> godina2 ; 
                                    Datum d(dan2,mjesec2,godina2);
                                    double cijenaa;
                                    cout << "Unesite cijenu stana: " ;
                                    cin >> cijenaa ;
                                    string name ; 
                                    cout << "Unesite ime i prezime kupca: " ; 
                                    cin.ignore(10000,'\n') ;
                                    getline(cin,name) ; 
                                    cout << "Unesite datum rodjenja kupca (formata d/m/g): ";
                                    cin >> dan2 ; 
                                    cin >> x ; 
                                    if(x!='/') throw domain_error("Neispravan unos podataka");
                                    cin >> mjesec2 ; 
                                    cin >> x ; 
                                    if(x!='/') throw domain_error("Neispravan unos podataka");
                                    cin>> godina2 ;
                                    Datum dd(dan2, mjesec2,godina2);
                                    cin.ignore(10000,'\n');
                                    cout << "Unesite adresu: ";
                                    string addr ;
                                    int spr,sob ;
                                    double kvvv;
                                    bool namje ; 
                                    getline(cin, addr) ;
                                    cout << "Unesite sprat: " ; 
                                    cin >> spr ; 
                                    cout << "Unesite broj soba: " ;
                                    cin >> sob ; 
                                    cout << "Da li je stan namjesten (1 - da, 0 - ne): ";
                                    cin >> namje ; 
                                    cout << "Unesite kvadraturu: " ; 
                                    cin >> kvvv ; 
                                    Kupac kk(name, dd) ;
                                    kupci.push_back(kk);
                                    Stan s(addr,spr,sob,namje,kvvv);
                                    stanovi.push_back(s);
                                    Prodaja p(agent, cijenaa,d,kk,s);
                                    prodaje.push_back(p);
                                    cout << "Prodaja uspjesno dodana!" << endl ; 
                                }
                                catch(domain_error w)
                                {
                                    cout << "Izuzetak: " << w.what() << ". Molimo unesite ponovo." << endl ;
                                    unosenje = true ;
                                }
                            }while(unosenje==true);
                        }
                        else if(kl==2)
                        {
                            bool uslov ;
                            do
                            {
                                try
                                {
                                    uslov = false ;
                                    cout << "Unesite ime i prezime agenta prodaje: " ; 
                                    string imeag ; 
                                    cin.ignore(10000,'\n');
                                    getline(cin,imeag);
                                    int danpr, mjpr, gpr ;
                                    cout << "Unesite datum prodaje (formata d/m/g): ";
                                    cin >> danpr ; 
                                    char x; 
                                    cin>> x ; 
                                    if(x!='/') throw domain_error("Neispravan unos podataka");
                                    cin >> mjpr ; 
                                    cin >> x ; 
                                    if(x!='/') throw domain_error("Neispravan unos podataka");
                                    cin>>gpr ;
                                    Datum prod(danpr, mjpr,gpr);
                                    cout << "Unesite cijenu stana: " ; 
                                    double cifra ; 
                                    cin >> cifra ; 
                                    cout << "Odaberite kupca. Dostupni kupci su: " << endl ;
                                    for(int i=0 ; i<kupci.size() ; i++)
                                    {
                                        cout << i+1 << " - "  ;
                                        kupci[i].Ispisi();
                                    }
                                    int brojkupca ; 
                                    cin>>brojkupca ; 
                                    cout << "Odaberite stan. Dostupni stanovi su:" << endl ; 
                                    for(int i=0 ; i<stanovi.size();i++)
                                    {
                                        cout << i+1 << " - ";
                                        stanovi[i].Ispisi();
                                    }
                                    int brojstana ; 
                                    cin>> brojstana ;
                                    Datum rodj = kupci[brojkupca-1].DajDatumRodjenja();
                                    string kupacc = kupci[brojkupca-1].DajImePrezime();
                                    string add = stanovi[brojstana-1].DajAdresu();
                                    Prodaja pp(imeag, cifra, danpr, mjpr,gpr, kupacc, rodj,add,stanovi[brojstana-1].DajSprat(), stanovi[brojstana-1].DajBrojSoba(),stanovi[brojstana-1].DajNamjesten(),stanovi[brojstana-1].DajKvadraturu());
                                    prodaje.push_back(pp);
                                    cout << "Prodaja uspjesno dodana!" << endl; 
                                }
                                catch(domain_error w)
                                {
                                    cout << "Izuzetak: "<< w.what() << ". Molimo unesite ponovo." ;
                                    uslov = true ; 
                                }
                                
                            }while(uslov==true);
                        }
                    }
                    else if(cc==2)
                    {
                        return 0 ; 
                    }
                }
            }
        }*/
        
    return 0;
}