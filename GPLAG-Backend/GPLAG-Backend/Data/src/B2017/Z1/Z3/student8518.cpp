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

typedef std::deque<std::vector<int>> dek_vektora;

enum Smjer {Rastuci=true, Opadajuci=false};

bool StepenDvojke(int clan)
{
	if(clan==0)
		return false;

	while(clan!=0) {
		if(clan==1)
			return true;

		if(clan%2!=0)
			return false;

		clan/=2;
	}
	return true;
}

dek_vektora MaksimalniPodnizoviStepenaDvojke(std::vector<int> v, Smjer a)
{
	dek_vektora DV;
	std::vector<int> pomocni;

	if(a) {
		int redni_br(0),j(0);

		for(int i=0; i<v.size(); i++) {
			if(StepenDvojke(v.at(i)))
				pomocni.push_back(v.at(i));
			else
				continue;

			for( j=i; j<v.size(); j++) {
				if((j+1)==v.size())
					break;

				if(v.at(j)<=v.at(j+1) && StepenDvojke(v.at(j+1))  ) {   //dodao jednako u prvom uslovu za razliku od prosle verzije
					pomocni.push_back(v.at(j+1));
					i=j+1;
				} else
					break;
			}

			if(pomocni.size()>=2) {
				DV.push_back(pomocni);
			} 
			pomocni.resize(0);
		}
		return DV;
	} else {
			int redni_br(0),j(0);

		for(int i=0; i<v.size(); i++) {
			if(StepenDvojke(v.at(i)))
				pomocni.push_back(v.at(i));
			else
				continue;

			for( j=i; j<v.size(); j++) {
				if((j+1)==v.size())
					break;

				if(v.at(j)>=v.at(j+1) && StepenDvojke(v.at(j+1))  ) {     //dodao jednako u prvom uslovu za razliku od prosle verzije
					pomocni.push_back(v.at(j+1));
					i=j+1;
				} else
					break;
			}

			if(pomocni.size()>=2) {
				DV.push_back(pomocni);
			} 
			pomocni.resize(0);
		}
	}
}


int main ()
{
	int n;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>n;

	std::vector<int> v(n);

	std::cout<<"Unesite elemente vektora: ";

	for (int i=0; i<v.size(); i++)
		std::cin>>v.at(i);


	int b;
	std::cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	std::cin>>b;

	Smjer smj;
	if(b==1) {
		smj=Smjer(1);
		std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
	} else if(b==2) {
		smj=Smjer(0);
		std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
	}


	dek_vektora dv;
	dv=MaksimalniPodnizoviStepenaDvojke(v, smj);


	for(int i=0; i<dv.size(); i++) {
		for(int j=0; j<dv.at(i).size(); j++) {
			std::cout<<dv.at(i).at(j)<<" ";
		}
		std::cout<<std::endl;
	}

	return 0;
}