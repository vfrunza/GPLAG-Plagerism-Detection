/B 2016/2017, Zadaca 4, Zadatak 3
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <cctype>
#include <iomanip>
#include <vector>
   // ========= DATUM =======
class Datum
{
    int dan, mj, god;
    public:
    Datum(int dan, int mjesec, int godina);
    void Postavi(int dan, int mjesec, int godina) { *this = Datum(dan, mjesec, godina); }
    int DajDan() const { return dan; }
    int DajMjesec() const { return mj; }
    int DajGodinu() const { return god; }
    void Ispisi() const { std::cout<<dan<<"/"<<mj<<"/"<<god; }
};
bool Jednaki(Datum d1,Datum d2) { return d1.DajDan()==d2.DajDan() && d1.DajMjesec()==d2.DajMjesec() && d1.DajGodinu()==d2.DajGodinu();}
bool Ranije(Datum d1, Datum d2)
{
    if(d1.DajGodinu() < d2.DajGodinu()) return true;
    else if(d1.DajGodinu() > d2.DajGodinu()) return false;
    else if(d1.DajMjesec() < d2.DajMjesec()) return true;
    else if(d1.DajMjesec() > d2.DajMjesec()) return false;
    else return d1.DajDan() < d2.DajDan();
}
Datum::Datum(int dan, int mjesec, int godina)
{
    int niz[]{31,28,31,30,31,30,31,31,30,31,30,31};
    if(godina % 4 == 0 && !(godina % 400 != 0 && godina % 100 == 0)) 
        niz[1]++;
    if(godina < 0 || mjesec < 1 || mjesec > 12 || dan < 1 || dan > niz[mjesec - 1])
        throw std::domain_error("Neispravan datum");
    Datum::dan = dan;
    mj = mjesec;
    god = godina;
}

//  ======== KUPAC ==========
class Kupac
{
  std::string ime_i_preyime;
  Datum datum_rodjenja;
  public:
    Kupac(const std::string &ime_i_prezime, const Datum &datum_rodjenja);
    void Postavi(const std::string &ip, const Datum &dr) { *this = Kupac(ip, dr); }
    std::string DajImePrezime() const { return ime_i_preyime; }
    Datum DajDatumRodjenja() const { return datum_rodjenja; }
    void Ispisi() const { std::cout<< ime_i_preyime<< " ("; datum_rodjenja.Ispisi(); std::cout<<")"; }
};
Kupac::Kupac(const std::string &ime_i_prezime, const Datum &datum_rodjenja): datum_rodjenja(datum_rodjenja)
{
    for(auto e: ime_i_prezime)
    {
        if(!isalpha(e) && !isdigit(e) && e != '\'' && e != '-' && e != ' ')
        {
            throw std::domain_error("Neispravno ime i prezime");
        }
    }
    ime_i_preyime = ime_i_prezime;
}


// ========== STAN ===========

class Stan
{
  std::string adresa;
  int sprat, broj_soba;
  bool namjesten;
  double kvadratura;
  public:
    Stan(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura);
    void Postavi(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura)
        { *this = Stan(adresa, sprat, broj_soba, namjesten, kvadratura); }
    std::string DajAdresu() const { return adresa; }
    int DajSprat() const { return sprat; }
    int DajBrojSoba() const { return broj_soba; }
    bool DajNamjesten() const { return namjesten; }
    double DajKvadraturu() const { return kvadratura; }
    void Ispisi() const;
};
Stan::Stan(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura)
{
    if(sprat < 0 || broj_soba < 0 || kvadratura < 0)
        throw std::domain_error("Neispravan unos podataka");
    Stan::adresa = adresa;
    Stan::sprat = sprat;
    Stan::broj_soba = broj_soba;
    Stan::namjesten = namjesten;
    Stan::kvadratura = kvadratura;
}
void Stan::Ispisi() const
{
    std::cout<< "Stan se nalazi na adresi "<< adresa << " na "<<sprat<<". spratu i ima "<<
        broj_soba<<" "<< ((broj_soba == 2 || broj_soba == 3 || broj_soba == 4) ? "sobe" : (broj_soba == 1 ? "sobu" : "soba"))<<
        ". " <<"Kvadratura stana je "<< kvadratura<< " (m^2) i stan "<< (namjesten ? "je" : "nije") << " namjesten."; 
}

// ========= PRODAJA ==========

class Prodaja
{
   std::string ime_agenta;
   double cijena_stana;
   Datum datum_prodaje;
   Kupac kupac_stana;
   Stan stan;
   
