#include <iostream> 
#include <stdexcept>

class Datum {
    
    friend class Kupac;
    int d, m, g;
    
    public: 
    
    Datum (int dan, int mjesec, int godina)
    {
        int broj_dana[] {31,28,31,30,31,30,31,31,30,31,30,31};
        
        if ((godina % 4 == 0 && godina % 100 != 0) || godina % 400 == 0)
        {
            broj_dana[1]++;
        }
        if (godina < 1 || mjesec < 1 || dan < 1 || mjesec > 12 || dan > broj_dana[mjesec-1])
        {
            throw std::domain_error ("Neispravan datum");
        }
        
        this -> d = dan; 
        this -> m = mjesec; 
        this -> g = godina;
    }
    void Postavi (int dan, int mjese, int godina);
    int DajDan() const { return d; }
    int DajMjesec() const { return m; }
    int DajGodinu() const { return g; }
    void Ispisi() const
    {
        std::cout << "(" << d << "/" << m  << "/" << g << ")";
    }
    
};

void Datum::Postavi (int dan, int mjesec, int godina)
{
    int broj_dana[] {31,28,31,30,31,30,31,31,30,31,30,31};
    
    if ((godina % 4 == 0 && godina % 100 != 0) || godina % 400 == 0)
    {
        broj_dana[1]++;
    }
    if (godina < 1 || mjesec < 1 || dan < 1 || mjesec > 12 || dan > broj_dana[mjesec-1])
    {
        throw std::domain_error ("Neispravan datum");
    }
    
    this -> d = dan;
    this -> m = mjesec; 
    this -> g = godina;
}


class Kupac 
{
    std::string ime;
    Datum datum;
    public: 
    
    Kupac (const std::string &ime_i_prezime, const Datum &datum_rodjenja) : datum(datum_rodjenja)
    {
        for (int i = 0; i < ime_i_prezime.length(); i++)
        {
            if (!((ime_i_prezime[i] >= 'a' || ime_i_prezime[i] <= 'z') ||
               (ime_i_prezime[i] >= 'A' || ime_i_prezime[i] <= 'Z') || 
                ime_i_prezime[i] == ' ' || ime_i_prezime[i] == '\n'))
                {
                    throw std::domain_error ("Neispravno ime i prezime");
                }
        }
        
        this -> ime = ime_i_prezime;
        this -> datum = datum_rodjenja;
    }
    void Postavi (const std::string &ime_i_prezime, const Datum &datum_rodjenja);
    std::string DajImePrezime() const { return ime; }
    Datum DajDatumRodjenja() const { return datum; }
    void Ispisi() const
    {
        std::cout << ime << "(" << datum.d << "/" << datum.m << "/" << datum.g << ")";
    }
};

void Kupac::Postavi (const std::string &ime_i_prezime, const Datum &datum_rodjenja)
{
    for (int i = 0; i < ime_i_prezime.length(); i++)
    {
        if (!((ime_i_prezime[i] >= 'a' || ime_i_prezime[i] <= 'z') ||
           (ime_i_prezime[i] >= 'A' || ime_i_prezime[i] <= 'Z') ||
           ime_i_prezime[i] == ' ' || ime_i_prezime[i] == '\n'))
           {
               throw std::domain_error ("Neispravno ime i prezime");
           }
    }
    
    this -> ime = ime_i_prezime;
    this -> datum = datum_rodjenja;
}


class Stan 
{
    std::string a;
    int s;
    int broj;
    bool n;
    double k;
    
    public:
   
   Stan (const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura)
   {
       if (sprat < 0 || broj_soba < 0 || kvadratura < 0)
       {
           throw std::domain_error ("Izuzetak: Neispravan unos podataka. Molimo unesite opet.");
       }
       
       this -> a = adresa;
       this -> s = sprat;
       this -> broj = broj_soba;
       this -> n = namjesten;
       this -> k = kvadratura;
   }
   
   void Postavi (const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura)
   {
       if (sprat < 0 || broj_soba < 0 || kvadratura < 0) 
       {
           throw std::domain_error ("Izuzetak: Neispravan unos podataka. Molimo unesite opet.");
       }
       
       this -> a = adresa;
       this -> s = sprat; 
       this -> broj = broj_soba; 
       this -> n = namjesten; 
       this -> k = kvadratura;
   }
   
