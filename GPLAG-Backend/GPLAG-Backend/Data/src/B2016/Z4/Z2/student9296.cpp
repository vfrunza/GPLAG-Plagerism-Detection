/B 2016/2017, Zadaća 4, Zadatak 2
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <string>
#include <stdexcept>
class GradjaninBiH{
    std::string ime_i_prezime;
    int jmbg[13];
    static bool IspravnostDatuma(int d, int m, int g);
public:
    enum Pol{Musko, Zensko};
    GradjaninBiH(std::string ime_i_prezime, long long int jmbg);
    GradjaninBiH(std::string ime_i_prezime, int dan, int mjesec, int godina, int sifra, Pol pol);
    std::string DajImeIPrezime()const;
    long long int DajJMBG()const;
    int DajDanRodjenja()const;
    int DajMjesecRodjenja()const;
    int DajGodinuRodjenja()const;
    int DajSifruRegije()const;
    Pol DajPol()const;
    void PromijeniImeIPrezime(std::string novo);
};
GradjaninBiH::GradjaninBiH(std::string iip, long long int jmbg):ime_i_prezime(iip){
    if(!IspravnostDatuma(DajDanRodjenja(), DajMjesecRodjenja(), DajGodinuRodjenja()))
        throw std::logic_error("JMBG nije validan");
    
}
GradjaninBiH::GradjaninBiH(std::string iip, int d, int m, int g, int sifra, Pol pol){
    
}
bool IspravnostDatuma(int d, int m, int g){
    int dani[12]{31,28,31,30,31,30,31,31,30,31,30,31};
    if(g%4==0 && g%100!=0 || g%400==0) dani[1]++;
    if(g<1 || d<1 || m<1 || m>12 || d>dani[m-1]) return false;
    return true;
}
int main ()
{
	return 0;
}