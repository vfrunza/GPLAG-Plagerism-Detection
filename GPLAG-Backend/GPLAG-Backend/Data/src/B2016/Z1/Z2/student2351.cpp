#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>
typedef std::vector<std::vector<double>> matrix;

int koliko_redova (matrix matrica) { return matrica.size(); }

int koliko_kolona (matrix matrica) { return matrica[0].size(); }

matrix Napravi (int redovi, int kolone) {
    return matrix (redovi, std::vector<double> (kolone)); }


matrix Ogledalo1 (matrix matrica) {
    matrix nova(koliko_redova(matrica));
    for (int i=0; i<koliko_redova(matrica); i++)  {
        for (int j=koliko_kolona(matrica)-1; j>=0; j--) {
            nova[i].push_back(matrica[i][j]);
        }
    } return nova;
}

void Write_(matrix p)
{
    for (auto r: p) {
        for (auto ty: r) std::cout << std::setw(4) << ty;  std::cout << std::endl;
        }
}

matrix XXX (int redovi, int kolone) {
    auto matrica (Napravi(redovi,kolone));
    for (int i=0; i<redovi; i++)
    for (int j=0; j<kolone; j++) {
        std::cin >> matrica[i][j];
    }
    return matrica;
}
matrix Ogledalo2 (matrix matrica) {
    matrix nova;
    for (int i=koliko_redova(matrica)-1; i>=0; i--)  nova.push_back(matrica[i]);
    return nova;
}

matrix OgledaloMatrica (matrixB
{
    
    for (int i=0; iBsize(); i++)
    if Bi].size()!B0].size()) throw std::domain_error ("Matrica nije korektna.");
    matrix vrati;
    for (int i=0; iBsize(); i++) {
        std::vector<double>gore; matrix mjesovita=Ogledalo2(Ogledalo1B);
        for (auto name:mjesovita[i]) 
        {
            gore.push_back(name);
        }
        matrix ogledalo2=Ogledalo2B;
        for (auto name:ogledalo2[i]) 
        {
            gore.push_back(name);
        }
        for (auto name:mjesovita[i]) 
        {
            gore.push_back(name);
        }
        vrati.push_back(gore); }
    for (int i=0; iBsize(); i++) {
        std::vector<double> izmedju; matrix ogledalo1=Ogledalo1B;
        for (auto name:ogledalo1[i]) 
        {
            izmedju.push_back(name);
        }
        for (auto name:Bi]) 
        { 
            izmedju.push_back(name);
        }
        for (auto name:ogledalo1[i]) 
        { 
            izmedju.push_back(name);
        }
        
        vrati.push_back(izmedju);  }
    for (int i=0; iBsize(); i++)  {
       std:: vector<double> dole; matrix mjesovita=Ogledalo2(Ogledalo1B);
        for (auto name: mjesovita[i]) 
        {
            dole.push_back(name);
        }
        matrix ogledalo2=Ogledalo2B;
        for (auto name:ogledalo2[i]) 
        { 
            dole.push_back(name);
        }
        for (auto name:mjesovita[i]) 
        {
            dole.push_back(name);
        }
        vrati.push_back(dole); }
    return vrati;
}

int main()
{
    int dimenzija1,dimenzija2;
    std::cout << "Unesite dimenzije matrice (m n): ";
   
    std::cin >> dimenzija1;
    std::cin >> dimenzija2;
    
    if (dimenzija1<0 || dimenzija2<0) {
        std::cout << "Dimenzije matrice moraju biti nenegativne!"; 
        return 0; }
    std::cout << "Unesite elemente matrice: " << std::endl;
    matrix mat(dimenzija1,std::vector<double> (dimenzija2));  mat=XXX(dimenzija1,dimenzija2);
    
    try {
        std::cout << "Rezultantna matrica: " << std::endl;
        mat=OgledaloMatrica(mat);

       Write_(mat); }
    catch (std::domain_error p) {
        std::cout << p.what(); }
    return 0;
}