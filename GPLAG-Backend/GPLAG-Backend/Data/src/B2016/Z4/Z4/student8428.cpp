/B 2016/2017, Zadaća 4, Zadatak 3
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <memory>
#include <initializer_list>

class Datum{
    int Dan, Mjesec, Godina;
    bool Prestupna(int god)
    {
        if(god % 100 == 0)
        {
            if(god % 400 == 0)
                return true;
            else
                return false;
        }
        if(god % 4 == 0)
            return true;
        
        return false;
    }
    int BrojDana(int mjes, int god)
    {
        switch(mjes)
        {
            case 4: case 6: case 9: case 11:
                return 30;
            case 2:
            if(Prestupna(god))
                return 29;
            else
                return 28;
            default:
                return 31;
        }
    }
public:
    Datum(int dan, int mjesec, int godina)
    {
        Postavi(dan, mjesec, godina);
    }
    void Postavi(int dan, int mjesec, int godina);
    int DajDan() const { return Dan;}
    int DajMjesec() const { return Mjesec;};
    int DajGodinu() const { return Godina;};
    void Ispisi() const
    {
        std::cout << Dan << "/" << Mjesec << "/" << Godina;
    }
};
void Datum::Postavi(int dan, int mjesec, int godina)
{
    if(dan > 0 && dan <= BrojDana(mjesec, godina))
        Dan = dan;
    else
       throw std::domain_error("Neispravan datum");
        
    if(mjesec > 0 && mjesec < 13)
        Mjesec = mjesec;
    else
        throw std::domain_error("Neispravan datum");
    
    Godina = godina;
}

