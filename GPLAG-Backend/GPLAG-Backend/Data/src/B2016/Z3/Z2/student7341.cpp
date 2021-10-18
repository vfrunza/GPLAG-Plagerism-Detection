/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <utility>
#include <set>

std:: map<std::string, std::set<int>> KreirajIndeksPojmova( std::string s){
    
    for(int i=0; i<s.size(); i++){
       if(s[i]>='A' && s[i]<='Z') s[i]=s[i]+'a'-'A';
    }
     
     std::map<std::string, std::set<int>> vracas;
     for(int i=0; i<s.length(); i++){
    
        //IDE KROZ RAZMAKE
        if( i<s.length() && (s[i]==' ' || s[i]== '\t' || s[i]=='\n' || (s[i]<'0') || (s[i]>'9' && s[i]<'A') ||(s[i]>'Z' && s[i]<'a') || (s[i]>'z'))) continue;
        int pocetak=i; 
        //IDE DO KRAJA RIJECI
        while(i<s.length() && ((s[i]>='a'&& s[i]<='z') || (s[i]>='A' && s[i]<='Z') ||(s[i]>='0' && s[i]<='9'))) i++;
        std::string rijec=s.substr(pocetak,i-pocetak);
        vracas[rijec].insert(pocetak);
        int kraj=i;
        
        //IDE DOK NE NADE PRVO SLOVO RIJECI
        while(kraj<s.length()){ 
             if(kraj<s.length()-rijec.length() && s[kraj]==rijec[0] && (s[kraj-1]==' ' || s[kraj-1]=='\n' || s[kraj-1]=='\t')){
                for(int k=0; k<rijec.length(); k++){
                    if(k==int(rijec.length())-1 && s[kraj+k]!=rijec[k]) vracas[rijec].insert(kraj);
                    if(s[kraj+k]!=rijec[k]) break;
                 }
            }
        kraj++;
        }
    
     }
      return vracas;
}    
     
     
 std::set<int> PretraziIndeksPojmova (std::string rijec, std::map<std::string, std::set<int>> parovi){
     if(!parovi.count(rijec)) throw std::logic_error ("Pojam nije naden!");
     for(auto it=parovi.begin(); it!=parovi.end(); it++){
         if(it->first==rijec) return it->second;
     }
      
 }
 
void IspisiIndeksPojmova (std::map<std::string, std::set<int>> parovi){
    for(auto it=parovi.begin(); it!=parovi.end(); it++){
        std::cout<<it->first<<": ";
        int brojac=0;
        for(auto it2=(it->second).begin(); it2!=(it->second).end(); it2++){
            if(brojac==(it->second).size()-1) std::cout<<*it2;
            else std::cout <<*it2<< ",";
            brojac++;
        }    
        std::cout<<std::endl;
    
}
}

        

int main (){
    std::string s;
    std::cout<<"Unesite tekst: ";
    std::getline(std::cin, s);
    auto mapa=KreirajIndeksPojmova(s);
    IspisiIndeksPojmova(mapa);
    std::cout<<"Unesite rijec: ";
        std::string rijec;
        std::cin>>rijec;
        while(rijec!="."){
            try{
                auto skup=PretraziIndeksPojmova(rijec,mapa);
                for(int x: skup) std::cout<<x<<" ";
                std::cout<<std::endl;
                
            } catch(std:: logic_error Izuzetak){
                std::cout<<"Unesena rijec nije nadjena!"<<std::endl;
            }
            std::cout<<"Unesite rijec: ";
            std::cin>>rijec;
    
        }
    return 0;

}