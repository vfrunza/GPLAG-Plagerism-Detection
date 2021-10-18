#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <new>
#include <stdexcept>
#include <algorithm>
#include <utility>

enum Pol {Musko,Zensko};


class GradaninBiH {
    std::string ime_i_prezime;
   long long int jmbg;
    Pol pol_gradanina;
    GradaninBiH* prethodni=nullptr;
static GradaninBiH* zadnji;
    public: 
    GradaninBiH(std::string ime_i_prezime, long long int jmbg) {
                GradaninBiH(ime_i_prezime,DajDanRodjenja(),DajMjesecRodjenja(),DajGodinuRodjenja(),DajSifruRegije(),DajPol());
                GradaninBiH::zadnji=this;
    }
GradaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja,
 int godina_rodjenja, int sifra_regije, Pol pol);
std::string DajImeIPrezime() const {
    return ime_i_prezime;
}
long long int DajJMBG() const {
    return jmbg;
}
GradaninBiH* &DajPrethodnog(GradaninBiH* &trenutni) {
    return trenutni->prethodni;
}
GradaninBiH(const GradaninBiH &g)=delete;
GradaninBiH &operator=(const GradaninBiH &g)=delete;
int DajDanRodjenja() const;
int DajMjesecRodjenja() const;
int DajGodinuRodjenja() const;
int DajSifruRegije() const;
Pol DajPol() const {
    return pol_gradanina;
}
void PromijeniImeIPrezime(std::string novo_ime) {
    ime_i_prezime=novo_ime;
}
};
int DajBrojCifara(int d) {
    int broj(0);
    while(d!=0) {
        d/=10;
        broj++;
    }
    return broj;
}
GradaninBiH::GradaninBiH(std::string ime_i_prezime,int dan_rodjenja,int mjesec_rodjenja,int godina_rodjenja,int sifra_regije,Pol pol) {
    GradaninBiH::ime_i_prezime=ime_i_prezime;
   int brojdana[]={31,28,31,30,31,30,31,31,30,31,30,31};
    if(godina_rodjenja%4==0  && (godina_rodjenja%100!=0 || godina_rodjenja%400==0))
    brojdana[1]++;
    long long int broj(0);
    int cifra(0);
    for(int i=0;i<2;i++) {
    if(pol==Pol(i) && prethodni==nullptr) {
    cifra=11-(7*((dan_rodjenja/10)%10+godina_rodjenja%10)+6*(dan_rodjenja%10+(sifra_regije/10)%10)+5*((mjesec_rodjenja/10)%10+sifra_regije%10)+4*(mjesec_rodjenja%10)+3*((godina_rodjenja/100)%10)+2*((godina_rodjenja/10)%10))%11;
    if(cifra==11) {
        cifra=0;
    }
    else {
        if(cifra==10 || dan_rodjenja<1 || mjesec_rodjenja<1 || godina_rodjenja<1 || mjesec_rodjenja>12 || dan_rodjenja>brojdana[mjesec_rodjenja-1] || sifra_regije<0 || sifra_regije>99) {
            throw std::logic_error("JMBG nije validan");
        }
    }
    broj+=dan_rodjenja;
    broj=broj*pow(10,DajBrojCifara(mjesec_rodjenja))+mjesec_rodjenja;
    broj=broj*pow(10,DajBrojCifara(godina_rodjenja-1000))+godina_rodjenja;
    broj=broj*pow(10,DajBrojCifara(sifra_regije))+sifra_regije;
    if(pol==Pol::Musko) 
    broj=broj*pow(10,3);
    else 
    broj=broj*pow(10,3)+500;
    broj=broj*10+cifra;
    GradaninBiH::zadnji=this;
}
else {
    int n=1;
    if(pol==Pol(i) && prethodni!=nullptr) {
         broj+=dan_rodjenja;
    broj=broj*pow(10,DajBrojCifara(mjesec_rodjenja))+mjesec_rodjenja;
    broj=broj*pow(10,DajBrojCifara(godina_rodjenja-1000))+godina_rodjenja;
    broj=broj*pow(10,DajBrojCifara(sifra_regije))+sifra_regije;
    if(pol==Pol::Musko) 
    broj=broj*pow(10,3)+n;
    else 
    broj=broj*pow(10,3)+500+n;
    broj=broj*10+cifra;
    GradaninBiH* pok(GradaninBiH::zadnji);
        while(pok->prethodni!=nullptr) {
               if(pok->DajJMBG()==broj) {
                   throw std::logic_error("Vec postoji gradjanin sa istim JMBG");
               }
               pok=pok->prethodni;
        }
     GradaninBiH::zadnji=this;
        GradaninBiH::zadnji=new GradaninBiH(ime_i_prezime,broj);
        n++;
    }
}
}
}
int DajBroj(long long int pomocni,int indeks,int broj_cifara) {
    int i(0),j(0),broj(0);
    while(i<indeks) {
        pomocni/=10;
        i++;
    }
while(j<broj_cifara) {
    broj=broj+pomocni%10*10;
}
return broj;
}
int GradaninBiH::DajDanRodjenja() const {
    return DajBroj(this->jmbg,12,2);
}

int GradaninBiH::DajMjesecRodjenja() const {
    return DajBroj(this->jmbg,10,2);
}

int GradaninBiH::DajGodinuRodjenja() const {
    int rezultat=DajBroj(this->jmbg,7,3);
    return rezultat+1000;
}
int GradaninBiH::DajSifruRegije() const {
        return DajBroj(this->jmbg,5,3);
}

int main ()
{
    std::cout<<"Unesite broj gradjana: ";
    int n,i(0);
    std::cin>>n;
    std::cin.ignore(1000,'\n');
    std::string ime;
    long long int licna;
    GradaninBiH::DajZadnjeg()=nullptr;
    while(i<n) {
    try {
    for(i=0;i<n;i++) {
	std::cout<<"Unesite podatke za "<<i+1<<". gradjanina: "<<std::endl;
	std::cout<<"Unesite ime gradjanina: ";
	std::getline(std::cin,ime);
	std::cout<<"Unesite jmbg gradjanina: ";
	std::cin>>licna;
	if(i==0) {
   GradaninBiH::zadnji=new GradaninBiH(ime,licna);
  GradaninBiH::zadnji->DajPrethodnog(GradaninBiH::zadnji)=nullptr;
    }
    else {
    GradaninBiH* pok(GradaninBiH::zadnji);
   GradaninBiH::zadnji=new GradaninBiH(ime,licna);
        GradaninBiH::zadnji->DajPrethodnog(GradaninBiH::zadnji)=pok;
    }
    }
    }
    catch(std::bad_alloc) {
        std::cout<<"Problemi sa memorijom";
        return 0;
    }
    catch(std::logic_error e) {
        std::cout<<e.what()<<std::endl;
        i--;
    }
    }
	return 0;
}