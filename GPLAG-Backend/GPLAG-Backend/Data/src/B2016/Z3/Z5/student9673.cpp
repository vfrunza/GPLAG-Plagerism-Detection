/B2016/2017: Zadaća 3, Zadatak 5
#include <iostream>
#include <string>
#include <new>
#include <set>
#include <vector>
#include <stdexcept>

struct Dijete{
    std::string ime;
    Dijete *sljedeci = nullptr;
};

Dijete *NapraviListu(std::vector<std::string> v){
    int n(0);
    Dijete *pocetak(nullptr), *prosli(nullptr);
    
    while(n != v.size()){
        Dijete *novi = new Dijete;
        novi -> ime = v[n++]; novi -> sljedeci = nullptr;
        if(!pocetak) pocetak = novi;
        else prosli -> sljedeci = novi;
        prosli = novi;
    }
    prosli -> sljedeci = pocetak;
    return pocetak;
}

void UnistiListu(Dijete *pocetak) {
        Dijete *novi(pocetak);
        while (novi != nullptr) { novi = pocetak -> sljedeci; delete pocetak; pocetak = novi; }
    }

bool SlovoIliBroj(char znak){
    return (((znak>='a' && znak<='z') || (znak>='A' && znak<='Z')) || (znak>='0' && znak<='9'));
}

int BrojSlova(std::string s){
    int brojac(0);
    for(int i = 0; i < s.length(); i++) if(SlovoIliBroj(s[i])) brojac++;
    return brojac;
}

bool ProvjeriTimove(std::vector<std::set<std::string>> &timovi, std::vector<int> &velicine){
    for(int i = 0; i < timovi.size(); i++) if(timovi[i].size() != velicine[i]) return false;
    return true;
}

std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> s, const int k){
    if(k < 1 || k > s.size()) throw std::logic_error("Razvrstavanje nemoguce");
    
    Dijete *lista(nullptr), *prosli(nullptr), *kraj(nullptr);
    std::vector<std::set<std::string>> timovi(k);
    std::vector<int> velicine(k);
    int n(s.size()), v(n%k), t(0), krug(0);

    for(int i = 0; i < velicine.size(); i++) { if(i < v) velicine[i] = n/k + 1; else velicine[i] = n/k; }
    
    try{
        lista = NapraviListu(s);
        kraj = lista;
        for(int i = 0; i < s.size() - 1; i++) kraj = kraj -> sljedeci; 
    }
    catch(std::bad_alloc()){
        UnistiListu(lista);
        throw std::bad_alloc();
    }
    
    while(1){
        if(timovi[0].size() == 0) { 
            timovi[0].insert(lista -> ime); 
            krug = BrojSlova(lista -> ime) - 1; 
            kraj -> sljedeci = lista -> sljedeci; 
            delete lista; 
            lista = kraj -> sljedeci;
        }
        if(timovi[t].size() == velicine[t]) t++;
        
        int i(0);
        while(i < krug){ 
            lista = lista -> sljedeci; 
            i++;
        }
        
        auto pomocni (lista -> sljedeci);
        while (pomocni != lista) { prosli = pomocni; pomocni = pomocni -> sljedeci;}

        timovi[t].insert(lista -> ime); 
        if(ProvjeriTimove(timovi, velicine)) { delete lista; break; }  
        
        krug = BrojSlova(lista -> ime) - 1; 
        prosli -> sljedeci = lista -> sljedeci;
        delete lista;
        lista = prosli -> sljedeci;
    }
    
    return timovi;
} 


int main ()
{
    std::vector<std::string> s(0); 
    int n(0), br(0);
    
    std::cout << "Unesite broj djece: ";
    std::cin >> n; s.resize(n);
    
    std::cin.ignore(1000, '\n');
    std::cout << "Unesite imena djece: " << std::endl;
    for(int i = 0; i < n; i++) std::getline(std::cin, s[i]);
    
    std::cout << "Unesite broj timova: "; std::cin >> br;
    
    try{
        auto timovi (Razvrstavanje(s, br)); 
        for(int i = 0; i < timovi.size(); i++){
            std::cout << "Tim " << i+1 << ": ";
            for(auto it = timovi[i].begin(); it != timovi[i].end(); it++){
                auto kraj = timovi[i].end(); kraj--; 
                if(it != kraj) std::cout << *it << ", "; 
                else std::cout << *it;}
            std::cout << std::endl;
        }
    }
    catch(std::logic_error e){
        std::cout << "Izuzetak: " << e.what() << std::endl;
    }
    catch(std::bad_alloc()){
        
    }
	return 0;
}