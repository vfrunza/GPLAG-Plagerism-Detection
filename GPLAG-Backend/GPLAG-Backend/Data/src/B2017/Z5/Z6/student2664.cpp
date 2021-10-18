/B2017/2018: Zadaća 5, Zadatak 6
#include <iostream>
#include <cmath>
#include <stdexcept>

class Berza {
  int max_cijena, min_cijena;
  public:
  Berza(int min_cijena, max_cijena): {
      if(min_cijena < 0) throw std::domain_error("Ilegalne granicne cijene");
      else min_cijena = min_cijena;
      if(max_cijena < 0) throw std::domain_error("Ilegalne granicne cijene");
      else max_cijena = max_cijena;
  }
  Berza(int max_cijena) :{
      if(max_cijena < 0) throw std::domain_error("Ilegalne granicne cijene");
      else max_cijena = max_cijena;
      min_cijena = 0;
  }
  void RegistrirajCijenu(int nova_cijena){
      if(nova_cijena < min_cijena || nova_cijena > max_cijena) throw std::domain_error("Ilegalna cijena");
      
  }
  int DajBrojRegistriranihCijena() const {
      //return brojac;
  }
  Berza ~Berza(){};
  void BrisiSve() const{
      ~Berza();
  }
  int DajMinimalnuCijenu() const {
      //prostor za izuzetak
      return min_cijena;
  }
  int DajMaksimalnuCijenu() const {
      //prostor za izuzetak
      return max_cijena;
  }
  
  //unarni operator !
  
  int DajBrojCijenaVecihOd(int cijena) {
      int brojac(0);
      //preko veznika uraditi, i biblioteka iz algorithm i functional
      return brojac;
  }
  
  void Ispisi() const {
      //sortirati u opadajucem poretku
  }
  
  
};

int main ()
{
	return 0;
}
