/*B 2016/2017, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/

#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <stdexcept>

typedef std::vector<std::vector<double>> Matrica;

Matrica KreirajMatricu(int m, int n) {
	return Matrica(m, std::vector<double> (n));
}


Matrica UnesiMatricu(int br_redova, int br_kolona) {

 auto m(KreirajMatricu(br_redova, br_kolona));
 
 for(int i = 0; i < br_redova; i++) {
 for(int j = 0; j < br_kolona; j++) {
 std::cin >> m[i][j];
 }
}
return m;
}
 
 // VERTIKALNO OGLEDALO 
 Matrica Vertikalno( Matrica m) {
 	std::vector<double> pomocni;
 	for(int i=0; i<m.size()/2; i++) {
 		pomocni = std::move(m[i]);
 		m[i] = std::move(m[m.size()-1-i]);
 		m[m.size()-1-i] = std::move(pomocni);
 	}
 	return m;
 }
 
 // HORIZONTALNO OGLEDALO
  Matrica Horizontalno( Matrica m) {
  	double tmp;
  	for(int i=0; i<m.size(); i++) {
  		for(int j=0; j<m[i].size()/2; j++) {
  		tmp = m[i][j];
  		m[i][j] = m[i][m[i].size() - 1-j];
  		m[i][m[i].size() - 1-j] = tmp;
  		
  		}
  	}
  	return m;
  }
  
  // KOMBINOVANO OGLEDALO
  Matrica Kombinovano ( Matrica m ) {
  	m = Horizontalno(m);
  	m = Vertikalno(m);
  	
  	return m;
  }
  
  // OGLEDALO MATRICA
  Matrica OgledaloMatrica( Matrica m) {
  	Matrica h (Horizontalno(m));
  	Matrica v (Vertikalno(m));
  	Matrica hv (Kombinovano(m));
  	
  	if(m.size() == 0 ) return m;
  	
  	for(int i=0; i<m.size(); i++) {
  		for(int j=0; j<m[i].size(); j++) {
  			if (m[i].size() != m[0].size()) throw std::domain_error("Matrica nije korektna");
  		}
   	}
  	m = Matrica (3*m.size(), std::vector<double> (3*m[0].size()) );

  	for(int i = 0; i<hv.size(); i++) {
  		for(int j=0; j<hv[i].size(); j++) {
  			m[i][j] = hv[i][j];
  			m[i][hv[i].size()*2+j] = hv[i][j];
  			m[i][hv[i].size()*2-1-j] = hv[i][j];
  			
  			// Sredina 
   			m[hv.size()+i][j] = h[i][j];
  			m[hv.size()+i][hv[i].size()*2+j] = h[i][j];
  			m[hv.size()+i][hv[i].size()*2-1-j] = h[i][j];
  			
  			// Zadnji redovi
  			m[hv.size()*2+i][j] = hv[i][j];
  			m[hv.size()*2+i][hv[i].size()*2+j] = hv[i][j];
  			m[hv.size()*2+i][hv[i].size()*2-1-j] = hv[i][j];
  		}
  	}
  	return m;
  }
 
void IspisiMatricu(Matrica m) {
	for(int i=0; i<m.size(); i++) {
		for(int j=0; j<m[i].size(); j++) 
		std::cout << std::setw(4) << m[i][j];
		std::cout << std::endl;
	}
}
 
int main ()
{
	try 
	{
	int m, n;
	std::cout <<"Unesite dimenzije matrice (m n): ";
	std::cin >> m >> n;
	
	if(m<0 || n<0) {
		std::cout << "Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	
	std::cout <<"Unesite elemente matrice: ";
	auto m1 = (UnesiMatricu(m, n));

	std::cout <<"\nRezultantna matrica: \n";
	IspisiMatricu(OgledaloMatrica(m1));
}
catch (std::domain_error izuzetak) {
std::cout << izuzetak.what() << std::endl; 
	
}
	return 0;
}