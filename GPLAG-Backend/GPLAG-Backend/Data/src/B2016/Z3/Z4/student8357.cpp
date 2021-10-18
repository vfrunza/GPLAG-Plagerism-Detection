#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <set>
#include <algorithm>
#include <list>
using std::list;
using std::set;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int IzbaciGluposti(string s){
    int brojac(0);
    for(int i=0;i<s.length();i++){
        if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')){
            brojac++;
        }
    }
    return brojac;
}
void OslobodiSkup(set<string> skup){
    auto it(skup.begin());
    while (it!=skup.end()) {
             skup.erase(*it);
             it++;
         }
}

vector<set<string>> Razvrstavanje(vector<string> Djeca,int broj_timova){
    if(broj_timova<1 || broj_timova>Djeca.size()) throw std::logic_error("Razvrstavanje nemoguce");
    list<string> Lista_djece;
    for(int i=0;i<Djeca.size();i++){
        Lista_djece.push_back(Djeca[i]);
    }
    vector<set<string>> Rezultat;
    int timovi_za_jedan_vise(Djeca.size()%broj_timova),broj_clanova(Djeca.size()/broj_timova);
    auto it(Lista_djece.begin());
    int x(0);
    while(std::distance(it,Lista_djece.end())!=0){
         x++;
         set<string> skup;
         int br(broj_clanova);
         if(x<=timovi_za_jedan_vise && timovi_za_jedan_vise!=0) br++;
             int brojac1(0);
             while(brojac1<br){
             skup.insert(*it);
             int brojac(IzbaciGluposti(*it));
             it=Lista_djece.erase(it);
             it--;
             for(int i=0;i<brojac;i++){
                 it++;
                 if(it==Lista_djece.end()) it=Lista_djece.begin();
             }
             brojac1++;
             int b(std::distance(it,Lista_djece.end()));
             if(b==0) break;
             }
             Rezultat.push_back(skup);
         }
    return Rezultat;
}

int main ()
{
    cout<<"Unesite broj djece: ";
    int broj_djece;
    cin>>broj_djece;
    vector<string> Djeca;
    string jedno_dijete;
    cout<<"Unesite imena djece: "<<endl;
    cin.ignore(10000,'\n');
    for(int i=0;i<broj_djece;i++){
        getline(cin,jedno_dijete);
        Djeca.push_back(jedno_dijete);
    }
    cout<<"Unesite broj timova: ";
    int broj_timova;
    cin>>broj_timova;
    vector<set<string>> Rezultat;
    try{
    Rezultat=Razvrstavanje(Djeca,broj_timova);
    }catch(std::logic_error greska){
        cout<<"Izuzetak: "<<greska.what();
    }
    for(int i=0;i<Rezultat.size();i++){
        auto it(Rezultat[i].begin());
        cout<<"Tim "<<i+1<<":";
        while(it!=Rezultat[i].end()){
            cout<<" "<<*it;
            it++;
            if(it!=Rezultat[i].end()) cout<<",";
        }
        cout<<endl;
    }
	return 0;
}