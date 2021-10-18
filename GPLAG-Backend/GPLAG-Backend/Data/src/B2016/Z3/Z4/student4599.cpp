/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <stdexcept>
#include <set>
#include <map>

std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> imena, int brojt){
    
    if(brojt<1 || brojt>imena.size()) throw std::logic_error("Razvrstavanje nemoguce");
    
    std::vector<std::set<std::string>> timovi(brojt);
    
    std::list<std::string> lista;
    
    std::map<std::string, int> mapa;
    
    for(int i(0);i<imena.size();i++){
        
        int br(0);
        lista.push_back(imena[i]);
        
        for(int j(0);j<imena[i].size();j++){
            
            if((imena[i][j]>='a' && imena [i][j]<='z') || (imena[i][j]>='A' && imena[i][j]<='Z') || (imena[i][j]>='0'  && imena[i][j]<='9'))
            br++;
        }
        
        mapa[imena[i]]=br;
    }
    
    auto it=lista.begin();
    
    int e(imena.size()/brojt+1);
    int ee(imena.size()/brojt);
    int brojac(0);
    int brojac2(0);

    for(int i(0);i<brojt;i++){
        
        if(i<(imena.size()%brojt)) brojac=e;
        else if(i>=(imena.size()%brojt)) brojac2=ee;
        
        for(;;){
            if(brojac==0 && brojac2==0) break;
            
            if(brojac!=0){
                timovi[i].insert(*it);
                brojac--;
            }
            
            else if(brojac2!=0){
                timovi[i].insert(*it);
                brojac2--;
            }
            
            int slova(mapa[*it]-1);
            
            if(it==--lista.end()) slova+=1;
            it=lista.erase(it);
            
            while(slova>0){
                if(it==--lista.end())
                    it=lista.begin();
                    
                else it++;
                
                slova--;
            }
        }
    }
    
    return timovi;
}

int main ()
{ 
    try{
    int broj;
    std::cout<<"Unesite broj djece: ";
    std::cin>>broj;
    
    std::cout<<"Unesite imena djece:"<<std::endl;
    
    std::vector<std::string> imena;
    
    std::cin.ignore(1000,'\n');
    std::cin.clear();
    
    for(int i(0);i<broj;i++){
        
        std::string s;
        getline(std::cin,s);
        
        imena.push_back(s);
    }
    
    std::cout<<"Unesite broj timova: ";
    
    int t;
    std::cin>>t;
    
    auto a=Razvrstavanje(imena,t);
    
    for(int i(0);i<a.size();i++){
        std::cout<<"Tim "<<i+1<<": ";
        
        for(auto it=a[i].begin();it!=a[i].end();it++){
            
            if(it==--a[i].end()) std::cout<<*it;
            
            else
            std::cout<<*it<<", ";
        }
        
        std::cout<<std::endl;
    }}
    
    catch(std::logic_error e){
        std::cout<<"Izuzetak: "<<e.what();
    }
    
	return 0;
}