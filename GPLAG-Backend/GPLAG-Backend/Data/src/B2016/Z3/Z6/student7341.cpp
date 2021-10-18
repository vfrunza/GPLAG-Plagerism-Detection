/B2016/2017: Zadaća 3, Zadatak 5
#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <set>
#include <vector>
#include <memory>


struct Dijete {
 std::string ime;
 std::shared_ptr<Dijete> sljedeci;
};

std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string>imena, int br_timova){
    
    if( br_timova<1 || br_timova >imena.size() ) throw std::logic_error ("Razvrstavanje nemoguce");
    std::vector<std::set<std::string>> razvrstani;
    razvrstani.resize(br_timova);
     std::shared_ptr<Dijete> pocetak(nullptr); 
     std::shared_ptr<Dijete> prethodni;
     int i(0);
     for(;;) {
      if(i==imena.size())break;
      std::shared_ptr<Dijete> novi(std::shared_ptr<Dijete> (new Dijete)); // Kreiranje novog čvora
      novi->ime = imena[i]; novi->sljedeci = nullptr;
      if(!pocetak) pocetak = novi; // Prvi čvor...
      else prethodni->sljedeci = novi; 
      prethodni = novi;
      i++;
     }
     
    prethodni->sljedeci=pocetak;
    int u_timu=(imena.size()/br_timova);
    int ostatak=imena.size()%br_timova;
    
    int trenutni_tim(0);
    std::string osoba=pocetak->ime;
    auto it=pocetak;
    
    razvrstani[trenutni_tim].insert(it->ime);
    it=it->sljedeci;
    prethodni->sljedeci=it;
    while(trenutni_tim<br_timova){
    
        
        int broj_slova=count_if(osoba.begin(), osoba.end(), [] (char x) { if((x>='a'&& x<='z') || (x>='A' && x<='Z') ||(x>='0' && x<='9'))return 1; else return 0;});
        
        
        if (prethodni->sljedeci==it->sljedeci){
            it->sljedeci=nullptr;
            razvrstani[br_timova-1].insert(it->ime);
            return razvrstani;
        } 
        
        
        //pomjera it za broj slova imena osobe
        for(int i=0; i<broj_slova-1; i++){
            it=it->sljedeci;
            prethodni=prethodni->sljedeci;
            
        }
        
        //prvi timovi koji imaju vise clanova
        if(trenutni_tim<ostatak){
            if(razvrstani[trenutni_tim].size()==u_timu+1)  trenutni_tim++;
            razvrstani[trenutni_tim].insert(it->ime);
            
            
        }
        //timovi koji imaju tacno clanova
       else if(trenutni_tim>=ostatak){
            if(razvrstani[trenutni_tim].size()==u_timu) trenutni_tim++;
            razvrstani[trenutni_tim].insert(it->ime);
          
        }
        // uzima se ime izbacenog clana za sl krug
        osoba=it->ime;  
        //brise ubacenu osobu i pomjera na sljedecu

        
        it=it->sljedeci;
        prethodni->sljedeci=it;
      
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
 