class Kupac
{
    std::string ImeIPrezime;
    Datum DatumRodjenja{1, 1, 2000};
    bool ProvjeriIme(std::string ime)
    {
        for(int i(0); i < ime.size(); i++)
        {
            auto c = ime[i];
            if(c == ' ' || c == '-' || c == 39 || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
                continue;
            else
            {
                return false;
            }
        }
        return true;
    }
    public:
    Kupac(const std::string &ime_i_prezime, const Datum &datum_rodjenja)
    {
        Postavi(ime_i_prezime, datum_rodjenja);
    }
    void Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja);
    std::string DajImePrezime() const
    {
        return ImeIPrezime;
    }
    Datum DajDatumRodjenja() const
    {
        return DatumRodjenja;
    }
    void Ispisi() const
    {
        std::cout << ImeIPrezime << " (";
        DatumRodjenja.Ispisi();
        std::cout << ")";
    }
    
};
void Kupac::Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja)
{
    DatumRodjenja.Postavi(datum_rodjenja.DajDan(), datum_rodjenja.DajMjesec(), datum_rodjenja.DajGodinu());
    if(ProvjeriIme(ime_i_prezime))
        ImeIPrezime = ime_i_prezime;
    else
        throw std::domain_error("Neispravno ime i prezime");
}
class Stan
{
    std::string Adresa;
    int Sprat, BrojSobe;
    bool Namjesten;
    double Kvadratura;
    public:
    Stan(const std::string &adresa, int sprat, int broj_soba, bool namjesten,
    double kvadratura)
    {
        Postavi(adresa, sprat, broj_soba, namjesten, kvadratura);
    }
    void Postavi(const std::string &adresa, int sprat, int broj_soba,
    bool namjesten, double kvadratura)
    {
        if(sprat < 0 || broj_soba < 0 || kvadratura < 0)
            throw std::domain_error("Neispravan unos podataka");
        Adresa = adresa;
        Sprat = sprat;
        BrojSobe = broj_soba;
        Namjesten = namjesten;
        Kvadratura = kvadratura;
    }
    std::string DajAdresu() const { return Adresa;}
    int DajSprat() const { return Sprat;}
    int DajBrojSoba() const { return BrojSobe;}
    bool DajNamjesten() const { return Namjesten;}
    double DajKvadraturu() const {return Kvadratura;}
    void Ispisi() const
    {
        std::cout << "Stan se nalazi na adresi " << Adresa << " na " << Sprat << ". spratu i ima " << BrojSobe;
        if((BrojSobe >= 2 && BrojSobe <= 4) || (BrojSobe > 20 && BrojSobe % 10 >= 2 && BrojSobe % 10 <= 4))
            std::cout << " sobe." << std::endl;
        else
            std::cout << " soba." << std::endl;
            
        std::cout << "Kvadratura strana je " << Kvadratura << " (m^2) i stan ";
        if(Namjesten)
            std::cout << "je namjesten.";
        else 
            std::cout << "nije namjesten.";
    }

};
class Prodaja
{
    std::string ImeAgenta;
    double CijenaStana;
    Datum DatumProdaje;
    Kupac KupacStana;
    Stan KupljeniStan;
    bool Prestupna(int god)
    {
        if(god % 100 == 0)
        {
            if(god % 400 == 0)
                return true;
            else
                return false;
        }
        if(god % 4 == 0)
            return true;
        
        return false;
    }
    int BrojDana(int mjes, int god)
    {
        switch(mjes)
        {
            case 4: case 6: case 9: case 11:
                return 30;
            case 2:
            if(Prestupna(god))
                return 29;
            else
                return 28;
            default:
                return 31;
        }
    }
    public:
    Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana,
    const Datum &datum_prodaje, const Kupac &kupac_stana,
    const Stan &kupljeni_stan): DatumProdaje(datum_prodaje), KupacStana(kupac_stana), KupljeniStan(kupljeni_stan)
    {
        ImeAgenta = ime_agenta_prodaje;
        CijenaStana = cijena_stana;
    }
    Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana,
     int dan_prodaje, int mjesec_prodaje, int godina_prodaje,
     std::string &ime_kupca, const Datum &datum_rodjenja_kupca,
    const std::string &adresa_stana, int sprat_stana, int broj_soba,
     bool namjesten_stan, double broj_kvadrata): DatumProdaje(dan_prodaje, mjesec_prodaje, godina_prodaje), 
        KupacStana(ime_kupca, datum_rodjenja_kupca), KupljeniStan(adresa_stana, sprat_stana, broj_soba, namjesten_stan, broj_kvadrata)
    {
        ImeAgenta = ime_agenta_prodaje;
        CijenaStana = cijena_stana;
        //DatumProdaje(dan_prodaje, mjesec_prodaje, godina_prodaje);
        //KupacStana(ime_kupca, datum_rodjenja_kupca);
        //KupljeniStan(adresa_stana, sprat_stana, broj_soba, namjesten_stan, broj_kvadrata);
    }
    void PromijeniKupca(const Kupac &novi_kupac)
    {
        KupacStana.Postavi(novi_kupac.DajImePrezime(), novi_kupac.DajDatumRodjenja());
    }
    void PromijeniStan(const Stan &novi_stan)
    {
        KupljeniStan.Postavi(novi_stan.DajAdresu(), novi_stan.DajSprat(), novi_stan.DajBrojSoba(), 
            novi_stan.DajNamjesten(), novi_stan.DajKvadraturu());
    }
    void PromijeniDatumKupovine(const Datum &novi_datum)
    {
        DatumProdaje.Postavi(novi_datum.DajDan(), novi_datum.DajMjesec(), novi_datum.DajGodinu());
    }
    void PromijeniCijenuProdaje(const double &nova_cijena)
    {
        CijenaStana = nova_cijena;
    }
    void PomjeriDanUnaprijed();
    void PomjeriDanUnazad();
    std::string DajImeAgenta() const { return ImeAgenta;}
    std::string DajImeKupca() const { return KupacStana.DajImePrezime();}
    Datum DajDatumProdaje() const { return DatumProdaje;}
    double DajCijenuStana() const { return CijenaStana;}
    friend bool ProdatPrije(const Prodaja &p1, const Prodaja &p2);
    friend bool SkupljiStan(const Prodaja &p1, const Prodaja &p2)
    {
        return p1.DajCijenuStana() < p2.DajCijenuStana();
    }
    void Ispisi() const;

};
void Prodaja::Ispisi() const
{
    std::cout << std::left << std::setw(32) << "Ime agenta: " << ImeAgenta << std::endl;
    std::cout << std::setw(32) << "Ime kupca: ";
    KupacStana.Ispisi();
    std::cout << std::endl;
    std::cout << std::setw(32) << "Zakazani datum prodaje: ";
    DatumProdaje.Ispisi();
    std::cout << std::endl;
    std::cout << std::setw(32) << "Cijena stana: " << CijenaStana << std::endl;
    std::cout << "Informacije o stanu: " << std::endl;
    KupljeniStan.Ispisi();
}
bool ProdatPrije(const Prodaja &p1, const Prodaja &p2)
{
    if(p1.DatumProdaje.DajGodinu() == p2.DatumProdaje.DajGodinu())
    {
        if(p1.DatumProdaje.DajMjesec() == p2.DatumProdaje.DajMjesec())
        {
            if(p1.DatumProdaje.DajDan() < p2.DatumProdaje.DajDan())
                return true;
            else
                return false;
        }
        else
            return p1.DatumProdaje.DajMjesec() < p2.DatumProdaje.DajMjesec();
    }
    else
        return p1.DatumProdaje.DajGodinu() < p2.DatumProdaje.DajGodinu();
}
void Prodaja::PomjeriDanUnaprijed()
{
    int godina = DatumProdaje.DajGodinu();
    int mjesec = DatumProdaje.DajMjesec();
    int dan = DatumProdaje.DajDan();
    if(dan == BrojDana(mjesec, godina))
    {
            dan = 1;
            if(mjesec == 12)
            {
                godina++;
                mjesec = 1;
            }
            else
                mjesec++;
    }
    else
        dan++;
    DatumProdaje.Postavi(dan, mjesec, godina);
    
}
void Prodaja::PomjeriDanUnazad()
{
    int godina = DatumProdaje.DajGodinu();
    int mjesec = DatumProdaje.DajMjesec();
    int dan = DatumProdaje.DajDan();
    if(dan == 1)
    {
            if(mjesec == 1)
            {
                godina--;
                mjesec = 12;
            }
            else
                mjesec--;
            dan = BrojDana(mjesec, godina);
    }
    else
        dan--;
    DatumProdaje.Postavi(dan, mjesec, godina);
}

