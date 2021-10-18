/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <set>
#include <stdexcept>

std::vector<std::multiset<std::string>> Razvrstavanje(std::vector<std::string> imena_djece, int broj_timova){
    if(broj_timova<1 || broj_timova>imena_djece.size())
        throw std::logic_error("Razvrstavanje nemoguce");
    //napravi broj timova i razvsrtaj broj djece
    int broj_djece_1_vise;
    broj_djece_1_vise=imena_djece.size()%broj_timova;
    int broj_po_timovima;
    broj_po_timovima=imena_djece.size()/broj_timova;
    
    //formira listu djece
    std::list<std::string> lista_djece;
    for(int i=0; i<imena_djece.size(); i++)
        lista_djece.push_back(imena_djece[i]);
    std::vector<std::multiset<std::string>> vrati;
    
    //pok na kraj
    auto na_kraj(lista_djece.begin());
    for(int i=0; i<lista_djece.size(); i++)
        na_kraj++;
    na_kraj--;
    
    //sortiranje djece
    auto iter=lista_djece.begin();
    int ubacen_u_skup(0);
    int za_1_veci(0);
    std::multiset<std::string> skup;
    bool jeste_zadnji(false);
    while(lista_djece.size()!=0 && jeste_zadnji==false){
        std::string pomoc;
        int umanji(0);
        //osiguraj ponavljanje pri izbacivanju
        if(iter==lista_djece.end() && lista_djece.size()==1){
            iter=lista_djece.begin(); //???
            pomoc=*iter;
            jeste_zadnji=true;
        } else {
            if(iter==na_kraj){
                pomoc=*iter;
                na_kraj--;
                lista_djece.erase(iter); //dodano
                iter=lista_djece.begin();
            } else {
                pomoc=*iter;
                iter=lista_djece.erase(iter);
            }
        }
        
        //ubaci u skupove
        if(za_1_veci<broj_djece_1_vise && ubacen_u_skup<broj_po_timovima+1){
            skup.insert(pomoc);
            ubacen_u_skup++;
        } else if(za_1_veci<broj_djece_1_vise && ubacen_u_skup==broj_po_timovima+1){
            za_1_veci++;
            vrati.push_back(skup);
            //ocisti ubaceni skup
            skup.clear();
            ubacen_u_skup=0;
            skup.insert(pomoc);
            ubacen_u_skup++;
        } else if(za_1_veci==broj_djece_1_vise && ubacen_u_skup<broj_po_timovima){
            skup.insert(pomoc);
            ubacen_u_skup++;
        } else if(za_1_veci==broj_djece_1_vise && ubacen_u_skup==broj_po_timovima){
            vrati.push_back(skup);
            //ocisti ubaceni skup
            skup.clear();
            ubacen_u_skup=0;
            skup.insert(pomoc);
            ubacen_u_skup++;
        } else if(lista_djece.size()==1){
            skup.insert(pomoc);
            vrati.push_back(skup);
        }
        
        //pomak za broj slova
        int pomak;
        for(auto j=pomoc.begin(); j<pomoc.end(); j++){
             if(*j<'0' || (*j>'9' && *j<'A') || (*j>'Z' && *j<'a') || *j>'z')
                umanji++;
        }
        pomak=pomoc.length()-umanji;
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
    std::cin.ignore(1000,'\n');
    for(int i=0; i<broj_djece; i++){
        std::string ime;
        std::getline(std::cin,ime);
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
        std::cout << "Izuzetak: " << tekst.what();
    }
	return 0;
}