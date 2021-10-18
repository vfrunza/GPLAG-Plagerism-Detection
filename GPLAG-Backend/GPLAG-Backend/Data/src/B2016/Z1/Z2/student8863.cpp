#include <iostream>
#include <vector>
#include <stdexcept>

using std::cin;
using std::cout;

typedef std::vector<double> Vektor;
typedef std::vector<Vektor> Matrica;

Matrica Vertikalno(Matrica mat){
    Matrica vertikalna;
    for(int i = mat.size() - 1; i >= 0; i--){
        if(mat[0].size() != mat[i].size()) throw std::domain_error("Greska");
        vertikalna.push_back(mat[i]);
    }
    return vertikalna;
}

Matrica Horizontalno(Matrica mat){
    Matrica horizontalna;
    horizontalna.resize(mat.size());
    for(int i = 0; i < horizontalna.size(); i++){
        for(int j = mat[i].size() - 1; j >= 0; j--){
            horizontalna[i].push_back(mat[i][j]);
        }
            
    }
    return horizontalna;
}

Matrica Ness3in1(Matrica mat1, Matrica mat2){
    Matrica prva;
    prva.resize(mat1.size());
    for(int i = 0; i < prva.size(); i++){
        for(int j = 0; j < 3 * mat1[i].size(); j++){
            if(j >= 0 && j < mat1[i].size())
                prva[i].push_back(mat1[i][j]); 
                
            if(j >= 2 * mat1[i].size() && j < 3 * mat1[i].size())
                prva[i].push_back(mat1[i][j - 2 * mat1[i].size()]);
                
            if(j >= mat1[i].size() && j < 2 * mat1[i].size()) {
                prva[i].push_back(mat2[i][j - mat1[i].size()]);
            }
        }
    }
    return prva;
}

Matrica OgledaloMatrica(Matrica mat){
    try{
        Matrica ogledalo;
        Matrica hvvhv(Ness3in1(Horizontalno(Vertikalno(mat)), Vertikalno(mat)));
        Matrica hMh(Ness3in1(Horizontalno(mat), mat));
        for(int i = 0; i < 2 * mat.size(); i++){
            if(i < mat.size())
                ogledalo.push_back(hvvhv[i]);
     
            if(i >= mat.size())
                ogledalo.push_back(hMh[i - mat.size()]);
    
        }
        
        for(int i = 0; i < mat.size(); i++){
            if(i < mat.size())
                ogledalo.push_back(hvvhv[i]);
        }
        
        return ogledalo;

    }
    catch(...){
        throw std::domain_error("Matrica nije korektna");
    }
}


int main (){
    try{
        Matrica mat;
        int a, b;
        cout << "Unesite dimenzije matrice (m n): ";
        cin >> a >> b;
            if(a < 0 || b < 0){
                cout << "Dimenzije matrice moraju biti nenegativne!";
                return 0;
            }
        double x;
        mat.resize(a);
        cout << "Unesite elemente matrice: " << std::endl;
        for(int i = 0; i <= a-1; i++){
            int j(0);
            while(j <= b-1){
                cin >> x;
                mat[i].push_back(x);
                j++;
            }
        }
        mat = OgledaloMatrica(mat);
        cout << "Rezultantna matrica: " << std::endl;
        for(Vektor i : mat){
                for(double j : i){
                    cout.width(4);
                    cout << j;
                }
                cout << std::endl;
        }
    }
    
    catch(std::domain_error izuzetak){
        cout << izuzetak.what() << std::endl;
    }
	return 0;
}