/B 2016/2017, Zadaća 4, Zadatak 2
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <string>
#include <stdexcept>
enum Pol{Musko, Zensko};
class GradjaninBiH{
    std::string ime_i_prezime;
    long long int jmbg;
    GradjaninBiH *pok=nullptr;
    static GradjaninBiH *pok_na_zadnjeg=nullptr;
    Pol pol;
    bool JelDobar(int d, int m, int g){
        int brojdana[12]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if((g % 4 == 0 && g % 100 != 0 )|| g % 400 == 0) brojdana[1]++;
        if(g < 1 || d < 1 || m < 1 || m > 12 || d > brojdana[m-1])return false;
        return true;
    }
    public:
    int DajDanRodjenja() const;
    int DajMjesecRodjenja() const;
    int DajGodinuRodjenja() const;
    int DajSifruRegije() const;
    Pol DajPol()const;
    void PromijeniImeIPrezime(std::string novoime){ime_i_prezime = novoime;}
    GradjaninBiH(std::string ime_i_prezime, long long int jmbg);
    GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja,int sifra_regije,Pol pol){
        bool a=JelDobar(dan_rodjenja,mjesec_rodjenja,godina_rodjenja);
        if(a==false || sifra_regije<0 || sifra_regije>99)throw std::logic_error("Neispravni podaci");
        
        GradjaninBiH::ime_i_prezime=ime_i_prezime;
        
    }
};

Pol GradjaninBiH::DajPol()const{
    int c[13];
    long long int jbg = jmbg;
    for(int i=0; i<13; i++){
        int cifra = jbg%10;
        c[12-i]=cifra;
        jbg/=10;
    }
    int polni = c[9]*100 + c[10]*10 + c[11];
    if(polni >= 0 || polni<=499)return Musko;
    else return Zensko;
}
int GradjaninBiH::DajDanRodjenja()const{
  int c[13];
    long long int jbg = jmbg;
    for(int i=0; i<13; i++){
        int cifra = jbg%10;
        c[12-i]=cifra;
        jbg/=10;
    }
     int dan_rodjenja = c[0]*10+c[1];
     return dan_rodjenja;
}
int GradjaninBiH::DajMjesecRodjenja()const{
    int c[13];
    long long int jbg = jmbg;
    for(int i=0; i<13; i++){
        int cifra = jbg%10;
        c[12-i]=cifra;
        jbg/=10;
    }
     int mjesec_rodjenja = c[2]*10+c[3];
     return mjesec_rodjenja;
}
int GradjaninBiH::DajSifruRegije()const{
    int c[13];
    long long int jbg = jmbg;
    for(int i=0; i<13; i++){
        int cifra = jbg%10;
        c[12-i]=cifra;
        jbg/=10;
    }
    int sifra_regije = c[7]*10+c[8];
    return sifra_regije;
}
int GradjaninBiH::DajGodinuRodjenja()const{
   int c[13];
    long long int jbg = jmbg;
    for(int i=0; i<13; i++){
        int cifra = jbg%10;
        c[12-i]=cifra;
        jbg/=10;
    }
    int godina_rodjenja;
    int godo=c[4]*100 + c[5]*10 + c[6];
    if(godo>17 && godo<=999)godina_rodjenja=1000+godo;
    else godina_rodjenja=2000+godo;
    return godina_rodjenja;
}
GradjaninBiH::GradjaninBiH(std::string ime_i_prezime, long long int jmbg){
    int c[13];
    long long int jbg = jmbg;
    for(int i=0; i<13; i++){
        int cifra = jbg%10;
        c[12-i]=cifra;
        jbg/=10;
    }
    int vr=11-(7*(c[0]+c[6])+ 6*(c[1]+c[7])+ 5*(c[2]+c[8])+ 4*(c[3]+c[9])+ 3*(c[4]+c[10])+ 2*(c[5]+c[11]));
    int dan_rodjenja = c[0]*10+c[1];
    int mjesec_rodjenja = c[2]*10+c[3];
    int godo=c[4]*100 + c[5]*10 + c[6];
    int godina_rodjenja;
    if(godo>17 && godo<=999)godina_rodjenja=1000+godo;
    else godina_rodjenja=2000+godo;
    if(vr==10 || JelDobar(dan_rodjenja,mjesec_rodjenja,godina_rodjenja)==false)throw std::logic_error("JMBG nije validan");
    int polni = c[9]*100 + c[10]*10 + c[11];
    if(polni >= 0 || polni<=499)pol=Musko;
    else pol=Zensko;
    GradjaninBiH::jmbg=jmbg;
    GradjaninBiH::ime_i_prezime=ime_i_prezime;
    
}


int main ()
{
    
	return 0;
}