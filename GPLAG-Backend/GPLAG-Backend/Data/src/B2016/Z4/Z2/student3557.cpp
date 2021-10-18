#include <iostream>
#include <stdexcept>

enum Pol { Musko, Zensko };

 bool ProvjeriDatum(long long int jmbg) {
    int d = int(jmbg/100000000000);
    int m = int((jmbg/1e11 - int(jmbg/1e11))*100);
     int godina = ((jmbg/1e9 - int(jmbg/1e9))*1000); 
     if(godina >= 0 && godina <=17) godina +=2000;
     else if(godina >=917 && godina <=999) godina +=1000;
    int g = godina;
    long long int tmp = jmbg;
    int c[13]; int i(0);
    while (tmp != 0) {
        c[i] = tmp%10;
        tmp /=10;
        i++;
        if(i >= 13) throw std::logic_error("JMBG nije validan");
    }
    
    long long int cz = (jmbg/10 -int(jmbg/10))*10;
    long long int czadnje =11 -(7*(c[0]+c[6])+ 6*(c[1]+c[7]) +5*(c[2]+c[8])+4*(c[3]+c[9])+3*(c[4]+c[10])+2*(c[5]+c[11]))%11;
    
 int broj_dana[12] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
 if(g % 4 == 0 && g % 100 != 0 || g % 400 == 0) broj_dana[1]++;
 if(g <1 || d<1 || m<1 || m>12 || d > broj_dana[m-1] || cz != czadnje) throw std::logic_error("JMBG nije validan");
}

class GradjaninBiH {
  
  std::string ime_i_prezime; 
  long long int jmbg;
//  int dan_rodjenja, mjesec_rodjenja, godina_rodjenja, sifra_regije;
//  Pol pol;
  

  public:
    
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
 // KONSTRUKTORI DODATI !!!
GradjaninBiH::GradjaninBiH(std::string ime_i_prezime, long long int jmbg) {
     GradjaninBiH::ime_i_prezime = ime_i_prezime;
     GradjaninBiH::jmbg = jmbg;
 }

 
 
 long long int GradjaninBiH::DajJMBG() const { return jmbg; }
 int GradjaninBiH::DajDanRodjenja() const { return int(jmbg/100000000000);} 
 int GradjaninBiH::DajMjesecRodjenja() const { return int((jmbg/1e11 - int(jmbg/1e11))*100);}
 int GradjaninBiH::DajGodinuRodjenja() const { 
     int godina = ((jmbg/1e9 - int(jmbg/1e9))*1000); 
     if(godina >= 0 && godina <=17) godina +=2000;
     else if(godina >=917 && godina <=999) godina +=1000;
     return godina;
     }
     
 int GradjaninBiH::DajSifruRegije() const {
    return int((jmbg/1e6- int(jmbg/1e6))*100);
 }
 
 Pol GradjaninBiH::DajPol() const {
     int pol = ((jmbg/1e4- int(jmbg/1e4))*1000);
     if(pol >=0 && pol <=499) return Musko;
     else if(pol >=500 && pol <=999) return Zensko;
 }
 
 void GradjaninBiH::PromijeniImeIPrezime(std::string novo_ime) {
     GradjaninBiH::ime_i_prezime = novo_ime;
 }

int main ()
{
    int broj_gradjana;
    std::cout << "Koliko gradjana zelite unijeti po JMBG? ";
    std::cin >> broj_gradjana;
    
    GradjaninBiH gradjani(new GradjaninBiH *[broj_gradjana]);
    
	return 0;
}