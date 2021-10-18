/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include<string>
#include<map>
#include<set>
#include<iomanip>
#include<iterator>
#include<vector>
#include<stdexcept>

std::map<std::string, std::set<int>>KreirajIndeksPojmova(std::string s){
    std::map<std::string, std::set<int>>mapa;
    int i=0;
    int kraj=0;
    for(int i=0;i<s.size();i++){
        s[i]=tolower(s[i]);
    }
    while(i<s.size()){
        while(!(s[i]>='a' && s[i]<='z' || s[i]>='0' && s[i]<='9') && i<s.size())
        i++;
        kraj=i;
        while((s[kraj]>='a' && s[kraj]<='z' || s[kraj]>='0' && s[kraj]<='9') && kraj<s.size())
        kraj++;
        
        std::string pojam=s.substr(i,kraj-i);
        //std::cout << pojam << std::endl;
        std::set<int>skup;
        for(int j=0;j<=s.size()-pojam.size();j++){
            
            if(s.substr(j,pojam.size())==pojam)
            {
                if(j==0 && !(s[pojam.size()]>='a' && s[pojam.size()]<='z' || s[pojam.size()]>='0' && s[i]<='9')) skup.insert(j);
                else if(j!=0 && j!=s.size()-pojam.size() && !(s[j-1]>='a' && s[j-1]<='z' || s[j-1]>='0' && s[j-1]<='9') && !(s[j+pojam.size()]>='a' && s[j+pojam.size()]<='z' || s[j+pojam.size()]>='0' && s[j+pojam.size()]<='9')) skup.insert(j);
                else if(j!=0 && j==s.size()-pojam.size() && !(s[j-1]>='a' && s[j-1]<='z' || s[j-1]>='0' && s[j-1]<='9'))  skup.insert(j);
            }
        }
       
        mapa.insert(std::make_pair(pojam,skup));
        i=kraj;
    }
    
    
    return mapa;
}

std::set<int>PretraziIndeksPojmova(std::string rijec, std::map<std::string,std::set<int>>mapa){
    
    int ima=0;
    for(auto it=mapa.begin();it!=mapa.end();it++){
       if((it->first)==rijec) {
       ima++;
        return it->second;
    }
 }
    if(ima==0) throw std::logic_error ("Unesena rijec nije nadjena!");
    
}

void IspisiIndeksPojmova(std::map<std::string, std::set<int>>mapa){
    
    for(auto it=mapa.begin();it!=mapa.end();it++){
        std::cout<<it->first<<": ";
       int br=0;
        for(int x: it->second){
            if(br<it->second.size()-1)
           std::cout<<x<<",";
           else std::cout<<x;
           br++;
        }
        std::cout<<std::endl;
    }
}


int main ()
{
    std::string s;
    std::cout<<"Unesite tekst: ";
    std::cin>>std::ws;
    std::getline(std::cin,s);
    std::map<std::string,std::set<int>>a(KreirajIndeksPojmova(s));
    
    /*for(auto it=a.begin();it!=a.end();it++){
    std::cout<<it->first<<": ";
    for(int x: it->second) std::cout<<x<<" ";
    std::cout<<std::endl;
    
    }*/
    IspisiIndeksPojmova(a);
    std::string rijec;
    std::string znak;
    do{
    std::cout<<"Unesite rijec: ";
    std::cin>>std::ws;
    std::getline(std::cin,rijec);
    if(rijec==".") break;
    try{
        std::set<int>b(PretraziIndeksPojmova(rijec,a));
        for(int x: b) std::cout<<x<<" ";
        std::cout<<std::endl;
    }catch(std::logic_error izuzetak){
        std::cout<<izuzetak.what()<<std::endl;
    }
    }while(rijec!=".");
	return 0;
}