/*B 2017/2018, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na email: bcocalic1@etf.unsa.ba.	
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <deque>
enum Smjer {Rastuci = 1, Opadajuci = 2};

bool StepenDvojke(int n){
/*	unsigned long long int i(1);
	if (n<0) return false;
	while (i<n) i*=2;
	if(i==n) return true;
	return false;*/
	return n>0 && !(n&(n-1));
	
}

std::deque<std::vector<int>> MaksimalniPodnizoviStepenaDvojke(std::vector<int> a, Smjer b){
	std::deque<std::vector<int>> povratni;
	if(a.size()==0) return povratni;
	int i=0;
	if(b==1){
		for(i=0;i<a.size()-1;i++){
			if(StepenDvojke(a.at(i)) && a.at(i+1)>=a.at(i) && StepenDvojke(a.at(i+1))){
				int j=i+2;
				std::vector<int> pom;
				pom.push_back(a.at(i));
				pom.push_back(a.at(i+1));
				for(j=i+2;j<a.size();j++){
					if(StepenDvojke(a.at(j)) && StepenDvojke(a.at(j-1)) && a.at(j)>=a.at(j-1)){ pom.push_back(a.at(j)); }
					else break; 
				}
				i=j-1;
				povratni.push_back(pom);
				
			}
		}
	}
	else if(b==2) {
		for(i=0;i<a.size()-1;i++){
			if(StepenDvojke(a.at(i)) && a.at(i+1)<=a.at(i) && StepenDvojke(a.at(i+1))){
				int j=i+2;
				std::vector<int> pom;
				pom.push_back(a.at(i));
				pom.push_back(a.at(i+1));
				for(j=i+2;j<a.size();j++){
					if(StepenDvojke(a.at(j)) && StepenDvojke(a.at(j-1)) && a.at(j)<=a.at(j-1)){ pom.push_back(a.at(j)); }
					else break;
				}
				i=j-1;
				povratni.push_back(pom);
			}
		}
	}
	return povratni;
	
}
int main ()
{
	int n(0);
	
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>n;
	std::vector<int> a(n);
	std::cout<<"Unesite elemente vektora: ";
	for(int i=0;i<n;i++)std::cin>>a.at(i);
	std::cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	int kojiNiz(0);
	std::cin>>kojiNiz;
	Smjer odgovarajuci;
	odgovarajuci=Smjer(kojiNiz);
	
	
	std::deque<std::vector<int>>rezultat;
	
	rezultat=MaksimalniPodnizoviStepenaDvojke(a, odgovarajuci);

	if(odgovarajuci==1)std::cout<<"Maksimalni rastuci podnizovi: \n";
	if(odgovarajuci==2)std::cout<<"Maksimalni opadajuci podnizovi: \n";
	for(auto x:rezultat){
		for(auto y:x) std::cout<<y<<" ";
		std::cout<<std::endl;
	}
	return 0;
}