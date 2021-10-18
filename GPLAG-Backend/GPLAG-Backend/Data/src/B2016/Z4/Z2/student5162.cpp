/B 2016/2017, Zadaća 4, Zadatak 2
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <string>

class GradjaninBiH
{
    std::string ime_i_prezime;
    long long int jmbg;
  
public:
    enum Pol {Musko, Zensko};
    GradjaninBiH(std::string ime_i_prezime, long long int jmbg);
    GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja,
                 int godina_rodjenja, int sifra_regije, Pol pol);
    std::string DajImeIPrezime() const{return ime_i_prezime; }
    long long int DajJMBG() const{ return jmbg; }
    int DajDanRodjenja() const { return (DajCifru(0)*10+DajCifru(1)); }
    int DajMjesecRodjenja() const { return (DajCifru(2)*10+DajCifru(3)); }
    int DajGodinuRodjenja() const{ return (DajCifru(4)*100+DajCifru(5)*10 + DajCifru(6)); }
    int DajSifruRegije() const{ return (DajCifru(7)*10+DajCifru(8)); }
    Pol DajPol() const;
    void PromijeniImeIPrezime(std::string novo_ime){ this->ime_i_prezime=ime_i_prezime;}
};
GradjaninBiH::DajPol() const{
   
    else return Pol::Zensko;
}
bool test_jmbga(long long int jmbg){
    int niz[13];
    int i(0);
    while(jmbg!=0){
        int temp;
        temp=jmbg%10;
        jmbg/=10;
        niz[i]=temp;
        i++;
    }
    int a(niz[0]*10+niz[1]);
    int b(niz[2]*10 + niz[3]);
    if(a<0 || a>31) return false;
    if(b<0 || b>12) return false;
    int c(niz[4]*100+niz[5]*10+niz[6]);
    if(c<0 || (c>17 && c<917)) return false;
    int d(11-( 7 * (niz[0]+niz[6]) + 6 * (niz[1]+niz[7]) + 5 * (niz[2]+niz[8]) + 4 * (niz[3]+niz[9]) + 3 * (niz[4]+niz[10]) + 2 * (niz[5]+niz[11]) ) % 11 );
    if(niz[12]!=d || d==10) return false;
    return true;
    
}
GradjaninBiH::GradjaninBiH(std::string ime_i_prezime, long long int jmbg){
    if(!test_jmbga(jmbg)) throw std::logic_error ("JMBG nije validan");
    if(postojeci_jmbg(jmbg)) throw std::logic_error("Vec postoji gradjanin sa istim JMBG");
    
    this->ime_i_prezime=ime_i_prezime;
    this->jmbg=jmbg;
}
int main ()
{
    return 0;
}