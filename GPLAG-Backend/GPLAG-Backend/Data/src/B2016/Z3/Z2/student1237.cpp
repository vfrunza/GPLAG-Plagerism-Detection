/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <map>
#include <set>

void IspisiIndeksPojmova(std::map<std::string,std::set<int>> mapa){
    for(auto x: mapa){
        std::cout<<x.first<<": ";
        int i(0);
        for(int y: x.second){
           
          if(i!=0)  std::cout<<","<<y;
            else {
                std::cout<<y;
                i++;
            }
        }
        std::cout<<std::endl;
    }
}

std::set<int> PretraziIndeksPojmova(std::string s,std::map<std::string,std::set<int>> mapa){
    for(int j=0;j<s.size();j++){
        if(isupper(s[j])){
            s[j]=tolower(s[j]);
        }
    }
    if(mapa[s].size()!=0)
    return mapa[s];
    else{ throw std::logic_error("Unesena rijec nije nadjena!");}
}


std::map<std::string,std::set<int>> KreirajIndeksPojmova(std::string s){
    std::map<std::string,std::set<int>> pomocna;
    std::string nova;
    int i(0);
    while(i!=s.size()){
        if(s[i]!=' '){
            nova+=s[i];
            if(i==s.size()-1){
                int mjesto(0);
                mjesto=i-nova.size()+1;
                for(int j=0;j<nova.size();j++){
                    if(isupper(nova[j])){
                        nova[j]=tolower(nova[j]);
                    }
                }
                pomocna[nova].insert(mjesto);
            }
        }
        else {
            int mjesto;
            mjesto=i-nova.size();
              for(int j=0;j<nova.size();j++){
                    if(isupper(nova[j])){
                        nova[j]=tolower(nova[j]);
                    }
                }
            pomocna[nova].insert(mjesto);
            while(s[i]==' '){
                i++;
            }
            if(i!=s.size())
            i--;
            nova="";
            
        }
        i++;
    }
   return pomocna; 
}

int main ()
{
    std::map<std::string,std::set<int>> nova_mapa;
    std::string rijeci;
    
    std::cout<<"Unesite tekst: ";
    std::getline(std::cin,rijeci);
    nova_mapa=KreirajIndeksPojmova(rijeci);
    
    for(auto x:nova_mapa){
        std::cout<<x.first<<": ";
        int i(0);
        for(int y: x.second){
            if(i==0){
                std::cout<<y;
                i++;
            }
            else std::cout<<","<<y;
        }
        std::cout<<std::endl;
    }
    std::cout<<"Unesite rijec: ";
    std::string ta_rijec;
    std::cin>>ta_rijec;
    
    while(ta_rijec!="."){
        try{
            std::set<int> pomocno;
            pomocno=PretraziIndeksPojmova(ta_rijec,nova_mapa);
            int i(0);
            for(int x: pomocno){
                if(i==0){
                    std::cout<<x;
                    i++;
                }
                else std::cout<<" "<<x;
            }
            
        }
        catch(std::logic_error nesto){
            std::cout<<nesto.what();
        }
        std::cout<<std::endl<<"Unesite rijec: ";
        std::cin>>ta_rijec;
    }
	return 0;
}