/B2017/2018: Zadaća 5, Zadatak 6
#include <iostream>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <iomanip>

class Berza 
{
    
    std::vector<int> v;
    static int broj_registrovanih;
    public:
    Berza(int min, int max) 
    {
        if (max < 0 || min < 0) throw std::range_error ("Ilegalne granicne cijene");
        this->v.push_back(min);
        this->v.push_back(max);
    }
    
    Berza (int max)
    {
        if (max < 0) throw std::range_error ("Ilegalne granicne cijene");
        this->v.push_back('0');
        this->v.push_back(max);
        
    }
    
    void RegistrirajCijenu (int min, int max)
    {
        if (max > v[1] || min < v[0]) throw std::range_error ("Ilegalna cijena");
        v.push_back(min);
        v.push_back(max);
    }
    
    void RegistrirajCijenu (int max)
    {
        if (max > v[1]) throw std::range_error ("Ilegalne granicne cijene");
        v.push_back(max);
        broj_registrovanih = broj_registrovanih + 1;
    }
    
    int DajBrojRegistriranihCijena() const { return broj_registrovanih; }
    
    void BrisiSve()
    {
      broj_registrovanih = 0;
    }
    
    int DajMinimalnuCijenu() const 
    {
        if (broj_registrovanih = 0) throw std::range_error ("Nema registriranih cijena");
        int min = *(std::min_element(v.begin()+2, v.end()));
        return min;
    }
    
    int DajMaksimalnuCijenu() const
    {
        if (broj_registrovanih = 0) throw std::range_error ("Nema registriranih cijena");
        int max = *(std::max_element(v.begin()+2, v.end()));
        return max;
    }
    
    void Ispisi() const
    {
        
        std::sort(v.begin()+2, v.end(), std::less<int>());
        
    }
    
};
int Berza::broj_registrovanih = 0;

int main ()
{
    Berza b1 = Berza(1000,4000);
    b1.RegistrirajCijenu(3000);
    b1.RegistrirajCijenu(1500);
    
    std::cout << b1.DajBrojRegistriranihCijena();
    
    b1.BrisiSve();
    std::cout << b1.DajBrojRegistriranihCijena();
	return 0;
}
