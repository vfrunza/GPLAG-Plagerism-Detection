/B2016/2017: Zadaća 3, Zadatak 6
// pametni samo isto sve
#include <iostream>
#include <vector>
#include <set>
#include <list>
#include <stdexcept>
#include <memory>

char toUpper(char c)
{
	if (c>='a' && c<='z')
		return c - ('a' - 'A'); // prebaci c u veliko i vrati
	return c; // ako nije bilo malo slovo, ostaje nepromjenjeno
}

int isSiliC(char c)
{
    if(c>='0' && c<='9') return true;
	c = toUpper(c);
	// vrati 1 ako je c slovo, 0 ako nije
	return c>='A' && c<='Z';
}

int duzinaprez(const std::string &s){
    int duzina(0);
    for(int i=0; i < s.size(); i++){
        if(isSiliC(s[i])) duzina++;
    }
    return duzina;
}

struct Dijete {
  std::string ime;
  std::shared_ptr<Dijete> sljedeci = nullptr;
};

std::vector<std::set<std::string>> Razvrstavanje(const std::vector<std::string> &vekt, int k){
    if(k < 1 || k > vekt.size()) throw std::logic_error("Razvrstavanje nemoguce");
    
    int prvitimovi = vekt.size()%k; // kolicina prvih
    int ostalitimovi = k - prvitimovi; // kolicina drugih
    
    int brojclanovaprvih = int(vekt.size())/k +1; // broj djece prvih
    int brojclanovadrugih = int(vekt.size())/k;  // broj djece drugih
    
    std::vector<std::set<std::string>> zaVratit(k);
    
    std::shared_ptr<Dijete> pocetak(nullptr), prethodni;
    try{
    for(int i=0; i < vekt.size(); i++){
        std::shared_ptr<Dijete> novi = std::make_shared<Dijete>();
        novi->ime = vekt[i];
        novi->sljedeci = nullptr;
        if(!pocetak) pocetak = novi;
        else prethodni->sljedeci = novi;
        prethodni = novi;
        novi = nullptr;
    }
    prethodni->sljedeci = pocetak;
    
    }catch(...){
        if(pocetak == nullptr) throw std::bad_alloc();
        std::shared_ptr<Dijete> pomocni;
            while (pocetak != nullptr) {
                pomocni = pocetak;
                pocetak = pocetak->sljedeci;
                pomocni = nullptr;
            }
        throw std::bad_alloc();
    }
    
    int brojdjece(0);
    int j(0);
    if(prvitimovi != 0){
    for(;;){
        if(j>=prvitimovi) break;
        if(brojdjece == brojclanovaprvih){
            j++;
            brojdjece =0;
        }
        if(j>=prvitimovi) break;
        zaVratit[j].insert(pocetak->ime);
        int duzina = duzinaprez(pocetak->ime);
        prethodni->sljedeci = pocetak->sljedeci;
        auto it2(pocetak);
        pocetak = pocetak->sljedeci;
        it2->sljedeci = nullptr;
        it2 = nullptr;
        
        int h(0);
        while(h < duzina -1){
            pocetak = pocetak->sljedeci;
            prethodni = prethodni->sljedeci;
            h++;
        }
        brojdjece++;
    }
    
    if(ostalitimovi == 0){ pocetak = nullptr; prethodni = nullptr; return zaVratit; }
    }
    brojdjece = 0;
    int z = 0;
    if(ostalitimovi !=0) {
    for(;;){
        if(z>=ostalitimovi) break;
        if(brojdjece == brojclanovadrugih){
            j++;
            z++;
            brojdjece =0;
        }
        if(z>=ostalitimovi) break;
        zaVratit[j].insert(pocetak->ime);
        int duzina = duzinaprez(pocetak->ime);
        prethodni->sljedeci = pocetak->sljedeci;
        auto it2(pocetak);
        pocetak = pocetak->sljedeci;
        it2->sljedeci = nullptr;
        it2 = nullptr;
        
        int h(0);
        while(h < duzina -1){
            if(pocetak != pocetak->sljedeci){
            pocetak = pocetak->sljedeci;
            prethodni = prethodni->sljedeci;
            }
            else {
                j++;
                z++;
                if(z>=ostalitimovi){
                    zaVratit[j-1].insert(pocetak->ime);
                    prethodni->sljedeci = nullptr;
                    pocetak->sljedeci = nullptr;
                    prethodni = nullptr;
                    pocetak = nullptr;
                    return zaVratit;
                }
                zaVratit[j].insert(pocetak->ime);
                prethodni->sljedeci = nullptr;
                pocetak->sljedeci = nullptr;
                prethodni = nullptr;
                pocetak = nullptr;
                return zaVratit;
            }
            h++;
        }
        brojdjece++;
    }
    }
    
    return zaVratit;
}


int main ()
{
    int x, y;
    std::vector<std::set<std::string>> a;
    std::cout << "Unesite broj djece: ";
    std::cin >> x;
    std::cout << "Unesite imena djece: " << std::endl;
    std::vector<std::string> imena(x);
    std::cin.ignore(10000, '\n');
    for(int i=0; i < x; i++) std::getline(std::cin, imena[i]);
    std::cout << "Unesite broj timova: ";
    std::cin >> y;
    try {
        a = Razvrstavanje(imena, y);
    }catch(std::logic_error exec){
        std::cout << "Izuzetak: " << exec.what();
        return 0;
    }catch(std::bad_alloc exec){
        return 0;
    }
    for(int i=0; i < y; i++){
        auto it2 = a[i].begin(); it2++;
        std::cout << "Tim " << i + 1 << ": ";
        for(auto it = a[i].begin(); it != a[i].end(); it++){
            if(it2 == a[i].end()) std::cout << *it;
            else std::cout << *it << ", ";
            it2++;
        }
        std::cout << std::endl;
    }
	return 0;
}