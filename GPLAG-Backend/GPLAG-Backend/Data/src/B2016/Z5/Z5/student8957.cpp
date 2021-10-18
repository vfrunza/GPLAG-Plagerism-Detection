/B16/17 (Zadaća 5, Zadatak 5)
//Autotestovi by Berina Cocalic (mail: bcocalic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <list>
#include <stdexcept>
#include <algorithm>
#include <functional>
#include <vector>

using namespace std;

class Temperature
{
    list<int> minimalneTemp, maksimalneTemp;
    int minimalnaTemp, maksimalnaTemp;
public:
    Temperature(int minTemp, int maxTemp);
    Temperature(const Temperature &t);
    Temperature &operator=(const Temperature &t);
    void RegistrirajTemperature(pair<int, int> temperature);
    void BrisiSve() { minimalneTemp.resize(0); maksimalneTemp.resize(0); }
    void BrisiNegativneTemperature(); //uraditi
    int DajBrojRegistriranihTemperatura() const { return minimalneTemp.size(); }
    int DajMinimalnuTemperaturu();
    int DajMaksimalnuTeperaturu();
    int DajBrojTeperaturaVecihOd(int temp);
    int DajBrojTeperaturaManjihOd(int temp); 
    Temperature operator++();
    Temperature operator++(int);
    Temperature operator--();
    Temperature operator--(int);
    friend bool operator!(const Temperature &t);
    friend vector<int> operator*(const Temperature &t);
    friend vector<int> operator-(const Temperature &t);
    friend vector<int> operator+(const Temperature &t);
    friend ostream &operator<<(ostream &cout, const Temperature &t);
    friend Temperature operator+(const Temperature &t, int temperatura);
    friend Temperature operator+(const Temperature &t1, const Temperature &t2);
    friend Temperature operator-(const Temperature &t, int temperatura);
    friend Temperature operator-(const Temperature &t1, const Temperature &t2);
    friend Temperature &operator+=(Temperature &t, int temperatura);
    friend Temperature &operator+=(Temperature &t1, Temperature &t2);
    friend Temperature &operator-=(Temperature &t, int temperatura);
    friend Temperature &operator-=(Temperature &t1, Temperature &t2);
    friend bool operator==(const Temperature &t1, const Temperature &t2);
    friend bool operator!=(const Temperature &t1, const Temperature &t2);
    pair<int,int> operator[](int indeks); 
};

Temperature::Temperature(const Temperature &t)
{
    minimalneTemp.resize(t.minimalneTemp.size());
    maksimalneTemp.resize(t.maksimalneTemp.size());
    minimalnaTemp = t.minimalnaTemp;
    maksimalnaTemp = t.maksimalnaTemp;
    copy(t.minimalneTemp.begin(), t.minimalneTemp.end(), minimalneTemp.begin());
    copy(t.maksimalneTemp.begin(), t.maksimalneTemp.end(), maksimalneTemp.begin());
}

Temperature &Temperature::operator=(const Temperature &t)
{
    if(this == &t) return *this;
    
    minimalneTemp.resize(0);
    maksimalneTemp.resize(0);
    minimalneTemp.resize(t.minimalneTemp.size());
    maksimalneTemp.resize(t.maksimalneTemp.size());
    minimalnaTemp = t.minimalnaTemp;
    maksimalnaTemp = t.maksimalnaTemp;
    copy(t.minimalneTemp.begin(), t.minimalneTemp.end(), minimalneTemp.begin());
    copy(t.maksimalneTemp.begin(), t.maksimalneTemp.end(), maksimalneTemp.begin());
    
    return *this;
}

bool operator==(const Temperature &t1, const Temperature &t2)
{
    if(t1.DajBrojRegistriranihTemperatura() != t2.DajBrojRegistriranihTemperatura()) return false;
    if(t1.minimalnaTemp != t2.minimalnaTemp || t1.maksimalnaTemp != t2.maksimalnaTemp) return false;
    
    return (equal(t1.minimalneTemp.begin(), t1.minimalneTemp.end(), t2.minimalneTemp.begin()) && equal(t1.maksimalneTemp.begin(), t1.maksimalneTemp.end(), t2.maksimalneTemp.begin()));
}

bool operator!=(const Temperature &t1, const Temperature &t2)
{
    return !(t1 == t2);
}

