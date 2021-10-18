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
using std::cout;
using std::cin;
typedef std::vector<int> Vektor;
enum Smjer {Rastuci, Opadajuci};
bool DaLiJeStepenDvojke (int broj) {
	if (broj<1) return false;
	while (broj!=1) {
		if (broj%2!=0) return false;
		broj/=2;
	}
	return true;
}
int BrojElemenataUMaxPodnizu (Vektor v, int i, Smjer smjer) {
	if (!DaLiJeStepenDvojke(v.at(i))) return 0;
	int brojac(0);
	for (int j=i+1;j<v.size();j++) {
		if (DaLiJeStepenDvojke(v.at(j))) {
			if (smjer==Rastuci) {
				if (v.at(j)>=v.at(j-1))
					brojac++;
				else break;
			}
			else {
				if (v.at(j)<=v.at(j-1))
					brojac++;
				else break;
			}
		}
		else break;
		}
	return brojac;
}
std::deque<Vektor> MaksimalniPodnizoviStepenaDvojke (Vektor v, Smjer smjer) {
	std::deque<Vektor> povratniDek;
	int brojRedova(0);
	for (int i=0;i<v.size();i++) {
		int sirinaPodniza=BrojElemenataUMaxPodnizu(v, i, smjer);
		if (sirinaPodniza>=1) {
			brojRedova++;
			povratniDek.resize(brojRedova);
			for (int j=i;j<=i+sirinaPodniza;j++) 
				povratniDek.at(brojRedova-1).push_back(v.at(j));
			i+=sirinaPodniza;
		}
	}
	return povratniDek;
}
int main ()
{
	cout<<"Unesite broj elemenata vektora: ";
	int brojelemenata;
	cin>>brojelemenata;
	Vektor v;
	cout<<"Unesite elemente vektora: ";
	for (int i=0;i<brojelemenata;i++) {
		int broj;
		cin>>broj;
		v.push_back(broj);
	}
	cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	Smjer smjer;
	double intsmjer;
	cin>>intsmjer;
	if (intsmjer==1) smjer=Rastuci;
	else if (intsmjer==2) smjer=Opadajuci;
	else return 1;
	auto dek=MaksimalniPodnizoviStepenaDvojke(v, smjer);
	if (smjer==Rastuci)
		cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
	else 
		cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
	for (auto red : dek) {
		for (auto element : red) 
			cout<<element<<" ";
		cout<<std::endl;
	}
	return 0;
}