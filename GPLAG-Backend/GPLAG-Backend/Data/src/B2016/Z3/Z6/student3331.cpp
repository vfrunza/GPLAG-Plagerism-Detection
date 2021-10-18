/B2016/2017: Zadaća 3, Zadatak 6
#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <stdexcept>
#include <memory>

struct Dijete {
    std::string ime;
    std::shared_ptr<Dijete> sljedeci = nullptr;
};

int Prebroji(std::shared_ptr<Dijete> to, std::shared_ptr<Dijete> zadnji) {
    int br=1;
    while ( to->sljedeci != zadnji) {
        br++;
        to = to->sljedeci;
    }
    to= nullptr;
    zadnji = nullptr;
    return br;
}

int PrebrojiDjecu(std::shared_ptr<Dijete> prvo) {
    auto ovo(prvo);
    int brojac = 1;
    
    while( ovo->sljedeci != prvo) {
        brojac++;
        ovo = ovo->sljedeci;
    }
    prvo = nullptr;
    ovo = nullptr;
   
   return brojac;
}


int velicinaImena(std::string ime) {
    int vel = ime.length();
    
    for(int i = 0; i < ime.length(); i++) {
        if( !( (ime[i] >= 'a' && ime[i] <= 'z') || (ime[i] >= 'A' && ime[i] <= 'Z') || (ime[i] >= '0' && ime[i] <= '9') ) ) vel--;
    }
    
    return vel;
}



std::shared_ptr<Dijete> ProsloDijete(std::shared_ptr<Dijete> neko) {
    auto ovo(neko);
    
    while(ovo->sljedeci != neko) ovo = ovo->sljedeci;
    neko = nullptr;
    return ovo;
}

std::shared_ptr<Dijete> KreirajListuDjece(std::vector<std::string> djeca) {
  std::shared_ptr<Dijete> pocetak(nullptr), prethodni(nullptr), novi(nullptr);
    
    for(int i = 0; i < djeca.size(); i++) {
        try{
        novi = std::make_shared<Dijete>();
        }catch(...) {
            
             pocetak = nullptr;
             prethodni = nullptr;
             novi = nullptr;
             throw;
        }
        novi->ime = djeca[i];
        novi->sljedeci = nullptr;
        if(!pocetak ) pocetak = novi;
        else prethodni->sljedeci = novi;
        prethodni = novi;
        novi = nullptr;
    }
    prethodni->sljedeci = pocetak; 
    
    return pocetak;
}


void Pomakni(std::shared_ptr<Dijete> &prvi, int zaToliko) {
    
    while (true) {
        if(zaToliko == 0) break;
        prvi = prvi->sljedeci;
        zaToliko--;
    }
}



std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> djeca, int brojTimova) {
    if( brojTimova < 1 || brojTimova > djeca.size() ) throw std::logic_error("Razvrstavanje nemoguce");
    
    std::vector<std::set<std::string>> timovi;
    int kolkoVise = djeca.size() % brojTimova;
    int brojClanova = djeca.size() / brojTimova;
    std::vector<int> brClTim; // smijem li imat?
    int korak = 0, k = 0;
    
    for(int i = 0; i < brojTimova; i++) {
        if(i < kolkoVise) brClTim.push_back(brojClanova+1);
        else brClTim.push_back(brojClanova);
    }
    
    auto djecaUListi = KreirajListuDjece(djeca);
    
    std::shared_ptr<Dijete> tu = djecaUListi;
    std::shared_ptr<Dijete> prvi = std::move(djecaUListi);
    std::shared_ptr<Dijete> zadnji = std::move(ProsloDijete(prvi));
    std::shared_ptr<Dijete> it = nullptr;
        for(int j = 0 ; j < brClTim.size(); j++) {
            
            std::set<std::string> tim;
                k = 0;
                it = tu;
                 
                while( true ) {
                    int vel = PrebrojiDjecu(it);
                    
                    if ( k == brClTim[j]) break;
                   
                    Pomakni(it, korak);
                    
                    tim.insert(it->ime);
                    
                    korak = velicinaImena(it->ime)-1;
                    if(vel == 1) { 
                        it->sljedeci = nullptr;
                        break; 
                    }
                    else if(it == prvi) {
                     
                      it = it->sljedeci;
                      prvi = it;
                      zadnji->sljedeci = it;
                     }
                    else if( it == zadnji){ 
                        
                        auto prethodni = std::move(ProsloDijete(it));
                        it = it->sljedeci;
                        prethodni->sljedeci = prvi;
                        
                        zadnji = prethodni;
                    }
                    else {
                   
                    auto prethodni = std::move(ProsloDijete(it));
                    it = it->sljedeci;
                    prethodni->sljedeci = it;
                    }
                   tu = it;
                  
                    k++;
    }
    timovi.push_back(tim);
        }
        
        it = nullptr;
        return timovi;
}







int main ()
{
    
  // std::vector<std::string> djeca = {"Damir","Ana","Muhamed","Marko","Ivan","Mirsad","Nikolina","Alen","Jasmina","Merima"};
 // std::vector<std::string> djeca = {"Zlata","Akif","Mehmed","Muris","Jasmina","Nezla","Ali Raza","Muhamed-Ali"};
 //std::vector<std::string> djeca = {"Ana Marija","Bin Laden","Isus Hristos Simnen Stanko","Mirza","David Vid Viktorije Dimitrije Sebastijan Ernest"};
  // std::cout<<velicinaImena("David Vid Viktorije Dimitrije Sebastijan Ernest");
  try{
    std::cout<<"Unesite broj djece: ";
    int n=0;
    std::cin>>n;
    std::cout<<"Unesite imena djece: ";
    std::vector<std::string> djeca;
    std::string dijete;
    std::cin.ignore(10000,'\n');
    for(int i = 0 ; i < n; i++) {
        std::getline(std::cin,dijete);
        djeca.push_back(dijete);
    }

    
    std::cout<<std::endl<<"Unesite broj timova: ";
    int br;
    std::cin>>br;
    
    auto vek = Razvrstavanje(djeca,br);
    
    for(int i = 0; i < vek.size(); i++) {
        std::cout<<"Tim "<<i+1<<": ";
        int vel = std::distance(vek[i].begin(),vek[i].end());
        for(auto it = vek[i].begin(); it != vek[i].end(); it++) {
            vel--;
            if(vel == 0) std::cout<<*it;
            else std::cout<<*it<<", ";
    }
    std::cout<<std::endl;
    }
    
  }
    catch(std::logic_error l) {
        std::cout <<"Izuzetak: "<< l.what() << std::endl; 
    }
     
  
  
    
	return 0;
}