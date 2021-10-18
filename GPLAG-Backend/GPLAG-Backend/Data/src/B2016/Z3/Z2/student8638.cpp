/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <stdexcept>
#include <algorithm>
#include <vector>

std::vector<std::string> IzdvojiRijeci(std::string str){
    std::vector<std::string> vek;
    std::string::size_type temp=0, kraj;
    
    do{
        kraj = str.find(' ', temp);
        if(kraj == std::string::npos){
            kraj = str.size();
        }
        vek.push_back(str.substr(temp, kraj - temp));
        temp = kraj + 1;
    } while(temp < str.size());
    
    return vek;
}

std::set<int> Pozicija(std::string str, std::vector<std::string> vek){
    std::set<int> tivra;
    int brojac_slova=0;
    
    for(int i=0; i<vek.size(); i++){
        if(str == vek[i]){
            tivra.insert(i+brojac_slova);
        }
        brojac_slova += vek[i].size();
    }
    return tivra;
}

bool Ima_li_ga(std::map <std::string, std::set <int>> mapa, std::string str){
    bool tivra = false;
    for(auto it = mapa.begin(); it != mapa.end(); it++){
        if(it->first == str){
            tivra = true;
            break;
        }
    }
    return tivra;
}

std::map <std::string, std::set <int>> KreirajIndeksPojmova(std::string str){
    std::map <std::string, std::set <int>> tivra;
    std::string tekst;
    tekst = str;
    std::transform(tekst.begin(), tekst.end(), tekst.begin(), ::tolower);
    
    std::vector<std::string> vek = IzdvojiRijeci(tekst);
    
    for(int i=0; i<vek.size(); i++){
        if(Ima_li_ga(tivra,vek[i]) == false){
            tivra.insert(std::pair <std::string, std::set<int>> (vek[i], Pozicija(vek[i], vek)) );
        }
    }
    
    return tivra;
}


std::set<int> PretraziIndeksPojmova(std::string str, std::map <std::string, std::set <int>> mapa){
    
    std::set<int> tivra;
    bool nisam_naso(false);
    
    for(auto it1 = mapa.begin(); it1 != mapa.end(); it1++){
        if(str == it1 -> first){
            tivra = it1 -> second;
            nisam_naso = true;
        } 
    }
    
    
   if(nisam_naso == false) throw std::logic_error("Pojam nije nadjen");
   
   else return tivra;
}


void IspisiIndeksPojmova (std::map <std::string, std::set <int>> mapa){
    
    for(auto it1 = mapa.begin(); it1 != mapa.end(); it1++){
        std::cout << it1 -> first <<": ";
        for(auto x = (it1->second).begin() ; x != (it1->second).end(); x++) {
            if(x == prev((it1->second).end())) std::cout << *x;
            else std::cout << *x << ",";
        }
        std::cout << std::endl;
    }
}

int main (){
    
    
    std::cout << "Unesite tekst: ";
    std::string tekst;
    std::cin.clear();
    std::getline(std::cin, tekst);
    
    std::map <std::string, std::set <int>> mapa;
    mapa = KreirajIndeksPojmova(tekst);
    
    IspisiIndeksPojmova(mapa);
    
    std::cout << "Unesite rijec: ";
    std::string rijec;
    std::cin.clear();
    std::getline(std::cin, rijec);
    
    while(rijec!= "."){
        try{
        std::set<int> indeksi;
        indeksi = PretraziIndeksPojmova(rijec, mapa);
        for(auto x : indeksi) std::cout << x << " ";
        std::cout << std::endl;
        }
        catch(std::logic_error e1){
            std::cout << "Unesena rijec nije nadjena!" << std::endl;
        }
        std::cout << "Unesite rijec: ";
        rijec.clear();
        std::getline(std::cin, rijec);
    }
    
	return 0;
}