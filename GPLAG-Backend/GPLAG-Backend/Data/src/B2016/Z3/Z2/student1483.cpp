#include <iostream>
#include <set>
#include<map>
#include<string>
#include<cstring>
#include<iomanip>
#include <stdexcept>
#include <vector>
#include <iterator>

typedef std::set<int>::iterator setiter;

std::set<int> Funkcija(std::string s,std::vector<std::string>vstring ,std::vector<int>vbroj){
    std::set<int>skup;
    for(int i=0;i<vstring.size();i++){
        if(vstring[i]==s){
            skup.insert(vbroj[i]);
        }
    }
    
    return skup;
}

std::map<std::string,std::set<int>> KreirajIndeksPojmova(std::string s){
    std::map<std::string,std::set<int>>mapa;
   
    if(s!="" && s!=" "){
    std::vector<int>vektorindeksa;
    std::vector<std::string>vektorstringova;
    int pom_brojac(0);
    std::string pomocni_string;
    pomocni_string=s;
    
    for(int i=0;i<s.length();i++){
        if(s[i]>='A'&& s[i]<='Z'){
            s[i]-='A'-'a';
            
        }
    }
    
    for(int i=0;i<s.length();i++){
        while((s[i]<'a' && s[i]>'z') || (s[i]<'0' && s[i]>'9')){
            i++;
        }
        if(i==s.length()) break;
        int temp(i);
        if( (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9') ){
            while( (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9') ){
                pom_brojac++;
                i++;
            }
            std::string pomocni;
            pomocni=s.substr(temp,pom_brojac);
            vektorstringova.push_back(pomocni);
            vektorindeksa.push_back(temp);
            pom_brojac=0;
        }
    }
   

   
    std::vector<std::string> pomocni_string_za_funkciju(vektorstringova);
    
    for(int i=0;i<vektorstringova.size()-1;i++){
        for(int j=i+1;j<vektorstringova.size();j++){
            if(vektorstringova[i]==vektorstringova[j]){
                vektorstringova.erase(vektorstringova.begin()+j);
            }
        }
    }
    std::set<int>s1;
    for(int i=0;i<vektorstringova.size();i++){
        s1=Funkcija(vektorstringova[i],pomocni_string_za_funkciju,vektorindeksa);
        mapa.insert(std::make_pair(vektorstringova[i],s1));
        
    }
    return mapa;
}}

std::set<int> PretraziIndeksPojmova(std::string s,std::map<std::string,std::set<int>>mapa){
    setiter indeksi;
if(!mapa.count(s)){

    throw std::logic_error("Unesena rijec nije nadjena!");
}
else {
 return mapa[s];   
}}

void IspisiIndeksPojmova(std::map<std::string,std::set<int>>mapa){
int n;
std::map<std::string,std::set<int>>::iterator iter(mapa.begin());
setiter seti_pomocni;    
seti_pomocni=iter->second.begin();
n=std::distance(mapa.begin(),mapa.end());
std::advance(seti_pomocni,n-1);

for(auto it=mapa.begin();it!=mapa.end();it++){
    auto iterr=it->second.end()--;
    iterr--;
    
    std::cout<<it->first<<": ";
    
    for(setiter seti=it->second.begin();seti!=it->second.end();seti++){
        
        if(seti==iterr){
            std::cout<<*seti;
        }
        else {
        std::cout<<*seti<<",";
        }
    }
    std::cout<<std::endl;
}    
    
}


int main(){
    std::string s;
    std::map<std::string,std::set<int>>mapa;
    std::cout<<"Unesite tekst: ";
    std::getline(std::cin,s);
  try{  mapa=KreirajIndeksPojmova(s);
    IspisiIndeksPojmova(mapa);
        
}
catch(std::domain_error poruka){
    std::cout<<poruka.what();
    return 0;
}
    
  
        std::string s1;

      do{
        std::set<int>skup;
        std::cout<<"Unesite rijec: ";
        std::getline(std::cin,s1);
        if(s1=="."){
            break;
        }
        try{
        skup=PretraziIndeksPojmova(s1,mapa);
        
        for(auto itek=skup.begin();itek!=skup.end();itek++){
            std::cout<<*itek<<" ";
        }}
        catch(std::logic_error poruka){
            std::cout<<poruka.what();
        }
        std::cout<<std::endl;
    }while(s1!=".");


    
    
    return 0;
}
    
    
    
    
    
    
    
    
    
    
