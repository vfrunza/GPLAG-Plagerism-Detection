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

enum Smjer {Rastuci, Opadajuci};

bool stepenDvojke(int n) //provjera da li je n stepen dvojke
{
	int x(1);
	while(x<n)
		x*=2;

	if(x==n)
		return true;

	return false;
}

std::deque<std::vector<int>> MaksimalniPodnizoviStepenaDvojke (std::vector<int> v, Smjer x)
{
	std::deque<std::vector<int>> rez;

	for(int i=0; i<v.size(); i++) {
		if(stepenDvojke(v.at(i))) {
			std::vector<int> podniz;
			while(i<v.size() && stepenDvojke(v.at(i))) {
				/*pomjera indeks iz for	petlje sve dok je broj stepen dvojke, a pri
				tome nije izvan vektora*/
				if((x==Smjer::Rastuci && podniz.size()!=0 &&
				        v.at(i)>podniz.at(podniz.size()-1)) || podniz.size()==0) {
					podniz.push_back(v.at(i));
					i++;
				}/*provjerava je li opada ili raste i dodaje u podniz
					ukoliko zadovoljava uslov*/
				else if((x==Smjer::Opadajuci && podniz.size()!=0 &&
				         v.at(i)<podniz.at(podniz.size()-1)) || podniz.size()==0) {
					podniz.push_back(v.at(i));
					i++;
				} else if ((x==Smjer::Rastuci && v.at(i)<=podniz.at(podniz.size()-1))
				           ||(x==Smjer::Opadajuci && v.at(i)>=podniz.at(podniz.size()-1))) {
					break;
				}/*ako je uslov da raste, a niz opada ili obrnuto, petlja se prekida*/

			}
			if(podniz.size()>1) //ako podniz ima vise od jednog elementa dodamo u dek
				rez.push_back(podniz);
			i--;
		}
	}
	return rez;
}

int main ()
{
	int n;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>n;
	std::cout<<"Unesite elemente vektora: ";
	std::vector<int> v;
	for(int i=0; i<n; i++) {
		int x;
		std::cin>>x;
		v.push_back(x);
	}

	std::cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	int x;
	for(;;) {
		std::cin>>x;
		if(x==1 || x==2) break;
	}

	std::deque<std::vector<int>> v1;
	v1=MaksimalniPodnizoviStepenaDvojke(v,Smjer(x-1));

	if(x==1) {
		if(v1.size()==0) std::cout<<"Nema ni jedan monotono rastuci podniz ciji su svi elementi stepen dvojke!";
		else  {
			std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
			for(int i=0; i<v1.size(); i++) {
				for(int j=0; j<v1.at(i).size(); j++) {
					std::cout<<v1.at(i).at(j)<<" ";
				}
				std::cout<<std::endl;
			}
		}
	} else if(x==2) {
		if(v1.size()==0) std::cout<<"Nema ni jedan monotono rastuci podniz ciji su svi elementi stepen dvojke!";
		else {
			std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
			for(int i=0; i<v1.size(); i++) {
				for(int j=0; j<v1.at(i).size(); j++) {
					std::cout<<v1.at(i).at(j)<<" ";
				}
				std::cout<<std::endl;
			}
		}
	}

	return 0;
}