#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>
using std::cout;
using std::cin;
using std::vector;
using std::deque;

typedef vector<vector<long long int>> Matrica;

void IspisiMatricu(Matrica m){
	for (int i(0); i<m.size(); i++){
		for (int j(0); j<m[i].size(); j++){
			cout << std::setw(6) << m[i][j] << " ";
		}
		cout << std::endl;
	}
} 


bool O_Da_Li_Je_Broj_Savrshen(long long int x){
    long long int suma(0);
    for (long long int i=1; i<x; i++){
        if (x%i==0) suma+=i;
    }
    if (x==suma) return true;
    return false;
}


long long int BrojSavrsenihDjelilaca(long long int x){
          long long int brojac(0);
    for (int i=2; i<=x; i++){
        if (x%i==0) { if(O_Da_Li_Je_Broj_Savrshen(i)) brojac++; }
    }
    return brojac;
}

int SumaCifara(long long int x){
    int suma(0);
    while (x!=0){
        int cifra;
        cifra = x%10;
        x=x/10;
        suma+=cifra;
    }
    return suma;
}

int SumaDjelilaca(long long int x){
    int suma(0);
    if (x<0) x=abs(x);
    for (int i=1; i<=x; i++){
        if (x%i==0) suma+=i;
    }
    return suma;
}

bool O_Da_Li_Je_Prost(long long int x){
    bool prost(true);
    for (int i(2); i<x/2; i++){
        if (x%i==0) prost=false;
    }
    return prost;
}


int BrojProstihFaktora(long long int x){
    int brojac(0);
    for (int i=2; i<=x; i++){
        if (x%i==0){
            brojac++;
            x=x/i;
            i=1;
        }
    }
    return brojac;
}


template <typename Container>
bool Sortiranje(Container v1, Container v2){
    if (v1[2]==v2[2]){
        if (v1[0]==v2[0]){
            return v1[1]<v2[1];
        }
        return v1[0]<v2[0];
    }
    return v1[2]<v2[2];
}


template <typename Tip1, typename Tip2,typename Funkcija_kriterija=int, typename Funk_tip=int>
auto UvrnutiPresjek(Tip1 prvi_pocetak, Tip1 prvi_izakraja, Tip2 drugi_pocetak, Tip2 drugi_izakraja, Funkcija_kriterija (*f)(Funk_tip)=nullptr) -> vector<vector<decltype(*prvi_pocetak+*prvi_pocetak)>>{
    vector<vector<decltype(*prvi_pocetak+*prvi_pocetak)>> Matrica_Presjeka;
    int k(0); int brojac(0);
    for (auto i=prvi_pocetak; i<prvi_izakraja; i++){
        for (auto j=drugi_pocetak; j<drugi_izakraja; j++){
            if ((f && f(*i)==f(*j)) || (!f && *i==*j)){
                if (f) {   Matrica_Presjeka.resize(k+1);
                            Matrica_Presjeka[k].push_back(*i);
                            Matrica_Presjeka[k].push_back(*j);
                            Matrica_Presjeka[k].push_back(f(*i)); 
                            k++; }
                            
                else  { Matrica_Presjeka.resize(k+1);
                            Matrica_Presjeka[k].push_back(*i);
                            Matrica_Presjeka[k].push_back(0);
                            Matrica_Presjeka[k].push_back(0); 
                            k++; }
                    
                }
            }
        }
    std::sort(Matrica_Presjeka.begin(), Matrica_Presjeka.end(), Sortiranje<vector<decltype(*prvi_pocetak+0)>>);
    return Matrica_Presjeka;
}
template <typename Container>
bool Sortiranje_Opadajuce(Container k1, Container k2){
    if (k1[0]==k2[0]) return k1[1]>k2[1];
    return k1[0]>k2[0];
}

