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

typedef std::vector<std::vector<double>> Matrica;

bool DaLiJeGrbava(Matrica m) {
	for(int i=0; i<m.size(); i++) {
		if(m[0].size()!=m[i].size())
			return true;
	}
	return false;
}

Matrica OgledaloMatrica(Matrica m) {
	if(DaLiJeGrbava(m))
		throw std::domain_error ("Matrica nije korektna");
	
	Matrica nova;
	nova.resize(3*m.size());
	int R(m.size()-1), brojacR(1);
	for(int i=0; i<nova.size(); i++) {
		int brojacK(1);
		for(int j=0; j<3*m[0].size(); j++) {
			int K=m[0].size()-1;
			for(int k=0; k<m[0].size(); k++) {
			 	if(brojacK%2!=0) {
			 		nova[i].push_back(m[R][K]);
			 		K--;
			 		j++;
			 	}
			 	else if(brojacK%2==0) {
			 		nova[i].push_back(m[R][k]);
			 		j++;
			 	}
			 	if(k+1==m[0].size()) {
			 		j--;
			 		brojacK++;
			 	}
			}
		}
		if(m.size()==1)
			continue;
		if(i!=0 && (i+1)%m.size()==0) {
			brojacR++;
			R--;
			if(brojacR%2!=0)
				R=m.size();
		}
		if(brojacR%2!=0)
			R--;
		else if(brojacR%2==0)
			R++;
	}
	return nova;
}

int main ()
{
	int m,n;
	
	std::cout<<"Unesite dimenzije matrice (m n): ";
	std::cin>>m>>n;
	if(m<0 || n<0) {
		std::cout<<"Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	std::cout<<"Unesite elemente matrice: ";
	Matrica mat(m, std::vector<double> (n));
	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			int clan;
			std::cin>>clan;
			mat[i][j]=clan;
		}
	}
	try {
	
		Matrica nova(OgledaloMatrica(mat));
		std::cout<<std::endl<<"Rezultantna matrica:"<<std::endl;
		for(int i=0; i<nova.size(); i++) {
			for(int j=0; j<nova[0].size(); j++)
				std::cout<<std::setw(4)<<nova[i][j];
			std::cout<<std::endl;	
		}
	}
	catch(std::domain_error IZUZETAK) {
		std::cout<<"Izuzetak: "<<IZUZETAK.what();
	}
	return 0;
}