   public:
   Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan):
   datum_prodaje(datum_prodaje), kupac_stana(kupac_stana), stan(kupljeni_stan)
   {
       ime_agenta = ime_agenta_prodaje;
       Prodaja::cijena_stana = cijena_stana;
   }
   
    Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, 
    int godina_prodaje, std::string &ime_kupca, const Datum &datum_rodjenja_kupca,
    const std::string &adresa_stana, int sprat_stana, int broj_soba,
    bool namjesten_stan, double broj_kvadrata): ime_agenta(ime_agenta_prodaje), cijena_stana(cijena_stana), 
        datum_prodaje(dan_prodaje, mjesec_prodaje, godina_prodaje), kupac_stana(ime_kupca, datum_rodjenja_kupca),
        stan(adresa_stana, sprat_stana, broj_soba, namjesten_stan, broj_kvadrata){}
    void PromijeniAgenta(const std::string& s){ ime_agenta = s; }
    void PromijeniKupca(const Kupac &novi_kupac) { kupac_stana = novi_kupac; }
    void PromijeniStan(const Stan &novi_stan) { stan = novi_stan; }
    void PromijeniDatumKupovine(const Datum &novi_datum) { datum_prodaje = novi_datum; }
    void PromijeniCijenuProdaje(const double &nova_cijena){ cijena_stana = nova_cijena; }
    void PomjeriDanUnaprijed();
    void PomjeriDanUnazad();
    std::string DajImeAgenta() const { return ime_agenta; }
    std::string DajImeKupca() const { return kupac_stana.DajImePrezime(); }
    Datum DajDatumProdaje() const { return datum_prodaje; }
    double DajCijenuStana() const { return cijena_stana; }
    friend bool ProdatPrije(const Prodaja &p1, const Prodaja &p2);
    friend bool SkupljiStan(const Prodaja &p1, const Prodaja &p2);
    void Ispisi() const;
    
};

void Prodaja::PomjeriDanUnaprijed()
{
    int d,m,g;
    d = datum_prodaje.DajDan();
    m = datum_prodaje.DajMjesec();
    g = datum_prodaje.DajGodinu();
    int niz[]{31,28,31,30,31,30,31,31,30,31,30,31};
    if(g % 4 == 0 && !(g % 400 != 0 && g % 100 == 0)) 
        niz[1]++;
    d++;
    if( d > niz[m - 1] ) { d = 1; m++;}
    if(m == 13) { m = 1; g++;}
    datum_prodaje = Datum(d, m, g);
}
void Prodaja::PomjeriDanUnazad()
{
    int d,m,g;
    d = datum_prodaje.DajDan();
    m = datum_prodaje.DajMjesec();
    g = datum_prodaje.DajGodinu();
    int niz[]{31,28,31,30,31,30,31,31,30,31,30,31};
    if(g % 4 == 0 && !(g % 400 != 0 && g % 100 == 0)) 
        niz[1]++;
    d--;
    if(d < 1){
        d = niz[( m + 10) % 12 ];
        m--;
        if(m < 1){
            g--;
            m = 12;
        }
    }
    datum_prodaje = Datum(d, m, g);
}
bool ProdatPrije(const Prodaja& p1, const Prodaja& p2)
{
    if( p1.datum_prodaje.DajGodinu() < p2.datum_prodaje.DajGodinu()) return true;
    else if (p1.datum_prodaje.DajGodinu() > p2.datum_prodaje.DajGodinu()) return false;
    else
    {
        if(p1.datum_prodaje.DajMjesec() < p2.datum_prodaje.DajMjesec()) return true;
        else if(p1.datum_prodaje.DajMjesec() > p2.datum_prodaje.DajMjesec()) return false;
        else
        {
            if(p1.datum_prodaje.DajDan() < p2.datum_prodaje.DajDan()) return true;
            return false;
        }
    }
}
bool SkupljiStan(const Prodaja &p1, const Prodaja &p2)
{
    return p1.cijena_stana < p2.cijena_stana;
}
void Prodaja::Ispisi() const
{
    std::cout<<std::setw(32)<<std::left<< "Ime agenta:"<< ime_agenta<<"\n";
    std::cout<<std::setw(32)<< "Ime kupca:"; kupac_stana.Ispisi(); std::cout<< "\n";
    std::cout<<std::setw(32)<< "Zakazani datum prodaje:"; datum_prodaje.Ispisi(); std::cout<< "\n";
    std::cout<<std::setw(32)<< "Cijena stana:"<< cijena_stana<< "\n";
    std::cout<<"Informacije o stanu:\n";
    stan.Ispisi();
}

// :============= PRODAJEEEEEE ===========: 

