/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <stdexcept>

// VRACA VEKTOR RIJECI POJEDINACNO IZ RECENICE
std::vector<std::string> RijeciPojedinacno (const std::string &recenica){
    std::vector<std::string> vektor_rijeci;
    for(int i=0; i<recenica.size(); i++){
        std::string tmp_rijec;
        while( (recenica[i]>='a' && recenica[i]<='z') || (recenica[i]>='0' && recenica[i]<='9') ){
            tmp_rijec.push_back(recenica[i]);
            i++;
        }
        if(tmp_rijec.size() > 0){
            vektor_rijeci.push_back(tmp_rijec);
        }
    }
    return vektor_rijeci;
}

// VRACA VEKTOR SA INDEXIMA POCETKA SVAKE RIJECI
std::vector<int> PozicijeRijeci (const std::string &recenica){
    std::vector<int> index_rijeci;
    if( (recenica[0]>='a' && recenica[0]<='z') || (recenica[0]>='0' && recenica[0]<='9') ){
        index_rijeci.push_back(0);
    }
    for(int i=1; i<recenica.size(); i++){
        if( ((recenica[i-1]>=32 && recenica[i-1]<=47) || (recenica[i-1]>=91 && recenica[i-1]<=96) || (recenica[i-1]>=123 && recenica[i-1]<=126)) && ((recenica[i]>='a' && recenica[i]<='z') || (recenica[i]>='0' && recenica[i]<='9')) ){
            index_rijeci.push_back(i);
        }
    }
 
    return index_rijeci;
}

std::map<std::string, std::set<int>> KreirajIndeksPojmova (std::string recenica){
    // transfomacija u MALA slova
    std::transform(recenica.begin(), recenica.end(), recenica.begin(), ::tolower);
    std::map<std::string, std::set<int>> mapa;
    
    //POZICIJE pojedinacno u VEKTORU
    std::vector<int> pozicija_rijeci = PozicijeRijeci(recenica);
    //RIJECI pojedinacno u VEKTORU
    std::vector<std::string> vektor_rijeci = RijeciPojedinacno(recenica);
    
    for(int i=0; i<vektor_rijeci.size(); i++){
        mapa[vektor_rijeci[i]].insert(pozicija_rijeci[i]);
    }
    return mapa;
}

std::set<int> PretraziIndeksPojmova (std::string rijec, std::map<std::string, std::set<int>> mapa){
    std::set<int> pozicije_rijeci;
    for(int i=0; i<rijec.size(); i++){
        if(rijec[i] == ' '){
            rijec.erase(i, 1);
        }
    }
    if(mapa.find(rijec) == mapa.end()){
        throw std::logic_error("Pojam nije nadjen");
    } else {
        for(auto it = mapa.find(rijec)->second.begin(); it != mapa.find(rijec)->second.end(); ++it){
            pozicije_rijeci.insert(*it);
        }
    }
    return pozicije_rijeci;
}

void IspisiIndeksPojmova (std::map<std::string, std::set<int>> mapa){
    for(auto it = mapa.begin(); it != mapa.end(); ++it){
        std::cout << it->first << ": ";
        for(auto it2 = it->second.begin(); it2 != it->second.end(); ++it2){
            if(it2 == ++it->second.end()){
                std::cout << *it2; 
                break;
            }
            std::cout << *it2 << ",";
        }
        std::cout << std::endl;
    }
}


int main (){
    std::string recenica;
	std::cout << "Unesite tekst: ";
	std::getline (std::cin, recenica);
	std::map<std::string, std::set<int>> mapa = KreirajIndeksPojmova(recenica);
	IspisiIndeksPojmova(mapa);
	
	for(;;){
	    std::string tmp;
	    std::cout << "Unesite rijec: ";
	    std::getline (std::cin, tmp);
	    for(int i=0; i<tmp.size(); i++){
	        if(tmp[i] == ' '){
                tmp.erase(i, 1);
	        }
	    }
	    if(tmp == "."){
	        return 0;
	    }
	    try{
    	    std::set<int> pozicije_rijeci = PretraziIndeksPojmova(tmp, mapa);
    	    for(auto iter=pozicije_rijeci.begin(); iter!=pozicije_rijeci.end();++iter){
    	        std::cout << *iter << " ";
    	    }
    	    std::cout << std::endl;
	    } catch(std::logic_error){
	        std::cout << "Unesena rijec nije nadjena!";
	        std::cout << std::endl;
	    }
	}
    return 0;
}
