#include <iostream>
#include <set>
#include <map>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::set;

typedef map<string,set<int>> IndeksPojmova;

bool JesteSlovo(char karakter){
     if(karakter<'A' or (karakter>'Z' and karakter<'a') or karakter>'z')
        return false;
    return true;
}

bool JesteBroj(char karakter) {
    if(karakter>='0' and karakter <='9')
        return true;
    return false;
}

int PomjeriDoNeslova(string s, int indeks){ //"Slova" su samo slova alfabeta i brojevi
    for(int i=indeks; i<s.size(); i++){
        if(!(JesteBroj(s.at(i)) or JesteSlovo(s.at(i)))) return i;
    }
    return int(s.size()); //Ako nema neslova do kraja
}

void PretvoriUMala (string &s){
    for(int i=0; i<s.length(); i++){
        if(s.at(i)>='A' and s.at(i)<='Z') s.at(i)+=('a'-'A');
    }
}

bool UporediInsensitive(string s1, string s2){
    PretvoriUMala(s1); PretvoriUMala(s2);
    return s1==s2;
}

IndeksPojmova KreirajIndeksPojmova (string s){
    IndeksPojmova mapa;
    bool razmak(true);
    PretvoriUMala(s);
    for(int i=0; i<s.size(); i++){
        if(!(JesteBroj(s.at(i)) or JesteSlovo(s.at(i)))) razmak=true;
        else if(razmak){
            razmak=false;
            int poc(i); 
            int kraj(PomjeriDoNeslova(s,i));
            string rijec=s.substr(poc,kraj-poc); //Izvucimo rijec
            bool ima_u_mapi(false); 
            
            for(auto it=mapa.begin(); it!=mapa.end(); it++){ //Provjera postojanja rijeci u mapi
                if(it->first==rijec){
                    ima_u_mapi=true;
                    it->second.insert(poc);
                    break;
                }
            }
            if(!ima_u_mapi)   //Dodaj novi ako ga nema
                mapa[rijec]=set<int>{poc};
        }
    }
    return mapa;
}

set<int> PretraziIndeksPojmova(string rijec, IndeksPojmova mapa){
    set<int> rezultat;
    for(auto it=mapa.begin(); it!=mapa.end(); it++){
        if(UporediInsensitive(rijec,it->first)) {
            rezultat=it->second;
            break;
        }
    }
    if(!rezultat.size()) throw std::logic_error("Pojam nije nadjen");
    return rezultat;
}

void IspisiIndeksPojmova(IndeksPojmova mapa){
    for(auto it=mapa.begin(); it!=mapa.end(); it++){
        cout<<it->first<<": ";
        for(auto broj:it->second){
            if(broj==*--(it->second.end())) cout<<broj;
            else cout<<broj<<",";
        }
        cout<<endl;
    }
}


int main ()
{
    string tekst;
    cout<<"Unesite tekst: ";
    getline(cin,tekst);
    auto mapa_indeksa(KreirajIndeksPojmova(tekst));
    IspisiIndeksPojmova(mapa_indeksa);
    do{
        try{
            cout<<"Unesite rijec: ";
            string rijec;
            getline(cin,rijec);
            if(rijec==".") break;
            PretvoriUMala(rijec);
            set<int> skup(PretraziIndeksPojmova(rijec,mapa_indeksa));
            for(auto broj: skup) cout<<broj<<" ";
            cout<<endl;
            
        }
        catch(std::logic_error){
            cout<<"Unesena rijec nije nadjena!"<<endl;
        }
    }
    while(true);
	return 0;
}