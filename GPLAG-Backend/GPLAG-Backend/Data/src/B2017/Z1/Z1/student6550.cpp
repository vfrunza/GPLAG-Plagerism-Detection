#include <iostream>
#include <vector>
#include <cmath>
typedef std::vector<int> IntVektor;

bool ProstBroj(int broj)
{
	if(broj==2) return false;
	for (int i=2; i<=sqrt (broj); i++) {
		if(broj%i==0) return false;
	}
	return true;
}

int NajveciStepen(int x)
{
	int i(0);
	do {
		if(x<3 and x>-3) return 0;
		x=x/3;
		i++;
	} while(x/3!=0);
	return i;
}

bool DaLiSePonavlja(std::vector<int> vektor_za_provjeru, int x)
{
	for(int i=0; i<vektor_za_provjeru.size(); i++) {
		for(int j=i+1; j<vektor_za_provjeru.size(); j++) {
			if(vektor_za_provjeru.at(i)==vektor_za_provjeru.at(j)) return true;
		}
	}
	return false;
}

bool TernarnaReprezentacija(int x)
{
	int stepen(NajveciStepen(x));
	int maxi(NajveciStepen(x));
	int suma(0);
	for(int i=0; i<=maxi; i++) {
		if(x<3 and x>(-3))	break;

		suma+=x/int((pow(3,stepen))) * (pow(10,stepen));
		x=x-(((x/int(pow(3,stepen)))*pow(3,stepen)));
		stepen--;
	}

	suma+=x;

	IntVektor vektor;
	IntVektor vektor1;
	int ostatak(0);

	do {
		ostatak=suma%10;
		vektor.push_back(ostatak);
		suma/=10;
	} while (suma!=0);

	for(int i=vektor.size()-1; i>=0; i--) {
		vektor1.push_back(vektor.at(i));
	}
	
	if(vektor==vektor1) return true;
	return false;
}

IntVektor IzdvojiSimetricneTernarne(IntVektor V, bool prost)
{
6
	IntVektor VektorProstihSimetricnihBrojeva;
	IntVektor VektorSlozenihSimetricnihBrojeva;

	if(prost) {
		for(int i=0; i<V.size(); i++) {
			if(ProstBroj(V.at(i)) and TernarnaReprezentacija(V.at(i))) {
				if(!(DaLiSePonavlja(V, V.at(i))))
					VektorProstihSimetricnihBrojeva.push_back(V.at(i));
			}
		}
		return VektorProstihSimetricnihBrojeva;
	} else if(!(prost)) {
		for(int i=0; i<V.size(); i++) {
			if(!(ProstBroj(V.at(i))) and TernarnaReprezentacija(V.at(i))) {
				if(!(DaLiSePonavlja(V, V.at(i))))
					VektorSlozenihSimetricnihBrojeva.push_back(V.at(i));
			}
		}

		return VektorSlozenihSimetricnihBrojeva;
	}
	return V;
}


int main ()
{
	std::cout << "Unesite elemente vektora (-1 za kraj): ";
	IntVektor UlazniVektor;
	int elemenat;

	while(std::cin >> elemenat and elemenat!=-1) {
		while(!(std::cin)) {
			std::cout << "Neispravan unos. Molimo unesite elemente vektora." << std::endl;
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			std::cin >> elemenat;
		}
		UlazniVektor.push_back(elemenat);
	}

	std::cout << "Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	int LogickaPromjenljiva;

	do {
		std::cin >> LogickaPromjenljiva;
		if(((LogickaPromjenljiva==1) or (LogickaPromjenljiva==0))) break;
		else {
			std::cout << "Neispravan unos. Unesite ponovo: ";
			std::cin.ignore(10000, '\n');
		}
	} while(LogickaPromjenljiva!=1 and LogickaPromjenljiva!=0);


	IntVektor A=IzdvojiSimetricneTernarne(UlazniVektor, LogickaPromjenljiva);

	if(LogickaPromjenljiva) {
		if(A.size()==0) {
			std::cout << "Nema prostih simetricnih brojeva u vektoru." << std::endl;
			return 0;
		}
		std::cout << "Prosti simetricni brojevi iz vektora su: " ;

		for(int i=0; i<A.size(); i++) {
			if(A.at(i)!=(A.at(A.size()-1))) {
				std::cout << A.at(i) << ", ";
			} else std::cout << A.at(i) << "."<< std::endl;
		}
	} else  {
		if(A.size()==0) {
			std::cout << "Nema slozenih simetricnih brojeva u vektoru." << std::endl;
			return 0;
		}
		std::cout << "Slozeni simetricni brojevi iz vektora su: " ;
		for(int i=0; i<A.size(); i++) {
			if(A.at(i)!=(A.at(A.size()-1))) {
				std::cout << A.at(i) << ", ";
			} else std::cout << A.at(i)<< "." << std::endl;
		}
	}

	return 0;
}