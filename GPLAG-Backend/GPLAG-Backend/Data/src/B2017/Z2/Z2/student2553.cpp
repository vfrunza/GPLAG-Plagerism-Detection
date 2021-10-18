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
#include <algorithm>
#include <vector>
#include <deque>
#include <iomanip>
#include <type_traits>
#include <stdexcept>

using std::cout;
using std::cin;
using std::endl;

enum class SmjerKretanja { NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo }; 
 
 
template<typename NekiTip>
NekiTip PjescaniSat2D(const NekiTip &kontejner, SmjerKretanja smjer){ //2d za sve osim NaprijedNazad i NazadNaprijed
	
	int n(kontejner.size());
	
	NekiTip PjescaniSat(n);

	int k(0),l(n);
	
	if(smjer!=SmjerKretanja::NaprijedNazad && smjer!=SmjerKretanja::NazadNaprijed){
		for(int i=0;i<n;i++){
			for(int j=k;j<l;j++){
			if(smjer==SmjerKretanja::GoreDolje) PjescaniSat.at(i).push_back(kontejner.at(i).at(j));
			else if(smjer==SmjerKretanja::DoljeGore) PjescaniSat.at(i).push_back(kontejner.at(n-i-1).at(j));
			else if(smjer==SmjerKretanja::DesnoLijevo) PjescaniSat.at(i).push_back(kontejner.at(j).at(n-i-1));
			else PjescaniSat.at(i).push_back(kontejner.at(j).at(i));
			} 
			if(i<n/2){ k++; l--;}
			else{ k--; l++;}
		}
	}
	
	
	return PjescaniSat;
}

template <typename NekiTip>
NekiTip PjescaniSat(const NekiTip &kontejner, SmjerKretanja smjer){ //3d 

	
	int n(kontejner.size());
	
	for(int i=0;i<n;i++){
		for(int j=0;j<kontejner.at(i).size();j++){
			if(kontejner.at(i).size()!=n || kontejner.at(i).at(j).size()!=n) throw std::domain_error ("3D matrica nema oblik kocke");
			else if(n%2==0) throw std::length_error ("3D kontejner ne zadovoljava uvjet neparnosti");
		}
	}
			
			
	
	
	int k(0),l(n);
	
    typename std::remove_reference<decltype(kontejner.at(0))>::type matrica (n);
    
	if(smjer!=SmjerKretanja::NaprijedNazad && smjer!=SmjerKretanja::NazadNaprijed){
	NekiTip PjescaniSat(n);
	for(int i=0;i<n;i++){
	auto ploha(PjescaniSat2D(kontejner.at(i),smjer));
	PjescaniSat.at(i)=ploha;
	}
	
	return PjescaniSat;
	}
	
	
	else{
		NekiTip PjescaniSat;
		for(int m=0;m<n;m++){
			k=0;
			l=n;
			PjescaniSat.push_back(matrica);// ubacivanje matrice
		for(int i=0;i<n;i++){
			for(int j=k;j<l;j++){
				if(smjer==SmjerKretanja::NaprijedNazad) PjescaniSat.at(m).at(i).push_back(kontejner.at(i).at(m).at(j));
				else PjescaniSat.at(m).at(i).push_back(kontejner.at(n-i-1).at(m).at(j));
			}
			if(i<n/2){ k++; l--;}
			else{ k--; l++;}
		}
	
	}
	
	return PjescaniSat;
	}
}


int main ()
{
	cout<<"Unesite dimenziju (x/y/z): ";
	int dimenzija;
	
	while(!(cin>>dimenzija) || dimenzija<0){
		std::cin.clear();
		std::cin.ignore(10000,'\n');
		cout<<"Dimenzija nije ispravna, unesite opet: ";
	}

	std::vector<std::deque<std::deque<int>>> kontejner(dimenzija,std::deque<std::deque<int>>(dimenzija,std::deque<int>(dimenzija)));
	

	cout<<"Unesite elemente kontejnera: ";
	for(int i=0;i<dimenzija;i++){
		for(int j=0;j<dimenzija;j++){
			for(int k=0;k<dimenzija;k++){
				cin>>kontejner.at(i).at(j).at(k);
			}
		} 
	}
	
	cout<<"Unesite smjer kretanja [0 - 5]: ";
	int smjer_kretanja;
	
	while (!(cin>>smjer_kretanja) || smjer_kretanja>5 || smjer_kretanja<0){
		std::cin.clear();
		std::cin.ignore(10000,'\n');
		cout<<"Smjer nije ispravan, unesite opet: ";
	} 
	
	try{
		
	auto m(PjescaniSat(kontejner, SmjerKretanja(smjer_kretanja)));
	
	cout<<endl<<"Pjescani sat unesene matrice je:"<<endl<<endl;
	
	for(int k=0;k<m.size();k++){
	for(int i=0;i<m.at(k).size();i++){ 
	for(int j=0;j<m.at(k).at(i).size();j++) {
		if(i<=dimenzija/2 && j==0) cout<<std::setw(4*(i+1))<<m.at(k).at(i).at(j);
		else if(j==0) cout<<std::setw(4*(dimenzija-i))<<m.at(k).at(i).at(j);
		else cout<<std::setw(4)<<m.at(k).at(i).at(j);
	}
	cout<<endl;
	}
	cout<<endl;
	}
	
	}
	catch(std::domain_error izuzetak){
		cout<<endl<<"Izuzetak: "<<izuzetak.what()<<endl;
	}
	catch(std::length_error izuzetak){
		cout<<endl<<"Izuzetak: "<<izuzetak.what()<<endl;
	}

	return 0;
}
