/B16/17 (Zadaća 5, Zadatak 5)
//Autotestovi by Berina Cocalic (mail: bcocalic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <list>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <functional>

using namespace std;

class Temperature {
    list<int> min;
    list<int> max;
    
    public:
    Temperature( int minimalna, int maximalna);
    void RegistrirajTemperature( pair<int, int> temp );
    void BrisiSve();
    void BrisiNegativneTemperature();
    int DajBrojRegistriranihTemperatura() const;
    int DajMinimalnuTemperaturu() const;
    int DajMaksimalnuTeperaturu() const;
    int DajBrojTeperaturaVecihOd(int temp) const;
    int DajBrojTeperaturaManjihOd(int temp) const;
    bool operator !();
    Temperature &operator ++();
    Temperature &operator --();
    friend Temperature operator ++(Temperature &t, int);
    friend Temperature operator --(Temperature &t, int);
    vector<int> operator *();
    vector<int> operator -();
    vector<int> operator +();
    pair<int,int> operator [](int i);
    friend Temperature &operator +(const Temperature &t, int Y);
    friend Temperature &operator -(const Temperature &t, int Y);
    friend Temperature &operator +(int Y, const Temperature &t);
    friend Temperature &operator -(int Y, const Temperature &t);
    friend Temperature &operator +=(Temperature &t, int Y);
    friend Temperature &operator -=(Temperature &t, int Y);
    friend bool operator ==(const Temperature &t1, const Temperature &t2);
    friend bool operator !=(const Temperature &t1, const Temperature &t2);
    friend ostream &operator <<(ostream &tok, const Temperature &t);
};