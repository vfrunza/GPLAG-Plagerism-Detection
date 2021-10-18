#include <iostream>
#include <vector>
#include <limits>
#include <cmath>
typedef std::vector<int> vektor;
bool DaLiJeProst(int broj)
{
    if(broj<=1) return false;
    for(int i=2; (unsigned int )(i*i)<=broj; i++) {
        if(broj%i==0) return false;
    }
    return true;
}

bool Simetrican(int broj)
{
    int temp;
    temp=broj;
    int a(0);
    do {
        a*=10;
        a+=temp%10;
        temp/=10;
    } while(temp!=0);

    return(a==broj);
}
int Ternar(int broj)
{
    int a(0);
    std::vector<int> v;
    v.clear();
    do {
        
        a=broj%3;
        v.push_back(a);
        broj/=3;
    } while (broj!=0);
    int tri(0);
    for(int i=v.size()-1;i>=0;i--)
    {
        
        tri=tri*10+v.at(i);
    }
    return tri;
}
vektor IzdvojiSimetricneTernarne (vektor brojevi, bool logicki)
{

    vektor novi;
    bool minus=false;
    for(int i(0); i<brojevi.size(); i++) {
        minus=false;
        if(brojevi.at(i)<0) {
            brojevi.at(i)*=-1;
            minus=true;
        }
        if(logicki) {
            if(DaLiJeProst(brojevi.at(i))) {
                int broj=(Ternar(brojevi.at(i)));
                if(Simetrican(broj)) {
                    bool dodaj=true;
                    if(minus) brojevi.at(i)*=-1;
                    for(auto x:novi)
                    {
                        if(x==brojevi.at(i))dodaj=false;
                    }
                    if (dodaj) novi.push_back(brojevi.at(i));
                }
            }
        } else {
            if(!(DaLiJeProst(brojevi.at(i))) && brojevi.at(i)!=1) {
                int broj=(Ternar(brojevi.at(i)));
                if(Simetrican(broj)) {
                    bool dodaj=true;
                    
                    if(minus) brojevi.at(i)*=-1;
                    for(auto x:novi)
                    {
                        if(x==brojevi.at(i)) dodaj=false;
                    }
                    if(dodaj) novi.push_back(brojevi.at(i));
                }
            }
        }
    }
    return novi;
}
int main ()
{
    std::cout<<"Unesite elemente vektora (-1 za kraj): ";
    vektor niz;
    int unos;
    while (1) {

        std::cin>>unos;
        if(unos==-1) break;
        else niz.push_back(unos);
    }
    std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
    int broj;
    bool istina;
    while(1) {
        std::cin>>broj;
        if(broj==0 || broj==1) {
            istina=broj;
            break;
        } else std::cout<<"Neispravan unos! Unesite ponovo: ";

    }
   
    vektor simetricniTer=IzdvojiSimetricneTernarne(niz,istina);
    int duzina=simetricniTer.size();
    if(duzina>0) {
        if(istina) std::cout<<"Prosti simetricni brojevi iz vektora su: ";
        else if(!istina) std::cout<<"Slozeni simetricni brojevi iz vektora su: ";
        for(int i(0); i<duzina; i++) {
            if(i>0)std::cout<<", ";
            std::cout<<simetricniTer.at(i);
        }
        std::cout<<".";
    } else {
        if(istina) std::cout<<"Nema prostih simetricnih brojeva u vektoru.";
        else std::cout<<"Nema slozenih simetricnih brojeva u vektoru.";
    }
    return 0;
}