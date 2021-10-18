/B16/17 (Zadaća 5, Zadatak 5)
//Autotestovi by Berina Cocalic (mail: bcocalic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include<stdexcept>
#include<list>
#include<iterator>
#include<algorithm>
#include<functional>
#include<vector>
using namespace std;

class Temperature
{
    list<int>min;
    list<int>max;

public:
    Temperature(int min, int max);
    void RegistrirajTemperature(pair<int, int>min_max);
    void BrisiSve(list<int>min, list<int>max);
    void BrisiNegativneTemperature(pair<int, int>par);
    int  DajBrojRegistriranihMetoda()const;
    int  DajMinimalnuTemperaturu() const ;
    int DajMaksimalnuTemperaturu()const ;
    int DajBrojTemperaturaVecihOd(int maksimalna_temp);
    int DajBrojTemperaturaManjihOd(int minimalna_temp);

    friend Temperature operator ++ (Temperature &t);
    friend Temperature operator ++ (Temperature &t, int) ;
    friend Temperature operator -- (Temperature &t);
    friend Temperature operator -- (Temperature &t, int);

    friend Temperature operator-(int dozvoljena, const Temperature &t);
    friend Temperature operator-(const Temperature &t, int dozvoljena);
    friend vector<int> operator -(const Temperature &t, const Temperature &t1);
    friend Temperature operator+(int dozvoljena, const Temperature &t);
    friend Temperature operator+(const Temperature &t, int dozvoljena);
    friend vector<int> operator +(const Temperature &t, const Temperature &t1);

    friend vector<int> operator * ( const Temperature &t, const Temperature &t1);
    Temperature  & operator +=(int x);
    Temperature  & operator -=(int x);
    
    friend ostream &operator<<(ostream &cout, const Temperature &t);

    friend bool operator==(Temperature &t, Temperature &t1);
    friend bool operator !(pair<int, int> registrirana);
    pair<int, int> operator[] (int indeks);


};

Temperature::Temperature (int min, int max) :min(min), max(max)
{
    if(min>max) throw range_error("Nekorektne temperature");
}

int Temperature::DajBrojRegistriranihMetoda() const
{
    int rez=min.size()+max.size();
    return rez;
}
void Temperature::RegistrirajTemperature(pair<int, int>min_max)
{
    min.push_back(min_max.first);
    max.push_back(min_max.second);
}
void Temperature::BrisiSve(list<int>min, list<int>max)
{
    min.resize(0);
    max.resize(0);
}
void Temperature::BrisiNegativneTemperature(pair<int, int>par)
{
    if(par.first<0 || par.second<0)
        min.resize(par.first, par.second);
    max.resize(par.first, par.second);
}
int Temperature::DajBrojTemperaturaVecihOd(int maksimalna_temp)
{
    int a;
    a= count_if(max.begin(), max.end(), bind(greater<int>(), placeholders::_1, maksimalna_temp));
    int test=DajBrojRegistriranihMetoda();
    if(test<=0) throw logic_error("Nema registriranih temperatura");
    return a;
}
int Temperature::DajBrojTemperaturaManjihOd(int minimalna_temp)
{
    int a;
    a= count_if(min.begin(), min.end(), bind(less<int>(), placeholders::_1, minimalna_temp));
    int test=DajBrojRegistriranihMetoda();
    if(test<=0) throw logic_error("Nema registriranih temperatura");

    return a;
}
int Temperature::DajMaksimalnuTemperaturu() const
{
    int test=DajBrojRegistriranihMetoda();
    if(test<=0) throw logic_error("Nema registriranih temperatura");

    return *max_element(max.begin(), max.end());
}
int Temperature::DajMinimalnuTemperaturu() const
{
    int test=DajBrojRegistriranihMetoda();
    if(test<=0) throw logic_error("Nema registriranih temperatura");
    return *min_element(min.begin(), min.end());
}
Temperature operator ++ (Temperature &t)
{
    if(t.min>t.max) throw ("Ilegalna operacija");
    transform(t.max.begin(), t.max.end(), t.max.begin(), bind(plus<int>(), placeholders::_1,1));
}
Temperature operator ++ (Temperature &t, int)
{
    // if(this->min.begin(), this->min.end(), bind(less<int>(), placeholders::_1, max) throw;
    if(t.min>t.max) throw ("Ilegalna operacija");

    Temperature temp=t;
    transform(t.max.begin(), t.max.end(), t.max.begin(), bind(plus<int>(), placeholders::_1,1));
    return temp;
}
Temperature operator -- (Temperature &t)
{
    if(t.min>t.max) throw ("Ilegalna operacija");

    transform(t.max.begin(), t.max.end(), t.max.begin(), bind(minus<int>(), placeholders::_1,1));
}
Temperature operator -- (Temperature &t, int)
{
    if(t.min>t.max) throw ("Ilegalna operacija");
    Temperature temp=t;
    transform(t.max.begin(), t.max.end(), t.max.begin(), bind(minus<int>(), placeholders::_1,1));
    return temp;
}

