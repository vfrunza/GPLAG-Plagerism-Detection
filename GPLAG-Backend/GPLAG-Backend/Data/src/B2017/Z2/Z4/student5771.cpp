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
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <functional>

bool Prost(int x)
{
	if (x<0) x*=(-1);
	for (int i = 2; i < x; i++) {
		if (x%i==0) return false;
	}
	return true;
}

int BrojProstihFaktora(int x)
{
	int br(0);
	for (int i = 2; i < x; i++) {
		if (Prost(i)) if(x%i==0) br++;
	}
	return br;
}

bool MojKriterij(int x, int y)
{
	if (BrojProstihFaktora(x)==BrojProstihFaktora(y)) return x>y;
	return BrojProstihFaktora(x)>BrojProstihFaktora(y);
}

int fun(int x, int y)
{
	return (-2)*x+y;
}

template <typename T1,typename T2,typename T3,typename F1,typename F2>
void SortirajPodrucjeVrijednosti(T1 p1, T1 q1, T2 p2, T3 p3, F1 f(F1 x, F1 y), bool Kriterij (F2 a, F2 b))
{
	int kraj(q1-p1);
	std::sort(p1,p1+kraj,Kriterij);
	std::sort(p2,p2+kraj,Kriterij);
	auto pom1(p1);
	auto pom2(p3);
	for (int i = 0; i < kraj; i++) {
		bool iz(false);
		auto pom3(p3);
		while(pom3!=(p3+kraj)) {
			if (f(*p1, *p2) == *pom3) {
				auto temp(*pom3);
				*pom3=*p3;
				*p3=temp;
				iz=true;
			}
			pom3++;
		}
		p3++;
		p1++;
		p2++;
		if(iz==false) throw std::logic_error ("Vrijednost koja odgovara nekom od parova nije nadjena");
	}
}

int main ()
{
	std::cout<<"Unesite broj elemenata: ";
	int n;
	std::cin>>n;
	std::vector<int> v1;
	std::vector<int> v2;
	std::vector<int> v3;
	int el;
	std::cout<<"Unesite elemente prvog vektora: ";
	for (int i = 0; i < n; i++) {
		std::cin>>el;
		bool isti(false);
		for (int j = 0; j < v1.size(); j++) {
			if(el==v1.at(j)) isti=true;
		}
		if(isti==false) v1.push_back(el);
		else i--;
	}
	std::cout<<"Unesite elemente drugog vektora: ";
	for (int i = 0; i < n; i++) {
		std::cin>>el;
		bool isti(false);
		for (int j = 0; j < v2.size(); j++) {
			if(el==v2.at(j)) isti=true;
		}
		if(isti==false) v2.push_back(el);
		else i--;
	}
	std::cout<<"Unesite elemente treceg vektora: ";
	for (int i = 0; i < n; i++) {
		std::cin>>el;
		bool isti(false);
		for (int j = 0; j < v3.size(); j++) {
			if(el==v3.at(j)) isti=true;
		}
		if(isti==false) v3.push_back(el);
		else i--;
	}

	try {
		SortirajPodrucjeVrijednosti(v1.begin(), v1.end(), v2.begin(), v3.begin(), fun, MojKriterij);
		std::cout<<std::endl<<"Nakon sortiranja podrucja vrijednosti imamo sljedece trojke: "<<std::endl;
		for (int i = 0; i < n; i++) {
			std::cout<<"f("<<v1[i]<<", "<<v2[i]<<") = "<<v3[i]<<std::endl;
		}
	} catch(std::logic_error e) {
		std::cout<<std::endl<<"Izuzetak: "<<e.what();
	}
	return 0;
}