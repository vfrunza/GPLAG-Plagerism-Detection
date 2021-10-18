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

typedef std::deque<std::vector<int>> DV ;

enum Smjer {Rastuci =1,Opadajuci};

DV MaksimalniPodnizoviStepenaDvojke(std::vector<int > v,Smjer s){
	bool pravac(s-1);
	DV nizovi;
	for (int i = 0; i < v.size(); i++) {
		int a (1);
		if(v.at(i)%2!=0 && v.at(i)!=1 && v.at(i)!=-1)
			continue;
		//int x (abs(v.at(i)));
		int x(v.at(i));
		while (a<=x) {
			bool  stepen (false);
			std::vector<int> v1 ;
			if(a==x){
				 v1.push_back(v.at(i));
				 i++;
				while (i<v.size()) {
					int b(1);
					stepen=false;
					while (b<=v.at(i)) {
						if(b==v.at(i)){
							stepen=true;
							break;
						}
							b*=2;
					}
					if( ( stepen &&  ( pravac == v.at(i-1)>v.at(i)  ) ) || v.at(i)==v.at(i-1)){
						v1.push_back(v.at(i));
						i++;
				
					}else break;
				}
			}
			a*=2;
			if(v1.size()>1)
				nizovi.push_back(v1);
		
			if(v1.size()==1 || stepen) 
				i--;
		}
	}
	return nizovi;
}
int main ()
{
	std::cout << "Unesite broj elemenata vektora: " ;
	int br;
	std::cin >> br;
	std::vector<int>  v;
	int a;
	std::cout << "Unesite elemente vektora: " ;
	for (int i = 0; i < br; i++) {
		std::cin >> a;
		v.push_back(a);
	}
	int pravac;
	std::cout << "Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	std::cin >> pravac;
	Smjer s =Smjer(pravac);
	DV nizovi=MaksimalniPodnizoviStepenaDvojke(v,s );
	if(pravac-1)
		std::cout <<"Maksimalni opadajuci podnizovi: "<<std::endl;
	else 
		std::cout << "Maksimalni rastuci podnizovi: "<<std::endl;
	for (int i = 0; i < nizovi.size(); i++) {
		for (int j = 0; j < nizovi.at(i).size() ; j++) {
			std::cout << nizovi.at(i).at(j) << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}