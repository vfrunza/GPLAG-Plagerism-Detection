#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int Funkcija (int x, int y)
{
	return -2*x+y;
}

bool Prost(int n)
{
	if (n==2 || n==3 ) return true;
	if (n<0 || n==1) return false;
	if ( n%2==0 ) return false;
	for (int i=3; (unsigned int)(i*i)<=n; i++) {
		if ( n%i==0 ) return false;
	}
	return true;
}

int BrojProstihFaktora (int x)
{
	int broj(0);
	if (x==0 || x==1) {
		broj++;
		return broj;
	}
	for (int i=1; i<=x; i++) {
		double pom(x);
		if (Prost(i)) {
			for (;;) {
				pom=pom/i;
				if (pom==int(pom))
					broj++;
				else break;
			}
		}
	}
	return broj;
}

bool Poredjenje (int x, int y)
{
	if (BrojProstihFaktora(x)==BrojProstihFaktora(y)) {
		if (x>y) return true;
	}
	if (BrojProstihFaktora(x)>BrojProstihFaktora(y)) return true;
	return false;
}

template <typename tip1, typename tip2, typename tip3>
void SortirajPodrucjeVrijednosti (tip1 niz1_p, tip1 niz1_k, tip2 niz2, tip3 niz3,decltype(*niz3+0) f(decltype(*niz1_p+0),decltype(*niz1_p+0)), bool g(decltype(*niz1_p+0),decltype(*niz1_p+0)))
{
	bool greska(true);
	int u(0);
	std::sort (niz1_p,niz1_k,g);
	int brojac=0;
	tip1 p(niz1_p);
	while (p!=niz1_k) {
		p++;
		brojac++;
	}
	std::sort (niz2,niz2+brojac,g);
	auto pomocni1(niz1_p);
	auto pomocni2(niz2);
	while (pomocni1!=niz1_k) {
		auto vrijednost (f(*pomocni1, *pomocni2));
		auto temp (niz3);
		auto spas(niz1_p);
		while (spas!=niz1_k) {
			greska=true;
			if (vrijednost==*temp) {
				u++;
				greska=false;
				break;
			} else {
				temp++;
				spas++;
			}
		}
		if (greska) throw std::logic_error ("Vrijednost koja odgovara nekom od parova nije nadjena");
		pomocni1++;
		pomocni2++;
	}
	if (u==brojac) {
		while (niz1_p!=niz1_k) {
			*niz3++=f(*niz1_p++,*niz2++);
		}
	}
}

int main ()
{
	try {
		std::cout<<"Unesite broj elemenata: ";
		int n;
		std::cin>>n;
		std::cout<<"Unesite elemente prvog vektora: ";
		std::vector <int> vektor1;

		while (vektor1.size()!=n) {
			int a;
			std::cin>>a;
			bool unesen(false);
			for (int i=0; i<vektor1.size(); i++) {
				if (a==vektor1.at(i)) {
					unesen=true;
					break;
				}
			}
			if (unesen==false)
				vektor1.push_back(a);
		}

		std::cout<<"Unesite elemente drugog vektora: ";
		std::vector<int> vektor2;
		while (vektor2.size()!=n) {
			int b;
			std::cin>>b;
			bool unesen(false);
			for (int i=0; i<vektor2.size(); i++) {
				if (b==vektor2.at(i)) {
					unesen=true;
					break;
				}
			}
			if (unesen==false)
				vektor2.push_back(b);
		}

		std::cout<<"Unesite elemente treceg vektora: ";
		std::vector<int> vektor3;
		while (vektor3.size()!=n) {
			int c;
			std::cin>>c;
			bool unesen(false);
			for (int i=0; i<vektor3.size(); i++) {
				if (c==vektor3.at(i)) {
					unesen=true;
					break;
				}
			}
			if (unesen==false)
				vektor3.push_back(c);
		}
		SortirajPodrucjeVrijednosti(vektor1.begin(),vektor1.end(),vektor2.begin(),vektor3.begin(),Funkcija,Poredjenje);
		std::cout<<std::endl<<"Nakon sortiranja podrucja vrijednosti imamo sljedece trojke: "<<std::endl;
		for (int i=0; i<vektor3.size(); i++) {
			std::cout<<"f("<<vektor1.at(i)<<", "<<vektor2.at(i)<<") = "<<vektor3.at(i)<<std::endl;
		}
	} catch(std::logic_error izuzetak) {
		std::cout<<std::endl<<"Izuzetak: "<<izuzetak.what();
	}

	return 0;
}