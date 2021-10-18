#include <iostream>
#include <limits>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;

typedef std::vector<int> Vektor;

Vektor IzdvojiGadne(Vektor v, bool opak){
    Vektor gadni;
    for(int broj: v) {
        bool preskoci=false;
        int suma_0(0),suma_1(0),suma_2(0), potenc(broj);
        do {
            switch(abs(broj%3)) {
                case 0: suma_0++; break;
                case 1: suma_1++; break;
                case 2: suma_2++; break;
            }
            broj/=3;
        }while(broj!=0);
        if( ((suma_0%2!=opak) or (suma_0==0)) and ((suma_1%2!=opak) or (suma_1==0)) and ((suma_2%2!=opak) or (suma_2==0))){
            for(int x: gadni)
                if(x==potenc){preskoci=true; break;}
            if(!preskoci)
                gadni.push_back(potenc);
        }
    }
    return gadni;
}



int main (){
    cout<<"Unesite brojeve (0 za prekid unosa): ";
    Vektor pocetni;
    while(true){
        int broj;
        cin>>broj;
        if(broj==0) break;
        pocetni.push_back(broj);
    }
    Vektor opaki(IzdvojiGadne(pocetni,true)),odvratni(IzdvojiGadne(pocetni,false));
    cout<<"Opaki: ";
    for(int x:opaki)
        cout<<x<<" ";
    cout<<"\nOdvratni: ";
    for(int x:odvratni)
        cout<<x<<" ";
    return 0;
}
