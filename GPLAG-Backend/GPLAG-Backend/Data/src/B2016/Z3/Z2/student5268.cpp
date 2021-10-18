#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>


std::map<std::string, std::set<int>> KreirajIndeksPojmova(std::string s){
    std::map <std::string, std::set<int>> m;
    for(int i=0;i<s.length();i++){
        std::set<int> skup;
        if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0'&& s[i]<='9')){
        int poc=i;
        
        while ((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0'&& s[i]<='9')){
        if(i==s.length()) 
        break;
        i++;
        }
        int kraj=i;
        int du=kraj-poc;
        std::string pom=s.substr(poc,du);
        int poc2;
        for(int j=0;j<=s.length();j++){
         if((s[j]>='A' && s[j]<='Z') || (s[j]>='a' && s[j]<='z') || (s[j]>='0'&& s[j]<='9')){
        poc2=j;
        
        while ((s[j]>='A' && s[j]<='Z') || (s[j]>='a' && s[j]<='z') || (s[j]>='0'&& s[j]<='9')){
        if(j==s.length()) 
        break;
        j++;
        }
        }
        std::string hh(s.substr(poc2,j-poc2));
        if(hh==pom)
         skup.insert(poc2);
    }
       m.insert(std::make_pair(pom,skup));
    }
}
return m;
}
std::set<int> PretraziIndeksPojmova(std::string s,std::map<std::string, std::set<int>> m){
        auto it(m.find(s));
        if(it==m.end()) 
        throw std::logic_error("Unesena rijec nije nadjena!");
        return it->second;
}
void IspisiIndeksPojmova(std::map<std::string, std::set<int>> m){
    std::vector<int> v;
    for(auto it=m.begin();it!=m.end();it++){
        int br(0);
        for(auto x : it->second)
        br++;
        v.push_back(br);
    }
    int vec(0);
    for(auto it=m.begin();it!=m.end();it++){
    std::cout << it->first <<": ";
    int br(0);
    for(auto x : it->second){
        if(br==v[vec]-1)
        std::cout << x <<" ";
        else
        std::cout << x <<",";
        br++;
    }
    vec++;
    std::cout  << std::endl;
    }
}
int main(){
    std::cout << "Unesite tekst: " ;
    std::string s;
    std::getline(std::cin,s);
    std::map<std::string, std::set<int>> m(KreirajIndeksPojmova(s));
    std::vector<int> br;
    for(auto it(m.begin());it!=m.end();it++){
        int n(0);
        for(auto a: it->second){
            n++;
        }
        br.push_back(n);
    }
    int nes(0);
    for(auto it(m.begin());it!=m.end();it++){
        std::cout << it->first <<": ";
        int bro(0);
        for(auto a : it->second){
        if(bro==br[nes]-1)
        std::cout << a ;
        else std::cout << a <<",";
        bro++;
        }
        nes++;
        std::cout  << std::endl;
    }
    std::string rijec;
    std::cout << "Unesite rijec: " ;
    std::getline(std::cin,rijec);
    while(rijec!="."){
        try{
        std::set<int> skup(PretraziIndeksPojmova(rijec,m));
        for(auto x : skup)
        std::cout << x << " ";
        std::cout  << std::endl;
            
        }
        catch(std::logic_error l){
            std::cout << l.what() << std::endl;
        }
        std::cout << "Unesite rijec: " ;
        std::getline(std::cin,rijec);
    }
    return 0;
}