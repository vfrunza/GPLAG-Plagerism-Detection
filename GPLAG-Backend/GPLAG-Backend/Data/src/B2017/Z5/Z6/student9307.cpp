/B2017/2018: Zadaća 5, Zadatak 6
#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <functional>
#include <iomanip>

class Berza {
  std::vector<int> cijene_dionica;
  int maks,min;
  public:
  
  Berza (int min, int maks) : maks(maks), min(min) {
      if (maks<0 || min<0 || min>maks) throw std::range_error ("Ilegalne granice cijene");
  }
  
  explicit Berza (int maks) : maks(maks), min(0) {
      if (maks<0) throw std::range_error ("Ilegalne granice cijene");
  }
  
  void RegistrirajCijenu (int cijena) {
      if (cijena<min || cijena>maks) throw std::range_error ("Ilegalna cijena");
      cijene_dionica.push_back(cijena);
  }
  
  int DajBrojRegistriranihCijena () const {
      return cijene_dionica.size();
  }
  
  void BrisiSve () {
      cijene_dionica.resize(0);
  }
  
  int DajMinimalnuCijenu () const {
      if (cijene_dionica.size()==0) throw std::range_error ("Nema registriranih cijena");
      return *std::min_element(cijene_dionica.begin(), cijene_dionica.end());
  }
  
  int DajMaksimalnuCijenu () const {
      if (cijene_dionica.size()==0) throw std::range_error ("Nema registriranih cijena");
      return *std::max_element(cijene_dionica.begin(), cijene_dionica.end());
  }
  
  bool operator ! (){
      return !cijene_dionica.size();
  }
    
  int DajBrojCijenaVecihOd (int cijena) const; 
  
  void Ispisi () const;
  
  int operator [] (int indeks){
      if (indeks<1 || indeks>cijene_dionica.size()) throw std::range_error ("Neispravan indeks");
      return cijene_dionica.at(indeks-1);
  }
  
  std::vector<int> &operator ++();
  
  std::vector<int> &operator --();
  
  std::vector<int> operator ++(int);
  
  std::vector<int> operator --(int);
  
  Berza operator - ();
  
  bool operator == (const Berza &berza) const;
  
  bool operator != (const Berza &berza) const;
  
  Berza operator - (const Berza &beza) const;
  
  Berza operator + (int y) const;
  
  Berza operator - (int y) const;
  
  friend Berza operator + (int x,const Berza& berza);
  
  friend Berza operator - (int x, const Berza& berza);
  
  Berza& operator += (int x);
  
  Berza& operator -= (int x);
};

struct ispis {
    void operator () (int x) { std::cout<<std::fixed<<std::setprecision(2)<<double(x)/100<<std::endl; }
};

struct marka_ko_tepsija{
    const int maks;
        public:
        marka_ko_tepsija (int maks) : maks(maks) {}
        int operator () (int &x) {
        if ((x+100)>maks) throw std::range_error("Prekoracen dozvoljeni opseg cijena");
        x=x+100;
        return x;
    }
};

struct marka_ko_tepsija_vol2{
    const int min;
    public:
    marka_ko_tepsija_vol2 (int min) : min(min) {}
    int operator () (int &x) {
        if ((x-100)<min) throw std::range_error ("Prekoracen dozvoljeni opseg cijena");
        x=x-100;
        return x;
    }
};

struct nova_berza {
    const int zbir;
    public:
    nova_berza (int zbir) : zbir(zbir) {}
    int operator () (int &x) {
        x=zbir-x;
        return x;
    }
};

struct da_li_su_iste {
    public:
    bool operator () (int x, int y){
        return x==y;
    }
};

struct oduzmi_dvije_berze{
    const int min;
    public:
    oduzmi_dvije_berze (int min) : min(min) {}
    int operator () (int x, int y){
        if ((x-y)<min) throw std::domain_error ("Prekoracen dozvoljeni opseg");
        return x-y;
    }
};

struct saberi_pare_i_berzu{
    const int maks,y;
    public:
    saberi_pare_i_berzu (int maks, int y) : maks(maks),y(y)  {}
    int operator () (int &x){
        if ((x+y)>maks) throw std::domain_error ("Prekoracen dozvoljeni opseg");
        x=x+y;
        return x;
    }
};

struct oduzmi_pare_i_berzu{
    const int min,y;
    public:
    oduzmi_pare_i_berzu (int min, int y) : min(min),y(y)  {}
    int operator () (int &x){
        if ((x-y)<min) throw std::domain_error ("Prekoracen dozvoljeni opseg");
        x=x-y;
        return x;
    }
};

struct oduzmi{
    const int min,y;
    public:
    oduzmi (int min, int y) : min(min), y(y) {}
    int operator () (int &x){
        if ((y-x)<min) throw std::domain_error ("Prekoracen dozvoljeni opseg");
        x=y-x;
        return x;
    }
};

