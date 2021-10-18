#include <iostream>
#include <vector>
#include <cmath>

using std::cin;
using std::cout;

typedef std::vector<int> Vektor;

int BrojCifara(int broj){
    int i(1), brCifara(0);
    while((broj / int(pow(3, i))) != 0){
        brCifara++;
        i++;
    }
    return brCifara;
}
Vektor Isti(Vektor novi, int x){
    Vektor v(novi);
    if(v.size() == 0)
        v.push_back(x);
    else{
        bool isti = false;
        for(int i = 0; i < int(v.size()); i++){
            if(v[i] == x){
                isti = true;
                break;
                }
            if(i == v.size() - 1) break;
        }
        if(isti == false)
            v.push_back(x);
    }
    return v;
}

Vektor IzdvojiGadne(Vektor brojevi, bool x){
    Vektor novi;
    for(int i : brojevi){
        int niz[3]{0, 0, 0};
        int m(abs(i));
        for(int j = BrojCifara(i); j >= 0; j--){
            for(int k : {2, 1, 0}){
                if((m - int(pow(3, j))*k) >= 0){
                    m-= int(pow(3, j))*k;
                    niz[k]++;
                    break;
                }
            }
        }
        if(x){
            if(niz[0] % 2 == 0 && niz[1] % 2 == 0 && niz[2] % 2 == 0)
                novi = (Isti(novi, i));
        }
        if(!x){
            for(int k = 0; k <= 2; k++){
                if(niz[k] == 0)
                    niz[k]++;
            }
            if(niz[0] % 2 != 0 && niz[1] % 2 != 0 && niz[2] % 2 != 0)
                novi = (Isti(novi, i));
        }
    }
    return novi;
}


int main ()
{
    Vektor v;
    int x;
    cout << "Unesite brojeve (0 za prekid unosa): ";
    cin >> x;
    while(x != 0){
        v.push_back(x);
        cin >> x;
    }
    cout << "Opaki: ";
    for(int i : IzdvojiGadne(v, true))
        cout <<  i << " ";
    
    cout << std::endl << "Odvratni: ";
    
    for(int j : IzdvojiGadne(v, false))
        cout << j << " ";
	return 0;
}

