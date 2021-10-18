/B 2016/2017, Zadaća 4, Zadatak 2
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <string>
#include <stdexcept>
#include <cmath>
#include <new>

class GradjaninBiH{
    std::string Gime_i_prezime;
    long long int GJMBG;
    int Gdan_rodjenja, Gmjesec_rodjenja, Ggodina_rodjenja;
    int Gsifra_regije;
    int pol;
    GradjaninBiH* pnp=nullptr;
    static GradjaninBiH* pnz;
    static int broj;
    bool ImaLiIstiJMBG(long long int JMBG) const;
    int UzmiKod(int kpol);
    static int Zenski_kod;
    static int Muski_kod;
    public:
    enum Pol {Musko, Zensko};
    GradjaninBiH(const GradjaninBiH &g)=delete;
    GradjaninBiH &operator=(const GradjaninBiH &g)=delete;
    GradjaninBiH(std::string ime_i_prezime, long long int JMBG);
    GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja,
    int godina_rodjenja, int sifra_regije, Pol pol);
    std::string DajImeIPrezime() const;
    long long int DajJMBG() const;
    int DajDanRodjenja() const;
    int DajMjesecRodjenja() const;
    int DajGodinuRodjenja() const;
    int DajSifruRegije() const;
    Pol DajPol() const;
    void PromijeniImeIPrezime(std::string novo_ime);
    ~GradjaninBiH();
};

GradjaninBiH::~GradjaninBiH(){
    if(pnp==nullptr) {
        auto p(pnz);
        while(p->pnp!=nullptr) p=p->pnp;
        p=nullptr;
    }
    else if(pnz==this) pnz=pnp;
    else{
        auto p(pnz);
        while(p->pnp!=this) p=p->pnp;
        p->pnp=pnp;
    }
}
GradjaninBiH* GradjaninBiH::pnz=nullptr;
int GradjaninBiH::broj=0;
int GradjaninBiH::Zenski_kod=500;
int GradjaninBiH::Muski_kod=0;

void CifreJMBG(long long int JMBG, int a[]){
    int broj(0);
    int i(12);
    while(JMBG!=0){
        a[i--]=JMBG%10;
        broj++;
        JMBG/=10;
    }
    if(broj==12) a[i]=0;
}

bool DaLiJeIspravanDatum(int (&a)[13]){
    int dan_rodjenja(a[0]*10+a[1]);
    int mjesec_rodjenja(a[2]*10+a[3]);
    int godina_rodjenja;
    if(a[4]>=1) godina_rodjenja=1000+a[4]*100+a[5]*10+a[6];
    else godina_rodjenja=2000+a[5]*10+a[6];
    int broj_dana[12]{31,28,31,30,31,30,31,31,30,31,30,31};
    if((godina_rodjenja%4==0 && godina_rodjenja%100 !=0) || godina_rodjenja%400==0) broj_dana[1]++;
    if(godina_rodjenja<1 || dan_rodjenja<1 || mjesec_rodjenja<1 || mjesec_rodjenja>12 || dan_rodjenja>broj_dana[mjesec_rodjenja-1]) return false;
    return true;
}
bool DaLiJeIspravanDatum(int d, int m, int g){
    int broj_dana[12]{31,28,31,30,31,30,31,31,30,31,30,31};
    if((g%4==0 && g%100!=0) || g%400==0) broj_dana[1]++;
    if(g<1 || d<1 || m<1 || m>12 || d>broj_dana[m-1]) return false;
    return true;
}

bool GradjaninBiH::ImaLiIstiJMBG(long long int JMBG) const{
    auto p(pnz);
    while(p!=nullptr){
        if(p->GJMBG==JMBG) return true;
        p=p->pnp;
    }
    return false;
}

