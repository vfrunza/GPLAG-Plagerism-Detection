/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <set>
#include <list>
#include <vector>
#include <string>
#include <algorithm>
#include <stdexcept>



std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string>imena, int br_timova){
    
    if( br_timova<1 || br_timova >imena.size() ) throw std::logic_error ("Razvrstavanje nemoguce");
    std::vector<std::set<std::string>> razvrstani;
    razvrstani.resize(br_timova);
    std::list<std::string> lista;
    int u_timu=(imena.size()/br_timova);
    int ostatak=imena.size()%br_timova;
    
    
    //prebacujes u listu elemente vektora
    
    std::copy(imena.begin(), imena.end(), std::back_inserter(lista) );
    
    
    int trenutni_tim(0);
    std::string osoba=*lista.begin();
    auto it=lista.begin();
    
    
    //broji slova u imenu ako ima razmake da se ne pikaju u duzinu;
    
    
    razvrstani[trenutni_tim].insert(*it);
    it=lista.erase(it);
    while(trenutni_tim<br_timova){
    
        
        int broj_slova=count_if(osoba.begin(), osoba.end(), [] (char x) { if((x>='a'&& x<='z') || (x>='A' && x<='Z') ||(x>='0' && x<='9'))return 1; else return 0;});
        
        
        if (lista.size()==1){
           razvrstani[br_timova-1].insert(*it);
           return razvrstani;
        } 
        
        
        //pomjera it za broj slova imena osobe
        for(int i=0; i<broj_slova-1; i++){
            it++;
            if(it==lista.end()) it=lista.begin();
        }
        
        //prvi timovi koji imaju vise clanova
        if(trenutni_tim<ostatak){
            if(razvrstani[trenutni_tim].size()==u_timu+1)  trenutni_tim++;
            razvrstani[trenutni_tim].insert(*it);
            
            
        }
        //timovi koji imaju tacno clanova
       else if(trenutni_tim>=ostatak){
            if(razvrstani[trenutni_tim].size()==u_timu) trenutni_tim++;
            razvrstani[trenutni_tim].insert(*it);
          
        }
        // uzima se ime izbacenog clana za sl krug
        osoba=*it;  
        //brise ubacenu osobu i pomjera na sljedecu

        it=lista.erase(it);
        if(it==lista.end()) it=lista.begin();
    }
        
    return razvrstani;
    
    
}

int main (){
    std::vector<std::string> imena;
    int broj_djece;
    std::cout<<"Unesite broj djece: ";
    std::cin>>broj_djece;
    std::cin.ignore(1000, '\n');
    std::cout<<"Unesite imena djece: ";
    std::string ime;
    for(int i=0; i<broj_djece; i++){
      std::getline(std::cin, ime);
      imena.push_back(ime);
    }
    
    int n;
    std::cout<<std::endl<<"Unesite broj timova: ";
    std::cin>>n;
    try {
        auto razvrstani=Razvrstavanje(imena,n);
    
        for(int i=0; i<razvrstani.size(); i++){
            std::cout<<"Tim "<<i+1<<": ";
            int brojac=0;
            for(auto it=razvrstani[i].begin(); it!=razvrstani[i].end(); it++){
                if(brojac==razvrstani[i].size()-1) std::cout<<*it;
                else std::cout<<*it<<", ";
                 brojac++;
            }
        std::cout<<std::endl;
        
        }
    }catch(std::logic_error Izuzetak) {
        std::cout<<"Izuzetak: "<<Izuzetak.what()<<std::endl;
        return 0;
    }    
    
    return 0;
    
    
	
}