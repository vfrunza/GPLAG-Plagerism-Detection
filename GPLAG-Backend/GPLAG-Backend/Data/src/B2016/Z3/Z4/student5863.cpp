/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <list>
#include <vector>
#include <set>
#include <string>
#include <stdexcept>

int velicinaImena(std::string ime) {
    int vel = ime.length();
    for(int i = 0; i < ime.length(); i++) {
        if( !( (ime[i] >= 'a' && ime[i] <= 'z') || (ime[i] >= 'A' && ime[i] <= 'Z') || (ime[i] >= '0' && ime[i] <= '9') ) ) vel--;
    }
    return vel;
}

int kolikoPomaket(int korak, int gdje, int velicina) {
  
    int p=korak,uvecanje =0;
       while(korak != 0) {
       for(int i = 1; i<= velicina; i++) {
            if(korak == 0) break;
            else if( korak == p && gdje+1 <= velicina) i = gdje+1;
            else if (korak == p && gdje+1 > velicina){ i = 1; uvecanje++; }
            
            if( i == velicina  && korak-1 == 0){korak--; break; }
            else if(i == velicina) uvecanje++;
            korak--;
        }
       }
       
    return uvecanje;
}


std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> djeca, int brojTimova) {
    if( brojTimova < 1 || brojTimova > djeca.size() ) throw std::logic_error("Razvrstavanje nemoguce");
    
    std::vector<std::set<std::string>> timovi;
    std::list<std::string> djecaUListi;
    int kolkoVise = djeca.size()%brojTimova;
    int brojClanova =djeca.size()/brojTimova;
    std::vector<int> brClTim;
    
    for(int i = 0; i < brojTimova; i++) {
        if(i < kolkoVise) brClTim.push_back(brojClanova+1);
        else brClTim.push_back(brojClanova);
    }
    
    
    for(auto it = djeca.begin(); it != djeca.end(); it++) 
    djecaUListi.push_back(*it);
   
    
    int korak=0,k=0;
 
    
    std::list<std::string>::iterator tu = djecaUListi.begin();
        for(int j = 0 ; j < brClTim.size(); j++) {
            std::set<std::string> tim;
        
                k = 0;
                auto it = tu;
                 int vel = std::distance(djecaUListi.begin(),djecaUListi.end());
                 int gdje = vel - std::distance(it, djecaUListi.end())+1;
                 
                while( true ) {
                    if ( k == brClTim[j]) break;
                  
                   if(vel - gdje < korak){
                      int koliko = kolikoPomaket(korak,gdje,vel);
                   
                        std::advance(it, korak+koliko);
                    } 
                    else std::advance(it, korak);
                    
                    if(it == djecaUListi.end())  it = djecaUListi.begin(); 
                 
                    tim.insert(*it);
                  
                    korak = velicinaImena(*it)-1;
                    it = djecaUListi.erase(it);
                    if(it == djecaUListi.end()) it = djecaUListi.begin(); 
                  
                    tu = it;
                    vel = std::distance(djecaUListi.begin(),djecaUListi.end());
                    gdje = vel - std::distance(it, djecaUListi.end())+1;
                    k++;
    }
    timovi.push_back(tim);
        }
        return timovi;
}




int main ()
{  //std::vector<std::string> djeca = {"Noa","Zara","Ana-Marija","2PAC","Dario","Leon","50 Cent","Lea Alma","Albus Percival Wulfric Brian","Harry James","Hermione Jean","Rubeus","Minevra","Nicole"};
  //std::vector<std::string> djeca = {"Damir","Ana","Muhamed","Marko","Ivan","Mirsad","Nikolina","Alen","Jasmina","Merima"};
   // std::vector<std::string> djeca = {"Zlata","Akif","Mehmed","Muris","Jasmina","Nezla","Ali Raza","Muhamed-Ali"};
  // std::vector<std::string> djeca  = {"Ana Marija","Bin Laden","Isus Hristos Simnen Stanko","Mirza","David Vid Viktorije Dimitrije Sebastijan Ernest"};
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
    int br=0;
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
    
  }catch(std::logic_error l) {
      std::cout << "Izuzetak: "<< l.what() << std::endl;
  }
    
	return 0;
}