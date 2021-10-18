#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>

typedef std::vector<std::vector<double>> Matrica;

// Kreira matricu sa zadanim brojem redova i kolona
Matrica KreirajMatricu(int m, int n)
{
    return Matrica(m, std::vector<double>(n));
}

// Vraća broj redova zadane matrice
int BrojRedova(Matrica M)
{
    return M.size();
}

// Vraća broj kolona zadane matrice
int BrojKolona(Matrica M)
{
    return M[0].size();

}
// Unosi sa tastature matricu sa zadanim brojem redova i kolona i
// vraća je kao rezultat
Matrica UnesiMatricu(int m, int n)
{
    auto M (KreirajMatricu(m, n));
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++) {
            std::cin >> M[i][j];
        }
    return M;
}

// Ispisuje zadanu matricu
void IspisiMatricu(Matrica M)
{
    for(int i = 0; i < BrojRedova(M); i++) {
        for(int j = 0; j < BrojKolona(M); j++)
            std::cout << std::setw(5) << M[i][j];
        std::cout << std::endl;
    }
}


std::vector <std::vector<double>> IzvrniRedove(std::vector<std::vector<double>> Matrica)
{
    std::vector <std::vector<double>> povratna;

    for(int i=Matrica.size()-1; i>=0; i--) {
        povratna.push_back(Matrica[i]);
    }
    return povratna;
}

std::vector <std::vector<double>> IzvrniKolone(std::vector<std::vector<double>> Matrica)
{
    std::vector <std::vector<double>> povratna;

    for(int i=0; i<Matrica.size(); i++) {
        std::vector<double> vektor;
        for(int j=Matrica.size()-1; j>=0; j--) {
            vektor.push_back(Matrica[i][j]);
        }
        povratna.push_back(vektor);
    }
    return povratna;
}



std::vector<std::vector<double>> OgledaloMatrica(std::vector<std::vector<double>> Matrica)
{
    std::vector<std::vector<double>> povratna;


    for(int i=0; i<Matrica.size(); i++) {
        if(Matrica[0].size()!=Matrica[i].size()) {
            throw std::domain_error("Matrica nije korektna.");
        }
    }


    std::vector<std::vector<double>> H;
    H=IzvrniKolone(Matrica);

    std::vector<std::vector<double>> V;
    V=IzvrniRedove(Matrica);

    std::vector<std::vector<double>> HV;
    HV=IzvrniKolone(IzvrniRedove(Matrica));



    for(int i=0; i<Matrica.size(); i++) {
        std::vector<double> veliki; /*Deklaracija reda nove velike matrice*/

        for(auto x: HV[i]) veliki.push_back(x);
        for(auto x: V[i]) veliki.push_back(x);
        for(auto x: HV[i]) veliki.push_back(x);

        povratna.push_back(veliki);
    }

    for(int i=0; i<Matrica.size(); i++) {
        std::vector<double> veliki;

        for(auto x: H[i]) veliki.push_back(x);
        for(auto x: Matrica[i]) veliki.push_back(x);
        for(auto x: H[i]) veliki.push_back(x);

        povratna.push_back(veliki);
    }

    for(int i=0; i<Matrica.size(); i++) {
        std::vector<double> veliki;

        for(auto x: HV[i]) veliki.push_back(x);
        for(auto x: V[i]) veliki.push_back(x);
        for(auto x: HV[i]) veliki.push_back(x);

        povratna.push_back(veliki);
    }

    return povratna;
}


// Glavni program
int main()
{

    try {

        std::cout << "Unesite dimenzije matrice (m n): ";
        int m,n;
        std::cin>> m >>n;
        if(m<0 || n<0) {
            std::cout << "Dimenzije matrice moraju biti nenegativne!"<<std::endl;
            return 0;
        }

        std::cout << "Unesite elemente matrice:\n";
        std::vector<std::vector<double>> Matrica ;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                
                auto M (UnesiMatricu(m,n));

                
            }
        }


        std::cout <<"Rezultantna matrica:\n";
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
               
               IspisiMatricu(OgledaloMatrica(M)); 
            }
        }

        

    } catch(std::domain_error e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
