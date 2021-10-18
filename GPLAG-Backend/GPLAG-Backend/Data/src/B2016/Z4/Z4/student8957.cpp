/B 2016/2017, Zadaća 4, Zadatak 4
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
#include <memory>
#include <initializer_list>

using namespace std;

class Datum
{
    int Dan, Mjesec, Godina;
public:
    Datum(int dan, int mjesec, int godina) { Postavi(dan, mjesec, godina); }
    void Postavi(int dan, int mjesec, int godina);
    int DajDan() const { return Dan; }
    int DajMjesec() const { return Mjesec; }
    int DajGodinu() const { return Godina; }
    void Ispisi() const { cout << Dan << "/" << Mjesec << "/" << Godina; }
};

void Datum::Postavi(int dan, int mjesec, int godina)
{
    int brojDana[12]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(godina % 4 == 0 && godina % 100 != 0 || godina % 400 == 0) brojDana[1]++;
    if(godina < 1 || dan < 1 || mjesec < 1 || mjesec > 12 || dan > brojDana[mjesec - 1])
        throw domain_error("Neispravan datum");
    Dan = dan;
    Mjesec = mjesec;
    Godina = godina;
}

class Kupac
{
    string imePrezime;
    Datum datumRodjenja;
public:
    Kupac(const std::string &ime_i_prezime, const Datum &datum_rodjenja) : datumRodjenja(datum_rodjenja.DajDan(), datum_rodjenja.DajMjesec(), datum_rodjenja.DajGodinu()) 
    {
        bool validan = true;
        for(int i = 0; i < ime_i_prezime.length(); i++)
        {
            if(!(ime_i_prezime[i] >= 'a' && ime_i_prezime[i] <= 'z' || ime_i_prezime[i] >= 'A' && ime_i_prezime[i] <= 'Z' || ime_i_prezime[i] >= '0' && ime_i_prezime[i] <= '9' || 
                ime_i_prezime[i] == '-' || ime_i_prezime[i] == '\'' || ime_i_prezime[i] == ' '))
            {
                validan = false;
                break;
            }
        }
    
        if(!validan)
            throw domain_error("Neispravno ime i prezime");
            
        imePrezime = ime_i_prezime;
    }
    void Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja);
    std::string DajImePrezime() const { return imePrezime; }
    Datum DajDatumRodjenja() const { return datumRodjenja; }
    void Ispisi() const { cout << imePrezime << "("; datumRodjenja.Ispisi(); cout << ")"; }
};

void Kupac::Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja)
{
    bool validan = true;
    for(int i = 0; i < ime_i_prezime.length(); i++)
    {
        if(!(ime_i_prezime[i] >= 'a' && ime_i_prezime[i] <= 'z' || ime_i_prezime[i] >= 'A' && ime_i_prezime[i] <= 'Z' || ime_i_prezime[i] >= '0' && ime_i_prezime[i] <= '9' || 
            ime_i_prezime[i] == '-' || ime_i_prezime[i] == '\'' || ime_i_prezime[i] == ' '))
        {
            validan = false;
            break;
        }
    }
    
    if(!validan)
        throw domain_error("Neispravno ime i prezime");
    
    imePrezime = ime_i_prezime;
    datumRodjenja.Postavi(datum_rodjenja.DajDan(), datum_rodjenja.DajMjesec(), datum_rodjenja.DajGodinu());
}

class Stan
{
    string Adresa;
    int Sprat;
    int brojSoba;
    bool Namjesten;
    double Kvadratura;
public:
    Stan(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura) { Postavi(adresa, sprat, broj_soba, namjesten, kvadratura); }
    void Postavi(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura);
    std::string DajAdresu() const { return Adresa; }
    int DajSprat() const { return Sprat; }
    int DajBrojSoba() const { return brojSoba; }
    bool DajNamjesten() const { return Namjesten; }
    double DajKvadraturu() const { return Kvadratura; }
    void Ispisi() const;
};

void Stan::Postavi(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura)
{
    if(sprat < 0 || broj_soba < 0 || kvadratura < 0)
        throw domain_error("Neispravan unos podataka");
    Adresa = adresa;
    Sprat = sprat;
    brojSoba = broj_soba;
    Namjesten = namjesten;
    Kvadratura = kvadratura;
}

void Stan::Ispisi() const
{
    string n, s;
    
    if(Namjesten) n = "je namjesten";
    else n = "nije namjesten";
    
    if(brojSoba % 10 == 1) s = "sobu";
    else if(brojSoba % 10 == 2 || brojSoba % 10 == 3 || brojSoba % 10 == 4) s = "sobe";
    else s = "soba";
    
    cout << "Stan se nalazi na adresi " << Adresa << " na " << Sprat << ". spratu i ima " << brojSoba << " " << s << "." << endl;
    cout << "Kvadratura stana je " << Kvadratura << " (m^2) i stan " << n << "." << endl;
}