   std::string DajAdresu() const { return a; }
   int DajSprat() const { return s; }
   int DajBrojSoba() const { return broj; }
   bool DajNamjesten() const { return n; }
   double DajKvadraturu() const { return k; }
   void Ispisi() const
   {
       if (broj % 10 == 2 || broj % 10 == 3 || broj % 4 == 0)
       {
           std::cout << "Stan se nalazi na adresi " << a << " na " << s << ". spratu i ima "  
           << broj << "sobe.";
       }
       
       else 
       {
           std::cout << "Stan se nalazi na adresi " << a << " na " << s << ". spratu i ima " 
           << broj << "soba.";
       }
       
       if (n == 1)
       {
           std::cout << "Kvadratura stana je " << k << " (m^2) " << "i stan je namjesten.";
       }
       
       if (n == 0)
       {
           std::cout << "Kvadratura stana je " << k << " (m^2) " << "i stan nije namjesten.";
       }
   }
};

class Prodaja 
{
    std::string ime_agenta;
    double cijena;
    Datum datum;
    Kupac kupac;
    Stan stan;
    public: 
    
    Prodaja (const std::string &ime_agenta_prodaje, double cijena_stana,
             const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan);
             
    Prodaja (const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, 
             int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca, 
             const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana,
             int broj_soba, bool namjesten_stan, double broj_kvadrata);
             
    void PromjeniKupca (const Kupac &novi_kupac);
    void PromjeniStan (const Stan &novi_stan);
    void PromjeniDatumKupovine (const Datum &novi_datum);
    void PromjeniCijenuProdaje (const double &nova_cijena);
    void PomjeriDanUnaprijed() const;
    void PomjeriDanUnazad() const;
    std::string DajImeAgenta() const { return ime_agenta; }
    std::string DajImeKupca() const;
    Datum DajDatumProdaje() const;
    double DajCijenuStana() const;
    friend bool ProdatPrije (const Prodaja &p1, const Prodaja &p2);
    friend bool SkupljiStan (const Prodaja &p1, const Prodaja &p2);
    void Ispisi() const;
};


int main() 
{
    try
    {
    int broj;
    std::cout << "Dobrodosli!" << std::endl;
    std::cout << std::endl;
    
    std::cout << "Izaberite opciju: " << std::endl;
    std::cout << "0 - kraj" << std::endl 
              << "1 - uredjivanje stanova" << std::endl 
              << "2 - uredjivanje kupaca" << std::endl
              << "3 - uredjivanje prodaja" << std::endl;
    std::cin >> broj;
    
    if (broj == 0) return 0;
              
    std::cout << "Izaberite opciju: " << std::endl;
    std::cout << "0 - nazad" << std::endl 
              << "1 - dodavanje stana" << std::endl
              << "2 - uredjivanje stanova" << std::endl
              << "3 - ispis svih stanova" << std::endl
              << "4 - kraj" << std::endl;
              
    int sprat, broj_soba;
    
    
    bool namjesten;
    double kvadratura;
    std::string adresa;
              
    for (;;)
    {
        std::cin >> broj;
        if (broj == 1)
        {
        std::cout << "Unesite adresu: "; 
        std::getline (std::cin, adresa);
        std::cin.clear();
        std::cin.ignore (1000000, '\n');
        std::cout << "Unesite sprat: ";
        std::cin >> sprat;
        std::cout << "Unesite broj soba: ";
        std::cin >> broj_soba;
        std::cout << "Da li je stan namjesten (1 - da, 0 - ne): ";
        std::cin >> namjesten;
        std::cout << "Unesite kvadraturu: "; 
        std::cin >> kvadratura;
        Stan s1(adresa,sprat,broj_soba,namjesten,kvadratura);
  
        std::cout << "Stan je uspjesno dodan!";
        
        }
        
        
       
        
        if (broj != 1) break;
    }
    
    }
    
    catch (std::domain_error izuzetak)
    {
        std::cout << izuzetak.what() << std::endl;
    }

    
    return 0;
}