int Berza::DajBrojCijenaVecihOd(int cijena) const {
    if (cijene_dionica.size()==0) throw std::range_error ("Nema registriranih cijena");
    return std::count_if(cijene_dionica.begin(), cijene_dionica.end(),std::bind( std::greater<int>(), std::placeholders::_1, cijena));
}

void Berza::Ispisi () const {
    std::vector<int> kopija=(cijene_dionica);
    std::sort(kopija.begin(), kopija.end(), std::greater<int>());
    std::for_each(kopija.begin(), kopija.end(), ispis());
}

std::vector<int>& Berza::operator ++() {
    std::for_each (cijene_dionica.begin(), cijene_dionica.end(), marka_ko_tepsija(maks));
    return cijene_dionica;
}

std::vector<int>& Berza::operator --() {
    std::for_each(cijene_dionica.begin(), cijene_dionica.end(), marka_ko_tepsija_vol2(min));
    return cijene_dionica;
}

std::vector<int> Berza::operator ++(int) {
    std::vector<int> kopija=cijene_dionica;
    std::for_each (cijene_dionica.begin(), cijene_dionica.end(), marka_ko_tepsija(maks));
    return kopija;
}

std::vector<int> Berza::operator --(int) {
    std::vector<int> kopija=cijene_dionica;
    std::for_each (cijene_dionica.begin(), cijene_dionica.end(), marka_ko_tepsija_vol2(min));
    return kopija;
}

Berza Berza::operator -(){
    std::for_each(cijene_dionica.begin(), cijene_dionica.end(), nova_berza(maks+min));
    return *this;
}

bool Berza::operator == (const Berza &berza) const {
    if (cijene_dionica.size()!=berza.cijene_dionica.size()) return false;
    if (!std::equal(cijene_dionica.begin(), cijene_dionica.end(), berza.cijene_dionica.begin(), da_li_su_iste())) return false;
    return true;
}

bool Berza::operator !=(const Berza &berza) const {
    if (cijene_dionica.size()!=berza.cijene_dionica.size()) return true;
    if (std::equal(cijene_dionica.begin(), cijene_dionica.end(), berza.cijene_dionica.begin(), da_li_su_iste())) return false;
    return true;
}

Berza Berza::operator - (const Berza &berza) const {
    if (cijene_dionica.size() != berza.cijene_dionica.size() || maks!=berza.maks || min!=berza.min) throw std::domain_error ("Nesaglasni operandi");
    Berza vrati(min,maks);
    vrati.cijene_dionica.resize(cijene_dionica.size());
    std::transform(cijene_dionica.begin(), cijene_dionica.end(), berza.cijene_dionica.begin(), vrati.cijene_dionica.begin(), oduzmi_dvije_berze(min));
    return vrati;
}

Berza Berza::operator + (int y) const {
    Berza kopija(*this);
    std::for_each(kopija.cijene_dionica.begin(), kopija.cijene_dionica.end(), saberi_pare_i_berzu(maks, y));
    return kopija;
}

Berza Berza::operator - (int y) const {
    Berza kopija(*this);
    std::for_each(kopija.cijene_dionica.begin(), kopija.cijene_dionica.end(), oduzmi_pare_i_berzu(min, y));
    return kopija;
}

Berza operator + (int x, const Berza& berza){
    return berza+x;
}

Berza operator -(int x, const Berza& berza){
    Berza kopija(berza);
    std::for_each(kopija.cijene_dionica.begin(), kopija.cijene_dionica.end(), oduzmi(berza.min, x));
    return kopija;
}

Berza& Berza::operator +=(int x){
    *this=*this+x;
    return *this;
}

Berza& Berza::operator -=(int x){
    *this=*this-x;
    return *this;
}

int main ()
{
    try {
        Berza berza(4,50), b2(2500);
        Berza b1 = Berza(0,2500);
        b1.RegistrirajCijenu(1200);
        b1.RegistrirajCijenu(1000);
        b2.RegistrirajCijenu(1000);
        b2.RegistrirajCijenu(500);
        (b1-b2).Ispisi();
        //b1.BrisiSve();
        if (b1==b2) std::cout<<"Iste su";
        else std::cout<<"razlicite su";
        std::cout<<b1.DajBrojCijenaVecihOd(1000);
        (-b1).Ispisi();
        b1-=500;
        (b1).Ispisi();
        berza.RegistrirajCijenu(5);
        berza.RegistrirajCijenu(25);
        std::cout<<berza[3];
        b1.BrisiSve();
        std::cout<<std::boolalpha<<(!berza)<<std::endl;
        std::cout<<berza.DajBrojRegistriranihCijena()<<" "<<berza.DajMinimalnuCijenu()<<" "<<berza.DajMaksimalnuCijenu();
    }catch (std::range_error iz){
        std::cout<<iz.what();
    }
    catch (std::domain_error iz){
        std::cout<<iz.what();
    }
	return 0;
}
