/B2017/2018: Zadaća 3, Zadatak 2
#include <iostream>

#include <tuple>
#include <vector>
#include <set>
#include <map>

typedef std::map<std::string, std::vector<std::string>> Knjiga;
typedef std::set<std::tuple<std::string, int, int>> InstancePojma;
typedef std::map<std::string, InstancePojma> IndeksPojmova;

bool isPartOfWord(char);
std::string tolower(std::string);

IndeksPojmova KreirajIndeksPojmova(const Knjiga&);
InstancePojma PretraziIndeksPojmova(std::string, const IndeksPojmova&);
void IspisiIndeksPojmova(const IndeksPojmova&);

int main ()
{
    Knjiga knjiga;
    
    while (true) {
        std::string nazivPoglavlja;
        std::cout << "Unesite naziv poglavlja: ";
        std::getline(std::cin, nazivPoglavlja);
        if (nazivPoglavlja == ".")
            break;
        
        for (int i = 1; true; i++) {
            std::string stranica;
            std::cout << "Unesite sadrzaj stranice " << i << ": ";
            std::getline(std::cin, stranica);
            if (stranica == ".")
                break;
            
            knjiga[nazivPoglavlja].push_back(stranica);
        }
    }
    
    auto index(KreirajIndeksPojmova(knjiga));
    
    std::cout << std::endl;
    std::cout << "Kreirani indeks pojmova:" << std::endl;
    IspisiIndeksPojmova(index);
    
    std::cout << std::endl;
    while (true) {
        std::string rijec;
        std::cout << "Unesite rijec: ";
        std::cin >> rijec;
        if (rijec == ".")
            break;
        
        try {
            auto instance = PretraziIndeksPojmova(rijec, index);
            for (const auto &instanca : instance)
                std::cout << std::get<0>(instanca) << "/"
                    << std::get<1>(instanca) << "/"
                    << std::get<2>(instanca) << " ";
            std::cout << std::endl;
        }
        catch(...) {
            std::cout << "Unesena rijec nije nadjena!" << std::endl;
        }
    }
    
	return 0;
}

IndeksPojmova KreirajIndeksPojmova(const Knjiga &knjiga)
{
    IndeksPojmova res;
    
    for (auto poglavlje : knjiga)
        for (int i = 0; i < poglavlje.second.size(); i++) {
            std::string rijec{""};
            bool nijeRijec(true);
            
            for (int j = 0; j < poglavlje.second[i].length(); j++) {
                char znak = poglavlje.second[i][j];
                bool jeLiKraj = j == poglavlje.second[i].length() - 1;
                
                if (isPartOfWord(znak)) {
                    nijeRijec = false;
                    rijec += znak;
                }
                if ((!isPartOfWord(znak) || jeLiKraj) && !nijeRijec) {
                    nijeRijec = true;
                    res[tolower(rijec)].insert(
                        std::make_tuple(poglavlje.first, i + 1, j - rijec.length() + jeLiKraj)
                    );
                    rijec = "";
                }
            }
        }
        
    return res;
}

InstancePojma PretraziIndeksPojmova(std::string pojam, const IndeksPojmova &index)
{
    auto nadjeno = index.find(tolower(pojam));
    
    if (nadjeno == index.end())
        throw std::logic_error("Pojam nije nadjen");
        
    return nadjeno->second;
}

void IspisiIndeksPojmova(const IndeksPojmova &index)
{
    for (const auto& pojam : index)
    {
        std::cout << pojam.first << ": ";
        for (const auto& instanca : pojam.second)
            std::cout << (instanca == *pojam.second.begin() ? "" : ", ")
                << std::get<0>(instanca) << "/"
                << std::get<1>(instanca) << "/"
                << std::get<2>(instanca);
                
        std::cout << std::endl;
    }
}

bool isPartOfWord(char c)
{
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9');
}

std::string tolower(std::string str)
{
    std::string res{""};
    for (char c : str)
        res += std::tolower(c);
        
    return res;
}