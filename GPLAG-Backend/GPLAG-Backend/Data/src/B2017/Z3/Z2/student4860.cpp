/B2017/2018: Zadaća 3, Zadatak 2
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <tuple>
#include <cctype>
#include <set>
#include <stdexcept>
#include <iterator>

typedef std::map<std::string, std::vector<std::string>> Knjiga;

typedef std::set<std::tuple<std::string, int, int>> SetTuplovaT;

typedef std::map<std::string, SetTuplovaT> IndeksPojmovaT;


bool is_alnum(char z)
{
    z = std::tolower(z);
    return ('a' <= z && z <= 'z') || ('A' <= z && z <= 'Z') || ('0' <= z && z <= '9');
}

IndeksPojmovaT KreirajIndeksPojmova(const Knjiga& knjiga)
{
    IndeksPojmovaT ip;
    for(const auto& p : knjiga){
        for(std::size_t k = 0; k < p.second.size(); ++k){
            const auto& tekst = p.second[k];
            for(std::size_t i = 0; i < tekst.size(); ++i){
                bool razmak = true;
                if(!is_alnum(tekst[i])){
                    razmak = true;
                }
                else if (razmak){
                    razmak = false;
                    auto pocetak = i;
                    while(i < tekst.size() && is_alnum(tekst[i])){
                        ++i;
                    }
                    auto rijec = tekst.substr(pocetak, i - pocetak);
                    for(char& e : rijec){
                        e = std::tolower(e);
                    }
                    
                    auto it = ip.find(rijec);
                    if(it == ip.end()){
                        ip[rijec] = SetTuplovaT{std::tuple<std::string, int, int>{p.first, k + 1, pocetak} };
                    }
                    else{
                        it->second.insert(std::make_tuple(p.first, k + 1, pocetak));
                    }
                }
                
            }
        }
    }
    return ip;
}


SetTuplovaT PretraziIndeksPojmova(std::string rijec, const IndeksPojmovaT& ip)
{
    for(char& e : rijec){
        e = std::tolower(e);
    }
    const auto p = ip.find(rijec);
    if(p == ip.end()){
        throw std::logic_error("Pojam nije nadjen");
    }
    return p->second;
}

void IspisiIndeksPojmova(const IndeksPojmovaT& ip)
{
    for(const auto& e : ip){
        std::cout << e.first << ": ";
        const auto kraj = e.second.end();
        const auto prije_kraja = std::prev(kraj);
        
        for(auto it = e.second.begin(); it != kraj; ++it){
            if(it == prije_kraja){
                std::cout << std::get<0>(*it) << '/' << std::get<1>(*it) << '/' << std::get<2>(*it);
            }
            else{
                std::cout << std::get<0>(*it) << '/' << std::get<1>(*it) << '/' << std::get<2>(*it) << ", ";
            }
        }
        std::cout << '\n';
    }
}


int main ()
{
    std::cout << "Unesite naziv poglavlja: ";
    std::string ime_poglavlja;
    std::getline(std::cin, ime_poglavlja);
    Knjiga k;
    std::vector<std::string> str;
    if(ime_poglavlja != "."){
        for(int i = 1; ; ++i){
            std::cout << "Unesite sadrzaj stranice " << i << ": ";
            std::string stranica;
            std::getline(std::cin, stranica);        
            if(stranica == "."){
                i = 0;
                k.emplace(std::move(ime_poglavlja), std::move(str));
                str.clear();
                std::cout << "Unesite naziv poglavlja: ";            
                std::getline(std::cin, ime_poglavlja);
                if(ime_poglavlja == "."){
                    break;
                }
            }
            else{
                str.push_back(std::move(stranica));
            }
        }
    }
    
    std::cout << "\nKreirani indeks pojmova:\n";
    const auto ip = KreirajIndeksPojmova(k);
    IspisiIndeksPojmova(ip);
    std::cout << '\n';
    
    for(;;){
        std::cout << "Unesite rijec: ";
        std::string rijec;
        std::getline(std::cin, rijec);        
        if(rijec == "."){
            break;
        }
        try {
            const SetTuplovaT set = PretraziIndeksPojmova(rijec, ip);
            for(const auto& e : set){
                std::cout << std::get<0>(e) << '/' << std::get<1>(e) << '/' << std::get<2>(e) << ' ';
            }
        }
        catch (std::logic_error e) {
            std::cout << "Unesena rijec nije nadjena!";
        }
        std::cout << '\n';
    }
    
    
	return 0;
}
