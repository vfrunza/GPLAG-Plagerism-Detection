/B2017/2018: Zadaća 3, Zadatak 2
#include <iostream> 
#include <map>
#include <set>
#include <tuple>
#include <vector> 
typedef std::map<std::string, std::vector<std:: string>> Knjiga;
typedef std::map<std::string, std::set<std::tuple<std::string, int, int>>> mapa;
bool domen (int p, std::string s ){
    return (s.at(p)>= 'A' && s.at(p) <= 'Z' ) || (s.at(p)>='a' && s.at(p) <='z'); 
}
void pretvoriUmala (std::string &s){
    for (int i=0; i<s.size(); i++){
        if (s.at(i)>= 'A' && s.at(i) <= 'Z') s.at(i)+='a' - 'A';
    }
}
bool rijec (std::string rijec) {
    for (int i=0; i<rijec.size(); i++){
        if (!domen(i, rijec)) return false;
    }
    return true;
}


void obradiStranicu (int broj, std::string poglavlje, std::string str, mapa &Mapa) {
 
    for (int i=0; i<str.size(); i++){
        for (int j=1; j<=str.size()-i; j++){
            auto pomocna (str.substr (i, j));
            bool pocetak(false), kraj(false); 
            if (i==0 || !domen(i-1, str)) pocetak = true; 
            if (i+j==str.size() || !domen(i+j, str)) kraj = true; 
            if (pocetak && kraj && rijec(pomocna)) {
               // if (i==35) std::cout<< "*" << i; 
            pretvoriUmala (pomocna);
            auto it (Mapa.find(pomocna));
            if (it == Mapa.end()) {
            Mapa[pomocna] = {std::make_tuple(poglavlje, broj, i)};
            }
            else {
            Mapa[pomocna].insert(std::make_tuple(poglavlje, broj, i));
            }
            }
        }
    }
}


mapa KreirajIndeksPojmova (Knjiga k ){
    mapa Mapa; 
    for (auto it = k.begin(); it != k.end(); it++){
        int i(1); 
        for (auto str : it->second){
            obradiStranicu(i, it->first,  str, Mapa);
            i++; 
        }
    }
    return Mapa;
    
}

std::set<std::tuple<std::string, int, int>>  PretraziIndeksPojmova (std::string rijec, mapa &m){
    auto it (m.find(rijec) );
    if (it == m.end()) throw std::logic_error ("Pojam nije nadjen");
    return it->second; 
}

void IspisiIndeksPojmova (const mapa &m) {
    for (auto it= m.begin(); it!= m.end(); it++){
        std::cout<<it->first<<": "; 
        int i(1);
        for (auto x : it->second){
            std::cout << std::get<0>(x) << "/" << std::get<1>(x) <<"/" << std::get<2>(x);  
            if (i!=(it->second).size()) std::cout<<", ";
           
            i++;
        }
          std::cout<<"\n";
    }
}



int main ()
{
    Knjiga k;
    // k["I"] = {"abc qwe stsda abc abc dhi qwe hrkw dhi"};
    // IspisiIndeksPojmova (KreirajIndeksPojmova(k)); 
    for ( ; ;) {
        std::string poglavlje;
        std::cout<<"Unesite naziv poglavlja: "; 
        std::cin>>poglavlje; 
        if (poglavlje==".") break;
        std::cin.ignore(1000, '\n'); 
        int i(1);
        std::vector<std::string> v; 
        for (; ;) {
            std::cout<<"Unesite sadrzaj stranice "<<i<<": ";
            std::string stranica;
            std::getline (std::cin, stranica);
         //   std::cin.ignore(1000, '\n'); 
            if (stranica==".") break; 
            i++;
            v.push_back(stranica); 
            k [poglavlje] = v; 
        }
    }
    std::cout<<"\nKreirani indeks pojmova:\n";
    auto m (KreirajIndeksPojmova(k));
    IspisiIndeksPojmova (m);
  //  std::cout<<"\n"; 
    for ( ;; ){
        std::string rijec;
        std::cout<<"Unesite rijec: ";
        std::cin>>rijec;
        if (rijec == ".") break;
        std::cin.ignore(1000,'\n');
        try { 
        auto x (PretraziIndeksPojmova (rijec, m));
        for (auto y : x) std::cout << std::get<0>(y) << "/" << std::get<1>(y) <<"/" << std::get<2>(y)<<" "; 
        std::cout<<"\n";
        }
        catch (...){
            std::cout<<"Unesena rijec nije nadjena!\n"; 
        }
    }  
	return 0;
}
