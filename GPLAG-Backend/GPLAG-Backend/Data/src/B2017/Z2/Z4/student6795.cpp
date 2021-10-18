/B 2017/2018, Zadaća 2, Zadatak 4
#include <iostream>
#include <vector>
#include <algorithm>
#include <type_traits>
#include <functional>

template <typename Tip>
int BrojElemenata(Tip pocetak, Tip iza_kraja)
{

    int brojac(0);
    while(pocetak != iza_kraja) {
        ++brojac;
        ++pocetak;
    }

    return brojac;
}

template <typename Tip>
bool f2(Tip pocetak, int vel)
{
    bool breakaj(false);
    if(vel <= 0) throw "Sortiranje nije uspjelo!";
    Tip p = pocetak;
    Tip s = pocetak + 1;
    int i(0);
    int j(1);
    int prosti_faktori(0);
    int prosti_faktori2(0);
    while(i < vel - 1) {

        if(breakaj) {
            --p;
            --i;
            breakaj = false;
        }


        s = pocetak + 1 + i;
        j = 1 + i;
        int a = *p;
        if(a == 1) prosti_faktori = 1;
        else {
            int b;
            int k = a % 2;
            while(k==0) {
                b=a/2;
                ++prosti_faktori;
                a = b;
                k = a%2;
            }
            for(int x=3; x<=a; x+=2) {
                int k=a%x;
                while(k==0) {
                    b=a/x;
                    ++prosti_faktori;
                    a=b;
                    k=a%x;
                }
            }
        }

        while(j < vel) {
            prosti_faktori2 = 0;

            int a = *s;
            if(a == 1) prosti_faktori2 = 1;
            else {
                int b;
                int k = a % 2;
                while(k==0) {
                    b=a/2;
                    ++prosti_faktori2;
                    a = b;
                    k = a%2;
                }
                for(int x=3; x<=a; x+=2) {
                    int k=a%x;
                    while(k==0) {
                        b=a/x;
                        ++prosti_faktori2;
                        a=b;
                        k=a%x;
                    }
                }
            }

            if(prosti_faktori2 == prosti_faktori) {
                if(*s > *p) {
                    typename std::remove_reference<decltype(*pocetak + *pocetak)>::type temp(*p);
                    *p = *s;
                    *s = temp;
                }
            } else if(prosti_faktori2 > prosti_faktori) {
                typename std::remove_reference<decltype(*pocetak + *pocetak)>::type temp(*p);
                *p = *s;
                *s = temp;
                breakaj = true;
                break;
            }

            if(j != vel-1) ++s;
            ++j;
        }
        if(i != vel-2) ++p;
        ++i;
        prosti_faktori = 0;
    }
    
    return true;
}

//template <typename Tip1, typename Tip2>
int f(int x, int y){
   
  int rezultat((-1 * 2 * x) + y);
   
   return rezultat;
}



template <typename Tip1, typename Tip2, typename Tip3 ,typename TipFun, typename TipFun2>
void SortirajPodrucjeVrijednosti (Tip1 pocetak_prvog, Tip1 iza_kraja, Tip2 pocetak_drugog, Tip3 pocetak_treceg, 
TipFun f, TipFun2 f2)
{

    int velicina(BrojElemenata(pocetak_prvog, iza_kraja));

    if(!(f2(pocetak_prvog, velicina) && f2(pocetak_drugog, velicina))) throw "Sortiranje nije Uspjelo";
    
    Tip1 pok1(pocetak_prvog);
    Tip2 pok2(pocetak_drugog);
    Tip3 pok3(pocetak_treceg);
    
    int brojac(0);
    for(int i(0); i<velicina; ++i){
        Tip3 provjera(f(*pok1, *pok2));
        for(int j(0); j<velicina; ++j){
            if(*pok3 == provjera) ++brojac;
            if(brojac == 0) throw std::logic_error("Vrijednost koja odgovara nekom od parova nije nadjena");
            ++pok3;
        }
        pok3 = pocetak_treceg;
        ++pok1;
        ++pok2;
        brojac = 0;
    }
    pok1 = pocetak_prvog;
    pok2 = pocetak_drugog;
    pok3 = pocetak_treceg;


}



int main ()
{
    std::cout<<"Unesite broj elemenata: ";
    int br_elemenata;
    std::cin>>br_elemenata;
    std::vector<int> S1(br_elemenata), S2(br_elemenata), S3(br_elemenata);
    std::cout<<"Unesite elemente prvog vektora: ";
    std::for_each(std::begin(S1), std::begin(S1) + br_elemenata, [](int &broj) {
        std::cin>>broj;
    });
    std::cout<<"Unesite elemente drugog vektora: ";
    std::for_each(std::begin(S2), std::begin(S2) + br_elemenata, [](int &broj) {
        std::cin>>broj;
    });
    std::cout<<"Unesite elemente treceg vektora: ";
    std::for_each(std::begin(S3), std::begin(S3) + br_elemenata, [](int &broj) {
        std::cin>>broj;
    });

    SortirajPodrucjeVrijednosti(std::begin(S1), std::end(S1), std::begin(S2), std::begin(S3), f, f2);

    return 0;
}