Temperature &operator-=(Temperature &t1, Temperature &t2)
{
    transform(t1.minimalneTemp.begin(), t1.minimalneTemp.end(), t2.minimalneTemp.begin(), t1.minimalneTemp.begin(), minus<int>());
    transform(t1.maksimalneTemp.begin(), t1.maksimalneTemp.end(), t2.maksimalneTemp.begin(), t1.maksimalneTemp.begin(), minus<int>());
    
    int provjera = count_if(t1.minimalneTemp.begin(), t1.minimalneTemp.end(), bind(less<int>(), placeholders::_1, t1.minimalnaTemp)) + count_if(t1.maksimalneTemp.begin(), t1.maksimalneTemp.end(), bind(less<int>(), placeholders::_1, t1.minimalnaTemp));
    
    if(provjera != 0) throw logic_error("Prekoracen dozvoljeni opseg temperatura");
    
    return t1;
}

Temperature &operator-=(Temperature &t, int temperatura)
{
    transform(t.minimalneTemp.begin(), t.minimalneTemp.end(), t.minimalneTemp.begin(), bind(minus<int>(), placeholders::_1, temperatura));
    transform(t.maksimalneTemp.begin(), t.maksimalneTemp.end(), t.maksimalneTemp.begin(), bind(minus<int>(), placeholders::_1, temperatura));
    
    int provjera = count_if(t.minimalneTemp.begin(), t.minimalneTemp.end(), bind(less<int>(), placeholders::_1, t.minimalnaTemp)) + count_if(t.maksimalneTemp.begin(), t.maksimalneTemp.end(), bind(less<int>(), placeholders::_1, t.minimalnaTemp));
    
    if(provjera != 0) throw logic_error("Prekoracen dozvoljeni opseg temperatura");
    
    return t;
}

Temperature &operator+=(Temperature &t1, Temperature &t2)
{
    transform(t1.minimalneTemp.begin(), t1.minimalneTemp.end(), t2.minimalneTemp.begin(), t1.minimalneTemp.begin(), plus<int>());
    transform(t1.maksimalneTemp.begin(), t1.maksimalneTemp.end(), t2.maksimalneTemp.begin(), t1.maksimalneTemp.begin(), plus<int>());
    
    int provjera = count_if(t1.minimalneTemp.begin(), t1.minimalneTemp.end(), bind(greater<int>(), placeholders::_1, t1.maksimalnaTemp)) + count_if(t1.maksimalneTemp.begin(), t1.maksimalneTemp.end(), bind(greater<int>(), placeholders::_1, t1.maksimalnaTemp));
    
    if(provjera != 0) throw logic_error("Prekoracen dozvoljeni opseg temperatura");
    
    return t1;
}

Temperature &operator+=(Temperature &t, int temperatura)
{
    transform(t.minimalneTemp.begin(), t.minimalneTemp.end(), t.minimalneTemp.begin(), bind(plus<int>(), placeholders::_1, temperatura));
    transform(t.maksimalneTemp.begin(), t.maksimalneTemp.end(), t.maksimalneTemp.begin(), bind(plus<int>(), placeholders::_1, temperatura));
 
    int provjera = count_if(t.minimalneTemp.begin(), t.minimalneTemp.end(), bind(greater<int>(), placeholders::_1, t.maksimalnaTemp)) + count_if(t.maksimalneTemp.begin(), t.maksimalneTemp.end(), bind(greater<int>(), placeholders::_1, t.maksimalnaTemp));
    
    if(provjera != 0) throw logic_error("Prekoracen dozvoljeni opseg temperatura");
    
    return t;
}

Temperature operator-(const Temperature &t1, const Temperature &t2)
{
    Temperature temp(t1);
    
    transform(t1.minimalneTemp.begin(), t1.minimalneTemp.end(), t2.minimalneTemp.begin(), temp.minimalneTemp.begin(), minus<int>());
    transform(t1.maksimalneTemp.begin(), t1.maksimalneTemp.end(), t2.maksimalneTemp.begin(), temp.maksimalneTemp.begin(), minus<int>());
    
    int provjera = count_if(temp.minimalneTemp.begin(), temp.minimalneTemp.end(), bind(less<int>(), placeholders::_1, temp.minimalnaTemp)) + count_if(temp.maksimalneTemp.begin(), temp.maksimalneTemp.end(), bind(less<int>(), placeholders::_1, temp.minimalnaTemp));
    
    if(provjera != 0) throw logic_error("Prekoracen dozvoljeni opseg temperatura");
    
    return temp;
}

