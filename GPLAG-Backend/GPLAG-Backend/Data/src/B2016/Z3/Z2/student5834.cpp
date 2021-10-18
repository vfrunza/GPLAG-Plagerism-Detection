/B2016/2017: Zadaća 3, Zadatak 2
#include<iostream>
#include<map>
#include<set>
#include<string>
#include<vector>
#include<algorithm>
std::vector<std::string> vektorstringova(std::string s){
    std::vector<std::string> pomvsrt;
    if(s.length()==0) return pomvsrt;
    for(int i=0;i<s.length();i++){
        if((s[i]>='A' && s[i]<='Z')|| (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')){
            std::string pom;
            int poc=i;
            while(((s[i]>='A' && s[i]<='Z')|| (s[i]>='a' && s[i]<='z')|| (s[i]>='0' && s[i]<='9')) && i!=s.length()) i++;
            for(int j=poc;j<i;j++)
                pom.push_back(s[j]);
            pomvsrt.push_back(pom);
        }
        if(i==s.length()) break;
    }
    for(int i=0;i<pomvsrt.size()-1;i++){
        for(int j=i+1;j<pomvsrt.size();j++){
            std::transform(pomvsrt[i].begin(),pomvsrt[i].end(),pomvsrt[i].begin(),::tolower);
            std::transform(pomvsrt[j].begin(),pomvsrt[j].end(),pomvsrt[j].begin(),::tolower);
            if(pomvsrt[i]==pomvsrt[j]){
            pomvsrt.erase(pomvsrt.begin()+j);
            j--;
            }
        }
    }
    return pomvsrt;
}
std::map<std::string,std::set<int>>KreirajIndeksPojmova(std::string s){
    std::vector<std::string> vs=vektorstringova(s);
    std::map<std::string,std::set<int>> rez;
    for(int i=0;i<vs.size();i++){
        std::string trazi=vs[i];
       // std::transform(trazi.begin(),trazi.end(),trazi.begin(),::tolower);
        std::set<int> pomset;
        for(int j=0;j<s.length();j++){
            std::string pom;
            if((s[j]>='A' && s[j]<='Z')|| (s[j]>='a' && s[j]<='z') || (s[j]>='0' && s[j]<='9')){
                int poc=j;
                while(( (s[j]>='a' && s[j]<='z') || (s[j]>='0' && s[j]<='9'))  && j!=s.length()) j++;
                for(int k=poc;k<j;k++)
                  pom.push_back(s[k]);
                if(pom==trazi)
                    pomset.insert(poc);
            }
        }
        rez[vs[i]]=pomset;
    }
    return rez;
}
void IspisiIndeksPojmova(std::map<std::string,std::set<int>> rez){
    for(auto i=rez.begin();i!=rez.end();i++){
        std::cout<<i->first<<": ";
        int br=0;
        for(auto j : i->second){
            br++;
        }
        int pombr=0;
        for(auto j : i->second){
            if(pombr==br-1){std::cout<<j; break;}
            std::cout<<j<<",";
            pombr++;
        }
        std::cout<<std::endl;
    }
}
std::set<int> PretraziIndeksPojmova(std::string s,std::map<std::string,std::set<int>> mapa){
    std::transform(s.begin(),s.end(),s.begin(),::tolower);
    std::set<int> rez;
    auto it(mapa.find(s));
    if(it==mapa.end()) throw std::logic_error("Pojam nije nadjen");
    else{
        rez=it->second;
    }
    return rez;
}
int main ()
{
    std::cout<<"Unesite tekst: ";
    std::string s;
    std::getline(std::cin,s);
    auto rez=KreirajIndeksPojmova(s);
    IspisiIndeksPojmova(rez);
    for(;;){
        std::cout<<"Unesite rijec: ";
        std::string pom;
        std::getline(std::cin,pom);
        if(pom==std::string(".")) break;
        try{
        auto rezmape=PretraziIndeksPojmova(pom,rez);
        int br=0;
        for(auto j : rezmape){
            br++;
        }
        int pombr=0;
        for(auto j : rezmape){
            if(pombr==br-1){std::cout<<j; break;}
            std::cout<<j<<" ";
            pombr++;
        }
        std::cout<<std::endl;
        }
        catch(std::logic_error x){
           // std::cout<<x.what()<<std::endl;
           std::cout << "Unesena rijec nije nadjena!" << std::endl;
        }
    }
	return 0;
}