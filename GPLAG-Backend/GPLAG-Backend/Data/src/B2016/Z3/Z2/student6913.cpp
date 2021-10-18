/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <string>
#include <set>
#include <map>
std::map<std::string,std::set<int>> KreirajIndeksPojmova (std::string s){
    std::string pom;
    std::map<std::string, std::set<int>> m;
    for(int i=0;i<s.length();i++){
         std::set<int> skup;
        if((s[i]>='A' && s[i]<='Z')||(s[i]>='a' && s[i]<='z')||(s[i]>='0' && s[i]<='9')){
            int p=i;
                for(;;){
                    if((s[i]>='A' && s[i]<='Z')||(s[i]>='a' && s[i]<='z')||(s[i]>='0' && s[i]<='9'))
                       i++;
                    else break;
            }
         pom=s.substr(p,i-p);
       for(int j=0;j<s.length();j++){
         if((s[j]>='A' && s[j]<='Z')||(s[j]>='a' && s[j]<='z')||(s[j]>='0' && s[j]<='9')){
             int dp=j;
             for(;;){
                if((s[j]>='A' && s[j]<='Z')||(s[j]>='a' && s[j]<='z')||(s[j]>='0' && s[j]<='9'))
                j++;
                else break;
             }
             std::string up=s.substr(dp,j-dp);
             if(pom==up)
             skup.insert(dp);
       }   
}
}
m.insert(std::make_pair(pom,skup));
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
    for(auto it(m.begin());it!=m.end();it++){
        std::cout << it->first <<": ";
        std::set<int> s(it->second);
        int br(0);
        for(auto x : s)
        br++;
        int n(0);
        for(auto y : s){
            if(n==br-1)
            std::cout << y << " ";
            else std::cout << y <<",";
            n++;
        }
        std::cout  << std::endl;
    }
}
int main(){
    std::string s;
    std::cout << "Unesite tekst: ";
    std::getline(std::cin,s);
    std::map<std::string, std::set<int>> m(KreirajIndeksPojmova(s)) ;
    for(auto it(m.begin());it!=m.end();it++){
        std::cout << it->first <<": ";
        std::set<int> s(it->second);
        int br(0);
        for(auto x : s)
        br++;
        int n(0);
        for(auto y : s){
            if(n==br-1)
            std::cout << y <<" ";
            else std::cout << y <<",";
            n++;
        }
        std::cout  << std::endl;
    }
    std::string s2;
    std::cout << "Unesite rijec: " ;
    while(std::getline(std::cin,s2),s2!="."){
        std::set<int> skup;
        try{
       skup=PretraziIndeksPojmova(s2,m);
        }
        catch(std::logic_error l){
            std::cout << l.what() << std::endl;
        }
         for(auto x : skup)
        std::cout << x <<" ";
        std::cout  << std::endl;
        std::cout << "Unesite rijec: " ;
    }
    return 0;
}