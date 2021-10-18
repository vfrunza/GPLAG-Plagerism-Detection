/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <iterator>
#include <utility>

std::map<std::string,std::set<int>> KreirajIndeksPojmova (std::string s){
    std::map<std::string,std::set<int>> mapa;
    for(int i=0;i<s.size();i++){
        if(s[i]>='A' && s[i]<='Z') s[i]=s[i]-'A'+'a';
    }
    std::vector<std::string> rijeci;
    for(int i=0;i<s.size();i++){
        if( ((i==0) || !((s[i-1]>='a' && s[i-1]<='z') || (s[i-1]>='0' && s[i-1]<='9'))) &&  ((s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9'))){
            int c=i;
            while( (s[i]>='a' && s[i]<='z') || ( (s[i]>='0' && s[i]<='9') && s[i]!=s[s.size()])) {
                i++;
            }
            rijeci.push_back(s.substr(c,i-c));
            i--;
        }
    }
    for(int i=0;i<rijeci.size()-1;i++){
        for(int j=i+1;j<rijeci.size();j++){
            if(rijeci[i]==rijeci[j]) rijeci.erase(rijeci.begin()+j);
        }
    }
    std::vector<std::set<int>> brojevi;
    for(int i=0;i<rijeci.size();i++){
        std::set<int> skup;
        for(int j=0;j<s.size();j++){
            int k=0,d=j;
            if((j==0 || !((s[j-1]>='a' && s[j-1]<='z') || (s[j-1]>='0' && s[j-1]<='9')) ) && s[j]==rijeci[i][k]){
                while(s[j]==rijeci[i][k] && j!=s.size()){
                    j++;
                    k++;
                }
                if( k==rijeci[i].size() && (j==s.size() || !((s[j]>='a' && s[j]<='z') || (s[j]>='0' && s[j]<='9')) ) ) {
                    skup.insert(d);
                 }
            }
        }
        brojevi.push_back(skup);
    }
    for(int i=0;i<rijeci.size();i++){
        mapa[rijeci[i]]=brojevi[i];
    }
    return mapa;
}

std::set<int> PretraziIndeksPojmova(std::string s, std::map<std::string,std::set<int>> mapa){
    if(!mapa.count(s)) throw std::logic_error("Pojam nije nadjen");
    return mapa[s];
}

void IspisiIndeksPojmova (std::map<std::string,std::set<int>> mapa){
    for(auto it=mapa.begin();it!=mapa.end();it++){
        std::cout << it->first << ": " ;
        auto skup=it->second;
        int c=distance(skup.begin(),skup.end());
        int i=0;
        for(auto x: skup){
            if(i==c-1) std::cout << x;
            else std::cout << x << ",";
            i++;
        }
        std::cout << std::endl;
    }
}

int main ()
{
    std::cout << "Unesite tekst: ";
    std::string s;
    std::getline(std::cin,s);
    auto mapa=KreirajIndeksPojmova(s);
    IspisiIndeksPojmova(mapa);
    for(;;){
        std::cout << "Unesite rijec: ";
        std::string rijec;
        std::getline(std::cin,rijec);
        if(rijec==".") break;
        try{
            auto skup=PretraziIndeksPojmova(rijec,mapa);
            for(auto it=skup.begin();it!=skup.end();it++){
                std::cout << *it << " ";
            }
            std::cout << std::endl;
        }catch(std::logic_error ){
            std::cout << "Unesena rijec nije nadjena!" << std::endl;
        }
    }
	return 0;
}