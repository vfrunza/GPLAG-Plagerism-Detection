/*B 2017/2018, Zadaća 2, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na forum (c2).
*/
#include <iostream>
#include <deque>
#include <vector>
#include <stdexcept>
#include <type_traits>

using std::cin;
using std::cout;

enum class SmjerKretanja {
	NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo
};

template <typename kontejner>
auto PjescaniSat(kontejner kont, SmjerKretanja s) -> typename std::remove_reference<decltype(kont)>::type {
	for(int i=0; i<kont.size(); i++) {
		for(int j=0; j<kont.at(i).size(); j++) {
			if(kont.at(i).at(j).size()!=kont.at(i).at(0).size() || kont.at(i).at(j).size()!=kont.size() ) 
			throw std::domain_error("3D matrica nema oblik kocke");
			}
	}
	for(int i=0; i<kont.size(); i++) {
		if(kont.at(i).size()%2==0) throw std::length_error("3D kontejner ne zadovoljava uvjet neparnosti");
		for(int j=0; j<kont.at(i).size(); j++) {
			if(kont.at(i).at(j).size()%2==0) throw std::length_error("3D kontejner ne zadovoljava uvjet neparnosti");
		}
	}
	
	
	typename std::remove_reference<decltype(kont)>::type povratni;
	//popunjavamo matricu za smjer gore-dolje
//	if((int)s==2) {
	for(int i=0; i<kont.size(); i++) {
		typename std::remove_reference<decltype(kont.at(i))>::type matrica;
		for(int j=0; j<kont.at(i).size(); i++) {
			int vel(0);
			typename std::remove_reference<decltype(kont.at(i).at(j))>::type pom;
				if(j<=kont.at(i).at(j).size()/2) {
					for(int k=j; k<j+kont.at(i).size()-vel; k++) {
				if((int)s==2)	pom.push_back(kont.at(i).at(j).at(k));
					vel+=2;
		
					}
					matrica.push_back(pom);
				}
				else {
			
					for(int k=kont.at(i).size()-j-1; k<kont.at(i).at(j).size()-kont.at(i).size()-j; k++) {
					if((int)s==2)	pom.push_back(kont.at(i).at(j).at(k));
					
					}
					matrica.push_back(pom);
				}
			}
			povratni.push_back(matrica);
				
			}
		
		
		//popunjavamo matricu za smjer dolje-gore
	//	if(s==1) {
			
	//	}
		
		
	return povratni;	
}
	



int main ()
{
	cout<<"Unesite dimenziju (x/y/z): ";
	int n;
	while(1) {
	cin>>n;
	if(n<=0) cout<<"Dimenzija nije ispravna, unesite opet: ";
	else break;
	}
	typedef std::vector<std::deque<std::deque<int>>> kvadar;
	kvadar kontejner;
	kontejner.resize(n);
	for(int i=0; i<n; i++) kontejner.at(i).resize(n);
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) kontejner.at(i).at(j).resize(n);
	}
	
	cout<<"Unesite elemente kontejnera: ";
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			for(int k=0; k<n; k++) cin>>kontejner.at(i).at(j).at(k);
		}
	}
			
	cout<<"Unesite smjer kretanja [0 - 5]: ";
	int smjer;
	while(1) {
		cin>>smjer;
		if(smjer<0 || smjer>5) cout<<"Smjer nije ispravan, unesite opet: ";
		else break;
	}
	
	try {
		kvadar pjescani;
		pjescani=PjescaniSat(kontejner, (SmjerKretanja)smjer);
		cout<<"Pjescani sat unesene matrice je: "<<std::endl;
		for(int i=0; i<pjescani.size(); i++)
			for(int j=0; j<pjescani.at(i).size(); j++) {
				for(int k=0; k<pjescani.at(i).at(j).size(); k++) cout<<pjescani.at(i).at(j).at(k)<<" ";
				cout<<std::endl;
			}
		cout<<std::endl;	
	}
	catch(std::domain_error izuzetak) {
		cout<<"\nIzuzetak: "<<izuzetak.what();
	}
	catch(std::logic_error izuzetak2) {
		cout<<"\nIzuzetak: "<<izuzetak2.what();
	}
	catch(...) {
		
	}
	return 0;
}