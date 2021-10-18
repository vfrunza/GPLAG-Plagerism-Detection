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
enum Smjer{Rastuci=1, Opadajuci=2};
int StepenDvojke(int n){
	if(n<=0) return 0;
	if(n==1) return 1;
	int pom(n);
	for(int i=0; i<pom; i++){
		if(n%2!=0) break;
		n/=2;
		if(n==1) return 1;
	}
	return 0;
}
std::deque<std::vector<int>> MaksimalniPodnizoviStepenaDvojke(std::vector<int> v, Smjer sm ){
	std::deque<std::vector<int>> dek;
	int clanovi(0), postoji(0);
	int br=v.size();
	//prvo ako su opadajuci
	if(sm==2){
		for(int i=0; i<br-1; i++){
			if(StepenDvojke(v.at(i))==1 && StepenDvojke(v.at(i+1))==1 && v.at(i)>=v.at(i+1)){
				if(postoji==0){
					dek.push_back(std::vector<int>(1));
					dek.at(clanovi).at(0)=v.at(i);
				}
				dek.at(clanovi).push_back(v.at(i+1));
				postoji=1;
			} else if(postoji){
				clanovi++;
				postoji=0;
			}
		}
	} else if(sm==1){
		for(int i=0; i<br-1; i++){
			if(StepenDvojke(v.at(i))==1 && StepenDvojke(v.at(i+1))==1 && v.at(i)<=v.at(i+1)){
				if(postoji==0){
					dek.push_back(std::vector<int>(1));
					dek.at(clanovi).at(0)=v.at(i);
				}
				dek.at(clanovi).push_back(v.at(i+1));
				postoji=1;
			} else if(postoji){
				clanovi++;
				postoji=0;
			}
		}
	}
	return dek;
	/*
	for(int i=0; i<br-1; i++){
		if(v.at(i)<=v.at(i+1) && sm==1 && StepenDvojke(v.at(i))==1){
			int j(i); 
			while(v.at(j)<v.at(j+1) && j<v.size() && StepenDvojke(v.at(j))==1) {
				if(j>=v.size()-1) break;
				j++;
			}
			//pravimo u deku za clan reda [vrijednost od clanovi]
			dek.push_back(std::vector<int> (1));
			int prosirenje(j-i+1);
			dek.at(clanovi).resize(prosirenje);
			int pom(0);
			for(int k=i; k<=j; k++){
				dek.at(clanovi).at(pom)=v.at(k);
				pom++;
			}
			i+=prosirenje-1;
			clanovi++;
		}
		else if(v.at(i)>=v.at(i+1) && sm==2){
			int j=i; 
			while(v.at(j)>=v.at(j+1) && j<v.size() && StepenDvojke(v.at(j))==0) j++;
			dek.push_back(std::vector<int> (0));
			int prosirenje(j-i+1);
			dek.at(clanovi).resize(prosirenje);
			int pom(0);
			for(int k=i; k<=j; k++){
				dek.at(clanovi).at(pom)=v.at(k);
				pom++;
			}
			i+=prosirenje-1;
			clanovi++;
		}
	}
	return dek;*/
}
int main ()
{
	Smjer sm;
	std::cout<<"Unesite broj elemenata vektora: ";
	int n;
	std::cin>>n;
	std::vector<int> v;
	if(n>=0){
		std::cout<<"Unesite elemente vektora: ";
		for(int i=0; i<n; i++){
			int pom;
			std::cin>>pom;
			v.push_back(pom);
		}
		std::cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
		int pom2;
		std::cin>>pom2;
		sm=Smjer(pom2);
		std::deque<std::vector<int>> dek; 
		dek=MaksimalniPodnizoviStepenaDvojke(v,sm);
		if(dek.size()==0){
			if(sm==1) std::cout << "Nema maksimalnih rastucih podnizova." << std::endl;
			else std::cout << "Nema maksimalnih opadajucih podnizova." << std::endl;
		}
		else{
			if(sm==1){
				std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
			}
			else std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
			for(int i=0; i<dek.size(); i++){
				for(int j=0; j<dek.at(i).size(); j++){
					std::cout<<dek.at(i).at(j)<<" ";
				}
				std::cout<<std::endl;
			}
		}
	}

	return 0;
}