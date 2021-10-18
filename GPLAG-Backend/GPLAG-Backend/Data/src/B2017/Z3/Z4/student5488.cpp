#include <iostream>
#include <list>
#include <string>
#include <utility>
#include <stdexcept>
#include <map>
#include <queue>
#include <algorithm>


enum class Boje {Pik, Tref, Herc, Karo};

std::list<std::pair<Boje, std::string>> KreirajSpil(){
std::list<std::pair<Boje, std::string>> lista;
for(int i = 2; i < 15; i++){
        if(i <=10)lista.push_back(std::make_pair(Boje::Pik, std::to_string(i)));
        else if(i == 11)lista.push_back(std::make_pair(Boje::Pik, "J"));
        else if(i == 12)lista.push_back(std::make_pair(Boje::Pik, "Q"));
        else if(i == 13)lista.push_back(std::make_pair(Boje::Pik, "K"));
        else if(i == 14)lista.push_back(std::make_pair(Boje::Pik, "A"));
    }
     for(int i = 2; i < 15; i++){
        if(i <=10)lista.push_back(std::make_pair(Boje::Tref, std::to_string(i)));
        else if(i == 11)lista.push_back(std::make_pair(Boje::Tref, "J"));
        else if(i == 12)lista.push_back(std::make_pair(Boje::Tref, "Q"));
        else if(i == 13)lista.push_back(std::make_pair(Boje::Tref, "K"));
        else if(i == 14)lista.push_back(std::make_pair(Boje::Tref, "A"));
    }
     for(int i = 2; i < 15; i++){
        if(i <=10)lista.push_back(std::make_pair(Boje::Herc, std::to_string(i)));
        else if(i == 11)lista.push_back(std::make_pair(Boje::Herc, "J"));
        else if(i == 12)lista.push_back(std::make_pair(Boje::Herc, "Q"));
        else if(i == 13)lista.push_back(std::make_pair(Boje::Herc, "K"));
        else if(i == 14)lista.push_back(std::make_pair(Boje::Herc, "A"));
    }
     for(int i = 2; i < 15; i++){
        if(i <= 10)lista.push_back(std::make_pair(Boje::Karo, std::to_string(i)));
        else if(i == 11)lista.push_back(std::make_pair(Boje::Karo, "J"));
        else if(i == 12)lista.push_back(std::make_pair(Boje::Karo, "Q"));
        else if(i == 13)lista.push_back(std::make_pair(Boje::Karo, "K"));
        else if(i == 14)lista.push_back(std::make_pair(Boje::Karo, "A"));
    }
    return lista;
}
void IzbaciKarte (std::list<std::pair<Boje, std::string>> &spil, std::multimap<Boje, std::string> &za_izbaciti){
    int brojac = 0;
    for(auto it = spil.begin(); it != spil.end(); it++){
        brojac++;
    }
    if (brojac > 52) throw std::logic_error("Neispravna lista!");
    
    for(auto it = za_izbaciti.begin(); it != za_izbaciti.end(); it++){
        for(auto na_spil = spil.begin(); na_spil != spil.end(); na_spil++){
            if(it -> first == na_spil -> first && it ->second == na_spil-> second){
                na_spil = spil.erase(na_spil);
                za_izbaciti.erase(it);
            }
        }   
    }
}

std::queue<std::pair<Boje, std::string>> IzbaciKarteRazbrajanjem(std::list<std::pair<Boje, std::string>> &spil, const short int r, const int &b){
    if(r < 1 || r > 52 || b < 1)throw std::logic_error("Neispravni elementi za izbacivanje!");
    int broj_u_listi = 0;
    for(auto it = spil.begin(); it != spil.end(); it++){
        broj_u_listi++;
    }
    if(broj_u_listi > 52)throw std::logic_error("Neispravna lista!");
    
    std::queue<std::pair<Boje, std::string>> red;
    
    int brojac = 0;
    for(auto it = spil.begin(); it != spil.end(); it ++){
        if(brojac == b)break;
        if(brojac > 0)it--;
        int pomocni = 0;
       
        while(pomocni != r || it != spil.end()){
            it++;
             pomocni++;
            if(it == spil.end() && pomocni != r)it = spil.begin();
           
            if(pomocni == r || it == spil.end()) break;
        }
        if(it != spil.begin()) {
            it--;
            red.push(std::make_pair(it -> first, it -> second));
            it = spil.erase(it);
        }
        
        else{
            
        red.push(std::make_pair(spil.end() -> first, spil.end() -> second));
        it = spil.erase(it);
        }
       // it++;
        brojac++;
        if(it == spil.end() && brojac != b)it = spil.begin();
        if(brojac == b) break;
    }
    return red;
}