class Prodaje
{
    std::vector<Prodaja*> prodaje;
    public:
    explicit Prodaje();
    Prodaje(std::initializer_list<Prodaja> spisak_prodaja);
    ~Prodaje();
    Prodaje(const Prodaje &prodaje);
    Prodaje(Prodaje &&prodaje);
    Prodaje &operator =(const Prodaje &prodaje);
    Prodaje &operator =(Prodaje &&prodaje);
    
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje,
    double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana,
    const Stan &kupljeni_stan);
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje,double cijena, int dan_prodaje,
    int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca,
    const Datum &datum_rodjenja_kupca, const std::string &adresa_stana,
    int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata);
    void RegistrirajProdaju(Prodaja *prodaja);
    int DajBrojProdaja() const;
    int DajBrojProdajaNaDatum(const Datum &datum) const;
    int DajBrojProdajaOdAgenta(const std::string &ime_agenta) const;
    Prodaja &DajNajranijuProdaju();
    Prodaja DajNajranijuProdaju() const;
    Prodaja &DajNajskupljuProdaju();
    Prodaja DajNajskupljuProdaju() const;
    void IsprazniKolekciju();
    void ObrisiNajranijuProdaju();
    void ObrisiProdajeAgenta(const std::string &ime_agenta);
    void ObrisiProdajeNaDatum(const Datum &datum);
    void IspisiProdajeNaDatum(const Datum &datum) const;
    void IspisiSveProdaje() const;
    Prodaja& DajProdaju(int ind);
};
Prodaja& Prodaje::DajProdaju(int ind)
{
    if(ind > prodaje.size() || ind < 1) throw "losina";
    return *prodaje[ind-1];
}
 Prodaje::Prodaje()
{
    
}
Prodaje::Prodaje(std::initializer_list<Prodaja> spisak_prodaja)
{
    prodaje.resize(spisak_prodaja.size());
    try
    {
        for(int i=0; i < spisak_prodaja.size(); i++) prodaje[i] = nullptr;
        auto it = spisak_prodaja.begin();
        for(int i=0; i < spisak_prodaja.size(); i++)
        {
            prodaje[i] = new Prodaja(*it++);
        }
    }
    catch(...)
    {
        for(int i=0; i<spisak_prodaja.size(); i++)
        delete prodaje[i];
        throw;
    }
}
Prodaje::~Prodaje()
{
    for(int i=0;i<prodaje.size();i++) delete prodaje[i];
    prodaje.clear();
}
Prodaje::Prodaje(const Prodaje& p)
{
    try
    {
        prodaje.resize(p.prodaje.size());
        for(int i=0; i<p.prodaje.size(); i++) prodaje[i] = nullptr;
        for(int i=0; i<p.prodaje.size(); i++)
        {
            prodaje[i] = new Prodaja(*(p.prodaje[i]));
        }
    }
    catch(...)
    {
        for(int i=0; i < p.prodaje.size(); i++) delete prodaje[i];
        throw;
    }
}
Prodaje::Prodaje(Prodaje &&p)
{
    std::swap(prodaje, p.prodaje);
}
Prodaje& Prodaje::operator =(const Prodaje &p)
{
    this->~Prodaje();
    prodaje.resize(p.prodaje.size());
    try
    {
        for(int i=0;i<prodaje.size();i++) prodaje[i] = nullptr;
        for(int i=0;i<prodaje.size();i++) prodaje[i] = new Prodaja(*p.prodaje[i]);
    }
    catch(...)
    {
        for(int i=0;i<prodaje.size();i++) delete prodaje[i];
        throw;
    }
    return *this;
}
Prodaje& Prodaje::operator=(Prodaje &&p)
{
    std::swap(prodaje, p.prodaje);
    return *this;
}
void Prodaje::RegistrirajProdaju(const std::string &im, double ci, const Datum &da, const Kupac &ku, const Stan &st)
{
   //if(prodaje.size() == prodaje.size()) throw std::range_error("Dostignut maksimalni broj prodaja");
   prodaje.push_back( new Prodaja(im, ci, da, ku, st));
}
void Prodaje::RegistrirajProdaju(const std::string &imea,double ci, int d,int m, int g, std::string &imek, const Datum &datk, const std::string &adr,
    int sprat, int bs, bool namj, double brk)
{
    //if(prodaje.size() == prodaje.size()) throw std::range_error("Dostignut maksimalni broj prodaja");
    prodaje.push_back( new Prodaja(imea, ci, d, m, g, imek, datk, adr, sprat, bs, namj, brk));
}
void Prodaje::RegistrirajProdaju(Prodaja* p)
{
    if(prodaje.size() == prodaje.size()) throw std::range_error("Dostignut maksimalni broj prodaja");
    prodaje.push_back( p);
}
int Prodaje::DajBrojProdaja() const { return prodaje.size(); }
int Prodaje::DajBrojProdajaNaDatum(const Datum& d) const
{
    return std::count_if(prodaje.begin(), prodaje.end(), [d](Prodaja* p){ 
        auto e = p->DajDatumProdaje();
        return Jednaki(d,e);});
}
int Prodaje::DajBrojProdajaOdAgenta(const std::string &ag) const
{
    return std::count_if(prodaje.begin(), prodaje.end(), [ag](Prodaja* p){return p->DajImeAgenta() == ag;});
}
Prodaja& Prodaje::DajNajranijuProdaju()
{
    if(prodaje.size() == 0) throw std::domain_error("Nema registriranih prodaja");
    return **std::min_element(prodaje.begin(), prodaje.end(), [](Prodaja* p1, Prodaja* p2){
       Datum d1(p1->DajDatumProdaje()), d2(p2->DajDatumProdaje());
       if(d1.DajGodinu() < d2.DajGodinu()) return true;
       else if(d1.DajGodinu() > d2.DajGodinu()) return false;
       else if(d1.DajMjesec() < d2.DajMjesec()) return true;
       else if(d1.DajMjesec() > d2.DajMjesec()) return false;
       else return d1.DajDan() < d2.DajDan();
    });
}
Prodaja Prodaje::DajNajranijuProdaju() const {if(prodaje.size() == 0) throw std::domain_error("Nema registriranih prodaja");
return Prodaje(*this).DajNajranijuProdaju(); }