GradjaninBiH::GradjaninBiH(std::string ime_i_prezime, long long int JMBG){
    int a[13];
    CifreJMBG(JMBG, a);
    int c(11-(7*(a[0]+a[6]) + 6*(a[1]+a[7]) + 5*(a[2]+a[8]) + 4*(a[3]+a[9]) + 3*(a[4]+a[10]) + 2*(a[5]+a[11]))%11);
    if(c==11) c=0;
    bool istinitost(DaLiJeIspravanDatum(a));
    if(a[12]!=c || c==10 || !istinitost) throw std::logic_error("JMBG nije validan");
   if(ImaLiIstiJMBG(JMBG)) throw std::logic_error("Vec postoji gradjanin sa istim JMBG");
    pnp=pnz;
    pnz=this;
    Gime_i_prezime=ime_i_prezime;
    GJMBG=JMBG;
    Gdan_rodjenja=a[0]*10+a[1];
    Gmjesec_rodjenja=a[2]*10+a[3];
    if(a[4]>=1) Ggodina_rodjenja=1000+a[4]*100+a[5]*10+a[6];
    else Ggodina_rodjenja=2000+a[5]*10+a[6];
    Gsifra_regije=a[7]*10+a[8];
    pol=a[9]*100+a[10]*10+a[11];
}

int GradjaninBiH::UzmiKod(int kpol){
    GradjaninBiH::Pol poli;
    if(kpol==1) poli=Zensko;
    else poli=Musko;
    auto p(pnz);
    if(p->pnp==nullptr){
        if(poli==Zensko) return 500;
        return 0;
    }
    while(p!=nullptr && p!=this){
        if(p->DajPol()==poli && p->DajDanRodjenja()==DajDanRodjenja() && p->DajGodinuRodjenja()==DajGodinuRodjenja() && p->DajMjesecRodjenja()==DajMjesecRodjenja() && p->DajSifruRegije()==DajSifruRegije()) {
          if(p->pol==499)  return 0;
          else if(p->pol==999) return 500;
          else return p->pol+1;
        }
        p=p->pnp;
    }
    if(poli==Zensko) return 500;
    return 0;
}

int formula(int (&a)[13]);

long long int StaviUJMBG(int d, int m, int g, int sg, int p){
    long long int JMBG(0);
    if(g>=2000) g=g%2000;
    else if(g>=1000) g=g%1000;
    int a[13];
    JMBG=d*std::pow(10,11)+m*std::pow(10,9)+g*std::pow(10,6)+sg*std::pow(10,4)+p*10;
    CifreJMBG(JMBG, a);
    int c(formula(a));
    if(c==11) c=0;
    else if(c==10) {
        return 0;
    }
    JMBG+=c;
    return JMBG;
}

int formula(int (&a)[13]){
    int c(11-(7*(a[0]+a[6]) + 6*(a[1]+a[7]) + 5*(a[2]+a[8]) + 4*(a[3]+a[9]) + 3*(a[4]+a[10]) + 2*(a[5]+a[11]))%11);
    return c;
}
GradjaninBiH::GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja,
int sifra_regije, Pol pol){
    if(!DaLiJeIspravanDatum(dan_rodjenja,mjesec_rodjenja,godina_rodjenja) || sifra_regije<0 || sifra_regije>99) throw std::logic_error("Neispravni podaci");
    pnp=pnz;
    pnz=this;
    Gdan_rodjenja=dan_rodjenja;
    Gmjesec_rodjenja=mjesec_rodjenja;
    Ggodina_rodjenja=godina_rodjenja;
    Gsifra_regije=sifra_regije;
    Gime_i_prezime=ime_i_prezime;
    if(pol==Zensko) {GradjaninBiH::pol=UzmiKod(1);}
    else {GradjaninBiH::pol=UzmiKod(0);}
    GJMBG=StaviUJMBG(dan_rodjenja, mjesec_rodjenja, godina_rodjenja,sifra_regije, GradjaninBiH::pol);
    if(GJMBG==0){
        while(!GJMBG){
            GradjaninBiH::pol++;
            if(GradjaninBiH::pol==500) GradjaninBiH::pol=0;
            if(GradjaninBiH::pol==1000) GradjaninBiH::pol=500;
            GJMBG=StaviUJMBG(dan_rodjenja, mjesec_rodjenja, godina_rodjenja, sifra_regije, GradjaninBiH::pol);
        }
    }
}

