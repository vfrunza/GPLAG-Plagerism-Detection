/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <vector>
#include <set>
#include <list>
#include <stdexcept>

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

std::vector<std::set<std::string>> Razvrstavanje(const std::vector<std::string> &vekt, int k){
    if(k < 1 || k > vekt.size()) throw std::logic_error("Razvrstavanje nemoguce");
    
    int prvitimovi = vekt.size()%k; // kolicina prvih
    int ostalitimovi = k - prvitimovi; // kolicina drugih
    
    int brojclanovaprvih = int(vekt.size())/k +1; // broj djece prvih
    int brojclanovadrugih = int(vekt.size())/k;  // broj djece drugih
    
    std::vector<std::set<std::string>> zaVratit(k);
    std::list<std::string> prcaladija;
    for(int i=0; i < vekt.size(); i++) prcaladija.push_back(vekt[i]); // u red..
    
    int brojdjece(0);
    int j(0);
    auto pomocni = prcaladija.begin();
    for(auto it = prcaladija.begin(); it != prcaladija.end();){
        if(j >= prvitimovi) { pomocni = it; break; }
        if(brojdjece == brojclanovaprvih){
            j++;
            brojdjece = 0;
        }
        if(j >= prvitimovi) { pomocni = it; break; }
        if(it == prcaladija.end()) it = prcaladija.begin();
        zaVratit[j].insert(*it);
        int duzina = duzinaprez(*it);
        it = prcaladija.erase(it);
        if(it == prcaladija.end()) it=prcaladija.begin();
        int h(0);
        while(h < duzina-1){
            it++;
            if(it == prcaladija.end()) it = prcaladija.begin();
            h++;
        }
        brojdjece++;
    }
    
    brojdjece = 0;
    int z(0);
    for(auto it = pomocni; it != prcaladija.end();){
        if(z >= ostalitimovi) break;
        if(brojdjece == brojclanovadrugih){
            z++;
            j++;
            brojdjece = 0;
        }
        if(z >= ostalitimovi) break;
        if(it == prcaladija.end()) it = prcaladija.begin();
        zaVratit[j].insert(*it);
        int duzina = duzinaprez(*it);
        it = prcaladija.erase(it);
        if(it == prcaladija.end()) it=prcaladija.begin();
        int h(0);
        while(h < duzina -1){
            it++;
            if(it == prcaladija.end()) it = prcaladija.begin();
            h++;
        }
        brojdjece++;
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