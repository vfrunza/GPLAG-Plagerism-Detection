/B 2016/2017, Zadaća 4, Zadatak 2
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>
#include <cmath>

class GradjaninBiH {
    std::string ime;
    long long int JMBG;
    mutable int kod_z=500;
    mutable int kod_m=0;
    static GradjaninBiH *zadnji;
    GradjaninBiH *prethodni=nullptr;
    bool Provjeri_da_li_postoji(long long int broj);
    public:
    enum Pol {Musko, Zensko};
    GradjaninBiH (std::string ime_i_prezime, long long int jmbg);
    GradjaninBiH (std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol);
    ~GradjaninBiH ();
    std::string DajImeIPrezime() const;
    long long int DajJMBG() const;
    int DajDanRodjenja() const;
    int DajMjesecRodjenja() const;
    int DajGodinuRodjenja() const;
    int DajSifruRegije() const;
    Pol DajPol() const;
    void PromijeniImeIPrezime(std::string novo_ime);
};
GradjaninBiH * GradjaninBiH::zadnji=nullptr;

bool Neispravan_datum(int d, int m, int g) {
    int broj_dana[]={31,28,31,30,31,30,31,31,30,31,30,31};
    if ((g%4==0 && g%100!=0) || g%400==0) broj_dana[1]++;
    if (g<1917 || g>2017 || m<1 || m>12 || d<1 || d>broj_dana[m-1]) return true;
    return false;
}

bool Validan_jmbg(long long int jmbg) {
    int d=jmbg/100000000000, m=(jmbg%100000000000)/1000000000, g=(jmbg%1000000000)/1000000, kod=(jmbg%10000)/10, s_regije=(jmbg%1000000)/10000;
    if(g>17) g+=1000;
    else g+=2000;
    if (Neispravan_datum(d,m,g)) return false;
    int c=11-(7*(d/10+g%10)+6*(d%10+s_regije/10)+5*(m/10+s_regije%10)+4*(m%10+kod/100)+3*((g%1000)/100+(kod%100)/10)+2*((g%100)/10+kod%10))%11;
    if (c==11) c=0;
//std::cout<<"c je "<<c;
    if (jmbg%10!=c || c==10) return false;
    return true;
}

bool GradjaninBiH::Provjeri_da_li_postoji (long long int broj) {
    for (GradjaninBiH *p=GradjaninBiH::zadnji; p!=nullptr; p=p->GradjaninBiH::prethodni) 
        if (p->GradjaninBiH::DajJMBG()==broj) return true;
    return false;
}

GradjaninBiH::GradjaninBiH (std::string ime_i_prezime, long long int jmbg) {
    if(Provjeri_da_li_postoji(jmbg)) {
        throw std::logic_error("Vec postoji gradjanin sa istim JMBG"); 
    }
    if(!Validan_jmbg(jmbg)) throw std::logic_error("JMBG nije validan"); 
    GradjaninBiH::ime=ime_i_prezime; 
    GradjaninBiH::JMBG=jmbg;
    prethodni=GradjaninBiH::zadnji;
    GradjaninBiH::zadnji=this;
}

GradjaninBiH::GradjaninBiH (std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol) {
    if(Neispravan_datum(dan_rodjenja,mjesec_rodjenja,godina_rodjenja)==true || sifra_regije<0 || sifra_regije>99) throw std::logic_error("Neispravni podaci");
    int kod_osobe;
    if(pol==Pol::Zensko) {
        kod_osobe=GradjaninBiH::kod_z;
        kod_z++;
    }
    else {
        kod_osobe=GradjaninBiH::kod_m;
        kod_m++;
    }
    int c=11-(7*(dan_rodjenja/10+godina_rodjenja%10)+6*(dan_rodjenja%10+sifra_regije/10)+5*(mjesec_rodjenja/10+sifra_regije%10)+4*(mjesec_rodjenja%10+kod_osobe/100)+3*((godina_rodjenja%1000)/100+(kod_osobe%100)/10)+2*((godina_rodjenja%100)/10+kod_osobe%10))%11;
    if (c==11) c=0;
    else if (c==10) throw std::logic_error("JMBG nije validan");
    long long int moguci_jmbg=dan_rodjenja*pow(10,11)+mjesec_rodjenja*pow(10,9)+(godina_rodjenja%1000)*pow(10,6)+sifra_regije*pow(10,4)+kod_osobe*10+c;
    if (Provjeri_da_li_postoji(moguci_jmbg)) {
        throw std::logic_error("Vec postoji gradjanin sa istim JMBG");
    }
    else {
        GradjaninBiH::ime=ime_i_prezime;
        GradjaninBiH::JMBG=moguci_jmbg;
        prethodni=GradjaninBiH::zadnji;
        GradjaninBiH::zadnji=this;
    }
}

