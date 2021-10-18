#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <stdexcept>

struct Dijete {
    std::string ime;
    Dijete *sljedeci;
};


std::vector<std::multiset<std::string>> Razvrstavanje(std::vector<std::string> imena , int brojtimova) {
        
        if(brojtimova<1 || brojtimova>imena.size()) throw std::domain_error("Razvrstavanje nemoguce");
        
        //PRAVIM VEKTOR BROJEVA KOLIKO JE U SVAKOM TIMU CLANOVA
        std::vector<int> brojclanovautimu(brojtimova);
        for(int i=0;i<brojclanovautimu.size();i++) brojclanovautimu[i]=(imena.size()/brojtimova); 
            
        //POVECAVAM TIMOVE SA OSTATKOM 
        int ostatak; ostatak=imena.size()-brojclanovautimu[0]*brojtimova; 
        for(int i=0;i<ostatak;i++) brojclanovautimu[i]++;
        
        
        std::vector<std::multiset<std::string>> timovi;
        timovi.resize(brojtimova); 
        
        Dijete *prvi, *prethodni;
        prvi=nullptr;
        for(int i=0;i<imena.size();i++) {
            Dijete *dijete(new Dijete);
            dijete->sljedeci=nullptr;
            dijete->ime=imena[i];
            if(!prvi) prvi=dijete;
            else prethodni->sljedeci=dijete;
            prethodni=dijete;
        }
        prethodni->sljedeci=prvi;
        
        //UBACUJEM IMENA U TIMOVE
        int brojac{0};
        for(int i=0;i<timovi.size();i++) {
            while(brojac!=brojclanovautimu[i]) {
                
                timovi[i].insert(prvi->ime); 
                brojac++;
                prethodni->sljedeci=prvi->sljedeci;
                Dijete* nul; nul=prvi;
                int brojslova; brojslova=(prvi->ime).size();
                
                prvi=prethodni->sljedeci;
                for(int j=0;j<brojslova-1;j++) 
                {
                    prvi=prvi->sljedeci;
                    prethodni=prethodni->sljedeci;
                }
               delete nul;
            }
            brojac=0;
           }
           return timovi;

}

int main() {
    std::cout<<"Unesite broj djece: ";
    int brojdjece; std::cin>>brojdjece;
    
    std::cout<<"Unesite imena djece: "<<std::endl;
    std::vector<std::string> imena;
    for(int i=0;i<brojdjece;i++) {
        std::string ime;
        std::cin>>std::ws;
        std::getline(std::cin,ime);
        imena.push_back(ime);
    }
    
    std::cout<<"Unesite broj timova: ";
    int brojtimova; std::cin>>brojtimova;
    
    
    try{
        std::vector<std::multiset<std::string>> konacni;
        konacni=Razvrstavanje(imena,brojtimova);
        
        for(int i=0;i<konacni.size();i++) {
            auto iter1=konacni[i].begin();
            auto iter2=konacni[i].end();
            std::cout<<"Tim "<<i+1<<": ";
            int brojac{0};
            while(iter1!=iter2) {
                brojac++;
                if(brojac==konacni[i].size()) std::cout<<*iter1;
                else std::cout<<*iter1<<", ";
                iter1++;
            }
            std::cout<<std::endl;
        }
    }
    catch(std::domain_error izuzetak){
        std::cout<<izuzetak.what()<<std::endl;
    }
    
    return 0;
}