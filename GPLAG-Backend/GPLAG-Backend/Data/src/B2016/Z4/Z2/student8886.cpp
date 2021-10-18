/B 2016/2017, Zadaća 4, Zadatak 2
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <string>
#include <stdexcept>

class GradjaninBiH
{
public:
    enum Pol {Musko, Zensko};
private:
    std::string ime_i_prezime;
    long long int jmbg;
    Pol pol;
    int dan_rodjenja, mjesec_rodjenja, godina_rodjenja, sifra_regije, kod;
    bool TestJmbg(long long int jmbg) const;
    static int Formula(int *c);
    static GradjaninBiH *posljednji;
    GradjaninBiH *prethodni;
    bool TestDatuma(int dan, int mjesec, int godina) const;
    bool TestSifreIKoda(int kod, int sifra) const;
    int DajKod() const { return GradjaninBiH::kod; }
public:
    GradjaninBiH(std::string ime_i_prezime, long long int jmbg);
    GradjaninBiH(const GradjaninBiH &g) = delete;  //Zabrana kopiranja
    GradjaninBiH &operator =(const GradjaninBiH &g) = delete;  //Zabrana dodjele
    GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol);
    ~GradjaninBiH();
    std::string DajImeIPrezime() const;
    long long int DajJMBG() const;
    int DajDanRodjenja() const;
    int DajMjesecRodjenja() const;
    int DajGodinuRodjenja() const;
    int DajSifruRegije() const;
    Pol DajPol() const { return GradjaninBiH::pol; }
    void PromijeniImeIPrezime(std::string novo_ime) { GradjaninBiH::ime_i_prezime=novo_ime; }
};

GradjaninBiH *GradjaninBiH::posljednji{};

GradjaninBiH::~GradjaninBiH()
{
    auto pomocni(posljednji);
    if (posljednji==this) posljednji=posljednji->prethodni;
    else 
    {
        while (pomocni->prethodni!=this) pomocni=pomocni->prethodni;
        pomocni->prethodni=this->prethodni;
    }
}

int GradjaninBiH::Formula(int *c)
{
    return 11-(7*(c[0]+c[6])+6*(c[1]+c[7])+5*(c[2]+c[8])+4*(c[3]+c[9])+3*(c[4]+c[10])+2*(c[5]+c[11]))%11;
}

bool GradjaninBiH::TestDatuma(int dan, int mjesec, int godina) const
{
    int broj_dana[12]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (godina%4==0 and godina%100!=0 or godina%400==0) broj_dana[1]++; 
    if (godina<1917 or godina>2017 or mjesec<1 or mjesec>12 or dan<1 or dan>broj_dana[mjesec-1]) return false;
    return true;
}

bool GradjaninBiH::TestSifreIKoda(int kod, int sifra) const
{
    if (kod<0 or kod>999 or sifra<0 or sifra>99) return false;
    return true;
}

bool GradjaninBiH::TestJmbg(long long int jmbg) const
{
    int c[13];
    auto pomocna(jmbg);
    for (int i=12; i>=0; i--)
    {
        c[i]=pomocna%10;
        pomocna/=10;
    }
    if ((Formula(c)==13 and c[12]!=0) or Formula(c)==10 or Formula(c)!=c[12]) return false;
    int dan=(c[0]*10)+c[1];
    int mjesec=(c[2]*10)+c[3];
    int godina=(c[4]*100+((c[5]*10)+c[6]));
    if (c[4]==0) godina+=2000;
    else godina+=1000;
    if (!TestDatuma(dan, mjesec, godina)) return false;
    int sifra=(c[7]*10)+c[8];
    int kod=c[9]*100+((c[10]*10)+c[11]);
    if (!TestSifreIKoda(kod, sifra)) return false;
    return true;
}

GradjaninBiH::GradjaninBiH(std::string ime_i_prezime, long long int jmbg)
{
    if (!TestJmbg(jmbg)) throw std::logic_error("JMBG nije validan");
    prethodni=posljednji;
    auto pomocni(prethodni);
    if (pomocni!=nullptr)
    {
        while (pomocni!=nullptr)
        {
            if (pomocni->jmbg==jmbg) throw std::logic_error("Vec postoji gradjanin s istim JMBG");
            pomocni=pomocni->prethodni;
        }
    }
    int c[13];
    auto pomocna(jmbg);
    for (int i=12; i>=0; i--)
    {
        c[i]=pomocna%10;
        pomocna/=10;
    }
    int dan=(c[0]*10)+c[1];
    int mjesec=(c[2]*10)+c[3];
    int godina=(c[4]*100+((c[5]*10)+c[6]));
    if (c[4]==0) godina+=2000;
    else godina+=1000;
    int sifra=(c[7]*10)+c[8];
    int kod=c[9]*100+((c[10]*10)+c[11]);
    GradjaninBiH::ime_i_prezime=ime_i_prezime;
    GradjaninBiH::jmbg=jmbg;
    GradjaninBiH::dan_rodjenja=dan;
    GradjaninBiH::mjesec_rodjenja=mjesec;
    GradjaninBiH::godina_rodjenja=godina;
    GradjaninBiH::sifra_regije=sifra;
    GradjaninBiH::kod=kod;
    if (kod<500) GradjaninBiH::pol=Musko;
    else pol=Zensko;
    posljednji=this;
}

