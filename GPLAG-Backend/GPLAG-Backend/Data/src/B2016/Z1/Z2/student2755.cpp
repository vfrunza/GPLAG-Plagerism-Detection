#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>

typedef std::vector<std::vector<double> > matrica;

matrica HorizontalnoOgledalo (matrica m) {
    for(int i(0), j(m.size() - 1); i<m.size()/2; i++, j--) std::swap(m[i], m[j]);
    return m;
}

matrica VertikalnoOgledalo (matrica m) {
    for(int i(0); i<m.size(); i++) {
        for(int j(0); j<m[i].size()/2; j++) std::swap(m[i][j], m[i][m[i].size()-j-1]);
    }
    return m;
}

matrica HorVertOgledalo (matrica m) {
    return VertikalnoOgledalo(HorizontalnoOgledalo(m));
}

matrica OgledaloMatrica (matrica m) {
    matrica velika, H(HorizontalnoOgledalo(m)), V(VertikalnoOgledalo(m)), HV(HorVertOgledalo(m));
    int redovi(m.size());
    int kolone(m[0].size());
    
    for(int i(1); i<redovi; i++){
        if(m[i].size()!=kolone) throw std::domain_error("Matrica nije korektna");
    }
    velika.resize(3*redovi);

    int p(0); // brojac za trecinu redova matrice
    for(int i(0); i<3*redovi; i++, p++) {
        velika[i].resize(3*kolone);

        if(p%redovi==0 && p!=0) p=0;
        int q(0); // brojac za trecinu kolona matrice
        for(int j(0); j<3*kolone; j++, q++){
            if(q!=0 && q%kolone==0) q=0;
            if((i<redovi && (j<kolone || j>=2*kolone)) || (i>=2*redovi && (j<kolone || j>=2*kolone)))
                velika[i][j] = HV[p][q];
            else if(j>=kolone && j<2*kolone && (i<redovi || i>=2*redovi))
                velika[i][j] = H[p][q];
            else if(i>=redovi && i<=2*redovi && (j<kolone || j>=2*kolone))
                velika[i][j] = V[p][q];
            else velika[i][j] = m[p][q];
        }
    }
    return velika;
}



int main() {
    int m, n;
    
    std::cout << "Unesite dimenzije matrice (m n): ";
    std::cin >> m >> n;
    if(m<0 || n<0) {
        std::cout << "Dimenzije matrice moraju biti nenegativne!";
        return 0;
    }
    
    matrica mat;
    
    std::cout << "Unesite elemente matrice:";
    mat.resize(m);
    for(int i(0); i<mat.size(); i++) mat[i].resize(n);

    for(int i(0); i<mat.size(); i++) {
        for(int j(0); j<mat[i].size(); j++) {
            std::cin >> mat[i][j];
        }
    }
    std::cout << "\nRezultantna matrica:" << std::endl;
    matrica velika;
    try{
        velika = OgledaloMatrica(mat);
    }
    catch(std::domain_error e){
        std::cout << e.what();
    }
    for(int i(0); i<velika.size(); i++) {
        for(int j(0); j<velika[i].size(); j++) {
            std::cout << std::setw(4) << velika[i][j];
        }
        std::cout << std::endl;
    }

    return 0;
}
