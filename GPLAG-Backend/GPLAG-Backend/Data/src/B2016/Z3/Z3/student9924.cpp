/B2016/2017: Zadaća 3, Zadatak 3
#include <iostream>
#include <set>
#include <string>
#include <list>
#include <vector>

int main ()
{
    std::list<std::string> lista_djece;
    std::vector<std::string> imena_djece;
    for(int i=0; i<10; i++){
        std::string ime;
        std::cin >> ime;
        imena_djece.push_back(ime);
    }
    for(int i=0; i<imena_djece.size(); i++)
        lista_djece.push_back(imena_djece[i]);
    std::vector<std::set<std::string>> vrati;
    
    //pok na ktaj
    auto na_kraj(lista_djece.begin());
    for(int i=0; i<lista_djece.size(); i++)
        na_kraj++;
    na_kraj--;
    
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
        if(za_1_veci<1 && ubacen_u_skup<3+1){
            skup.insert(pomoc);
            ubacen_u_skup++;
        } else if(za_1_veci<1 && ubacen_u_skup==3+1){
            za_1_veci++;
            vrati.push_back(skup);
            //ocisti ubaceni skup
            for(auto x: skup) skup.erase(x);
            ubacen_u_skup=0;
            skup.insert(pomoc);
            ubacen_u_skup++;
        } else if(za_1_veci==1 && ubacen_u_skup<3){
            skup.insert(pomoc);
            ubacen_u_skup++;
        } else if(za_1_veci==1 && ubacen_u_skup==3){
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
	return 0;
}