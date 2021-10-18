#include <iostream>
#include <vector>
#include <cmath>

bool jeLiProst(int broj)
{
    if(broj<0)broj*=(-1);
    int a(sqrt(broj));
    for(int i=2; i<=a; i++) {
        if(broj%i==0)return false;
    }
    return true;
}

int simetrija(int take,int token)
{
    long long counter(pow(10,token-1)),suma(0);
    while(take!=0) {
        suma+=((take%10)*counter);
        counter/=10;
        take/=10;
    }
    return suma;
}

bool Take1(int take)
{
    long long counter(1),suma(0),token(0);
    while(take!=0) {
        suma+=((take%3)*counter);
        counter*=10;
        take/=3;
        token++;
    }
    int pozovi(simetrija(suma,token));
    return suma==pozovi;
}

std::vector<int> IzdvojiSimetricneTernarne(std::vector<int>v,bool t)
{
    std::vector<int> noviVektor;
    for(int x:v) {
        switch(t) {
        case 1:
            if(jeLiProst(x) && Take1(x))
                noviVektor.push_back(x);
            break;
        case 0:
            if(!jeLiProst(x) && Take1(x))
                noviVektor.push_back(x);
            break;
        }
    }
   // for(int i=0; i<noviVektor.size(); i++)
     //   for(int j=i+1; j<noviVektor.size(); j++)
       //     if(noviVektor.at(i)==noviVektor.at(j))noviVektor.erase(noviVektor.begin()+j);
       
    return noviVektor;
}

int main ()
{
    std::cout<<"Unesite elemente vektora (-1 za kraj): ";
    std::vector<int> v1;
    for(;;) {
        int broj;
        std::cin>>broj;
        if(broj==-1)break;
        v1.push_back(broj);
    }
    int var;
    std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
    while(std::cin>>var,var!=0 && var!=1) 
        std::cout<<"Neispravan unos! Unesite ponovo: ";
    std::vector<int> v2;
    bool var1(var);
    switch(var1) {
    case 1:
        v2=IzdvojiSimetricneTernarne(v1,var);
        if(v2.size()==0) {
            std::cout<<"Nema prostih simetricnih brojeva u vektoru.";
            return 0;
        }
        std::cout<<"Prosti simetricni brojevi iz vektora su: ";
        for(int i=0; i<v2.size(); i++) {
            if(v2.size()-1==i) {
                std::cout<<v2.at(i)<<".";
                break;
            }
            std::cout<<v2.at(i)<<", ";
        }
        break;
    case 0:
        v2=IzdvojiSimetricneTernarne(v1,var);
        if(v2.size()==0) {
            std::cout<<"Nema slozenih simetricnih brojeva u vektoru.";
            return 0;
        }
        std::cout<<"Slozeni simetricni brojevi iz vektora su: ";
        for(int i=0; v2.size(); i++) {
            if(v2.size()-1==i) {
                std::cout<<v2.at(i)<<".";
                break;
            }
            std::cout<<v2.at(i)<<", ";
        }
        break;
    }
    return 0;
}