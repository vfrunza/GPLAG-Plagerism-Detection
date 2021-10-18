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
#include <stdexcept>
using std::cout;
using std::cin;
using std::endl;
std::vector<std::vector<double>> OgledaloMatrica (std::vector<std::vector<double>> matrica) {
		std::vector<std::vector<double>> vertikalna, horizontalna, kombinovana, rezultat;
	std::vector<double> v, pomocni;
	try{
		bool grbava=false;
		for(int i=0; i<matrica.size(); i++) {
			if(matrica[i].size()!=matrica[0].size()) {
				grbava=true;
				break;
			} 
		} if(grbava) throw std::domain_error("Matrica nije korektna");
	rezultat.resize(3*matrica.size());
	for(int i=0; i<matrica.size(); i++) {
		v=pomocni;
		for(int j=matrica[0].size()-1; j>=0; j--) {
			v.push_back(matrica[i][j]);
		} horizontalna.push_back(v);
	}
	for(int i=matrica.size()-1; i>=0; i--) {
		v=pomocni;
		for(int j=0; j<matrica[0].size(); j++) {
			v.push_back(matrica[i][j]);
		} vertikalna.push_back(v);
	}
	for(int i=matrica.size()-1; i>=0; i--) {
		v=pomocni;
		for(int j=matrica[0].size()-1; j>=0; j--) {
		v.push_back(matrica[i][j]);
		} kombinovana.push_back(v);
	}
	for(int i=0; i<matrica.size(); i++) {
		for(int j=0; j<matrica[0].size(); j++) {
			rezultat[i].push_back(kombinovana[i][j]);
		} 
	}
	for(int i=0; i<matrica.size(); i++) {
		for(int j=0; j<matrica[0].size(); j++) {
			 rezultat[i].push_back(vertikalna[i][j]);
		}
	}
	for(int i=0; i<matrica.size(); i++) {
		for(int j=0; j<matrica[0].size(); j++) {
			rezultat[i].push_back(kombinovana[i][j]);
		} 
	}
	for(int i=0; i<matrica.size(); i++) {
		for(int j=0; j<matrica[0].size(); j++) {
			rezultat[i+matrica.size()].push_back(horizontalna[i][j]);
		} 
	}
	for(int i=0; i<matrica.size(); i++) {
		for(int j=0; j<matrica[0].size(); j++) {
			 rezultat[i+matrica.size()].push_back(matrica[i][j]);
		}
	}
	for(int i=0; i<matrica.size(); i++) {
		for(int j=0; j<matrica[0].size(); j++) {
			rezultat[i+matrica.size()].push_back(horizontalna[i][j]);
		} 
	}
	for(int i=0; i<matrica.size(); i++) {
		for(int j=0; j<matrica[0].size(); j++) {
		rezultat[i+2*matrica.size()].push_back(kombinovana[i][j]);
		} 
	}
	for(int i=0; i<matrica.size(); i++) {
		for(int j=0; j<matrica[0].size(); j++) {
			rezultat[i+2*matrica.size()].push_back(vertikalna[i][j]);	
		} 
	}
	for(int i=0; i<matrica.size(); i++) {
		for(int j=0; j<matrica[0].size(); j++) {
			rezultat[i+2*matrica.size()].push_back(kombinovana[i][j]);
		} 
	} } catch(std::domain_error greska) {
		cout<<greska.what();	}
	return rezultat;
}

int main ()
{
	int m(0), n(0);
std::vector<std::vector<double>> matrica;
	cout<<"Unesite dimenzije matrice (m n): ";
	try{
	cin>>m>>n;
	
	if(m<0 || n<0) {throw std::range_error("Dimenzije matrice moraju biti nenegativne!");}}
	catch(std::range_error e) {
		cout<<e.what();
	} if(m>=0 && n>=0) {
		matrica.resize(m);
	for(int i=0; i<m; i++) {
		matrica[i].resize(n);
	}
	cout<<"Unesite elemente matrice: ";
	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			std::cin >> matrica[i][j];
		}
	}
std::vector<std::vector<double>> ogledalce(OgledaloMatrica(matrica));
cout<<"\nRezultantna matrica:"<<endl;
cout<<" ";
	for(int i=0; i<ogledalce.size(); i++) {
		for(int j=0; j<ogledalce[0].size(); j++) {
			cout<<std::setw(3)<<ogledalce[i][j]<<" ";
		} cout<<endl;
	if(i!=ogledalce.size()-1)	cout<<" ";
	}}
	return 0;
}