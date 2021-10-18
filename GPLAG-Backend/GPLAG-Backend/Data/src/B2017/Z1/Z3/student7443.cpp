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
#include <iomanip>
enum Smjer {Rastuci=1 ,Opadajuci};
int Stepen( int b)
{
	int a(1);
	if (b<0) {
		a=0;
		return a;
	}
	for(int i=1; i<=b; i*=2) {
		if(b==i) return a;
	}
	a=0;
	return a;
}

std::deque<std::vector<int>> MaksimalniPodnizoviStepenaDvojke(std::vector<int> a, Smjer b)
{

	std::deque<std::vector<int>> dek;
	std::vector<int> v;
	int br(0);
	if(b==Rastuci)	{

		int i=0;
		do {
			if(Stepen(a.at(i)) && i!=a.size()-1 && Stepen(a.at(i+1)) && a.at(i+1)>a.at(i)) {
				v.push_back(a.at(i));
				i++;
				while(Stepen(a.at(i))==1 && a.at(i)>a.at(i-1)) {
					v.push_back(a.at(i));
					i++;
					if (i==a.size())
						break;
				}
				dek.resize(br+1);
				for (int i = 0; i < v.size(); i++) {
					dek.at(br).push_back(v.at(i));
				}
				br++;
				v.resize(0);
				i--;
			}
			i++;
		} while(i<a.size());
	} else if(b== Opadajuci) {
		//	std::vector<int> v;
		int i=0;
		do {
			if(Stepen(a.at(i)) && i!=a.size()-1 && Stepen(a.at(i+1)) && a.at(i)>a.at(i+1)) {
				v.push_back(a.at(i));
				i++;
				while(Stepen(a.at(i)) && Smjer(a.at(i)) && a.at(i)<a.at(i-1)) {
					v.push_back(a.at(i));
					i++;
					if (i==a.size())
						break;
				}
				dek.resize(br+1);
				for (int i = 0; i < v.size(); i++) {
					dek.at(br).push_back(v.at(i));
				}
				br++;
				v.resize(0);
				i--;
			}
			i++;
		} while(i<a.size());
	}

	return dek;
}





int main ()
{

	Smjer s;
	std::cout<<"Unesite broj elemenata vektora: ";
	int n;
	std::cin>>n;
	std::vector<int> a;
	int broj;
	std::cout<<"Unesite elemente vektora: ";
	for(int i=0; i<n; i++) {
		std::cin>>broj;
		a.push_back(broj);
	}
	std::cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	int S;
	std::cin>>S;
	s=Smjer(S);
	std::deque<std::vector<int>> Novi;
	Novi=MaksimalniPodnizoviStepenaDvojke(a,s);
	if(s==Opadajuci)
		std::cout<<"Maksimalni opadajuci podnizovi: \n";
	else if(s==Rastuci)
		std::cout<<"Maksimalni rastuci podnizovi: \n";
	for(int i=0; i<Novi.size(); i++) {
		for(int j=0; j<Novi.at(i).size(); j++) {
			std::cout<<Novi.at(i).at(j)<<" ";
		}
		std::cout<<std::endl;
	}
	return 0;
}
