#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>
typedef std::vector<std::vector<double>> Matrica;
typedef std::vector<double> Vektor;

Matrica NajvecaPlaninaMatrice(Matrica mat)
{
    Matrica zapisi;
    Vektor v;
    double suma(0); suma2(0);
    int krug(1);
    for(int i(0); i < mat.size()-1; i++) {
        if(mat.at(i).size() != mat.at(i+1).size()) throw std::domain_error("Matrica nije korektna");
    }
    for(int i(0); i < mat.size(); i++){
        for(int j(0); j < mat.at(i).size(); j++){
            for(int p = i - krug; p <= i + krug; p++){
                for(int q = j - krug; q <= j + krug; q++){
                    
                }
            }
        }
    }
}

Matrica UnesiMatricu(int red, int kolona)
{
    Matrica unosMatrica(red, std::vector<double>(kolona));
    for(int i(0); i < red; i++) {
        for(int j(0); j < kolona; j++) {
            std::cin >> unosMatrica.at(i).at(j);
        }
    }
    return unosMatrica;
}

void IspisiMatricu(Matrica mat)
{
    for(auto x : mat) {
        for(auto y : x) {
            std::cout << std::setw(6) << y;
        }
        std::cout << std::endl;
    }
}

int main()
{
    int red(0), kolona(0);
    std::cout << "Unesite dimenzije matrice (m i n): ";
    std::cin >> red >> kolona;
    if(red < 0 || kolona < 0) {
        std::cout << "Dimenzije matrice moraju biti nenegativne!";
        return 0;
    }
    std::cout << "Unesite elemente matrice:" << std::endl;
    Matrica mat(UnesiMatricu(red, kolona));
    std::cout << "Najveca planina matrice je:" << std::endl;

    Matrica mat1(NajvecaPlaninaMatrice(mat));
    std::cout << mat1.size();

    for(auto x : mat1) {
        for(auto y : x) {
            std::cout << std::setw(6) << y;
        }
        std::cout << std::endl;
    }

    /* try {
         IspisiMatricu(NajvecaPlaninaMatrice(mat));
     } catch(std::domain_error izuzetak) {
         std::cout << izuzetak.what() << std::endl;
     }*/

    return 0;
}