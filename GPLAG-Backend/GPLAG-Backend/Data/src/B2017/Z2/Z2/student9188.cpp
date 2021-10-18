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
#include <iomanip>
#include <type_traits>
#include <stdexcept>
#include <vector>
#include <deque>

enum class SmjerKretanja
{
    NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo
};
template <typename Tip1>
auto PjescaniSat(Tip1 kont, SmjerKretanja smjer)->typename std::remove_reference<decltype(kont)>::type {
	if(kont.size()%2==0) throw std::length_error("3D kontejner ne zadovoljava uvjet neparnosti");
	for(int i=0; i<kont.size(); i++) {
		for(int j=0; j<kont.at(i).size(); j++) {
			//"LIJINJA ISPOD" >> PRVI USLOV PROVJERAVA DA LI SU MATRICE KVADRATNE A DRUGI PROVJERAVA DA LI JE BROJ PLOHA JEDNAK BROJ REDOVA SVAKE PLOHE
			if(kont.at(i).at(j).size()!=kont.at(i).size() || kont.size()!=kont.at(i).at(j).size()) throw std::domain_error("3D matrica nema oblik kocke");
		}
	}
	int a(-100);
	if(kont.size()>0 && kont.at(0).size()>0)  a = kont.at(0).size();
	for(int i=0; i<kont.size(); i++) if(kont.at(i).size()!=a) throw std::domain_error("3D matrica nema oblik kocke");
	typename std::remove_reference<decltype(kont)>::type Sat;

	if((int)smjer==2) {
		for(int i=0;i<kont.size();i++){
			typename std::remove_reference<decltype(kont.at(0))>::type satic;
			for(int j=0;j<kont.at(i).size();j++){
				typename std::remove_reference<decltype(kont.at(0).at(0))>::type jos_manji_satic;
				for(int k=0;k<kont.at(i).size();k++){
					if(j>kont.at(i).size()/2 && j>=k && j+k>=kont.at(i).size()-1 && j+k<=2*kont.at(i).size()-2) jos_manji_satic.push_back(kont.at(i).at(j).at(k));
					else if(j==kont.at(i).size()/2 && j==k) jos_manji_satic.push_back(kont.at(i).at(j).at(k)); 
					else if(j<kont.at(i).size()/2 && j<=k && k>=0 && j+k<=kont.at(i).size()-1) jos_manji_satic.push_back(kont.at(i).at(j).at(k));
				}
				satic.push_back(jos_manji_satic);
			}
			Sat.push_back(satic);
		}
	} else if((int)smjer==3) {
		for(int i=0; i<kont.size(); i++) {
			typename std::remove_reference<decltype(kont.at(0))>::type satic;
			for(int j=kont.at(i).size()-1; j>=0; j--) {
				typename std::remove_reference<decltype(kont.at(0).at(0))>::type jos_manji_satic;
				for(int k=0; k<kont.size(); k++) {
					if(j>kont.at(i).size()/2 && j>=k && j+k>=kont.at(i).size()-1 && j+k<=2*kont.at(i).size()-2) jos_manji_satic.push_back(kont.at(i).at(j).at(k));
					else if(j==kont.at(i).size()/2 && j==k) jos_manji_satic.push_back(kont.at(i).at(j).at(k));
					else if(j<kont.at(i).size()/2 && j<=k && k>=0 && j+k<=kont.at(i).size()-1) jos_manji_satic.push_back(kont.at(i).at(j).at(k));
				}
				satic.push_back(jos_manji_satic);
			}
			Sat.push_back(satic);
		}
	} else if((int)smjer==5) {
		for(int i=0; i<kont.size(); i++) {
			typename std::remove_reference<decltype(kont.at(0))>::type satic;
			for(int j=kont.at(i).size()-1; j>=0; j--) {
				typename std::remove_reference<decltype(kont.at(0).at(0))>::type jos_manji_satic;
				for(int k=0; k<kont.at(i).at(j).size(); k++) {
					if(j<kont.size()/2 && j<=k && k>=0 && j+k<=kont.at(i).size()-1) jos_manji_satic.push_back(kont.at(i).at(k).at(j));
					else if(j==kont.at(i).size()/2 && k==j) jos_manji_satic.push_back(kont.at(i).at(k).at(j));
					else if(j>kont.at(i).size()/2 && j>=k && k+j>=kont.size()-1 && j+k<=2*kont.at(i).size()-2) jos_manji_satic.push_back(kont.at(i).at(k).at(j));
				}
				satic.push_back(jos_manji_satic);
			}
			Sat.push_back(satic);
		}
	} else if((int)smjer==4) {
		for(int i=0; i<kont.size(); i++) {
			typename std::remove_reference<decltype(kont.at(0))>::type satic;
			for(int j=0; j<kont.at(i).size(); j++) {
				typename std::remove_reference<decltype(kont.at(0).at(0))>::type jos_manji_satic;
				for(int k=0; k<kont.at(i).size(); k++) {
					if(j>kont.at(i).size()/2 && j>=k && k+j>=kont.size()-1 && j+k<=2*kont.at(i).size()-2) jos_manji_satic.push_back(kont.at(i).at(k).at(j));
					else if(j==kont.at(i).size()/2 && k==j) jos_manji_satic.push_back(kont.at(i).at(k).at(j));
					else if(j<kont.size()/2 && j<=k && k>=0 && j+k<=kont.at(i).size()-1) jos_manji_satic.push_back(kont.at(i).at(k).at(j));
				}
				satic.push_back(jos_manji_satic);
			}
			Sat.push_back(satic);
		}
	} else if((int)smjer==0) {
		for(int i=0;i<kont.size();i++) {
			typename std::remove_reference<decltype(kont.at(0))>::type satic;
			for(int j=0;j<kont.at(i).size();j++) {
				typename std::remove_reference<decltype(kont.at(0).at(0))>::type jos_manji_satic;
				for(int k=0;k<kont.at(i).at(j).size();k++) {
					if(j<kont.size()/2  && j<=k && j+k<=kont.size()-1) jos_manji_satic.push_back(kont.at(j).at(i).at(k));
					else if(j==kont.size()/2 && k==j) jos_manji_satic.push_back(kont.at(j).at(i).at(k));
					else if(j>kont.at(i).size()/2 && j>=k && j+k>=kont.at(i).size()-1 && j+k<=2*kont.at(i).size()-2) jos_manji_satic.push_back(kont.at(j).at(i).at(k));
				}
				satic.push_back(jos_manji_satic);
			}
			Sat.push_back(satic);
		}
	
	}else if((int)smjer==1) {
		for(int i=0;i<kont.size();i++) {
			typename std::remove_reference<decltype(kont.at(0))>::type satic;
			for(int j=kont.at(i).size()-1;j>=0;j--){
				typename std::remove_reference<decltype(kont.at(0).at(0))>::type jos_manji_satic;
				for(int k=0;k<kont.size();k++) {
					if(j<kont.size()/2 && j<=k && j+k<=kont.size()-1) jos_manji_satic.push_back(kont.at(j).at(i).at(k));
					else if(j==kont.size()/2 && k==j) jos_manji_satic.push_back(kont.at(j).at(i).at(k));
					else if(j>kont.at(i).size()/2 && j>=k && j+k>=kont.at(i).size()-1 && j+k<=2*kont.at(i).size()-2 ) jos_manji_satic.push_back(kont.at(j).at(i).at(k));
				}
				satic.push_back(jos_manji_satic);
			}
			Sat.push_back(satic);
		}
	}
	return Sat;
}

