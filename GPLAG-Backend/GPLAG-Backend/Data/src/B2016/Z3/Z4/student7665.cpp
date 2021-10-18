#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <list>
#include <iterator>
#include <stdexcept>
#include <cstring>

std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> VekStr, int BrojTimova){
    int BrojDjece(0);
    for(int i=0; i<VekStr.size(); i++){
        BrojDjece++;
    }
    
    if(BrojTimova<1 || BrojTimova>BrojDjece) throw std::logic_error("Razvrstavanje nemoguce");
    
    std::vector<std::set<std::string>> PovratniVektor;
    std::list<std::string> Lista;
    std::set<std::string> TempSet;
    std::list<std::string>::iterator it(Lista.begin());
    
    for(int i=0; i<VekStr.size(); i++){                                                //kreiranje liste
        Lista.insert(it, VekStr[i]);
        it++;
    }
    
    if(it==Lista.end()) it=Lista.begin();
    
    int PrviTimovi;
    int OstaliTimovi;
    
    PrviTimovi=BrojDjece%BrojTimova;
    OstaliTimovi=BrojTimova-PrviTimovi;
    std::vector<std::string> TempVec;
    
    while(!Lista.empty()){
        
        TempVec.push_back(*it);
        int brojac(0);
        brojac=int((*it).length());
        
        it=Lista.erase(it); 
        if(it==Lista.end()) it=Lista.begin();
        
        for(int j=0; j<brojac-1; j++) {
            it++;
            if(it==Lista.end()) it=Lista.begin();
        }
    }
    
    
    for(int z=0; z<PrviTimovi; z++){
        for(int j=0; j<int(BrojDjece/BrojTimova)+1; j++){
            TempSet.insert(TempVec[0]);
            TempVec.erase(TempVec.begin()+0);
            if(TempVec.size()==0) break;
        }
        PovratniVektor.push_back(TempSet);
        while(!TempSet.empty()) TempSet.erase(TempSet.begin());
    }
    
    for(int z=0; z<OstaliTimovi; z++){
        for(int j=0; j<int(BrojDjece/BrojTimova); j++){
            TempSet.insert(TempVec[0]);
            if(TempVec.size()>1) 
            TempVec.erase(TempVec.begin()+0);
        }
        PovratniVektor.push_back(TempSet);
        while(!TempSet.empty()) TempSet.erase(TempSet.begin());
    }
    
    return PovratniVektor;
}

int main ()
{
    int n, k;
    std::cout<<"Unesite broj djece: ";
    std::cin>>n;
    
    std::vector<std::string> Imena;
    Imena.resize(n);
    std::string Pom;
    
    
    std::cout<<"Unesite imena djece: "<<std::endl;
    for(int i=0; i<n; i++){
        std::cin>>Pom;
        Imena[i]=Pom;
        Pom.clear();
    }
    
    std::cout<<"Unesite broj timova: ";
    std::cin>>k;
    
    try{
        auto Povratna(Razvrstavanje(Imena, k));
        for(int i=0; i<k; i++){
            std::cout<<"Tim "<<i+1<<": ";
            std::string MaxEl;
            
            for(auto x: Povratna[i]){
                MaxEl=x;
                if(x>MaxEl) MaxEl=x;
            }
            
            for(auto x: Povratna[i]){
                if(x==MaxEl) std::cout<<x;
                else std::cout<<x<<", ";
            }
            std::cout<<std::endl;
        }
    }
    
    catch(std::logic_error izuzetak){
        std::cout<<izuzetak.what();
    }
    
	return 0;
}