#include <iostream>
#include <stdexcept>
#include <string>

class GradjaninBiH {
  std::string imeprezime;
  long long int maticni;
  int br(0);
  public:
  
GradjaninBiH(std::string ime_i_prezime, long long int jmbg){
    imeprezime=ime_i_prezime;
    maticni=jmbg;
    while(jmbg!=0){
      for(int i=0;i<13;i++){
        broj[i]=jmbg%10;
      jmbg=jmbg/10;
      br++;
    }
    
}
GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol){
  imeprezime=ime_i_prezime;
  
}
 enum Pol {Musko, Zensko};
 
std::string DajImeIPrezime() const{
  return imeprezime;
}
long long int DajJMBG() const;
int DajDanRodjenja() const;
int DajMjesecRodjenja() const;
int DajGodinuRodjenja() const;
int DajSifruRegije() const;
Pol DajPol() const{
return Pol;
}
void PromijeniImeIPrezime(std::string novo_ime);
  
  
};
int main ()
{
	return 0;
}