class Prodaje
{
    int BrojProdaja = 0;
    std::vector<std::shared_ptr<Prodaja>> pok;
    int IstiDatumi(Datum d1, Datum d2)
    {
        if(d1.DajGodinu() == d2.DajGodinu())
            if(d1.DajMjesec() == d2.DajMjesec())
                if(d1.DajDan() == d2.DajDan())
                    return 1;
        return 0;
    }
    public:
    explicit Prodaje(int max_broj_prodaja){}
    Prodaje(std::initializer_list<Prodaja> spisak_prodaja);
    ~Prodaje(){}
    Prodaje(const Prodaje &prodaje);
    Prodaje(Prodaje &&prodaje);
    Prodaje &operator =(const Prodaje &prodaje);
    Prodaje &operator =(Prodaje &&prodaje);
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje,
     double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana,
    const Stan &kupljeni_stan);
    
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana,
    int dan_prodaje, int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca,
     const Datum &datum_rodjenja_kupca, const std::string &adresa_stana,
     int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata);
     
    void RegistrirajProdaju(std::shared_ptr<Prodaja> prodaja);
    int DajBrojProdaja() const {return BrojProdaja;}
int DajBrojProdajaNaDatum(const Datum &datum) const
    {
        int brojProdajaNaDatum;
        brojProdajaNaDatum = std::count_if(pok.begin(), pok.end(), [&](const std::shared_ptr<Prodaja>& p){
            return datum.DajGodinu() == p->DajDatumProdaje().DajGodinu() && 
            datum.DajMjesec() == p->DajDatumProdaje().DajMjesec() && datum.DajDan() == p->DajDatumProdaje().DajDan();
        });
        return brojProdajaNaDatum;
    }
int DajBrojProdajaOdAgenta(const std::string &ime_agenta) const
    {
        int brojProdajaAgenta;
        brojProdajaAgenta = std::count_if(pok.begin(), pok.end(), [&](const std::shared_ptr<Prodaja>& p){
            return ime_agenta == p->DajImeAgenta();
        });
        return brojProdajaAgenta;
    }
Prodaja &DajNajranijuProdaju()
    {
        return **std::min_element(pok.begin(), pok.end(),
        [](const std::shared_ptr<Prodaja>& p1, const std::shared_ptr<Prodaja>& p2){
            return ProdatPrije(*p1, *p2);
        });   
    }
Prodaja DajNajranijuProdaju() const
    {
        return **std::min_element(pok.begin(), pok.end(),
        [](const std::shared_ptr<Prodaja>& p1, const std::shared_ptr<Prodaja>& p2){
            return ProdatPrije(*p1, *p2);
        }); 
    }
Prodaja &DajNajskupljuProdaju()
    {
        return (**std::max_element(pok.begin(), pok.end(),
        [](const std::shared_ptr<Prodaja>& p1, const std::shared_ptr<Prodaja>& p2){
            return p1->DajCijenuStana() < p2->DajCijenuStana();
        }));
    }
Prodaja DajNajskupljuProdaju() const
    {
        return (**std::max_element(pok.begin(), pok.end(),
        [](const std::shared_ptr<Prodaja>& p1, const std::shared_ptr<Prodaja>& p2){
            return p1->DajCijenuStana() < p2->DajCijenuStana();
        }));
    }
    void IsprazniKolekciju();
    void ObrisiNajranijuProdaju()
    {
        if(BrojProdaja == 0)
            throw std::range_error("Prazna kolekcija");
        auto& prva = DajNajranijuProdaju();
        for(int i(0); i < BrojProdaja; i++)
        {
            if(IstiDatumi(pok[i]->DajDatumProdaje(), prva.DajDatumProdaje()))
            {
                pok.erase(pok.begin() + i);
                BrojProdaja--;
                return;
            }
        }
    }
    void ObrisiProdajeAgenta(const std::string &ime_agenta); 
    void ObrisiProdajeNaDatum(const Datum &datum);
    void IspisiProdajeNaDatum(const Datum &datum) const
    {
        std::for_each(pok.begin(), pok.end(), [&](const std::shared_ptr<Prodaja>& p)
        {
            const Datum& dan = p->DajDatumProdaje();
            if(dan.DajDan() == datum.DajDan() && dan.DajMjesec() == datum.DajMjesec() &&
            dan.DajGodinu() == datum.DajGodinu())
            {
                p->Ispisi();
                std::cout << std::endl;
            }
        });   
    }
    void IspisiSveProdaje() const
    {
        std::for_each(pok.begin(), pok.end(), [](const std::shared_ptr<Prodaja>& p)
        {
            p->Ispisi();
            std::cout << std::endl;
        });
    }
    Prodaja& DajProdaju(int brojProdaje)
    {
        if( brojProdaje < 0 && brojProdaje > BrojProdaja)
            throw std::range_error("Pogresan paramatar funkcije!");
        return *pok[brojProdaje];
    }
};