class Prodaja
{
    string imeAgentaProdaje;
    double cijenaStana;
    Datum datumProdaje;
    Kupac kupacStana;
    Stan kupljeniStan;
public:
    Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan) : imeAgentaProdaje(ime_agenta_prodaje),
        cijenaStana(cijena_stana), datumProdaje(datum_prodaje.DajDan(), datum_prodaje.DajMjesec(), datum_prodaje.DajGodinu()), kupacStana(kupac_stana.DajImePrezime(), kupac_stana.DajDatumRodjenja()),
        kupljeniStan(kupljeni_stan.DajAdresu(), kupljeni_stan.DajSprat(), kupljeni_stan.DajBrojSoba(), kupljeni_stan.DajNamjesten(), kupljeni_stan.DajKvadraturu()) {} 
    Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata) :
        imeAgentaProdaje(ime_agenta_prodaje), cijenaStana(cijena_stana), datumProdaje(dan_prodaje, mjesec_prodaje, godina_prodaje), kupacStana(ime_kupca, datum_rodjenja_kupca), kupljeniStan(adresa_stana, sprat_stana, broj_soba, namjesten_stan, broj_kvadrata) {}
    void PromijeniKupca(const Kupac &novi_kupac) { kupacStana = novi_kupac; }
    void PromijeniStan(const Stan &novi_stan) { kupljeniStan = novi_stan; }
    void PromijeniDatumKupovine(const Datum &novi_datum) { datumProdaje = novi_datum; }
    void PromijeniCijenuProdaje(const double &nova_cijena) { cijenaStana = nova_cijena; }
    void PomjeriDanUnaprijed();
    void PomjeriDanUnazad();
    std::string DajImeAgenta() const { return imeAgentaProdaje; }
    std::string DajImeKupca() const { return kupacStana.DajImePrezime(); }
    Datum DajDatumProdaje() const { return datumProdaje; }
    double DajCijenuStana() const { return cijenaStana; }
    friend bool ProdatPrije(const Prodaja &p1, const Prodaja &p2);
    friend bool SkupljiStan(const Prodaja &p1, const Prodaja &p2);
    void Ispisi() const;
};

bool ProdatPrije(const Prodaja &p1, const Prodaja &p2)
{
    int d1, m1, g1, d2, m2, g2;
    bool prodatPrije = false;
    
    d1 = p1.DajDatumProdaje().DajDan();
    m1 = p1.DajDatumProdaje().DajMjesec();
    g1 = p1.DajDatumProdaje().DajGodinu();
    d2 = p2.DajDatumProdaje().DajDan();
    m2 = p2.DajDatumProdaje().DajMjesec();
    g2 = p2.DajDatumProdaje().DajGodinu();
    
    if(g1 < g2) prodatPrije = true;
    else if(g1 == g2)
    {
        if(m1 < m2) prodatPrije = true;
        else if(m1 == m2)
        {
            if(d1 < d2) prodatPrije = true;
        }
    }
    
    return prodatPrije;
}

bool SkupljiStan(const Prodaja &p1, const Prodaja &p2)
{
    return (p1.DajCijenuStana() > p2.DajCijenuStana());
}

void Prodaja::PomjeriDanUnaprijed()
{
    int dan, mjesec, godina;
    
    dan = datumProdaje.DajDan();
    mjesec = datumProdaje.DajMjesec();
    godina = datumProdaje.DajGodinu();
    
    int brojDana[12]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(godina % 4 == 0 && godina % 100 != 0 || godina % 400 == 0) brojDana[1]++;
    dan++;
    if(dan == brojDana[mjesec - 1] + 1)
    {
        dan = 1;
        mjesec++;
    }
    if(mjesec == 13)
    {
        mjesec = 1;
        godina++;
    }
    
    datumProdaje.Postavi(dan, mjesec, godina);
}

void Prodaja::PomjeriDanUnazad()
{
    int dan, mjesec, godina;
    
    dan = datumProdaje.DajDan();
    mjesec = datumProdaje.DajMjesec();
    godina = datumProdaje.DajGodinu();
    
    int brojDana[12]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(godina % 4 == 0 && godina % 100 != 0 || godina % 400 == 0) brojDana[1]++;
    dan--;
    if(dan == 0)
    {
        if(mjesec == 1)
        {
            mjesec = 12;
            godina--;
        }
        else mjesec--;
        dan = brojDana[mjesec - 1];
    }
    
    datumProdaje.Postavi(dan, mjesec, godina);
}

