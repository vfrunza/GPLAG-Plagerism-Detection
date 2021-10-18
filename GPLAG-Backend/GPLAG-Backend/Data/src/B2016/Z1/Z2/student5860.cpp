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
#include <iomanip>

typedef std::vector< std::vector<double> > Matrica;

std::vector<std::vector<double>> UnesiMatricu(int m, int n){
std::vector<std::vector<double>> mat (m, std::vector<double> (n));
std::cout<<"Unesite elemente matrice:";
for(int i=0; i<m; i++){
    for(int j=0; j<n; j++){ 
        std::cin>>mat[i][j];
    }
}
return mat;
}

// Tvorba horizontalne matrice
std::vector<std::vector<double>> horizontalna(std::vector< std::vector<double>> Mat){
std::vector<std::vector<double>> h(Mat.size());
for(int i=0; i<Mat.size(); i++){
    for(int j=Mat[0].size()-1; j>=0; j--){
        h[i].push_back(Mat[i][j]);
    }
}
/*for(int i=0; i<h.size(); i++){
    for(int j=0; j<h[0].size(); j++){
        std::cout<<h[i][j]<<" ";
}
std::cout<<std::endl;
}*/
return h;
}
// Tvorba vertikalne matrice
std::vector<std::vector<double>> vertikalna(std::vector< std::vector<double> > Mat){
std::vector<std::vector<double>> v(Mat.size());
for(int i=Mat.size()-1; i>=0; i--){
    for(int j=0; j<Mat[0].size(); j++){
        v[Mat.size()-1-i].push_back(Mat[i][j]);
    }
}
/*for(int i=0; i<v.size(); i++){
    for(int j=0; j<v[0].size(); j++){
std::cout<<v[i][j]<<" ";
}std::cout<<std::endl;
}*/
return v;
}

// Tvorba hv matrice:
std::vector< std::vector<double> > mjesana(std::vector< std::vector<double> > Mat){
std::vector< std::vector<double> > hv(Mat.size());
int brojac(0);
for(int i=Mat.size()-1; i>=0; i--){
    for(int j=Mat[0].size()-1; j>=0; j--){
        hv[brojac].push_back(Mat[i][j]);
    }
    brojac++;
}
/*for(int i=0; i<hv.size(); i++){
    for(int j=0; j<hv[0].size(); j++){
        std::cout<<hv[i][j]<<" ";
}
std::cout<<std::endl;
}*/
return hv;
}

//Ovaj dio bi trebao glupisati matrice v h i vh i sastaviti veliku matricu
std::vector<std::vector<double>> OgledaloMatrica(std::vector<std::vector<double>> Mat){
int mo(3*Mat.size());
std::vector<std::vector<double>> m1(mjesana(Mat));
std::vector<std::vector<double>> m2(vertikalna(Mat));
std::vector<std::vector<double>> m3(horizontalna(Mat));
std::vector<std::vector<double>> MatO(mo);
int m_1(0), m_2(0), m_3(0);
for(int i=0; i<mo; i++){
    if(i<(double(mo)/3)){
        for(int k=0; k<m1[0].size(); k++){
            MatO[i].push_back(m1[m_1][k]);
        }
        for(int k=0; k<m2[0].size(); k++){
            MatO[i].push_back(m2[m_1][k]);
        }
        for(int k=0; k<m1[0].size(); k++){
            MatO[i].push_back(m1[m_1][k]);
        }
    m_1++;
    }
    if(i<(2*(double(mo)/3)) && i>=(double(mo)/3)){
        for(int k=0; k<m3[0].size(); k++){
            MatO[i].push_back(m3[m_2][k]);
        }
        for(int k=0; k<Mat[0].size(); k++){
            MatO[i].push_back(Mat[m_2][k]);
        }
        for(int k=0; k<m3[0].size(); k++){
            MatO[i].push_back(m3[m_2][k]);
        }
    m_2++;
    }
    if(i>=(2*double(mo)/3) && i<mo){
       for(int k=0; k<m1[0].size(); k++){
            MatO[i].push_back(m1[m_3][k]);
        }
        for(int k=0; k<m2[0].size(); k++){
            MatO[i].push_back(m2[m_3][k]);
        }
        for(int k=0; k<m1[0].size(); k++){
            MatO[i].push_back(m1[m_3][k]);
        }
    m_3++;
    }
}
  return MatO;

}


int main(){
    std::cout<<"Unesite dimenzije matrice (m n): ";
    int m, n;
    std::cin>>m>>n;
    if(m<0 || n<0){
        std::cout<<"Dimenzije matrice moraju biti nenegativne!";
        return 0;
    }
    std::vector<std::vector<double>> Mat=UnesiMatricu(m, n);
    
    try{
        std::vector<std::vector<double>> MatO(OgledaloMatrica(Mat));
        std::cout<<"\nRezultantna matrica: "<<std::endl;
        for(int i=0; i<MatO.size(); i++){
            for(int j=0; j<MatO[0].size(); j++){
                std::cout<<" "<<std::right<<std::setw(3)<<MatO[i][j];
            }
            std::cout<<std::endl;
        }
    }
    catch(std::domain_error izuzetak){
    	std::cout<<izuzetak.what()<<std::endl;
    }

    return 0;
}