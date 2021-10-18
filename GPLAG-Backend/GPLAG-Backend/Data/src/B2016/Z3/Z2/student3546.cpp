#include <iostream>
#include <utility>
#include <set>
#include <string>
#include <map>
#include <stdexcept>

using std::cin;
using std::cout;

std::map<std::string,std::set<int>> KreirajIndeksPojmova(std::string s){
    std::map<std::string,std::set<int>> indeksi;
    bool novarijec(true);
    int brojac(0);
    for(int i=0;i<s.length();i++)
    if(s[i]>='A' && s[i]<='Z') s[i]+=32;
    for(int i=0;i<s.length();i++){
        if((s[i]<'a' || s[i]>'z') && (s[i]<'0' || s[i]>'9'))
        novarijec=false;
        else{
            if(novarijec==false){
            novarijec=true;
            brojac=0;
            }
            while((s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')){
                brojac++;
                i++;
            }
            std::string pojam=s.substr(i-brojac,brojac);
            if(indeksi.count(pojam))
            indeksi[pojam].insert(i-brojac);
            else{
                indeksi.insert(std::make_pair(pojam,std::set<int>{i-brojac}));
            }
            i--;
        }
    }
    return indeksi;
}

std::set<int> PretraziIndeksPojmova(std::string pojam,std::map<std::string,std::set<int>> indeksi){
    if(indeksi.count(pojam))
    return indeksi[pojam];
    else
    throw std::logic_error("Pojam nije nadjen");
}

void IspisiIndeksPojmova(std::map<std::string,std::set<int>> indeksi){
    for(auto it=indeksi.begin();it!=indeksi.end();it++){
        cout<<it->first<<": ";
        auto kraj(it->second.end());
        kraj--;
        for(auto it2=it->second.begin();it2!=it->second.end();it2++){
            if(it2==kraj)
            cout<<*it2;
            else
            cout<<*it2<<",";
        }
        cout<<"\n";
    }
}

int main ()
{
    std::string s;
    cout<<"Unesite tekst: ";
    std::getline(cin,s);
    std::map<std::string,std::set<int>> mapa;
    mapa=KreirajIndeksPojmova(s);
    IspisiIndeksPojmova(mapa);
    for(;;){
        cout<<"Unesite rijec: ";
        std::string rijec;
        std::getline(cin,rijec);
        if(rijec==".") break;
        else{
            std::set<int> skup;
            try{
            skup=PretraziIndeksPojmova(rijec,mapa);
            for(auto x:skup)
            cout<<x<<" ";
            cout<<"\n";
            }
            catch(std::logic_error){
                cout<<"Unesena rijec nije nadjena!"<<std::endl;
            }
        }
    }
	return 0;
}