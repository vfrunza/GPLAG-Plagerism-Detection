#include <iostream>
#include <vector>
#include <iomanip>
#include <deque>
#include <stdexcept>

enum class SmjerKretanja{
    NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo
};
template <typename NekiTip>
NekiTip VratiOkrenut(NekiTip Niz){
    NekiTip Novi(Niz.at(0).size(), typename std::remove_reference<decltype(Niz.at(0))>::type(Niz.size()));
    
    for(int i = 0; i < Niz.size(); i++){
        for(int j = 0; j < Niz.at(0).size(); j++){
            Novi.at(j).at(i) = Niz.at(i).at(j);
        }
    }
    return Novi;
}

template <typename NekiTip>
auto Funkcije(NekiTip Kvadar, int Provjera)->typename std::remove_reference<decltype(Kvadar.at(0))>::type{
    
    typename std::remove_reference<decltype(Kvadar.at(0))>::type Niz2D;
    typename std::remove_reference<decltype(Kvadar.at(0).at(0))>::type red,prazan;

    if(Provjera == 0){
        
        for(int i = 0; i < Kvadar.size(); i++){
            for(int j = 0; j < Kvadar.at(0).size(); j++){
                for(int k = 0; k < Kvadar.at(0).at(0).size(); k++)
                    if(j == k)
                    red.push_back(Kvadar.at(i).at(j).at(k));
                }
                Niz2D.push_back(red);
                red = prazan;
            }
        }
    if(Provjera == 1){
        
    for(int i = Kvadar.size()-1; i >= 0 ; i--){
        for(int j(0); j < Kvadar.at(0).size(); j++){
                for(int k = 0; k < Kvadar.at(0).at(j).size(); k++)
                if(j == Kvadar.at(0).at(0).size()-1-k)
                red.push_back(Kvadar.at(i).at(j).at(k));
        }
        Niz2D.push_back(red);
            red = prazan;
        }
    }
    
    else if(Provjera == 2){
        
        int indeks(0);
        for(int i = Kvadar.size()-1; i >= 0; i--){
            for(int j(0); j < Kvadar.at(i).size(); j++){
                red.push_back(Kvadar.at(i).at(j).at(indeks));
            }
            indeks++;
            Niz2D.push_back(red);
            if(indeks == Kvadar.at(0).at(0).size())break;
            red = prazan;
        }
    }
    
    else if(Provjera == 3){
        int k(Kvadar.at(0).at(0).size()-1);
        for(int i = Kvadar.size()-1; i >= 0; i--){
            for(int j = Kvadar.at(0).size()-1; j >= 0; j--){
                    red.push_back(Kvadar.at(i).at(j).at(k));
                }
            Niz2D.push_back(red);
            red = prazan;
            if(k == 0)break;
            k--;
        }
    }
    else if(Provjera == 4){
        
        int indeks = 0;
        for(int i = Kvadar.size()-1; i >= 0; i--){
            for(int j = 0; j < Kvadar.at(0).at(0).size(); j++){
                red.push_back(Kvadar.at(i).at(indeks).at(j));
            }
            indeks++;
            Niz2D.push_back(red);
            red = prazan;
        }
    }
    else if(Provjera == 5){
        
        int indeks = 0;
        for(int i = 0; i < Kvadar.size(); i++){
            for(int j = Kvadar.at(0).at(0).size()-1; j >= 0; j--){
                red.push_back(Kvadar.at(i).at(indeks).at(j));
            }
            indeks++;
            Niz2D.push_back(red);
            red = prazan;
        }
    }
    
    typename std::remove_reference<decltype(Kvadar.at(0))>::type Novi;
    Novi = VratiOkrenut(Niz2D);
    if(Provjera == 0 || Provjera == 1) Novi = Niz2D;
    
return Novi;
}


template <typename NekiTip>
auto IzdvojiDijagonale3D(NekiTip Kvadar, SmjerKretanja Smjer) -> typename std::remove_reference<decltype(Kvadar.at(0))>::type{
    typename std::remove_reference<decltype(Kvadar.at(0))>::type Novi;
    
    for(int i(0); i < Kvadar.size()-1; i++){
        for(int j(0); j < Kvadar.at(i).size()-1; j++){
            for(int k(0); k < Kvadar.at(i).at(j).size(); k++){
                if(Kvadar.at(i).at(j).size() != Kvadar.at(i).at(j+1).size()) throw std::domain_error("Redovi nemaju isti broj elemenata");
            }
            if(Kvadar.at(i).size() != Kvadar.at(i+1).size()) throw std::domain_error("Plohe nemaju isti broj redova");
        }
    }
    
    for(int i(0); i < 6; i++){
        if(int(Smjer) == i) Novi = Funkcije(Kvadar, i);
}
return Novi;
}
int main ()
{
    try{
    std::cout << "Unesite dimenzije (x y z): ";

    int duz,sir,vis;
    
    std::cin >> duz >> sir >> vis;
    
    if(duz <0 || duz > 2 || sir <0 || vis <0){
        std::cout << "Neispravne dimenzije kontejnera!";
        return 0;
    }
    
    std::cout << "Unesite elemente kontejnera: " << std::endl;
    int element;
    std::vector<std::deque<std::deque<int>>> Kvadar;
    std::deque<std::deque<int>> Strana, prazno;
    std::deque<int> red, prazan;
    for(int i(0); i < duz; i++){
        for(int j(0); j < sir; j++){

            for(int k(0); k < vis; k++){
                std::cin >> element;
                red.push_back(element);
            }
            Strana.push_back(red);
            red = prazan;
        }
        Kvadar.push_back(Strana);
        Strana = prazno;
    }
    
    std::cout << "Unesite smjer kretanja [0 - 5]: ";
    int smjer;
    std::cin >> smjer;
    if(smjer <0 || smjer >5)std::cout<< "Smjer kretanja nije ispravan!" << std::endl;
    
    else{
        
    auto Niz(IzdvojiDijagonale3D(Kvadar, SmjerKretanja(smjer)));
    
    std::vector<std::string> Sm{{"NaprijedNazad: "}, {"NazadNaprijed: "}, {"GoreDolje: "}, {"DoljeGore: "}, {"LijevoDesno: "}, {"DesnoLijevo: "}};
    std::cout << Sm[smjer] << std::endl;
    
    for(int i(0); i < Niz.size(); i++){
        for(int j(0); j < Niz[i].size(); j++){
            std::cout << std::setw(4) << Niz[i][j];
        }
        std::cout << std::endl;
    }
    }
}catch(std::domain_error izuzetak){
    std::cout << izuzetak.what() << std::endl;
}
	return 0;
}