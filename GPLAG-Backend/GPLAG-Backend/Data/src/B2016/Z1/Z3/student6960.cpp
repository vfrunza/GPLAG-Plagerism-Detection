#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
//mozda prebaciti u atove, poslati opet

typedef std::vector<double> DoubleVektor;
typedef std::vector<std::vector<double>> DoubleMatrica;

void IspisMatrice (DoubleMatrica m)
{
    for (auto red: m) {
        for(auto x:red)
            std::cout<<std::setprecision(12)<<x<<" ";
        std::cout<<"\n";
    }
}

DoubleMatrica OpadajuciPodnizovi (DoubleVektor v)
{
    DoubleMatrica TrazenaMatrica(0, DoubleVektor(0));
    DoubleVektor pomocni;
    v.push_back(1000000);
    for(int i=0; i<v.size(); i++) {
        if(v.at(i)!=1000000 && v[i]>=v[i+1]) pomocni.push_back(v[i]);
        else {
            if(pomocni.size()!=0) {
                pomocni.push_back(v.at(i));
                TrazenaMatrica.push_back(pomocni);
            }
            pomocni.resize(0);
        }
    }
    return TrazenaMatrica;
}

DoubleMatrica   RastuciPodnizovi(DoubleVektor v)
{
    DoubleMatrica TrazenaMatrica(0,std::vector<double> (0));
    DoubleVektor pomocni;
    v.push_back(-1000000);
    for(int i=0; i<v.size(); i++) {
        if(v.at(i)!=-1000000 &&  v[i]<=v[i+1]) pomocni.push_back(v[i]);
        else {
            if(pomocni.size()!=0) {
                pomocni.push_back(v.at(i));
                TrazenaMatrica.push_back(pomocni);
            }
            pomocni.resize(0);
        }
    }
    return TrazenaMatrica;
}

int main ()
{
    std::cout<<"Unesite broj elemenata vektora: ";
    int BrojElemenata;
    std::cin>>BrojElemenata;
    std::cout<<"Unesite elemente vektora: ";
    DoubleVektor UneseniVektor;

    for(int i=0; i<BrojElemenata; i++) {                                        //Unos vektora
        double broj;
        std::cin>>broj;
        UneseniVektor.push_back(broj);
    }

    std::cout<<"Maksimalni rastuci podnizovi: \n";
    DoubleMatrica Rastuci (RastuciPodnizovi(UneseniVektor));
    IspisMatrice(Rastuci);
    std::cout<<"Maksimalni opadajuci podnizovi: \n";
    DoubleMatrica Opadajuci (OpadajuciPodnizovi(UneseniVektor));
    IspisMatrice(Opadajuci);
    return 0;
}