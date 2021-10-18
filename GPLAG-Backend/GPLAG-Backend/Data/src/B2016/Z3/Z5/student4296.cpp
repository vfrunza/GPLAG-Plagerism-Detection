#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>
#include <string>
#include <deque>
#include <algorithm>
#include <cstring>
#include <iterator>
#include <list>
#include <set>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
struct Dijete {
    std::string ime;
    Dijete *sljedeci;
};

int broj_slova(string s){
    int i{},brojac{};
    while(i<s.size()){
        if((s[i]>='0' && s[i]<='9') || (s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z'))
            brojac++;
    i++;
}
return brojac;
}
  Dijete *KreirajPovezanuListu(std::vector<string> V){
        Dijete *pocetak(nullptr), *prethodni;
        for(int i=0;i<V.size(); i++) {
            
            Dijete *novi=nullptr;
            novi=(new Dijete); // Kreiranje novog čvora
            novi->ime = V[i];
            novi->sljedeci = nullptr;
            if(!pocetak) pocetak = novi; // Prvi čvor...
            else prethodni->sljedeci = novi; // Svi osim prvog...
            prethodni = novi;
            if(i+1==V.size())
                        novi->sljedeci= pocetak;

        }
        return pocetak;
    }

vector<std::set<string>> Razvrstavanje(std::vector<string> V, int k){
    if(k<1 || k>V.size()) throw std::logic_error("Razvrstavanje nemoguce");
    int  n(V.size());
    
    int broj_clanova,brojac{};
    broj_clanova=n/k;
    int broj_dodatnih;
    broj_dodatnih=n%k;
    Dijete *L;
    L=KreirajPovezanuListu(V);
    vector<int> M(k);
    for(int i=0; i<k; i++){
        if(i<broj_dodatnih)
            M[i]=(broj_clanova+1);
        else M[i]=(broj_clanova);
    }
    vector<std::set<string>> T(k);
    auto it=L;
    int i=0;
    T[0].insert(L->ime);
    int l=1;
    auto zadnji(L);
    while(l<n){
        l++;
        zadnji=zadnji->sljedeci;
    }
    brojac=broj_slova(L->ime);

    auto kt=L;
    auto d=kt->sljedeci;
     zadnji->sljedeci=d;
    delete kt;
    kt=d;
    auto L1(kt);
    n--;
    while(n>=0 && i<M.size()){
        if(T[i].size()==M[i])
            i++;
        it=kt;
        for(int i=1; i< brojac; i++)
            kt=kt->sljedeci;

        T[i].insert(kt->ime);
        if(n>1){
            auto p1(L1);
            auto p2(p1);
            brojac=broj_slova(kt->ime);
            if(p1==kt)
                p1=p1->sljedeci;
            for(;p1!=kt; p1=p1->sljedeci)
                p2=p1;
            auto d(kt);
            d=d->sljedeci;
            p2->sljedeci=d;
            delete kt;
            kt=d;
            L1=d;
        }
        if(n==1){
            n--;
            delete kt;
        }
        n--;
        if(T[i].size()==M[i])
            i++;
    }
    
    return T;
    
}

int main (){
    int n=1,k;
    vector<string> V;
    cout<<"Unesite broj djece: ";
    cin>>n;
    V.resize(n);
    cin.ignore(1000,'\n');
    cout<<"Unesite imena djece: ";
    for(int i=0; i<n; i++)
        	std::getline(std::cin, V[i]);
    cout<<endl<<"Unesite broj timova: ";
    cin>>k;
    try{
        vector<std::set<string>> K;
        K=Razvrstavanje(V,k);
        for(int i=0; i<K.size(); i++){
            cout<<"Tim "<<i+1<<": ";
             auto ita=K[i].begin();
        while(ita!=K[i].end()) {
            ita++;
            if(ita==K[i].end()) {
                ita--;
                cout<<*ita;
                break;
            } else {
                ita--;
                std::cout <<*ita<<", ";
            }
            ita++;

        }
            cout<<endl;
        }
    }
    catch(std::logic_error e){
        cout<<"Izuzetak: "<<e.what()<<endl;        
    }


	return 0;
}