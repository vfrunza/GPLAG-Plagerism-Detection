/B2017/2018: Zadaća 3, Zadatak 2
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <tuple>
#include <stdexcept>

typedef std::map<std::string, std::vector<std::string>> Knjiga;

std::map<std::string, std::set<std::tuple<std::string, int, int>>> KreirajIndeksPojmova(Knjiga a){
    std::map<std::string, std::set<std::tuple<std::string, int, int>>> indeks;
    // treba proci kroz knjigu a i sad ubaciti svaku rijec u mapu indeks i to s oznakom poglavlja to je ova kljucna rijec kod tipa knjiga i 
    //broj stranice to je indeks koji je element ovog vektora, a broj poicije je brojac ono iteratora kako prolazi kroz stringove iz ovog vektora iz tipa kNjige...
   for(auto it = a.begin(); it!=a.end(); it++){                     // ide kroz poglavlje po poglavlje
       for(int i=0; i<(it->second).size(); i++){                    // ide kroz stranicu po stranicu poglavlja
            for(int j=0; j<(it->second)[i].size(); j++){             // ide kroz sve karaktere na jednoj stranici
                std::string rijec;
                while(j<(it->second).size() && (it->second)[i][j]==0 )j++; // razmake
                int zapamti(j);
                while(j<(it->second).size() && ((it->second)[i][j]>=48 && (it->second)[i][j]<=57) || ((it->second)[i][j]>=65 && (it->second)[i][j]<=90) || ( (it->second)[i][j]>=97 && (it->second)[i][j]<=122 )){
                    rijec.push_back((it->second)[i][j]);
                    j++;
                }
                //indeks.insert(rijec, std::set<std::tuple<std::string, int, int>> (std::make_tuple(it->first, i, zapamti) ) );
                for(int z=0; z<rijec.size(); z++){
                    if(rijec[z]>=65 && rijec[z]<=90)rijec[z]+='a'-'A';
                }
                indeks[rijec].insert(std::make_tuple(it->first, i+1, zapamti));
            }
        }
   }
    return indeks;
}

std::set<std::tuple<std::string, int, int>> PretraziIndeksPojmova(std::string rijec, std::map<std::string, std::set<std::tuple<std::string, int, int>>> indeks_pojmova){
    auto it(indeks_pojmova.find(rijec));
    if(it==indeks_pojmova.end())throw std::logic_error("Pojam nije nadjen");
    else return it->second; 
}

void IspisiIndeksPojmova (std::map<std::string, std::set<std::tuple<std::string, int, int>>> indeks_pojmova){
    for(auto it=indeks_pojmova.begin(); it!=indeks_pojmova.end(); it++){
        std::cout << it->first << ":";
        for(auto it2=(it->second).begin(); it2!=(it -> second).end(); it2++){
            std::cout << " " << std::get<0>(*it2) << "/" << std::get<1>(*it2) << "/" << std::get<2>(*it2);
            if(it2!=--(it->second).end()) std::cout << ",";
        }
        std::cout << "\n";
    }
}

int main ()
{
    Knjiga knjiga;
    for(;;){
        std::cout << "Unesite naziv poglavlja: ";
        std::string naziv_poglavlja;
        std::getline(std::cin, naziv_poglavlja);
        if(naziv_poglavlja==".")break;
        
        for(int i=1; ; i++){
            std::cout << "Unesite sadrzaj stranice " << i << ": ";
            std::string pomocna;
            std::getline(std::cin, pomocna);
            if(pomocna==".")break;
            knjiga[naziv_poglavlja].push_back(pomocna);
        }
    }
    std::cout << "\nKreirani indeks pojmova:\n"; 
    auto indeks_pojmova(KreirajIndeksPojmova(knjiga));
    /*for(auto it=indeks_pojmova.begin(); it!=indeks_pojmova.end(); it++){
        std::cout << it->first << ":";
        for(auto x : it->second){
            std::cout << " " << std::get<0>(x) << "/" << std::get<1>(x) << "/" << std::get<2>(x);
        }
        std::cout << "\n";
    }*/
    IspisiIndeksPojmova(indeks_pojmova);
    
    for(;;){
        std::cout << "\nUnesite rijec: ";
        std::string rijec;
        std::getline(std::cin, rijec);
        if(rijec==".")break;
        try{
            auto pozicije (PretraziIndeksPojmova(rijec, indeks_pojmova));
            for(auto it=pozicije.begin(); it!=pozicije.end(); it++){
                std::cout << std::get<0>(*it) << "/" << std::get<1>(*it) << "/" << std::get<2>(*it); 
                if(it!=--(pozicije.end())) std::cout << " ";
            }
        }
        catch(std::logic_error){
            std::cout << "Unesena rijec nije nadjena!";
            continue;
        }
    }
	return 0;
}
