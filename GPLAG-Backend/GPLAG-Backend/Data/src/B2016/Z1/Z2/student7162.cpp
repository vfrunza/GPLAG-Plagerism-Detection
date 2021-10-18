/*B 2016/2017, Zadaća 1, Zadatak 2 */
#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>

// PONOVITI 
// if(matrica.size() == 0 || matrica[0].size() == 0) ne radi ?
// if(matrica.size() == 0) radi !

// KREIRA MATRICU
std::vector<std::vector<double>> KreirajMatricu(int m, int n){
    std::cout << "Unesite elemente matrice: ";
    std::vector<std::vector<double>> MATRIX (m, std::vector<double>(n));
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            std::cin >> MATRIX[i][j];
        }
    }
    return MATRIX;
}

// ISPISUJE MATRICU
void IspisMatrice(std::vector<std::vector<double>> MATRIX){
    std::cout << std::endl << "Rezultantna matrica: " << std::endl;
    for(int i=0; i<MATRIX.size(); i++){
        for(int j=0; j<MATRIX[0].size(); j++){
            std::cout << std::setw(4) << MATRIX[i][j];
        }
        std::cout << std::endl;
    }
}

// h(M) MATRICA
std::vector<std::vector<double>> hM(std::vector<std::vector<double>> MATRIX){
    std::vector<std::vector<double>> OgledaloHM (MATRIX.size(), std::vector<double>(MATRIX[0].size(), 0));
    int k_brojac(0);
    for(int i=0; i<MATRIX.size(); i++){
        int l_brojac(0);
        for(int j=MATRIX[0].size()-1; j>=0; j--){
            OgledaloHM[k_brojac][l_brojac] = MATRIX[i][j];
            l_brojac++;
        }
        k_brojac++;
    }
    return OgledaloHM;
}

//v(M) MATRICA
std::vector<std::vector<double>> vM(std::vector<std::vector<double>> MATRIX){
    std::vector<std::vector<double>> OgledaloVM (MATRIX.size(), std::vector<double>(MATRIX[0].size(), 0));
    int k_brojac(0);
    for(int i=MATRIX.size()-1; i>=0; i--){
        int l_brojac(0);
        for(int j=0; j<MATRIX[0].size(); j++){
            OgledaloVM[k_brojac][l_brojac] = MATRIX[i][j];
            l_brojac++;
        }
        k_brojac++;
    }
    return OgledaloVM;
}

//hv(M) MATRICA
std::vector<std::vector<double>> hvM(std::vector<std::vector<double>> MATRIX){
    std::vector<std::vector<double>> OgledaloHVM (MATRIX.size(), std::vector<double>(MATRIX[0].size(), 0));
    int k_brojac(0);
    for(int i=MATRIX.size()-1; i>=0; i--){
        int l_brojac(0);
        for(int j=MATRIX[0].size()-1; j>=0; j--){
            OgledaloHVM[k_brojac][l_brojac] = MATRIX[i][j];
            l_brojac++;
        }
        k_brojac++;
    }
    return OgledaloHVM;
}

// hvm vm hvm
// hm m hm
// hvm vm hvm
std::vector<std::vector<double>> OgledaloMatrica (std::vector<std::vector<double>> MATRIX){
    // PROVJERA: da li je prazna
    if(MATRIX.size()==0){
        return MATRIX;
    }
    // PROVJERA: da li je grbava
    for(int i=0; i<MATRIX.size()-1; i++){
        if(MATRIX[i].size() != MATRIX[i+1].size()){
            throw std::domain_error("Matrica nije korektna");
        }
    }
    int duzina_matrix(3*MATRIX.size()), sirina_matrix(3*MATRIX[0].size());
    std::vector<std::vector<double>> hvm = hvM(MATRIX);
    std::vector<std::vector<double>> hm = hM(MATRIX);
    std::vector<std::vector<double>> vm = vM(MATRIX);
    // Ogledalo matrice inicijalizacija i svi elementi su nula
    std::vector<std::vector<double>> ogledalo (duzina_matrix, std::vector<double> (sirina_matrix, 0));
    int prva_trecina_sirine = sirina_matrix/3, druga_trecina_sirine = prva_trecina_sirine*2;
    int prva_trecina_duzine = duzina_matrix/3, druga_trecina_duzine = prva_trecina_duzine*2;

    // PRVA DIO MATRICE
    for(int i=0; i<prva_trecina_duzine; i++){
        int x_brojac(0), y_brojac(0), z_brojac(0);
        for(int j=0; j<prva_trecina_sirine; j++){
            ogledalo[i][j] = hvm[i][x_brojac];
            x_brojac++;
        }
        for(int k=prva_trecina_sirine; k<druga_trecina_sirine; k++){
            ogledalo[i][k] = vm[i][y_brojac];
            y_brojac++;
        }
        for(int l=druga_trecina_sirine; l<sirina_matrix; l++){
            ogledalo[i][l] = hvm[i][z_brojac];
            z_brojac++;
        }
    }

    // DRUGI DIO MATRICE
    int l_brojac(0), m_brojac(0), n_brojac(0);
    for(int i=prva_trecina_duzine; i<druga_trecina_duzine; i++){
        int x_brojac(0), y_brojac(0), z_brojac(0);
        for(int j=0; j<prva_trecina_sirine; j++){
            ogledalo[i][j] = hm[l_brojac][x_brojac];
            x_brojac++;
        }
        for(int k=prva_trecina_sirine; k<druga_trecina_sirine; k++){
            ogledalo[i][k] = MATRIX[m_brojac][y_brojac];
            y_brojac++;
        }
        for(int l=druga_trecina_sirine; l<sirina_matrix; l++){
            ogledalo[i][l] = hm[n_brojac][z_brojac];
            z_brojac++;
        }
        l_brojac++; m_brojac++; n_brojac++;
    }

    // TRECI DIO MATRICE
    l_brojac = 0; m_brojac = 0; n_brojac = 0;
    for(int i=druga_trecina_duzine; i<duzina_matrix; i++){
        int x_brojac(0), y_brojac(0), z_brojac(0);
        for(int j=0; j<prva_trecina_sirine; j++){
            ogledalo[i][j] = hvm[l_brojac][x_brojac];
            x_brojac++;
        }
        for(int k=prva_trecina_sirine; k<druga_trecina_sirine; k++){
            ogledalo[i][k] = vm[m_brojac][y_brojac];
            y_brojac++;
        }
        for(int l=druga_trecina_sirine; l<sirina_matrix; l++){
            ogledalo[i][l] = hvm[n_brojac][z_brojac];
            z_brojac++;
        }
        l_brojac++; m_brojac++; n_brojac++;
    }

    return ogledalo;
}

int main(){
    std::cout << "Unesite dimenzije matrice (m n): ";
    int m, n;
    std::cin >> m >> n;
    if(m<0 || n<0){
        std::cout << "Dimenzije matrice moraju biti nenegativne!";
        return 0;
    }
    std::vector<std::vector<double>> MATRIX = KreirajMatricu(m, n);
    try{
        std::vector<std::vector<double>> ogledalo = OgledaloMatrica(MATRIX);
        IspisMatrice(ogledalo);
    }
    catch(std::domain_error izuzetak){
        std::cout << izuzetak.what() << std::endl;
    }
    return 0;
}