#include <iostream>
#include <string>
#include <stdexcept>

class GradjaninBiH
{
    std::string ime_i_prezime;
    int dan_rodjenja;
    int mjesec_rodjenja;
    int godina_rodjenja;
    int sifra_regije;
    int kod_pola;
    int kontrolna_sifra;
    GradjaninBiH* prethodni;
    static GradjaninBiH* dijeljenji;
    bool Provjera_gradjana_jmbg (long long int jmbg);
    int Odabir_koda (const GradjaninBiH &g, int drugi_odabir);
    long long int Napravi_jmbg_bez_ks () const;
public:
    enum Pol {Musko, Zensko};
    GradjaninBiH(const GradjaninBiH &g) = delete;
    GradjaninBiH &operator = (const GradjaninBiH &g) = delete; 
    GradjaninBiH(std::string ime_i_prezime, long long int jmbg);
    GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja,
    int godina_rodjenja, int sifra_regije, Pol pol);
    ~GradjaninBiH();
    std::string DajImeIPrezime() const;
    long long int DajJMBG() const;
    int DajDanRodjenja() const;
    int DajMjesecRodjenja() const;
    int DajGodinuRodjenja() const;
    int DajSifruRegije() const;
    Pol DajPol() const;
    void PromijeniImeIPrezime(std::string novo_ime);
};

GradjaninBiH *GradjaninBiH::dijeljenji = nullptr;   ///Deklaracija dijeljenog statickog pokazivaca


bool GradjaninBiH::Provjera_gradjana_jmbg (long long int jmbg)
{
    GradjaninBiH* pomocni = dijeljenji;
    
    while (pomocni!=nullptr)
        {
            if (jmbg == pomocni->DajJMBG())
                return true;
                
            pomocni = pomocni->prethodni;
        }
    
    return false;
}

int GradjaninBiH::Odabir_koda (const GradjaninBiH &g, int drugi_odabir)
{
    int kod = 0;
    if (g.DajPol() == Pol::Zensko)
        kod = 500;
        
    GradjaninBiH* pomocni = dijeljenji;
    while(pomocni != nullptr)
        {
            if (g.DajDanRodjenja() == pomocni->DajDanRodjenja() && g.DajMjesecRodjenja() == pomocni->DajMjesecRodjenja() &&
                g.DajGodinuRodjenja() == pomocni->DajGodinuRodjenja() && g.DajSifruRegije() == pomocni->DajSifruRegije())
                kod++;
            
            pomocni = pomocni->prethodni;
        }
        
    kod+=drugi_odabir;
    
    return kod;
}

long long int GradjaninBiH::Napravi_jmbg_bez_ks () const
{
    long long int rezultat = 0;
    int cifre[12];
    
    int a = 0, b = 0, c = 0;
    int pomocna = dan_rodjenja;
    b = pomocna%10;
    pomocna/=10;
    a = pomocna%10;
    
    cifre[0] = a;
    cifre[1] = b;
    
    pomocna = mjesec_rodjenja;
    b = pomocna%10;
    pomocna/=10;
    a = pomocna%10;
    
    cifre[2] = a;
    cifre[3] = b;
    pomocna = godina_rodjenja;
    c = pomocna%10;
    pomocna/=10;
    b = pomocna%10;
    pomocna/=10;
    a = pomocna%10;
    
    cifre[4] = a;
    cifre[5] = b;
    cifre[6] = c;
    
    pomocna = sifra_regije;
    b = pomocna%10;
    pomocna/=10;
    a = pomocna%10;
    
    cifre[7] = a;
    cifre[8] = b;
    
    pomocna = kod_pola;
    c = pomocna%10;
    pomocna/=10;
    b = pomocna%10;
    pomocna/=10;
    a = pomocna%10;
    
    cifre[9] = a;
    cifre[10] = b;
    cifre[11] = c;
    
    for (int i{};i<12;i++)
        {
            rezultat = rezultat*10+cifre[i];
        }
        
    return rezultat;
}