Prodaja& Prodaje::DajNajskupljuProdaju()
{
    if(prodaje.size() == 0) throw std::domain_error("Nema registriranih prodaja");
    return **std::max_element(prodaje.begin(), prodaje.end(), [](Prodaja* p1, Prodaja* p2){
       return p1->DajCijenuStana() < p2->DajCijenuStana(); 
    });
}
Prodaja Prodaje::DajNajskupljuProdaju() const { return Prodaje(*this).DajNajskupljuProdaju(); }
void Prodaje::IsprazniKolekciju()
{
    for(int i=0; i<prodaje.size(); i++) delete prodaje[i];
    prodaje.clear();
}
void Prodaje::ObrisiNajranijuProdaju()
{
    if(prodaje.size() == 0) throw std::range_error("Prazna kolekcija");
    auto najranija = DajNajranijuProdaju();
    for(int i=0; i<prodaje.size(); i++)
    {
        if(&najranija == prodaje[i])
        {
            delete prodaje[i];
            for(int j=i; j+1<prodaje.size(); j++) prodaje[j] = prodaje[j+1];
            prodaje.pop_back();
            break;
        }
    }
}
void Prodaje::ObrisiProdajeAgenta(const std::string& ime_agenta)
{
    int vel = 0;
    for(int i=0; i<prodaje.size(); i++)
    {
        if(prodaje[i]->DajImeAgenta() == ime_agenta)
        {
            delete prodaje[i];
        }
        else
        {
            prodaje[vel++] = prodaje[i];
        }
    }
    prodaje.resize(vel);
}
void Prodaje::ObrisiProdajeNaDatum(const Datum& dat)
{
    int vel = 0;
    for(int i=0; i<prodaje.size(); i++)
    {
        if(Jednaki(prodaje[i]->DajDatumProdaje(), dat))
        {
            delete prodaje[i];
            prodaje[i] = nullptr;
        }
        else
        {
            prodaje[vel++] = prodaje[i];
        }
    }
    prodaje.resize(vel);
}
void Prodaje::IspisiProdajeNaDatum(const Datum& dat) const
{
    Prodaje aux(*this);
    std::sort(aux.prodaje.begin(), aux.prodaje.end(), [](Prodaja* p1, Prodaja* p2){
       return !Ranije(p1->DajDatumProdaje(), p2->DajDatumProdaje()) ||
       (Jednaki(p1->DajDatumProdaje(), p2->DajDatumProdaje()) && p1->DajImeKupca() < p2->DajImeKupca());
    });
    for(int i=0; i<aux.prodaje.size(); i++)
    {
        if(Jednaki(aux.prodaje[i]->DajDatumProdaje(), dat)) { (aux.prodaje[i])->Ispisi(); std::cout<< "\n\n"; }
    }
}
void Prodaje::IspisiSveProdaje() const
{
    Prodaje aux(*this);
     std::sort(aux.prodaje.begin(), aux.prodaje.end(), [](Prodaja* p1, Prodaja* p2){
       return Ranije(p1->DajDatumProdaje(), p2->DajDatumProdaje()) ||
       (Jednaki(p1->DajDatumProdaje(), p2->DajDatumProdaje()) && p1->DajImeKupca() < p2->DajImeKupca());
    });
    for(int i=0; i < aux.prodaje.size(); i++)
    {
        aux.prodaje[i]->Ispisi(); std::cout<< "\n\n";
    }
}











