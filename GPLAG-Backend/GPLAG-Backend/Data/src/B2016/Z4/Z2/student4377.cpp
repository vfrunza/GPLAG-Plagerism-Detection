/B 2016/2017, Zadaća 4, Zadatak 2
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <string>
#include <stdexcept>

class GradjaninBiH
{
    public:
    enum Pol {Musko, Zensko};
    GradjaninBiH(std::string ime_i_prezime, long long int jmbg);
    GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol);
    GradjaninBiH(const GradjaninBiH &r) = delete;
    GradjaninBiH &operator =(const GradjaninBiH &r) = delete;
    ~GradjaninBiH();
    
    std::string DajImeIPrezime() const;
    long long int DajJMBG() const;
    int DajDanRodjenja() const;
    int DajMjesecRodjenja() const;
    int DajGodinuRodjenja() const;
    int DajSifruRegije() const;
    Pol DajPol() const;
    void PromijeniImeIPrezime(std::string novo_ime);

    private:
    static GradjaninBiH* spok;
    std::string ime_i_prezime;
    long long int jmbg;
    int dan_rodjenja;
    int mjesec_rodjenja;
    int godina_rodjenja;
    int sifra_regije;
    Pol pol;
    GradjaninBiH* pok;
    
    int BrojCifara(long long int n)
    {
        int brojac(0);
        while(n!=0) { n/=10; brojac++; }
        return brojac;
    }
    
    bool ProvjeriDatum(int dd, int mm, int g)
    {
        bool prestupna(false);
         if((g % 4 == 0 && g % 100 != 0 )|| g % 400 == 0) prestupna = true;
        if(dd < 0 || dd > 31 || mm < 0 || mm > 12) return false;
        else if(mm == 1 && dd > 31) return false;
        else if(prestupna && mm == 2 && dd > 29) return false;
        else if (mm == 2 && dd>28) return false;
        else if(mm == 3 && dd > 31) return false;
        else if(mm == 4 && dd > 30) return false;
        else if(mm == 5 && dd > 31) return false;
        else if(mm == 6 && dd > 30) return false;
        else if(mm == 7 && dd > 31) return false;
        else if(mm == 8 && dd > 31) return false;
        else if(mm == 9 && dd > 30) return false;
        else if(mm == 10 && dd > 31) return false;
        else if(mm == 11 && dd > 30) return false;
        else if(mm == 12 && dd > 31) return false;
        return true;
    }
};

GradjaninBiH* GradjaninBiH::spok = nullptr;

GradjaninBiH::GradjaninBiH(std::string ime_i_prezime, long long int jmbg)
{
    if(BrojCifara(jmbg) < 12 || BrojCifara(jmbg) > 13) throw std::logic_error("JMBG nije validan");
    GradjaninBiH::jmbg = jmbg;
    int JMBG[13];
    for(int i = 12; i >= 0; i--)
    { 
        JMBG[i] = jmbg%10;
        jmbg/=10;
    }
    int izraz (7*(JMBG[0]+JMBG[6]) + 6*(JMBG[1]+JMBG[7]) + 5*(JMBG[2]+JMBG[8]) + 4*(JMBG[3]+JMBG[9]) + 3*(JMBG[4]+JMBG[10]) + 2*(JMBG[5]+JMBG[11]));
    izraz = izraz%11;
    izraz = 11-izraz;
    if(izraz == 11) izraz = 0;
    if(izraz == 10 || izraz != JMBG[12]) throw std::logic_error("JMBG nije validan");
    
    auto p = spok;
    while(p != nullptr)
    {
        if(p->jmbg == GradjaninBiH::jmbg) throw std::logic_error("Vec postoji gradjanin sa istim JMBG");
        p = p->pok;
    }
    
    GradjaninBiH::ime_i_prezime = ime_i_prezime;
    dan_rodjenja = JMBG[0]; dan_rodjenja*=10; dan_rodjenja+=JMBG[1];
    mjesec_rodjenja = JMBG[2]; mjesec_rodjenja*=10; mjesec_rodjenja+=JMBG[3];
    if(JMBG[4] == 0) godina_rodjenja = 2000; else godina_rodjenja = 1900; 
    godina_rodjenja+=JMBG[5]*10; godina_rodjenja+=JMBG[6];
    sifra_regije = JMBG[7]; sifra_regije*=10; sifra_regije+=JMBG[8];
    if(JMBG[9] < 5) pol = Musko;
    else pol = Zensko;
    if(!ProvjeriDatum(dan_rodjenja,mjesec_rodjenja,godina_rodjenja)) throw std::logic_error("JMBG nije validan");
    pok = spok; spok = this;
}

