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

bool DaLiJeStepenDvojke(int a){
	if (a==0) return false;
	if (a==1) return true;
	while (a%2==0){
		a/=2;
		if (a==1) break;
	}
	if (a==1) return true;
	else return false;
}
enum Smjer {Rastuci=1,Opadajuci};
std::deque<std::vector<int>> MaksimalniPodnizoviStepenaDvojke (std::vector<int> v,enum Smjer a){
	std::deque<std::vector<int>> v1(0,std::vector<int> (0));
	if (v.empty()) return v1;
	int j(0);
	if (a==Rastuci){
	for (int i=0;i<v.size()-1;i++){
		if(v.at(i)<=v.at(i+1) && DaLiJeStepenDvojke(v.at(i)) && DaLiJeStepenDvojke(v.at(i+1))){
			j++;
			v1.resize(j);
			while (v.at(i)<=v.at(i+1) && (i+1)!=v.size()-1 && DaLiJeStepenDvojke(v.at(i)) && DaLiJeStepenDvojke(v.at(i+1))){
				v1.at(j-1).push_back(v.at(i));
				i++;
			}
			v1.at(j-1).push_back(v.at(i));
		}
	}
			if ((v.at(v.size()-1) >= v.at(v.size()-2)) && DaLiJeStepenDvojke(v.at(v.size()-1)) && DaLiJeStepenDvojke(v.at(v.size()-2))){
			v1.at(j-1).push_back(v.at(v.size()-1));
		}
	}
	else{
		for (int i=0;i<v.size()-1;i++){
			if (v.at(i)>=v.at(i+1) && DaLiJeStepenDvojke(v.at(i)) && DaLiJeStepenDvojke(v.at(i+1))){
				j++;
				v1.resize(j);
				while (v.at(i)>=v.at(i+1) && DaLiJeStepenDvojke(v.at(i)) && DaLiJeStepenDvojke(v.at(i+1)) && (i+1)<v.size()-1){
					v1.at(j-1).push_back(v.at(i));
					i++;
				}
				v1.at(j-1).push_back(v.at(i));
			}
		}
		if ((v.at(v.size()-1) <= v.at(v.size()-2)) && DaLiJeStepenDvojke(v.at(v.size()-1)) && DaLiJeStepenDvojke(v.at(v.size()-2))){
			v1.at(j-1).push_back(v.at(v.size()-1));
		}
	}
	return v1;
}

int main ()
{
	std::cout<<"Unesite broj elemenata vektora: ";
	int n;
	std::cin>>n;
	std::cout<<"Unesite elemente vektora: ";
	std::vector<int> v(n);
	for (int i=0;i<v.size();i++) std::cin>>v.at(i);
	std::cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	int a;
	std::cin>>a;
	Smjer s;
	if (a==1) {
		s=Rastuci;
		std::cout<<"Maksimalni rastuci podnizovi: " ;
	}
	else {
		s=Opadajuci;
		std::cout<<"Maksimalni opadajuci podnizovi: ";
	}
	std::cout<<std::endl;
	std::deque<std::vector<int>> nizovi;
	nizovi=MaksimalniPodnizoviStepenaDvojke(v,s);
	for (int i=0;i<nizovi.size();i++){
		for (int j=0;j<nizovi.at(i).size();j++){
			std::cout<<nizovi.at(i).at(j)<<" ";
		}
		std::cout<<std::endl;
	}
	return 0;
}