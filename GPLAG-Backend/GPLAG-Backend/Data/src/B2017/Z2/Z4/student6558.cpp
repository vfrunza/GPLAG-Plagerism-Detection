#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <stdexcept>
#include <iterator>
bool Prost(int faktor)
{
    if(faktor<2) return false;
    for(int i=2; i<faktor; i++) {
        if(faktor%i==0) return false;
    }
    return true;
}
template <typename NekiTip1, typename NekiTip2>
bool Broj_Prostih_Faktora(NekiTip1 x, NekiTip2 y)
{
    auto temp1(x);
    int brojac1(0);
    for(int i=0; i<abs(temp1); i++) {
        if(Prost(i)) {
            if(temp1%i==0) {
                brojac1++;
                temp1/=i;
                i=0;
            }
        }
    }
    auto temp2(y);
    int brojac2(0);
    for(int i=0; i<abs(temp2); i++) {
        if(Prost(i)) {
            if(temp2%i==0) {
                brojac2++;
                temp2/=i;
                i=0;
            }
        }
    }
    if(brojac1>brojac2) return true;
    else if(brojac1==brojac2) {
        if(x>y) return true;
        else if(abs(x)==abs(y)) {
            if(x>y) return true;
        }
    }
    return false;
}
//Provjera da li postoji broj u nizu tokom unosa
template <typename Kontejner>
bool NePostoji(const Kontejner &x,int broj)
{
    for(int i=0; i<x.size(); i++) {
        if(x.at(i)==broj) return false;
    }
    return true;
}
template <typename Kontejner>
void Unos_Niza(Kontejner &x, int broj_el)
{
    int i(0);
    do {
        int pomocna;
        std::cin>>pomocna;
        if(!(NePostoji(x, pomocna))) {
            i--;
        } else {
            x.push_back(pomocna);
        }
        i++;
    } while(i<broj_el);
}
//Zamjena mjesta elementima u nizu
template <typename iter>
void Swapaj(iter p1, iter p2)
{
    auto pomocna(*p1);
    *p1=*p2;
    *p2=pomocna;
}
//F(x,y) funkcija
template <typename iter1, typename iter2, typename iter3>
iter3 Funkcija(iter1 p1, iter2 p2)
{
    iter3 suma=-2*(*p1)+*p2;
    return suma;
}
template <typename iter1, typename iter2, typename iter3>
void SortirajPodrucjeVrijednosti(iter1 p1, iter1 p2, iter2 p3, iter3 p4, decltype(*p4+*p4) func(iter1 x, iter2 y), bool sortiranje(decltype(*p1+*p1) x, decltype(*p1+*p1) y))
{
    auto pok1(p1);
    auto pok3(p3);
    int razlika(std::distance(p1,p2));
    auto pok(p3);
    std::advance(pok, razlika);
    //Sortiranje prva dva niza
    std::sort(p1, p2, sortiranje);
    std::sort(p3, pok, sortiranje);
    auto kraj(p4);
    std::advance(kraj, razlika);
    //Trazenje f(x,y) u trecem bloku
    while(p1!=p2) {
        auto suma(func(p1, p3));
        auto el(std::find(p4, kraj, suma));
        if(el==kraj) throw std::logic_error ("Vrijednost koja odgovara nekom od parova nije nadjena");
        else {
            if(p4!=el) {
                Swapaj(p4,el);
            }
        }
        p1++;
        p3++;
        p4++;
    }
}
int main ()
{
    std::cout << "Unesite broj elemenata: ";
    int broj_el;
    std::cin >> broj_el;
    std::vector<int> v1;
    std::cout << "Unesite elemente prvog vektora: ";
    Unos_Niza(v1,broj_el);
    std::deque<int> v2;
    std::cout << "Unesite elemente drugog vektora: ";
    Unos_Niza(v2,broj_el);
    std::vector<int> v3;
    std::cout << "Unesite elemente treceg vektora: ";
    Unos_Niza(v3,broj_el);
    try {
        SortirajPodrucjeVrijednosti(v1.begin(), v1.end(), v2.begin(),v3.begin(),Funkcija, Broj_Prostih_Faktora);
        std::cout <<std::endl<< "Nakon sortiranja podrucja vrijednosti imamo sljedece trojke: " << std::endl;
        for(int i=0; i<v1.size(); i++) {
            std::cout << "f("<<v1.at(i)<<", "<<v2.at(i)<<") = "<<v3.at(i) << std::endl;
        }
    } catch(std::logic_error izuzetak) {
        std::cout <<std::endl<<"Izuzetak: "<< izuzetak.what() << std::endl;
    }
    return 0;
}