std::string GradjaninBiH::DajImeIPrezime() const{
    return Gime_i_prezime;
}

long long int GradjaninBiH::DajJMBG() const{
    return GJMBG;
}

int GradjaninBiH::DajDanRodjenja() const{
    return Gdan_rodjenja;
}

int GradjaninBiH::DajMjesecRodjenja() const{
    return Gmjesec_rodjenja;
}

int GradjaninBiH::DajGodinuRodjenja() const{
    return Ggodina_rodjenja;
}

int GradjaninBiH::DajSifruRegije() const{
    return Gsifra_regije;
}

GradjaninBiH::Pol GradjaninBiH::DajPol() const{
    if(pol<=499) return Musko;
    return Zensko;
}

void GradjaninBiH::PromijeniImeIPrezime(std::string novo_ime) {
    Gime_i_prezime=novo_ime;
}
int main ()
{
    
        GradjaninBiH* niz[100];
        std::cout<<"Koliko gradjana zelite unijeti po JMBG? "<<std::endl;
        int n; 
        std::cin>>n;
        std::cin.ignore(1000,'\n');
        int m(0);
        for(int i=0; i<n; i++){
            std::cout<<"Unesite ime i prezime (u istom redu): "<<std::endl;
            std::string ime;
            std::getline(std::cin, ime);
            std::cout<<"Unesite JMBG: "<<std::endl;
            long long int JMBG;
            std::cin>>JMBG;
            std::cin.ignore(1000, '\n');
            try{
                niz[i]=new GradjaninBiH(ime,JMBG);
                std::cout<<"Unijeli ste gradjanina "<<niz[i]->DajImeIPrezime()<<" rodjenog "<<niz[i]->DajDanRodjenja()<<"."<<niz[i]->DajMjesecRodjenja()<<"."<<niz[i]->DajGodinuRodjenja()<<" u regiji "<<niz[i]->DajSifruRegije()<<", ";
                if(niz[i]->DajPol()==GradjaninBiH::Musko) std::cout<<"musko."<<std::endl;
                else if(niz[i]->DajPol()==GradjaninBiH::Zensko) std::cout<<"zensko."<<std::endl;
                m++;
            }
            catch(std::logic_error e){
                std::cout<<e.what()<<std::endl;
            }
            if(m==i) i--;
        }
    
        std::cout<<"Koliko gradjana zelite unijeti po datumu rodjenja, regiji i polu? "<<std::endl;
        GradjaninBiH* niz2[100];
        int x;
        std::cin>>x;
        std::cin.ignore(1000, '\n');
        int m1(0);
        for(int i=0; i<x; i++){
            std::cout<<"Unesite ime i prezime (u istom redu): "<<std::endl;
            std::string ime;
            std::getline(std::cin, ime);
            std::cout<<"Unesite datum rodjenja (format dd/mm/gggg): "<<std::endl;
            int dan, mesec, godina;
            char znak;
            std::cin>>dan>>znak>>mesec>>znak>>godina;
            std::cin.ignore(1000, '\n');
            std::cout<<"Unesite sifru regije: "<<std::endl;
            int sifra;
            std::cin>>sifra;
            std::cin.ignore(1000, '\n');
            GradjaninBiH::Pol pol;
            std::cout<<"Unesite M za musko, Z za zensko: "<<std::endl;
            char slovo;
            std::cin>>slovo;
            std::cin.ignore(1000,'\n');
            if(slovo=='M' || slovo=='m') {pol=GradjaninBiH::Musko;}
            else if(slovo=='Z' || slovo=='z') pol=GradjaninBiH::Zensko;
            else {std::cout<<"Neispravni podaci"<<std::endl; i--; continue;}
            try{
                niz2[i]=new GradjaninBiH(ime, dan, mesec, godina, sifra, pol);
                m1++;
                std::cout<<"Unijeli ste gradjanina "<<niz2[i]->DajImeIPrezime()<<" JMBG: "<<niz2[i]->DajJMBG()<<"."<<std::endl;
            }
            catch(std::logic_error e){
                std::cout<<e.what()<<std::endl;
            }
            if(m1==i) i--;
        }
	return 0;
}