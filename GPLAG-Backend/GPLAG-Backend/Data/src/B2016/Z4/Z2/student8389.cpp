/B 2016/2017, Zadaća 4, Zadatak 2
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <cstring>
#include <stdexcept>
class GradjaninBiH {
   // enum Pol{Musko, Zensko};
   public:
   enum Pol {Musko, Zensko};
   private:
    long long int JMBG;
    std::string ime_i_prezime;
    int dan_rodjenja, mjesec_rodjenja, godina_rodjenja, sifra_regije;
    GradjaninBiH* prethodni;
    Pol pol;
    static GradjaninBiH* posljednji;
    bool IspravanDatum(int godina, int mjesec, int dan);
    bool Jmbg(long long int jbmg);
    public:
    //enum Pol{Musko, Zensko};
    GradjaninBiH(std::string ime_i_prezime, long long int JMBG);
    GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol);
    GradjaninBiH(const GradjaninBiH &gradjanin)=delete;
    GradjaninBiH&operator=(const GradjaninBiH&gradjanin)=delete;
    std::string DajImeIPrezime() const {return ime_i_prezime; }
    long long int DajJMBG() const{return JMBG;}
    int DajDanRodjenja() const { return dan_rodjenja; }
    int DajMjesecRodjenja() const {return mjesec_rodjenja;}
    int DajGodinuRodjenja() const {return godina_rodjenja; }
    int DajSifruRegije() const{return sifra_regije; }
    Pol DajPol() const{return pol; }
    void PromijeniImeIPrezime(std::string novo_ime) {
        ime_i_prezime=novo_ime;
    }
    ~GradjaninBiH();
    //bool IspravanDatum(int godina, int mjesec,int dan);
    
};
GradjaninBiH* GradjaninBiH::posljednji=nullptr;
GradjaninBiH::GradjaninBiH(std::string ime_i_prezime, long long int JMBG) {
    prethodni=posljednji;
    posljednji=this;
    auto sacuvaj1(prethodni);
    auto sacuvaj2(posljednji);
    bool postoji(Jmbg(JMBG));
    if(postoji) {
        prethodni=sacuvaj1;
        posljednji=sacuvaj2;
        throw std::logic_error ("Vec postoji gradjanin sa istim JMBG");
    } 
        long long int pomocni(JMBG), pomocni2(JMBG);
        pomocni2/=1000000;
        int godina, mjesec, dan;
        godina=pomocni2%1000;
        if (godina<18) godina+=2000;
        else godina+=1000;
        pomocni2/=1000;
        mjesec=pomocni2%100;
        pomocni2/=100;
        dan=pomocni2%100;
        bool Ispravan(IspravanDatum(godina, mjesec, dan));
        //prethodni=posljedni;
        //posljedni=this;
        long long int temp(JMBG), broj(0);
        while (temp!=0) {
            broj++;
            temp/=10;
        }
        temp=JMBG;
        int c[14];
        for (int i=0; i<=broj; i++) {
            //std::cout<<i;
            c[broj-i]=temp%10;
            //std::cout<<broj-i;
            temp/=10;
        }
        //std::cout<<c[13];
        int temp2(0);
        temp2=11-(7*(c[1]+c[7])+6*(c[2]+c[8])+5*(c[3]+c[9])+4*(c[4]+c[10])+3*(c[5]+c[11])+2*(c[6]+c[12]))%11;
        if (temp2==11)  {
            temp2=0;
            c[broj]=0;
        }
        //std::cout<<temp2;
        bool dobar(true);
        if (temp2==10 || temp2!=c[broj]) dobar=false;
        else dobar=true;
        if (Ispravan==false || dobar==false) {
             prethodni=sacuvaj1;
             posljednji=sacuvaj2;
            throw std::logic_error ("JMBG nije validan");
        }
        GradjaninBiH::ime_i_prezime=ime_i_prezime;
        GradjaninBiH::JMBG=JMBG;
        GradjaninBiH::godina_rodjenja=godina;
        GradjaninBiH::dan_rodjenja=dan;
        GradjaninBiH::mjesec_rodjenja=mjesec;
        pomocni/=10;
        int odredjivanje_pola;
        odredjivanje_pola=pomocni%1000;
        if (odredjivanje_pola>=500) pol=Zensko;
        else pol=Musko;
        pomocni/=1000;
        GradjaninBiH::sifra_regije=pomocni%100;
        pomocni/=100;
}
bool GradjaninBiH::Jmbg(long long int jmbg) {
    auto pomocni(prethodni);
    bool postoji(false);
    while (pomocni!=nullptr) {
        if (jmbg==pomocni->JMBG) {
           postoji=true;
            break;
            
        }
        pomocni=pomocni->prethodni;
    }
    return postoji;
}
bool GradjaninBiH::IspravanDatum(int godina, int mjesec, int dan) {
    bool ispravan(true);
    int broj_dana[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    if ((godina%4==0 && godina%100==0) || godina%400==0) broj_dana[1]++;
    //std::cout<<godina<<"mjesec:"<<mjesec<<"dan:"<<dan;
    if (godina<1 || dan<1 || mjesec<1 || mjesec>12 || dan>broj_dana[mjesec-1])
    ispravan=false;
    return ispravan;
}
GradjaninBiH::GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol) {
     prethodni=posljednji;
        posljednji=this;
    int broj_dana[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    if ((godina_rodjenja%4==0 && godina_rodjenja%100==0) || godina_rodjenja%400==0) broj_dana[1]++;
    if (godina_rodjenja<1 || dan_rodjenja<1 || mjesec_rodjenja<1 || mjesec_rodjenja>12 || dan_rodjenja>broj_dana[mjesec_rodjenja-1] || sifra_regije<0 || sifra_regije>99)
        throw std::logic_error("Neispravni podaci");
        GradjaninBiH::ime_i_prezime=ime_i_prezime;
        GradjaninBiH::pol=pol;
        GradjaninBiH::dan_rodjenja=dan_rodjenja;
        GradjaninBiH::mjesec_rodjenja=mjesec_rodjenja;
        GradjaninBiH::godina_rodjenja=godina_rodjenja;
        GradjaninBiH::sifra_regije=sifra_regije;
        long long int jmbg(dan_rodjenja);
        
       
        jmbg*=100;
        jmbg+=mjesec_rodjenja;
        jmbg*=1000;
        jmbg+=godina_rodjenja%1000;
        jmbg*=100;
        jmbg+=sifra_regije;
        jmbg*=1000;
        int pomocna(0);
        if (pol==Musko) pomocna=0;
        else if (pol==Zensko) pomocna=500;
        auto pokazivac(prethodni);
        int broj(0);
        while (pokazivac!=nullptr) {
            if (pol==pokazivac->pol && dan_rodjenja==pokazivac->dan_rodjenja && mjesec_rodjenja==pokazivac->mjesec_rodjenja && sifra_regije==pokazivac->sifra_regije)
                broj++;
                pokazivac=pokazivac->prethodni;
        }
        pomocna+=broj;
        jmbg+=pomocna;
        int trinaesti;
        bool dobar(true);
        int c[13];
        c[2]=dan_rodjenja%10;
        dan_rodjenja/=10;
        c[1]=dan_rodjenja%10;
        c[4]=mjesec_rodjenja%10;
        mjesec_rodjenja/=10;
        c[3]=mjesec_rodjenja%10;
        c[7]=godina_rodjenja%10;
        godina_rodjenja/=10;
        c[6]=godina_rodjenja%10;
        godina_rodjenja/=10;
        c[5]=godina_rodjenja%10;
        c[9]=sifra_regije%10;
        sifra_regije/=10;
        c[8]=sifra_regije%10;
        int kod(pomocna);
        c[12]=pomocna%10;
        c[11]=(pomocna%100)/10;
        c[10]=pomocna/10;
        do {
            dobar=false;
        trinaesti=11-(7*(c[1]+c[7])+6*(c[2]+c[8])+5*(c[3]+c[9])+
        4*(c[4]+c[10])+3*(c[5]+c[11])+2*(c[6]+c[12]))%11;  
        if (trinaesti!=10 && trinaesti!=11) {
            jmbg*=10;
            jmbg+=trinaesti;
        }
        if (trinaesti==11) {
            trinaesti=0;
            jmbg*=10;
            jmbg+=trinaesti;
        }
        //std::cout<<"pomocna"<<pomocna<<"kod"<<kod;
        //jmbg*=10;
        //jmbg+=trinaesti;
        if (trinaesti==10) {
            //pomocna=kod;
            pomocna++;
                dobar=true;
                c[10]=pomocna/100;
                c[11]=(pomocna%100)/10;
                c[12]=pomocna%10;
                jmbg/=10000;
                jmbg*=10;
                jmbg+=c[10];
                jmbg*=10;
                jmbg+=c[11];
                jmbg*=10;
                jmbg+=c[12];
                jmbg*=10;
                jmbg+=trinaesti;
        }
        }while (dobar);
        JMBG=jmbg;
}
GradjaninBiH::~GradjaninBiH() {
    if (posljednji==this) posljednji=this->prethodni;
    else {
        auto pok1(posljednji);
        auto pok2(pok1->prethodni);
        while (pok2!=this && pok2!=nullptr) {
            pok1=pok1->prethodni;
            pok2=pok2->prethodni;
        }
     pok1->prethodni=pok2->prethodni;
    }
}

int main ()
{
    int broj;
    std::cout<<"Koliko gradjana zelite unijeti po JMBG? "<<std::endl;
    std::cin>>broj;
    GradjaninBiH* niz[100];
    int vel(0);
    for (int i=0; i<broj; i++) {
        try {
        std::string ime;
        std::cout<<"Unesite ime i prezime (u istom redu): "<<std::endl;
        std::cin.ignore(10000, '\n');
        std::getline(std::cin, ime);
        std::cout<<"Unesite JMBG: "<<std::endl;
        long long int jmbg;
        std::cin>>jmbg;
            niz[vel]=new GradjaninBiH(ime, jmbg);
            //GradjaninBiH x(ime, jmbg);
            std::cout<<"Unijeli ste gradjanina "<<niz[vel]->DajImeIPrezime()<<" rodjenog "<<niz[vel]->DajDanRodjenja()<<"."<<niz[vel]->DajMjesecRodjenja()<<"."<<niz[vel]->DajGodinuRodjenja()<<" u regiji " <<niz[vel]->DajSifruRegije()<<", ";
            if (niz[vel]->DajPol()==GradjaninBiH::Zensko) std::cout<<" zensko."<<std::endl;
            else std::cout<<"musko."<<std::endl;
            vel++;
            
        }
        catch(std::logic_error a) {
            std::cout<<a.what()<<std::endl;
            i--;
        } 
    }
    std::cout<<"Koliko gradjana zelite unijeti po datumu rodjenja, regiji i polu? "<<std::endl;
   // std::cout<<"DALJE";
    int broj2;
    std::cin>>broj2;
    for (int i=0; i<broj2; i++) {
        try {
            std::string ime2;
            std::cout<<"Unesite ime i prezime (u istom redu): "<<std::endl;
            std::cin.ignore(1000,'\n');
            std::getline(std::cin, ime2);
            int dan, mjesec, godina;
            char znak;
            std::cout<<"Unesite datum rodjenja (format dd/mm/gggg): "<<std::endl;
            std::cin>>dan>>znak>>mjesec>>znak>>godina;
            int regija;
            std::cout<<"Unesite sifru regije: "<<std::endl;
            std::cin>>regija;
            char znak2;
            std::cout<<"Unesite M za musko, Z za zensko: "<<std::endl;
            std::cin>>znak2;
            GradjaninBiH::Pol pol;
            if (znak2=='Z') pol=GradjaninBiH::Pol::Zensko;
            else pol=GradjaninBiH::Pol::Musko;
            niz[vel]=new GradjaninBiH(ime2, dan, mjesec, godina, regija, pol);
            std::cout<<"Unijeli ste gradnjanina "<<niz[vel]->DajImeIPrezime()<<" JMBG: "<<niz[vel]->DajJMBG()<<".";
            vel++;
        } catch (std::logic_error a) {
            std::cout<<a.what()<<std::endl;
            i--;
        }
    }
    for (int i=0; i<vel; i++) delete niz[i];
	return 0;
}