Temperature operator-(const Temperature &t, int temperatura)
{
    Temperature temp(t);
    
    transform(temp.minimalneTemp.begin(), temp.minimalneTemp.end(), temp.minimalneTemp.begin(), bind(minus<int>(), placeholders::_1, temperatura));
    transform(temp.maksimalneTemp.begin(), temp.maksimalneTemp.end(), temp.maksimalneTemp.begin(), bind(minus<int>(), placeholders::_1, temperatura));
    
    int provjera = count_if(temp.minimalneTemp.begin(), temp.minimalneTemp.end(), bind(less<int>(), placeholders::_1, temp.minimalnaTemp)) + count_if(temp.maksimalneTemp.begin(), temp.maksimalneTemp.end(), bind(less<int>(), placeholders::_1, temp.minimalnaTemp));
    
    if(provjera != 0) throw logic_error("Prekoracen dozvoljeni opseg temperatura");
    
    return temp;
}

Temperature operator+(const Temperature &t1, const Temperature &t2)
{
    Temperature temp(t1);
    
    transform(t1.minimalneTemp.begin(), t1.minimalneTemp.end(), t2.minimalneTemp.begin(), temp.minimalneTemp.begin(), plus<int>());
    transform(t1.maksimalneTemp.begin(), t1.maksimalneTemp.end(), t2.maksimalneTemp.begin(), temp.maksimalneTemp.begin(), plus<int>());
    
    int provjera = count_if(temp.minimalneTemp.begin(), temp.minimalneTemp.end(), bind(greater<int>(), placeholders::_1, temp.maksimalnaTemp)) + count_if(temp.maksimalneTemp.begin(), temp.maksimalneTemp.end(), bind(greater<int>(), placeholders::_1, temp.maksimalnaTemp));
    
    if(provjera != 0) throw logic_error("Prekoracen dozvoljeni opseg temperatura");
    
    return temp;
}

Temperature operator+(const Temperature &t, int temperatura)
{
    Temperature temp(t);
    
    transform(temp.minimalneTemp.begin(), temp.minimalneTemp.end(), temp.minimalneTemp.begin(), bind(plus<int>(), placeholders::_1, temperatura));
    transform(temp.maksimalneTemp.begin(), temp.maksimalneTemp.end(), temp.maksimalneTemp.begin(), bind(plus<int>(), placeholders::_1, temperatura));
    int provjera = count_if(temp.minimalneTemp.begin(), temp.minimalneTemp.end(), bind(greater<int>(), placeholders::_1, temp.maksimalnaTemp)) + count_if(temp.maksimalneTemp.begin(), temp.maksimalneTemp.end(), bind(greater<int>(), placeholders::_1, temp.maksimalnaTemp));
    
    if(provjera != 0) throw logic_error("Prekoracen dozvoljeni opseg temperatura");
    
    return temp;
}

pair<int, int> Temperature::operator[](int indeks)
{
    if(indeks < 1 || indeks > minimalneTemp.size()) throw range_error("Neispravan indeks");
    
    vector<int> v1{begin(minimalneTemp), end(minimalneTemp)}, v2{begin(maksimalneTemp), end(maksimalneTemp)};
    pair<int, int> par;
    par.first = v1[indeks - 1];
    par.second = v2[indeks - 1];
    
    return par;
}

vector<int> operator-(const Temperature &t)
{
    list<int> temp(t.minimalneTemp);
    
    transform(temp.begin(), temp.end(), temp.begin(), bind(minus<int>(), placeholders::_1, t.minimalnaTemp));
    vector<int> v{begin(temp), end(temp)};
    
    return v;
}

vector<int> operator+(const Temperature &t)
{
    list<int> temp(t.maksimalneTemp);
    
    transform(temp.begin(), temp.end(), temp.begin(), bind(minus<int>(), t.maksimalnaTemp, placeholders::_1));
    vector<int> v{begin(temp), end(temp)};
    
    return v;
}

vector<int> operator*(const Temperature &t)
{
    list<int> temp1(t.maksimalneTemp), temp2(t.minimalneTemp);
    
    transform(temp1.begin(), temp1.end(), temp2.begin(), temp1.begin(), minus<int>());
    vector<int> v{begin(temp1), end(temp1)};
    
    return v;
}

bool operator!(const Temperature &t)
{
    return (t.minimalneTemp.size() == 0);
}

ostream &operator<<(ostream &cout, const Temperature &t)
{
    for_each(t.minimalneTemp.begin(), t.minimalneTemp.end(), [&](int temp)->void { cout << temp << " "; });
    cout << endl;
    for_each(t.maksimalneTemp.begin(), t.maksimalneTemp.end(), [&](int temp)->void { cout << temp << " "; });
    cout << endl;
    
    return cout;
}

Temperature::Temperature(int minTemp, int maxTemp)
{
    if(minTemp > maxTemp) throw range_error("Nekorektne temperature");
    
    minimalnaTemp = minTemp;
    maksimalnaTemp = maxTemp;
}

