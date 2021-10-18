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

Matrica ObrniRedove(Matrica m) {
	Matrica m2; //pomocna matrica
	for (int i=m.size()-1; i>=0; i--)
		m2.push_back(m[i]);
	return m2;
}

Matrica ObrniKolone(Matrica m) {
	Matrica m2;
	for (int i=0; i<m.size(); i++) {
		std::vector<double> pomocni;
		for (int j=m[i].size()-1; j>=0; j--)
			pomocni.push_back(m[i][j]);
		m2.push_back(pomocni);
	}
	return m2;
}

std::vector<double> SpojiVektore(std::vector<double> x, std::vector<double> y, std::vector<double> z) {
	std::vector<double> v;
	for (double s:x) v.push_back(s);
	for (double r:y) v.push_back(r);
	for (double d:z) v.push_back(d);
	return v;
}

Matrica OgledaloMatrica(Matrica m) {
	for (int i=0; i<m.size(); i++) 
		if (m[i].size() != m[0].size()) throw std::domain_error("Matrica nije korektna");
		
	Matrica m2;
	Matrica hv = ObrniRedove(ObrniKolone(m));    //Kombinovano ogledalo
	Matrica v = ObrniRedove(m);                  //Vertikalno ogledalo
	Matrica h = ObrniKolone(m);                  //Horizontalno ogledalo

	for (int i=0; i<m.size(); i++) 
		m2.push_back(SpojiVektore(hv[i], v[i], hv[i]));
	
	for (int i=0; i<m.size(); i++) 
		m2.push_back(SpojiVektore(h[i], m[i], h[i]));
	
	for (int i=0; i<m.size(); i++) 
		m2.push_back(SpojiVektore(hv[i], v[i], hv[i]));
	
	return m2;
}

int main ()
{
    try {
    	int m{}, n{};
    	std::cout<<"Unesite dimenzije matrice (m n): ";
		std::cin>>m>>n;
		if (m<0 || n<0) {
			std::cout<<"Dimenzije matrice moraju biti nenegativne!";
		    return 0;
		}
		
		Matrica m1(m, std::vector<double>(n));
		
		std::cout<<"Unesite elemente matrice: "<<std::endl;
		
		for (int i=0; i<m; i++) {
			for (int j=0; j<n; j++)
				std::cin>>m1[i][j];
		}
		
		Matrica m2 = OgledaloMatrica(m1);
		
		std::cout<<"Rezultantna matrica: "<<std::endl;
		
		for (auto x:m2) {
			for (auto y:x)  std::cout<<std::setw(4)<<y;
			std::cout<<std::endl;
		}
    }
    
    catch (std::domain_error izuzetak) {
    	std::cout<<izuzetak.what()<<std::endl;
    }
    
	return 0;
}
