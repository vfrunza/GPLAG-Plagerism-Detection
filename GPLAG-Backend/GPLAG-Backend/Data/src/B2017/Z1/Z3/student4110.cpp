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
#include <deque>

enum Smjer{Rastuci=true,Opadajuci=false};

bool StepenDvojke(int x){
	if(x==1) return true;
	if(x==0) return false;
	while(x!=1){
		if(x%2!=0)return false;
		x/=2;
	}
	return true;
	
}

std::deque<std::vector<int>> MaksimalniPodnizoviStepenaDvojke(std::vector<int> a, Smjer b){
std::deque<std::vector<int>> dek;
std::vector<int> vektor;
int indeks{0},br{0};
if(a.size()==0) return dek;
if(b) {
    for(int i=0;i<a.size()-1;i++){
	indeks=i;
	br=0;
	while(StepenDvojke(a.at(i))&&i<a.size()-1&&a.at(i)<=a.at(i+1)) {if(StepenDvojke(a.at(i+1)))br++;i++;}
	if(br!=0){
		for(int j=indeks;j<=indeks+br;j++) vektor.push_back(a.at(j));
		if(vektor.size()>1) dek.push_back(vektor);
		vektor.resize(0);
	}
}
} else 
for(int i=0;i<a.size()-1;i++){
	indeks=i;
	br=0;
	while(StepenDvojke(a.at(i))&&i<a.size()-1&&a.at(i)>=a.at(i+1)) {if(StepenDvojke(a.at(i+1)))br++;i++;}
	if(br!=0){
		for(int j=indeks;j<=indeks+br;j++) vektor.push_back(a.at(j));
		if(vektor.size()>1) dek.push_back(vektor);
		vektor.resize(0);
	}
}

return dek;
}
int main ()
{
	int n,x;
	Smjer niz;
	std::vector<int> a;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>n;
	std::cout<<"Unesite elemente vektora: ";
	for(int i=0;i<n;i++) {std::cin>>x; a.push_back(x);}
	std::cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	std::cin>>x;
	if(x==1) niz=Rastuci; else niz=Opadajuci;
	std::deque<std::vector<int>> dek=MaksimalniPodnizoviStepenaDvojke(a,niz);
	if(niz==Rastuci){std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
	for(int i=0;i<dek.size();i++){
		for(int j=0;j<dek.at(i).size();j++){
			std::cout<<dek.at(i).at(j)<<" ";
		}
		std::cout<<std::endl;
	}}
	else{
	std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
	for(int i=0;i<dek.size();i++){
		for(int j=0;j<dek.at(i).size();j++){
			std::cout<<dek.at(i).at(j)<<" ";
		}
		std::cout<<std::endl;
	}	
	}
	return 0;
}