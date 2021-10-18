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
typedef std::vector<std::vector<double>> matrica;

matrica Vertikalno(matrica m){
	for(int i=0; i<m[0].size(); i++){
		int vel=m.size()-1;
		for(int j=0; j<(m.size())/2; j++){
			double temp=m[j][i];
			m[j][i]=m[vel][i];
			m[vel][i]=temp;
			vel--;
		}
	}
	return m;
}
matrica Horizontalno(matrica h){
	for(int i=0; i<h.size(); i++){
		int vel=h[i].size()-1;
		for(int j=0; j<(h[i].size())/2; j++){
			double temp=h[i][j];
			h[i][j]=h[i][vel];
			h[i][vel]=temp;
			vel--;
		}
	}
	return h;
}
matrica KreirajMatricu(int brred, int brkol){
    matrica m;
    m.resize(brred);
    for(int i=0; i<brred; i++){
        m[i].resize(brkol);
    }
    return m;
}

matrica OgledaloMatrica(matrica m){
	matrica h=m,v=m,hv;
	matrica mat;
	if(m.size()==0) return mat;
	for(int i=0; i<m.size()-1; i++){
        if(m[i].size()!= m[i+1].size()){
            throw std::domain_error("Matrica nije korektna.");
            break;
        }
	}
	int duzina=3*(m.size()), sirina=3*(m[0].size());
	mat.resize(duzina);
	for(int i=0; i<duzina; i++) {
        mat[i].resize(sirina);
	}
	h=Horizontalno(h);
	v=Vertikalno(v);
	hv=h;
	hv=Vertikalno(hv);
	int m1=m.size(), m2=2*m.size(), n1=m[0].size(), n2=2*m[0].size();
	for(int i=0; i<m1; i++){
		for(int j=0; j<n1; j++){
          	mat[i][j]=hv[i][j];
          	mat[i][j+n2]=hv[i][j];
          	mat[i+m2][j]=hv[i][j];
          	mat[i+m2][j+n2]=hv[i][j];
		}
	}
    for(int i=0; i<m1; i++){
        for(int j=0; j<n1; j++){
            mat[i][j+n1]=v[i][j];
            mat[i+m2][j+n1]=v[i][j];
        }
    }
	for(int i=0; i<m1; i++){
        for(int j=0; j<n1; j++){
            mat[i+m1][j+n1]=m[i][j];
        }
	}
	for(int i=0; i<m1; i++){
        for(int j=0; j<n1; j++){
            mat[i+m1][j]=h[i][j];
            mat[i+m1][j+n2]=h[i][j];
        }
	}
	return mat;
}
int main ()
{
	int m1,n;
	std::cout<<"Unesite dimenzije matrice (m n): ";
	std::cin>> m1 >>n;
	if(m1<0 || n<0){ std::cout<<"Dimenzije matrice moraju biti nenegativne!"; return 0;}
	matrica m(m1,std::vector<double>(n));
	std::cout<<"Unesite elemente matrice: ";
	for(int i=0; i<m1; i++){
		for(int j=0; j<n; j++){
			std::cin>> m[i][j];
		}
	}
	try{
        matrica h=OgledaloMatrica(m);
        std::cout<<std::endl<<"Rezultantna matrica: "<<std::endl;
        for(int i=0; i<h.size(); i++){
            for(int j=0; j<h[i].size(); j++){
                std::cout<<std::setw(4)<<h[i][j];
            }
            std::cout<<std::endl;
        }
	}
	catch(std::domain_error izuzetak){
        std::cout<<izuzetak.what()<<std::endl;
    }
	return 0;
}
