#include <iostream>
#include <vector>
#include <iomanip>
#include <deque>
#include <stdexcept>
enum class SmjerKretanja {
 NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo
};

std::vector<std::deque<std::deque<int>>> unesi_kontejner(int n){
    std::vector<std::deque<std::deque<int>>> kontejner(n, std::deque<std::deque<int>>(n, std::deque<int>(n)));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            for(int k = 0; k < n; k++)
                std::cin>>kontejner.at(i).at(j).at(k);
    return kontejner;
}

void ispisi_kontejner(std::vector<std::deque<std::deque<int>>> kontejner){
    for(int i = 0; i < kontejner.size(); i++){
        for(int j = 0; j < kontejner.at(i).size(); j++){
            int t;
            if(j < kontejner.at(i).size() - 1 - j)
                t = j;
            else
                t = kontejner.at(i).size() - 1 - j;
            for(int i = 0; i < t; i++) std::cout<<std::setw(4)<<" ";
            for(int k = 0; k < kontejner.at(i).at(j).size(); k++)
                std::cout<<std::setw(4)<<kontejner.at(i).at(j).at(k);
            std::cout<<std::endl;
        }
        std::cout<<std::endl;;
    }
}

template <typename matrix>
    auto transpose(matrix matrica) -> matrix{
        matrix pomocna(matrica);
        for(int i = 0; i < matrica.size(); i++)
            for(int j = 0; j < matrica.size(); j++)
                pomocna.at(matrica.size()-1-j).at(i) = matrica.at(i).at(j);
        return pomocna;
    }

template <typename container>
    auto npnz(container kontejner) -> container{
        auto rezultat(kontejner);
        for(int i = 0; i < kontejner.size(); i++)
            for(int j = 0; j < kontejner.at(i).size(); j++)
                rezultat.at(j).at(i) = kontejner.at(i).at(j);
        return rezultat;
    }

template <typename container>
    auto dg(container kontejner) -> container{
        auto pomocni(kontejner);
        for(int i = 0; i < kontejner.size(); i++)
            for(int j = 0; j < kontejner.size(); j++)
                pomocni.at(i).at(j) = kontejner.at(i).at(kontejner.size() - 1 - j);
        return pomocni;
    }

template <typename container>
    auto dl(container kontejner) -> container{
        for(int i = 0; i < kontejner.size(); i++)
            kontejner.at(i) = transpose(kontejner.at(i));
        return kontejner;
    }

template <typename container>
    auto suzi(container kontejner) -> container{
        auto pomocni(kontejner);
        for(int i = 0; i < kontejner.size(); i++)
            for(int j = 0; j < kontejner.at(i).size(); j++){
                auto pomocni_vektor(kontejner.at(0).at(0));
                pomocni_vektor.resize(0);
                //int k(std::min(j, kontejner.size() - 1 - j));
                int k;
                if(j < kontejner.size() - 1 - j) k = j;
                else k = kontejner.size() - 1 - j;
                for(int t = k; t <= kontejner.size() - 1 - k; t++)
                    pomocni_vektor.push_back(kontejner.at(i).at(j).at(t));
                pomocni.at(i).at(j) = pomocni_vektor;
            }
        return pomocni;
    }

template <typename matrica>
bool Neparnost (matrica matrix) {
    if (matrix.size()%2==0 || matrix.at(0).size()%2==0)
        return false;
    return true;
}
template <typename matrica>
bool Dimenzije (matrica matrix, int &format) {
    if (matrix.size() != matrix.at(0).size())
        return false;
    format = matrix.size();
    return true;
}

template <typename container>
    auto PjescaniSat(container kontejner, SmjerKretanja smjer) -> container {
        if (kontejner.size() != kontejner.at(0).size())
            throw std::domain_error("3D matrica nema oblik kocke");
        int velicina(0);
        Dimenzije(kontejner.at(0), velicina);
        for (int i(1); i<kontejner.size(); i++) {
            int trenutna (0);
            if(!(Dimenzije(kontejner.at(i), trenutna)) || velicina != kontejner.at(i).size())
                throw std::domain_error("3D matrica nema oblik kocke");
        }        
        for (int i(0); i<kontejner.size(); i++) {
            if (!Neparnost(kontejner.at(i))) throw std::length_error ("3D kontejner ne zadovoljava uvjet neparnosti");
        }
        if (smjer == SmjerKretanja::NaprijedNazad) return suzi(npnz(kontejner));
        if (smjer == SmjerKretanja::NazadNaprijed) return suzi(dg(npnz(kontejner)));
        if (smjer == SmjerKretanja::GoreDolje) return suzi(kontejner);
        if (smjer == SmjerKretanja::DoljeGore) return suzi(dg(kontejner));
        if (smjer == SmjerKretanja::LijevoDesno) return suzi(dg(dl(kontejner)));
        if (smjer == SmjerKretanja::DesnoLijevo) return suzi(dl(kontejner));
    }

int main(){
    /*std::deque<std::deque<int>> v1 {{11, 12, 13, 14, 15}, {16, 17, 18, 19, 20}, {21, 22, 23, 24, 25}, {26, 27, 28, 29, 30}, {31, 32, 33, 34, 35}};
    std::deque<std::deque<int>> v2 {{-9, -8, -7, -6, -5}, {-4, -3, -2, -1, 17}, {14, 25, 28, 30, 35}, {19, -8, 54, 78, 65}, {22, 11, 72, 16, 67}};
    std::deque<std::deque<int>> v3 {{89, 28, 17, 56, 55}, {64, 93, 12, 81, 17}, {14, 25, 28, 31, 35}, {19, 44, 53, 72, 65}, {22, 18, 72, 16, 69}};
    std::deque<std::deque<int>> v4 {{36, 37, 38, 42, 43}, {39, 40, 41, 44, 45}, {46, 47, 48, 55, 56}, {49, 50, 51, 57, 58}, {52, 53, 54, 59, 60}};
    std::deque<std::deque<int>> v5 {{61, 62, 63, 67, 68}, {64, 65, 66, 69, 70}, {71, 72, 73, 80, 82}, {74, 75, 76, 81, 83}, {77, 78, 79, 84, 85}};
    std::vector<std::deque<std::deque<int>>> kontejner {v1, v2, v3, v4, v5};*/
    std::cout << "Unesite dimenziju (x/y/z): ";
    int dimenzija;
    std::cin>>dimenzija;
    if(dimenzija < 0) {
        do {
            std::cout << "Dimenzija nije ispravna, unesite opet: ";
            std::cin >> dimenzija;
        } while (dimenzija<0);
    }
    std::cout << "Unesite elemente kontejnera: ";
    std::vector<std::deque<std::deque<int>>> kontejner(unesi_kontejner(dimenzija));
    int smjer;
    std::cout << "Unesite smjer kretanja [0 - 5]: ";
    std::cin>>smjer;
    if(smjer > 5 || smjer < 0) {
        do {
            std::cout << "Smjer nije ispravan, unesite opet: ";
            std::cin >> smjer;
        } while (smjer > 5 || smjer < 0);
    }
    try {
        auto rezultat = PjescaniSat(kontejner, SmjerKretanja(smjer));
    }
    catch(std::exception &izuzetak) {
        std::cout << std::endl <<  "Izuzetak: " << izuzetak.what();
        return 0;
    }
    std::cout << std::endl;
    std::cout << "Pjescani sat unesene matrice je:" << std::endl;
    ispisi_kontejner(PjescaniSat(kontejner, SmjerKretanja(smjer)));

    return 0;
}
