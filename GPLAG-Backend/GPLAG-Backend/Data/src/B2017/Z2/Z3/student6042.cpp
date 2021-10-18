#include <iostream>
#include <new>
#include <vector>
#include <stdexcept>

using namespace std;

template <typename TipElemenata>
vector <TipElemenata> Unos (int n) {
    TipElemenata broj;
    vector<TipElemenata> v;
    for (int i=0; i<n; i++) {
        cin>>broj;
        v.push_back (broj);
    }
    return v;
}

typename TipElemenata ** AlocirajFragmentirano (const vector<TipElemenata> &v, int &koliko_puta) {
    if (!v) {
        throw range_error ("Prazan vektor! ");
        
    TipElemenata **p=nullptr;
    }
    return p
}

typename TipElemenata ** AlocirajKontinualno (const vector<TipElemenata> &v, int &koliko_puta) {
    if (!v) {
        throw range_error ("Prazan vektor! ");
        
    TipElemenata **p=nullptr;
    }
    return p
}

int main ()
{
    int br_el;
    cout<<"Unesite broj elemenata vektora: ";
    cin>>br_el;
    cout<<"Unesite elemente vektora: ";
    auto v=Unos(br_el);
    cout<<"Odaberite alokaciju: 1 - fragmentirana, 0 - kontinualna: ";
    int tip_alokacije;
    cin>>tip_alokacije;
    cout<<"Dinamicki alocirana matrica: ";
    int koliko_puta (0);
    if (tip_alokacije==1)
        auto m=AlocirajFragmentirano (v, koliko_puta);
    if (tip_alokacije==0)
        auto m=AlocirajKontinualno (v, koliko_puta);
        

return 0;
}