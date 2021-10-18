/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <set>
#include <list>
#include <algorithm>

using namespace std;

int lettersCount(string s){
    int suma(0);
    for(char c : s)
        if((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'))
            suma++;        
    return suma;
}

vector<set<string>> Razvrstavanje(vector<string> v, int n){
    if(n < 1 || n > v.size())
        throw logic_error("Razvrstavanje nemoguce");
    vector<set<string>> rez(1);
    int modul = (int)v.size() % n;
    int brojTima(0);
    int velicinaTima;
    int brojacClanova(0);
    bool naPocetku(true);
    list<string> raja;
    raja.assign(v.begin(), v.end());
    auto it = raja.begin();
    int velImena(0);
    int korak(0);
    while(!raja.empty()){
        if(it == raja.end()) it = raja.begin();
        brojTima < modul ? velicinaTima = (int)v.size() / n + 1 : velicinaTima = (int)v.size() / n;
        if(brojacClanova == velicinaTima){
            brojacClanova = 0;
            brojTima++;
            rez.push_back(set<string>());
        }
        if(naPocetku || korak == velImena){
            rez.at(brojTima).insert(*it);
            brojacClanova++;
            velImena = lettersCount(*it);
            it = raja.erase(it);
            naPocetku = false;
            korak = 0;
        }
        else it++;
        korak++;
    }
    return rez;
}

int main ()
{
    try{
	    int brojDjece, brojTimova;
	    vector<string> djeca;
	    cout << "Unesite broj djece: ";
	    cin >> brojDjece;
	    cout << "Unesite imena djece:" << endl;
	    cin.ignore(1000, '\n');
	    for(int i(0); i < brojDjece; i++){
    	    string s;
	        getline(cin, s);
	        djeca.push_back(s);
	    }
	    cout << "Unesite broj timova: ";
	    cin >> brojTimova;
	    vector<set<string>> v = Razvrstavanje(djeca, brojTimova);
        for(int i(0); i < v.size(); i++){
            cout << "Tim " << i + 1 << ": ";
            auto kraj(v[i].end()); kraj--;
            for(auto it(v[i].begin()); it != kraj; it++)
                cout << *it << ", ";
            cout << *kraj << endl;
        }
    }catch(exception &e){
        cout<<"Izuzetak: "<<e.what();
    }
	return 0;
}