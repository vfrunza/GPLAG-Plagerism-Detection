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
#include <algorithm>
#include <math.h>
#include <limits>

int VektorUInt(std::vector<int> v) // Funkcija koja pretvara clanove vektora u jedan INT
{

	int decimala = 1;
	int suma = 0;
	for (auto it : v) {
		suma += it * decimala;
		decimala *= 10;
	}
	return suma;
}

bool ProvjeriSimetriju (int n)
{

	int a,nazad=0,cifra;
	n = fabs(n);
	a = n;

	do {
		cifra = n%10;
		nazad = (nazad*10) + cifra;
		n=n/10;
	} while (n!=0);

	if(a==nazad) return true;

	else return false;

}

int Ternarni (int broj)
{

	std::vector<int> privremeni;
	int povratna=0;
	

	while (broj>0) {

		privremeni.push_back(broj%3);
		broj=broj/3;
	}

	

	povratna=VektorUInt(privremeni);

	return povratna;
}


int Decimalni (int n)
{

	std::vector<int> privremeni;
	int povratna=0;
	int i=0;
	int ostatak;

	while (n!=0) {
		ostatak = n%10;
		n/=10;
		povratna+= ostatak * pow(3,i);
		++i;
	}

	return povratna;
}

bool DaLiJeProst (int n) // Ovu funkciju sam kopirao sa tutorijala 2; licno sam je napisao i radi ustede vremena je nisam ponovo kucao
{

	bool status = true;
	n=fabs(n);
	if (n>1) {
		for (int i=2; i<=std::sqrt(n); ++i) {
			if (n%i==0) {

				status = false;
				break;
			}

		}
	} else status = false;
	return status;
}

std::vector<int>  IzdvojiSimetricneTernarne (std::vector<int> burazeri, int n)
{

	std::vector<int> pomocni;
	std::vector<int> pomocni2;

	if (n==1) {							// Kad trazi proste..

		for (int z : burazeri) {
			if (DaLiJeProst(z)) {
				if (ProvjeriSimetriju(Ternarni(z))==true)

					pomocni2.push_back(z);
			}
		}

	} else  {

		for (int z : burazeri) {
			if (DaLiJeProst(z)==false) {
				if (ProvjeriSimetriju(Ternarni(z))==true)

					pomocni2.push_back(z);
			}
		}
	}
	
	
for (int i=0; i<pomocni2.size(); i++) {
	for (int j=i+1; j<pomocni2.size(); j++) {
		
		if (pomocni2.at(i)==pomocni2.at(j)) {
			
			pomocni2.erase(pomocni2.begin()+j);
			j--;
		}
	}
	
}
	
	return pomocni2;

}


int main ()
{
	std::vector<int> brojevi;
	std::vector<int> pomocni_vektor;
	long long int  p;
	long long int broj ;

	std::cout << "Unesite elemente vektora (-1 za kraj): ";
	std::cin>>p;

	while (p!=-1) {
		
		
		brojevi.push_back(p);
		std::cin>>p;

	}

	std::cout << "Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	std::cin >> broj;
	
	
	
	while (!std::cin>>broj) {
		std::cout << "Neispravan unos! Unesite ponovo: ";
		std::cin.clear();
		std::cin.ignore(10000, '\n');
	
	}



	
bool temp = true;
	while (temp) {
	
		if (broj==1) {
			
			break;
			temp=false;
		}
		else if (broj==0) {
			
			break;
			temp=false;
		}
		
		std::cout << "Neispravan unos! Unesite ponovo: ";
		std::cin >> broj;
		
	}

	
	
	int vel = IzdvojiSimetricneTernarne(brojevi, broj).size();
	pomocni_vektor = IzdvojiSimetricneTernarne(brojevi,broj);
	

	if (broj==1) {
		
		if (vel==0) 
			std::cout<<"Nema prostih simetricnih brojeva u vektoru."; 
		
		else {
			
		std::cout <<"Prosti simetricni brojevi iz vektora su: ";
			
			for (int i = 0; i <vel; i++) {
			if (i!=vel-1)
			std::cout<<pomocni_vektor.at(i)<<", ";
			if(i==vel-1)
			std::cout<<pomocni_vektor.at(i)<<".";
			}
		}
		
	}
	
	else if (broj==0) {
		
		if (vel==0) 
			std::cout<<"Nema slozenih simetricnih brojeva u vektoru."; 
		
		else {
			std::cout <<"Slozeni simetricni brojevi iz vektora su: ";
			
			for (int i = 0; i <vel; i++) {
			if (i!=vel-1)
			std::cout<<pomocni_vektor.at(i)<<", ";
			if(i==vel-1)
			std::cout<<pomocni_vektor.at(i)<<".";
			}
		}
	}

return 0;


}