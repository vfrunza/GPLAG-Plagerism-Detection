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
#include <deque>
#include <vector>
enum Smjer{ Rastuci=true, Opadajuci=false};
typedef std::deque<std::vector<int>> Dek;
void IspisiMatricu(Dek m){
	for(std::vector<int> x : m){
		for(int x1 : x){
			std::cout<<x1<<" ";
		}
		std::cout<<std::endl;
	}
}

bool StepenDvojke(int n){
//	if(n<0) n=-n;
	bool stepen=false;
	while(1){
		if(n==0) break;
		if(n==1) {
			stepen=true;
			break;
		}
		if(n%2!=0){ 
		   stepen=false;
		   break;
		}
		if(n%2==0){
		stepen=true;
		n=n/2;
		} 
	}
	return stepen;
}
std::deque<std::vector<int>> MaksimalniPodnizoviStepenaDvojke(std::vector<int> v, Smjer n){
	std::deque<std::vector<int>> novidek;
	std::vector<int> novivektor=v;
	/*for(int i=0; i<v.size(); i++){
		if(StepenDvojke(v.at(i))==1) novivektor.push_back(v.at(i));
	}*/
//	std::cout<<StepenDvojke(v.at(1));
	bool net=false;
	for(int i=0; i<v.size(); i++) if(StepenDvojke(v.at(i))==1) net=true;
	if(net==false || v.size()==0) return novidek;
	int j(1), k(0), i(0);
	while(j<novivektor.size()){
		novidek.resize(k+1);


		if(n==1){
			if(novivektor.at(0)!=0 || StepenDvojke(novivektor.at(0))!=0) novidek.at(k).push_back(novivektor.at(i));
		while(novivektor.at(i)<=novivektor.at(j)){
			if(StepenDvojke(novivektor.at(j))==0){
				j++;
				i++;
				break;
			}
			novidek.at(k).push_back(novivektor.at(j));
			j++;
			i++;
			if(i==novivektor.size() || j==novivektor.size()) break;
		}
		}
		if(n==0){
			 novidek.at(k).push_back(novivektor.at(i));
			while(novivektor.at(i)>=novivektor.at(j)){
				if(StepenDvojke(novivektor.at(j))==0){
					j++; 
					i++; 
					break;
				}
				novidek.at(k).push_back(novivektor.at(j));
				j++;
				i++;
				if(i==novivektor.size() || j==novivektor.size()) break;
			}
		}
		i++;
		k++;
		j++;
	}
	Dek dek;
	for(int i=0; i<novidek.size(); i++){
		if(novidek.at(i).size()==1) continue;
		else dek.push_back(novidek.at(i));
	}
	
	return dek;
}

int main ()
{
	int n, m, broj;
	Smjer smer;
	std::vector<int> v;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>n;
	std::cout<<"Unesite elemente vektora: ";
	for(int i=0; i<n; i++){
		std::cin>>broj;
		v.push_back(broj);
	}
	std::cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	std::cin>>m;
	if(m==1){ 
		smer=Rastuci;
		auto v1=MaksimalniPodnizoviStepenaDvojke(v, smer);
		std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
		IspisiMatricu(v1);
	}
	if(m==2){
		smer=Opadajuci;
		auto v1=MaksimalniPodnizoviStepenaDvojke(v, smer);
		std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;;
		IspisiMatricu(v1);
	} 
	
	
	
	return 0;
}