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


typedef std::vector<int> Vektor;
typedef std::deque<std::vector<int>> DekVektora;

enum Smjer {Rastuci=1, Opadajuci};

//provjerava da li je proslijedjeni cjelobrojni parametar stepen dvojke
bool StepenDvojke (int broj)
{
	if (broj<=0) return false;
 
	for(;;) {
		if(broj!=1 && broj%2==1) return false; 
		broj/=2;
		if(broj==0) break;
	}

	return true;
}


DekVektora MaksimalniPodnizoviStepenaDvojke (Vektor v, Smjer s)
{
	DekVektora max_podnizovi;
	int m(1);
	for(unsigned int i=0; i<v.size(); i++) { 

		if(StepenDvojke(v.at(i))) {
			max_podnizovi.resize(m);
			max_podnizovi.at(m-1).push_back(v.at(i));

			while ( i<v.size()-1 && StepenDvojke(v.at(i+1)) &&  //brojac u opsegu i stepen dvojke i
			        ((s==Rastuci && v.at(i) <= v.at(i+1)) ||    // rastuci ili
			         (s==Opadajuci && v.at(i) >= v.at(i+1)))    //opadajuci
			      ) {
				max_podnizovi.at(m-1).push_back(v.at(i+1));
				i++;
			}

			if(max_podnizovi.at(m-1).size() > 1)
				m++;
			else
				max_podnizovi.at(m-1).erase(max_podnizovi.at(m-1).begin());
		}
	}

	return max_podnizovi;
}


int main ()
{
	
	std::cout <<"Unesite broj elemenata vektora: ";
	int duzina;
	std::cin >> duzina;

	Vektor v;
	std::cout << "Unesite elemente vektora: ";
	for(int i=0; i<duzina; i++) {
		int tmp;
		std::cin >> tmp;  
		v.push_back(tmp);
	}   

	std::cout << "Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	int s;
	
	std::cin>>s;

	auto max_podnizovi(std::move(MaksimalniPodnizoviStepenaDvojke(v, Smjer(s))));

		if(s==1)
			std::cout << "Maksimalni rastuci podnizovi: "<< std::endl;
		else
			std::cout << "Maksimalni opadajuci podnizovi: "<<std::endl;

		for(unsigned int i=0; i<max_podnizovi.size(); i++) {
			for(unsigned int j=0; j<max_podnizovi.at(i).size(); j++)
				std::cout << max_podnizovi.at(i).at(j) << " ";
			std::cout << std::endl;
		}
	
	return 0;
}