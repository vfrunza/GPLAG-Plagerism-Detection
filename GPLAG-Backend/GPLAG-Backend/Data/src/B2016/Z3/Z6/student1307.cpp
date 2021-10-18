/B2016/2017: Zadaća 3, Zadatak 6
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <stdexcept>
#include <set>
#include <memory>

struct Dijete {
    std::string ime;
    std::shared_ptr<Dijete> sljedeci;
};

std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> imena, int brojt){
    
    if(brojt>imena.size() || brojt<1) throw std::logic_error("Razvrstavanje nemoguce");
    
    std::vector<std::set<std::string>> timovi(brojt);
    std::map<std::string, int> mapa;
    
    std::shared_ptr<Dijete> poc(nullptr);
    
    for(int i(0);i<imena.size();i++){
        
        if(!poc){
            std::shared_ptr<Dijete> neki(new Dijete);
            poc=neki;
            poc->ime=imena[i];
            poc->sljedeci=poc;
        }
        else {
            std::shared_ptr<Dijete> pom(poc);
            std::shared_ptr<Dijete> budala(new Dijete);
            
            while(pom->sljedeci!=poc)   pom=pom->sljedeci;
            
            pom->sljedeci=budala;
            pom->sljedeci->ime=imena[i];
            pom->sljedeci->sljedeci=poc;
        }
        
        int br(0);
        for(int j(0);j<imena[i].size();j++){
            
            if((imena[i][j]>='a' && imena[i][j]<='z') || (imena[i][j]>='A' && imena[i][j]<='Z') || (imena[i][j]>='0' && imena[i][j]<='9'))
            br++;
        }
        
        mapa[imena[i]]=br;
    }
    
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
                timovi[i].insert(poc->ime);
                brojac--;
            }
            
            else if(brojac2!=0){
                timovi[i].insert(poc->ime);
                brojac2--;
            }
            
            int slova(mapa[poc->ime]-1);
            
            std::shared_ptr<Dijete> pomocna(poc);
            
            while(pomocna->sljedeci!=poc) pomocna=pomocna->sljedeci;
            
            std::shared_ptr<Dijete> next(poc->sljedeci);
            
            pomocna->sljedeci=next;
            
            if(poc->sljedeci==poc) { poc->sljedeci=nullptr; break; }
            
            poc=next;
            
            while(slova>0){
                poc=poc->sljedeci;
                slova--;
            }
        }
    }
    
    
    return timovi;
}
int main ()
{ try{
    int broj;
    std::cout<<"Unesite broj djece: ";
    std::cin>>broj;
    
    std::cout<<"Unesite imena djece: "<<std::endl;
    
    std::cin.ignore(1000,'\n');
    std::cin.clear();
    
    std::vector<std::string> imena;
    
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
            else std::cout<<*it<<", ";
        }
        
        std::cout<<std::endl;
    }
}

    catch(std::logic_error e){
        std::cout<<"Izuzetak: "<<e.what();
    }
	return 0;
}