GradjaninBiH::GradjaninBiH(std::string ime_i_prezime, long long int jmbg)
{
    int dan_rodjenja = 0;
    int mjesec_rodjenja = 0;
    int godina_rodjenja = 0;
    int sifra_regije = 0;
    int kod_pola = 0;
    int kontrolna_sifra = 0;
    
    /*Provjera na ispravnost JMBG */
    
    if (jmbg<0)
        throw std::logic_error ("JMBG nije validan");
    
    int broj_cifara = 0;
    long long int kopija = jmbg;
    while(kopija>0)
        {
            broj_cifara++;
            kopija/=10;
        }
    
    if (broj_cifara<12 || broj_cifara>13)
        throw std::logic_error ("JMBG nije validan");
    
    kopija = jmbg;
    int cifre[13];
    for (int i{12};i>=0;i--)
        {
            int a = kopija%10;
            cifre[i] = a;
            kopija/=10;
        }
        
    kopija = jmbg;
    
    /*Izvlacenje podataka iz jmbg */
    
    kontrolna_sifra = jmbg%10;          ///c13
    jmbg/=10;
    
    int pomocna = 0;                    ///c10c11c12
    for (int i{};i<3;i++)
        {
            int a = jmbg%10;
            pomocna = pomocna*10+a;
            jmbg/=10;
        }
    
    for (int i{};i<3;i++)
    {
        int a = pomocna%10;
        kod_pola = kod_pola*10+a;
        pomocna/=10;
    }
    
    pomocna = 0;                        ///c8c9
    for (int i{};i<2;i++)
    {
        int a = jmbg%10;
        pomocna = pomocna*10+a;
        jmbg/=10;
    }
    
    for (int i{};i<2;i++)
    {
        int a = pomocna%10;
        sifra_regije = sifra_regije*10+a;
        pomocna/=10;
    }
    
    pomocna = 0;                        ///c5c6c7
    for (int i{};i<3;i++)
    {
        int a = jmbg%10;
        pomocna = pomocna*10+a;
        jmbg/=10;
    }
    
    for (int i{};i<3;i++)
    {
        int a = pomocna%10;
        godina_rodjenja = godina_rodjenja*10+a;
        pomocna/=10;
    }
    
    pomocna = 0;                     ///c3c4
    for (int i{};i<2;i++)
    {
        int a = jmbg%10;
        pomocna = pomocna*10+a;
        jmbg/=10;
    }
    
    for (int i{};i<2;i++)
    {
        int a = pomocna%10;
        mjesec_rodjenja = mjesec_rodjenja*10+a;
        pomocna/=10;
    }
    
    pomocna = 0;                    ///c1c2
    for (int i{};i<2;i++)
    {
        int a = jmbg%10;
        pomocna = pomocna*10+a;
        jmbg/=10;
    }
    
    for (int i{};i<2;i++)
    {
        int a = pomocna%10;
        dan_rodjenja = dan_rodjenja*10+a;
        pomocna/=10;
    }
    
    
    /*Testiranje ispravnosti dobivenih podataka iz JMBG*/
    
    if (!((godina_rodjenja>=0 && godina_rodjenja<=17) || (godina_rodjenja>=927 && godina_rodjenja<=999)))
        throw std::logic_error ("JMBG nije validan");
    
    if (mjesec_rodjenja<1 || mjesec_rodjenja>12)
        throw std::logic_error ("JMBG nije validan");
        
    int mjeseci[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if (dan_rodjenja<1 || dan_rodjenja>mjeseci[mjesec_rodjenja-1])
        throw std::logic_error ("JMBG nije validan");
    
    int c13 = 11-(7*(cifre[0]+cifre[6])+6*(cifre[1]+cifre[7])+5*(cifre[2]+cifre[8])+4*(cifre[3]+cifre[9])+3*(cifre[4]+cifre[10])+2*(cifre[5]+cifre[11]))%11;
    
    if (c13 == 11)
        c13 = 0;
        
    if (kontrolna_sifra != c13 || c13 == 10)
        throw std::logic_error ("JMBG nije validan");
    
    if (Provjera_gradjana_jmbg(kopija) == true)
        throw std::logic_error ("Vec postoji gradjanin sa istim JMBG");
    
    GradjaninBiH::ime_i_prezime = ime_i_prezime;
    GradjaninBiH::dan_rodjenja = dan_rodjenja;
    GradjaninBiH::mjesec_rodjenja = mjesec_rodjenja;
    GradjaninBiH::godina_rodjenja = godina_rodjenja;
    GradjaninBiH::sifra_regije = sifra_regije;
    GradjaninBiH::kod_pola = kod_pola;
    GradjaninBiH::kontrolna_sifra = kontrolna_sifra;
    
    if (dijeljenji == nullptr)
        {
            prethodni = nullptr;
            dijeljenji = this;
        }
    else
        {
            prethodni = dijeljenji;
            dijeljenji = this;
        }
}

GradjaninBiH::GradjaninBiH (std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja,
    int godina_rodjenja, int sifra_regije, Pol pol) : kod_pola(0)
{
    if (pol == Pol::Musko)
        kod_pola = 0;
    else
        kod_pola = 500;
        
    int pomocna = 0;
    for (int i{};i<3;i++)
        {
            int a = godina_rodjenja%10;
            pomocna=pomocna*10+a;
            godina_rodjenja/=10;
        }
        
    godina_rodjenja = 0;
    for (int i{};i<3;i++)
        {
            int a = pomocna%10;
            godina_rodjenja = godina_rodjenja*10+a;
            pomocna/=10;
        }
        
    
    if (!((godina_rodjenja>=0 && godina_rodjenja<=17) || (godina_rodjenja>=927 && godina_rodjenja<=999)))
        throw std::logic_error ("Neispravni podaci");
    
    if (mjesec_rodjenja<1 || mjesec_rodjenja>12)
        throw std::logic_error ("Neispravni podaci");
        
    int mjeseci[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if (dan_rodjenja<1 || dan_rodjenja>mjeseci[mjesec_rodjenja-1])
        throw std::logic_error ("Neispravni podaci");
    
    if (sifra_regije<0 || sifra_regije>99)
        throw std::logic_error ("Neispravni podaci");
        
    GradjaninBiH::ime_i_prezime = ime_i_prezime;
    GradjaninBiH::dan_rodjenja = dan_rodjenja;
    GradjaninBiH::mjesec_rodjenja = mjesec_rodjenja;
    GradjaninBiH::godina_rodjenja = godina_rodjenja;
    GradjaninBiH::sifra_regije = sifra_regije;
    
    int c13 = 10;
    int j = 0;
    while (c13 == 10)
    {
        
        kod_pola = Odabir_koda(*this,j);
        long long int kopija = Napravi_jmbg_bez_ks();
        int cifre[12];
        for (int i{11};i>=0;i--)
            {
                int a = kopija%10;
                cifre[i] = a;
                kopija/=10;
            }
        c13 = 11-(7*(cifre[0]+cifre[6])+6*(cifre[1]+cifre[7])+5*(cifre[2]+cifre[8])+4*(cifre[3]+cifre[9])+3*(cifre[4]+cifre[10])+2*(cifre[5]+cifre[11]))%11;
        j++;
    }
    
    if (c13 == 11)
        c13 = 0;
        
    GradjaninBiH::kontrolna_sifra = c13;
    
    if (dijeljenji == nullptr)
        {
            prethodni = nullptr;
            dijeljenji = this;
        }
    else
        {
            prethodni = dijeljenji;
            dijeljenji = this;
        }
}

GradjaninBiH::~GradjaninBiH()
{
    if (this == dijeljenji)
        dijeljenji = dijeljenji->prethodni;
    else if (this->prethodni == nullptr)
        {
            if (dijeljenji!=this)
                {
                    GradjaninBiH* pomocni = dijeljenji;
                    while (pomocni->prethodni != this)
                        pomocni = pomocni->prethodni;
                        
                    pomocni->prethodni = nullptr;
                }
            else
                dijeljenji = nullptr;
        }
    else
        {
            GradjaninBiH* pomocni = dijeljenji;
            GradjaninBiH* pomocni2 = dijeljenji;
            pomocni = pomocni->prethodni;
            
            while (pomocni!=this)
                {
                    pomocni = pomocni->prethodni;
                    pomocni2 = pomocni2->prethodni;
                }
            
            pomocni2->prethodni = pomocni->prethodni;
        }
}

std::string GradjaninBiH::DajImeIPrezime() const
{
    return ime_i_prezime;
}

long long int GradjaninBiH::DajJMBG() const
{
    long long int kopija = Napravi_jmbg_bez_ks();
    kopija = kopija*10+kontrolna_sifra;
    
    return kopija;
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
    if (godina_rodjenja>=927 && godina_rodjenja<=999)
        return 1000+godina_rodjenja;
    
    return 2000+godina_rodjenja;
}

int GradjaninBiH::DajSifruRegije() const
{
    return sifra_regije;
}

GradjaninBiH::Pol GradjaninBiH::DajPol() const
{
    if (kod_pola>=0 && kod_pola<=499)
        return GradjaninBiH::Pol::Musko;
    
    return GradjaninBiH::Pol::Zensko;
}

void GradjaninBiH::PromijeniImeIPrezime(std::string novo_ime)
{
    ime_i_prezime = novo_ime;
}


int main ()
{
    
        std::cout<<"Koliko gradjana zelite unijeti po JMBG? ";
        int n;
        std::cin>>n;
        std::cin.ignore(10000, '\n');
        
        for (int i{};i<n;i++)
            {
                try
                {
                std::cout<<std::endl<<"Unesite ime i prezime (u istom redu): ";
                std::string ime;
                std::getline(std::cin, ime);
                std::cout<<std::endl<<"Unesite JMBG: ";
                long long int jmbg;
                std::cin>>jmbg;
                std::cin.ignore(10000, '\n');
                
                GradjaninBiH rezultat (ime,jmbg);
                std::cout<<std::endl<<"Unijeli ste gradjanina "<<rezultat.DajImeIPrezime()<<" rodjenog "<<rezultat.DajDanRodjenja()<<".";
                std::cout<<rezultat.DajMjesecRodjenja()<<"."<<rezultat.DajGodinuRodjenja()<<" u regiji ";
                std::cout<<rezultat.DajSifruRegije()<<", ";
                if (rezultat.DajPol() == GradjaninBiH::Pol::Musko)
                    std::cout<<"musko.";
                else
                    std::cout<<"zensko.";
                }
                catch (std::logic_error e)
                {
                    std::cout<<std::endl<<e.what();
                    i--;
                }
            }
            
        std::cout<<std::endl<<"Koliko gradjana zelite unijeti po datumu rodjenja, regiji i polu? ";
        std::cin>>n;
        std::cin.ignore(10000, '\n');
        
        for (int i{};i<n;i++)
            {
                try
                {
                    std::cout<<std::endl<<"Unesite ime i prezime (u istom redu): ";
                    std::string ime;
                    std::getline(std::cin,ime);
                    
                    std::cout<<std::endl<<"Unesite datum rodjenja (format dd/mm/gggg): ";
                    int dan,mjesec,godina;
                    char znak;
                    std::cin>>dan>>znak>>mjesec>>znak>>godina;
                    std::cin.ignore(100000, '\n');
                    
                    std::cout<<std::endl<<"Unesite sifru regije: ";
                    int sifra_regije;
                    std::cin>>sifra_regije;
                    std::cin.ignore(10000, '\n');
                    
                    std::cout<<std::endl<<"Unesite M za musko, Z za zensko: ";
                    char c;
                    std::cin>>c;
                    std::cin.ignore(10000, '\n');
                    GradjaninBiH::Pol pol;
                    if (c == 'M')
                        pol = GradjaninBiH::Pol::Musko;
                    else if (c == 'Z')
                        pol = GradjaninBiH::Pol::Zensko;
                    else    
                        throw std::logic_error ("Neispravni podaci");
                        
                    GradjaninBiH rezultat (ime,dan,mjesec,godina,sifra_regije,pol);
                    
                    std::cout<<std::endl<<"Unijeli ste gradjanina "<<rezultat.DajImeIPrezime()<<" JMBG: "<<rezultat.DajJMBG()<<".";
                }
                catch (std::logic_error e)
                {
                    std::cout<<std::endl<<e.what();
                    i--;
                }
            }
        

	return 0;
}