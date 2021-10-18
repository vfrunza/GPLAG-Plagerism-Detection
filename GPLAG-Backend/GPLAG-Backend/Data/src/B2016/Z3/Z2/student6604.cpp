/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <set>
#include <stdexcept>

std::map<std::string, std::set<int>> KreirajIndeksPojmova (std::string s){
    std::map<std::string, std::set<int>> m;
    std::string r;
    std::set<int> skup;
    for(int i=0; i<s.length(); i++){
        if(s[i]==' ') i++;
        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') || (s[i]>='0' && s[i]<='9')){
            skup.insert(i);
            int k(i);
            while((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')|| (s[i]>='0' && s[i]<='9')){
                r.push_back(s[i]);
                i++;
            }
            for(int i=0; i<r.length(); i++){
                if(r[i]>='A' && r[i]<='Z') r[i]+=32;
            }
            m.insert(std::make_pair(r, skup));
            for(auto it = m.begin(); it != m.end(); it++){
                if(r==it->first) (it->second).insert(i-r.length());
            }
           skup.erase(k);
        }
        r.resize(0);
    }
    return m;
}

std::set<int> PretraziIndeksPojmova (std::string s, std::map<std::string, std::set<int>> m){
    for(auto it=m.begin(); it!=m.end(); it++){
        if(s==it->first)return it->second;
    }
    throw std::logic_error("Pojam nije nadjen");
}
void IspisiIndeksPojmova(std::map<std::string, std::set<int>>m){
        for(auto it=m.begin(); it!=m.end(); it++){
        std::cout << it->first <<": " ;
        for(auto i=(it->second).begin(); i!=(it->second).end(); i++) {
            if(i==--(it->second).end())std::cout << *i; 
            else std::cout<<*i<<",";
        }
        std::cout<<std::endl;
}}
int main ()
{
    try{
    std::string s;
    std::cout<<"Unesite tekst: ";
    std::getline(std::cin, s);
    std::map<std::string, std::set<int>>m= KreirajIndeksPojmova(s);
    IspisiIndeksPojmova(m);
    std::string p;
    std::set<int> skup;
    for(;;){
        std::cout<<"Unesite rijec: ";
        std::getline(std::cin, p);
        if(p==".") break;
        int ima(0);
        for(int i=0; i<s.length(); i++){
            for(int j=0; j<p.length(); j++){
                if(s[i]==p[j] && (i==0 || s[i-1]==' ')){
                    while(s[i]==p[j] && i<s.length() && j<p.length()){
                        i++;
                        j++;
                    }
                    if((i==s.length()|| s[i]==' ') && j==p.length()) {ima=1; break;}
                }
            }
        }
        if(ima){
        skup=PretraziIndeksPojmova(p, m);
        for(int x : skup) std::cout << x << " "; 
        std::cout<<std::endl;
        }
        else std::cout<<"Unesena rijec nije nadjena!"<<std::endl;
    }
    }
    catch(std::logic_error izuzetak){
        std::cout<<izuzetak.what();
    }
	return 0;
}