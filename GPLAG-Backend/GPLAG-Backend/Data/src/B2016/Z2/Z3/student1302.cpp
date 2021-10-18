#include <iostream>
#include <algorithm>
#include <iomanip>
#include <deque>
#include <type_traits>
#include <cmath>
#include <vector>

int SumaDjelilaca (long long int broj){
    int suma = 0;
    if (broj<0)
        broj=std::abs(broj);
    for(long long int i=2; i<broj; ++i){
        if(broj%i==0)
            suma+=i;
    }
    suma+=broj+1;
    return suma;
}

bool jelprost (long long int broj){
    int brojac = 0;
    if(broj<0)
        broj=std::abs(broj);
    for(long long int i = 2; i<broj; ++i){
        if(broj%i==0) ++brojac;
    }
    if(brojac==0) return true;
    else return false;
}
int BrojProstihFaktora (long long int broj){
    int brojac = 0;
    if(broj<0)
        broj=std::abs(broj);
    for(long long int i = 2; i<broj; ++i){
        long long int pikalise;
        if(broj%i==0){
            pikalise=i;
            bool dalijeprost = jelprost(i);
            if(dalijeprost) brojac++;
        }
    }
    return brojac;
}
int suma_sumica (long long int broj){
    int suma = 0;
    long long int cifra = broj;
    if (cifra<0)
        cifra = std::abs(cifra);
    while (cifra!=0){
        cifra=broj%10;
        suma+=cifra;
        cifra/=10;
    }    
    return suma;
}
int BrojSavrsenihDjelilaca (long long int broj){
    int brojac = 0, suma = 0;
    if(broj<0)
        broj=std::abs(broj);
    for(long long int i = 2; i<broj; ++i){
        if(broj%i==0){
            long long int cifrica = i;
            for(int j = 1; j<i; ++j){
            if(cifrica%j==0)
                suma+=j;
        }
        if(suma == cifrica) brojac++;
        suma = 0;
    }
}
    if(SumaDjelilaca(broj)-broj == broj) brojac++;
    return brojac;
}
template <typename t1, typename t2, typename t3, typename t4>

auto UvrnutiPresjek (t1 pok1, t1 pok2, t2 pok3, t2 pok4, t3 funkcija(t4)) -> std::deque<std::deque<typename std::remove_reference <decltype (*pok1)>::type>> { //removamo referencu
    std::deque<std::deque<typename std::remove_reference <decltype (*pok1)>::type>> vracam;
    while(pok1!=pok2){
        t2 pomoc(pok3);
        while(pok3!=pok4){
            if(funkcija(*pok3)==funkcija(*pok1)){
                vracam.push_back({*pok1, *pok3, funkcija(*pok1)});
            }
            pok3++;
        }
        pok3=pomoc;
        pok1++;
    }
    int prvi = 0;
    std::sort(vracam.begin(), vracam.end(), [vracam, &prvi](std::deque<std::deque<typename std::remove_reference <decltype (*pok1)>::type>> prva, std::deque<std::deque<typename std::remove_reference <decltype (*pok1)>::type>> druga){
        prvi = 0;
        if(prva[vracam[0].size()-1] == druga[vracam[0].size()-1]){
            if(prva[prvi] > druga[prvi]) 
                return false;
            else if (prva[prvi]==druga[prvi]){
                ++prvi;
                if(prva[prvi] > druga[prvi]) 
                    return false; 
                return true;
            }
            else if(prva[vracam[0].size()-1] > druga[vracam[0].size()-1])
                return false;
            return true;
        
        }
    });
    return vracam;
} 
//AKO FUNKCIJA PRIMA SAMO 4 PARAMETRA UVRNUTI PRESJEK
template <typename t1, typename t2>
auto UvrnutiPresjek (t1 pok1, t1 pok2, t2 pok3, t2 pok4) -> std::deque<std::deque<typename std::remove_reference <decltype (*pok1)>::type>> {
    std::deque<std::deque<typename std::remove_reference <decltype (*pok1)>::type>> vracam;
    while(pok1!=pok2){
        t2 pomoc(pok3);
        while(pok3!=pok4){
            if(*pok3==*pok1){
                vracam.push_back({*pok1, 0, 0});
            }
            pok3++;
        }
        pok3=pomoc;
        pok1++;
    }
    int prvi = 0;
    std::sort(vracam.begin(), vracam.end(), [&prvi](std::deque<std::deque<typename std::remove_reference <decltype (*pok1)>::type>> prva, std::deque<std::deque<typename std::remove_reference <decltype (*pok1)>::type>> druga){
        if(prva[prvi]>druga[prvi]) return false;
        return true;
    });
    return vracam;
}

int main () {
    //std::cout<<"BROJ PROSTIH: "<<BrojProstihFaktora(21);
    //std::cout<<"BROJ SAVRSENIH: "<<BrojSavrsenihDjelilaca(168);
    long long int x, y, n, n1;
    std::cout<<"Unesite broj elemenata prvog kontejnera: ";
    std::cin>> x;
    std::cout<<"Unesite elemente prvog kontejnera: ";
    std::deque<long long int> prvi;
    std::deque<long long int> drugi;
    for(long long int i = 0; i!= x; ++i){
        std::cin>>n;
        prvi.push_back(n);
    }
    std::cout<<"Unesite broj elementa drugog kontejnera: ";
    std::cin>>y;
    for(long long int i = 0; i!=y; ++i){
        std::cin>>n1;
        drugi.push_back(n1);
    }
    std::cout<<"Dovidjenja!";
	return 0;
}