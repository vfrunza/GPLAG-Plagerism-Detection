/B 2016/2017, Zadaća 4, Zadatak 2
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>
#include <string>
class GradjaninBiH
{
  int dan,mjesec,godina,sifraregije;
  long long int jmbg;
  std::string ime_prezime;
  static int muski_kod, zenski_kod;
  GradjaninBiH* prethodni;
  static GradjaninBiH* poslj_kreiran;
  public:
  enum Pol {Musko, Zensko};
  GradjaninBiH(std::string ime_i_prezime, long long int jmbg)
  {
    muski_kod=0;
    ime_prezime=ime_i_prezime; GradjaninBiH::jmbg=jmbg;
  }
};

int main ()
{
  GradjaninBiH("Mujota",131231);
   std::cout<<"a";
}