/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <utility>
#include <iterator>
#include <stdexcept>
bool prazno(char c){
    if(c==' ') return true;
    else return false;
}
std::map<std::string,std::set<int>> KreirajIndeksPojmova(std::string s){
    std::map<std::string,std::set<int>> vrati;
    std::set<int> skup;
    std::vector<std::string> v;
    std::transform(s.begin(),s.end(),s.begin(),::tolower);
    //std::cout<<s;
    int i=0;
    while(i!=s.size()){
    while(i!=s.size() && s[i]==' ') ++i;
    int j=i;
    while(j!=s.size() && s[j]!=' ') ++j;
    if(j!=i){
        v.push_back(s.substr(i,j-i));
        i=j;
    }
    }
   
    //imam vektor
   
    std::sort(v.begin(),v.end());
    auto last=std::unique(v.begin(),v.end());
    v.erase(last,v.end());
    //for (int i=0; i<v.size(); i++) std::cout<<v[i]<<std::endl;
    if(v.size()==0) throw;
    //int brojac=1;//jer imamo sigurno jednu rijec
    //std::string::size_type
    int start_pos=0;
    //std::string::iterator start_pos=s.begin();
   
    for(int i=0; i<v.size(); i++){
       
        while (std::string::npos!=(start_pos=s.find(v[i],start_pos))) {
            
         
            skup.insert(start_pos);
        
            ++start_pos;
            
        }
        
        vrati.insert(make_pair(v[i],skup));
        skup.clear();
        start_pos=0;
        
    }
	


    //skup.insert(brojac);
    //vrati.insert(make_pair(rijec,skup));
    //stavi u mapu rijec i brojac
   
    return vrati;
    
    
}
std::set<int> PretraziIndeksPojmova( std::string s, std::map<std::string, std::set<int>> mapa){
    std::set<int> vrati;
    std::map<std::string, std::set<int>>::iterator it=mapa.find(s);
    if(it!=mapa.end()) vrati=(*it).second;
    else throw std::logic_error ("Unesena rijec nije nadjena!");
    
    return vrati;
}
void IspisiIndeksPojmova(std::map<std::string, std::set<int>> mapa){
    for(auto& pair : mapa){
        int h=0;
        //for(auto& rijec : pair.first){
             std::cout<<pair.first<<": ";
            for(auto& broj : pair.second){
            std::cout<<broj;
            if(h!=(pair.second).size()-1) std::cout<<",";
            h++;
            }
            std::cout<<std::endl;
        //}
    }
}
int main ()
{
   /*std::string s={"abc qwe stsda abc abc dhi qwe hrkw dhi"};
    std::map<std::string,std::set<int>> mapa=KreirajIndeksPojmova(s);
    IspisiIndeksPojmova(mapa);
    try{
    std::set<int> s=PretraziIndeksPojmova("30",mapa);
    }
    catch(std::logic_error e){
        std::cout<<e.what();
        return 1;
    }*/
   // KreirajIndeksPojmova(s);
   /*IspisiIndeksPojmova({
        {"abc", {0, 1, 2}},
        {"cde", {0, 1, 2}},
        {"ab", {0, 1, 2}},
        {"---", {0, 1, 2}},
        {"xabc", {0, 1, 2, 4, 5, 6, 7}},
        {"abcd", {7}}
    });*/
    std::string s;
    std::cout<<"Unesite tekst: ";
    std::getline(std::cin,s);
   // std::cout<<s;
    std::map<std::string,std::set<int>> mapa=KreirajIndeksPojmova(s);
    IspisiIndeksPojmova(mapa);
    std::string rijec;
    std::set<int> skup;
    
    while(true){
    std::cout<<"Unesite rijec: ";
    std::getline(std::cin,rijec);
    if(rijec==".") break;
        try{
        skup=PretraziIndeksPojmova(rijec,mapa);
        for(auto s:skup) std::cout<<s<<" ";
        std::cout<<std::endl;
        }
        catch(std::logic_error e){
            std::cout<<e.what()<<std::endl;
          
        }
        
    
    }
    
	return 0;
}