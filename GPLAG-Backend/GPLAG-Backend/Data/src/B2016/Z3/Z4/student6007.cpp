/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <iterator>
#include <list>
#include <vector>
#include <string>
#include <set>
#include <stdexcept>
int slova(std::string s)
{
    int br = 0;
    for(int i = 0; i <s.length(); i++){
        if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9'))
            br++;
    }
    return br;
}
typedef std::vector<std::set<std::string>> vektorsetstring;
vektorsetstring Razvrstavanje (std::vector<std::string> s, int brtim){
    //int prvih_timova;
    std::list<std::string> lista; 
    //std::set<std::string> setovina;
    int velicina = s.size();
    int  brojac1 = 0;
    int kolkojeime;
    //int brojac = 0, brojac1 = 0;
    //int velicina = s.size();
    vektorsetstring vracam;
    std::vector<int> vek;
    //vracam.resize(brtim);
    //prvih_timova = velicina % brtim;
    //int broj_clanova = s.size()/brtim;
    //std::vector<std::set<std::string>> funkcija;
   //std::set<std::string> setovina;
    //std::list<std::string> lista; 
    vek.resize(brtim);
    vracam.resize(brtim);
    //KOPIRAMO U LISTU -----RADI
    for(auto i = 0; i < velicina; i++){
        lista.push_back(s[i]);        
    }
    /*for(auto x : lista){
        std::cout<< x;
    }*/
    //int brojac1 = 0;
    int ostalo, brojac = 0;
    int dodjeljeno;
    auto it =  lista.begin();
    if(brtim>velicina || brtim<=0)
        throw std::domain_error("Razvrstavanje nemoguce");
    int velicina_veka=vek.size();
    for(auto i = 0; i< velicina_veka; ++i) vek[i] = velicina/brtim;
    
        dodjeljeno = (velicina/brtim)*brtim;
        ostalo = velicina-dodjeljeno;
    
        while(ostalo != 0){
            vek[brojac]++;
            ostalo--;
            brojac++;
        }
    //int kolkojeime = 0;/*   }
        /*while(lista.size()!=0){
            for (int i = 0; i<brtim; i++){
             std::set<std::string> skup_djece;
            int broj_slova = 0;
            //if(it==lista.end()) it = lista.begin();
            while(skup_djece.size() != broj_clanova){
            
            if(broj_slova == 0){
                auto ime1 = *it;
                skup_djece.insert(ime1);
                broj_slova = (ime1).length();
                it = lista.erase(it);
            }
            for(int j = 0; j < broj_slova; ++j){
                it++;
                if(it==lista.end()) {
                    it = lista.begin();
                    j--;
                }
            }*/
           
    for(auto i = 0; i!=vracam.size(); ++i){
        while(brojac1 !=vek[i]){
            kolkojeime = slova(*it);
            vracam[i].insert(*it);
            it = lista.erase(it);
            brojac1++;
            for(int j = 0; j<kolkojeime-1;j++){
                if(it==lista.end())
                    it = lista.begin();
                it++;
            }
            if(it==lista.end())
                    it = lista.begin();
        }
        brojac1 = 0;
    }
        return vracam;
}
/*
            auto ime1 = *it;
            skup_djece.insert(ime1);
            broj_slova = (ime1).length();
            it = lista.erase(it);
            }
            if(prvih_timova>0){
                auto ime1 = *it;
                skup_djece.insert(ime1);
                broj_slova = (ime1).length();
                it = lista.erase(it);
                for(auto x : skup_djece){
                    std::cout<< x<< " ";
                }
                }
                funkcija.push_back(skup_djece);
                prvih_timova--;
            }
            
        }
    
    return funkcija;
}*/
void IspisiSkup(std::set<std::string> s){
    for(auto i = s.begin(); i!=s.end();){
        std::cout<<*i;
        i++;
        if(i!=s.end()) std::cout<<", ";
    }
}
int main () {
    //std::cout<<"Mimica";
   int broj_djece;
    vektorsetstring funkcija;
    std::cout<<"Unesite broj djece: ";
    std::cin>>broj_djece;
    std::cin.clear();
    std::cin.ignore(1000, '\n');
    std::vector<std::string> imena_djece;
    std::string ime;
    std::cout<<"Unesite imena djece: ";
    for(int i = 0; i <broj_djece; ++i){
        std::getline(std::cin, ime);
        imena_djece.push_back(ime);
    }
    std::cout<<std::endl;
    std::cout<<"Unesite broj timova: ";
    int brtim;
    std::cin>>brtim;
    try{
    funkcija = Razvrstavanje(imena_djece, brtim);
    for(int i = 0; i<brtim; ++i){
        std::cout<<"Tim "<< i+1 << ": ";
        IspisiSkup(funkcija[i]);
        std::cout<<std::endl;
        }
    }
    catch(std::logic_error izuzetak){
        std::cout<<"Izuzetak: "<<izuzetak.what();
    }
	return 0;
}