#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <iterator>
#include <new>
#include <utility>
#include <stdexcept>
#include <memory>
#include <functional>
#include <cmath>
#include <map>
#include <tuple>
class Datum{
    int d,m,g;
    public:
    Datum(int dan, int mjesec, int godina);
    void Postavi(int dan, int mjesec, int godina){
        if(dan>31 || dan<0 || mjesec<0 || mjesec>12 || godina<0) throw std::domain_error("Neispravan datum");
        d=dan;
        m=mjesec;
        g=godina;}
    std::tuple<int, int, int> Ocitaj() const;
    void Ispisi() const{
        std::cout << d <<"/"<< m <<"/"<< g;
    };
};
class Vrijeme{
    int min,hour;
    Vrijeme(int sati, int minute);
    void Postavi(int sati, int minute){
        if(minute<0 || minute>59 || sati<0 || sati>23) throw std::domain_error("Neispravno vrijeme");
        min=minute;
        hour=sati;
    };
    std::pair<int, int> Ocitaj () const;
    void Ispisi() const{
        std::cout << hour <<":" << min;
    };
};
for(int i=0;i<v.size();i++){
        Kugla prva=v[i];
        for(int j=i+1;j<v.size();j++){
            Kugla druga=v[j];
            if(prva.DajX()==druga.DajX() && prva.DajY()==druga.DajY() && prva.DajZ()==druga.DajZ() && prva.DajPoluprecnik()==druga.DajPoluprecnik()) continue;
            if(DaLiSeSijeku(prva,druga)){
                prva.Ispisi();
                druga.Ispisi();
                a++;
            }
        }}
int main ()
{
	return 0;
}
