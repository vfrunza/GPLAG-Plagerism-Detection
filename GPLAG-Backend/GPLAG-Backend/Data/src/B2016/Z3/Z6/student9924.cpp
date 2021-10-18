/B2016/2017: Zadaća 3, Zadatak 6
#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <set>
#include <stdexcept>

std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> imena_djece, int broj_timova){
    //if(broj_timova<1 || broj_timova>imena_djece.size())
        //throw std::logic_error("Razvrstavanje nemoguce");
    //napravi broj timova i razvsrtaj broj djece
    int broj_djece_1_vise;
    broj_djece_1_vise=imena_djece.size()%broj_timova;
    int broj_po_timovima;
    broj_po_timovima=imena_djece.size()/broj_timova;
    
    //formira listu djece
    std::list<std::string> lista_djece;
    for(int i=0; i<imena_djece.size(); i++)
        lista_djece.push_back(imena_djece[i]);
    //dodano
    auto na_kraj(lista_djece.begin());
    for(int i=0; i<lista_djece.size(); i++)
        na_kraj++;
    na_kraj--;
    std::vector<std::set<std::string>> vrati;
    
    //sortiranje djece
    auto iter=lista_djece.begin();
    int ubacen_u_skup(0);
    int za_1_veci(0);
    std::set<std::string> skup;
    bool jeste_zadnji(false);
    while(lista_djece.size()!=0 && jeste_zadnji==false){
        std::string pomoc;
        //osiguraj ponavljanje pri izbacivanju
        if(iter==lista_djece.end() && lista_djece.size()==1){
            iter=lista_djece.begin(); //???
            pomoc=*iter;
            jeste_zadnji=true;
        } else {
            if(iter==na_kraj)
                na_kraj--;
            if(iter==lista_djece.end())
                iter=lista_djece.begin();
            pomoc=*iter;
            iter=lista_djece.erase(iter);
        }
        
        //ubaci u skupove
        if(za_1_veci<broj_djece_1_vise && ubacen_u_skup<broj_po_timovima+1){
            skup.insert(pomoc);
            ubacen_u_skup++;
        } else if(za_1_veci<broj_djece_1_vise && ubacen_u_skup==broj_po_timovima+1){
            za_1_veci++;
            vrati.push_back(skup);
            //ocisti ubaceni skup
            for(auto x: skup) skup.erase(x);
            ubacen_u_skup=0;
            skup.insert(pomoc);
            ubacen_u_skup++;
        } else if(za_1_veci==broj_djece_1_vise && ubacen_u_skup<broj_po_timovima){
            skup.insert(pomoc);
            ubacen_u_skup++;
        } else if(za_1_veci==broj_djece_1_vise && ubacen_u_skup==broj_po_timovima){
            vrati.push_back(skup);
            //ocisti ubaceni skup
            for(auto x: skup) skup.erase(x);
            ubacen_u_skup=0;
            skup.insert(pomoc);
            ubacen_u_skup++;
        } else if(lista_djece.size()==1){
            skup.insert(pomoc);
            vrati.push_back(skup);
        }
        
        //pomak za broj slova
        int pomak;
        pomak=pomoc.length();
        for(int i=0; i<pomak-1; i++){
            if(iter==na_kraj)
                iter=lista_djece.begin();
            else
                iter++;
        }
    }
    vrati.push_back(skup);
    return vrati;
}

int main ()
{
    int broj_djece;
    std::cout << "Unesite broj djece: ";
    std::cin >> broj_djece;
    std::cout << "Unesite imena djece: " << std::endl;
    std::vector<std::string> imena_djece;
    for(int i=0; i<broj_djece; i++){
        std::string ime;
        std::cin >> ime;
        imena_djece.push_back(ime);
    }
    int broj_timova;
    std::cout << "Unesite broj timova: ";
    std::cin >> broj_timova;
    try{
        auto vraceni=Razvrstavanje(imena_djece,broj_timova);
        for(int i=0; i<broj_timova; i++){
            std::cout << "Tim " << i+1 << ": ";
            int j(0);
            for(auto x: vraceni[i]) {
                j++;
                if(j!=vraceni[i].size()) std::cout << x << ", ";
                else std::cout << x;
            }
            std::cout << std::endl;
        }
    } catch(std::logic_error tekst){
        std::cout << tekst.what();
    }
	return 0;
}