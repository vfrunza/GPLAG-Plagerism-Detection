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
typedef std::vector<std::vector<double>> Matrica;

Matrica KreirajMatricu(int br_redova, int br_kolona){
	return Matrica(br_redova, std::vector<double>(br_kolona));
} 

Matrica HorizontalnoOgledalo (Matrica m){
	if(m.size() == 0) return m; 
	Matrica ho(KreirajMatricu(m.size(), m[0].size()) );
	for (int i=0; i < ho.size(); i++){
	int l(0);
		for(int j = ho[i].size()-1; j>=0; j--){
			ho[i][l] = m[i][j];
			l++;
		}
	}
return ho; 	
} //ispravna!

Matrica VertikalnoOgledalo (Matrica m){
	if(m.size() == 0) return m; 
	Matrica vo(KreirajMatricu(m.size(), m[0].size())); 
	int l(0);
	for (int i = vo.size()-1; i >= 0; i--){
		for(int j=0; j< vo[i].size(); j++){
			vo[l][j] = m[i][j];
		}
		l++;
	}
return vo; 	
} // ispravna! 


Matrica KombinovanoOgledalo (Matrica m){
	if(m.size() == 0) return m; 
	Matrica ko(KreirajMatricu(m.size(), m[0].size()) );
	int k(0);
	for (int i=ko.size()-1; i >= 0; i--){ int l(0);
		for(int j=ko[i].size()-1; j>=0; j--){
			ko[k][l] = m[i][j];
			l++;
		}
		k++;
	}
	
return ko; 	
} //ispravna!



Matrica OgledaloMatrica (Matrica m){
	if(m.size() == 0) return m; 
	bool isti(true);
	for(int i=0; i < m.size(); i++){
		if(i < m.size()-1){
			if(m[0].size() != m[i+1].size()){
				isti = false; 
				break;
			}
		}
	}
	if(!isti) throw std::domain_error("Matrica nije korektna");
	Matrica om(KreirajMatricu(3*m.size(), 3*m[0].size())); 
	
	Matrica ho(HorizontalnoOgledalo(m));
	Matrica vo(VertikalnoOgledalo(m));
	Matrica ko(KombinovanoOgledalo(m));
	for(int i=0; i < m.size(); i++){
		for(int j=0; j < m[i].size(); j++)
			om[i][j] = ko[i][j];
	}
	for(int i=0; i < m.size(); i++){
		for(int j=0; j < m[i].size(); j++)
			om[i][j+m[i].size()] = vo[i][j];
	}
	
	for(int i=0; i < m.size(); i++){
		for(int j=0; j < m[i].size(); j++)
			om[i][j+2*m[i].size()] = ko[i][j];
	}
	
	for(int i=0; i < m.size(); i++){
		for(int j=0; j < m[i].size(); j++)
			om[i+m.size()][j] = ho[i][j];
	}
	for(int i=0; i < m.size(); i++){
		for(int j=0; j < m[i].size(); j++)
			om[i+m.size()][j+m[i].size()] = m[i][j];
	}
	for(int i=0; i < m.size(); i++){
		for(int j=0; j < m[i].size(); j++)
			om[i+m.size()][j+2*m[i].size()] = ho[i][j];
	}
	for(int i=0; i < m.size(); i++){
		for(int j=0; j < m[i].size(); j++)
			om[i+2*m.size()][j] = ko[i][j];
	}
	for(int i=0; i < m.size(); i++){
		for(int j=0; j < m[i].size(); j++)
			om[i+2*m.size()][j+m[i].size()] = vo[i][j];
	}
	for(int i=0; i < m.size(); i++){
		for(int j=0; j < m[i].size(); j++)
			om[i+2*m.size()][j+2*m[i].size()] = ko[i][j];
	}
	
	
	return om; 
} //ispravna!
	


int main ()
{	try{
	int m, n;
	std::cout << "Unesite dimenzije matrice (m n): ";
	std::cin >> m >> n; 
	if(m < 0 || n < 0) {std::cout << "Dimenzije matrice moraju biti nenegativne!" << std::endl; return 0;}

	Matrica mat(KreirajMatricu(m, n));
	
	std::cout << "Unesite elemente matrice: " << std::endl; 
	
	for(int i=0; i < m; i++){
		for(int j=0; j < n; j++){
			std::cin >> mat[i][j];
		}
	}// unos elemenata matrice
	
	std::cout << std::endl; 
	
	auto mo(OgledaloMatrica(mat));
	std::cout << "Rezultantna matrica: " << std::endl;
	
	for(int i=0; i<mo.size(); i++){
		for(int j=0; j<mo[0].size(); j++) std::cout << std::setw(4) << mo[i][j];
		std::cout << std::endl; 
	} 

}
catch (std::domain_error izuzetak){
	std::cout << izuzetak.what();
}
	return 0;
}