/B 2016/2017, Zadaća 4, Zadatak 3
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iomanip>
#include <iostream>
#include <string>
#include <stdexcept>
#include <initializer_list>

class Datum 
{
    int d, m, god;
    public: 
    Datum(int dan, int mjesec, int godina) : d(dan), m(mjesec), god(godina) { Postavi(dan, mjesec, godina); }
    Datum(){Postavi(d,m,god);}
    void Postavi(int dan, int mjesec, int godina);
    int DajDan() const { return d; }
    int DajMjesec() const { return m; }
    int DajGodinu() const { return god; }
    void Ispisi() const 
    {
        std::cout << d << "/" << m << "/" << god;
    }
};
class Kupac
{
    std::string ime_kupca;
    Datum dat_rodj;
    public:
    Kupac(const std::string &ime_i_prezime, const Datum &datum_rodjenja) : ime_kupca(ime_i_prezime), dat_rodj(datum_rodjenja) { Postavi(ime_i_prezime, datum_rodjenja); }
    Kupac(){Postavi(ime_kupca, dat_rodj);}
    void Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja);
    std::string DajImePrezime() const { return ime_kupca; }
    Datum DajDatumRodjenja() const { return dat_rodj; }
    void Ispisi() const
    {
        std::cout << ime_kupca << " (" ;
        dat_rodj.Ispisi();
        std::cout << ")" ;
    }
};
class Stan 
{
    std::string adresaa;
    int spratt;
    int broj_sobaa;
    bool namjestenn;
    double kvadraturaa;
    public:
    Stan(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura) : adresaa(adresa), spratt(sprat), broj_sobaa(broj_soba), namjestenn(namjesten), kvadraturaa(kvadratura)
    {
        Postavi(adresa, sprat, broj_soba, namjesten, kvadratura);
    }
    Stan(){Postavi(adresaa, spratt, broj_sobaa, namjestenn, kvadraturaa);}
    void Postavi(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura);
    std::string DajAdresu() const { return adresaa; }
    int DajSprat() const { return spratt; }
    int DajBrojSoba() const { return broj_sobaa; }
    bool DajNamjesten() const { return namjestenn; }
    double DajKvadraturu() const { return kvadraturaa; }
    void Ispisi() const
    {
        std::cout << "Stan se nalazi na adresi " << adresaa << " na " << spratt << " spratu i ima " << broj_sobaa << " soba." << std::endl;
        if (namjestenn == false) std::cout << "Kvadratura stana je " << kvadraturaa << " (m^2) i stan nije namjesten";
        else std::cout << "Kvadratura stana je " << kvadraturaa << " (m^2) i stan je namjesten";
    }
};
class Prodaja
{
    std::string ime_agenta, ime;
    double cijena;
    Datum dat_prod, dat_rod_kup, dat_kup;
    Kupac kupac, novi_k;
    Stan kupljen, novi;
    int dan_pr, mjesec_pr, god_pr;
    public:
    Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan);
    Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata);
    void PromijeniKupca(const Kupac &novi_kupac) { novi_k = novi_kupac;}
    void PromijeniStan(const Stan &novi_stan) {novi = novi_stan; }
    void PromijeniDatumKupovine(const Datum &novi_datum) {dat_kup = novi_datum;}
    void PromijeniCijenuProdaje(const double &nova_cijena) {cijena = nova_cijena; }
    void PomjeriDanUnaprijed() { dan_pr += 1;}
    void PomjeriDanUnazad() {dan_pr -= 1;}
    std::string DajImeAgenta() const { return ime_agenta; }
    std::string DajImeKupca() const { return ime; }
    Datum DajDatumProdaje() const { return dat_prod; }
    double DajCijenuStana() const { return cijena; }
    friend bool ProdatPrije(const Prodaja &p1, const Prodaja &p2); //{ if(p1.DajDatumProdaje() != p2.DajDatumProdaje()) return true; else return false; }
    friend bool SkupljiStan(const Prodaja &p1, const Prodaja &p2); //{ if(p1.DajDatumProdaje() != p2.DajDatumProdaje()) return true; else return false; }
    void Ispisi() const
    {
        std::cout << "Ime agenta: " << ime_agenta << std::endl;
        std::cout << "Ime kupca: ";
        kupac.Ispisi();
        std::cout << std::endl;
        std::cout << "Zakazani datum prodaje: ";
        dat_prod.Ispisi();
        std::cout << std::endl;
        std::cout << "Cijena stana:" << cijena;
        std::cout << "Informacije o stanu: " << std::endl;
        kupljen.Ispisi();
    }
};
class Prodaje
{
    int br_prodaja, br_prodaja_na_datum, br_prodaja_od_agenta;
    int max_br_prod;
    Prodaja spisak;
    public:
    explicit Prodaje(int max_broj_prodaja);
    Prodaje(std::initializer_list<Prodaja> spisak_prodaja);
    ~Prodaje();
    Prodaje(const Prodaje &prodaje);
    Prodaje(Prodaje &&prodaje);
    Prodaje &operator =(const Prodaje &prodaje);
    Prodaje &operator =(Prodaje &&prodaje);
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan);
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata);
    void RegistrirajProdaju(Prodaja *prodaja);
    int DajBrojProdaja() const { return br_prodaja; }
    int DajBrojProdajaNaDatum(const Datum &datum) const { return br_prodaja_na_datum; }
    int DajBrojProdajaOdAgenta(const std::string &ime_agenta) const { return br_prodaja_od_agenta; }
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
};