GradjaninBiH::GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol)
{
    if (!TestDatuma(dan_rodjenja, mjesec_rodjenja, godina_rodjenja)) throw std::logic_error("Neispravni podaci");
    if (sifra_regije<0 or sifra_regije>99) throw std::logic_error("Neispravni podaci");
    prethodni=posljednji;
    GradjaninBiH::ime_i_prezime=ime_i_prezime;
    GradjaninBiH::dan_rodjenja=dan_rodjenja;
    GradjaninBiH::mjesec_rodjenja=mjesec_rodjenja;
    GradjaninBiH::godina_rodjenja=godina_rodjenja;
    GradjaninBiH::sifra_regije=sifra_regije;
 /*   auto pomocni(prethodni);
    if (pomocni!=nullptr)
    {
        while (pomocni!=nullptr)
        {
            if (pomocni->DajDanRodjenja()==this->DajDanRodjenja() and pomocni->DajPol()==this->DajPol())
            {    auto kodic=(pomocni->DajKod()); kodic++; GradjaninBiH::kod=kodic; }
            pomocni=pomocni->prethodni;
        }
    }
    else 
    {
        if (pomocni->DajPol()==0) GradjaninBiH::kod=0;
        else GradjaninBiH::kod=500;
    }
    int c[13];
    c[1]=dan_rodjenja%10; c[0]=dan_rodjenja/10;
    c[3]=mjesec_rodjenja%10; c[2]=mjesec_rodjenja/10;
    if (godina_rodjenja>=2000) godina_rodjenja-=2000;
    else if (godina_rodjenja<2000) godina_rodjenja-=1000;
    c[6]=godina_rodjenja%10; godina_rodjenja/=10; c[5]=godina_rodjenja%10; c[4]=(godina_rodjenja/10)%10;
    c[8]=sifra_regije%10; c[7]=sifra_regije/10;
    int kodina(GradjaninBiH::kod);
    c[11]=kodina%10; kodina/=10; c[10]=kodina%10; c[9]=(kodina/10)%10;
    if (Formula(c)==11) c[12]=0;
    else c[12]=Formula(c);
    long long int suma{};
    for (int i=0; i<12; i++)
    {
        suma+=c[i]*10+c[i+1];
    }
    GradjaninBiH::jmbg=suma; */
    posljednji=this;
};

std::string GradjaninBiH::DajImeIPrezime() const { return GradjaninBiH::ime_i_prezime; }
long long int GradjaninBiH::DajJMBG() const { return GradjaninBiH::jmbg; }
int GradjaninBiH::DajDanRodjenja() const { return GradjaninBiH::dan_rodjenja; }
int GradjaninBiH::DajMjesecRodjenja() const { return GradjaninBiH::mjesec_rodjenja; }
int GradjaninBiH::DajGodinuRodjenja() const { return GradjaninBiH::godina_rodjenja; }
int GradjaninBiH::DajSifruRegije() const { return GradjaninBiH::sifra_regije; }

int main ()
{
    int n;
    std::cout << "Koliko gradjana zelite unijeti po JMBG? " << std::endl;
    std::cin >> n;
    GradjaninBiH *gradjani[100];
    for (int i=0; i<n; i++)
    {
        std::cout << "Unesite ime i prezime (u istom redu): " << std::endl;
        std::cin.ignore(1000, '\n');
        std::cin.clear();
        std::string ime_i_prezime;
        std::getline(std::cin, ime_i_prezime);
        long long int jmbg;
        std::cout << "Unesite JMBG: " << std::endl;
        std::cin >> jmbg;
        try
        {
            GradjaninBiH seljo(ime_i_prezime, jmbg);
            gradjani[i]=&seljo;
            std::cout << "Unijeli ste gradjanina " << gradjani[i]->DajImeIPrezime() << " rodjenog " << gradjani[i]->DajDanRodjenja() << "." 
                << gradjani[i]->DajMjesecRodjenja() << "." << gradjani[i]->DajGodinuRodjenja() << " u regiji " << gradjani[i]->DajSifruRegije();
            if (gradjani[i]->DajPol()==0) std::cout << ", musko.";
            else std::cout << ", zensko.";
            std::cout << std::endl;
        }
        catch(std::logic_error e)
        {
            std::cout << e.what() << std::endl;
            i--;
        }
    }
    int x;
    std::cout << "Koliko gradjana zelite unijeti po datumu rodjenja, regiji i polu? " << std::endl;
    std::cin >> x;
    for (int i=0; i<x; i++)
    {
        std::cout << "Unesite ime i prezime (u istom redu): " << std::endl;
        std::string ime_i_prezime;
        std::cin.ignore(1000, '\n');
        std::cin.clear();
        std::getline(std::cin, ime_i_prezime);
        std::cout << "Unesite datum rodjenja (format dd/mm/gggg): " << std::endl;
        int d, m, g;
        char znak;
        std::cin >> d >> znak >> m >> znak >> g;
        int sifra;
        std::cout << "Unesite sifru regije: " << std::endl;
        std::cin >> sifra;
        std::cout << "Unesite M za musko, Z za zensko: " << std::endl;
        char ses;
        std::cin >> ses;
        GradjaninBiH::Pol pol;
        if (ses=='M') GradjaninBiH::Pol pol=GradjaninBiH::Musko;
        else if (ses=='Z') GradjaninBiH::Pol pol=GradjaninBiH::Zensko;
        try 
        {
            GradjaninBiH seljo(ime_i_prezime, d, m, g, sifra, pol);
            gradjani[i]=&seljo;
            std::cout << "Unijeli ste gradjanina " << gradjani[i]->DajImeIPrezime() << " JMBG: " << gradjani[i]->DajJMBG();
            std::cout << std::endl;
        }
        catch(std::logic_error e)
        {
            std::cout << e.what() << std::endl;
            i--;
        }
    }
	return 0;
}