void VratiPrvihNKarata (std::list<std::pair<Boje, std::string>> &spil, std::queue<std::pair<Boje, std::string>> &red, int n){
     if(n < 0 || n > 52)throw std::domain_error("Broj n je besmislen!");
    if(n > red.size())throw std::range_error("Nedovoljno karata u redu!");
    
     int broj_u_listi = 0;
    for(auto it = spil.begin(); it != spil.end(); it++){
        broj_u_listi++;
    }
    if(broj_u_listi > 52)throw std::logic_error("Neispravna lista!");
   
   for(auto it = spil.begin(); it != spil.end(); it++){
       if(it -> second == "10") it -> second = "a";
       if(it -> second == "J") it -> second = "b";
       else if(it -> second == "Q") it -> second = "c";
       else if(it -> second == "K") it -> second = "d";
       else if(it -> second == "A") it -> second = "e";
   }
  
   
   for(int i = 0; i < red.size(); i++){
    if (red.front().second == "10")red.front().second ="a";
       else if(red.front().second == "J") red.front().second = "b";
       else if(red.front().second == "Q") red.front().second = "c";
       else if(red.front().second == "K") red.front().second = "d";
       else if(red.front().second == "A") red.front().second = "e";
       std::pair<Boje, std::string>pomocni = red.front();
       red.push(pomocni);
       red.pop();
   }
   
  
   int brojac = 0;
   
   while( brojac != n){
       for(auto karte = spil.begin(); karte != spil.end(); karte++){
            if(red.front().first == karte -> first){
               
                while(karte != spil.end() && ((karte -> first == red.front().first )&& ((karte -> second ) < (red.front().second )))){karte++;}
                spil.insert(karte, red.front());
                break;
            }
           
        }
        
    red.pop();
     
    brojac++;
    if(brojac == n || red.empty()) break;
 
   }

     for(auto it = spil.begin(); it != spil.end(); it++){
      if(it -> second =="a")it -> second ="10";
      if(it -> second == "b") it -> second = "J";
      if(it -> second == "c") it -> second = "Q";
      if(it -> second == "d") it -> second = "K";
      if(it -> second == "e") it -> second = "A";
  }
  
}

int main(){
    std::cout<<"Unesite korak razbrajanja: ";
     short int korak;
    std::cin >> korak;
    std::cout<< "Unesite broj karata koje zelite izbaciti: ";
     int broj_karata;
    std::cin >> broj_karata;
    try{
        std::list<std::pair<Boje, std::string>> lista;
        lista = KreirajSpil();
        std::queue<std::pair<Boje, std::string>> red = IzbaciKarteRazbrajanjem(lista, korak, broj_karata);
        std::cout <<"U spilu trenutno ima " << 52 - broj_karata << " karata, i to:";
        std::cout <<std::endl;
       
        auto it1 = lista.begin();
        
     
            std::cout <<"\nPik: ";
            while(it1 -> first == Boje::Pik || it1 != lista.end()){
                std::cout<< it1 -> second << " ";
                it1++;
                if(it1 -> first != Boje::Pik || it1 == lista.end())break;
            }
            
         
            std::cout <<"\nTref: ";
            while(it1 ->first == Boje::Tref || it1 != lista.end()){
                std::cout<< it1 -> second << " ";
                it1++;
                if(it1 -> first != Boje::Tref || it1 == lista.end())break;
            }
            
         
            std::cout <<"\nHerc: ";
            while(it1 -> first == Boje::Herc || it1 != lista.end()){
                std::cout<< it1 -> second << " ";
                it1++;
                if(it1 -> first != Boje::Herc || it1 == lista.end())break;
            }
           
         
            std::cout <<"\nKaro: ";
            while(it1 -> first == Boje::Karo || it1 != lista.end()){
                std::cout<< it1 -> second << " ";
                it1++;
                if(it1 -> first != Boje::Karo || it1 == lista.end())break;
            }
           // it++;
           // if( it == lista.end())break;
       std::cout<<std::endl;
        std::cout<<"Unesite broj karata koje zelite vratiti u spil: ";
        int za_vracanje;
        std::cin >> za_vracanje;
        VratiPrvihNKarata(lista,red, za_vracanje);
        std::cout<<"U spilu trenutno ima "<< 52 - broj_karata + za_vracanje <<" karata, i to:";
        
           auto it = lista.begin();
             std::cout <<"\nPik: ";
             
             //kopirano iz prethodnog dijela za ispis
             
            while(it -> first == Boje::Pik || it != lista.end()){
                std::cout<< it -> second << " ";
                it++;
                if(it -> first != Boje::Pik || it == lista.end())break;
            }
            
         
            std::cout <<"\nTref: ";
            while(it ->first == Boje::Tref || it != lista.end()){
                std::cout<< it -> second << " ";
                it++;
                if(it -> first != Boje::Tref || it == lista.end())break;
            }
            
         
            std::cout <<"\nHerc: ";
            while(it -> first == Boje::Herc || it != lista.end()){
                std::cout<< it -> second << " ";
                it++;
                if(it -> first != Boje::Herc || it == lista.end())break;
            }
           
         
            std::cout <<"\nKaro: ";
            while(it -> first == Boje::Karo || it != lista.end()){
                std::cout<< it -> second << " ";
                it++;
                if(it -> first != Boje::Karo || it == lista.end())break;
            } 
        
    }
    catch(std::domain_error izuzetak){
        std::cout <<"Izuzetak: "<< izuzetak.what()<<std::endl;
    }
     catch(std::logic_error izuzetak){
        std::cout <<"Izuzetak: "<< izuzetak.what()<<std::endl;
    }
     catch(std::range_error izuzetak){
        std::cout <<"Izuzetak: "<< izuzetak.what()<<std::endl;
    }
    return 0;
}