void Prodaja::Ispisi() const
{
    cout << setw(32) << setfill(' ') << left << "Ime agenta: "  << imeAgentaProdaje << endl;
    cout << setw(32) << setfill(' ') << left << "Ime kupca: "; 
    kupacStana.Ispisi();
    cout << endl;
    cout << setw(32) << setfill(' ') << left << "Zakazani datum prodaje:";
    datumProdaje.Ispisi();
    cout << endl;
    cout << setw(32) << setfill(' ') << left << "Cijena stana: " << cijenaStana << endl;
    cout << "Informacije o stanu:" << endl;
    kupljeniStan.Ispisi();
    cout << endl;
}

class Prodaje
{
    vector<shared_ptr<Prodaja>> sveProdaje;
public:
    explicit Prodaje()
    {
        sveProdaje.resize(0);
    }
    Prodaje(std::initializer_list<Prodaja> spisak_prodaja) 
    {
        sveProdaje.resize(spisak_prodaja.size());
        auto it = spisak_prodaja.begin();
        for(int i = 0; i < spisak_prodaja.size(); i++)
        {
            sveProdaje[i] = make_shared<Prodaja>(*it);
            it++;
        }
    }
    Prodaje(const Prodaje &prodaje) : sveProdaje(prodaje.sveProdaje.size())
    {
        for(int i = 0; i < sveProdaje.size(); i++) sveProdaje[i] = make_shared<Prodaja>(*prodaje.sveProdaje[i]);
    }
    Prodaje(Prodaje &&prodaje) : sveProdaje(move(prodaje.sveProdaje)) {}
    
    Prodaje &operator =(const Prodaje &prodaje)
    {
        if(&prodaje == this) return *this;
        
        sveProdaje.resize(prodaje.sveProdaje.size());
        for(int i = 0; i < prodaje.sveProdaje.size(); i++) sveProdaje[i] = make_shared<Prodaja>(*prodaje.sveProdaje[i]);
        
        return *this;
    }
    Prodaje &operator =(Prodaje &&prodaje)
    {
        if(&prodaje == this) return *this;
        
        sveProdaje = move(prodaje.sveProdaje);
        
        return *this;
    }
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan);
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje,double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata);
    void RegistrirajProdaju(shared_ptr<Prodaja> prodaja);
    int DajBrojProdaja() const { return sveProdaje.size(); }
    int DajBrojProdajaNaDatum(const Datum &datum) const;
    int DajBrojProdajaOdAgenta(const std::string &ime_agenta) const;
    Prodaja &DajNajranijuProdaju();
    Prodaja DajNajranijuProdaju() const;
    Prodaja &DajNajskupljuProdaju();
    Prodaja DajNajskupljuProdaju() const;
    Prodaja &DajProdaju(int indeks)
    { 
        if(indeks < 0 || indeks > sveProdaje.size())
            throw range_error("Nije ispravan");
        return *sveProdaje[indeks - 1]; 
    }
    void IsprazniKolekciju();
    void ObrisiNajranijuProdaju();
    void ObrisiProdajeAgenta(const std::string &ime_agenta);
    void ObrisiProdajeNaDatum(const Datum &datum); //
    void IspisiProdajeNaDatum(const Datum &datum) const;
    void IspisiSveProdaje() const;
};

void Prodaje::RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan)
{
    shared_ptr<Prodaja> p(make_shared<Prodaja>(ime_agenta_prodaje, cijena_stana, datum_prodaje, kupac_stana, kupljeni_stan));
    sveProdaje.push_back(p);
}

void Prodaje::RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata)
{
    shared_ptr<Prodaja> p(make_shared<Prodaja>(ime_agenta_prodaje, cijena_stana, dan_prodaje, mjesec_prodaje, godina_prodaje, ime_kupca, datum_rodjenja_kupca, adresa_stana, sprat_stana, broj_soba, namjesten_stan, broj_kvadrata));
    sveProdaje.push_back(p);
}

void Prodaje::RegistrirajProdaju(shared_ptr<Prodaja> prodaja)
{
    sveProdaje.push_back(prodaja);
}

int Prodaje::DajBrojProdajaNaDatum(const Datum &datum) const
{
    int brojac = count_if(sveProdaje.begin(), sveProdaje.end(), [&](shared_ptr<Prodaja> p) { return (p->DajDatumProdaje().DajDan() == datum.DajDan() && p->DajDatumProdaje().DajMjesec() == datum.DajMjesec() &&
        p->DajDatumProdaje().DajGodinu() == datum.DajGodinu()); });
        
    return brojac;
}

int Prodaje::DajBrojProdajaOdAgenta(const std::string &ime_agenta) const
{
    int brojac = count_if(sveProdaje.begin(), sveProdaje.end(), [&](shared_ptr<Prodaja> p) { return (p->DajImeAgenta() == ime_agenta); });
    
    return brojac;
}

