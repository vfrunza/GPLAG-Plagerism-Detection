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

typedef std::vector<std::vector<double>> matrica;


matrica ZamijeniRedove(matrica m) {
	matrica povratna;
	for(int i=m.size()-1; i>=0; i--) {
		povratna.push_back(m[i]);
	}
	return povratna;
}

matrica ZamijeniKolone(matrica m) {
	matrica povratna;
	for(int i=0; i<m.size(); i++) {
		std::vector<double> pomocni;
		for(int j=m[i].size()-1; j>=0; j--) {
			pomocni.push_back(m[i][j]);
		}
		povratna.push_back(pomocni);
	}
	return povratna;
}


matrica OgledaloMatrica(matrica m) {
	matrica povratna;
	
	for(int i=0; i<m.size(); i++) {
		if(m[0].size()!=m[i].size())
	throw std::domain_error("Matrica nije korektna");
	}
	
	
	auto horizontalna=ZamijeniKolone(m);
	auto vertikalna=ZamijeniRedove(m);
	auto kombinovana=ZamijeniKolone(ZamijeniRedove(m));
	
	for(int i=0; i<m.size(); i++) {
		std::vector<double> clanovi;
		for(auto x : kombinovana[i]) clanovi.push_back(x);
		for(auto x : vertikalna[i]) clanovi.push_back(x);
		for(auto x : kombinovana[i]) clanovi.push_back(x);
		povratna.push_back(clanovi);
	}
	
	for(int i=0; i<m.size(); i++) {
		std::vector<double> clanovi;
		for(auto x : horizontalna[i]) clanovi.push_back(x);
		for(auto x : m[i]) clanovi.push_back(x);
		for(auto x : horizontalna[i]) clanovi.push_back(x);
		povratna.push_back(clanovi);
	}
	
	for(int i=0; i<m.size(); i++) {
		std::vector<double> clanovi;
		for(auto x : kombinovana[i]) clanovi.push_back(x);
		for(auto x : vertikalna[i]) clanovi.push_back(x);
		for(auto x : kombinovana[i]) clanovi.push_back(x);	
		povratna.push_back(clanovi);
	}
	
 return povratna;
} 

int main ()
{
	int m,n;
	std::cout<<"Unesite dimenzije matrice (m n): ";
	std::cin>>m>>n;
	if(m<0 || n<0) {
	std::cout<<"Dimenzije matrice moraju biti nenegativne!";
	return 0; }
	matrica mat(m, std::vector<double>(n) );
	std::cout<<"Unesite elemente matrice: ";
	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			std::cin>>mat[i][j];
		}
	}
	
	try {
		std::cout<<"\nRezultantna matrica: \n";
		matrica ogledalo=OgledaloMatrica(mat);
	
	

	for( auto x : ogledalo) {
		for(auto y : x)
		std::cout<<std::right<<std::setw(4)<<y;
		std::cout<<std::endl;
	}
	
	}
	
		catch(std::domain_error izuzetak) {
		std::cout <<"Nekorektna matrica"<<izuzetak.what();
	}

	return 0;
}