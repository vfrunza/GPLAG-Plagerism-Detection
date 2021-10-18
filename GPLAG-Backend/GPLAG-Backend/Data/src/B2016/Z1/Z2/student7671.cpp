/*B 2016/2017, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/

#include <iostream>
#include <vector>
#include <stdexcept>

typedef std::vector<std::vector<double>> Matrica;

Matrica H (const Matrica &v){
    double temp;
    Matrica mat(v);
    for(int i=0; i<mat.size(); i++){
        for(int j=0; j<mat[i].size()/2; j++){
            temp = mat[i][j];
            mat[i][j] = mat[i][mat[i].size()-1-j];
            mat[i][mat[i].size()-1-j] = temp;
        }
    }
    return mat;
}

Matrica V (const Matrica &v){
    Matrica mat(v);
    double temp;
    for(int i=0; i<mat.size()/2; i++){
        for(int j=0; j<mat[i].size(); j++){
            temp = mat[i][j];
            mat[i][j] = mat[mat.size()-1-i][j];
            mat[mat.size()-1-i][j] = temp;
        }
    }
    return mat;
}

Matrica HV (const Matrica &v){
    Matrica mat(v);
    double temp;
    for(int i=0; i<mat.size(); i++){
        for(int j=0; j<mat[i].size()/2; j++){
            temp = mat[i][j];
            mat[i][j] = mat[i][mat[i].size()-1-j];
            mat[i][mat[i].size()-1-j] = temp;
        }
    }
    for(int i=0; i<mat.size()/2; i++){
        for(int j=0; j<mat[i].size(); j++){
            temp = mat[i][j];
            mat[i][j] = mat[mat.size()-1-i][j];
            mat[mat.size()-1-i][j] = temp;
        }
    }
    return mat;
}
void Ispisi (const Matrica &mat){
    for(int i=0; i<mat.size(); i++){
        for(int j=0; j<mat[i].size(); j++){
            std::cout.width(4);
            std::cout<<mat[i][j];
        }
        std::cout<<std::endl;
    }
}

Matrica OgledaloMatrica (const Matrica &mat){
    for(int i=0; i<mat.size(); i++){
        for(int j=i; j<mat.size(); j++){
            if(mat[i].size()!=mat[j].size())
                throw std::domain_error("Matrica nije korektna");
        }
    }
    Matrica v(V(mat)), h(H(mat)), hv(HV(mat));
    Matrica glavna(mat.size()*3,std::vector<double>(mat[0].size()*3));
    for(int i=0; i<glavna.size(); i++){
        for(int j=0; j<glavna[i].size(); j++){
            if(i<hv.size() && j<hv[0].size())
                glavna[i][j] = hv[i][j];
            else if(i<v.size() && j>=v[0].size() && j<v[0].size()*2 )
                glavna[i][j] = v[i][j-v[0].size()];
            else if(i<hv.size() && j>=hv[0].size()*2 )
                glavna[i][j] = hv[i][j-hv[0].size()*2];
            else if(i>=h.size() && i<h.size()*2 && j<h[0].size())
                glavna[i][j] = h[i-h.size()][j];
            else if(i>=mat.size() && i<mat.size()*2 && j>=mat[0].size() && j<mat[0].size()*2)
                glavna[i][j] = mat[i-mat.size()][j-mat[0].size()];
            else if(i>=h.size() && i<h.size()*2 && j>=h[0].size()*2)
                glavna[i][j] = h[i-h.size()][j-h[0].size()*2];
            else if(i>=hv.size()*2 && j<h[0].size())
                glavna[i][j] = hv[i-hv.size()*2][j];
            else if(i>=v.size()*2 && j>=v[0].size() && j<v[0].size()*2)
                glavna[i][j] = v[i-v.size()*2][j-v[0].size()];
            else if(i>=hv.size()*2 && j>=hv[0].size()*2)
                glavna[i][j] = hv[i-hv.size()*2][j-hv[0].size()*2];
        }
    }
    return glavna;
}



int main(){
    try{
        int m, n;
        std::cout<<"Unesite dimenzije matrice (m n): ";
        std::cin>>m>>n;
        if(m<0 || n<0){
            std::cout<<"Dimenzije matrice moraju biti nenegativne!";
            return 0;
        }
        else if(m==0 || n==0){
            std::cout<<"Unesite elemente matrice: "<<std::endl;
            std::cout<<"Rezultantna matrica: "<<std::endl;
            if(m!=0){
                for(int i=0; i<m; i++)
                    std::cout<<std::endl;
            }
            else if(n!=0){
                for(int i=0; i<m; i++)
                    std::cout<<std::endl;
            }
            return 0;
        }
        Matrica mat(m,std::vector<double>(n));
        std::cout<<"Unesite elemente matrice: "<<std::endl;
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                std::cin>>mat[i][j];
        std::cout<<"Rezultantna matrica: "<<std::endl;
        Ispisi(OgledaloMatrica(mat));
    }
    catch(std::domain_error izuzetak){
        std::cout<<izuzetak.what()<<std::endl;
    }
    return 0;
}