Prodaja &Prodaje::DajNajranijuProdaju()
{
    if(sveProdaje.size() == 0)
        throw domain_error("Nema registriranih prodaja");
    
    auto najranija = min_element(sveProdaje.begin(), sveProdaje.end(), [](shared_ptr<Prodaja> p1, shared_ptr<Prodaja> p2) { return ProdatPrije(*p1, *p2); });
    return **najranija;
}

Prodaja Prodaje::DajNajranijuProdaju() const
{
    if(sveProdaje.size() == 0)
        throw domain_error("Nema registriranih prodaja");
    
    auto najranija = min_element(sveProdaje.begin(), sveProdaje.end(), [](shared_ptr<Prodaja> p1, shared_ptr<Prodaja> p2) { return ProdatPrije(*p1, *p2); });
    
    return **najranija;
}

Prodaja &Prodaje::DajNajskupljuProdaju()
{
    if(sveProdaje.size() == 0)
        throw domain_error("Nema registriranih prodaja");
        
    auto najskuplja = max_element(sveProdaje.begin(), sveProdaje.end(), [](shared_ptr<Prodaja> p1, shared_ptr<Prodaja> p2) { return SkupljiStan(*p1, *p2); });
    
    return **najskuplja;
}

Prodaja Prodaje::DajNajskupljuProdaju() const
{
    if(sveProdaje.size() == 0)
        throw domain_error("Nema registriranih prodaja");
        
    auto najskuplja = max_element(sveProdaje.begin(), sveProdaje.end(), [](shared_ptr<Prodaja> p1, shared_ptr<Prodaja> p2) { return SkupljiStan(*p1, *p2); });
    
    return **najskuplja;
}

void Prodaje::IsprazniKolekciju()
{
    sveProdaje.resize(0);
}

void Prodaje::ObrisiNajranijuProdaju()
{
    if(sveProdaje.size() == 0)
        throw range_error("Prazna kolekcija");
        
    Prodaja najranija = DajNajranijuProdaju();
    
    for(int i = 0; i < sveProdaje.size(); i++)
    {
        if(sveProdaje[i]->DajDatumProdaje().DajDan() == najranija.DajDatumProdaje().DajDan() &&
            sveProdaje[i]->DajDatumProdaje().DajMjesec() == najranija.DajDatumProdaje().DajMjesec() &&
            sveProdaje[i]->DajDatumProdaje().DajGodinu() == najranija.DajDatumProdaje().DajGodinu())
        {
            sveProdaje.erase(sveProdaje.begin() + i);
        }
    }
}

void Prodaje::ObrisiProdajeAgenta(const std::string &ime_agenta)
{
    for(int i = 0; i < sveProdaje.size(); i++)
    {
        if(ime_agenta == sveProdaje[i]->DajImeAgenta())
        {
            sveProdaje.erase(sveProdaje.begin() + i);
        }
    }
}

void Prodaje::ObrisiProdajeNaDatum(const Datum &datum)
{
    for(int i = 0; i < sveProdaje.size(); i++)
    {
        if(datum.DajDan() == sveProdaje[i]->DajDatumProdaje().DajDan() &&
            datum.DajMjesec() == sveProdaje[i]->DajDatumProdaje().DajMjesec() &&
            datum.DajGodinu() == sveProdaje[i]->DajDatumProdaje().DajGodinu())
        {
            sveProdaje.erase(sveProdaje.begin() + i);
        }
    }
}

void Prodaje::IspisiProdajeNaDatum(const Datum &datum) const
{
    vector<shared_ptr<Prodaja>> temp;
    temp = sveProdaje;
    sort(temp.begin(), temp.end(), [](shared_ptr<Prodaja> p1, shared_ptr<Prodaja> p2) { int a = p1->DajImeKupca().compare(p2->DajImeKupca());
                                                                                if(a < 0) return true;
                                                                                else return false; });
    
    for(int i = 0; i < temp.size(); i++)
    {
        if(datum.DajDan() == sveProdaje[i]->DajDatumProdaje().DajDan() &&
            datum.DajMjesec() == sveProdaje[i]->DajDatumProdaje().DajMjesec() &&
            datum.DajGodinu() == sveProdaje[i]->DajDatumProdaje().DajGodinu())
            temp[i]->Ispisi();
    }
}
void Prodaje::IspisiSveProdaje() const
{
    vector<shared_ptr<Prodaja>> temp;
    temp = sveProdaje;
    sort(temp.begin(), temp.end(), [](shared_ptr<Prodaja> p1, shared_ptr<Prodaja> p2) { return ProdatPrije(*p1, *p2); });
    
    for(int i = 0; i < temp.size(); i++)
        sveProdaje[i]->Ispisi();
}

int main ()
{

    
	return 0;
}