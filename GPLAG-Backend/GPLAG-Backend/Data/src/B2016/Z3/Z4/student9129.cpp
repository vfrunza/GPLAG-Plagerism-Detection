#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <list>
#include <stdexcept>

#include <list>
#include <iostream>

namespace std 
{
    template<typename Tip>
    class MojaLista : public list<Tip> 
    {
     public:
	    MojaLista() : list<Tip>() { std::cout << "Pozvana moja lista" << std::endl; }
        MojaLista(int brEl) : list<Tip>(brEl) { std::cout << "Pozvana moja lista1" << std::endl; }
    };
}

#define list MojaLista


void pomjer(std::list<std::string> &tmp, std::list<std::string>::iterator &eci){
    int n(-1);
    for(int i = 0; i < (*eci).length(); i++)
        if(((*eci)[i] >= '0' && (*eci)[i] <= '9') || ((*eci)[i] >= 'A' && (*eci)[i] <= 'Z') || ((*eci)[i] >= 'a' && (*eci)[i] <= 'z' ))
            n++;
    eci = tmp.erase(eci); if(eci == tmp.end()) eci = tmp.begin();
    for(int i = 0; i < n; i++){
        eci++;
        if(eci == tmp.end()) eci = tmp.begin();
    }
}
void help(std::list<std::string> &tmp, std::list<std::string>::iterator &eci, int num, int pos, std::vector<std::set<std::string>> &ret){
    for(int i = 0; i < num; i++) {
        ret[pos].insert(*eci);
        pomjer(tmp,eci);
    }
}
std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> v, int k){
    
    if (v.size() < k || k < 1)
        throw std::logic_error ("Razvrstavanje nemoguce");
    
    std::vector<std::set<std::string>> ret(k); int n(v.size());
    std::list<std::string> tmp(0);
    for(int i = 0; i < v.size(); i++) tmp.push_back(v[i]);
    std::list<std::string>::iterator it(tmp.begin());
    int prvi = n%k; int prviNum = n/k + 1;
    int drugi = k - n%k; int drugiNum = n/k;
    for(int i = 0; i < prvi; i++) help(tmp, it, prviNum, i, ret);
    for(int i = 0; i < drugi; i++) help(tmp,it,drugiNum,i+prvi,ret);
    return ret;
}

int main (){
    //AT11 (neaktivni) - Autotest koji testira da li je koristen kontejnerski tip <list> 
//Ovaj test je eliminatoran, tj. ako ovaj test pada, na zadatak se dobiva 0 poena.

    try
    {
        auto povratnaLista (Razvrstavanje({"Ana", "Noa", "Khan", "Mia"}, 2));
    }
    catch(std::logic_error& e)
    {
        std::cout << "Izuzetak: " << e.what();
    }
    
	return 0;
}