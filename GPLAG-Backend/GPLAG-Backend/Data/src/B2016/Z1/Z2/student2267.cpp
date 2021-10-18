/*B 2016/2017, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <vector>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <stdexcept>

using namespace std;

typedef std::vector<std::vector<double>> Matrica;

Matrica dajHorizontalnoOgledalo(Matrica M){
	Matrica H(M.size(), vector<double> (M[0].size()));
	
	for (int i=0; i<M.size(); i++) {
		for (int j=0; j<M[i].size(); j++) {
			H[i][j] = M[i][M[i].size()-1-j];
		}
	}
	return H;
	
}



Matrica dajVertikalnoOgledalo(Matrica M){
	
	
}


Matrica dajKombinacijaOgledalo(Matrica M){
	
	
}


bool daLiJeGrbava(Matrica M){
	for (int i=1; i<M.size(); i++) {
		if (M[i].size() != M[0].size()) {
			return true;
		} 
	}
	
	return false;
}

void ispisi(Matrica M){
	for (int i=0; i<M.size(); i++) {
		for (int j=0; j<M[i].size(); j++) {
			cout<<M[i][j]<< " ";
		}
		std::cout<<std::endl;
	}
} 

Matrica OgledaloMatrica (Matrica M) {
	
	if(daLiJeGrbava(M)) throw domain_error("Matrica nije korektna");
	Matrica OM(3*M.size(),vector<double>());
	
	Matrica H = dajHorizontalnoOgledalo(M);
	ispisi(H);
	return OM;
}


int main ()
{
	int m;
	int n;
	cout<<"REzultata";
	std::cin>>m>>n;
	Matrica M(m, vector<double>(n));
	
	for (int i=0; i<M.size(); i++) {
		for (int j=0; j<M[i].size(); j++) {
			cin>>M[i][j];
			
		}
	}
	return 0;
}