#include <iostream>
#include <vector>
#include <iomanip>
#include <istream>
#include <deque>
#include <cmath>
enum Smjer {Opadajuci=2,Rastuci=1};
std::deque<std::vector<int>> MaksimalniPodnizoviStepenaDvojke(std::vector<int> v1,Smjer x)
{
	int n=v1.size();
	int j=0,logicko=0,logicko2=0,ImaClanove=0;
	std::deque<std::vector<int>> v2;
	if(n==0) return v2;
	if(x==Rastuci) {
		for(int i=0; i<n-1; i++) {
			logicko=0;
			logicko2=0;
			for(int o=0; o<v1.at(i); o++) {
				logicko=0;
				if(pow(2,o)==v1.at(i)) {
					logicko=1;
					break;



				}
			}
			for(int k=0; k<v1.at(i+1); k++) {
				logicko2=0;
				if(pow(2,k)==v1.at(i+1)) {
					logicko2=1;
					break;
				}
			}


			if(v1.at(i)<=v1.at(i+1) && logicko==1 && logicko2==1) {

				if (ImaClanove==0) {
					v2.push_back(std::vector<int>(1));
					v2.at(j).at(0)=v1.at(i);
				}
				v2.at(j).push_back(v1.at(i+1));



				/*	v2.at(i).at(j)=v1.at(i);
					v2.at(i+1).at(j)=v1.at(i+1); */
				ImaClanove=1;

			} else if(ImaClanove==1) {
				j++;
				ImaClanove=0;
			}


		}


		return v2;
	}
	if(x==Opadajuci) {
		for(int i=0; i<n-1; i++) {
			logicko=0;
			logicko2=0;
			for(int o=0; o<v1.at(i); o++) {
				logicko=0;
				if(pow(2,o)==v1.at(i)) {
					logicko=1;
					break;



				}
			}
			for(int k=0; k<v1.at(i+1); k++) {
				logicko2=0;
				if(pow(2,k)==v1.at(i+1)) {
					logicko2=1;
					break;
				}
			}


			if(v1.at(i)>=v1.at(i+1) && logicko==1 && logicko2==1) {

				if (ImaClanove==0) {
					v2.push_back(std::vector<int>(1));
					v2.at(j).at(0)=v1.at(i);
				}
				v2.at(j).push_back(v1.at(i+1));



				/*	v2.at(i).at(j)=v1.at(i);
					v2.at(i+1).at(j)=v1.at(i+1); */
				ImaClanove=1;

			} else if(ImaClanove==1) {
				j++;
				ImaClanove=0;
			}


		}


		return v2;
	}
}
int main ()
{

	int n;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>n;
	std::vector<int> v1;
	std::cout<<"Unesite elemente vektora: ";
	for(int i=0; i<n; i++) {
		int broj;
		std::cin>>broj;
		v1.push_back(broj);
	}
	std::cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	Smjer x;

	int p;
	std::cin>>p;
	if(p==2) {
		x=Opadajuci;
		std::cout<<"Maksimalni opadajuci podnizovi: ";
	} else if(p==1) {
		x=Rastuci;
		std::cout<<"Maksimalni rastuci podnizovi: ";
	}


	std::deque<std::vector<int>> d=MaksimalniPodnizoviStepenaDvojke(v1,x);
	for(int i=0; i<d.size(); i++) {
		std::cout<<"\n";
		for(int j=0; j<d.at(i).size(); j++) {
			std::cout<<d.at(i).at(j)<<" ";

		}
	}

	return 0;
}
