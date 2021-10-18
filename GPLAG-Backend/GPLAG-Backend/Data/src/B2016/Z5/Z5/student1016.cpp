/B16/17 (Zadaća 5, Zadatak 5)
//Autotestovi by Berina Cocalic (mail: bcocalic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <list>
#include <stdexcept>
#include <algorithm>
#include <functional>
#include <vector>
#include <iterator>


class PomocnaFunkcijskaKlasa {
    std::ostream& n; 
public:
    PomocnaFunkcijskaKlasa(std::ostream &n) : n(n) {}
    std::ostream& operator ()(int x) { n<<x << " "; return n; }
};

class Temperature{
    int max_doz, min_doz, br=0;
    std::list<int> min, max;
    public:
    Temperature(int max, int min);
    void RegistrirajTemperature(std::pair<int, int> temp);
    void BrisiSve();
    void BrisiTemperature(std::pair<int, int> par);
    int DajBrojRegistriranihTemperatura() const;
    int DajBrojTemperaturaVecihOd(int temp) const;
    int DajBrojTemperaturaManjihOd(int temp) const ;
    int DajMaksimalnuTemperaturu() const;
    int DajMinimalnuTemperaturu() const;
    bool operator ! (){
        return min.size()==0;
    }
    void operator++();
    void operator--();
    Temperature operator++(int x);
    Temperature operator--(int x);
    std::vector<int> operator *();
    std::vector<int> operator -();
    std::vector<int> operator +();
    std::pair<int, int> operator [](int indeks) const;
    friend Temperature operator +(Temperature x, int n);
    friend Temperature operator +(int n, Temperature x);
    friend Temperature operator -(Temperature x, int n);
    friend Temperature operator -(int n, Temperature x);
    Temperature operator +=(int n);
    Temperature operator -=(int n);
    friend bool operator !=(Temperature t1, Temperature t2);
    friend bool operator ==(Temperature t1, Temperature t2);
    friend std::ostream& operator << (std::ostream& tok, Temperature t);
};

Temperature::Temperature(int min, int max){
    if(min>max) throw std::range_error("Nekorektne temperature");
    min_doz=min;
    max_doz=max;
    }
void Temperature::RegistrirajTemperature(std::pair<int, int> temp){
    if(temp.first<min_doz or temp.second<min_doz or temp.first>max_doz or temp.second>max_doz or temp.first>temp.second)
        throw std::range_error("Nekorektne temperature");
    min.push_back(temp.first);
    max.push_back(temp.second);
    br++;
}
void Temperature::BrisiSve(){
    min.resize(0);
    max.resize(0);
}
void Temperature::BrisiTemperature(std::pair<int,int> par){
    bool nadjen(false);
    for(auto it=min.begin(); it!=min.end(); it++){
        if(*it==par.first){
            auto itt=max.begin();
            for(itt=max.begin(); itt!=max.end(); itt++){
                if(*itt==par.second){ 
                    nadjen=true;
                    break;
                }
            }
            if(nadjen){
                min.erase(it);
                max.erase(itt);
            }
        }
    }
    if(!nadjen) throw std::logic_error ("Takve temperature nisu registrirane");
}
int Temperature::DajBrojRegistriranihTemperatura() const{
        return br;
}
                                                // Provjeriti da li treba i min i max porediti sa temp !!!!!
