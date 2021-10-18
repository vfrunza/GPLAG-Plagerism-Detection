#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <stdexcept>
#include <memory>

int BrojSlova(std::string s) {
    int br(0);
    for(int i=0; i<s.length(); i++) 
        if ((s[i] >='A' && s[i] <='Z')||(s[i] >='0' && s[i] <='9')||(s[i] >='a' && s[i] <='z')) br++;
        
    return br;
}

struct Dijete {
    std::string ime;
    std::shared_ptr<Dijete> sljedeci;
};

std::vector<std::set<std::string>> Razvrstavanje ( std::vector<std::string> imena, int br_timova) {
    
     if(br_timova<1 || br_timova > imena.size()) throw std::logic_error("Razvrstavanje nemoguce");
     std::vector<int> v1;
     std::vector<std::set<std::string>> v;
     
    int br_prvi (imena.size() % br_timova);
    int br_clan1 (imena.size()/br_timova + 1); 
    int br_drugi (br_timova - imena.size() % br_timova); 
    int br_clan2 (imena.size()/br_timova);
    
    for(int i=0; i<br_prvi; i++) v1.push_back(br_clan1);
    for(int i=0; i<br_drugi; i++) v1.push_back(br_clan2);
    int br_slova(0);
    
    std::shared_ptr <Dijete> pocetak(nullptr), prethodni;
    
    for(int i=0; i < imena.size(); i++) {
        std::shared_ptr<Dijete> novi (new Dijete);
        novi->ime = imena[i]; 
        novi->sljedeci = nullptr;
        if(!pocetak) pocetak = novi;
        else prethodni->sljedeci = novi; 
  
        prethodni = novi;
    }
    prethodni->sljedeci = pocetak;

    auto it = pocetak; 

    auto tmp = pocetak;
    int br = 0;
    
    for(int i=0; i < br_timova; i++) {
        std::set<std::string> skup;
        
        for(int j=0; j< v1[i]; j++) {
            if(br < imena.size()-1) {
            skup.insert(pocetak->ime);
            br++;
            br_slova = (BrojSlova(pocetak->ime));
            tmp = (pocetak->sljedeci);
         pocetak = nullptr;
            pocetak = tmp; 
         prethodni->sljedeci = pocetak;
      
            for(int k=0; k<br_slova-1; k++) {
                prethodni = pocetak;

                pocetak = pocetak->sljedeci;
            }
        }
        else if (br == imena.size()-1) {
                skup.insert(pocetak->ime);
                pocetak->sljedeci = nullptr;
             pocetak = nullptr;
           }
        }
           v.push_back(skup);
    }
    return v;
}

int main ()
{
     try {
    int br_djece;
    std::cout <<"Unesite broj djece: ";
    std::cin >> br_djece;
    std::cin.ignore(100, '\n');
    
    std::vector<std::string> imena;
    std::cout << "Unesite imena djece: ";
    
    for(int i=0; i<br_djece; i++) {
        std::string ime;
        std::getline(std::cin, ime);
        imena.push_back(ime);
    }
    
        int br_timova;
    std::cout << "\nUnesite broj timova: ";
    std::cin >> br_timova;
    
    auto v = Razvrstavanje(imena, br_timova);
    
    for(int i=0; i<v.size(); i++) {
        std::cout << "Tim " << i+1 <<": ";
         auto pomocni = (v[i].end());
         pomocni--;
        for(auto it = v[i].begin(); it != v[i].end(); it++) {
            std::cout << *it ;
           if(it != pomocni) std::cout << ", ";
        }
std::cout << std::endl;
    }
    } catch(std::logic_error izuzetak) {
        std::cout <<"Izuzetak: " << izuzetak.what();
    }
    
	return 0;
}