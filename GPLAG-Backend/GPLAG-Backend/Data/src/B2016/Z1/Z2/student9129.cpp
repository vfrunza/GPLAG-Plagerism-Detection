#include <iostream>
#include <iomanip>
#include <vector>
#include <iomanip>
#include <cmath>
//true- opaki brojevi, paran broj jedinica
typedef std::vector<int> IntVektor;

IntVektor    IzdvojiGadne (IntVektor v, bool a) {            //Trazena funkcija
        IntVektor rezultat;
        IntVektor pomocni;
        
        for(int x: v ) {                                    //Prolazim kroz elemente poslanog vektora v
            int broj(x), ostatak(0), brojac1(0), brojac2(0), brojac0(0);
            pomocni.resize(0);
            while(broj!=0) {                                //Tenarna reprezentacija broja, zapisana u vektoru pomocni
                ostatak=abs(broj%3);
                pomocni.push_back(ostatak);
                broj/=3;
            }
            
            for(int i=0; i<pomocni.size(); i++) {
                if(pomocni.at(i)==1) brojac1++;
                else if(pomocni.at(i)==2) brojac2++;
                else if(pomocni.at(i)==0) brojac0++;
                            }
            
             
            if(a && (brojac0%2==0 || brojac0==0) && (brojac1%2==0 || brojac1==0) && (brojac2%2==0 || brojac2==0)) rezultat.push_back(x);
            else if(!a && (brojac0%2!=0 || brojac0==0) && (brojac1%2!=0 || brojac1==0) && (brojac2%2!=0 || brojac2==0)) rezultat.push_back(x);
            }
            
        return rezultat;
}

int main () { 
    std::cout<<"Unesite brojeve (0 za prekid unosa): ";
    IntVektor ZadaniVektor;
    int broj;
    
    while(std::cin>>broj, broj!=0) {                                 //Unos vektora
        ZadaniVektor.push_back(broj);
    }
    
    std::cout<<ZadaniVektor.size();
    
    auto OpakiBrojevi=IzdvojiGadne(ZadaniVektor, true);             //Ispis vektora sa opakim brojevima
    std::cout<<"Opaki: ";
    for(int x:OpakiBrojevi) std::cout<<x<<" ";
    
    
    auto OdvratniBrojevi=IzdvojiGadne(ZadaniVektor, false);            //Ispis vektora sa odvratnim brojevima
    std::cout<<"\nOdvratni: ";
    for(int x: OdvratniBrojevi ) std::cout<<x<<" ";
    return 0;
}