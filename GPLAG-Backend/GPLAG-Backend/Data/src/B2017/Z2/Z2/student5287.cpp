#include <iostream>
#include <vector>
#include <deque>
#include <type_traits>
#include <stdexcept>

using std::vector;
using std::deque;

enum class SmjerKretanja {
    NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo
};

template <typename kont>
kont PjescaniSat(kont mat, SmjerKretanja smjer){
    kont psat;
    int size = mat.size();
    
    if(size == 0)
        return psat;
    
    //Nije kocka
    if(mat.at(0).size() != size || mat.at(0).at(0).size() != size || mat.at(0).size() != mat.at(0).at(0).size())
        throw std::domain_error("3D matrica nema oblik kocke");
    
    //Nije neparna
    if(size % 2 == 0)
        throw std::length_error("3D kontejner ne zadovoljava uvjet neparnosti");
    
    for(int k = 0; k < size; k++){
        //Privremena matrica
        typename std::remove_reference<decltype(mat.at(0))>::type temp2D;
        
        for(int j = 0; j < size; j++){
            //Privremeni red
            typename std::remove_reference<decltype(temp2D.at(0))>::type temp1D;
            
            //Pravila po kojima se koordinate mijenjaju tako da se uzme pjescani sat
            int hg_coord_rule = size/2 - std::abs(size/2-j);
            
            //Dodaji odgovarajuce elemente reda u privremeni red
            for(int i = hg_coord_rule; i < size - hg_coord_rule; i++){
                //Matrice se slazu odozgo nanize, pa je prva najvisa
                //Napomena sebi: k se "najsporije" mijenja, nakon njega j,
                //a i se "najbrze" mijenja, te zavisi od j u smislu da
                //u zavisnosti od j probira elemente iz matrice mat.at(k)
                //u "obliku" pjescanog sata
                //Razlicitim postavkama koordinata i,j,k moze se
                //postici odgovarajuci smjer kreiranja matrice
                
                typename std::remove_reference<decltype(temp1D.at(0))>::type vals[6] {
                    mat.at(j).at(k).at(i),
                    mat.at(size - 1 - j).at(k).at(i),
                    mat.at(k).at(j).at(i),
                    mat.at(k).at(size - 1 - j).at(i),
                    mat.at(k).at(i).at(j),
                    mat.at(k).at(i).at(size - 1 - j)
                };
                
                for(int ite = 0; ite < 6; ite++){
                    if(ite == int(smjer)){
                        temp1D.push_back(vals[ite]);
                        break;
                    }
                }
            }
            //Dodaj privremeni red u matricu
            temp2D.push_back(temp1D);
        }
        //Dodaj privremenu matricu u 3D psat
        psat.push_back(temp2D);
    }
    
    return psat;
}

int main ()
{
    int size;
    int iSmjer;
    
    std::cout << "Unesite dimenziju (x/y/z): ";
    while(std::cin >> size, size < 0){
        std::cout << "Dimenzija nije ispravna, unesite opet: ";
    }
    
    vector<deque<deque<int>>> cube(size, deque<deque<int>>(size, deque<int>(size)));
    
    std::cout << "Unesite elemente kontejnera: ";
    for(deque<deque<int>> &d2d : cube){
        for(deque<int> &d1d : d2d){
            for(int &i : d1d){
                std::cin >> i;
            }
        }
    }
    
    std::cout << "Unesite smjer kretanja [0 - 5]: ";
    while(std::cin >> iSmjer, (iSmjer < 0 || iSmjer > 5)){
        std::cout << "Smjer nije ispravan, unesite opet: ";
    }
    
    std::cout << std::endl;
    
    vector<deque<deque<int>>> psat;
    try{
        psat = PjescaniSat(cube, SmjerKretanja(iSmjer));
    }
    catch(std::domain_error err){
        std::cout << "Izuzetak: " << err.what();
        return 0;
    }
    catch(std::length_error err){
        std::cout << "Izuzetak: " << err.what();
        return 0;
    }
    
    std::cout << "Pjescani sat unesene matrice je:\n\n";
    for(int k = 0; k < size; k++){
        for(int j = 0; j < size; j++){
            int hgcr = size/2 - std::abs(size/2-j);
            
            for(int i = 0; i < size - hgcr; i++){
                std::cout.width(4);
                if(i >= hgcr)
                    std::cout << psat.at(k).at(j).at(i-hgcr);
                else
                    std::cout << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
    
	return 0;
}