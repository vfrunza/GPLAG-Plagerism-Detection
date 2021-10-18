/*B 2016/2017, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>
typedef std::vector<std::vector<double>>Matrica;
Matrica KreirajMatricu(int br_r,int br_k) {
	return Matrica(br_r, std::vector<double>(br_k));
}
Matrica UnesiMatricu(int br_r, int br_k) {
	auto m(KreirajMatricu(br_r,br_k));
	for(int i=0; i<br_r; i++) {
		for(int j=0; j<br_k; j++) {
			std::cin>>m[i][j];
		}	
	}
	return m;
}
void IspisiMatricu(Matrica m) {
	for (int i=0; i<m.size(); i++) {
		for(int j=0; j<m[0].size(); j++)
		std::cout<<std::setw(4)<<m[i][j];
		std::cout<<std::endl;
	}
}
Matrica Horizontalno(Matrica m) {
	for(int i=0; i<m.size(); i++) {
		for(int j=m[0].size()-1; j>=0; j--)
		std::cout<<std::setw(4)<<m[i][j];
		std::cout<<std::endl;
	}
 return m;	
}
Matrica Vertikalno(Matrica m) {
	for(int i=m.size()-1; i>=0; i--) {
		for(int j=0; j<m[0].size(); j++)
		std::cout<<std::setw(4)<<m[i][j];
		std::cout<<std::endl;
	}
 return m;	
}
Matrica HorizontalnoIVertikalno(Matrica m) {
	for(int i=m.size()-1; i>=0; i--) {
		for(int j=m[0].size()-1; j>=0; j--)
		std::cout<<std::setw(4)<<m[i][j];
		std::cout<<std::endl;
	}
 return m;	
}
Matrica OgledaloMatrica(Matrica m) {
	Matrica h=Horizontalno(m);
	Matrica v=Vertikalno(m);
	Matrica hv=HorizontalnoIVertikalno(m);
	Matrica pomocna;
		std::vector<double> redmatrice;
	if(
		for(int i=0; i<m.size(); i++) {
				for(int j=0; j<hv[0].size(); j++){
						redmatrice.push_back(hv[i][j]); 
				}
				for(int j=0;j<v[0].size(); j++){
				redmatrice.push_back(v[i][j]);
			}
				for(int j=0; j<hv[0].size(); j++) {
					redmatrice.push_back(hv[i][j]); 
				}
				pomocna.push_back(redmatrice);
				redmatrice.clear();	}
	for(int i=0; i<pomocna.size(); i++) {
		for(int j=0; j<h[0].size(); j++) {
			redmatrice.push_back(h[i][j]);
		}
		for(int j=0; j<m[0].size();j++) {
			redmatrice.push_back(m[i][j]);
		}
		for(int j=0; j<h[0].size();j++) {
			redmatrice.push_back(h[i][j]);
		}
	pomocna.push_back(redmatrice);
		redmatrice.clear();
	}
	for(int i=0; i<pomocna.size(); i++) {
		for(int j=0;j<hv[0].size();j++){
			redmatrice.push_back(hv[i][j]);
		}
		for(int j=0;j<v[0].size();j++) {
			redmatrice.push_back(v[i][j]);
		}
		for(int j=0;j<hv[0].size();j++) {
			redmatrice.push_back(hv[i][j]);
		}
		pomocna.push_back(redmatrice);
	}
	
	return pomocna;		
}		
			
		
int main() {
Matrica M;
int m,n;
std::cout<<"Unesite dimenzije matrice (m n): ";
std::cin>>m>>n;
if(m<0 || n<0) {
	std::cout<<"Dimenzije matrice moraju biti nenegativne!";
	return 0;
}
std::cout<<"Unesite elemente matrice: ";
M=UnesiMatricu(m, n);
std::cout<<"\nRezultantna matrica: \n";
IspisiMatricu(OgledaloMatrica(M));

	
	return 0;
}