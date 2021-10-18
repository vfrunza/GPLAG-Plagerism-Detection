/B2017/2018: Zadaća 5, Zadatak 6
#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <functional>
#include <iomanip>

class Berza
{
  std::vector<int> cijene_dionica;
  int max_cijena,min_cijena;

  public:
  Berza(int, int);
  explicit Berza(int);
  void RegistrirajCijenu(int);
  int DajBrojRegistriranihCijena()const;
  void BrisiSve();
  int DajMinimalnuCijenu()const;
  int DajMaksimalnuCijenu()const;
  bool operator!();
  int DajBrojCijenaVecihOd(const int&);
  void Ispisi()const;
  int operator[](int)const;
  friend Berza operator+(Berza, int);//
  friend Berza operator+(int,Berza);//
  friend Berza operator-(Berza,int);//
  friend Berza operator-(int,Berza);//
  friend Berza& operator+=(Berza&,int);//
  friend Berza& operator-=(Berza&,int);//
  friend bool operator ==(const Berza&, const Berza&);
  friend bool operator!=(const Berza&,const Berza&);
  friend Berza operator-(Berza,Berza);//
  friend Berza operator-(Berza);//
  friend Berza& operator++(Berza&);//
  friend Berza operator++(Berza);//
  friend Berza operator--(Berza);//
  friend Berza& operator--(Berza&);//
};

int main ()
{
  Berza a(0,10000);
  for(int i=100;i<10000;i+=100)
  {
    a.RegistrirajCijenu(i); 
  }
  a.Ispisi();
  Berza b(a);
  if(a==b)b.Ispisi();
  Berza c(0,20000);
  try{
    c=a-b;
    c.Ispisi();
  }catch(std::range_error izuzetak)
  {
    std::cout<<izuzetak.what();
  }
  catch(...)
  {
    std::cout<<"puff";
  }
	return 0;
}

bool operator!=(const Berza &a,const Berza &b)
{
  return !(a==b);
}
bool operator==(const Berza &a, const Berza &b)
{
  return (a.cijene_dionica==b.cijene_dionica);
}
Berza& operator +=(Berza &a, int b)
{
  a=a+b;
  return a;
}
Berza& operator-=(Berza& a,int b)
{
  a=a-b;
  return a;
}


Berza operator-(Berza a,Berza b)
{
  Berza c(a);
  if(a.cijene_dionica.size()!=b.cijene_dionica.size() || a.max_cijena!=b.max_cijena || a.min_cijena!=b.min_cijena)throw std::domain_error("Nesaglasni operandi");
  std::transform(a.cijene_dionica.begin(),a.cijene_dionica.end(),b.cijene_dionica.begin(),a.cijene_dionica.begin(),std::minus<int>());
  if(a.DajBrojCijenaVecihOd(a.max_cijena) || a.DajBrojCijenaVecihOd(a.min_cijena)-a.DajBrojRegistriranihCijena()>0 )throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
  return a;
}

