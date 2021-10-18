/B 2016/2017, Zadaća 4, Zadatak 3
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
class Datum
{
    int d, m, g;
    private PostaviDatum(int dan, int mjesec, int godina)
    public:
        Datum (int dan, int mjesec, int godina){PostaviDatum(dan, mjesec,godina);}
        void Postavi(int dan, int mjesec, int godina);
        int DajDan(){return d;}
        int DajMjesec(){return m;}
        int DajGodinu(){return g;}
        void Ispisi(){std::cout<<d<<"/"<<m<<"/"<<g;}
        
}
void Postavi::Datum(int dan, int mjesec, int godina)
{
    int broj_dana[12]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(g%4==0 && g%100!=0 || g%400==0) broj_dana[m-1])
        throw std::domain_error("Neispravan datum!");
    dan = d; mjesec=m; godina=g;
}
class Kupac
{
    std::string ime;
    Datum rodjenje;
    public:
        Kupac(const std::string &ime_i_prezime, const Datum &datum_rodjenja);
        void Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja)
        std::string DajImePrezime() const{return ime;}
        Datum DajDatumRodjenja() const{return rodjenje};
        void Ispisi() const{std::cout<<ime<<" ("<<rodjenje.Ispisi()<<")";}
}
void Kupac::Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja)
{
    for(int i=0; i<ime_i_prezime.length(); i++)
        if((ime_i_prezime[i]<'A' || (ime_i_prezime[i]>'Z' && ime_i_prezime[i]<'a') || ime_i_prezime[i]>'z') && ime_i_prezime[i]!=' ' && ime_i_prezime[i]!='\'' && ime_i_prezime[i]!='-')
            throw std::domain_error("Neispravno ime i prezime");
    ime=ime_i_prezime;
    rodjenje=datum_rodjenja;
}
class Stan
{
    std::string adr;
    int n_sprat, n_soba;
    bool namjesteno;
    double velicina;
    public:
        Stan(const std::string &adresa, int sprat, int broj_soba, bool namjesten,
            double kvadratura);
        void Postavi(const std::string &adresa, int sprat, int broj_soba,
            bool namjesten, double kvadratura);
        std::string DajAdresu() const{return adr;}
        int DajSprat() const{return n_sprat};
        int DajBrojSoba() const{return n_soba};
        bool DajNamjesten() const{return namjesteno};
        double DajKvadraturu() const{return velicina};
        void Ispisi() const{};
}
void Stan::Postavi(const std::string &adresa, int sprat, int broj_soba, 
    bool namjesten, double kvadratura)
    {
        if(sprat<0 || broj_soba<0 || kvadratura<0)  throw("Neispravan unos podataka");
        adr=adresa;
        n_sprat=sprat;
        n_soba=broj_soba;
        namjesteno=namjesten;
        velicina=kvadratura;
    }
void Stan::Ispisi() const
{
    std::cout<<"Stan se nalazi na adresi "<<adr<<" na "<<n_sprat<<". spratu i ima "<<n_soba<<" ";
    if(n_soba%10==1) std::cout<<"sobu."<<std::endl;
    else if(n_soba%10==2 || n_soba%10==3 || n_soba%10==4) std::cout<<"sobe."<<std::endl;
    else std::cout<<"soba."<<std::endl;
    std::cout<<"Kvadratura stana je "<<velicina<<" (m^2) i stan ";
    if(namjesteno) std::cout<<"je namjesten.";
    else std::cout<<"nije namjesten.";
}
class Prodaja
{
    std::string agent;
    double cijena;
    Datum dat_prodaje;
    Kupac kupac;
    Stan stan_kupljen;
    public:
        Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana,
            const Datum &datum_prodaje, const Kupac &kupac_stana,
                const Stan &kupljeni_stan);
        Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana,
            int dan_prodaje, int mjesec_prodaje, int godina_prodaje,
            std::string &ime_kupca, const Datum &datum_rodjenja_kupca,
            const std::string &adresa_stana, int sprat_stana, int broj_soba,
            bool namjesten_stan, double broj_kvadrata);
        void PromijeniKupca(const Kupac &novi_kupac);
        void PromijeniStan(const Stan &novi_stan);
        void PromijeniDatumKupovine(const Datum &novi_datum);
        void PromijeniCijenuProdaje(const double &nova_cijena);
        void PomjeriDanUnaprijed();
        void PomjeriDanUnazad();
        std::string DajImeAgenta() const;
        std::string DajImeKupca() const;
        Datum DajDatumProdaje() const;
        double DajCijenuStana() const;
        friend bool ProdatPrije(const Prodaja &p1, const Prodaja &p2);
        friend bool SkupljiStan(const Prodaja &p1, const Prodaja &p2);
        void Ispisi() const;
        
}
Prodaja::Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana,
                    const Datum &datum_prodaje, const Kupac &kupac_stana,
                        const Stan &kupljeni_stan);
                        {
                            
                        }
int main ()
{
	return 0;
}