void Datum::Postavi(int dan, int mjesec, int godina)
{
    int br_dana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if ((godina%4 == 0 && godina%100 != 0) || godina%400 == 0) br_dana[1]++;
    if (godina < 1 ) throw std::domain_error ("Neispravan unos datuma.");
    if (mjesec < 1 && mjesec > 12) throw std::domain_error ("Neispravan unos datuma."); 
    if (dan < 1 && dan > br_dana[mjesec - 1]) throw std::domain_error ("Neispravan unos datuma.");
    this->d = dan;
    this->m = mjesec;
    this->god = godina;
}
void Kupac::Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja)
{
    if ((ime_i_prezime < "A" && ime_i_prezime > "Z") || (ime_i_prezime < "a" && ime_i_prezime > "z")) throw std::domain_error ("Neispravno ime i prezime.");
    if ((ime_i_prezime < "0" && ime_i_prezime > "9")) throw std::domain_error ("Neispravno ime i prezime.");
    //if ((ime_i_prezime != " " || ime_i_prezime != "'" ||  ime_i_prezime != "-")) throw std::domain_error ("Neispravno ime i prezime.");
    this->ime_kupca = ime_i_prezime;
    this->dat_rodj = datum_rodjenja;
}
void Stan::Postavi(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura)
{
    if (sprat < 0 || broj_soba < 0 || kvadratura < 0) throw std::domain_error ("Neispravan unos podataka. ");
    this->adresaa = adresa;
    this->spratt = sprat;
    this->broj_sobaa = broj_soba;
    this->namjestenn = namjesten;
    this->kvadraturaa = kvadratura;
}
Prodaja::Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan)
{
    ime_agenta = ime_agenta_prodaje;
    cijena = cijena_stana;
    this->dat_prod = datum_prodaje;
    this->kupac = kupac_stana;
    this->kupljen = kupljeni_stan;
}
Prodaja::Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata) :
dat_prod(dan_prodaje, mjesec_prodaje, godina_prodaje), kupac(ime_kupca, datum_rodjenja_kupca), kupljen(adresa_stana, sprat_stana, broj_soba, namjesten_stan, broj_kvadrata)
{
    ime_agenta = ime_agenta_prodaje;
    cijena = cijena_stana;
}
//Prodaje::Prodaje(int max_broj_prodaja) : max_br_prod(max_broj_prodaja), br_prodaja(0), br_prodaja_na_datum(0), br_prodaja_od_agenta(0), spisak(new int[max_broj_prodaja]) {}
//Prodaje::Prodaje(std::initializer_list<Prodaja> spisak_prodaja),  max_br_prod(spisak_prodaja.size()), br_prodaja(0), br_prodaja_na_datum(0), br_prodaja_od_agenta(0), spisak(new Poodaja[spisak_prodaja.size()]) {}


