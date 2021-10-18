/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <exception>
std::map<std::string, std::set<int>>KreirajIndeksPojmova(std::string a){
    std::map<std::string, std::set<int>>vrati;
    for(int i=0; i<a.length(); i++){
        std::vector<int> pom;
        std::string m;
        if((a[i]>='A' && a[i]<='Z')||(a[i]>='a' && a[i]<='z')||(a[i]>='1' && a[i]<='9')){
            int poc=i,sig=0;
            while((a[i]>='A' && a[i]<='Z')||(a[i]>='a' && a[i]<='z')||(a[i]>='1' && a[i]<='9')){
                if(a[i]>='A' && a[i]<='Z')
                    m+=a[i]+32;
                else
                    m+=a[i];
                i++;
            }
            for(auto j=vrati.begin(); j!=vrati.end(); j++){
                if(m==j->first){j->second.insert(poc);sig=1;}
            }
            if(sig==0){
                std::set<int>a{poc};
                vrati.insert(std::make_pair(m,a));
            }
        }
    }

return vrati;
}
void IspisiIndeksPojmova(std::map<std::string, std::set<int>>a){
    for(auto i=a.begin(); i!=a.end(); i++){
        std::cout<<i->first<<": ";
        int k=0;
        for(int j : i->second){
            if(k!=i->second.size()-1)std::cout<<j<<",";
            else std::cout<<j;
            k++;
        }
        std::cout<<std::endl;
    }
}
std::set<int>PretraziIndeksPojmova(std::string a, std::map<std::string,std::set<int>>b){
    std::set<int>m;
    for(auto i=b.begin(); i!=b.end(); i++){
        if(a==i->first)m=i->second;
    }
    if(m.size()==0)throw std::logic_error("Pojam nije nadjen");
    return m;
}
int main ()
{
    std::cout<<"Unesite tekst: ";
    std::string a;
    std::getline(std::cin, a);
    std::map<std::string,std::set<int>>b;
    b=KreirajIndeksPojmova(a);
    IspisiIndeksPojmova(b);
    while(1){
        std::cout<<"Unesite rijec: ";
        std::string ame;
        std::getline(std::cin,ame);
        if(ame==".")break;
        else {
            try{
            std::set<int>ispis=PretraziIndeksPojmova(ame,b);
            for(int x:ispis)std::cout<<x<<" ";
            std::cout<<std::endl;
            }catch(std::logic_error){
                std::cout<<"Unesena rijec nije nadjena!"<<std::endl;
            }
        }
    }
	return 0;
}