template <typename Tip1, typename Tip2,typename Funkcija_kriterija=int, typename Funk_tip=int>
auto UvrnutaRazlika(Tip1 prvi_pocetak, Tip1 prvi_izakraja, Tip2 drugi_pocetak, Tip2 drugi_izakraja, Funkcija_kriterija (*f)(Funk_tip)=nullptr) -> vector<vector<decltype(*prvi_pocetak+0)>>{
    vector<vector<decltype(*prvi_pocetak+0)>> Matrica_Razlike;
    int k(0); 
        for (auto i=prvi_pocetak; i<prvi_izakraja; i++){
            bool nema(true); 
            for (auto j=drugi_pocetak; j<drugi_izakraja; j++){
                
                if ((f and f(*i)==f(*j)) or (!f and *i==*j)) 
                    nema=false;
                
            }   if (nema==true){
                if (f){
                    Matrica_Razlike.resize(k+1);
                    Matrica_Razlike[k].push_back(*i);
                    Matrica_Razlike[k].push_back(f(*i));
                    k++;}
                    else {
                        Matrica_Razlike.resize(k+1);
                    Matrica_Razlike[k].push_back(*i);
                    Matrica_Razlike[k].push_back(0);
                    k++;
                    }}
                
                }
        for (auto j=drugi_pocetak; j<drugi_izakraja; j++){
            bool nema(true); 
            for (auto i=prvi_pocetak; i<prvi_izakraja; i++){
                
                if ((f and f(*i)==f(*j)) or (!f and *i==*j)) 
                    nema=false;
                
            }   if (nema==true){
                if (f){
                    Matrica_Razlike.resize(k+1);
                    Matrica_Razlike[k].push_back(*j);
                    Matrica_Razlike[k].push_back(f(*j));
                    k++; }
                    else {    Matrica_Razlike.resize(k+1);
                              Matrica_Razlike[k].push_back(*j);
                              Matrica_Razlike[k].push_back(0);
                    k++;
                        
                    }            
                }
        }
        

     std::sort(Matrica_Razlike.begin(), Matrica_Razlike.end(), Sortiranje_Opadajuce<vector<decltype(*prvi_pocetak+0)>>);
    return Matrica_Razlike;
}



int main ()
{
    cout << "Unesite broj elemenata prvog kontejnera: ";
    int n;
    cin >> n;
    cout << "Unesite elemente prvog kontejnera: ";
    deque<long long int> yugi;
    deque<long long int> yugi_pomocni;
    for (int i(0); i<n; i++){
        long long int x;
        cin >> x;
        if (i==0) yugi.push_back(x);
        
        bool Ima_Ga(false);
        for (int j(0); j<yugi.size(); j++){
            if (i==0) break;
            if (x==yugi[j]) Ima_Ga=true;
              
        }
        if (i==0) continue;
        if (Ima_Ga==false) yugi.push_back(x);
        else i--;
    }
    cout << "Unesite broj elemenata drugog kontejnera: ";
    int m;
    cin >> m;
    cout << "Unesite elemente drugog kontejnera: ";
    deque<long long int> kaiba;
    deque<long long int> kaiba_pomocni;
   for (int i(0); i<m; i++){
        long long int x;
        cin >> x;
        if (i==0) kaiba.push_back(x);
        
        bool Ima_Ga(false);
        for (int j(0); j<kaiba.size(); j++){
            if (i==0) break;
            if (x==kaiba[j]) Ima_Ga=true;
              
        }
        if (i==0) continue;
        if (Ima_Ga==false) kaiba.push_back(x);
        else i--;
    }
    vector<vector<long long int>> Matrica_Presjeka;
    vector<vector<long long int>> Matrica_Razlike;
    Matrica_Presjeka=UvrnutiPresjek(yugi.begin(), yugi.end(), kaiba.begin(), kaiba.end(), SumaCifara);
    Matrica_Razlike=UvrnutaRazlika(yugi.begin(), yugi.end(), kaiba.begin(), kaiba.end(), BrojProstihFaktora);
    cout <<"Uvrnuti presjek kontejnera: " << std::endl;
    IspisiMatricu(Matrica_Presjeka);
    cout <<"Uvrnuta razlika kontejnera: " << std::endl;
    IspisiMatricu(Matrica_Razlike);
    cout <<"Dovidjenja!";
	return 0;
}