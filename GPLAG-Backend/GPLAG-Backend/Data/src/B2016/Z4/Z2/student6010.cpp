#include <iostream>
#include <string>
#include <stdexcept>
#include <cmath>
#include <string>
using std::cin;
 
class GradjaninBiH {
    public: enum Pol{Musko, Zensko};
    private: std::string ImeIPrezime;
    Pol spol;
    long long int jmbg;
    static GradjaninBiH* zadnji_kreirani;
    GradjaninBiH* prethodni=nullptr;
    public:
     
    GradjaninBiH(std::string ime_i_prezime, long long int jmbg) {
        if(prethodni && jmbg==prethodni->jmbg) throw std::logic_error("Vec postoji gradjanin sa istim JMBG");
        for(auto i=zadnji_kreirani; i!=nullptr; i=i->prethodni) if(i!=this && jmbg==i->jmbg) throw;
        auto zamjena=jmbg;
        int brojac=0;
        while(zamjena!=0) {
            brojac++; 
            zamjena/=10;
        } if(brojac<12 || brojac>13) throw;
        long long int nazivnik=pow(10,11);
        int dan_rodjenja=jmbg/nazivnik;
        int mjesec_rodjenja=(jmbg/(nazivnik/100))%100;
        int godina_rodjenja=(jmbg/(nazivnik/100000))%1000;
    
        if(godina_rodjenja<=17) godina_rodjenja+=2000;
        else  if(godina_rodjenja>17) godina_rodjenja+=1000;
        if((dan_rodjenja==31 && (mjesec_rodjenja==2 || mjesec_rodjenja==4 || mjesec_rodjenja==6 || mjesec_rodjenja==9 || mjesec_rodjenja==11) )|| (dan_rodjenja>31) || 
        (dan_rodjenja==30 && mjesec_rodjenja==2) || (dan_rodjenja==29 && mjesec_rodjenja==2 && (( godina_rodjenja%4==0 && godina_rodjenja%400!=0) || godina_rodjenja%4!=0))
        || dan_rodjenja<1 || mjesec_rodjenja<1 ||mjesec_rodjenja>12 || godina_rodjenja<1917 || godina_rodjenja>2017) throw std::logic_error("JMBG nije validan");
        ImeIPrezime=ime_i_prezime;
        GradjaninBiH::jmbg=jmbg;
        if(((jmbg/10)%1000)<500) spol=Musko;
        else spol=Zensko;
        prethodni=zadnji_kreirani;
        zadnji_kreirani=this;
    }
    GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol) {
         if((dan_rodjenja==31 && (mjesec_rodjenja==2 || mjesec_rodjenja==4 || mjesec_rodjenja==6 || mjesec_rodjenja==9 || mjesec_rodjenja==11) )|| (dan_rodjenja>31) || 
        (dan_rodjenja==30 && mjesec_rodjenja==2) || (dan_rodjenja==29 && mjesec_rodjenja==2 && (( godina_rodjenja%4==0 && godina_rodjenja%400!=0) || godina_rodjenja%4!=0))
        || dan_rodjenja<1 || mjesec_rodjenja<1 ||mjesec_rodjenja>12 || godina_rodjenja<1917 || godina_rodjenja>2017) throw std::logic_error("JMBG nije validan");
        ImeIPrezime=ime_i_prezime;
        spol=pol;
        GradjaninBiH::jmbg=0;
        int c[13]={0};
        c[1]=dan_rodjenja%10; dan_rodjenja/=10;
        c[0]=dan_rodjenja%10;
        c[3]=mjesec_rodjenja%10; mjesec_rodjenja/=10;
        c[2]=mjesec_rodjenja%10;
        c[6]=godina_rodjenja%10; godina_rodjenja/=10;
        c[5]=godina_rodjenja%10; godina_rodjenja/=10;
        c[4]=godina_rodjenja%10;
        c[8]=sifra_regije%10; sifra_regije/=10;
        c[7]=sifra_regije%10;
        if(pol==Musko) {c[9]=0; c[10]=0; c[11]=0;}
        else if(pol==Zensko){c[9]=5; c[10]=0; c[11]=0;}
          int koliko=pow(10,4);
        if(prethodni!=nullptr && this->jmbg/koliko==prethodni->jmbg/koliko) {
            int predzadnje3=(prethodni->jmbg%koliko)/10;
            predzadnje3++;
            c[11]=predzadnje3%10; predzadnje3/=10;
            c[10]=predzadnje3%10; predzadnje3/=10;
            c[9]=predzadnje3%10;
        }
        c[12]=11-(7*(c[0]+c[6])+6*(c[1]+c[7])+5*(c[2]+c[8]) +4*(c[3]+c[9])+3*(c[4]+c[10])+2*(c[5]+c[11]))%11;
        if(c[12]==11) c[12]=0;
        if(c[12]==10) throw std::logic_error("JMBG nije validan");
        for(int i=12; i>=0; i--) {
            GradjaninBiH::jmbg+=c[(int)fabs(12-i)]*pow(10, i);
        }
        if(prethodni!=nullptr && this->jmbg==prethodni->jmbg) throw std::logic_error("Vec postoji gradjanin sa istim JMBG");
          for(auto i=zadnji_kreirani; i!=nullptr; i=i->prethodni) if(i!=this && jmbg==i->jmbg) throw;
        prethodni=zadnji_kreirani;
        zadnji_kreirani=this;
    }
    std::string DajImeIPrezime() const {
        return ImeIPrezime;
    }
    long long int DajJMBG() const {
        return jmbg;
    }
    int DajDanRodjenja() const {
        long long int nazivnik=pow(10,11);
        int rezultat=jmbg/nazivnik;
        return rezultat;
    }
    int DajMjesecRodjenja() const {
        long long int nazivnik=pow(10,9);
        return (jmbg/nazivnik)%100;
    }
    int DajGodinuRodjenja() const {
        long long int nazivnik=pow(10, 6);
        int godina=(jmbg/nazivnik)%1000;
        if(godina<=17) return godina+2000;
        return godina+1000;
    }
    int DajSifruRegije() const {
        long long int broj=pow(10,2);
        int sifra=(jmbg/10000)%broj;
        return sifra;
    }
    Pol DajPol() const {
        return spol;
    }
    void PromijeniImeIPrezime(std::string novo_ime) {
        ImeIPrezime=novo_ime;
    }
};
GradjaninBiH* GradjaninBiH::zadnji_kreirani=nullptr;