GradjaninBiH::~GradjaninBiH() {
    for (GradjaninBiH *p=GradjaninBiH::zadnji; p!=nullptr; p=p->GradjaninBiH::prethodni) {
        if (p==this && p->GradjaninBiH::prethodni==nullptr) { GradjaninBiH::zadnji=nullptr; p=nullptr; break; }
        else if (p==this) { GradjaninBiH::zadnji=p->GradjaninBiH::prethodni; p->GradjaninBiH::prethodni=nullptr; p=GradjaninBiH::zadnji; break;}
    }
}

std::string GradjaninBiH::DajImeIPrezime () const {
    return ime;
}

long long int GradjaninBiH::DajJMBG() const {
    return GradjaninBiH::JMBG;
}

int GradjaninBiH::DajDanRodjenja() const {
    int dan=DajJMBG()/100000000000;
    return dan;
}

int GradjaninBiH::DajMjesecRodjenja() const {
    int mjesec= (DajJMBG()%100000000000)/1000000000;
    return mjesec;
}
int GradjaninBiH::DajGodinuRodjenja() const {
    int godina=(DajJMBG()%1000000000)/1000000;
    if (godina<=17) godina+=2000;
    else godina+=1000;
    return godina;
}

int GradjaninBiH::DajSifruRegije() const {
    return (DajJMBG()%1000000)/10000;
}

GradjaninBiH::Pol GradjaninBiH::DajPol() const {
    Pol a;
    int p=(DajJMBG()%10000)/10;
    if (p<=499) a=GradjaninBiH::Pol::Musko;
    else a=GradjaninBiH::Pol::Zensko;
    return a;
}

void GradjaninBiH::PromijeniImeIPrezime (std::string novo_ime) {
    GradjaninBiH::ime=novo_ime;
}

int main ()
{
    int n1,n2;
    std::cout<<"Koliko gradjana zelite unijeti po JMBG? \n";
    std::cin>>n1;
    for (int i=0; i<n1; i++) {
        try {    
            std::string ime,pol;
            long long int jmbg;
            std::cin.clear();
            std::cin.ignore(10000,'\n');
            std::cout<<"Unesite ime i prezime (u istom redu): \n";
            std::getline(std::cin,ime);
            std::cout<<"Unesite JMBG: \n";
            std::cin>>jmbg;
            GradjaninBiH g(ime,jmbg);
            if (g.DajPol()==GradjaninBiH::Pol::Zensko) pol="zensko";
            else pol="musko";
            std::cout<<"Unijeli ste gradjanina "<<g.DajImeIPrezime()<<" rodjenog "<<g.DajDanRodjenja()<<"."<<g.DajMjesecRodjenja()<<"."<<g.DajGodinuRodjenja()<<" u regiji "<<g.DajSifruRegije()<<", "<<pol<<"."<<std::endl;
        }
        catch (std::logic_error a) {
            i--;
            std::cout<<a.what()<<std::endl;
        }
    }
    std::cout<<"Koliko gradjana zelite unijeti po datumu rodjenja, regiji i polu? \n";
    std::cin>>n2;
    for (int i=0; i<n2; i++) {
        try {
            std::string ime;
            int d,m,g,sifra;
            char znak,miliz;
            GradjaninBiH::Pol p=GradjaninBiH::Pol::Musko;
            std::cin.clear();
            std::cin.ignore(10000,'\n');
            std::cout<<"Unesite ime i prezime (u istom redu): \n";
            std::getline(std::cin,ime);
            std::cout<<"Unesite datum rodjenja (format dd/mm/gggg): \n";
            std::cin>>d>>znak>>m>>znak>>g;
            std::cout<<"Unesite sifru regije: \n";
            std::cin>>sifra;
            std::cout<<"Unesite M za musko, Z za zensko: \n";
            std::cin>>miliz;
            if(miliz=='Z') p=GradjaninBiH::Pol::Zensko;
            GradjaninBiH gradj(ime,d,m,g,sifra,p);
            std::cout<<"Unijeli ste gradjanina "<<gradj.DajImeIPrezime()<<" JMBG: "<<gradj.DajJMBG()<<".\n";
        }
        catch (std::logic_error b) {
            i--;
            std::cout<<b.what()<<std::endl;
        }
    }
	return 0;
}