Berza operator-(Berza a,int b)
{
  std::transform(a.cijene_dionica.begin(),a.cijene_dionica.end(),a.cijene_dionica.begin(),std::bind(std::minus<int>(),b,std::placeholders::_1));
  if(a.DajBrojCijenaVecihOd(a.max_cijena) || a.DajBrojCijenaVecihOd(a.min_cijena)-a.DajBrojRegistriranihCijena()>0 )throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
  return a;
}
Berza operator-(int b,Berza a)
{
  std::transform(a.cijene_dionica.begin(),a.cijene_dionica.end(),a.cijene_dionica.begin(),std::bind(std::minus<int>(),std::placeholders::_1,-b));
  if(a.DajBrojCijenaVecihOd(a.max_cijena) || a.DajBrojCijenaVecihOd(a.min_cijena)-a.DajBrojRegistriranihCijena()>0 )throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
  return a;
}
Berza operator+(int b, Berza a)
{
  return a+b;
}
Berza operator+(Berza a,int b)
{
  std::transform(a.cijene_dionica.begin(),a.cijene_dionica.end(),a.cijene_dionica.begin(),std::bind(std::plus<int>(),std::placeholders::_1,b));
  if(a.DajBrojCijenaVecihOd(a.max_cijena) || a.DajBrojCijenaVecihOd(a.min_cijena)-a.DajBrojRegistriranihCijena()>0 )throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
  return a;
}
Berza operator-(Berza a)
{
  std::transform(a.cijene_dionica.begin(),a.cijene_dionica.end(),a.cijene_dionica.begin(),std::bind(std::minus<int>(),-a.max_cijena-a.min_cijena,std::placeholders::_1));
  return a;
}
Berza operator++(Berza a)
{
  std::transform(a.cijene_dionica.begin(),a.cijene_dionica.end(),a.cijene_dionica.begin(),std::bind(std::plus<int>(),std::placeholders::_1,100));
  if(a.DajBrojCijenaVecihOd(a.max_cijena) || a.DajBrojCijenaVecihOd(a.min_cijena)-a.DajBrojRegistriranihCijena()>0 )throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
  return a;
}  
Berza operator --(Berza a)
{
  std::transform(a.cijene_dionica.begin(),a.cijene_dionica.end(),a.cijene_dionica.begin(),std::bind(std::plus<int>(),std::placeholders::_1,-100));
  if(a.DajBrojCijenaVecihOd(a.max_cijena) || a.DajBrojCijenaVecihOd(a.min_cijena)-a.DajBrojRegistriranihCijena()>0 )throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
  return a;
}
Berza& operator++(Berza &a)
{
  std::transform(a.cijene_dionica.begin(),a.cijene_dionica.end(),a.cijene_dionica.begin(),std::bind(std::plus<int>(),std::placeholders::_1,100));
  if(a.DajBrojCijenaVecihOd(a.max_cijena) || a.DajBrojCijenaVecihOd(a.min_cijena)-a.DajBrojRegistriranihCijena()>0 )throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
  return a;
}  
Berza& operator --(Berza &a)
{
  std::transform(a.cijene_dionica.begin(),a.cijene_dionica.end(),a.cijene_dionica.begin(),std::bind(std::plus<int>(),std::placeholders::_1,-100));
  if(a.DajBrojCijenaVecihOd(a.max_cijena) || a.DajBrojCijenaVecihOd(a.min_cijena)-a.DajBrojRegistriranihCijena()>0 )throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
  return a;
}

Berza::Berza(int poc, int kraj)
{
  if(poc<0 || kraj<0 || (poc>kraj))throw std::range_error("Ilegalne granicne cijene");
  max_cijena=kraj;
  min_cijena=poc;
}
Berza::Berza(int kraj)
{
  if(kraj<0)throw std::range_error("Ilegalne granicne cijene");
  min_cijena=0;max_cijena=kraj;
}
void Berza::RegistrirajCijenu(int a)
{
  if(a<min_cijena || a>max_cijena)throw std::range_error("Ilegalna cijena");
  cijene_dionica.push_back(a);
//  std::sort(cijene_dionica.begin(),cijene_dionica.end(),std::greater<int>());
}
int Berza::DajBrojRegistriranihCijena()const
{
  return cijene_dionica.size();
}
void Berza::BrisiSve()
{
 cijene_dionica.clear();
}
int Berza::DajMinimalnuCijenu()const
{
  return *min_element(cijene_dionica.begin(),cijene_dionica.end());
}
int Berza::DajMaksimalnuCijenu()const
{
  return *max_element(cijene_dionica.begin(),cijene_dionica.end());
}
bool Berza::operator!()
{
  return !static_cast<bool>(cijene_dionica.size());
}
int Berza::DajBrojCijenaVecihOd(const int& a)
{
  if(cijene_dionica.size()==0)throw std::range_error("Nema registriranih cijena");
  return std::count_if(cijene_dionica.begin(),cijene_dionica.end(),std::bind(std::less<int>(),a,std::placeholders::_1));
  return 0;
}
void Berza::Ispisi()const
{
  std::vector<int> temp(cijene_dionica);
  std::sort(temp.begin(),temp.end(),std::greater<int>());
  std::function<double(int)> f = std::bind(std::divides<double>(),std::placeholders::_1,100.);
  std::cout.precision(2);
  for(int i=0;i<DajBrojRegistriranihCijena();i++)
  {
    std::cout<<std::fixed<<f(temp[i])<<std::endl;
  }
}

int Berza::operator[](int a)const
{
  if(a>=DajBrojRegistriranihCijena())throw std::range_error("Neispravan indeks");
  return cijene_dionica[a];
}