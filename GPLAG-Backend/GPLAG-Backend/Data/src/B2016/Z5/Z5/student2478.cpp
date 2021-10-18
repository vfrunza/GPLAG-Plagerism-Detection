#include <iostream>
#include <functional>
#include <list>
#include <algorithm>
#include <stdexcept>
#include <vector>

class Temperature {
    std::list<int> minimalne;
    std::list<int> maksimalne;
    int min_temp;
    int max_temp;
    static void TrebaLiGaBaciti(std::list<int> listica){
        if(listica.size() == 0 || listica.size() == 0) throw std::logic_error("Nema registriranih temperatura");
}
public:
    Temperature(int mini, int maxi){ if(mini > maxi) throw std::range_error("Nekorektne temperature"); min_temp = mini; max_temp = maxi; }
    void RegistrirajTemperature(std::pair<int,int> par);
    void BrisiSve(){ minimalne.resize(0); maksimalne.resize(0); }
    void BrisiNegativneTemperature();
    int DajBrojRegistriranihTemperatura() const{ return minimalne.size(); }
    int DajMinimalnuTemperaturu() const{ TrebaLiGaBaciti(minimalne); return *std::min_element(minimalne.begin(), minimalne.end()); }
    int DajMaksimalnuTemperaturu() const{ TrebaLiGaBaciti(maksimalne); return *std::max_element(maksimalne.begin(), maksimalne.end()); }
    int DajBrojTemperaturaVecihOd(int temperatura) const;
    int DajBrojTemperaturaManjihOd(int temperatura) const;
    Temperature &operator ++();
    Temperature operator ++(int);
    Temperature &operator --();
    Temperature operator --(int);
    std::vector<int>operator *();
    std::vector<int> operator +();
    std::vector<int> operator -();
    std::pair<int,int> operator [](int indeks);
    friend bool operator !(const Temperature &t);
    
    void Ispisi() const{
        std::cout << "Minimalne: ";
        for(auto i(minimalne.begin()); i != minimalne.end(); i++)
            std::cout << *i << " ";
        std::cout << "\nMaksimalne: ";
        for(auto i(maksimalne.begin()); i != maksimalne.end(); i++)
            std::cout << *i << " ";
    }
};

void Temperature::RegistrirajTemperature(std::pair<int,int> par){
    if(par.first < min_temp || par.second < min_temp || par.first > max_temp || par.second > max_temp || par.first > par.second)
        throw std::range_error("Nekorektne temperature");
    minimalne.push_back(par.first); maksimalne.push_back(par.second);
}
void Temperature::BrisiNegativneTemperature(){
}
int Temperature::DajBrojTemperaturaVecihOd(int temperatura) const{
    TrebaLiGaBaciti(maksimalne);
    return std::count_if(maksimalne.begin(), maksimalne.end(), std::bind(std::greater<int>(), std::placeholders::_1, temperatura));
}
int Temperature::DajBrojTemperaturaManjihOd(int temperatura) const{
    TrebaLiGaBaciti(minimalne);
    return std::count_if(minimalne.begin(), minimalne.end(), std::bind(std::less<int>(), std::placeholders::_1, temperatura));
}
bool operator !(const Temperature &t){
    if(t.minimalne.size() == 0)return true;
    return false;
}
Temperature &Temperature::operator ++(){
    std::transform(minimalne.begin(), minimalne.end(),minimalne.begin(), std::bind(std::plus<int>(), std::placeholders::_1, 1));
    auto p = maksimalne.begin();
    int n = std::count_if(minimalne.begin(), minimalne.end(), std::bind(std::greater<int>(), std::placeholders::_1, *p++));
    if(n > 0) throw std::logic_error("Ilegalna operacija");
    return *this;
}
Temperature Temperature::operator ++(int){
    Temperature t(*this);
    *this = ++(*this);
    return t;
}
Temperature &Temperature::operator --(){
    std::transform(maksimalne.begin(), maksimalne.end(), maksimalne.begin(), std::bind(std::minus<int>(), std::placeholders::_1, 1));
    auto p = minimalne.begin();
    int n = std::count_if(maksimalne.begin(), maksimalne.end(), std::bind(std::less<int>(), std::placeholders::_1, *p++));
    if(n > 0) throw std::logic_error("Ilegalna operacija");
    return *this;
}
Temperature Temperature::operator --(int){
    Temperature t(*this);
    *this = --*this;
    return t;
}
std::vector<int> Temperature::operator *(){
    std::vector<int> novi(maksimalne.size());
    std::transform(maksimalne.begin(), maksimalne.end(), minimalne.begin(), novi.begin(), std::bind(std::minus<int>(), std::placeholders::_1, std::placeholders::_2));
    return novi;
}
std::vector<int> Temperature::operator +(){
    std::vector<int> novi(maksimalne.size());
    std::transform(maksimalne.begin(), maksimalne.end(), novi.begin(), std::bind(std::minus<int>(), max_temp, std::placeholders::_1));
    return novi;
}
std::vector<int> Temperature::operator -(){
    std::vector<int> novi(minimalne.size());
    std::transform(minimalne.begin(), minimalne.end(), novi.begin(), std::bind(std::minus<int>(), std::placeholders::_1, min_temp));
    return novi;
}
std::pair<int,int> Temperature::operator [](int indeks){
    if(indeks < 1 || indeks> minimalne.size()) throw std::range_error("Neispravan indeks");
    std::pair<int,int> par;
    return par;
}
int main ()
{
    try{
    Temperature t(2,6);
    t.RegistrirajTemperature({3,5});
    t.RegistrirajTemperature({4,6});
    t.Ispisi();
    std::cout << t[1].first << t[0].second;
        
    }catch(std::range_error iz){
        std::cout << iz.what();
    }catch(std::logic_error iz){
        std::cout << iz.what();
    }
	return 0;
}