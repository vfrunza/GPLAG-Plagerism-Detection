#include <vector>
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <cmath>

int Provjera (int a){
    if(a==0) return 3;
    std::vector<int> v;
    while(a){
        v.push_back(std::abs(a%3));
        a/=3;
    }
    std::vector<int> cifre(10, 0);
    for(int i=0; i<v.size(); i++){
        cifre[v[i]]++;   
    }

    int kolko(0), brojac_2(0), brojac_3(0);
    for(int i = 0; i<cifre.size();i++){
        if(cifre[i]!=0)kolko++;
        if(cifre[i]%2==0 && cifre[i]!=0){
            brojac_2++;
        }
        if(cifre[i]%2!=0 && cifre[i]!=0){
            brojac_3++;
        }
    }
    int stanje(1);
    if(brojac_2==kolko)
        stanje=2;
    else if(brojac_3==kolko)
        stanje=3;    
    return stanje;
}
std::vector<int> IzdvojiGadne(std::vector<int> v, bool istina){
    std::vector<int> a; int stanje;
    for(int i=0; i<v.size();i++){
        stanje=Provjera(v[i]);
        if(stanje==2 && istina)
            a.push_back(v[i]);
        if(stanje==3 && !istina)
            a.push_back(v[i]);    
    }
    int n(a.size());
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(a[i]==a[j]){
                a.erase(a.begin()+j);
                n--;
                j--;
            }
        }
    }
    return a;
}
int main ()
{
    std::vector<int> v;
    std::cout << "Unesite brojeve (0 za prekid unosa): ";
    int x;
    do{
        std::cin >> x;
        while (!std::cin) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            //std::cout << "Niste unijeli broj!\n";
            //std::cout << "Unesite brojeve (0 za prekid unosa): ";
            std::cin >> x;
        }
        if (x==0) 
            continue;
        v.push_back(x);
    }while (x);
    std::vector<int> opaki(IzdvojiGadne(v,true));
    std::vector<int> odvratni(IzdvojiGadne(v,false));
    std::cout << "Opaki: ";
    for(int i=0; i<opaki.size(); i++){
        std::cout << opaki[i] << " ";
    }
    std::cout << "\nOdvratni: ";
    for(int i=0; i<odvratni.size(); i++){
        std::cout << odvratni[i] << " ";
    }    
    
	return 0;
}