Prodaje::Prodaje(std::initializer_list<Prodaja> spisak_prodaja): BrojProdaja(spisak_prodaja.size())
{
    try
    {
        
        for(auto i = spisak_prodaja.begin(); i != spisak_prodaja.end(); i++)
        {
            pok.emplace_back(std::make_shared<Prodaja>(*i));
        }
    }
    catch(std::bad_alloc)
    {
        pok.resize(0);
        BrojProdaja = 0;
        throw;
    }
}
void Prodaje::RegistrirajProdaju(const std::string &ime_agenta_prodaje,
 double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana,
const Stan &kupljeni_stan)
{
    pok.emplace_back(std::make_shared<Prodaja>(ime_agenta_prodaje, cijena_stana, datum_prodaje, kupac_stana, kupljeni_stan));
    BrojProdaja++;
}
void Prodaje::RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana,
int dan_prodaje, int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca,
 const Datum &datum_rodjenja_kupca, const std::string &adresa_stana,
 int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata)
{
    pok.emplace_back(std::make_shared<Prodaja>(ime_agenta_prodaje, cijena_stana, dan_prodaje, mjesec_prodaje, godina_prodaje, 
    ime_kupca, datum_rodjenja_kupca, adresa_stana, sprat_stana, broj_soba, namjesten_stan, broj_kvadrata));  
    BrojProdaja++;
}
void Prodaje::RegistrirajProdaju(std::shared_ptr<Prodaja> prodaja)
{
    pok.emplace_back(prodaja);
    BrojProdaja++;
}
void Prodaje::IsprazniKolekciju()
{
    pok.resize(0);
    BrojProdaja = 0;
}
Prodaje::Prodaje(const Prodaje &prodaje): BrojProdaja(prodaje.BrojProdaja)
{
    try
    {
        
        for(int i(0); i < BrojProdaja; i++)
            pok.emplace_back(std::make_shared<Prodaja>(*prodaje.pok[i]));
    }
    catch(std::bad_alloc)
    {
        pok.resize(0);
        BrojProdaja = 0;
        throw;
    }
}
Prodaje::Prodaje(Prodaje &&prodaje): BrojProdaja(prodaje.BrojProdaja)
{
    pok = prodaje.pok;
    prodaje.pok.resize(0);
}
Prodaje &Prodaje::operator =(const Prodaje &prodaje)
{
    if(&prodaje == this) return *this;
    pok.resize(0);
    BrojProdaja = prodaje.BrojProdaja;
    try
    {
        for(int i(0); i < BrojProdaja; i++)
            pok.emplace_back(std::make_shared<Prodaja>(*prodaje.pok[i]));
    }
    catch(std::bad_alloc)
    {
        pok.resize(0);
        BrojProdaja = 0;
        throw;
    }
    return *this;
}
Prodaje &Prodaje::operator =(Prodaje &&prodaje)
{
    if(&prodaje == this) return *this;
    pok.resize(0);
    BrojProdaja = prodaje.BrojProdaja;
    pok = prodaje.pok;
    prodaje.pok.resize(0);
    return *this;
}
void Prodaje::ObrisiProdajeAgenta(const std::string &ime_agenta)
{
    for(int i(0); i < pok.size(); i++)
    {
        if(pok[i]->DajImeAgenta() == ime_agenta)
        {
            pok.erase(pok.begin() + i);
            i--;
        }
    }
    BrojProdaja = pok.size();
}
void Prodaje::ObrisiProdajeNaDatum(const Datum &datum)
{
    for(int i(0); i < BrojProdaja; i++)
    {
        if(pok[i]->DajDatumProdaje().DajDan() == datum.DajDan() && pok[i]->DajDatumProdaje().DajMjesec() == datum.DajMjesec() &&
            pok[i]->DajDatumProdaje().DajGodinu() == datum.DajGodinu())
        {
            pok.erase(pok.begin() + i);
            i--;
        }
    }
    BrojProdaja = pok.size();
}
int main ()
{
	return 0;
}