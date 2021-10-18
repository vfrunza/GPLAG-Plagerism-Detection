/B2016/2017: Zadaća 3, Zadatak 5
#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <new>
#include <stdexcept>


struct Dijete {
    std::string ime;
    Dijete *sljedeci = nullptr;
};

int Prebroji(Dijete *to, Dijete *zadnji) {
    int br=1;
    while (to->sljedeci != zadnji) {
        br++;
        to = to->sljedeci;
    }
    return br;
}

int PrebrojiDjecu(Dijete *prvo) {
    Dijete *ovo(prvo);
    int brojac = 1;
    
    while(ovo->sljedeci != prvo) {
        brojac++;
        ovo = ovo->sljedeci;
    }
   
   return brojac;
}

void KillThemAll(Dijete *prvo) {
    /*int vel = PrebrojiDjecu(prvo);
    
    for(int i = 0; i < vel; i++) {
        Dijete *musko(prvo);
        prvo = prvo->sljedeci;
        musko->sljedeci = nullptr;
        delete musko;
    }*/
    auto zensko(prvo->sljedeci);
    while (zensko != prvo) {
        Dijete * musko = zensko->sljedeci;
        delete zensko;
        zensko = musko;
    }
    delete zensko;
    prvo = nullptr;
}

int velicinaImena(std::string ime) {
    int vel = ime.length();
    
    for(int i = 0; i < ime.length(); i++) {
        if( !( (ime[i] >= 'a' && ime[i] <= 'z') || (ime[i] >= 'A' && ime[i] <= 'Z') || (ime[i] >= '0' && ime[i] <= '9') ) ) vel--;
    }
    
    return vel;
}



Dijete *ProsloDijete( Dijete *neko) {
    Dijete *ovo(neko);
    
    while(ovo->sljedeci != neko) ovo = ovo->sljedeci; 
    
    return ovo;
}

Dijete *KreirajListuDjece(std::vector<std::string> djeca) {
    Dijete *pocetak(nullptr), *prethodni(nullptr), *novi(nullptr);
    
    for(int i = 0; i < djeca.size(); i++) {
        try{
        novi = new Dijete;
       }catch(...) {
           if(pocetak == nullptr) throw;
           KillThemAll(pocetak);
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


void IspisiDjecu(Dijete *prvi) {
     Dijete *p = prvi;
     
    do{
     std::cout<<p->ime<<std::endl;
     p = p->sljedeci; 
    }while(p != prvi);
}

void Pomakni(Dijete *&prvi, int zaToliko) {
    
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
    
    Dijete *djecaUListi = KreirajListuDjece(djeca);
    
    Dijete *tu = djecaUListi;
    Dijete *prvi = djecaUListi;
    Dijete *zadnji = ProsloDijete(prvi);
    
        for(int j = 0 ; j < brClTim.size(); j++) {
            
            std::set<std::string> tim;
                k = 0;
                auto it = tu;
                 
                while( true ) {
                    int vel = PrebrojiDjecu(it);
                    
                    if ( k == brClTim[j]) break;
                   
                    Pomakni(it, korak);
                    
                    tim.insert(it->ime);
                    
                    korak = velicinaImena(it->ime)-1;
                    if(vel == 1) { 
                        //delete it;
                        KillThemAll(it);
                        it = nullptr;
                        break; 
                    }
                    else if(it == prvi) {
                      Dijete  *p = it;
                      it = it->sljedeci;
                      prvi = it;
                      zadnji->sljedeci = it;
                     
                      delete p;
                      p = nullptr;
                    }
                    else if( it == zadnji){ 
                        Dijete *kr = it;
                        Dijete *prethodni = ProsloDijete(it);
                        prethodni->sljedeci = prvi;
                        it = it->sljedeci;
                        zadnji = prethodni;
                        
                       
                        delete kr;
                        kr = nullptr;
                    }
                    else {
                    Dijete *t = it;
                    Dijete *prethodni = ProsloDijete(it);
                    it = it->sljedeci;
                    prethodni->sljedeci = it;
                    delete t;
                    t = nullptr;
                    }
                  
                   tu = it;
                  
                    k++;
    }
    timovi.push_back(tim);
        }
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
    
    }catch(std::bad_alloc b) {
        std::cout << b.what() << std::endl;
    }
    catch(std::logic_error l){
        std::cout <<"Izuzetak: "<< l.what() << std::endl; 
    }
     
  
  
    
	return 0;
}