void Temperature::RegistrirajTemperature(pair<int, int> temperature)
{
    if(temperature.first > temperature.second || temperature.first < minimalnaTemp || temperature.first > maksimalnaTemp || temperature.second < minimalnaTemp || temperature.second > maksimalnaTemp)
        throw range_error("Nekorektne temperature");
        
    minimalneTemp.push_back(temperature.first);
    maksimalneTemp.push_back(temperature.second);
}

int Temperature::DajMinimalnuTemperaturu()
{
    if(minimalneTemp.size() == 0) throw logic_error("Nema registriranih temperatura");
    
    return *min_element(minimalneTemp.begin(), minimalneTemp.end());
}

int Temperature::DajMaksimalnuTeperaturu()
{
    if(maksimalneTemp.size() == 0) throw logic_error("Nema registriranih temperatura");
    
    return *max_element(maksimalneTemp.begin(), maksimalneTemp.end());
}

int Temperature::DajBrojTeperaturaVecihOd(int temp)
{
    if(minimalneTemp.size() == 0) throw logic_error("Nema registriranih temperatura");
    
    int brojac = count_if(minimalneTemp.begin(), minimalneTemp.end(), bind(greater<int>(), placeholders::_1, temp)) + count_if(maksimalneTemp.begin(), maksimalneTemp.end(), bind(greater<int>(), placeholders::_1, temp));
    
    return brojac;
}

int Temperature::DajBrojTeperaturaManjihOd(int temp)
{
    if(minimalneTemp.size() == 0) throw logic_error("Nema registriranih temperatura");
    
    int brojac =  count_if(minimalneTemp.begin(), minimalneTemp.end(), bind(less<int>(), placeholders::_1, temp)) + count_if(maksimalneTemp.begin(), maksimalneTemp.end(), bind(less<int>(), placeholders::_1, temp));
    
    return brojac;
}

Temperature Temperature::operator++()
{
    transform(minimalneTemp.begin(), minimalneTemp.end(), minimalneTemp.begin(), bind(plus<int>(), placeholders::_1, 1));
    
    int provjera = count_if(minimalneTemp.begin(), minimalneTemp.end(), bind(greater<int>(), placeholders::_1, maksimalnaTemp));
    
    if(provjera != 0) throw logic_error("Ilegalna operacija");
    
    return *this;
}

Temperature Temperature::operator++(int)
{
    ++(*this);
    
    return *this;
}

Temperature Temperature::operator--()
{
    transform(maksimalneTemp.begin(), maksimalneTemp.end(), maksimalneTemp.begin(), bind(minus<int>(), placeholders::_1, 1));
    
    int provjera = count_if(maksimalneTemp.begin(), maksimalneTemp.end(), bind(less<int>(), placeholders::_1, minimalnaTemp));
    
    if(provjera != 0) throw logic_error("Ilegalna operacija");
    
    return *this;
}

Temperature Temperature::operator--(int)
{
    --(*this);
    
    return *this;
}

int main ()
{
    try
    {
        Temperature t = Temperature(-10, 40); // test konstruktora
        t.RegistrirajTemperature(make_pair(-10,40)); // test metode RegistrirajTemperature
        t.RegistrirajTemperature(make_pair(5,20));
        t.RegistrirajTemperature(make_pair(10,30));
        t.RegistrirajTemperature(make_pair(-5,24));
        t.RegistrirajTemperature(make_pair(-9,-7));
        cout << t.DajBrojRegistriranihTemperatura() << endl; // test DajBrojRegistrovanihTemperatura
        cout << t.DajMinimalnuTemperaturu() << endl; // test DajMinimalnuTemperaturu
        cout << t.DajMaksimalnuTeperaturu() << endl; // test DajMaksimalnuTemperaturu
        cout << t.DajBrojTeperaturaVecihOd(9) << endl; // test DajBrojTemperaturaVcihOd
        cout << t.DajBrojTeperaturaManjihOd(15) << endl; // test DajBrojTemperaturaManjihOd
        cout << t; // test operatora <<
        //--t; // test operatora ++, --
        cout << t;
        cout << !t << endl; // test operatora !
        vector<int> v = *t; // test operatora *
        for(auto a: v) cout << a << " ";
        cout << endl;
        v = +t; // test operatora +
        for(auto a: v) cout << a << " ";
        cout << endl;
        v = -t; // test operatora -
        for(auto a: v) cout << a << " ";
        cout << endl;
        pair<int, int> par = t[2]; // test operatora []
        cout << par.first << "," << par.second << endl;
    }
    catch(range_error e)
    {
        cout << e.what() << endl;
    }
    catch(logic_error e)
    {
        cout << e.what() << endl;
    }
    
    
	return 0;
}