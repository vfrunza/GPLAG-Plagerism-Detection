#include <iostream>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <new>
#include <string>
#include <iomanip>

using std::cout;
using std::cin;

template <typename NekiTip>
int Periodican(const std::vector<NekiTip> &v) {
    int period(v.size());
    for(int i=1; i<v.size(); i++) {
        int period(i);
        for(int j=0; j<v.size(); j++) {
            if(j+i>=v.size()) break;
            if(v.at(j)!=v.at(j+i)) {
                period=v.size();
                break;
            }
        }
        if(period==i) return period;
    }
    return period;
}

template <typename NekiTip>
int** AlocirajFragmentirano(const std::vector<NekiTip> &v, int &koliko_puta) {
    if(v.size()==0) throw "Prazan vektor!";
    for(int i=0; i<v.size(); i++) {
        if(v.at(i)<=0) throw std::domain_error("Neispravan vektor!");
    }
    
    int T;
    int konacna_velicina(v.size());
    
    if((T=Periodican<NekiTip>(v))!=v.size()) {
        int broj_cijelih_perioda(v.size()/T);
        if(v.size()%T!=0) {
            konacna_velicina=T*(broj_cijelih_perioda+1);
        }  
        koliko_puta=konacna_velicina/T;
    } else {
        konacna_velicina=2*v.size();
        koliko_puta=2;
    }
    
    int **a(nullptr);
    try {
         a=new int*[konacna_velicina];
    } catch(...) {
        delete[] a;
        throw;
    }
    
    for(int i=0; i<konacna_velicina; i++) {
        try {
            if(i>=v.size()) a[i]=new int[v.at(i-T)];
            else a[i]=new int[v.at(i)];
        } catch(...) {
            for(int j=0; j<i; j++) 
                delete[] a[i];
            delete[] a;
            throw;
        }
    }

    int brojac(0), max_kolona=*std::max_element(v.begin(), v.end());
    
    for(int i=0; i<konacna_velicina; i++) {
        if(i>=v.size()) brojac=v.at(i-T);
        else brojac=v.at(i);
        for(int j=0; j<brojac; j++) {
            a[i][j]=max_kolona-(brojac-1-j);
        }
    }
    return a;
}

template <typename NekiTip>
int** AlocirajKontinualno(const std::vector<NekiTip> &v, int &koliko_puta) {
    if(v.size()==0) throw "Prazan vektor!";
    for(int i=0; i<v.size(); i++) {
        if(v.at(i)<=0) throw std::domain_error("Neispravan vektor!");
    }
    
    int T;
    int konacna_velicina(v.size());
    
    if((T=Periodican<NekiTip>(v))!=v.size()) {
        int broj_cijelih_perioda(v.size()/T);
        if(v.size()%T!=0) {
            konacna_velicina=T*(broj_cijelih_perioda+1);
        }  
        koliko_puta=konacna_velicina/T;
    } else {
        konacna_velicina=2*v.size();
        koliko_puta=2;
    }
    
    int** a(nullptr);
    try {
         a=new int*[konacna_velicina];
    } catch(...) {
        throw;
    }
    
    int broj_elemenata(0);
    for(int i=0; i<konacna_velicina; i++) {
        if(i>=v.size()) broj_elemenata+=v.at(i-T);
        else broj_elemenata+=v.at(i);
    }
    
    try {
        a[0]=new int[broj_elemenata];
    } catch(...) {
        delete[] a;
        throw;
    }
    
    for(int i=1; i<konacna_velicina; i++) {
        if((i-1)>=v.size()) a[i]=a[i-1]+v.at(i-T-1);
        else a[i]=a[i-1]+v.at(i-1);
    }
    
    int brojac(0);
    for(int i=0; i<konacna_velicina; i++) {
        if(i>=v.size()) brojac=v.at(i-T);
        else brojac=v.at(i);
        for(int j=0; j<brojac; j++) {
            a[i][j]=brojac-j;
        }
    }
    
    return a;
}
int main ()
{
    int n, koliko_puta;
    std::vector<int> v;
    cout<<"Unesite broj elemenata vektora: ";
    cin>>n;
    try {
        v.resize(n);
    } catch(...) {
        cout<<"Izuzetak: Nedovoljno memorije!";
        return 0;
    }
    
    cout<<"Unesite elemente vektora: ";
    for(int i=0; i<n; i++) {
        cin>>v.at(i);
    }
    
    int izbor;
    cout<<"Odaberite alokaciju: 1 - fragmentirana, 0 - kontinualna: ";
    cin>>izbor;
    int** a;
    try {
        if(izbor==1)  a=AlocirajFragmentirano(v, koliko_puta);
        else if(izbor==0) a=AlocirajKontinualno(v, koliko_puta);
        int period=Periodican(v), brojac(0);
        cout<<"Dinamicki alocirana matrica:\n";
        for(int i=0; i<koliko_puta*period; i++) {
            if(i>=v.size()) brojac=v.at(i-period);
            else brojac=v.at(i);
            for(int j=0; j<brojac; j++) {
                cout<<std::left<<std::setw(3)<<a[i][j];
            }
            cout<<"\n";
        }
        if(izbor==1) {
            for(int i=0; i<koliko_puta*period; i++) 
                delete[] a[i];
            delete[] a;
        } else if(izbor==0) {
            delete[] a[0]; delete[] a;
        }
    } catch(const char *msg) {
        std::string s(msg);
        cout<<"Izuzetak: "<<s;
    } catch(std::bad_alloc) {
        cout<<"Izuzetak: Nedovoljno memorije";
    } catch(std::domain_error izuzetak) {
        cout<<"Izuzetak: "<<izuzetak.what();
    }
    
    
	return 0;
}