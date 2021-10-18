/B2017/2018: Zadaća 5, Zadatak 6
#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>

class Berza{
  std::vector<int> cijene;
  int maks_cijena;
  int min_cijena;
public:
  Berza (int maks_cijena, int min_cijena) : maks_cijena(maks_cijena), min_cijena(min_cijena) {
      if (maks_cijena<0 || min_cijena<0 || min_cijena>maks_cijena) throw std::range_error("Ilegalne granicne cijene");
  }
  explicit Berza (int maks_cijena) : maks_cijena(maks_cijena), min_cijena(0) {
      if (maks_cijena<0) throw std::range_error("Ilegalne granicne cijene");
  }
  friend void RegistrirajCijenu (Berza &b, int cijena);
  int DajBrojRegistriranihCijena() const { return Berza::cijene.size(); }
  void BrisiSve();
  friend int DajMinimalnuCijenu() const;
  friend int DajMaksimalnuCijenu() const;
  friend bool operator !(const Berza &b);
  int DajBrojCijenaVecihOd(int parametar) const;
  void Ispisi(Berza &b) const;
  int operator [](const Berza &b);
  friend Berza operator ++(Berza &b);
  friend Berza operator --(Berza &b);
  friend Berza operator ++(Berza &b, int);
  friend Berza operator - (Berza &b);
  friend Berza operator - (const Berza &b1, const Berza &b2);
  friend Berza operator + (const Berza &b1, const Berza &b2);
  friend Berza operator +=(Berza &b1, const Berza &b2);
  friend Berza operator -=(Berza &b1, const Berza &b2);
  friend Berza operator ==(const Berza &b1, const Berza &b2);
  friend Berza operator !=(const Berza &b1, const Berza &b2);
};

void RegistrirajCijenu(Berza &b, int cijena) {
    if (cijena<b.min_cijena || cijena>b.maks_cijena) throw std::range_error("Ilegalna cijena");
    b.cijene.push_back(cijena);
}
void BrisiSve() { std::vector<int> a; Berza::cijene=a; }

int DajMinimalnuCijenu() {
    int broj(Berza::cijene.size());
    if (Berza::DajBrojRegistriranihCijena()==0) throw std::range_error("Nema registriranih cijena");
    return *std::max_element(Berza::cijene, Berza::cijene+broj);
}
int DajMaksimalnuCijenu() {
    int broj(Berza::cijene.size());
    if (Berza::DajBrojRegistriranihCijena()==0) throw std::range_error("Nema registriranih cijena");
    return *std::min_element(Berza::cijene, Berza::cijene+broj);
}
bool operator !(const Berza &b) { 
    if (b.DajBrojRegistriranihCijena()==0) 
        return true;
    return false;
}
void Ispisi(Berza &b){
    std::vector<int> v(b.cijene);
    std::sort(v.begin(), v.end(), std::greater<int>());
    for (int i=0; i<v.size(); i++)
        std::cout<<(double)(v[i])/100 <<std::endl;
}
int main ()
{
	return 0;
}
