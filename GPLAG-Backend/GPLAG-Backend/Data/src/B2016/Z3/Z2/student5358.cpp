/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <stdexcept>
std::string Mala(std::string s){
    for(int i=0;i<s.size();i++){
        if(s[i]>='A' && s[i]<='Z')s[i]+='a'-'A';
    }
    return s;
}
bool Jesu_iste(std::string s, std::string r){
      if(s.size()!=r.size()) return false;
      for (int i=0; i<s.size(); i++)
         if (s[i]!=r[i]) return false;
     return true;
}
std::map<std::string,std::set<int>>KreirajIndeksPojmova(std::string s){
    s=Mala(s);
    std::map<std::string,std::set<int>>m;
    std::set<std::string>l;
    for(int i=0;i<s.size();i++){
        std::string pom;
        //while(s[i]!=' ' && i!=s.size())
        while( ((s[i]>='0' && s[i]<='9') || (s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z')) && i!=s.size())
        {
            pom.push_back(s[i]);
            i++;
        }
        l.insert(pom);
    }
    for(std::string ss:l){
        std::set<int>brojevi;
        for (int j=0; j<s.size(); j++) {
            std::string r;
            int br=0;
            if ((s[j]>='0' && s[j]<='9') || (s[j]>='A' && s[j]<='Z') || (s[j]>='a' && s[j]<='z')) {
               br=j;
               r+=s[j];
               j++;
            }
            for (int k=j;((s[k]>='0' && s[k]<='9') || (s[k]>='A' && s[k]<='Z') || (s[k]>='a' && s[k]<='z')) && k!=s.size(); k++) {
                r+=s[k];
                j++;
            }
            if (Jesu_iste(ss,r)) brojevi.insert(br);
        }
        m.insert(make_pair(ss,brojevi));
     }
     return m;
}
std::set<int>PretraziIndeksPojmova(std::string s,std::map<std::string,std::set<int>>m){
    s=Mala(s);
    for(auto it=m.begin();it!=m.end();it++){
        if(s==it->first)return it->second;
    }
    throw std::logic_error("Unesena rijec nije nadjena!");
}
void IspisiIndeksPojmova(std::map<std::string,std::set<int>>m){
    for(auto it=m.begin();it!=m.end();it++){
        if(it->first=="")it++;
        std::cout<<it->first<<": ";
        bool z=true;
        for(int x:it->second){
            if(z){std::cout<<x;z=false;}
            else
            std::cout<<","<<x;
        }
        std::cout<<std::endl;
    }
}
int main ()
{
    std::cout<<"Unesite tekst: ";
    std::string s;
    std::getline(std::cin,s);
    std::map<std::string,std::set<int>>m;
    s=Mala(s);
    m=KreirajIndeksPojmova(s);
    IspisiIndeksPojmova(m);
    std::string rijec;
    //std::cin.clear();
    //std::cin.ignore(10000,'\n');
    for(;;) {
        std::cout<<"Unesite rijec: ";
        std::cin>>rijec;
        if(rijec==".")break;
        try{
            std::set<int>br;
            br=PretraziIndeksPojmova(rijec,m);
            for(int x:br)std::cout<<x<<" ";
            std::cout<<std::endl;
        }
        catch(std::logic_error e){
            std::cout<<e.what()<<std::endl;
        }
    }
	return 0;
}