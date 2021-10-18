/B2017/2018: Zadaća 5, Zadatak 6
#include <iostream>
#include <algorithm>
#include <vector>
#include <stdexcept>
#include <functional>


using std::cout;
using std::cin;
using std::vector;


class Berza
{
    vector<int> vektor;
    int min, max;
    public:
    Berza (int min, int max)
    {
        if (min < 0 || max < 0)
            throw std::range_error("Ilegalne granicne cijene");
        
        Berza::min=min;
        Berza::max=max;
    }
    Berza (int max)
    {
        if (max < 0)
            throw std::range_error("Ilegalne granicne cijene");
        Berza::max=max;
        min=0;
    }
    void RegistrirajCijenu(int x);
    int DajBrojRegistriranihCijena()
    {
        return vektor.size();
    }
    
    void BrisiSve()
    {
        vektor.clear();
    }
    int DajMinimalnuCijenu();
    int DajMaksimalnuCijenu();
  /*  bool operator ! (const Berza b) const
    {
        if (b.DajBrojRegistriranihCijena() == 0)
            return true;
        return false;    
    }*/
   int DajBrojCijenaVecihOd(int broj)
   {
       if (DajBrojRegistriranihCijena() == 0)
            throw std::range_error("Nema registriranih cijena");
        return std::count_if(vektor.begin(), vektor.end(), std::bind(std::greater<int>(), std::placeholders::_1, broj));    
   }
   
   void Ispisi() const;
  // friend int operator [] (int indeks);
   /*{
       if (indeks < 0 || indeks >= vektor.size())
            throw std::range_error("Neispravan indeks");
        return vektor[indeks];    
   }*/
   
   friend Berza operator++(Berza &b, int);
   friend Berza &operator++(Berza &b);
   friend Berza operator--(Berza &b, int);
   friend Berza &operator--(Berza &b);
};

void Berza::RegistrirajCijenu(int x)
{
    if (x < min || x > max)
        throw std::range_error("Ilegalna cijena");
    vektor.push_back(x);    
}

int Berza::DajMinimalnuCijenu()
{
    if (DajBrojRegistriranihCijena() == 0)
        throw std::range_error("Nema registriranih cijena");
    auto pok=std::min_element(vektor.begin(), vektor.end());
    return *pok;
}

int Berza::DajMaksimalnuCijenu()
{
    if (DajBrojRegistriranihCijena() == 0)
        throw std::range_error("Nema registriranih cijena");
    auto pok=std::max_element(vektor.begin(), vektor.end());
    return *pok;    
}

/*
bool operator!(const Berza &b) const
{
    if (b.DajBrojRegistriranihCijena() == 0)
        return true;
    return false;    
}*/

/*
void Berza::Ispisi() const
{
    vector<double> pomocni1, pomocni2;
    for(int i=0; i<vektor.size(); i++)
    {
        pomocni1.push_back(100);
        pomocni2.push_back(vektor[i]);
    }    
     std::transform(pomocni2.begin(), pomocni2.end(), pomocni1, pomocni1, std::divides<double>());
     std::sort(pomocni1.begin(), pomocni1.end(), std::greater<double>());
    std::for_each(pomocni1.begin(), pomocni1.end(), [](double a)
    {
        cout<<a<<std::endl;
    });    
}*/
/*
int operator [] (int indeks) 
   {
       if (indeks < 0 || indeks >= vektor.size())
            throw std::range_error("Neispravan indeks");
        return vektor[indeks];    
   }*/
/*
Berza operator ++(Berza &b, int)
{
    vector<int> pomocni(b.vektor.size());
    
    std::transform(vektor.begin(), vektor.end(), pomocni.begin(), pomocni.begin(),std::plus<int>());
}*/

int main ()
{
    cout<<"aaa";
	return 0;
}