int main ()
{
    std::vector<Stan> stanovi;
    std::vector<Kupac> kupci;
    Prodaje prodaje;
    std::cout<< "Dobrodosli!\n\n\n";
    
    int opt0 = 1;
  while(opt0)
  {
        
std::cout<< R"(Izaberite opciju:
 0 - kraj
 1 - uredjivanje stanova
 2 - uredjivanje kupaca
 3 - uredjivanje prodaja
)";
    std::cin>> opt0;
    if(opt0 == 0) break;
    else if(opt0 == 1)
    {

        int opt1 = 1;
        while(opt1)
        {
            std::cout<<R"(Izaberite opciju:
 0 - nazad
 1 - dodavanje stana
 2 - uredjivanje stanova
 3 - ispis svih stanova
 4 - kraj
)";
            std::cin>> opt1;
            if(opt1 == 0) break;
            else if(opt1 == 1)
            {
               bool neispravan = true;
               while(neispravan)
               {
                   std::string adresa;
                   int sprat, soba, namjesten;
                   double kvadratura;
                   std::cout<< "Unesite adresu: ";
                   std::cin.ignore(1000,'\n');
                   std::getline(std::cin, adresa);
                   std::cout<< "Unesite sprat: "; std::cin>> sprat;
                   std::cout<< "Unesite broj soba: "; std::cin>> soba;
                   std::cout<< "Da li je stan namjesten (1 - da, 0 - ne): "; std::cin>> namjesten;
                   std::cout<< "Unesite kvadraturu: "; std::cin>> kvadratura;
                   try 
                   {
                       Stan stan(adresa, sprat, soba, namjesten, kvadratura);
                       if(namjesten != bool(namjesten)) Stan s1("",-1,0,1,1);
                       stanovi.push_back(stan);
                       neispravan = false;
                       std::cout<< "Stan je uspjesno dodan!\n\n";
                   }
                   catch (std::domain_error e) 
                   {
                        std::cout<<"Izuzetak: "<< e.what()<< ". Molimo unesite opet.\n\n";    
                   }
               }
            }
            else if(opt1 == 2)
            {
                std::cout<< "Odaberite stan. Dostupni stanovi su:\n";
                for(int i=0; i<stanovi.size(); i++)
                {
                    std::cout<<" "<< i+1<<" - ";
                    stanovi[i].Ispisi();
                    std::cout<< std::endl;
                }
                std::cout<<std::endl;
                int broj_stana;
                std::cin>> broj_stana;
                Stan& s = stanovi[broj_stana-1];
                std::cout<<R"(Odaberite polje koje zelite urediti:
 0 - nazad
 1 - adresa
 2 - sprat
 3 - broj soba
 4 - da li je stan namjesten
 5 - kvadratura
 6 - sve
)"; 
            int za_urediti, broj;
            std::cin>>za_urediti;
            while(1)
            {
               try
               {
                if(za_urediti == 0) {}
                if(za_urediti == 1 || za_urediti == 6)
                {
                    std::string adr;
                    std::cout<< "Unesite adresu: ";
                    std::cin.ignore(100,'\n');
                    std::getline(std::cin,adr);
                    s.Postavi(adr, s.DajSprat(), s.DajBrojSoba(), s.DajNamjesten(), s.DajKvadraturu());
                }
                if(za_urediti == 2 || za_urediti == 6)
                {
                    std::cout<< "Unesite sprat: ";
                    std::cin>> broj;
                    s.Postavi(s.DajAdresu(), broj, s.DajBrojSoba(), s.DajNamjesten(), s.DajKvadraturu());
                }
                if(za_urediti == 3 || za_urediti == 6)
                {
                    std::cout<< "Unesite broj soba: ";
                    std::cin>>broj;
                    s.Postavi(s.DajAdresu(), s.DajSprat(), broj, s.DajNamjesten(), s.DajKvadraturu());
                }
                if(za_urediti == 4 || za_urediti == 6)
                {
                    std::cout<< "Da li je stan namjesten (1 - da, 0 - ne): ";
                    std::cin>> broj;
                    s.Postavi(s.DajAdresu(), s.DajSprat(), s.DajBrojSoba(), broj, s.DajKvadraturu());
                }
                if(za_urediti == 5 || za_urediti == 6)
                {
                    std::cout<< "Unesite kvadraturu: ";
                    double kvadratura;
                    std::cin>> kvadratura;
                    s.Postavi(s.DajAdresu(), s.DajSprat(), s.DajBrojSoba(), s.DajNamjesten(), kvadratura);
                }
                std::cout<< "Stan je uspjesno izmijenjen!\n\n";
                break;
               }
               catch(std::domain_error e)
               {
                    std::cout<<"Izuzetak: "<< e.what()<< ". Molimo unesite opet.\n";
               }
            }
            }
            else if(opt1 == 3)
            {
                for(int i=0; i<stanovi.size(); i++)
                {
                    std::cout<< i+1<<". ";
                    stanovi[i].Ispisi();
                    std::cout<< std::endl;
                }
                std::cout<<std::endl;
            }
        }
    }
    else if(opt0 == 2)
    {
        int opt2 = 1;
        while(opt2)
        {
std::cout<< R"(Izaberite opciju:
 0 - nazad
 1 - dodavanje kupca
 2 - uredjivanje kupaca
 3 - ispis svih kupaca
 4 - kraj
)";
            std::cin>> opt2;
            
            if(opt2 == 0) break;
            else if(opt2 == 1)
            {
                while(1)
                {
                    std::cout<< "Unesite ime i prezime kupca: ";
                    std::string ime;
                    std::cin.ignore(100, '\n');
                    std::getline(std::cin, ime);
                    int d,m,g;
                    char znak;
                    std::cout<< "Unesite datum rodjenja (formata d/m/g): ";
                    std::cin>> d>> znak>> m>> znak>> g;
                    try
                    {
                        kupci.push_back(Kupac(ime, {d, m, g}));
                        std::cout<< "Kupac je uspjesno dodan!\n\n";
                        break;
                    }
                    catch(std::domain_error e)
                    {
                        std::cout<< "Izuzetak: "<< e.what()<< ". Molimo unesite opet.\n";
                    }
                }
            }
            else if(opt2 == 2)
            {
                std::cout<< "Odaberite kupca kojeg zelite urediti. Dostupni kupci su:\n";
                for(int i=0;i<kupci.size(); i++)
                {
                    std::cout<<" "<< i+1<< " - "; kupci[i].Ispisi();
                    std::cout<<std::endl;
                }
                int broj_kupca;
                std::cin>> broj_kupca;
                Kupac& k = kupci[broj_kupca - 1];
                while(1)
                {
                    std::cout<< "Unesite ime i prezime kupca: ";
                    std::string ime;
                    std::cin.ignore(100, '\n');
                    std::getline(std::cin, ime);
                    int d,m,g;
                    char znak;
                    std::cout<< "Unesite datum rodjenja (formata d/m/g): ";
                    std::cin>> d>> znak>> m>> znak>> g;
                    try
                    {
                        k = Kupac(ime, {d,m,g});
                        std::cout<< "Kupac je uspjesno izmijenjen!\n\n";
                        break;
                    }
                    catch(std::domain_error e)
                    {
                        std::cout<<"Izuzetak: "<<e.what()<<". Molimo unesite opet.\n";
                    }
                }
            }
            else if(opt2 == 3)
            {
                for(auto& e: kupci)
                {
                    e.Ispisi();
                    std::cout<< std::endl;
                }
                std::cout<< "\n";
            }
            else { std::cout<< "Dovidjenja!"; return 0; }
        }
    }
    else if(opt0 == 3)
    {
        int opt3 = 1;
        while(1)
        {
std::cout<<R"(Izaberite opciju:
 0 - nazad
 1 - dodavanje prodaje
 2 - uredjivanje prodaje
 3 - ispis prodaja
 4 - brisanje prodaja
 5 - kraj
)";     
            std::cin>> opt3;
            if(opt3 == 0) break;
            else if(opt3 == 1)
            {
                int opt;
                while(1)
                {
                    std::cout<<R"(Izaberite opciju:
 0 - nazad
 1 - dodavanje potpuno nove prodaje
 2 - dodavanje nove prodaje na osnovu arhive
 3 - kraj
)";                 
                    std::cin>> opt;
                    if(opt == 0) break;
                    else if(opt == 1)
                    {
                        std::cout<< "Unesite ime i prezime agenta prodaje: ";
                        std::string imea,imek,adr;
                        std::cin.ignore(1000,'\n');
                        std::getline(std::cin, imea);
                        int d,m,g,dk,mk,gk; char x;
                        std::cout<< "Unesite datum prodaje (formata d/m/g): ";
                        std::cin>> d>>x>>m>>x>>g;
                        double cijena;
                        std::cout<< "Unesite cijenu stana: ";
                        std::cin>>cijena;
                        std::cout<< "Unesite ime kupca: ";
                        std::cin.ignore(1000,'\n');
                        std::getline(std::cin, imek);
                        std::cout<< "Unesite datum rodjenja kupca (formata d/m/g): ";
                        std::cin>> dk>>x>>mk>>x>>gk;
                        std::cout<< "Unesite adresu: ";
                        std::cin.ignore(1000,'\n');
                        std::getline(std::cin, adr);
                        int sprat, soba, namjesten;
                        double kvadratura;
                        std::cout<< "Unesite sprat: "; std::cin>> sprat;
                        std::cout<< "Unesite broj soba: "; std::cin>> soba;
                        std::cout<< "Da li je stan namjesten (1 - da, 0 - ne): "; std::cin>> namjesten;
                        std::cout<< "Unesite kvadraturu: "; std::cin>> kvadratura;
                        try
                        {
                            prodaje.RegistrirajProdaju(imea, cijena, d, m, g, imek, {dk, mk, gk}, adr, sprat, soba, namjesten, kvadratura);
                            kupci.push_back(Kupac(imek, {dk,mk,gk}));
                            stanovi.push_back(Stan(adr, sprat, soba, namjesten, kvadratura));
                            std::cout<<"Prodaja uspjesno dodana!\n\n";
                        }
                        catch(std::range_error e)
                        {
                            std::cout<< "Izuzetak: "<< e.what()<<". Molimo unesite opet.\n";
                        }
                    }
                    else if(opt == 2)
                    {
                        std::cout<< "Unesite ime i prezime agenta prodaje: ";
                        std::string imea;
                        std::cin.ignore(1000,'\n');
                        std::getline(std::cin, imea);
                        std::cout<< "Unesite datum prodaje (formata d/m/g): ";
                        int d,m,g; char x;
                        std::cin>>d>>x>>m>>x>>g;
                        double cijena;
                        std::cout<< "Unesite cijenu stana: ";
                        std::cin>> cijena;
                        std::cout<< "Odaberite kupca. Dostupni kupci su:\n";
                        for(int i=0;i<kupci.size(); i++)
                         {
                             std::cout<<" "<< i+1<< " - "; kupci[i].Ispisi();
                             std::cout<<std::endl;
                         }
                        int kupac;
                        std::cin>> kupac;
                        std::cout<< "Odaberite stan. Dostupni stanovi su:\n";
                         for(int i=0; i<stanovi.size(); i++)
                            {
                                std::cout<<" "<< i+1<<" - ";
                                stanovi[i].Ispisi();
                                std::cout<< std::endl;
                            }
                        int stan;
                        std::cin>> stan;
                        try
                        {
                            prodaje.RegistrirajProdaju(imea, cijena, {d,m,g}, kupci[kupac-1], stanovi[stan-1]);
                            std::cout<< "Prodaja uspjesno dodana!\n\n";
                        }
                        catch(std::range_error e)
                        {
                            std::cout<<e.what();
                        }
                    }
                    else if(opt == 3) { std::cout<< "Dovidjenja!"; return 0; }
                }
            }
            else if(opt3 == 2)
            {
                std::cout<< "Odaberite prodaju koju želite urediti. Dostupne prodaje su:\n";
                for(int i=0;i<prodaje.DajBrojProdaja();i++)
                {
                    std::cout<<i+1<<".\n";
                    prodaje.DajProdaju(i+1).Ispisi();
                    std::cout<<"\n";
                }
                int broj_p;
                std::cin>> broj_p;
                Prodaja& p = prodaje.DajProdaju(broj_p);
                while(1)
                {
                    
std::cout<<R"(Izaberite opciju:
 0 - nazad
 1 - izmjena agenta
 2 - izmjena datuma prodaje
 3 - izmjena kupca
 4 - izmjena stana
 5 - izmjena cijene stana
)";                 
                    int opt;
                    std::cin>>opt;
                    if(opt == 0) break;
                    else if(opt == 1)
                    {
                        while(1)
                        {
                        std::cout<< "Unesite ime i prezime agenta prodaje: ";
                        std::string ime;
                        std::cin.ignore(1000,'\n');
                        std::getline(std::cin, ime);
                            try
                            {
                                p.PromijeniAgenta(ime);
                                std::cout<< "Prodaja je uspjesno izmijenjena!\n\n";
                                break;
                            }
                            catch(...)
                            {}
                        }
                    }
                    else if(opt == 2)
                    {
                        std::cout<< "Unesite datum prodaje (formata d/m/g): ";
                        int d,m,g; char x;
                        std::cin>> d>> x>> m>> x>> g;
                            try
                            {
                                p.PromijeniDatumKupovine({d,m,g});
                                std::cout<< "Prodaja je uspjesno izmijenjena!\n\n";
                                break;
                            }
                            catch(...)
                            {}
                    }
                    else if(opt == 3)
                    {
std::cout<<R"(Izaberite opciju:
 0 - nazad
 1 - odabir postojeceg kupca
 2 - dodavanje novog kupca
)";
                            int sta;
                            std::cin>> sta;
                            if(sta == 0) break;
                            else if(sta == 1)
                            {
                                std::cout<< "Odaberite kupca. Dostupni kupci su:\n";
                                for(int i=0; i<kupci.size(); i++)
                                {
                                    std::cout<< " "<<i+1<<" - ";
                                    kupci[i].Ispisi();
                                    std::cout<< "\n";
                                }
                                int broj_kupca;
                                std::cin>> broj_kupca;
                                try
                                {
                                    p.PromijeniKupca(kupci[broj_kupca - 1]);
                                    std::cout<< "Prodaja je uspjesno izmijenjena!\n\n";
                                    break;
                                }
                                catch(...)
                                {}
                            }
                            else if(sta == 2)
                            {
                                while(1)
                                {
                                     std::cout<< "Unesite ime i prezime kupca: ";
                                    std::string ime;
                                    std::cin.ignore(100, '\n');
                                    std::getline(std::cin, ime);
                                    int d,m,g;
                                    char znak;
                                    std::cout<< "Unesite datum rodjenja (formata d/m/g): ";
                                    std::cin>> d>> znak>> m>> znak>> g;
                                    try
                                    {
                                         p.PromijeniKupca(Kupac(ime, {d,m,g}));
                                         std::cout<< "Prodaja je uspjesno izmijenjena!\n\n";
                                        break;
                                    }
                                    catch(std::domain_error e)
                                    {
                                          std::cout<< "Izuzetak: "<< e.what()<< ". Molimo unesite opet.\n";
                                    }
                                }
                            }
                    }
                    else if(opt == 4)
                    {
std::cout<<R"( 0 - nazad
 1 - odabir postojeceg stana
 2 - dodavanje novog stana
)";
                        int sta = 0;
                        std::cin>> sta;
                        if(sta == 1)
                        {
                             std::cout<< "Odaberite stan. Dostupni stanovi su:\n";
                         for(int i=0; i<stanovi.size(); i++)
                            {
                                std::cout<<" "<< i+1<<" - ";
                                stanovi[i].Ispisi();
                                std::cout<< std::endl;
                            }
                        int stan;
                        std::cin>> stan;
                        p.PromijeniStan(stanovi[stan-1]);
                        std::cout<< "Prodaja je uspjesno izmijenjena!\n\n";
                        }
                        else if(sta == 2)
                        {
                            bool neispravan = true;
                            while(neispravan)
                            {
                             std::string adresa;
                            int sprat, soba, namjesten;
                            double kvadratura;
                             std::cout<< "Unesite adresu: ";
                            std::cin.ignore(1000,'\n');
                            std::getline(std::cin, adresa);
                           std::cout<< "Unesite sprat: "; std::cin>> sprat;
                           std::cout<< "Unesite broj soba: "; std::cin>> soba;
                           std::cout<< "Da li je stan namjesten (1 - da, 0 - ne): "; std::cin>> namjesten;
                           std::cout<< "Unesite kvadraturu: "; std::cin>> kvadratura;
                           try 
                           {
                               Stan stan(adresa, sprat, soba, namjesten, kvadratura);
                               if(namjesten != bool(namjesten)) Stan s1("",-1,0,1,1);
                               stanovi.push_back(stan);
                               neispravan = false;
                               std::cout<< "Prodaja je uspjesno izmijenjena!\n\n";
                           }
                           catch (std::domain_error e) 
                           {
                                 std::cout<<"Izuzetak: "<< e.what()<< ". Molimo unesite opet.\n\n";    
                           }
                            }
                        }
                    }
                    else if( opt == 5)
                    {
                        
                        while(1)
                        {
                            double cijena;
                            std::cout<< "Unesite cijenu stana: ";
                            std::cin>> cijena;
                            try
                            {
                                p.PromijeniCijenuProdaje(cijena);
                                std::cout<< "Prodaja je uspjesno izmijenjena!\n\n";
                                break;
                            }
                            catch(...){}
                        }
                    }
                    break;
                }
            }
            else if(opt3 == 3)
            {
                int sta;
                while(1)
                {
std::cout<< R"(Izaberite opciju:
 0 - nazad
 1 - ispis svih prodaja
 2 - ispis prodaja na datum
 3 - ispis najranije prodaje
 4 - ispis najskuplje prodaje
 5 - ispis broja prodaja
 6 - ispis broja prodaja po datumu
 7 - ispis broja prodaja po agentu
 8 - kraj
)";             
                    std::cin>> sta;
                    if(sta == 0) break;
                    else if(sta == 1)
                    {
                        prodaje.IspisiSveProdaje();
                    }
                    else if(sta == 2)
                    {
                        int d,m,g; char x;
                        std::cin>>d>>x>>m>>x>>g;
                        prodaje.IspisiProdajeNaDatum({d,m,g});
                    }
                    else if(sta == 3)
                    {
                            prodaje.DajNajranijuProdaju().Ispisi();
                    }
                    else if(sta == 4)
                    {
                        prodaje.DajNajskupljuProdaju().Ispisi();
                    }
                    else if(sta == 5)
                    {
                        std::cout<< "Broj prodaja: "<<prodaje.DajBrojProdaja()<<"\n\n";
                    }
                    else if(sta == 6)
                    {
                        std::cout<<"Unesite datum (d/m/g): ";
                        int d,m,g; char x;
                        std::cin>> d>>x>>m>>x>>g;
                        std::cout<< "Broj prodaja na uneseni datum: "<<prodaje.DajBrojProdajaNaDatum({d,m,g})<<"\n\n";
                    }
                    else if(sta == 7)
                    {
                        std::cout<< "Unesite ime agenta: ";
                        std::string ime;
                        std::cin.ignore(1000,'\n');
                        std::getline(std::cin, ime);
                        std::cout<< "Broj prodaja: "<<prodaje.DajBrojProdajaOdAgenta(ime)<<"\n\n";
                    }
                    else if(sta == 8)
                    {
                        { std::cout<< "Dovidjenja!"; return 0; }
                    }
                }
            }
            else if(opt3 == 4)
            {
                while(1)
                {
std::cout<<R"(Izaberite opciju:
 0 - nazad
 1 - brisanje najranije prodaje
 2 - brisanje prodaja agenta
 3 - brisanje prodaja po datumu
 4 - brisanje svih prodaja
)";             
                    int sta = 0;
                    std::cin>> sta;
                    if(sta == 0) break;
                    else if(sta == 1)
                    {
                        try
                        {
                            prodaje.ObrisiNajranijuProdaju();
                            std::cout<<"Najranija prodaja je obrisana!\n";
                        }
                        catch(std::range_error e)
                        {
                            std::cout<<"Izuzetak: "<<e.what()<<"\n";
                        }
                    }
                    else if(sta == 2)
                    {
                        std::cout<< "Unesite ime agenta: ";
                        std::string ime;
                        std::cin.ignore(1000,'\n');
                        std::getline(std::cin, ime);
                        prodaje.ObrisiProdajeAgenta(ime);
                        std::cout<< "Sve prodaje tog agenta su obrisane.\n";
                    }
                    else if(sta == 3)
                    {
                        std::cout<< "Unesite datum: ";
                        int d,m,g; char x;
                        std::cin>>d>>x>>m>>x>>g;
                        try
                        {
                            prodaje.ObrisiProdajeNaDatum({d,m,g});
                            std::cout<< "Sve prodaje na taj datum su obrisane.\n";
                        }
                        catch(...){}
                    }
                    else if(sta == 4)
                    {
                        prodaje.IsprazniKolekciju();
                        std::cout<< "Sve prodaje su obrisane.\n";
                    }
                }
            }
            else if(opt3 == 5) { std::cout<< "Dovidjenja!"; return 0; }
        }
    }
  }
    
    
    
	{ std::cout<< "Dovidjenja!"; return 0; }
}