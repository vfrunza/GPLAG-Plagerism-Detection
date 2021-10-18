#include <iostream>
#include <string>
#include <stdexcept>
#include <algorithm>
#include <memory>

struct Datum{
    int dan_rodjenja, mjesec_rodjenja, godina_rodjenja;
    Datum(int dan_rodjenja, int mjesec_rodjenja,int godina_rodjenja);
    Datum(long long int jmbg);
};

class GradjaninBiH{
    std::string ime_i_prezime;
    long long int JMBG[13];
    int kod_osobe;
    static GradjaninBiH *prvi;
    static GradjaninBiH *zadnji;
    int regija, pol,rezerkod,kontkod_osobe;
    Datum datum;
    GradjaninBiH *prethodni;
    public:
    
    enum Pol {Musko, Zensko};
    GradjaninBiH(std::string ime_i_prezime, long long int jmbg);
    GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja,int godina_rodjenja, int sifra_regije, Pol pol);
    std::string DajImeIPrezime() const{return ime_i_prezime;}
    long long int DajJMBG() const;
    int DajDanRodjenja() const{return datum.dan_rodjenja;}
    int DajMjesecRodjenja() const{return datum.mjesec_rodjenja;}
    int DajGodinuRodjenja() const{return datum.godina_rodjenja;}
    int DajSifruRegije() const{return regija;}
    Pol DajPol() const{return Pol(pol);}
    void PromijeniImeIPrezime(std::string novo_ime){ime_i_prezime = novo_ime;}
    ~GradjaninBiH();
};

int main ()
{
    
    GradjaninBiH *niz[100]{nullptr};
    int j(0);
    std::cout<<"Koliko gradjana zelite unijeti po JMBG? "<<std::endl;
    int n;
    std::cin >>n;
    for(int i(0); i < n; i++){
        try{
        std::cin.ignore(10000,'\n');
        std::cout<<"Unesite ime i prezime (u istom redu): "<<std::endl;
        std::string ime;
        std::getline(std::cin,ime);
        std::cout<<"Unesite JMBG: "<<std::endl;
        long long int JMBG;
        std::cin>>JMBG;
        
        niz[j] = new GradjaninBiH(ime,JMBG);
        std::cout<<"Unijeli ste gradjanina "<<niz[j]->DajImeIPrezime()<<" rodjenog "<<niz[j]->DajDanRodjenja()<<"."<<niz[j]->DajMjesecRodjenja()<<"."<<niz[j]->DajGodinuRodjenja()<<" u regiji "<<niz[j]->DajSifruRegije()<<",";
        switch(niz[j]->DajPol()){
            case 0: std::cout<<" musko."<<std::endl;
            break;
            case 1: std::cout<<" zensko."<<std::endl;
            break;
        }
        j++;
        }catch(std::logic_error error){
            std::cout<< error.what()<<std::endl;
            i--;
        }
    }
    std::cout<<"Koliko gradjana zelite unijeti po datumu rodjenja, regiji i polu? "<<std::endl;
    std::cin>>n;
      for(int i(0); i < n; i++){
          try{
        std::cout<<"Unesite ime i prezime (u istom redu): "<<std::endl;
        std::cin.ignore(10000,'\n');
        std::string ime;
        std::getline(std::cin,ime);
        std::cout<<"Unesite datum rodjenja (format dd/mm/gggg): "<<std::endl;
        char znak;
        int d,m,g;
        std::cin>>d>>znak>>m>>znak>>g;
        std::cout<<"Unesite sifru regije: "<<std::endl;
        int sifra;
        GradjaninBiH::Pol pol;
        std::cin>>sifra;
        std::cout<<"Unesite M za musko, Z za zensko: "<<std::endl;
        std::cin.ignore(10000,'\n');
        std::cin>>znak;
        if(znak == 'M')
            pol = GradjaninBiH::Pol(0);
        else pol = GradjaninBiH::Pol(1);
        niz[j] = new GradjaninBiH(ime,d,m,g,sifra,pol);
        std::cout<<"Unijeli ste gradjanina "<<niz[j]->DajImeIPrezime()<<" JMBG: "<<niz[j]->DajJMBG()<<"."<<std::endl;
        j++;
      }catch(std::logic_error error){
            std::cout<< error.what()<<std::endl;
            i--;
        }
      }
    
/*for(int i(100); i >-1; i--)
    delete niz[i];*/

    return 0;
}
Datum::Datum(int dan_rodjenja, int mjesec_rodjenja,int godina_rodjenja){
    int dani[12]{31,28,31,30,31,30,31,31,30,31,30,31};
    if((godina_rodjenja%4== 0 && godina_rodjenja%100!= 0) || godina_rodjenja%400 == 0) dani[1]++;
    if(godina_rodjenja < 1 || dan_rodjenja < 1 || dan_rodjenja > dani[mjesec_rodjenja-1] || mjesec_rodjenja < 1 || mjesec_rodjenja > 12)
        throw std::logic_error("Neispravni podaci");
    Datum::dan_rodjenja = dan_rodjenja, Datum::mjesec_rodjenja = mjesec_rodjenja, Datum::godina_rodjenja = godina_rodjenja;
}
Datum::Datum(long long int jmbg){
    long long int a(1000000000000),b(1000000);
    try{
    if ((jmbg / (a / (b/10)) % 10)*10 + ((jmbg / (a / (b))) % 10) > 17)
    *this = Datum(((jmbg/a)%10)*10+(jmbg/(a/10))%10,((jmbg/(a/100))%10)*10+(jmbg/(a/1000))%10,1000 + ((jmbg/(a/(b/100)))%10)*100+((jmbg/(a/(b/10)))%10)*10+(jmbg/(a/(b)))%10);
    else
    *this = Datum(((jmbg/a)%10)*10+(jmbg/(a/10))%10,((jmbg/(a/100))%10)*10+(jmbg/(a/1000))%10,2000 + ((jmbg/(a/(b/100)))%10)*100+((jmbg/(a/(b/10)))%10)*10+(jmbg/(a/(b)))%10);
    }catch(...){
        throw std::logic_error("JMBG nije validan");
    }
}
GradjaninBiH* GradjaninBiH::prvi = nullptr;
GradjaninBiH* GradjaninBiH::zadnji = nullptr;
GradjaninBiH::GradjaninBiH(std::string ime_i_prezime, long long int jmbg) : ime_i_prezime(ime_i_prezime),datum(jmbg),prethodni(nullptr){
    static GradjaninBiH *pred;
    if(!prvi) prvi = this;
    else prethodni = pred;
    pred = this;
    GradjaninBiH *privremeni(nullptr);
    privremeni = this;
    int i(0);
    long long int temp(jmbg);
    while(temp){
        JMBG[i] = temp%10;
        temp/=10;
        i++;
    }
    while(privremeni != nullptr && privremeni->prethodni != this){
        if(privremeni != this && privremeni->DajJMBG() == jmbg)
            throw std::logic_error("Vec postoji gradjanin sa istim JMBG");
        privremeni = privremeni->prethodni;
    }
    std::reverse(std::begin(JMBG),std::end(JMBG));
    regija = JMBG[7]*10 + JMBG[8];
    if(JMBG[9] < 5)
        pol = 0;
    else pol = 1;
    
    kontkod_osobe = 11-(7*(JMBG[0] + JMBG[6]) + 6*(JMBG[1]+JMBG[7]) + 5*(JMBG[2]+JMBG[8]) + 4*(JMBG[3]+JMBG[9]) + 3*(JMBG[4]+JMBG[10]) + 2*(JMBG[5]+JMBG[11]))%11;
    rezerkod = JMBG[9]*100 + JMBG[10]*10 + JMBG[11];
    if(kontkod_osobe == 10)
        throw std::logic_error("JMBG nije validan");
    if(kontkod_osobe == 11)
        kontkod_osobe = 0;
        
    zadnji = this;
}

