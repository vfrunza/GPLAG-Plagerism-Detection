/B 2016/2017, Zadaća 4, Zadatak 2
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <cstring>
#include <cmath>
#include <stdexcept>
#include <vector>
enum Pol{
    Musko,Zensko
};
class GradjaninBiH{
  std::string imeiprez;
  int dan,mjesec,godina,sifra;
  long long int JMBG;
  Pol pol;
  public:  
  GradjaninBiH(std::string ime_i_prezime);
  GradjaninBiH(std::string ime_i_prezime,int dan_rodjenja,int mjesec_rodjenja,int godina_rodjenja,int sifra_regije,Pol pol);
  std::string DajImeIPrezime()const;
  long long int DajJMBG()const;
  int DajDanRodjenja()const;
  int DajMjesecRodjenja()const;
  int DajGodinuRodjenja()const;
  int DajSifruRegije()const;
  Pol DajPol()const;
  void PromijeniImeIPrezime(std::string novo_ime);
  std::vector<int> SortirajUVektor(const long long int JMBG){
      std::vector<int> vektor;
      for(long long int i=JMBG;i=1;i/10){
          vektor.push_back(i%10);
      }
      return vektor;
  }
  bool ValidanJMBG();
};
int main ()
{
	return 0;
}