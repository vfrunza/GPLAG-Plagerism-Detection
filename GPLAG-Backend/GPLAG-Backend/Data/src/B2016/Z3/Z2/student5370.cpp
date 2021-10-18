/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <string>
#include <set>
#include <vector>
#include <cctype>
#include <stdexcept>
bool UporediMe(std::string s1,std::string s2) {
    for(int i=0;i<s1.length();i++) {
        s1[i]=std::toupper(s1[i]);
    }
    for(int i=0;i<s2.length();i++) {
        s2[i]=std::toupper(s2[i]);
    }
    return s1==s2;
}
void SmanjiMe(std::string &s1,std::string &s2) {
    for(int i=0;i<s1.length();i++) {
        s1[i]=std::tolower(s1[i]);
    }
    for(int i=0;i<s2.length();i++) {
        s2[i]=std::tolower(s2[i]);
    }
}
std::map<std::string,std::set<int>> KreirajIndeksPojmova(std::string s) {
    std::map<std::string,std::set<int>> mapa;
    std::vector<std::string> vektor_stringova;
    int neslovo=1;
    for(int i=0;i<s.length();i++) {
        if(!((s[i]>='a' && s[i]<='z') ||(s[i]>='A' && s[i]<='Z') || (s[i]>='0' && s[i]<='9'))) neslovo=1;
        else if (neslovo==1 && (i==0 ||!((s[i-1]>='a' && s[i-1]<='z') || (s[i-1]>='A' && s[i-1]<='Z') || (s[i-1]>='0' && s[i-1]<='9')))) {
            neslovo=0;
            std::string rijec;
            if(!((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') || (s[i]>='0' && s[i]<='9'))) i++;
            while((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') || (s[i]>='0' && s[i]<='9')) {
                rijec.push_back(s[i]);
                i++;
            }
            i--;
            vektor_stringova.push_back(rijec);
        }
    }
    for(int i=0;i<vektor_stringova.size();i++) {
        for(int j=i+1;j<vektor_stringova.size();j++) {
            if(UporediMe(vektor_stringova[i],vektor_stringova[j])) {
                SmanjiMe(vektor_stringova[i],vektor_stringova[j]);
                for(int k=j;k<vektor_stringova.size()-1;k++) {
                    vektor_stringova[k]=vektor_stringova[k+1];
                }
                j--;
                vektor_stringova.resize(vektor_stringova.size()-1);
            }
        }
    }
    std::vector<std::set<int>> vektor_skupova(vektor_stringova.size());
    int brojac;
    int k;
    for(int i=0;i<vektor_stringova.size();i++) {
        for(int j=0;j<s.length();j++) {
            brojac=0;
            k=j;
            if(j==0 || (!(s[j-1]>='a' && s[j-1]<='z') || (s[j-1]>='A' && s[j-1]<='Z') || (s[j-1]>='0' && s[j-1]<='9')))
            while((s[k]==vektor_stringova[i][brojac] || s[k]-32==vektor_stringova[i][brojac] || s[k]+32==vektor_stringova[i][brojac]) && brojac!=vektor_stringova[i].length() && k!=s.length()) {
                brojac++;
                k++;
            }
            
            if(brojac==vektor_stringova[i].length() && (k==s.length() || (!(s[k]>='a' && s[k]<='z') || (s[k]>='A' && s[k]<='Z') || (s[k]>='0' && s[k]<='9')))) {
                vektor_skupova[i].insert(j);
                j=k;
            }
        }
    }
    for(int i=0;i<vektor_stringova.size();i++) {
        mapa.insert(std::make_pair(vektor_stringova[i],vektor_skupova[i]));
    }
    return mapa;
}
std::set<int> PretraziIndeksPojmova(std::string s,std::map<std::string,std::set<int>> mapa) {
    auto it=mapa.find(s);
    if(it==mapa.end()) throw std::logic_error ("Pojam nije nadjen");
    return it->second;
}
void IspisiIndeksPojmova(std::map<std::string,std::set<int>> mapa) {
    for(auto x:mapa) {
        std::cout<<x.first<<": ";
        std::set<int> skup;
        skup=x.second;
        for(auto it=skup.begin();it!=skup.end();) {
            std::cout<<*it++;
            if(it!=skup.end()) std::cout<<",";
        }
        std::cout<<std::endl;
    }
}
int main ()
{
    
    std::string s;
    std::cout<<"Unesite tekst: ";
    std::getline(std::cin,s);
    auto mapa=KreirajIndeksPojmova(s);
    IspisiIndeksPojmova(mapa);
    while(1) {
        std::cout<<"Unesite rijec: ";
        std::string rijec;
        std::getline(std::cin,rijec);
        if(rijec==".") break; 
        try {
            auto skup=PretraziIndeksPojmova(rijec,mapa);
            for(auto x:skup) {
                std::cout<<x<<" ";
            }
            std::cout<<std::endl;
        }
        catch(...) {
            std::cout<<"Unesena rijec nije nadjena!"<<std::endl;
        }
    }
	return 0;
}