int main ()
{
	try{
		std::cout<<"Unesite dimenziju (x/y/z): ";
		int n;
		for(;;){
			std::cin>>n;
			if(n<=0) std::cout<<"Dimenzija nije ispravna, unesite opet: ";
			else break;
		}
		std::vector<std::deque<std::deque<int>>> Matrica;
		std::cout<<"Unesite elemente kontejnera: ";
		for(int i=0;i<n;i++){
			std::deque<std::deque<int>> pomocni2;
			for(int j=0;j<n;j++){
				std::deque<int> pomocni1;
				for(int k=0;k<n;k++){
					int p;
					std::cin>>p;
					pomocni1.push_back(p);
				}
				pomocni2.push_back(pomocni1);
			}
			Matrica.push_back(pomocni2);
		}
		std::cout<<"Unesite smjer kretanja [0 - 5]: ";
		int f;
		for(;;){
			std::cin>>f;
			if(f<0 || f>5) std::cout<<"Smjer nije ispravan, unesite opet: ";
			else break;
		}
		auto Pjescani(PjescaniSat(Matrica,SmjerKretanja(f)));
		std::cout<<std::endl<<"Pjescani sat unesene matrice je:"<<std::endl;
		for(int i=0;i<Pjescani.size();i++){
			int brojac(1);
			for(int j=0;j<Pjescani.at(i).size();j++){
				for(int k=0;k<Pjescani.at(i).at(j).size();k++){
					if(k==0)std::cout<<std::setw(4*brojac)<<Pjescani.at(i).at(j).at(k);
					else std::cout<<std::setw(4)<<Pjescani.at(i).at(j).at(k);
				}
				if(j<Pjescani.size()/2)brojac++;
				else if(j>Pjescani.size()/2) brojac--;
				else brojac--;
				std::cout<<std::endl;
			}std::cout<<std::endl;
		}
		
	}catch(std::length_error izuzetak){
		std::cout<<std::endl<<"Izuzetak: "<<izuzetak.what();
	}
	return 0;
}