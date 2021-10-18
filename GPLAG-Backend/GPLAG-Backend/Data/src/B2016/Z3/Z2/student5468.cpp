/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <set>
#include <map>
#include <string>
#include <stdexcept>

std::map<std::string,std::set<int>> KreirajIndeksPojmova(std::string tekst){
    std::map<std::string,std::set<int>> pojmovi;
    std::string pom(tekst);
    for(auto &x : pom){
        if((x>='A')&&(x<='Z'))
            x+='a'-'A';
    }    
    for(int i=0; i<pom.length(); i++){
        if((i==0) or (((pom[i-1]<'a')and((pom[i-1]<'0') or (pom[i-1]>'9') ) )or(pom[i-1]>'z'))){
            if(((pom[i]>='a')and(pom[i]<='z')) or ((pom[i]>='0') and (pom[i]<='9'))){ 
                for(int j=i; j<pom.length(); j++){
                    if((j+1==pom.length()) or (((pom[j+1]<'a')and((pom[j+1]<'0') or (pom[j+1]>'9') ) )or(pom[j+1]>'z')) ){
                        pojmovi[pom.substr(i,j-i+1)].insert(i);
                        i=j;
                        break;
                    }
                }
            }
        }
    }
    return pojmovi;
}

std::set<int> PretraziIndeksPojmova(std::string rijec, std::map<std::string,std::set<int>> pojmovi){
    auto it(pojmovi.find(rijec));
    if( it==pojmovi.end()){
        throw std::logic_error ("Pojam nije nadjen");
    }
    else{
        return pojmovi[rijec];
    }
}

void IspisiIndeksPojmova(std::map<std::string,std::set<int>> pojmovi){
    
    for(auto it(pojmovi.begin()); it!=pojmovi.end(); it++){
        std::cout<<it->first<<": ";
        for(auto it2(it->second.begin()); it2!=it->second.end(); it2++){
            it2++;
            if(it2==it->second.end()){
            it2--;
            std::cout<<*it2;
            continue;
            }
            else it2--;
            std::cout<<*it2<<",";
        }
        std::cout<<std::endl;
    }
}

int main ()
{
    std::string recenica;
    std::cout<<"Unesite tekst: ";
    std::getline(std::cin,recenica);
    auto a(KreirajIndeksPojmova(recenica));
    IspisiIndeksPojmova(a);
    for(;;){
        std::cout<<"Unesite rijec: ";
        std::string rijec;
        std::getline(std::cin,rijec);
        if(rijec==".") break;
        try{
        for(auto x : PretraziIndeksPojmova(rijec,a)){
            std::cout<<x<<" ";
        }
        }catch(...){
            std::cout<<"Unesena rijec nije nadjena!";
        }
        std::cout<<std::endl;
    }
	return 0;
}