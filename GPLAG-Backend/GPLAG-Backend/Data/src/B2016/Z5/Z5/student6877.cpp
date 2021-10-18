/B16/17 (Zadaća 5, Zadatak 5)
//Autotestovi by Berina Cocalic (mail: bcocalic1@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <list>
#include <stdexcept>

class Temperature
{
    std::list<int>min;
    std::list<int>max;

    int najmanja, najveca;
public:
    Temperature(int x, int y) {
        if(x>y) throw std::range_error("Nekorektne temperature");
        /* min.push_back(x);
         max.push_back(y);*/
        najmanja=x;
        najveca=y;
    }
    void RegistrirajTemperature(std::pair<int, int> p) {
        if(p.first>p.second || p.first<najmanja || p.second>najveca) throw std::range_error("Nekorektne temperature");
        min.push_back(p.first);
        max.push_back(p.second);
    }
    void BrisiSve() {
        for(auto it=min.begin(); it!=min.end();) it=min.erase(it);
        for(auto it=max.begin(); it!=max.end();) it=max.erase(it);
    }
    void BrisiNegativneTemperature() {
        for(auto it=min.begin(); it!=min.end();) {
            if(*it<0) it=min.erase(it);
            else it++;
        }
        for(auto it=max.begin(); it!=max.end();) {
            if(*it<0) it=max.erase(it);
            else it++;
        }
    }
    int DajBrojRegistriranihTemperatura() {
        return min.size();
    }
    int DajMinimalnuTemperaturu();
    int DajMaksimalnuTemperaturu();
    int DajBrojTemperaturaVecihOd(int n) {
        int br(0);
        for(auto it=min.begin(); it!=min.end(); it++) {
            if(*it>n) br++;
        }
        for(auto it=max.begin(); it!=max.end(); it++) {
            if(*it>n) br++;
        }
        return br;

    }
    int DajBrojTemperaturaManjihOD(int n);
    friend bool operator !(const Temperature &t);
    friend Temperature &operator++(Temperature &t) {

        return t;
    }
    friend	Temperature operator ++(Temperature &t, int) {
        Temperature pomocni(t);

        return pomocni;
    }
    friend Temperature &operator--(Temperature &t) {

        return t;
    }
    friend Temperature operator --(Temperature &t, int) {
        Temperature pomocni(t);

        return pomocni;
    }
    friend Temperature operator +(const Temperature &t);
    friend Temperature operator -(const Temperature &t);
    friend Temperature operator *(const Temperature &t);
    Temperature operator[](int indeks)const;
    friend Temperature operator +(const Temperature &a, const Temperature &b);
    friend Temperature operator -(const Temperature &a, const Temperature &b);
    friend Temperature &operator +=(Temperature &a, const Temperature &b);
    friend Temperature &operator -=(Temperature &a, const Temperature &b);
    friend bool operator ==(const Temperature &a, const Temperature &b);
    friend bool operator !=(const Temperature &a, const Temperature &b);
    friend std::ostream &operator <<(std::ostream &Tok, Temperature a);



};
int main ()
{
    return 0;
}