#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <iomanip>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;

typedef std::vector<int> Vektor;
typedef std::vector<Vektor> Matrix;

//Funkcije potrebne za implementaciju autotestiranja

long long int SumaCifara(int broj){
    broj = abs(broj);
    long long int suma(0);
    while(broj>0){
        suma+=broj%10;
        broj/=10;
    }
    return suma;
}

long long int SumaDjelilaca(int broj){
    broj = abs(broj);
    long long int suma(0);
    for(int i=1; i<=broj; i++){
        if(broj%i==0) suma+=i;
    }
    return suma;
}

bool DaLiJeProst (long long int broj) {
    if(broj<=0 or broj==1)
        return false;
    int granica = sqrt(broj);
    for(int i=2; i<=granica; i++) { //Pocinjemo od 2 jer je svaki broj djeljiv sa 1
        if(broj%i==0)
            return false;
    }
    return true;
}

long long int BrojProstihFaktora(int broj){
    broj=abs(broj);
    long long int suma(0);
    for(int i=2; i<=broj; i++){
        if(!DaLiJeProst(i)) continue; //Ako i uopste nije prost, sigurno nije ni prosti faktor
        if(broj%i==0){
            broj/=i; //Ako jeste, podijelimo ga i gledajmo sada dalje 
            i--;
            suma++;
        }
    }
    return suma;
}

bool DaLiJeSavrsen(long long int x){
    long long int suma(SumaDjelilaca(x)); //Ako mu je suma djelilaca jednaka njemu samom, onda je prost
    return suma-x==x; //Posto funkcija sumadjelilaca uzima i sam broj kao djelioc, moramo to oduzeti u ovom ispitivanju
}

long long int BrojSavrsenihDjelilaca(int broj){
    broj = abs(broj);
    long long int suma(0);
    for(int i=2; i<=broj; i++){
        if(broj%i==0 and DaLiJeSavrsen(i)) suma++; //Ako je djelioc i ako je savrsen, povecaj sumu
    }
    return suma;
}


template<typename Kontejner>
bool sortiraj(Kontejner prvi, Kontejner drugi){ //Funkcija za sortiranje kontejnera u rastuci
    if(prvi.at(2)==drugi.at(2)){
        if(prvi.at(0)==drugi.at(0)){
            return prvi.at(1)<drugi.at(1);
        }
        return prvi.at(0)<drugi.at(0);
    }
    return prvi.at(2)<drugi.at(2);
}

template <typename It1, typename It2, typename Povratna=int,typename Parametar=int>
auto UvrnutiPresjek(It1 p_pocetak, It1 p_kraj, It2 d_pocetak, It2 d_kraj,Povratna (*f)(Parametar)=nullptr)->std::vector<std::vector<decltype(*p_pocetak+*p_pocetak)>>{
    std::vector<std::vector<decltype(*p_pocetak+*p_pocetak)>> Rezultat;
    int vel(0);
    for(auto i=p_pocetak; i!=p_kraj; i++){
        for(auto j=d_pocetak; j!=d_kraj; j++){
            if((f and f(*i)==f(*j)) or (!f and *i==*j) ){
                Rezultat.resize(vel+1);
                Rezultat.at(vel).push_back(*i);
                if(f){Rezultat.at(vel).push_back(*j); Rezultat.at(vel).push_back(f(*i));}
                else {Rezultat.at(vel).push_back(0); Rezultat.at(vel).push_back(0);}
                vel++;
            }
        }
    }
    sort(Rezultat.begin(),Rezultat.end(),sortiraj<std::vector<decltype(*p_pocetak+*p_pocetak)>>);
    return Rezultat;
}

template<typename Kontejner>
bool sortiraj_opadajuce(Kontejner prvi, Kontejner drugi){ //Sort u opadajuci poredak
    if(prvi.at(0)==drugi.at(0)) return prvi.at(1)>drugi.at(1);
    return prvi.at(0)>drugi.at(0);
}

template <typename It1, typename It2, typename Povratna=int,typename Parametar=int>
auto UvrnutaRazlika(It1 p_pocetak, It1 p_kraj, It2 d_pocetak, It2 d_kraj,Povratna (*f)(Parametar)=nullptr)->std::vector<std::vector<decltype(*p_pocetak+*p_pocetak)>>{
    std::vector<std::vector<decltype(*p_pocetak+*p_pocetak)>> Rezultat;
    int vel(0);
    for(auto i=p_pocetak; i!=p_kraj; i++){
        bool nema_par(true);
        for(auto j=d_pocetak; j!=d_kraj; j++){
            if( (f and f(*i)==f(*j)) or (!f and *i==*j)){nema_par=false; break;}
        }
        if(nema_par){
            Rezultat.resize(vel+1);
            Rezultat.at(vel).push_back(*i);
            if(f) Rezultat.at(vel).push_back(f(*i));
            else Rezultat.at(vel).push_back(0);
            vel++;
        }
    }
    for(auto i=d_pocetak; i!=d_kraj; i++){
        bool nema_par(true);
        for(auto j=p_pocetak; j!=p_kraj; j++){
            if((f and f(*i)==f(*j)) or (!f and *i==*j)){nema_par=false; break;}
        }
        if(nema_par){
            Rezultat.resize(vel+1);
            Rezultat.at(vel).push_back(*i);
            if(f) Rezultat.at(vel).push_back(f(*i));
            else Rezultat.at(vel).push_back(0);
            vel++;
        }
    }
    sort(Rezultat.begin(),Rezultat.end(),sortiraj_opadajuce<std::vector<decltype(*p_pocetak+*p_pocetak)>>);
    return Rezultat;
}



int main ()
{
    std::deque<int> prvi,drugi;
    cout<<"Unesite broj elemenata prvog kontejnera: ";
    int n;
    cin>>n;
    cout<<"Unesite elemente prvog kontejnera: ";
    while(n>0){
        int broj;
        cin>>broj;
        bool ima_vec(false);
        for(int i=0; i<prvi.size(); i++){
            if(broj==prvi.at(i)) ima_vec=true;
        }
        if(ima_vec) continue;
        prvi.push_back(broj);
        n--;
    }
    cout<<"Unesite broj elemenata drugog kontejnera: ";
    cin>>n;
    cout<<"Unesite elemente drugog kontejnera: ";
    while(n>0){
        int broj;
        cin>>broj;
        bool ima_vec(false);
        for(int i=0; i<drugi.size(); i++){
            if(broj==drugi.at(i)) ima_vec=true;
        }
        if(ima_vec) continue;
        drugi.push_back(broj);
        n--;
    }
    Matrix rez(UvrnutiPresjek(prvi.begin(),prvi.end(),drugi.begin(),drugi.end(),SumaCifara));
    cout<<"Uvrnuti presjek kontejnera:"<<endl;
    for(auto &red:rez){
        for(auto el:red) cout<<std::setw(6)<<el<<" ";
        cout<<endl;
    }
    cout<<"Uvrnuta razlika kontejnera:"<<endl;
    rez=UvrnutaRazlika(prvi.begin(),prvi.end(),drugi.begin(),drugi.end(),BrojProstihFaktora);
    for(auto &red:rez){
        for(auto el:red) cout<<std::setw(6)<<el<<" ";
        cout<<endl;
    }
    cout<<"Dovidjenja!";
	return 0;
}
