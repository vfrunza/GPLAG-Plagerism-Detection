#include <iostream>
#include <string>

class GradjaninBiH{
    std::string ime_i_prezime; 
    long long int jmbg;
    //GradjaninBiH* pokNaProslog;
  public:
    enum Pol{Musko, Zensko};
    GradjaninBiH (std::string ime_i_prezime, long long int jmbg){
        //Testiranje da li je jmbg validan
        //Test datuma, test posljednje cifre po formuli
        //Test ako neko vec ima taj broj
    }
    /*GradjaninBiH (std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol):(GradjaninBiH::ime_i_prezime(ime_i_prezime){
      //Baciti izuzetak ako podaci za datum neispravni ili sifra regije je m,anja od 0 a veca od 99
      // 
      
      int c1(dan_rodjenja/10), c2(dan_rodjenja%10), c3(mjesec_rodjenja/10), c4(mjesec_rodjenja%10), c5((godina_rodjenja/100)%10), c6((godina_rodjenja/10)%10), c7(godina_rodjenja%10), c8(sifra_regije/10), c9(sifra_regije%10), c10, c11, c12, c13;
      
      // fali c10 11 12
      
      for(;;){
            
          c13 = 11 - (7*(c1+c7) + 6*(c2+c8) + 5*(c3+c9) + 4* (c4 + c10) + 3*(c5 + c11) + 2*(c6 + c12))%11;
          if (c13 == 11) c13 = 0;
          if (c13 != 10) break;
      }
      
    }*/
    
    std::string DajImePrezime() const{
      return ime_i_prezime;
    }
    long long int DajJMBG() const{
        return jmbg;
    }
    int DajDanRodjenja() const{
        return jmbg/100000000000;
    }
    int DajMjesecRodjenja() const{
        return (jmbg/ 1000000000)%100;
    }
    int DajGodinuRodjenja() const{
        return (jmbg/ 1000000)%1000;
    }
    int DajSifruRegije() const{
        return (jmbg/ 10000)%100;
    }
    Pol DajPol() const{
        if ((jmbg/ 10)%1000 >= 0 && (jmbg/ 10)%1000 <= 499) return Musko;
        if ((jmbg/ 10)%1000 >= 500 && (jmbg/ 10)%1000 <= 999) return Zensko;
    }
    void PromijeniImeIPrezime(std::string novo_ime){
      ime_i_prezime = novo_ime;
    }
};

int main (){
    
	return 0;
}