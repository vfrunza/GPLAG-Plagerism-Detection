#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
#include <cmath>
#include <iterator>
#include <iomanip>

using namespace std;

template<typename TipPrvi, typename TipDrugi>
auto UvrnutiPresjek(TipPrvi pocetak1, TipPrvi kraj1, TipDrugi pocetak2, TipDrugi kraj2) -> vector<vector<typename remove_reference<decltype(*pocetak1)>::type>>   
{
    vector<vector<typename remove_reference<decltype(*pocetak1)>::type>> rezultujuca (1);
    int red_matrice(0);
    
    for(auto i = pocetak1; i!=kraj1; i++)
    {
        for(auto j = pocetak2; j!=kraj2; j++)
        {
            if(*i==*j)
            {
                rezultujuca.at(red_matrice).push_back(*i);
                rezultujuca.at(red_matrice).push_back(0);
                rezultujuca.at(red_matrice).push_back(0);
                rezultujuca.resize(rezultujuca.size()+1);
                red_matrice++;
            }
        }
    }
    
    rezultujuca.resize(rezultujuca.size()-1);
    sort(rezultujuca.begin(), rezultujuca.end(), [](const vector<typename remove_reference<decltype(*pocetak1)>::type>&a, const vector<typename remove_reference<decltype(*pocetak1)>::type>&b)->bool {return a.at(0)<b.at(0);});
    
    return rezultujuca;
}

template<typename TipPrvi, typename TipDrugi, typename Proizvoljni1, typename Proizvoljni2>
auto UvrnutiPresjek (TipPrvi pocetak1, TipPrvi kraj1, TipDrugi pocetak2, TipDrugi kraj2, Proizvoljni1 funkcija (Proizvoljni2)) -> vector<vector<typename remove_reference<decltype(*pocetak1)>::type>>   
{   
    vector<vector<typename remove_reference<decltype(*pocetak1)>::type>> rezultujuca (1); // da mogu nesto adresirat 
    int red_matrice(0);
    for(auto i = pocetak1; i!=kraj1; i++)
    {
        for(auto j = pocetak2; j!=kraj2; j++)
        {
            if(funkcija(*i)==funkcija(*j))
            {
                rezultujuca.at(red_matrice).push_back(*i);
                rezultujuca.at(red_matrice).push_back(*j);
                rezultujuca.at(red_matrice).push_back(funkcija(*i));
                rezultujuca.resize(rezultujuca.size()+1); // rasiri za novi red da mozes adresirati
                red_matrice++;
            }
        }
    }
    
    rezultujuca.resize(rezultujuca.size()-1); // uvijek ce biti onaj prazni red viska
    
    sort(rezultujuca.begin(), rezultujuca.end(), [](const vector<typename remove_reference<decltype(*pocetak1)>::type>&a, const vector<typename remove_reference<decltype(*pocetak1)>::type>&b)->bool {return a.at(1)<b.at(1);});
    stable_sort(rezultujuca.begin(), rezultujuca.end(), [](const vector<typename remove_reference<decltype(*pocetak1)>::type>&a, const vector<typename remove_reference<decltype(*pocetak1)>::type>&b)->bool {return a.at(0)<b.at(0);});
    stable_sort(rezultujuca.begin(), rezultujuca.end(), [](const vector<typename remove_reference<decltype(*pocetak1)>::type>&a, const vector<typename remove_reference<decltype(*pocetak1)>::type>&b)->bool {return a.at(2)<b.at(2);});
    
    return rezultujuca;
}

template<typename TipPrvi, typename TipDrugi>
auto UvrnutaRazlika (TipPrvi pocetak1, TipPrvi kraj1, TipDrugi pocetak2, TipDrugi kraj2) -> vector<vector<typename remove_reference<decltype(*pocetak1)>::type>>
{
    vector<vector<typename remove_reference<decltype(*pocetak1)>::type>> matrica (1);
    int red_matrice(0);
    for(auto i = pocetak1; i!=kraj1; i++)
    {
        if(find(pocetak2,kraj2,*i)==kraj2)
        {
            matrica.at(red_matrice).push_back(*i);
            matrica.at(red_matrice).push_back(0);
            matrica.resize(matrica.size()+1);
            red_matrice++;
        }
    }
    
    for(auto i = pocetak2; i!=kraj2; i++)
    {
        if(find(pocetak1, kraj1, *i)==kraj1)
        {
            matrica.at(red_matrice).push_back(*i);
            matrica.at(red_matrice).push_back(0);
            matrica.resize(matrica.size()+1);
            red_matrice++;
        }
    }
    
    matrica.resize(matrica.size()-1);
    
    sort(matrica.begin(), matrica.end(), [](const vector<typename remove_reference<decltype(*pocetak1)>::type>&a, const vector<typename remove_reference<decltype(*pocetak1)>::type>&b)->bool {return a.at(0)>b.at(0);});
    
    return matrica;
}

