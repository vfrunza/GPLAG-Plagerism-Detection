#include <iostream>
#include<vector>
#include<deque>
#include<iomanip>


enum Smjer {Opadajuci,Rastuci};

int StepenDvojke(int broj)
{
	for(int i=1; i<=broj; i*=2) {
		if(i==broj) return broj;

	}
	return 0;
}

std::deque<std::vector<int>> MaksimalniPodnizoviStepenaDvojke(std::vector<int>v,Smjer s)
{

	std::deque<std::vector<int>>a;

	if(s==Rastuci) {
		for(int i=0; i<int(v.size())-1; i++) {

			if(((StepenDvojke(v.at(i))!=0) && (v.at(i+1)>v.at(i)) && (StepenDvojke(v.at(i+1))!=0))) {
				std::vector<int> pom;

				while(i<v.size()-1 ) {

					pom.push_back(v.at(i));
					if(v.at(i)>v.at(i+1) || StepenDvojke(v.at(i+1))==0) break;
					i++;
				}
				if(i==v.size()-1 && StepenDvojke(v.at(i))!=0 && v.at(i)>v.at(i-1)) pom.push_back(v.at(i));
				
				a.push_back(pom);
			}

	}
}
if(s==Opadajuci) {
		for(int i=0; i<int(v.size())-1; i++) {

			if(((StepenDvojke(v.at(i))!=0) && (v.at(i+1)<v.at(i)) && (StepenDvojke(v.at(i+1))!=0))) {
				std::vector<int> pom;

				while(i<v.size()-1 ) {

					pom.push_back(v.at(i));
					if(v.at(i)<v.at(i+1) || StepenDvojke(v.at(i+1))==0) break;
					i++;
				}
				if(i==v.size()-1 && StepenDvojke(v.at(i))!=0 && v.at(i)<v.at(i-1)) pom.push_back(v.at(i));
				
				a.push_back(pom);
			}

	}
}

	return a;
}

int main ()
{
	std::cout<<"Unesite broj elemenata vektora: ";
	int broj;
	std::cin>>broj;
	std::cout<<"Unesite elemente vektora: ";
	std::vector<int>c;
	int broj1;
	for(int i=0; i<broj; i++) {
		std::cin>>broj1;
		c.push_back(broj1);
	}
	std::cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	int n;
	std::cin>>n;
	if(n==1) {
		Smjer s(Rastuci);
		std::cout<<"Maksimalni rastuci podnizovi: \n";
		std::deque<std::vector<int>>rastuci(MaksimalniPodnizoviStepenaDvojke(c,s));

		for(int i=0; i<rastuci.size(); i++) {
			for(int j=0; j<rastuci.at(i).size(); j++) {
				std::cout<<rastuci.at(i).at(j)<<" ";
			}
			std::cout<<std::endl;
		}
	} else if(n==2) {
		Smjer s(Opadajuci);
		std::cout<<"Maksimalni opadajuci podnizovi: \n";
		std::deque<std::vector<int>>opadajuci(MaksimalniPodnizoviStepenaDvojke(c,s));
		for(int i=0; i<opadajuci.size(); i++) {
			for(int j=0; j<opadajuci.at(i).size(); j++) {
				std::cout<<opadajuci.at(i).at(j)<<" ";
			}
			std::cout<<std::endl;
		}
	}

	return 0;
}