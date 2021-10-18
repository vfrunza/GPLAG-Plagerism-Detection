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
enum Smjer {Rastuci=true, Opadajuci=false};
//Pomocna f-ja koja provjerava da li je broj stepen dvojke
bool StepenDvojke(int x){
	for(int i(1); i<=x; i*=2){
		if(i==x) return 1;
	}
	return 0;
}
//Pomocna f-ja koja vraca podniz ciji su elementi stepena dvojke
std::vector<int> PodnizoviStepenaDvojke(std::vector<int> v){
	std::vector<int> pom;
	if(v.size()<1) return pom;
	for(int i(0); i<v.size(); i++){
		if(StepenDvojke(v.at(i))) pom.push_back(v.at(i));
		else break;
	}
	if(pom.size()<=1){
		pom.resize(0);
		return pom;
	}
	return pom;
}
//Pomocna f-ja koja izdvaja rastuce podnizove
std::deque<std::vector<int>> RastuciPodnizovi(std::vector<int> v){
	std::deque<std::vector<int>> rez;
	std::vector<int> pom;
	std::vector<int> pom2;
	if(v.size()<1) return rez;
	for(int i(0); i<v.size(); i++){
		if(v.at(i)==0) continue;
		if(i==(v.size()-1)) break;
			if(v.at(i)<=v.at(i+1)){
			int j(i);
			pom.push_back(v.at(j));
			for(; i<int(v.size())-1 && v.at(i)<=v.at(i+1); i++)
		    pom.push_back(v.at(i+1));	
		    pom2=PodnizoviStepenaDvojke(pom);
		    if(pom2.size()<=1) continue;
		    else{
		    	rez.push_back(pom2);
		    }
			pom.resize(0);
		}
	}
	return rez;
}
//Pomocna f-ja koja izdvaja opadajuce podnizove
std::deque<std::vector<int>> OpadajuciPodnizovi(std::vector<int> v){
	std::deque<std::vector<int>> rez;
	std::vector<int> pom;
	std::vector<int> pom2;
	if(v.size()<1) return rez;
	for(int i(0); i<v.size(); i++){
		if(v.at(i)==0) continue;
		if(i==(v.size()-1)) break;
		if(v.at(i)>=v.at(i+1)){
			int j(i);
			pom.push_back(v.at(j));
			for(; i<int(v.size())-1 && v.at(i)>=v.at(i+1); i++)
			pom.push_back(v.at(i+1));
			pom2=PodnizoviStepenaDvojke(pom);
			if(pom2.size()<=1) continue;
			else{
				rez.push_back(pom2);
			}
			pom.resize(0);
		}
	}
	return rez;
}
//F-ja MaksimalniPodnizoviStepenaDvojke
std::deque<std::vector<int>> MaksimalniPodnizoviStepenaDvojke(std::vector<int> v, Smjer x){
	std::deque<std::vector<int>> rez;
	if(v.size()<1) return rez;
	if(x) rez=RastuciPodnizovi(v);
	else rez=OpadajuciPodnizovi(v);
	return rez;
}

int main ()
{
	int n;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>n;
	std::vector<int> v;
	int x;
	std::cout<<"Unesite elemente vektora: ";
	for(int i(0); i<n; i++){
		std::cin>>x;
		v.push_back(x);
	}
	int m;
	std::cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	for(;;){
		std::cin>>m;
		if(m==1 || m==2) break;
		else std::cout<<"Neispravan unos! Unesite ponovo: ";
	}
	Smjer pobrojani;
	if(m==1) pobrojani=Rastuci;
	else if(m==2) pobrojani=Opadajuci;
	std::deque<std::vector<int>> rez=MaksimalniPodnizoviStepenaDvojke(v,pobrojani);
	if(pobrojani){
		std::cout<<"Maksimalni rastuci podnizovi: \n";
		for(int i(0); i<rez.size(); i++){ 
			for(int j(0); j<rez.at(i).size(); j++)
			std::cout<<rez.at(i).at(j)<<" ";
			std::cout<<std::endl;
			}
		}
	else{
		std::cout<<"Maksimalni opadajuci podnizovi: \n";
		for(int i(0); i<rez.size(); i++){
			for(int j(0); j<rez.at(i).size(); j++)
			std::cout<<rez.at(i).at(j)<<" ";
			std::cout<<std::endl;
		}
	}
	return 0;
}