GradjaninBiH::GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol)
{
    if(!ProvjeriDatum(dan_rodjenja,mjesec_rodjenja,godina_rodjenja)) throw std::logic_error("Neispravni podaci");
    int cdan(dan_rodjenja);
    int cmonth(mjesec_rodjenja);
    int cyear(godina_rodjenja-1000);
    int czip(sifra_regije);
    int brojac;
    if(pol == Musko) brojac = 0;
    else brojac = 500;
    
    if(sifra_regije < 0 || sifra_regije > 99) throw std::logic_error("Neispravni podaci");
    auto p = spok;
    while(p != nullptr)
    {
        if(p->sifra_regije == sifra_regije && p->pol == pol && p->dan_rodjenja == dan_rodjenja && p->mjesec_rodjenja == mjesec_rodjenja && p->godina_rodjenja == godina_rodjenja)
        brojac++;
        p = p->pok;
    }
    
    int JMBG[13];
    JMBG[1] = cdan%10; cdan/=10; JMBG[0] = cdan;
    JMBG[3] = cmonth%10; cmonth/=10; JMBG[2] = cmonth;
    JMBG[6] = cyear%10; cyear/=10; JMBG[5] = cyear%10; cyear/=10; JMBG[4] = cyear;
    JMBG[8] = czip%10; czip/=10; JMBG[7] = czip;
    JMBG[11] = brojac%10; brojac/=10; JMBG[10] = brojac%10; brojac/=10; JMBG[9] = brojac;
    int izraz (7*(JMBG[0]+JMBG[6]) + 6*(JMBG[1]+JMBG[7]) + 5*(JMBG[2]+JMBG[8]) + 4*(JMBG[3]+JMBG[9]) + 3*(JMBG[4]+JMBG[10]) + 2*(JMBG[5]+JMBG[11]));
    izraz = izraz%11;
    izraz = 11-izraz;
    if(izraz == 11) izraz = 0;
    JMBG[12] = izraz;
    
    long long int jmbg(0);
    for(int i=0; i<13; i++)
    {
        jmbg += JMBG[i];
        if(i!=12) jmbg*=10;
    }
    
    GradjaninBiH::jmbg = jmbg; 
    GradjaninBiH::ime_i_prezime = ime_i_prezime;
    GradjaninBiH::dan_rodjenja = dan_rodjenja;
    GradjaninBiH::mjesec_rodjenja = mjesec_rodjenja;
    GradjaninBiH::godina_rodjenja = godina_rodjenja;
    GradjaninBiH::sifra_regije = sifra_regije;
    GradjaninBiH::pol = pol;
    pok = spok; spok = this;
    
}


std::string GradjaninBiH::DajImeIPrezime() const
{
    return ime_i_prezime;
}
long long int GradjaninBiH::DajJMBG() const
{
    return jmbg;
}
int GradjaninBiH::DajDanRodjenja() const
{
    return dan_rodjenja;
}
int GradjaninBiH::DajMjesecRodjenja() const
{
    return mjesec_rodjenja;
}
int GradjaninBiH::DajGodinuRodjenja() const
{
    return godina_rodjenja;
}
int GradjaninBiH::DajSifruRegije() const
{
    return sifra_regije;
}
GradjaninBiH::Pol GradjaninBiH::DajPol() const
{
    return pol;
}
void GradjaninBiH::PromijeniImeIPrezime(std::string novo_ime)
{
    ime_i_prezime = novo_ime;
}

/*void GradjaninBiH::Ispisi() const
{
    std::cout << "Ime i prezime: " << ime_i_prezime << std::endl;
    std::cout << "jmbg: " << jmbg << std::endl;
    std::cout << "Datum rodjenja: " << dan_rodjenja << "/" << mjesec_rodjenja << "/" << godina_rodjenja << std::endl;
    std::cout << "Sifra regije: " << sifra_regije << std::endl;
    if(pol == false) std::cout << "Pol: Muski" << std::endl;
    else std::cout << "Pol: Zenski" << std::endl;
}*/
    
