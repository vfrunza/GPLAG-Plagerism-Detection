/B2017/2018: Zadaća 5, Zadatak 6
#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <functional>
#include <iterator>
#include <iomanip>
class Berza {
    
    std::vector<int> cijene;
    int mini,maxi;
    public: 
    
    Berza(int minimum, int maximum);
    explicit Berza(int maximum);
    void RegistrirajCijenu(int nova);
    int DajBrojRegistriranihCijena() const { return cijene.size(); }
    void BrisiSve();
    int DajMinimalnuCijenu() const;
    int DajMaksimalnuCijenu() const;
    bool operator !(){
        return cijene.size() == 0;
    }
    int DajBrojCijenaVecihOd(int broj) const;
    void Ispisi() const;
    int operator [] (int i) const;
    // prefixni
    friend Berza &operator ++(Berza &b){
        Berza nova(b);
        std::vector<int> marka(b.cijene.size(),100);
        std::transform(nova.cijene.begin(),nova.cijene.end(), marka.begin(), nova.cijene.begin(), std::plus<int>());
        if(nova.DajMaksimalnuCijenu() > nova.maxi)throw std::range_error("Prekoracen dozvoljeni opseg cijena");
        b = nova;
        return b;
    }
    // postfixni
    friend Berza operator ++(Berza &b, int){
        Berza nova(b);
        ++b;
        return nova;
    }
    Berza &operator - ();
    friend bool operator == (const Berza &a, const Berza &b){
        return a.cijene == b.cijene && a.mini == b.mini && a.maxi == b.maxi;
    }
    friend bool operator != (const Berza &a, const Berza &b){
        return a.cijene != b.cijene || a.mini != b.mini || a.maxi != b.maxi;
    }
};



Berza &Berza::operator -() {
    Berza nova(*this);
    std::vector<int> nove_cijene(cijene.size(), maxi+mini);
    std::transform(nove_cijene.begin(), nove_cijene.end(),nova.cijene.begin(), nova.cijene.begin(), std::minus<int>());
    return nova;
}
int Berza::operator [](int i) const {
    if(i<0 || i>=cijene.size()) throw std::range_error("Neispravan indeks");
    return cijene[i];
}
void Berza::Ispisi() const {
    std::vector<int> v(cijene);
    std::sort(v.begin(),v.end(),std::greater<int>());
    std::vector<double> novi(v.size(),100);
    std::transform(v.begin(),v.end(),novi.begin(), novi.begin(), std::divides<double>());
    std::remove_copy(novi.begin(),novi.end(),std::ostream_iterator<double>(std::cout<<std::fixed<<std::setprecision(2), "\n"),-1);
}

int Berza::DajBrojCijenaVecihOd(int broj) const {
    
    if(cijene.size() == 0) throw std::range_error("Nema registriranih cijena");
    return std::count_if(cijene.begin(), cijene.end(), 
        std::bind(std::greater<int>(), std::placeholders::_1, broj));
}
int Berza::DajMinimalnuCijenu() const {
    if(cijene.size() == 0) throw std::range_error("Nema registriranih cijena");
    return *std::min_element(cijene.begin(),cijene.end());
}

int Berza::DajMaksimalnuCijenu() const {
    if(cijene.size() == 0) throw std::range_error("Nema registriranih cijena");
    return *std::max_element(cijene.begin(),cijene.end());
}
void Berza::BrisiSve() {
    cijene.clear();
    cijene.resize(0);
}

Berza::Berza(int minimum, int maximum){
    if(minimum< 0 || maximum <= 0 || maximum < minimum)
        throw std::range_error("Ilegalne granicne cijene");
    mini = minimum;
    maxi = maximum;
}

Berza::Berza(int maximum){
    if(maximum<=0)throw std::range_error("Ilegalne granicne cijene");
    mini = 0;
    maxi = maximum;
}

void Berza::RegistrirajCijenu(int nova){
    if(nova<mini || nova > maxi)throw std::range_error("Ilegalna cijena");
    cijene.push_back(nova);
}


int main ()
{
    Berza b(1,25000);
    b.RegistrirajCijenu(200);
    b.RegistrirajCijenu(400);
    b.RegistrirajCijenu(600);
    b.RegistrirajCijenu(210);
    b.RegistrirajCijenu(220);
    b.RegistrirajCijenu(230);
    b.Ispisi();
    std::cout<<b.DajBrojCijenaVecihOd(0)<<std::endl;
    
	return 0;
}
