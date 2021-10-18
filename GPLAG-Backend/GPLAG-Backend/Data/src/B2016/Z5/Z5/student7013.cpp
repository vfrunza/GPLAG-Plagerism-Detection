/B16/17 (Zadaća 5, Zadatak 5)
//Autotestovi by Berina Cocalic (mail: bcocalic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <utility>
#include <functional>
#include <algorithm>
#include <stdexcept>
#include <vector>
#include <list>
#include <iterator>

using namespace std;
using namespace placeholders;

class Temperature {
    list<int> minimalne;
    list<int> maksimalne;
    int minTemp, maxTemp;
    void Provjera(int, int) const;
public:
    Temperature(int, int);
    void RegistrirajTemperature(pair<int, int>);
    void BrisiSve();
    void BrisiTemperature(pair<int, int>);
    int DajBrojRegistriranihTemperatura() const;
    int DajMaksimalnuTemperaturu() const;
    int DajMinimalnuTemperaturu() const;
    int DajBrojTemperaturaVecihOd(int) const;
    int DajBrojTemperaturaManjihOd(int) const;
    friend bool operator!(Temperature);
    friend Temperature& operator++(Temperature&, int);
    friend Temperature& operator++(Temperature&);
    friend Temperature& operator--(Temperature&, int);
    friend Temperature& operator--(Temperature&);
    friend vector<int> operator*(const Temperature&);
    friend vector<int> operator-(const Temperature&);
    friend vector<int> operator+(const Temperature&);
    pair<int, int>&& operator[](int indeks) const;
    friend Temperature operator+(Temperature, int);
    friend Temperature operator-(Temperature, int);
    friend Temperature operator+(int n, Temperature t) { return t + n; }
    friend Temperature operator-(int, Temperature);
    Temperature operator+=(int n) { return *this = *this + n; }
    Temperature operator-=(int n) { return *this = *this - n; }
    friend bool operator==(const Temperature&, const Temperature&);
    friend bool operator!=(const Temperature& t1, const Temperature& t2) { return !(t1 == t2); }
    friend ostream& operator<< (ostream&, const Temperature&);
};

void Temperature::Provjera(int minTemp, int maxTemp) const {
    if(minTemp < this->minTemp || maxTemp < this->minTemp || minTemp > this->maxTemp || maxTemp > this->maxTemp || minTemp > maxTemp)
        throw range_error("Nekorektne temperature");
}

Temperature::Temperature(int minTemp, int maxTemp) : minimalne(0), maksimalne(0) {
    if(minTemp > maxTemp) throw range_error("Nekorektne temperature");
    this->minTemp = minTemp;
    this->maxTemp = maxTemp;
}

void Temperature::RegistrirajTemperature(pair<int, int> p){
    Provjera(p.first, p.second);
    minimalne.push_back(p.first);
    maksimalne.push_back(p.second);
}

void Temperature::BrisiSve(){
    minimalne.clear();
    maksimalne.clear();
}

int Temperature::DajBrojRegistriranihTemperatura() const{
    return minimalne.size();
}

int Temperature::DajMaksimalnuTemperaturu() const{
    if(minimalne.empty() && maksimalne.empty()) throw logic_error("Nema registriranih temperatura");
    return *max_element(maksimalne.begin(), maksimalne.end());
}

int Temperature::DajMinimalnuTemperaturu() const{
    if(minimalne.empty() && maksimalne.empty()) throw logic_error("Nema registriranih temperatura");
    return *min_element(minimalne.begin(), minimalne.end());
}

int Temperature::DajBrojTemperaturaVecihOd(int n) const{
    if(minimalne.empty() && maksimalne.empty()) throw logic_error("Nema registriranih temperatura");
    return count_if(maksimalne.begin(), maksimalne.end(), bind(greater<int>(), _1, n));
}

int Temperature::DajBrojTemperaturaManjihOd(int n) const{
    if(minimalne.empty() && maksimalne.empty()) throw logic_error("Nema registriranih temperatura");
    return count_if(minimalne.begin(), minimalne.end(), bind(less<int>(), _1, n));
}

bool operator!(Temperature t){
    return t.minimalne.empty() && t.maksimalne.empty();
}

Temperature& operator++(Temperature& t, int n){
    transform(t.minimalne.begin(), t.minimalne.end(), t.minimalne.begin(), bind(plus<int>(), _1, 1)); //ubacit provjeru
    return t;
}

Temperature& operator++(Temperature& t){
    transform(t.minimalne.begin(), t.minimalne.end(), t.minimalne.begin(), bind(plus<int>(), _1, 1)); //ubacit provjeru
    return t;
}

Temperature& operator--(Temperature& t, int n){
    transform(t.minimalne.begin(), t.minimalne.end(), t.minimalne.begin(), bind(minus<int>(), _1, 1)); //ubacit provjeru
    return t;
}

Temperature& operator--(Temperature& t){
    transform(t.minimalne.begin(), t.minimalne.end(), t.minimalne.begin(), bind(minus<int>(), _1, 1)); //ubacit provjeru
    return t;
}

vector<int> operator*(const Temperature& t){
    vector<int> rez(t.minimalne.size());
    auto it1 = t.minimalne.begin();
    auto it2 = t.maksimalne.begin();
    generate(rez.begin(), rez.end(), bind(minus<int>(), *it1++, *it2++));
    return rez;
}

