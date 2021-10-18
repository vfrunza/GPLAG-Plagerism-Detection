/B 2016/2017, Zadaća 4, Zadatak 2
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <string>
#include <stdexcept>
class GradjaninBiH{
    std::string ime_i_prezime;
    long long int jmbg;
    GradjaninBiH *PrethodniGradjanin=nullptr;
    static GradjaninBiH *PosljednjiGradjanin;
    static bool TestDatuma(int , int ,int);
    int CifraJMBG(int) const;
    static int CifraJMBG(int,long long int);
    int DajKod() const{return CifraJMBG(10)*100+CifraJMBG(11)*10+CifraJMBG(12);}
    static int ValidanJMBG(long long int);
    public:
        GradjaninBiH(const GradjaninBiH &gradjanin) =delete;
        enum Pol {Musko,Zensko};
        ~GradjaninBiH();
        GradjaninBiH(std::string ime_i_prezime, long long int jmbg);
        GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol);
        std::string DajImeIPrezime() const;
        long long int DajJMBG() const;
        int DajDanRodjenja() const;
        int DajMjesecRodjenja() const;
        int DajGodinuRodjenja() const;
        int DajSifruRegije() const;
        Pol DajPol() const;
        void PromijeniImeIPrezime(std::string novo_ime);
};
int GradjaninBiH::ValidanJMBG(long long int jmbg){
    int cifra()
}
int GradjaninBiH::CifraJMBG(int cifra, long long int jmbg){
    if(jmbg<1000000000000){
        cifra--;    
        if(!cifra) return 0;
        for(int i=12;i>cifra;i--){jmbg/=10;}
        for(int i=1;i<cifra;i++){jmbg%=10;}
    }else{
        for(int i=13;i>cifra;i--){jmbg/=10;}
        for(int i=1;i<cifra;i++){jmbg%=10;}
    }
    return jmbg;
}
int GradjaninBiH::CifraJMBG(int cifra) const{
    long long int jmbg1(jmbg);
    if(jmbg1<1000000000000){
        cifra--;
        if(!cifra) return 0;
        for(int i=12;i>cifra;i--){jmbg1/=10;}
        for(int i=1;i<cifra;i++){jmbg1%=10;}
    }else{
        for(int i=13;i>cifra;i--){jmbg1/=10;}
        for(int i=1;i<cifra;i++){jmbg1%=10;}
    }
    return jmbg1;
}
bool GradjaninBiH::TestDatuma(int Dan,int Mjesec,int Godina){
    int DaniUMjesecu[]{31,28,31,30,31,30,31,31,30,31,30,31};
    if((Godina%4==0 && Godina%100!=0) || Godina%400==0) DaniUMjesecu[1]++;
    if(Mjesec<1 || Mjesec>12 || Dan<1 || Dan>DaniUMjesecu[Mjesec-1]) return false;
    return true;
}
std::string GradjaninBiH::DajImeIPrezime() const{return ime_i_prezime;}
long long int GradjaninBiH::DajJMBG() const{
    return jmbg;
}
int GradjaninBiH::DajDanRodjenja() const {return CifraJMBG(1)*10+CifraJMBG(2);}
int GradjaninBiH::DajMjesecRodjenja() const {return CifraJMBG(3)*10+CifraJMBG(4);}
int GradjaninBiH::DajGodinuRodjenja() const {
    int godina(CifraJMBG(5)*100+CifraJMBG(6)*10+CifraJMBG(7)); 
    if(godina<18) return 2000+godina;
    else return 1000+godina;
}
int GradjaninBiH::DajSifruRegije() const {return CifraJMBG(8)*10+CifraJMBG(9);}
GradjaninBiH::Pol GradjaninBiH::DajPol() const {
    int spol(CifraJMBG(10)*100+CifraJMBG(11)*10+CifraJMBG(12));
    if(spol>=500) return Zensko;
    return Musko;
}
void GradjaninBiH::PromijeniImeIPrezime(std::string novo_ime){std::getline(std::cin,ime_i_prezime);}
GradjaninBiH::GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol){
    if(!TestDatuma(dan_rodjenja,mjesec_rodjenja,godina_rodjenja) || sifra_regije>99 || sifra_regije<0) throw std::logic_error("Neispravni podaci");
    //provjera
}
GradjaninBiH::GradjaninBiH(std::string ime_i_prezime, long long int jmbg){
    
    //provjera
}
GradjaninBiH* GradjaninBiH::PosljednjiGradjanin(nullptr);
int main (){
	return 0;
}