int main()
{
    std::cout << "Dobrodosli!" << std::endl << std::endl;
    int unos, unos2, unos3;
    std::string adresa1;
    int sprat1;
    int br_soba;
    bool namjesten1;
    double kvadratura1;
    int brojac(0), brojac1(0);
    std::string ime_prezime;
    int dann, mjesecc, godinaa;
    Datum unos_d(dann, mjesecc, godinaa);
    Kupac unos_k (ime_prezime, unos_d);
    Stan unos_s (adresa1, sprat1, br_soba, namjesten1, kvadratura1);
    
    do
    {
         std::cout << "Izaberite opciju: " << std::endl;
         std::cout << "0 - kraj" << std::endl;
         std::cout << "1 - uredjivanje stanova" << std::endl;
         std::cout << "2 - uredjivanje kupca" << std::endl;
         std::cout << "3 - uredjivanje prodaja" << std::endl;
         std::cin >> unos;
         if (unos == 0) return 0;
         if (unos == 1) 
         {
             do
             {
                 std::cout << "Izaberite opciju: " << std::endl;
                 std::cout << "0 - nazad" << std::endl;
                 std::cout << "1 - dodavanje stana" << std::endl;
                 std::cout << "2 - uredjivanje stanova" << std::endl;
                 std::cout << "3 - ispis svih stanova" << std::endl;
                 std::cout << "4 - kraj" << std::endl;
                 std::cin >> unos2;
                 if (unos2 == 0) return unos;
                 if (unos2 == 1)
                 {
                     do
                     {
                     try
                     {
                         std::cout << "Unesite adresu: ";
                         std::cin >> adresa1;
                         std::cout << "Unesite sprat: ";
                         std::cin >> sprat1;
                         std::cout << "Unesite broj soba: ";
                         std::cin >> br_soba;
                         std::cout << "Da li je stan namjesten (1 - da, 0 - ne): ";
                         std::cin >> namjesten1;
                         std::cout << "Unesite kvadraturu: ";
                         std::cin >> kvadratura1;
                         unos_s.Postavi(adresa1, sprat1, br_soba, namjesten1, kvadratura1);
                         brojac++;
                      }
                      catch (std::domain_error izuzetak)
                      {
                          std::cout << "Izuzetak: " << izuzetak.what() << "Molimo unesite opet." << std::endl;
                          
                      }
                     
                     } while (sprat1 < 0 || br_soba < 0 || kvadratura1 < 0);
                     std::cout << "Stan je uspijesno dodan.";
                 }
                 if (unos2 == 2)
                 {
                     std::cout << "Odaberite stan. Dostupni stanovi su: " << std::endl;
                     for (int i(1); i<=brojac; i++)
                     {
                         std::cout << i << " - ";
                         unos_s.Postavi(adresa1, sprat1, br_soba, namjesten1, kvadratura1);
                         unos_s.Ispisi();
                     }
                     
                      do
                             {
                             std::cout << "Odaberite polje koji zelite urediti: " << std::endl;
                             std::cout << "0 - nazad" << std::endl;
                             std::cout << "1 - adresa" << std::endl;
                             std::cout << "2 - sprat" << std::endl;
                             std::cout << "3 - broj soba" << std::endl;
                             std::cout << "4 - da li je stan namjesten" << std::endl;
                             std::cout << "5 - kvadratura" << std::endl;
                             std::cout << "6 - sve" << std::endl;
                             std::cin >> unos3;
                             if (unos3 == 0) return unos2;
                             if (unos3 == 1)
                             {
                                 std::cout << "Unesite adresu: ";
                                 std::cin >> adresa1;
                             }
                             if (unos3 == 2)
                             {
                                 do
                                 {
                                 try
                                 {
                                     std::cout << "Unesite kvadraturu: ";
                                     std::cin >> sprat1;
                                 }
                                 catch (std::domain_error izuzetak)
                                 {
                                     std::cout << "Izuzetak: " << izuzetak.what() << " Molimo unesite opet.";
                                 }
                                 }while(sprat1 < 0);
                                 std::cout << "Stan je uspjesno izmijenjen!";
                             }
                             if (unos3 == 3)
                             {
                                 do
                                 {
                                 try
                                 {
                                     std::cout << "Unesite kvadraturu: ";
                                     std::cin >> br_soba;
                                 }
                                 catch (std::domain_error izuzetak)
                                 {
                                     std::cout << "Izuzetak: " << izuzetak.what() << " Molimo unesite opet.";
                                 }
                                 }while (br_soba < 0);
                                 std::cout << "Stan je uspjesno izmijenjen!";
                             }
                             if (unos3 == 4)
                             {
                                 std::cout << "Da li je stan namjesten (1 - da, 0 - ne): ";
                                 std::cin >> namjesten1;
                             }
                             if (unos3 == 5)
                             {
                                 do
                                 {
                                 try
                                 {
                                     std::cout << "Unesite kvadraturu: ";
                                     std::cin >> kvadratura1;
                                 }
                                 catch (std::domain_error izuzetak)
                                 {
                                     std::cout << "Izuzetak: " << izuzetak.what() << " Molimo unesite opet.";
                                 }
                                 }while(kvadratura1 < 0);
                                 std::cout << "Stan je uspjesno izmijenjen!";
                             }
                             if (unos3 == 6)
                             {
                                 do
                                 {
                                 try
                                 {
                                     std::cout << "Unesite adresu: ";
                                     std::cin >> adresa1;
                                     std::cout << "Unesite sprat: ";
                                     std::cin >> sprat1;
                                     std::cout << "Unesite broj soba: ";
                                     std::cin >> br_soba;
                                     std::cout << "Da li je stan namjesten (1 - da, 0 - ne): ";
                                     std::cin >> namjesten1;
                                     std::cout << "Unesite kvadraturu: ";
                                     std::cin >> kvadratura1;
                                     unos_s.Postavi(adresa1, sprat1, br_soba, namjesten1, kvadratura1);
                                  }
                                  catch (std::domain_error izuzetak)
                                  {
                                      std::cout << "Izuzetak: " << izuzetak.what() << "Molimo unesite opet.";
                                  }
                                 } while (sprat1 < 0 || br_soba < 0 || kvadratura1 < 0);
                                 std::cout << "Stan je uspijesno izmjenjen.";
                             }
                             }while (unos3 == 0);
                 }
                 if (unos2 == 3)
                 {
                     for (int i(0); i<brojac; i++)
                     {
                         std::cout << i+1 << ". ";
                         unos_s.Postavi(adresa1, sprat1, br_soba, namjesten1, kvadratura1);
                         unos_s.Ispisi();
                     }
                 }
             }while (unos2 == 4);
             
         }
         if (unos == 2) 
         {
             do
             {
                 std::cout << "Izaberite opciju: " << std::endl;
                 std::cout << "0 - nazad" << std::endl;
                 std::cout << "1 - dodavanje kupca" << std::endl;
                 std::cout << "2 - uredjivanje kupaca" << std::endl;
                 std::cout << "3 - ispis svih kupaca" << std::endl;
                 std::cout << "4 - kraj" << std::endl;
                 if (unos2 == 0) return unos;
                 if (unos2 == 1)
                 {
                     std::cout << "Unesite ime i prezime kupca: ";
                     std::cin >> ime_prezime;
                     do
                     {
                     try
                     {
                         std::cout << "Unesite datum rodjenja (formata d/m/g): ";
                         //std::cin >> dan; std::cout << "/"; std::cin >> mjesec; std::cout << "/"; std::cin >> godina;
                         std::cin >> dann >> mjesecc >> godinaa;
                         unos_d.Postavi(dann, mjesecc, godinaa);
                         unos_k.Postavi(ime_prezime, unos_d);
                         brojac1++;
                     }
                     catch (std::domain_error izuzetak)
                     {
                         std::cout << "Izuzetak: " << izuzetak.what() << " Molimo unesite opet.";
                     }
                     }while (dann<1 || dann>31 || mjesecc<1 || mjesecc>12 || godinaa<1);
                     std::cout << "Kupac je uspijesno dodan. ";
                 }
                 if (unos2 == 2)
                 {
                     std::cout << "Odaberite kupca kojeg zelite urediti. Dostupni kupci su: ";
                     for (int i(1); i<=brojac1; i++)
                     {
                         std::cout << i << " - ";
                         unos_k.Ispisi();
                         if (std::cin >> i)
                         {
                             std::cout << "Unesite ime i prezime kupca: ";
                             std::cin >> ime_prezime;
                             do
                             {
                             try
                             {
                                 std::cout << "Unesite datum rodjenja (formata d/m/g): ";
                                 //std::cin >> dan; std::cout << "/"; std::cin >> mjesec; std::cout << "/"; std::cin >> godina;
                                 std::cin >> dann >> mjesecc >> godinaa;
                                 unos_d.Postavi(dann, mjesecc, godinaa);
                                 unos_k.Postavi(ime_prezime, unos_d);
                             }
                             catch (std::domain_error izuzetak)
                             {
                                 std::cout << "Izuzetak: " << izuzetak.what() << " Molimo unesite opet.";
                             }
                             }while (dann<1 || dann>31 || mjesecc<1 || mjesecc>12 || godinaa<1);
                             std::cout << "Kupac je uspjesno izmijenjen!";
                         }
                     }
                 }
                 if (unos2 == 3)
                 {
                     for (int i(0); i<brojac1; i++)
                     {
                         std::cout << i+1 << ". ";
                        unos_k.Ispisi();
                     }
                 }
             
            } while (unos == 4);
         }
    }while (unos == 0);
    std::cout << std::endl << std::endl << "Dovidjenja!";
    
    return 0;
}