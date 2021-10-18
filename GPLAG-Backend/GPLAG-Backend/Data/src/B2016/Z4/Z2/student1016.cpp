/B 2016/2017, Zadaća 4, Zadatak 2
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <string>
#include <stdexcept>

class GradjaninBiH
{
    long long int JMBG;
    std::string ime;
    GradjaninBiH* prethodni=nullptr;
    static GradjaninBiH* adresa_trenutnog;
    GradjaninBiH* sljedeci=nullptr;
    static bool ProvjeriDatum(int dan, int mjesec, int godina);
    static long long int NapraviBroj(int x[]);
    GradjaninBiH*& DajSljedeci() {
        return sljedeci;
    }
public:
    enum Pol {Musko, Zensko};
    GradjaninBiH(std::string ime_i_prezime, long long int jmbg);
    GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol);
    std::string DajImeIPrezime() const {
        return ime;
    };
    long long int DajJMBG() const {
        return JMBG;
    };
    int DajDanRodjenja() const {
        return (JMBG/100000000000);
    }
    int DajMjesecRodjenja() const;
    int DajGodinuRodjenja() const;
    int DajSifruRegije() const;
    Pol DajPol() const;
    void PromijeniImeIPrezime(std::string novo_ime) {
        ime=novo_ime;
    };
    ~GradjaninBiH() {
        if(prethodni!=nullptr) prethodni->sljedeci=this->sljedeci;
    }
};

bool GradjaninBiH::ProvjeriDatum(int dan, int mjesec, int godina)
{
    int brojdana[] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if((godina % 4 == 0 && godina % 100 != 0) || godina % 400 == 0)
        brojdana[1]++;
    if(godina < 1 || mjesec < 1 || mjesec > 12 || dan < 1 || dan > brojdana[mjesec-1]) return false;
    return true;
}

int GradjaninBiH::DajMjesecRodjenja() const
{
    int x=JMBG/1000000000, dj=1, mj=0;
    for(int i=0; i<2; i++) {
        mj+=(x%10)*dj;
        dj*=10;
        x/=10;
    }
    return mj;
}

GradjaninBiH::Pol GradjaninBiH::DajPol() const
{
    long long int x=JMBG/1000;
    if(x%10>=5) return Zensko;
    return Musko;
}

int GradjaninBiH::DajGodinuRodjenja() const
{
    int x=JMBG/1000000, dj=1, god=0;
    for(int i=0; i<3; i++) {
        god+=(x%10)*dj;
        dj*=10;
        x/=10;
        if(i==1) {
            if(god>17) god+=1000;
            else god+=2000;
        }
    }
    return god;
}

int GradjaninBiH::DajSifruRegije() const
{
    long int x=JMBG/10000, dj=1, s=0;
    for(int i=0; i<2; i++) {
        s+=(x%10)*dj;
        dj*=10;
        x/=10;
    }
    return s;
}

long long int GradjaninBiH::NapraviBroj(int niz[])
{
    long long int j(0);
    long long int dekjed(1);
    for(int i=12; i>=0; i--) {
        j+=niz[i]*dekjed;
        dekjed*=10;
    }
    return j;
}
 

GradjaninBiH::GradjaninBiH(std::string ime_i_prezime, long long int jmbg):JMBG(jmbg), ime(ime_i_prezime)
{
    if(!ProvjeriDatum(this->DajDanRodjenja(), this->DajMjesecRodjenja(), this->DajGodinuRodjenja()) or this->DajSifruRegije()<0 or this->DajSifruRegije()>99) {
        throw std::logic_error ("JMBG nije validan");
    }
    GradjaninBiH* x;
    for(x=prethodni; x!=nullptr; x=x->prethodni) {
        if(x->DajJMBG()==JMBG) throw std::logic_error ("Vec postoji gradjanin sa istim JMBG");
    }
    if(prethodni!=nullptr) prethodni->sljedeci=this;
    prethodni=adresa_trenutnog;
    adresa_trenutnog=this;
}

