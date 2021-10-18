/B2017/2018: Zadaća 3, Zadatak 2
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <map>
using namespace std;

typedef map<string, vector<string>> Knjiga;
typedef map<string, tuple<string, int, int>> Mapa;

Mapa KreirajIndeksPojmova(Knjiga k){
    Mapa m;
    for (auto it=k.begin(); it!=k.end(); it++){
        bool razmak(true);
        for(auto i : it->first) 
    }
}

int main ()
{
    string poglavlje;
    cout<<"Unesite naziv poglavlja: ";
    getline(cin, poglavlje);
    cout<<"Unesite sadrzaj stranice 1: ";
    string str1;
    getline(cin, str1);
    cout<<"Unesite sadrzaj stranice 2: ";
    string str2;
    getline(cin, str2);
    cout<<"Unesite naziv poglavlja: ";
    
    cout<<"Kreirani indeks pojmova: "
	return 0;
}