GradjaninBiH::~GradjaninBiH()
{
    if(spok == this)
    {
        spok = this->pok;
    }
    else if(this->pok == nullptr)
    {
        auto p(spok);
        while(p->pok->pok != nullptr) p = p->pok;
        p->pok = nullptr;
    }
    else
    {
        auto p(spok);
        while(p->pok != this) p = p->pok;
        p->pok = this->pok;
    }
}

int main ()
{
    GradjaninBiH* pokazivaci[100] {};
    int brojac_gradjana(0);
    try {
        
        std::cout << "Koliko gradjana zelite unijeti po JMBG? \n";
        int n;
        std::cin >> n;
        for(int i=0; i<n; i++)
        {
            std::cout << "Unesite ime i prezime (u istom redu): \n";
            std::string ime, prezime, iip;
            std::cin.ignore(10000, '\n');
            getline(std::cin, iip);
            
            try {
            std::cout << "Unesite JMBG: \n";
            long long int jmb;
            std::cin >> jmb;
            pokazivaci[brojac_gradjana] = new GradjaninBiH (iip, jmb);

            if(pokazivaci[brojac_gradjana]->DajPol() == GradjaninBiH::Musko)
            std::cout << "Unijeli ste gradjanina "<< iip << " rodjenog " << pokazivaci[brojac_gradjana]->DajDanRodjenja()<<"."<<pokazivaci[brojac_gradjana]->DajMjesecRodjenja()<<"."<<pokazivaci[brojac_gradjana]->DajGodinuRodjenja() <<" u regiji "<<pokazivaci[brojac_gradjana]->DajSifruRegije() << ", musko.";
            else
            std::cout << "Unijeli ste gradjanina "<< iip << " rodjenog " << pokazivaci[brojac_gradjana]->DajDanRodjenja()<<"."<<pokazivaci[brojac_gradjana]->DajMjesecRodjenja()<<"."<<pokazivaci[brojac_gradjana]->DajGodinuRodjenja() <<" u regiji "<<pokazivaci[brojac_gradjana]->DajSifruRegije() << ", zensko.";
            std::cout<<std::endl;
            brojac_gradjana++;
            } catch (std::logic_error a) { std::cout << a.what() << std::endl; i--;}
        }
        
        
        std::cout << "Koliko gradjana zelite unijeti po datumu rodjenja, regiji i polu?  \n";
        std::cin >> n;
        for(int i=0; i<n; i++)
        {
            try{
            
            std::cout << "Unesite ime i prezime (u istom redu): \n";
            std::string iip;
            std::cin.ignore(10000, '\n');
            getline(std::cin, iip);
            
            std::cout << "Unesite datum rodjenja (format dd/mm/gggg): \n";
            int dd,mm,gg;
            char znak;
            std::cin >> dd >> znak >> mm >> znak >> gg;
            std::cout << "Unesite sifru regije: \n";
            int sifra;
            std::cin >> sifra;
            std::cin.ignore(10000, '\n');
            std::cout << "Unesite M za musko, Z za zensko: \n";
            char mz;
            std::cin >> mz;
            
            GradjaninBiH::Pol lop(GradjaninBiH::Musko);
            if(mz == 'M' || mz == 'm') lop = GradjaninBiH::Musko;
            else if(mz == 'Z' || mz == 'z') lop = GradjaninBiH::Zensko;
            else { std::cout << "Neispravan unos"; return 0; }
            //std::cout << dd<<"/"<<mm<<"/"<<gg<<std::endl;
            pokazivaci[brojac_gradjana] = new GradjaninBiH (iip, dd,mm,gg,sifra, lop);
            
            std::cout << "Unijeli ste gradjanina "<< iip << " JMBG: " << pokazivaci[brojac_gradjana]->DajJMBG()<<".";
            std::cout<<std::endl;
            brojac_gradjana++;
           
            } catch (std::logic_error a) { std::cout << a.what() << std::endl; i--; }
        }
        
        
    } catch (std::logic_error a) { std::cout << a.what();}
	return 0;
}