GradjaninBiH::GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja,int godina_rodjenja, int sifra_regije, Pol pol)
: ime_i_prezime(ime_i_prezime),regija(sifra_regije),pol(pol),datum(dan_rodjenja,mjesec_rodjenja,godina_rodjenja),prethodni(nullptr)
{
    if(regija < 0 || regija > 99)
        throw std::logic_error("Neispravni podaci");
    static GradjaninBiH *pred;
    if(!prvi) prvi = this;
    else prethodni = pred;
    pred = this;
    GradjaninBiH *privremeni = this;
    if(pol == 0)
        kod_osobe = 0;
    else if(pol == 1)
        kod_osobe=500;
    while(privremeni->prethodni != nullptr && privremeni->prethodni != this){
        if(privremeni != this && pol == privremeni->pol && regija == privremeni->regija && datum.dan_rodjenja == privremeni->datum.dan_rodjenja && datum.mjesec_rodjenja == privremeni->datum.mjesec_rodjenja && datum.godina_rodjenja == privremeni->datum.godina_rodjenja){
            if(kod_osobe == privremeni->kod_osobe)
                kod_osobe++;
            if(pol == 0 && kod_osobe == 500)
                kod_osobe = 0;
            else if (pol == 1 && kod_osobe == 1000)
                kod_osobe = 500;
        }
        privremeni = privremeni->prethodni;
    }
    //radim ovaj dio u 1 ujutro, mrsko mi išta pametnije smišljat, nadam se da neće sa ovime biti problema 
    JMBG[0] = (datum.dan_rodjenja/10)%10,JMBG[1] = dan_rodjenja%10,JMBG[2] = (datum.mjesec_rodjenja/10)%10,JMBG[3] = datum.mjesec_rodjenja%10,JMBG[4] = (datum.godina_rodjenja/100)%10,JMBG[5] = (datum.godina_rodjenja/10)%10,JMBG[6] = datum.godina_rodjenja%10,JMBG[7] = (regija/10)%10,JMBG[8] = regija%10;
    JMBG[9] = (kod_osobe/100)%10,JMBG[10] = (kod_osobe/10)%10,JMBG[11] = kod_osobe%10;
    JMBG[12] = 11-(7*(JMBG[0] + JMBG[6]) + 6*(JMBG[1]+JMBG[7]) + 5*(JMBG[2]+JMBG[8]) + 4*(JMBG[3]+JMBG[9]) + 3*(JMBG[4]+JMBG[10]) + 2*(JMBG[5]+JMBG[11]))%11;
    if(JMBG[12] == 11)
        JMBG[12] = 0;
    if(JMBG[12] == 10){
        kod_osobe++;
        JMBG[12] = 11-(7*(JMBG[0] + JMBG[6]) + 6*(JMBG[1]+JMBG[7]) + 5*(JMBG[2]+JMBG[8]) + 4*(JMBG[3]+JMBG[9]) + 3*(JMBG[4]+JMBG[10]) + 2*(JMBG[5]+JMBG[11]))%11;
    }
    zadnji = this;
}
long long int GradjaninBiH::DajJMBG() const{
    long long int JMBG(0),deset(1);
    for(int i(12); i > -1; i--)
        JMBG += GradjaninBiH::JMBG[i]*deset, deset *= 10;
    return JMBG;
}
GradjaninBiH::~GradjaninBiH(){
    GradjaninBiH *privremeni(zadnji);
    if(this != zadnji)
    while(privremeni->prethodni != this){
        privremeni = privremeni->prethodni;
    }
    else zadnji = this->prethodni;

    privremeni->prethodni = this->prethodni;
}