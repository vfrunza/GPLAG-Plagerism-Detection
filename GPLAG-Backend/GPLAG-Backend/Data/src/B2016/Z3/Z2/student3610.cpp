/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include<map>
#include <string>
#include<set>
#include<stdexcept>
using std:: cout;
using std:: cin;
using std:: string;

std::map<string, std:: set<int>> KreirajIndeksPojmova( string s){
    std:: map<string, std:: set<int>> rijeci;
    
    for(int i=0; i<s.length(); i++){
         int br(0);
         string s2;
        while (s[i]==' ') i++;
        while((s[i]>='a'&& s[i]<='z') || (s[i]>='A'&& s[i]<='Z') || (s[i]>='0'&& s[i]<='9')){ 
            char c(s[i]);
            if(s[i]>='A'&& s[i]<='Z') c+='a'-'A';
            s2=s2+c;
            i++; br++;}
        auto it(rijeci.find(s2));
        if(it== rijeci.end()) rijeci.insert(std:: make_pair(s2, std:: set<int>{i-br}));
        else (it->second).insert(i-br);
    }
    return rijeci;
}
std:: set<int> PretraziIndeksPojmova(string s, std:: map<string, std::set<int>> rijeci){
    string s2;
    for(int i=0; i<s.length(); i++){
        char c(s[i]);
        if(s[i]>='A'&& s[i]<='Z') c+='a'-'A';
        s2=s2+c;
    }
    auto it(rijeci.find(s2));
    if(it== rijeci.end()) throw std::logic_error ("Pojam nije nadjen");
    return(it->second);
    
}
void IspisiIndeksPojmova(std:: map<string, std::set<int>> rijeci){
    for(const auto &r: rijeci){
        cout << r.first<< ": ";
        int br(0);
        for(const auto & i:r.second){
            br++;
            cout << i;
            if(br==r.second.size()) break;
        cout << ",";
        }
        cout << std:: endl;
    }
}

int main () 
{
    try{
    cout << "Unesite tekst: ";
    string s;
    std:: getline(cin, s);
    auto mapa (KreirajIndeksPojmova(s));
    IspisiIndeksPojmova(mapa);
    for(;;){
        try{
        cout << "Unesite rijec: ";
        string s2;
        std:: getline(cin,s2);
        if(s2==".") break;
        std:: set<int> skup(PretraziIndeksPojmova(s2,mapa));
        for(const auto & i: skup) cout << i<< " ";
        cout<< std:: endl;
        }
        catch(std::logic_error){
            cout << "Unesena rijec nije nadjena!" << std::endl;
        }
        
    }
   

    }
    catch(std:: logic_error e){
        cout <<  e.what();
    }
	return 0;
}