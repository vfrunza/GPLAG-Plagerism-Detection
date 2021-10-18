/*B 2017/2018, Zadaća 2, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na forum (c2).
*/
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <algorithm>
#include <vector>
#include <type_traits>

template <typename Tip>
void Razmijeni (Tip &x, Tip &y) 
{
	auto temp(x);
	x=y;
	y=temp;
}

template <typename Tip1, typename Tip2, typename Tip3, typename Fun1 , typename Fun2>
void SortirajPodrucjeVrijednosti(Tip1 poc, Tip1 kraj,Tip2 poc2, Tip3 poc3, Fun1 f1, Fun2 f2)
{ 
	std::sort(poc,kraj,f2);
	int vel(0);
	Tip1 temp(poc);
	while (temp!=kraj) {
		temp++;
		vel++;
	}
	std::sort(poc2,poc2+vel,f2);
	int i(0);
	while (poc!=kraj) {
		typename std::remove_reference<decltype(*poc3)>::type rez(f1(*poc,*poc2));
		Tip3 temp(std::find(poc3,poc3+vel,rez));
		if (temp!=poc3+vel) {
			Tip3 temp2(poc3+i);
			Razmijeni(temp,temp2);
		}
		else 
			throw std::logic_error ("Vrijednost koja odgovara nekom od parova nije nadjena");
		poc++;
		poc2++;
		i++;
	}
}

bool DaLiSePonavlja (const std::vector<int> &v, int n, int x) 
{
	for (int i=0;i<n;i++) {
		if (x==v.at(i))
			return true;
	}
	return false;
}

int Funkcija (int x, int y) 
{
	return (-2*x+y);
}

bool Prost (int n)
{
	if (n<2)
	return false;
	for (int i=2;i<=std::sqrt(n);i++) {
		if (n%i==0)
		return false;
	}
	return true;
}

int BrojProstihFaktora (int x) 
{
	x=std::fabs(x);
	int brojac(0);
	int i(2);
	if (x<=1)
		return 1;
	while (x!=1) {
		if (Prost(i)) {
			if (x%i==0) {
				brojac++;
				x/=i;
			}
			else
			i++;
		}
		else
		i++;
	}
	return brojac;
}

bool ViseProstih (int x, int y) 
{
	if (BrojProstihFaktora(x)==BrojProstihFaktora(y))
		return x>y;
	return BrojProstihFaktora(x)>BrojProstihFaktora(y);
}

int main ()
{
	try {
	int n;
	std::cout<<"Unesite broj elemenata: ";
	std::cin>>n;
	std::vector<int> v1(n),v2(n),v3(n);
	int unos;
	std::cout<<"Unesite elemente prvog vektora: ";
	for (int i=0;i<n;) {
		std::cin>>unos;
		if (!DaLiSePonavlja(v1,i,unos)) {
			v1.at(i)=unos;
			i++;
		}
	}
	std::cout<<"Unesite elemente drugog vektora: ";
	for (int i=0;i<n;) {
		std::cin>>unos;
		if (!DaLiSePonavlja(v2,i,unos)) {
			v2.at(i)=unos;
			i++;
		}
	}
	std::cout<<"Unesite elemente treceg vektora: \n";
	for (int i=0;i<n;) {
		std::cin>>unos;
		if (!DaLiSePonavlja(v3,i,unos)) {
			v3.at(i)=unos;
			i++;
		}
	}
	SortirajPodrucjeVrijednosti(v1.begin(),v1.end(),v2.begin(),v3.begin(),Funkcija,ViseProstih);
	std::cout<<"Nakon sortiranja podrucja vrijednosti imamo sljedece trojke:\n";
	for (int i=0;i<v1.size();i++) {
		std::cout<<"f("<<v1.at(i)<<", "<<v2.at(i)<<") = "<<Funkcija(v1.at(i),v2.at(i))<<std::endl;
	}
	}
	catch (std::logic_error izuz) {
		std::cout<<"Izuzetak: "<<izuz.what();
	}
	return 0;
}