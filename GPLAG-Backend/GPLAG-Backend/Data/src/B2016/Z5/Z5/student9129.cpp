/B16/17 (Zadaća 5, Zadatak 5)
//Autotestovi by Berina Cocalic (mail: student9129@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <list>
#include <stdexcept>
#include <utility>
#include <algorithm>
#include <functional>
#include <vector>
#include <iterator>
class Temperature
{
    std::list<int> Minimalne;
    std::list<int> Maximalne;
    int min, max;
public:
    Temperature(int mini, int maxi): min(mini), max(maxi){
        if(mini > maxi)
            throw std::range_error("Nekorektne temperature");
    }
    void RegistrirajTemperature(std::pair<int, int> par);
    void BrisiSve(){
        Minimalne.clear();
        Maximalne.clear();
    }
        void BrisiNegativneTemperature();
    int DajBrojRegistriranihTemperatura() const{ return Minimalne.size();}
    int DajMinimalnuTemperaturu() const;
    int DajMaksimalnuTemperaturu() const;
    int DajBrojTemperaturaVecihOd(int x) const;
    int DajBrojTemperaturaManjihOd(int x) const;
    friend bool operator !(const Temperature &t1){
        return(t1.Maximalne.size() == 0);
    }
    friend Temperature &operator ++(Temperature &t1);
    friend Temperature operator ++(Temperature &t1, int);
    friend Temperature &operator --(Temperature &t1);
    friend Temperature operator --(Temperature &t1, int);
    friend std::vector<int> operator *(const Temperature &t1);
    friend std::vector<int> operator -(const Temperature &t1);
    friend std::vector<int> operator +(const Temperature &t1);
    std::pair<int,int> operator [] (int x) const;
    friend bool operator ==(const Temperature &t1, const Temperature &t2);
    friend bool operator !=(const Temperature &t1, const Temperature &t2);
    friend Temperature operator +(const Temperature &t1, int x);
    friend Temperature operator -(const Temperature &t1, int x);
    friend Temperature operator +(int x, const Temperature &t1);
    friend Temperature operator -(int x, const Temperature &t1);
    friend Temperature &operator +=(Temperature &t1, int x);
    friend Temperature &operator -=(Temperature &t1, int x);
    friend Temperature &operator +=(int x, Temperature &t1);
    friend Temperature &operator -=(int x, Temperature &t1);
    friend std::ostream& operator <<(std::ostream& Itok, const Temperature &t1);
};
void Temperature::RegistrirajTemperature(std::pair<int, int> par){
    int mini = par.first;
    int maxi = par.second;
    if(mini > maxi || mini < min || maxi > max)
            throw std::range_error("Nekorektne temperature");
    Minimalne.push_back(mini);
    Maximalne.push_back(maxi);
}
void Temperature::BrisiNegativneTemperature(){
    static auto itMin = Minimalne.begin();
    static auto itMax = Maximalne.begin();
    if(itMax == Maximalne.end()){
        itMin = Minimalne.begin();
        itMax = Maximalne.begin();
        return;
    }
    if(*itMin < 0 && *itMax < 0){
        itMin = Minimalne.erase(itMin);
        itMax = Maximalne.erase(itMax);
        BrisiNegativneTemperature();
    }
    else{
        itMin++;
        itMax++;
        BrisiNegativneTemperature();
    }
}
int Temperature::DajMinimalnuTemperaturu() const{
    if(Minimalne.size() == 0)
        throw std::logic_error("Nema registriranih temperatura");
    return *std::min_element(Minimalne.begin(), Minimalne.end());
}
int Temperature::DajMaksimalnuTemperaturu() const{
        if(Minimalne.size() == 0)
        throw std::logic_error("Nema registriranih temperatura");
    return *std::max_element(Maximalne.begin(), Maximalne.end());
}
int Temperature::DajBrojTemperaturaVecihOd(int x) const{
    if(Minimalne.size() == 0)
        throw std::logic_error("Nema registriranih temperatura");
    int suma = std::count_if(Minimalne.begin(), Minimalne.end(), 
        std::bind(std::less<int>(), x, std::placeholders::_1));
    suma += std::count_if(Maximalne.begin(), Maximalne.end(), 
        std::bind(std::less<int>(), x, std::placeholders::_1));
    return suma;
}
int Temperature::DajBrojTemperaturaManjihOd(int x) const{
    if(Minimalne.size() == 0)
        throw std::logic_error("Nema registriranih temperatura");
    int suma = std::count_if(Maximalne.begin(), Maximalne.end(), 
        std::bind(std::greater<int>(), x, std::placeholders::_1));
    suma += std::count_if(Minimalne.begin(), Minimalne.end(), 
        std::bind(std::greater<int>(), x, std::placeholders::_1));
    return suma;
}
Temperature &operator ++(Temperature &t1){
    std::transform(t1.Minimalne.begin(), t1.Minimalne.end(), t1.Minimalne.begin(), 
        std::bind(std::plus<int>(), std::placeholders::_1, 1));
    if(!std::equal(t1.Minimalne.begin(), t1.Minimalne.end(), t1.Maximalne.begin(), std::less_equal<int>()))
        throw std::logic_error("Ilegalna operacija");
    return t1;
}
Temperature operator ++(Temperature &t1, int){
    Temperature pomocni = t1;
    std::transform(t1.Minimalne.begin(), t1.Minimalne.end(), t1.Minimalne.begin(), 
        std::bind(std::plus<int>(), std::placeholders::_1, 1));
    if(!std::equal(t1.Minimalne.begin(), t1.Minimalne.end(), t1.Maximalne.begin(), std::less_equal<int>()))
        throw std::logic_error("Ilegalna operacija");
    return pomocni;
}
Temperature &operator --(Temperature &t1){
    std::transform(t1.Maximalne.begin(), t1.Maximalne.end(), t1.Maximalne.begin(), 
        std::bind(std::minus<int>(), std::placeholders::_1, 1));
    if(!std::equal(t1.Maximalne.begin(), t1.Maximalne.end(), t1.Minimalne.begin(), std::greater_equal<int>()))
        throw std::logic_error("Ilegalna operacija");
    return t1;
}
Temperature operator --(Temperature &t1, int){
    Temperature pomocni = t1;
    std::transform(t1.Maximalne.begin(), t1.Maximalne.end(), t1.Maximalne.begin(), 
        std::bind(std::minus<int>(), std::placeholders::_1, 1));
    if(!std::equal(t1.Maximalne.begin(), t1.Maximalne.end(), t1.Minimalne.begin(), std::greater_equal<int>()))
        throw std::logic_error("Ilegalna operacija");
    return pomocni;
}
std::vector<int> operator *(const Temperature &t1){
    std::vector<int> v(t1.Minimalne.size());
    std::transform(t1.Maximalne.begin(), t1.Maximalne.end(), t1.Minimalne.begin(), v.begin(),
    std::minus<int>());
    return v;
}
std::vector<int> operator -(const Temperature &t1){
    std::vector<int> v(t1.Minimalne.size());
    std::transform(t1.Minimalne.begin(), t1.Minimalne.end(), v.begin(), 
        std::bind(std::minus<int>(), std::placeholders::_1, t1.min));
    return v;
}
std::vector<int> operator +(const Temperature &t1){
    std::vector<int> v(t1.Maximalne.size());
    std::transform(t1.Maximalne.begin(), t1.Maximalne.end(), v.begin(), 
        std::bind(std::minus<int>(), t1.max, std::placeholders::_1));
    return v;
}
std::pair<int, int> Temperature::operator [] (int x) const{
    if(x > DajBrojRegistriranihTemperatura() || x < 1)
        throw std::range_error("Neispravan indeks");
    std::vector<int> minimalna(Minimalne.size()), maximalna(Maximalne.size());
    std::copy(Minimalne.begin(), Minimalne.end(), minimalna.begin());
    std::copy(Maximalne.begin(), Maximalne.end(), maximalna.begin());
    return std::make_pair(minimalna[x-1], maximalna[x-1]);
}
bool operator ==(const Temperature &t1, const Temperature &t2){
    if(t1.min != t2.min || t1.max != t2.max)
        return false;
    if(!std::equal(t1.Minimalne.begin(), t1.Minimalne.end(), t2.Minimalne.begin(), std::equal_to<int>()))
        return false;
    if(!std::equal(t1.Maximalne.begin(), t1.Maximalne.end(), t2.Maximalne.begin(), std::equal_to<int>()))
        return false;
    return true;
}
bool operator !=(const Temperature &t1, const Temperature &t2){
    return !(t1 == t2);
}
Temperature operator +(const Temperature &t1, int x){
    Temperature t3(t1);
    std::transform(t3.Minimalne.begin(), t3.Minimalne.end(), t3.Minimalne.begin(), 
        std::bind(std::plus<int>(), std::placeholders::_1, x));
    std::transform(t3.Maximalne.begin(), t3.Maximalne.end(), t3.Maximalne.begin(), 
        std::bind(std::plus<int>(), std::placeholders::_1, x));
    int y = std::count_if(t3.Maximalne.begin(), t3.Maximalne.end(), 
        std::bind(std::less<int>(), t3.max, std::placeholders::_1));
    if(y != 0)
        throw std::logic_error("Prekoracen dozvoljeni opseg temperatura");
    return t3;
}
Temperature operator -(const Temperature &t1, int x){
    Temperature t3(t1);
    std::transform(t3.Minimalne.begin(), t3.Minimalne.end(), t3.Minimalne.begin(), 
        std::bind(std::minus<int>(), std::placeholders::_1, x));
    std::transform(t3.Maximalne.begin(), t3.Maximalne.end(), t3.Maximalne.begin(), 
        std::bind(std::minus<int>(), std::placeholders::_1, x));
    int y = std::count_if(t3.Minimalne.begin(), t3.Minimalne.end(), 
        std::bind(std::less<int>(), std::placeholders::_1, t3.min));
    if(y != 0)
        throw std::logic_error("Prekoracen dozvoljeni opseg temperatura");
    return t3;
}
Temperature operator +(int x, const Temperature &t1){   
    return t1 + x;
}
Temperature operator -(int x, const Temperature &t1){
    Temperature t3(t1);
    std::transform(t1.Minimalne.begin(), t1.Minimalne.end(), t3.Maximalne.begin(), 
        std::bind(std::minus<int>(), x, std::placeholders::_1));
    std::transform(t1.Maximalne.begin(), t1.Maximalne.end(), t3.Minimalne.begin(), 
        std::bind(std::minus<int>(), x, std::placeholders::_1));
    
    int y = std::count_if(t3.Minimalne.begin(), t3.Minimalne.end(), 
        std::bind(std::less<int>(), std::placeholders::_1, t3.min));
    if(y != 0)
        throw std::logic_error("Prekoracen dozvoljeni opseg temperatura");
    y = std::count_if(t3.Maximalne.begin(), t3.Maximalne.end(), 
        std::bind(std::less<int>(), t3.max, std::placeholders::_1));
    if(y != 0)
        throw std::logic_error("Prekoracen dozvoljeni opseg temperatura");
    return t3;
}
Temperature &operator +=(Temperature &t1, int x){
    return t1 = t1 + x;
}
Temperature &operator -=(Temperature &t1, int x){
    return t1 = t1 - x;
}
Temperature &operator +=(int x, Temperature &t1){
    return t1 = x + t1;
}
Temperature &operator -=(int x, Temperature &t1){
    return t1 = x - t1;
}
std::ostream& operator <<(std::ostream& Itok, const Temperature &t1)
{
    std::copy(t1.Minimalne.begin(), t1.Minimalne.end(), std::ostream_iterator<int>(Itok, " "));
    Itok << "\n";
    std::copy(t1.Maximalne.begin(), t1.Maximalne.end(), std::ostream_iterator<int>(Itok, " "));
    return Itok;
}
int main ()
{
    try
    {
        Temperature t(-30, 30);
            t.RegistrirajTemperature(std::make_pair(0, 10));
            t.RegistrirajTemperature(std::make_pair(2, 10));
            t.RegistrirajTemperature(std::make_pair(1, 10));
            t.RegistrirajTemperature(std::make_pair(-5, 15));
            t.RegistrirajTemperature(std::make_pair(-4, 14));
            t.RegistrirajTemperature(std::make_pair(1, 12));
            t.RegistrirajTemperature(std::make_pair(2, 10));
            t.RegistrirajTemperature(std::make_pair(0, 5));
            t.RegistrirajTemperature(std::make_pair(2, 7));
            
            std::cout << "Broj registriranih temperatura je: " << t.DajBrojRegistriranihTemperatura() << std::endl;
            std::cout << "Minimalna temperatura: " << t.DajMinimalnuTemperaturu() << std::endl;
            std::cout << "Maximalna temperatura: " << t.DajMaksimalnuTemperaturu() << std::endl;
            std::cout << "Broj temperatura vecih od 10: " << t.DajBrojTemperaturaVecihOd(10) << std::endl;
            std::cout << "Broj temperatura manjih od 6: " << t.DajBrojTemperaturaManjihOd(6) << std::endl;
            std::cout << "Temperature: " << std::endl;
            std::cout << t;
            t++;
            ++t;
            std::cout << std::endl << std::endl;
            std::cout << "Temperature poslije t++ i ++t: " << std::endl;
            std::cout << t;
            --t;
            t--;
            std::cout << std::endl << std::endl;
            std::cout << "Temperature poslijee t-- i --t: " << std::endl;
            std::cout << t;
            std::cout << std::endl << "Razlika izmedu minimalnih i maximalnih temperatura: " << std::endl;
            for(auto x: *t)
                std::cout << x << " ";
            std::cout << std::endl << std::endl << "Razlika izmedji minilanih i dozvoljene minimalne temperature: " << std::endl;
            for(auto x: -t)
                std::cout << x << " ";
            std::cout << std::endl << std::endl << "Razlika izmedji maximalnih i dozvoljene maximalne temperature: " << std::endl;
            for(auto x: +t)
                std::cout << x << " ";
        Temperature novi = t + 3;
        std::cout << "\n\n" << novi << std::endl << std::endl;
        std::cout << "Da li su t1 i novi razliciti: " << (t != novi) << std::endl;
        novi = novi - 3;
        std::cout << "Da li su t1 i novi isti nakon -3: " << (t == novi) << std::endl;
        novi.BrisiSve();
        std::cout << !novi << " Ako je 1 znaci da je novi obrisan!" << std::endl << std::endl;
        std::cout << t << std::endl;
        Temperature t1 = -10 - t;
        std::cout << t1;
        t1 += 3;
        std::cout << std::endl << t1;
        //! += -= su izvedeni iz + - tako da ne treba provjera
        auto p = t1[5];
        std::cout << std::endl << "Peta temperatura je: " << p.first << " " << p.second;
        std::cout << "\nObrisi negativne iz t1" << std::endl;
        t1.BrisiNegativneTemperature();
        std::cout << std::endl << t1;
    }
    
    catch(std::logic_error e)
    {
        std::cout << e.what();
    }
	return 0;
}