int main ()
{
    int n;
    std::cout<<"Koliko gradjana zelite unijeti po JMBG?";
    std::cin>>n;
    for(int i=0; i<n; i++) {
        std::string name;
        long long int jmb;
          bool proslo=false;
        while(!proslo) {
            proslo=true; 
        std::cout<<"\nUnesite ime i prezime (u istom redu): ";
          std::cin.ignore(1000, '\n');
         std::getline(std::cin, name);
        std::cout<<"\nUnesite JMBG: ";
        std::cin>>jmb;
        try{
            GradjaninBiH neko(name, jmb);
            if(neko.DajPol()==0){
            std::cout<<"\nUnijeli ste gradjanina "<<neko.DajImeIPrezime()<<" rodjenog "<<neko.DajDanRodjenja()<<"."<<neko.DajMjesecRodjenja()<<"."<<neko.DajGodinuRodjenja()<<" u regiji "<<neko.DajSifruRegije()<<", musko.";
        }
        else if(neko.DajPol()==1)  std::cout<<"\nUnijeli ste gradjanina "<<neko.DajImeIPrezime()<<" rodjenog "<<neko.DajDanRodjenja()<<"."<<neko.DajMjesecRodjenja()<<"."<<neko.DajGodinuRodjenja()<<" u regiji "<<neko.DajSifruRegije()<<", zensko.";
        } catch(...) {
            std::cout<<"\nJMBG nije validan";
            proslo=false;
        } }
    }
    std::cout<<"\nKoliko gradjana zelite unijeti po datumu rodjenja, regiji i polu? ";
    std::cin>>n;
    for(int i=0; i<n; i++) {
        bool proslo=false;
        std::string name;
        int dan, mjesec, godina, sifraregije;
        char spol, znak;
        while(!proslo) {
            proslo=true;
        std::cout<<"\nUnesite ime i prezime (u istom redu): ";
        std::cin.ignore(1000, '\n');
     std::getline(std::cin, name);
        std::cout<<"\nUnesite datum rodjenja (format dd/mm/gggg): ";
        std::cin>>dan>>znak>>mjesec>>znak>>godina;
        std::cout<<"\nUnesite sifru regije: ";
        std::cin>>sifraregije;
        std::cout<<"\nUnesite M za musko, Z za zensko: ";
        std::cin>>spol;
        if(spol=='M') {
        try{
            GradjaninBiH neko(name, dan, mjesec, godina, sifraregije, GradjaninBiH::Pol::Musko);
            std::cout<<"\nUnijeli ste gradjanina "<<neko.DajImeIPrezime()<<" JMBG: "<<neko.DajJMBG()<<".";
        } catch(...) {std::cout<<"\nNeispravni podaci";
            proslo=false;
    } }
            else if(spol=='Z') {
                try{
                    GradjaninBiH neko(name, dan, mjesec, godina, sifraregije, GradjaninBiH::Pol::Zensko);
                    std::cout<<"\nUnijeli ste gradjanina "<<neko.DajImeIPrezime()<<" JMBG: "<<neko.DajJMBG()<<".";
                } catch(...) {std::cout<<"\nNeispravni podaci";
                    proslo=false;
                }
            }
        }}
	return 0;
}