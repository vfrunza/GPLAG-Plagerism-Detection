/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <stdexcept>

using std::cin;
using std::cout;
using std::endl;

bool SlovoCifra(char x){
    bool d(false);
    if((x>='a' && x<='z') || (x>='0' && x<='9')) d=true;
    return d;
}
 
std::map<std::string, std::set<int>> KreirajIndeksPojmova(std::string s){
    std::string novi;
    std::map<std::string, std::set<int>> mapa;
    std::set<int> skup;
    for(int i=0;i<s.size();i++){
        if(s[i]>='A' && s[i]<='Z') s[i]+=('a'-'A');
    }
    for(int i=0;i<s.size();i++){
        int k(i);
        while(i<s.size() && SlovoCifra(s[i])){
            novi.push_back(s[i]);
            i++;
        }
        skup.insert(k);
        if(novi.size()!=0){
        for(int j=i;j<s.size();j++){
            if(j!=0 && j<s.size() && s.substr(j,novi.size())==novi && !SlovoCifra(s[j-1]) && !SlovoCifra(s[j+novi.size()])) skup.insert(j);
        }
        mapa.insert(std::make_pair(novi, skup));
        }
        novi.resize(0);
        if(skup.size()!=0){
            skup.clear();
        }
    }
    return mapa;
}

std::set<int> PretraziIndeksPojmova(std::string s, std::map<std::string, std::set<int>> mapa){
    for(int i=0;i<s.size();i++){
        if(s[i]>='A' && s[i]<='Z') s[i]+=('a'-'A');
    }
    auto it(mapa.find(s));
    if(it==mapa.end()) throw std::logic_error("Pojam nije nadjen");
    else return it->second;
}

void IspisiIndeksPojmova(std::map<std::string, std::set<int>> mapa){
    for(auto it=mapa.begin(); it!=mapa.end(); it++) {
        cout<<it->first<<": ";
        auto it2((it->second).end());
        it2--;
    for(auto it1=(it->second).begin(); it1!=(it->second).end();it1++){
        if(it1!=it2) cout<<*it1<<",";
        else cout<<*it1;
    }
    cout<<endl;
    }
}

void IspisiSkup(std::set<int> skup){
    for(auto x: skup) cout<<x<<" ";
}
int main ()
{
    std::string s;
    cout<<"Unesite tekst: ";
    std::getline(cin, s);
    auto mapa(KreirajIndeksPojmova(s));
    IspisiIndeksPojmova(mapa);
    std::string znak;
    do{
        cout<<"Unesite rijec: ";
        std::getline(cin, znak);
        if(znak==".") break;
        try{
            auto skup(PretraziIndeksPojmova(znak,mapa));
            IspisiSkup(skup);
        }
        catch(std::logic_error){
            cout<<"Unesena rijec nije nadjena!";
        }
        cout<<endl;
    }while(znak!=".");
    
	return 0;
}