/B2016/2017: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <stdexcept>
#include <string>
#include <set>
typedef std::map<std::string, std::set<int>> tip;
tip KreirajIndeksPojmova(std::string s){
    if (s.empty()) return tip();
    s.push_back(' ');
    tip rezultat;
    int brojac(0);
    for(auto it(s.begin()); it!=s.end(); it++){
        std::string pomocna;
        while (it != s.end() && *it == ' ') {
            it++;
            brojac++;
        }
        
        if(it == s.end()) break;
        int temp(brojac);
        while(it!=s.end() && *it != ' '){
            pomocna.push_back(*it);
            ++it;
            temp++;
        }
        rezultat[pomocna].insert(brojac);
        brojac = temp;
        brojac++;
    }
    
    return rezultat;
}

std::set<int> PretraziIndeksPojmova(std::string s, tip m){
    auto biter(m.find(s));
    if(biter == m.end()) throw std::logic_error("Unesena rijec nije nadjena!");
    return biter->second;
}
void IspisiIndeksPojmova(tip nesto){
    for(auto iter(nesto.begin()); iter!=nesto.end(); iter++){
        std::cout<<iter->first<<": ";
        int temp(1);
        for(auto it(iter->second.begin()); it!=iter->second.end(); ++it, temp++){
            std::cout<< *it;
            if(temp!= (int)iter->second.size()) std::cout<<",";
        }
        std::cout<<std::endl;
    }
}
int main ()
{
    std::string recenica;
    std::cout<<"Unesite tekst: ";
    std::getline(std::cin, recenica);
    auto nesto = KreirajIndeksPojmova(recenica);
    IspisiIndeksPojmova(nesto);
    for(;;){
        std::string c;
        std::cout<<"Unesite rijec: ";
        std::getline(std::cin, c);
        
        if(c == ".") break;
        try{
            for(auto x : PretraziIndeksPojmova(c, nesto)) 
            std::cout<< x <<" ";
        }
        catch (std::logic_error e){
            std::cout<<e.what()<<std::endl;
        }
        std::cout<<std::endl;
    }
    
    
    
    
	return 0;
}