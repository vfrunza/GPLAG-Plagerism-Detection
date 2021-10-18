// B 16/17, Zadaća 2, Zadatak 2
//	Autotestovi by Enil Pajic (epajic1@etf.unsa.ba | @eon : etf.ba)
//	NAPOMENA: i javni ATo-vi su dio postavke!
#include <iostream>
#include <type_traits>
#include <vector>
#include <deque>
#include <stdexcept>
#include <iomanip>

enum class SmjerKretanja{
    NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo
};

int Min(int a, int b){
    if(a<=b) 
        return a;
    return b;
}

template <typename kontejner>
auto IzdvojiDijagonale3D (kontejner kont, SmjerKretanja Smjer) -> typename std::remove_reference<decltype(kont.at(0))>::type{
    
    typename std::remove_reference<decltype(kont.at(0))>::type matrica;
    
    if (kont.size() !=0 && kont.at(0).size() != 0 && kont.at(0).at(0).size() !=0){
        int a=kont.at(0).size();//broj redova
        int b=kont.at(0).at(0).size(); // broj elemenata u redu
        for(int i=0;i<kont.size();i++){
            for(int j=0;j<kont.at(i).size();j++){
                if(kont.at(i).at(j).size() != b)
                    throw std::domain_error("Redovi nemaju isti broj elemenata");
            }
        }
        
        for(int i=0;i<kont.size();i++){
            if(kont.at(i).size() != a)
                throw std::domain_error("Plohe nemaju isti broj redova");
        }
        
    switch(int(Smjer)){
        case 0: {
            for(int i=0;i<kont.size();i++){
                typename std::remove_reference<decltype((kont.at(0)).at(0))>::type red;
                for(int j=0; j<Min(kont.at(0).size(),kont.at(0).at(0).size()); j++)
                    red.push_back(kont.at(i).at(j).at(j));
                matrica.push_back(red);
            }
            return matrica;
        }
        case 1: {
            for(int i=kont.size()-1;i>=0;i--){
                typename std::remove_reference<decltype((kont.at(0)).at(0))>::type red;
                for(int j=0;j<Min(kont.at(0).size(),kont.at(0).at(0).size());j++)
                    red.push_back(kont.at(i).at(j).at(kont.at(0).at(0).size()-1-j));
                matrica.push_back(red);
            }
            return matrica;
        }
        case 2: {
            for(int i=0;i<kont.at(0).size();i++){
                typename std::remove_reference<decltype((kont.at(0)).at(0))>::type red;
                for(int j=0;j<Min(kont.size(),kont.at(0).at(0).size());j++)
                    red.push_back(kont.at(kont.size()-1-j).at(i).at(j));
                matrica.push_back(red);
            }
            return matrica;
        }
        case 3:{
            for(int i=kont.at(0).size()-1;i>=0;i--){
                typename std::remove_reference<decltype((kont.at(0)).at(0))>::type red;
                for(int j=0;j<Min(kont.size(),kont.at(0).at(0).size());j++)
                    red.push_back(kont.at(kont.size()-1-j).at(i).at(kont.at(0).at(0).size()-1-j));
                matrica.push_back(red);
            }
            return matrica;
        }
        case 4:{
            for(int i=0 ;i<kont.at(0).at(0).size() ;i++){
                typename std::remove_reference<decltype((kont.at(0)).at(0))>::type red;
                for(int j=0;j<Min(kont.size(),kont.at(0).size());j++)
                    red.push_back(kont.at(kont.size()-1-j).at(j).at(i));
                matrica.push_back(red);
            }
            return matrica;
        }
        case 5:{
            for(int i=kont.at(0).at(0).size()-1;i>=0;i--){
                typename std::remove_reference<decltype((kont.at(0)).at(0))>::type red;
                for(int j=0;j<Min(kont.size(),kont.at(0).size());j++)
                    red.push_back(kont.at(j).at(j).at(i));
                matrica.push_back(red);
            }
            return matrica;
        }
    } 
    }
    
    return matrica;
}

int main (){
    
    int x,y,z;
    std::cout<<"Unesite dimenzije (x y z): ";
    std::cin >> x >> y >> z;
    if(x<0 || y<0 || z<0){
        std::cout<<"Neispravne dimenzije kontejnera!";
        return 0;
    }
    
    std::vector<std::deque<std::deque<int>>> Matrica(x, std::deque<std::deque<int>> (y, std::deque<int> (z)));
    
    std::cout<<"Unesite elemente kontejnera: "<<std::endl;
    
    for(int i=0 ; i<x ; i++){
        for(int j=0; j<y; j++){
            for(int k=0;k<z;k++){
                std::cin>>Matrica.at(i).at(j).at(k);
            }
        }
    }
    
    std::cout<<"Unesite smjer kretanja [0 - 5]: ";
    int smjer;
    std::cin>>smjer;
    
    if(smjer<0 || smjer> 5){
        std::cout<<"Smjer kretanja nije ispravan!"<<std::endl;
        return 0;
    }
    
    try{
    auto matrica=IzdvojiDijagonale3D(Matrica, SmjerKretanja(smjer));
    
    switch(smjer){
        case 0: {std::cout<<"NaprijedNazad: "<<std::endl; break;}
        case 1: {std::cout<<"NazadNaprijed: "<<std::endl; break;}
        case 2: {std::cout<<"GoreDolje: "<<std::endl; break;}
        case 3: {std::cout<<"DoljeGore: "<<std::endl; break;}
        case 4: {std::cout<<"LijevoDesno: "<<std::endl; break;}
        case 5: {std::cout<<"DesnoLijevo: "<<std::endl; break;}
    }
    
    for(int i=0;i<matrica.size();i++){
        for(int j=0;j<matrica[i].size();j++){
            std::cout<<std::setw(4)<<matrica.at(i).at(j);}
            std::cout<<std::endl;
        
    }
    }
    catch (std::domain_error izuzetak){
        std::cout<< "Izuzetak: "<<izuzetak.what();
    }
	return 0;
}