GradjaninBiH::GradjaninBiH(std::string ime_i_prezime,  int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol)
{
    ime=ime_i_prezime;
    int niz[13];
    if(!ProvjeriDatum(dan_rodjenja, mjesec_rodjenja, godina_rodjenja) or (sifra_regije<0 or sifra_regije>99)) throw std::logic_error ("Neispravni podaci");
    for(int i=1; i>=0; i--) {
        niz[i]=dan_rodjenja%10;
        dan_rodjenja/=10;
        niz[i+2]=mjesec_rodjenja%10;
        mjesec_rodjenja/=10;
        niz[i+7]=sifra_regije%10;
        sifra_regije/=10;
    }
    int kod;
    if(pol==Pol::Zensko) {
        GradjaninBiH* x;
        kod=500;
        for(x=prethodni; x!=nullptr; x=x->prethodni) {
            if(x->DajDanRodjenja()==dan_rodjenja and x->DajMjesecRodjenja()==mjesec_rodjenja and x->DajGodinuRodjenja()==godina_rodjenja) kod++;
        }

    } else if(pol==Pol::Musko) {
        GradjaninBiH* x;
        kod=0;
        for(x=prethodni; x!=nullptr; x=x->prethodni) {
            if(x->DajDanRodjenja()==dan_rodjenja and x->DajMjesecRodjenja()==mjesec_rodjenja and x->DajGodinuRodjenja()==godina_rodjenja) kod++;
        }
    }
    for(int i=6; i>=4; i--) {
        niz[i]=godina_rodjenja%10;
        godina_rodjenja/=10;
        niz[i+5]=kod%10;
        kod/=10;
    }
    niz[12]=11-(7*(niz[0]+niz[6])+6*(niz[1]+niz[7])+5*(niz[2]+niz[8])+4*(niz[3]+niz[9])+3*(niz[4]+niz[10])+2*(niz[5]+niz[11]))%11;
    if(niz[12]==11) niz[12]=0;
    if(niz[12]==10) throw std::logic_error ("JMBG nije validan");
    JMBG=NapraviBroj(niz);
    GradjaninBiH* x;
    for(x=prethodni; x!=nullptr; x=x->prethodni) {
        if(x->DajJMBG()==JMBG) throw std::logic_error ("Vec postoji gradjanin sa istim JMBG");
    }
    if(prethodni!=nullptr) prethodni->sljedeci=this;
    prethodni=adresa_trenutnog;
    adresa_trenutnog=this;
}


GradjaninBiH* GradjaninBiH::adresa_trenutnog=nullptr;

int main ()
{
    std::cout << "Koliko gradjana zelite unijeti po JMBG? \n";
    int n;
    std::cin >>n;
    std::cin.ignore(10000, '\n');
    for(int i=0; i<n; i++) {
        std::cout<< "Unesite ime i prezime (u istom redu): \n";
        std::string s;
        std::getline(std::cin, s);
        std::cout<< "Unesite JMBG: \n";
        long long int jmbg;
        std::cin >> jmbg;
        std::cin.ignore(1000, '\n');
        try {
            GradjaninBiH t(s, jmbg);
            std::cout << "Unijeli ste gradjanina " << t.DajImeIPrezime() <<" rodjenog "<<t.DajDanRodjenja()<<"."<<t.DajMjesecRodjenja()<< "." << t.DajGodinuRodjenja()<<" u regiji "<<t.DajSifruRegije();
            if(t.DajPol()==GradjaninBiH::Pol::Musko) std::cout << ", musko.";
            else std::cout << ", zensko.";
            std::cout << std::endl;
        } catch (std::logic_error izuz) {
            std::cout << izuz.what() << std::endl;
            i--;
        }
    }
    std::cout << "Koliko gradjana zelite unijeti po datumu rodjenja, regiji i polu?\n";
    std::cin >>n;
    std::cin.ignore(1000, '\n');
    for(int i=0; i<n; i++) {
        std::cout << "Unesite ime i prezime (u istom redu): \n";
        std::string s;
        std::getline(std::cin, s);
        std::cout << "Unesite datum rodjenja (format dd/mm/gggg): \n";
        char znak;
        int d, m , g;
        std::cin >> d >> znak >> m >> znak >> g;
        int x;
        std::cout << "Unesite sifru regije: \n";
        std::cin >> x;
        std::cout << "Unesite M za musko, Z za zensko: \n";
        std::cin >> znak;
        GradjaninBiH::Pol pol;
        if(znak=='M') pol=GradjaninBiH::Musko;
        else pol=GradjaninBiH::Zensko;
        std::cin.ignore(10,'\n');
        try {
            GradjaninBiH t(s, d, m, g, x, pol);
            std::cout << "Unijeli ste gradjanina "<< t.DajImeIPrezime() <<" JMBG: " << t.DajJMBG() << "."<< std::endl;
        } catch(std::logic_error izuz) {
            std::cout << izuz.what()<< std::endl;
            i--;
        }
    }

    return 0;
}