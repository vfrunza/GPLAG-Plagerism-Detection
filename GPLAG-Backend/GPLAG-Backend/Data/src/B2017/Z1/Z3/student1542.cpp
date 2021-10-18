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
#include <cmath>

enum Smjer { Rastuci =1, Opadajuci=2};

bool Stepen_broja_dva( int broj)
{
	bool stepen(false);
	for (int j=0; j<50; j++) {
		if(j*log(2)==log(broj))
			stepen=true;
	}
	return stepen;
}
std::deque<std::vector<int>> RastuciPodnizovi(std::vector<int> v)
{
	std::vector<int> v1;
	int br(0),razlika(0),pocetak(0),kraj(0),brojac(0);
	for(int i=0; i<v.size(); i++) {
		if(i<v.size()-1 && v.at(i)>0 && v.at(i)<=v.at(i+1)) {
			pocetak=i;
			while(i<v.size()-1 && v.at(i)<=v.at(i+1)) {
				i++;
				kraj=i;
			}
			for(int j=pocetak; j<=kraj; j++)
				if(Stepen_broja_dva(v.at(j))==0) {
					br=j;
					break;
				}
			if(br!=0)
				razlika=kraj-br+1;
			if(br!=0 && kraj-pocetak==1) razlika=kraj-br+2;
			v1.push_back(pocetak);
			v1.push_back(kraj-razlika);

			razlika=0;
			br=0;
		}
	}
	std::deque<std::vector<int>>matrica(v1.size()/2);
	for(int i=0; i<matrica.size(); i++) {
		for(int j=v1.at(brojac); j<=v1.at(brojac+1); j++)
			matrica.at(i).push_back(v.at(j));
		brojac+=2;
	}
	return matrica;
}

std::deque<std::vector<int>> OpadajuciPodnizovi(std::vector<int> v)
{
	std::vector<int> v1;
	int pocetak(0),br(0),razlika(0),brojac(0),kraj(0);
	for(int i=0; i<v.size(); i++) {
		if(i<v.size()-1 && v.at(i)>=v.at(i+1)) {
			pocetak=i;
			while(i<v.size()-1  && v.at(i)>=v.at(i+1)) {
				i++;
				kraj=i;
			}
			for(int j=pocetak; j<=kraj; j++)
				if(Stepen_broja_dva(v.at(j))==0) {
					br=j;
					break;
				}
			if(br!=0)razlika=kraj-br+1;
			if(br!=0 && kraj-pocetak==1)razlika=kraj-br+2;
			v1.push_back(pocetak);
			v1.push_back(kraj-razlika);
			razlika=0;
			br=0;
		}
	}
	std::deque<std::vector<int>> matrica(v1.size()/2);
	for(int i=0; i<matrica.size(); i++) {
		for(int j=v1.at(brojac); j<=v1.at(brojac+1); j++)
			matrica.at(i).push_back(v.at(j));
		brojac+=2;
	}
	return matrica;
}

std::deque<std::vector<int>> MaksimalniPodnizoviStepenaDvojke(std::vector<int> vektor, Smjer n)
{
	std::deque<std::vector<int>> dek_vektora;
	if(n==1) {
		dek_vektora=RastuciPodnizovi(vektor);
	} else dek_vektora=OpadajuciPodnizovi(vektor);
	
	return dek_vektora;
}
int main ()
{
	std::deque<std::vector<int>> v;
	std::vector<int> vektor;
	int n,e,m;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>n;
	std::cout<<"Unesite elemente vektora: ";
	for(int i=0; i<n; i++) {
		std::cin>>e;
		vektor.push_back(e);
	}

	std::cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	std::cin>>m;
	if(m==1) {
		v=MaksimalniPodnizoviStepenaDvojke(vektor,Rastuci);
		std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
		for(int i=0; i<v.size(); i++) {
			for(int j=0; j<v.at(i).size(); j++) {
				std::cout<<v.at(i).at(j)<<" ";
			}
			std::cout<<std::endl;
		}
	} 
	else {
		v=MaksimalniPodnizoviStepenaDvojke(vektor,Opadajuci);
		std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
		for(int i=0; i<v.size(); i++) {
			for(int j=0; j<v.at(i).size(); j++) {
				std::cout<<v.at(i).at(j)<<" ";
			}
			std::cout<<std::endl;
		}
	}
	return 0;
}