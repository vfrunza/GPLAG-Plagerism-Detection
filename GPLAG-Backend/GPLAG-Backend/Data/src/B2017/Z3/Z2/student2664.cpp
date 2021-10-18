/B2017/2018: Zadaća 3, Zadatak 2
#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <tuple>
#include <map>
#include <set>

using std::logic_error;
using std::make_tuple;
using std::make_pair;
using std::tolower; //??
using std::getline;
using std::string;
using std::vector;
using std::tuple;
using std::cout;
using std::endl;
using std::cin;
using std::map;
using std::set;
using std::get;
typedef map<string, vector<string>> Knjiga;
typedef map<string, set<tuple<string, int, int>>> Pojmovi;
typedef set<tuple<string, int, int>> Skup;

bool SlovoCifra(char c){
    if((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')) return true;
    return false;
}
void PretvoriUMala(string &s){
    for(char &c : s) c = tolower(c);
}
Pojmovi KreirajIndeksPojmova(const Knjiga &k){
    Pojmovi p;
    for(auto it=k.begin(); it != k.end(); it++){
        string poglavlje(it->first);
        for(int j=0; j < it->second.size(); j++){
            const string tekst((it->second)[j]);
            
            int neslovonecifra(1), l(0);
            while(l<tekst.size()){
                if(!SlovoCifra(tekst[l])) neslovonecifra=1;
                else if(neslovonecifra == 1){
                    neslovonecifra = 0;
                    int duzina(1);
                    l++;
                    while(SlovoCifra(tekst[l]) && l<tekst.size()){
                        l++;
                        duzina++;
                    }
                    string rijec(tekst.substr(l-duzina, duzina));
                    PretvoriUMala(rijec);
                    p[rijec].insert(make_tuple(poglavlje, j+1, l-duzina));
                    l--; 
                }
                l++;
            }
            
        }
    }
    return p;
}
Skup PretraziIndeksPojmova(string rijec, Pojmovi p){
    if(!p.count(rijec)) throw logic_error("Pojam nije nadjen");
    return p[rijec];
}
void IspisiTapl(const tuple<string, int, int> &tapl){
    cout << get<0> (tapl) << "/" << get<1> (tapl) << "/" << get<2> (tapl);
}
void IspisiIndeksPojmova(const Pojmovi &p){
    for(auto par : p){
        cout << par.first << ": ";
        auto skup(par.second);
        int i=0;
        for(auto it = skup.begin(); it != skup.end(); it++, i++){
            IspisiTapl(*it);
            if(i == skup.size() - 1) cout << " ";
            else cout << ", ";
  
        }
        cout << endl;
    }
}

int main (){
    Knjiga k;
    do{
        string poglavlje, sadrzaj;
        cout << "Unesite naziv poglavlja: ";
        getline(cin, poglavlje);
        if(poglavlje == ".") break;
        int i(0);
        vector<string> vec;
        do{
            cout << "Unesite sadrzaj stranice " << i+1 << ": ";
            getline(cin, sadrzaj);
            if(sadrzaj == ".") break;
            vec.push_back(sadrzaj);
            i++;
        }while(1);
        k.insert(make_pair(poglavlje, vec));
    }while(1);
    
    
    Pojmovi pojmovi(KreirajIndeksPojmova(k));
    cout << "\nKreirani indeks pojmova: " << endl;
    IspisiIndeksPojmova(pojmovi);
    
    do{
        string rijec;
        cout << "\nUnesite rijec: ";
        getline(cin, rijec);
        if(rijec == ".") break;
        try{
            Skup skup(PretraziIndeksPojmova(rijec, pojmovi));
            for(auto tapl : skup){
                IspisiTapl(tapl);
                cout << " ";
            }
        }
        catch(logic_error){
            cout << "Unesena rijec nije nadjena!";
        }
    }while(1);
    
    
	return 0;
}
