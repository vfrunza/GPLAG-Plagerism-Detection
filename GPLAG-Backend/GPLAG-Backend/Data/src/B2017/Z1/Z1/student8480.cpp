/*B 2017/2018, Zadaća 1, Zadatak 1

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
#include <cmath>

bool DaLiJeProst(int n)
{
	if (n<2) return false;
	for(int i=2; i<=sqrt(n); i++)
		if(n%i==0) return false;	/*broj je slozen ako nadjemo neki broj
									takav da je n djeljiv tim brojem*/
	return true;
}

bool DaLiJeSimetrican(std::vector<int> cifre)
{
	int i(0), j(cifre.size()-1); //i je na pocetku na prvom indeksu, a j na zadnjem

	while(i<=j) {
		if(cifre.at(i)!=cifre.at(j)) //provjeravamo da li su prva i zadnja cifra iste,
			return false;			 //druga i predzadnja itd
		i++;
		j--;

	}
	return true;
}


std::vector<int> TernarniBroj(int n)
{
	std::vector<int> cifre;
//pretvaranje u ternarni sistem
	do {
		int cifra=n%3;
		cifre.push_back(std::abs(cifra));
		n/=3;
	} while(n!=0);

	return cifre;
}


std::vector<int> IzdvojiSimetricneTernarne (std::vector<int> v, bool b)
{
	std::vector<int> vektor;

	for(int i=0; i<v.size(); i++) {
		std::vector<int> tmp;
		tmp=TernarniBroj(v.at(i));

		if(DaLiJeProst(v.at(i))==true && v.at(i)!=1 && b==true && DaLiJeSimetrican(tmp)==true) {
			bool ima(false);
			for(int j=0; j<vektor.size(); j++) { //provjera da li se broj vec nalazi u vektoru
				if(vektor.at(j)==v.at(i)) {
					ima=true;
					break;
				}
			}
			if(ima==false)			//ako broj vec nije u vektoru, dodamo ga
				vektor.push_back(v.at(i));
		}

		if(DaLiJeProst(v.at(i))==false && v.at(i)!=1 && b==false && DaLiJeSimetrican(tmp)==true) {
			bool ima(false);
			for(int j=0; j<vektor.size(); j++) {
				if(v.at(i)==vektor.at(j)) {
					ima=true;
					break;
				}
			}
			if(ima==false)
				vektor.push_back(v.at(i));
		}
	}
	return vektor;
}

int main ()
{
	std::cout<<"Unesite elemente vektora (-1 za kraj): ";
	std::vector<int>v;

	for(;;) {
		int x;
		std::cin>>x;
		if(x==-1) break;
		v.push_back(x);
	}

	int n;
	std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	for(;;) {
		std::cin>>n;
		if(n==0 || n==1) break;
		std::cout<<"Neispravan unos! Unesite ponovo: ";
	}

	std::vector<int> simetrican;
	simetrican=IzdvojiSimetricneTernarne(v,n);

	if(n==1) {
		if(simetrican.size()==0) std::cout<<"Nema prostih simetricnih brojeva u vektoru.";
		else {
			std::cout<<"Prosti simetricni brojevi iz vektora su: ";
			for(int i=0; i<simetrican.size(); i++) {
				std::cout<<simetrican.at(i);
				if(i!=simetrican.size()-1) std::cout<<", ";
			}
			std::cout<<".";
		}
	} else  {
		if(simetrican.size()==0) std::cout<<"Nema slozenih simetricnih brojeva u vektoru.";
		else {
			std::cout<<"Slozeni simetricni brojevi iz vektora su: ";

			for(int i=0; i<simetrican.size(); i++) {
				std::cout<<simetrican.at(i);
				if(i!=simetrican.size()-1) std::cout<<", ";
			}
			std::cout<<".";
		}
	}

	return 0;
}