Temperature  operator -( int dozvoljena,  const Temperature &t)
{
    Temperature temp(t);
    transform(t.min.begin(),t.min.end(), temp.min.begin(), bind(minus<int>(), dozvoljena ,placeholders::_1));
    if(count_if(temp.min.begin(), temp.min.end(),bind(less<int>(), placeholders::_1, 0))>0)
        throw logic_error("Prekoracen dozvoljeni opseg temperatura");
    return temp;
}
Temperature operator -( const Temperature &t, int dozvoljena)
{
    Temperature temp(t);
    transform(t.min.begin(),t.min.end(), temp.min.begin(), bind(minus<int>(),placeholders::_1, dozvoljena));
    if(count_if(temp.min.begin(), temp.min.end(),bind(less<int>(), placeholders::_1, 0))>0)
        throw logic_error("Prekoracen dozvoljeni opseg temperatura");
    return temp;
}


vector<int> operator -(const Temperature &t, const Temperature &t1)
{
    std::vector<int>v(0) ;
    transform(t.min.begin(), t.min.end(), t1.min.begin(), v.begin(), minus<int>());
    return v;
}

Temperature  operator +( int dozvoljena,  const Temperature &t)
{
    Temperature temp(t);
    transform(t.max.begin(),t.max.end(), temp.max.begin(), bind(minus<int>(), dozvoljena ,placeholders::_1));
    if(count_if(temp.max.begin(), temp.max.end(),bind(greater<int>(), placeholders::_1, 0))>0)
        throw logic_error("Prekoracen dozvoljeni opseg temperatura");
    return temp;
}
Temperature operator +( const Temperature &t, int dozvoljena)
{
    Temperature temp(t);
    transform(t.max.begin(),t.max.end(), temp.max.begin(), bind(minus<int>(),placeholders::_1, dozvoljena));
    if(count_if(temp.max.begin(), temp.max.end(),bind(greater<int>(), placeholders::_1, 0))>0)
        throw logic_error("Prekoracen dozvoljeni opseg temperatura");
    return temp;
}


vector<int> operator +(const Temperature &t, const Temperature &t1)
{
    std::vector<int>v(0) ;
    transform(t.max.begin(), t.max.end(), t1.max.begin(), v.begin(), minus<int>());
    return v;
}
vector<int> operator * (const Temperature &t, const Temperature &t1)
{
    vector<int> razlika(0);
    transform(t.min.begin(),t.min.end(), t1.max.begin(), razlika.begin(), minus<int>());
    return razlika;
}
ostream &operator<<(ostream &cout, const Temperature &t)
{
    copy(t.max.begin(), t.max.end(), ostream_iterator<int>(cout, "\n"));
    cout<<endl;
    return cout;
}


bool operator==(Temperature &t, Temperature &t1 )
{
    if(t.min==t1.min || t.max==t1.max)
        return true;
    return false;
}
Temperature & Temperature::operator +=(int x)
{
    // this->max=x+this->max;
    transform(this->max.begin(), this->max.end(), this->max.begin(), bind(plus<int>(), placeholders::_1,x));
    return *this;
}
Temperature & Temperature::operator -=(int x)
{
    // this->max=x+this->max;
    transform(this->min.begin(), this->min.end(), this->min.begin(), bind(minus<int>(), placeholders::_1,x));
    return *this;
}

int main ()
{
    try {
        cout<<"Dobro dosli!";
        Temperature t(10, 32);
        Temperature s(2, 50);
        int nesto(10);
        t.RegistrirajTemperature({3, 32});
        cout<<t.DajBrojTemperaturaManjihOd(3)<<endl;
        cout<<t.DajBrojTemperaturaVecihOd(30)<<endl;
        cout<<t.DajMaksimalnuTemperaturu()<<endl;
        cout<<t.DajMinimalnuTemperaturu()<<endl;
        t+=2;
        s--;
        cout<<t;
        t++;
        cout<<s;
    } catch(...) {
        cout<<"Problemi sa memorijom"<<endl;
    }
    return 0;

}