void Temperature::BrisiTemperature(pair<int, int> p){
    for(auto it1 = minimalne.begin(); it1 != minimalne.end(); it1++){
        if(*it1 == p.first){
            for(auto it2 = maksimalne.begin(); it2 != maksimalne.end(); it2++)
                if(*it2 == p.second){
                    it1 = minimalne.erase(it1);
                    it2 = maksimalne.erase(it2);
                }
        }
    }
}

vector<int> operator-(const Temperature& t){
    vector<int> rez(t.minimalne.size());
    auto it1 = t.minimalne.begin();
    generate(rez.begin(), rez.end(), bind(minus<int>(), *it1++, t.minTemp));
    return rez;
}

vector<int> operator+(const Temperature& t){
    vector<int> rez(t.minimalne.size());
    auto it1 = t.maksimalne.begin();
    generate(rez.begin(), rez.end(), bind(minus<int>(), t.maxTemp, *it1++));
    return rez;
}

pair<int, int>&& Temperature::operator[](int indeks) const{
    if(indeks >= (int)minimalne.size() || indeks >= (int)maksimalne.size() || indeks < 1)
        throw range_error("Neispravan indeks");
    auto it1 = minimalne.begin();
    auto it2 = maksimalne.begin();
    advance(it1, indeks - 1);
    advance(it2, indeks - 1);
    return move(pair<int, int> (*it1, *it2));
}

Temperature operator+(Temperature t, int n){
    transform(t.minimalne.begin(), t.minimalne.end(), t.minimalne.begin(), bind(plus<int>(), _1, n));
    transform(t.maksimalne.begin(), t.maksimalne.end(), t.maksimalne.begin(), bind(plus<int>(), _1, n));
    auto it1 = find_if(t.minimalne.begin(), t.minimalne.end(), bind(greater<int>(), _1, t.maxTemp));
    auto it2 = find_if(t.maksimalne.begin(), t.maksimalne.end(), bind(greater<int>(), _1, t.maxTemp));
    if(it1 != t.minimalne.end() || it2 != t.maksimalne.end())
        throw logic_error("Prekoracen dozvoljeni opseg temperatura");
    return t;
}

Temperature operator-(Temperature t, int n){
    transform(t.minimalne.begin(), t.minimalne.end(), t.minimalne.begin(), bind(minus<int>(), _1, n));
    transform(t.maksimalne.begin(), t.maksimalne.end(), t.maksimalne.begin(), bind(minus<int>(), _1, n));
    auto it1 = find_if(t.minimalne.begin(), t.minimalne.end(), bind(less<int>(), _1, t.minTemp));
    auto it2 = find_if(t.maksimalne.begin(), t.maksimalne.end(), bind(less<int>(), _1, t.minTemp));
    if(it1 != t.minimalne.end() || it2 != t.maksimalne.end())
        throw logic_error("Prekoracen dozvoljeni opseg temperatura");
    return t;
}

Temperature operator-(int n, Temperature t){
    transform(t.minimalne.begin(), t.minimalne.end(), t.maksimalne.begin(), bind(minus<int>(), n, _1));
    transform(t.maksimalne.begin(), t.maksimalne.end(), t.minimalne.begin(), bind(minus<int>(), n, _1));
    auto it1 = find_if(t.minimalne.begin(), t.minimalne.end(), bind(less<int>(), _1, t.minTemp));
    auto it2 = find_if(t.maksimalne.begin(), t.maksimalne.end(), bind(less<int>(), _1, t.minTemp));
    auto it3 = find_if(t.minimalne.begin(), t.minimalne.end(), bind(greater<int>(), _1, t.maxTemp));
    auto it4 = find_if(t.maksimalne.begin(), t.maksimalne.end(), bind(greater<int>(), _1, t.maxTemp));
    if(it1 != t.minimalne.end() || it2 != t.maksimalne.end() || it3 != t.minimalne.end() || it4 != t.maksimalne.end())
        throw logic_error("Prekoracen dozvoljeni opseg temperatura");
    return t;
}

bool operator==(const Temperature& t1, const Temperature& t2){
    bool istiMin = t1.minTemp == t2.minTemp;
    bool istiMax = t1.maxTemp == t2.maxTemp;
    bool tempMin = t1.minimalne == t2.minimalne;
    bool tempMax = t1.maksimalne == t2.maksimalne;
    return istiMin && istiMax && tempMin && tempMax;
}

ostream& operator<< (ostream& tok, const Temperature& t){
    auto f = [&tok](int n) { tok << n << " "; }; // UPITNO UPITNO UPITNO UPITNO UPITNO UPITNO UPITNO UPITNO 
    for_each(t.minimalne.begin(), t.minimalne.end(), f);
    tok << endl;
    for_each(t.maksimalne.begin(), t.maksimalne.end(), f);
    tok << endl;
    return tok;
}

int main ()
{
    try{
        Temperature t(2, 44);
        t.RegistrirajTemperature(pair<int, int> (15, 18));
        t.RegistrirajTemperature(pair<int, int> (3, 31));
        cout << t;
        
    }catch(exception &e){
        cout << "Izuzetak: " << e.what();
    }
	return 0;
}