template<typename TipPrvi, typename TipDrugi, typename Proizvoljni1, typename Proizvoljni2>
auto UvrnutaRazlika (TipPrvi pocetak1, TipPrvi kraj1, TipDrugi pocetak2, TipDrugi kraj2, Proizvoljni1 funkcija (Proizvoljni2)) -> vector<vector<typename remove_reference<decltype(*pocetak1)>::type>>
{
    vector<vector<typename remove_reference<decltype(*pocetak1)>::type>> matrica (1);
    vector<typename remove_reference<decltype(*pocetak1)>::type> rezultati1(1), rezultati2(1);
    int brojac(0), red_matrice(0);
    bool nema_istog(true);
  
    for(auto i = pocetak1; i!=kraj1; i++)
    {
        nema_istog=true;
        for(auto j = pocetak2; j!=kraj2; j++)
        {
            if(funkcija(*i)==funkcija(*j))
            {
                nema_istog=false;
                break;
            }
        }
        
        if(nema_istog)
        {
            matrica.at(red_matrice).push_back(*i);
            matrica.at(red_matrice).push_back(funkcija(*i));
            matrica.resize(matrica.size()+1);
            red_matrice++;
        }
    }
    
   
    for(auto i = pocetak2; i!=kraj2; i++)
    {
        nema_istog=true;
        for(auto j = pocetak1; j!=kraj1; j++)
        {
            if(funkcija(*i)==funkcija(*j))
            {
                nema_istog=false;
                break;
            }
        }
        
        if(nema_istog)
        {
            matrica.at(red_matrice).push_back(*i);
            matrica.at(red_matrice).push_back(funkcija(*i));
            matrica.resize(matrica.size()+1);
            red_matrice++;
        }
    }
    
    matrica.resize(matrica.size()-1);
    sort(matrica.begin(), matrica.end(), [](const vector<typename remove_reference<decltype(*pocetak1)>::type>&a, const vector<typename remove_reference<decltype(*pocetak1)>::type>&b)->bool {return a.at(0)>b.at(0);});
    return matrica;
}

bool ImaLiGaVec(deque<int> dek, int broj) // ovo je moglo i preko find
{
    for(int i = 0 ; i<dek.size(); i++) {
        if(dek.at(i)==broj) return true;
    }
    return false;
}

int SumaCifara (long long int broj)
{
    int suma(0), cifra(0);
    while(broj!=0)
    {
        cifra=broj%10;
        suma+=cifra;
        broj/=10;
    }
    
    return suma;
}

int SumaDjelilaca (long long int broj)
{
    int suma_djelilaca(1);
    if (broj==0) return 0;
    
    broj=abs(broj);
    if(broj!=1) suma_djelilaca+=broj;
  
    
    for(int i=2; i<broj; i++)
        if(broj%i==0) suma_djelilaca+=i;
        
    return suma_djelilaca;
}

bool DaLiJeProst(int n)
{
    if(n==1) return false;
    if(n<=0) return false;
    if(n%2 == 0 && n != 2 ) return false; //ako je paran sigurno nije prost (osim ako je 2)
    bool prost=true;

    double korijen=sqrt(n); // da ne racuna korijen milion puta unutar petlje

    for(unsigned int i=2; i<=korijen ; i++) {
        if(n%i==0) {
            return false;
        }
    }

    return prost;
}

int BrojSavrsenihDjelilaca (long long int broj)
{
    int broj_savrsenih(0);
    for(int i = 2; i<=broj; i++) // ovdje ne moze korijen jer savrseni budu veliki brojevi
    {
        if(broj%i==0 and i==SumaDjelilaca(i)-i) broj_savrsenih++;
    }
    
    return broj_savrsenih;
}

int BrojProstihFaktora(long long int broj)
{
    int broj_prostih_faktora(0);
    double korijen=sqrt(broj);
    
    for(int i = 2; i<=korijen; i++)
    {
        while(DaLiJeProst(i) and broj%i==0)
        {
            broj_prostih_faktora++;
            broj/=i;
        }
    }
    
    if(broj>1) broj_prostih_faktora++;
    
    return broj_prostih_faktora;
}

template <typename Tip>
void IspisMatrice (Tip matrica)
{
    for(int i=0; i<matrica.size(); i++) {
        for(int j=0; j<(matrica.at(i).size()); j++) {
            cout << setw(6) <<matrica[i][j]<< " " ;
        }
       if(i!=matrica.size()-1) cout << endl;
    }
 }

int main () 
{
    int broj_elemenata, broj;
    cout << "Unesite broj elemenata prvog kontejnera: ";
    cin >> broj_elemenata;
    deque<int> dek1 (1);
    cout << "Unesite elemente prvog kontejnera: ";
    for(int i=0; i<=broj_elemenata; i++)
    {
        cin >> broj;

        if(!ImaLiGaVec(dek1, broj) and broj!=0) dek1.push_back(broj); // nulu ce uvijek naci kao prvi element
        else if (broj==0) dek1.push_back(0);
    }
    
   dek1.pop_front(); // mice onu nulu sto nam je sluzila da ne bude prazan dek u pocetku
    
   cout << "Unesite broj elemenata drugog kontejnera: ";
   cin >> broj_elemenata;
   deque<int> dek2 (1);
   cout << "Unesite elemente drugog kontejnera: ";
   for(int i=0; i<=broj_elemenata; i++)
   {
       cin >> broj;
       if(!ImaLiGaVec(dek2, broj) and broj!=0) dek2.push_back(broj);
       else if (broj==0) dek2.push_back(0);
   }
   
   dek2.pop_front(); 
   
   cout << "Uvrnuti presjek kontejnera:" << endl;
   IspisMatrice(UvrnutiPresjek(dek1.begin(), dek1.end(), dek2.begin(), dek2.end(), SumaCifara));
   cout << endl <<"Uvrnuta razlika kontejnera:" << endl;
   IspisMatrice(UvrnutaRazlika(dek1.begin(), dek1.end(), dek2.begin(), dek2.end(), BrojProstihFaktora)); 
   cout << endl << "Dovidjenja!";
	return 0;
}