#include <iostream>
#include <vector>
#include <limits>
#include <string>
#include <stdexcept>
#include <tuple>
#include <set>
#include <algorithm>
#include <map>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

typedef std::map<std::string,std::vector<std::string>> Knjiga;
typedef std::map<std::string, std::set<std::tuple<std::string, int,int>>> Mapa;
typedef std::map<std::string, std::set<std::tuple<std::string, int,int>>>::iterator MapaIt;

bool SlovoBroj(char c) {

    return ((c>=48 && c<=57) || (c>='A' && c<='Z') || (c>='a' && c<='z'));
}
Mapa KreirajIndeksPojmovaa(Knjiga k) {
    Mapa m;
    Knjiga::iterator It {k.begin()};

    while(It!=k.end()) {
        string poglavlje = It->first;
        for(int i=0; i<It->second.size(); i++) {
            std::string::iterator sIt {It->second.at(i).begin()};
            while(sIt!=It->second.at(i).end()) {
                if(SlovoBroj(*sIt)) {
                    std::string::iterator temp {sIt};
                    string rijec {};
                    while(SlovoBroj(*sIt) && sIt!=It->second.at(i).end()) {
                        rijec+=*sIt;
                        sIt++;
                    }
                    string::iterator s{rijec.begin()};
                    while(s!=rijec.end()){*s=char(std::tolower(*s)); s++;}
                    m[rijec].insert({std::make_tuple(poglavlje,i+1,temp-It->second.at(i).begin())});
                    sIt--;
                }
                sIt++;
            }
        }
        It++;
    }
    return m;
}
std::set<std::tuple<std::string, int,int>> PretraziIndeksPojmova(string s, Mapa m){
auto it(m.find(s));
if(it == m.end()) throw std::logic_error("Pojam nije nadjen");
return it->second;
}

void IspisiIndeksPojmova(Mapa m) {
    for(auto it=m.begin(); it!=m.end(); it++) {
        cout << it->first << ": ";
                int i=it->second.size();
             for(auto it2=it->second.begin(); it2!=it->second.end(); it2++){
                 cout << std::get<0>(*it2) << "/" << std::get<1>(*it2) << "/" << std::get<2>(*it2);
                 if(i-->1) cout << ", ";
                 }cout << endl;
    }
}
void IspisiSkup(std::set<std::tuple<std::string, int,int>> s){
     for(auto it=s.begin(); it!=s.end(); it++)
    cout << std::get<0>(*it) << "/" << std::get<1>(*it) << "/" << std::get<2>(*it) << " ";
}

int main (){
    Knjiga k;

    for(;;) {
        string poglavlje;
        cout << "Unesite naziv poglavlja: ";
        if(cin.peek()=='.') break;
        cin >> poglavlje;
        vector<string> temp;
        int i=1;
        cin.ignore(10000,'\n');
        for(;;) {
            string s;
            cout << "Unesite sadrzaj stranice " << i << ": ";
            if(cin.peek()=='.') {cin.get();break;}
            getline(cin,s);
            temp.push_back(s);
            i++;
        }
        k.insert({poglavlje,temp});
        cin.ignore(10000,'\n');
        
    }
    Mapa m{KreirajIndeksPojmovaa(k)};
    cout << "\nKreirani indeks pojmova: " << endl;
    IspisiIndeksPojmova(m);
    cin.ignore(1000,'\n');
    for(;;){
        string s;
        cout << "Unesite rijec: ";
        if(cin.peek()=='.') break;
        getline(cin,s);
        try{
            IspisiSkup(PretraziIndeksPojmova(s,m));}
            catch(std::exception &ex){
                cout << "Unesena rijec nije nadjena!";
            }
            cout << endl;
    }
    return 0;
}