int Temperature::DajBrojTemperaturaVecihOd(int temp) const{
    if(max.size()==0) throw std::logic_error("Nema registriranih temperatura");
    return std::count_if(max.begin(), max.end(), std::bind(std::greater<int>(), std::placeholders::_1,temp));;
}
int Temperature::DajBrojTemperaturaManjihOd(int temp) const{
    if(min.size()==0) throw std::logic_error("Nema registriranih temperatura");
    return std::count_if(min.begin(), min.end(), std::bind(std::less<int>(),std::placeholders::_1, temp));
}
int Temperature::DajMaksimalnuTemperaturu() const{
    if(max.size()==0) throw std::logic_error("Nema registriranih temperatura");
    auto maximalna=std::max_element(max.begin(), max.end());
    return *maximalna;
}
int Temperature::DajMinimalnuTemperaturu() const{
    if(min.size()==0) throw std::logic_error("Nema registriranih temperatura");
    auto minimalna=std::min_element(min.begin(), min.end());
    return *minimalna;
}
void Temperature::operator++(){
    std::transform(min.begin(), min.end(),min.begin(), std::bind(std::plus<int>(),std::placeholders::_1,1));
    if(!std::equal(min.begin(),min.end(),max.begin(),std::less<int>())) throw std::logic_error ("Ilegalna operacija");
}
Temperature Temperature::operator++(int x){
    Temperature y(*this);
    ++(*this);
    return y;
}
void Temperature::operator--(){
    std::transform(max.begin(), max.end(),max.begin(), std::bind(std::minus<int>(),std::placeholders::_1,1));
    if(!std::equal(max.begin(),max.end(),min.begin(),std::greater<int>())) throw std::logic_error ("Ilegalna operacija");
}
Temperature Temperature::operator--(int x){
    Temperature y(*this);
    std::transform(max.begin(), max.end(),max.begin(), std::bind(std::minus<int>(),std::placeholders::_1,1));
    if(!std::equal(max.begin(),max.end(),min.begin(),std::greater<int>())) throw std::logic_error ("Ilegalna operacija");
    return y;
}
std::vector<int> Temperature::operator *(){
    std::vector<int> v(min.size());
    std::transform(max.begin(), max.end(),min.begin(),v.begin(), std::minus<int>());
    return v;
}
std::vector<int> Temperature::operator -(){
    std::vector<int> v(min.size());
    std::vector<int> x(min.size(), min_doz);
    std::transform(min.begin(), min.end(), x.begin(), v.begin(), std::minus<int>());
    return v;
}
std::vector<int> Temperature::operator +(){
    std::vector<int> v(min.size());
    std::vector<int> x(min.size(), max_doz);
    std::transform(x.begin(), x.end(), max.begin(), v.begin(), std::minus<int>());
    return v;
}
std::pair<int, int> Temperature::operator [](int indeks) const{
    if(indeks<0 or indeks>min.size()) throw std::range_error("Neispravan indeks");
    auto x=min.begin();
    auto y=max.begin();
    std::advance(y, indeks-1);
    std::advance(x, indeks-1);
    return std::make_pair(*x, *y);
}
Temperature operator +(Temperature x, int n){
    Temperature y(x);
    std::transform(y.max.begin(), y.max.end(), y.max.begin(), std::bind(std::plus<int>(),std::placeholders::_1,n));
    std::transform(y.min.begin(), y.min.end(), y.min.begin(), std::bind(std::plus<int>(),std::placeholders::_1,n));
    auto it1=std::find_if(y.max.begin(), y.max.end(), std::bind(std::greater<int>(),std::placeholders::_1,y.max_doz));
    auto it2=std::find_if(y.min.begin(), y.min.end(), std::bind(std::greater<int>(),std::placeholders::_1,y.max_doz));
    if(it1!=y.max.end() or it2!=y.min.end()) throw std::logic_error("Prekoracen dozvoljeni opseg temperatura");
    return y;
}
Temperature operator +(int n, Temperature x){
    Temperature y(x);
    return y+n;
}
Temperature operator -(Temperature x, int n){
    Temperature y(x);
    std::transform(y.max.begin(), y.max.end(), y.max.begin(), std::bind(std::minus<int>(),std::placeholders::_1,n));
    std::transform(y.min.begin(), y.min.end(), y.min.begin(), std::bind(std::minus<int>(),std::placeholders::_1,n));
    auto it1=std::find_if(y.max.begin(), y.max.end(), std::bind(std::less<int>(),std::placeholders::_1,y.min_doz));
    auto it2=std::find_if(y.min.begin(), y.min.end(), std::bind(std::less<int>(),std::placeholders::_1,y.min_doz));
    if(it1!=y.max.end() or it2!=y.min.end()) throw std::logic_error("Prekoracen dozvoljeni opseg temperatura");
    return y;
}
Temperature operator -(int n, Temperature x){
    Temperature y(x);
    auto lista=y.min;
    std::transform(y.max.begin(), y.max.end(), y.min.begin(), std::bind(std::minus<int>(),n,std::placeholders::_1));
    std::transform(lista.begin(), lista.end(), y.max.begin(), std::bind(std::minus<int>(),n,std::placeholders::_1));
    auto it1=std::find_if(y.max.begin(), y.max.end(), std::bind(std::less<int>(),std::placeholders::_1,y.min_doz));
    auto it2=std::find_if(y.min.begin(), y.min.end(), std::bind(std::less<int>(),std::placeholders::_1,y.min_doz));
    if(it1!=y.max.end() or it2!=y.min.end()) throw std::logic_error("Prekoracen dozvoljeni opseg temperatura");
    return y;
}
Temperature Temperature::operator +=(int n){
    std::transform(max.begin(), max.end(), max.begin(), std::bind(std::plus<int>(),std::placeholders::_1,n));
    std::transform(min.begin(), min.end(), min.begin(), std::bind(std::plus<int>(),std::placeholders::_1,n));
    auto it1=std::find_if(max.begin(), max.end(), std::bind(std::greater<int>(),std::placeholders::_1,max_doz));
    auto it2=std::find_if(min.begin(), min.end(), std::bind(std::greater<int>(),std::placeholders::_1,max_doz));
    if(it1!=max.end() or it2!=min.end()) throw std::logic_error("Prekoracen dozvoljeni opseg temperatura");
    return *this;
}
Temperature Temperature::operator -=(int n){
    std::transform(max.begin(),max.end(), max.begin(), std::bind(std::minus<int>(),std::placeholders::_1,n));
    std::transform(min.begin(), min.end(), min.begin(), std::bind(std::minus<int>(),std::placeholders::_1,n));
    auto it1=std::find_if(max.begin(), max.end(), std::bind(std::less<int>(),std::placeholders::_1,min_doz));
    auto it2=std::find_if(min.begin(), min.end(), std::bind(std::less<int>(),std::placeholders::_1,min_doz));
    if(it1!=max.end() or it2!=min.end()) throw std::logic_error("Prekoracen dozvoljeni opseg temperatura");
    return *this;
}
bool operator ==(Temperature t1, Temperature t2){
    return (t1.max_doz==t2.max_doz and t1.min_doz==t2.min_doz and
        std::equal(t1.max.begin(), t1.max.end(), t2.max.begin()) and
        std::equal(t1.min.begin(), t1.min.end(), t2.max.begin()) and t1.br==t2.br);
}
bool operator !=(Temperature t1, Temperature t2){
    return !(t1==t2);
}
std::ostream& operator <<(std::ostream &tok, Temperature t){
    std::for_each(t.min.begin(), t.min.end(), PomocnaFunkcijskaKlasa(tok));
    tok << std::endl;
    std::for_each(t.max.begin(), t.max.end(), PomocnaFunkcijskaKlasa(tok));
    return tok;
}

using std::cout;
using std::cin;
int main ()
{
    cout << "Unesite minimalnu i maksimalnu dozvoljenu temperaturu: \n";
    int a, b;
    cin >> a >> b;
    Temperature x(a, b);
    cout << "Koliko je registriranih minimalnih i maksimalnih temperatura: \n";
    int n; 
    cin >>n;
    cout << "Unesite minimalne i maksimalne temperature: ";
    for(int i=0; i<n; i++){
        cin >> a >>b;
        try{
            x.RegistrirajTemperature(std::make_pair(a,b));
        } catch(std::range_error e){
            cout << e.what() << std::endl ;
            i--;
        }
    }
    try{
    cout << "Minimalne temperature uvecane za 1 i maksimalne temperature umanjene za 1 iznose: \n";
    x++; x--;
    std::cout << x;
    cout << "Unesite broj koji zelite dodati na temperature: \n";
    cin >>n;
    cout << x+n;
    cout << "Unesite broj koji zelite oduzeti od temperatura: \n";
    cin >> n;
    cout << x-n;
    cout << "Unesite broj od kojeg zelite oduzeti temperature: \n";
    cin >> n;
    cout << n-x;
    } catch(std::logic_error e){
        std::cout << e.what();
    }
	return 0;
}