#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <vector>

using std::cout;
using std::cin;

int fja(int x, int y) {
    return -2*x+y;
}

bool DaLiJeProst(int n) {
    if(n<=1) return false;
    bool Prost=true;
    
    for(int i=2; i*i<n; i++) {
        if(i==n) break;
        if(n%i==0) {
            Prost=false;
            break;
        }
    }
    return Prost;
}

bool BrojProstihFaktora(int x, int y) {
    int x_broj(-1), y_broj(-1);
    if(x<=1) x_broj=0;
    if(y<=1) y_broj=0;
    
    if(x_broj!=0) {
        x_broj=0;
        for(int i=2; i*i<=x; i++) {
            if(DaLiJeProst(i) && x%i==0) x_broj++;
        }
    }
    if(y_broj!=0) {
        y_broj=0;
        for(int i=2; i*i<=y; i++) {
            if(DaLiJeProst(i) && y%i==0) y_broj++;
        }
    }
    if(x_broj==y_broj) return x>y;
    return x_broj>y_broj;
    
}

template <typename NekiTip1, typename NekiTip2>
void SortirajPodrucjeVrijednosti(NekiTip1 pocetak_prvog, NekiTip1 kraj_prvog, NekiTip1 drugi, NekiTip2 treci, decltype(*(treci)+*treci) fun(decltype(*(drugi)+*drugi) x, decltype(*(drugi)+*drugi) y), bool logy_fun(decltype(*drugi+*drugi) x, decltype(*drugi+*drugi) y)) {
    
    std::sort(pocetak_prvog, kraj_prvog, logy_fun);
    std::sort(drugi, drugi+(kraj_prvog-pocetak_prvog), logy_fun);
    
    int brojac(0), korak(kraj_prvog-pocetak_prvog);
    
    while(pocetak_prvog!=kraj_prvog) {
        auto rezultat(fun(*pocetak_prvog, *drugi));
        auto p(std::find(treci, treci+korak, rezultat));
        if(p==treci+korak) throw std::logic_error("Vrijednost koja odgovara nekom od parova nije nadjena");
        else {
            auto pomocna(*p);
            *p=*(treci+brojac);
            *(treci+brojac)=pomocna;
        }
        pocetak_prvog++;
        drugi++;
        brojac++;
    }
}

int main ()
{
    int n, broj;
    std::vector<int> v1, v2, v3;
    
    cout<<"Unesite broj elemenata: ";
    cin>>n;
    cout<<"Unesite elemente prvog vektora: ";
    
    for(int i=0; i<n; i++) {
        cin>>broj;
        auto p1(std::find(v1.begin(), v1.end(), broj));
        if(p1==v1.end()) v1.push_back(broj);
        else i--;
    }
    
    cout<<"Unesite elemente drugog vektora: ";
    for(int i=0; i<n; i++) {
        cin>>broj;
        auto p2(std::find(v2.begin(), v2.end(), broj));
        if(p2==v2.end()) v2.push_back(broj);
        else i--;
    }
    cout<<"Unesite elemente treceg vektora: ";
    for(int i=0; i<n; i++) {
        cin>>broj;
        auto p3(std::find(v3.begin(), v3.end(), broj));
        if(p3==v3.end()) v3.push_back(broj);
        else i--;
    }
    try {
        SortirajPodrucjeVrijednosti(v1.begin(), v1.end(), v2.begin(), v3.begin(), fja, BrojProstihFaktora);
        cout<<"\nNakon sortiranja podrucja vrijednosti imamo sljedece trojke:\n";
        for(int i=0; i<n; i++) {
            cout<<"f("<<v1[i]<<", "<<v2[i]<<") = "<<v3[i]<<"\n";
        }
    } catch(std::logic_error izuzetak) {
        cout<<"\nIzuzetak: "<<izuzetak.what();
    }
    
    
	return 0;
}