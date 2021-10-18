#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <stdexcept>
#include <algorithm>
#include <cmath>
#include <list>

std::vector<int> Unesi (int n)
{
	std::vector<int> v;
	for (int i = 0; i<n; i++) {
		int broj;
		bool isti (false);
		std::cin>>broj;
		for (int j = 0; j<v.size(); j++)  // Provjerava da li ima istih elemenata
			if (broj==v.at(j)) {
				isti=true;
				break;
			}
		if (isti) {
			i--;
			continue;
		}
		v.push_back(broj);
	}
	return v;
}  //Unos vektora sa tastature

bool Prosti (int n)
{
	if (n==2) return true;
	if (n<0) n=-n;
	for (int i = 2; i<=sqrt(n); i++)
		if (n%i==0) return false;
	return true;
}  // Za proste faktore

template<typename Tip>
void Ispis (Tip pocetak, int dimnezija)
{
	for (int i = 0; i<dimnezija; i++) {
		std::cout<<*pocetak<<" ";
		pocetak++;
	}
} // Ispisuje vektor

template<typename TipIzlaz, typename TipUlaz>  // Funkcija koja je peti parametar
TipIzlaz f(TipUlaz x, TipUlaz y)
{
	return -2*x+y;
}

template<typename TipUlaz>
bool f_bool (TipUlaz x, TipUlaz y)
{
	int brojacx(0),brojacy(0);
	TipUlaz xprim(x),yprim(y);
	for (TipUlaz i = 2; i<= xprim; i++)
		if (Prosti(i))
			if (xprim%i==0) {
				while (x%i==0) {
					x=x/i;
					brojacx++;
				}
				x=xprim;
			}
	for (TipUlaz i = 2; i<=yprim; i++)
		if (Prosti(i))
			if (y%i==0) {
				while (y%i==0) {
					y=y/i;
					brojacy++;
				}
				y=yprim;
			}
	if (brojacx>brojacy) return true;
	else if (brojacy==brojacx) {
		if (x>y) return true;
		return false;
	}
	return false;
} // Funkcija koja je šesti parametar

// Tip elemenata u prvom i drugom bloku su isti, u trecem se mogu razlikovati
template <typename Tip12, typename Tip3, typename Tip4>
void SoritrajPodrucjeVrijednosti (Tip12 p1, Tip12 p2, Tip3 p3, Tip4 p4, decltype(*p4+*p4) f(decltype(*p1+*p1), decltype(*p1+*p1)), bool f_bool (decltype(*p1+*p1), decltype(*p1+*p1)) )
{
	// Pretpostavljam da je za iteratore samo podrzano ++, !=, ==, =
	int broj_elemenata(0),brojac(0);
	std::sort (p1,p2,f_bool);
	auto temp(p1);
	while (temp!=p2) {
		temp++;
		broj_elemenata++;
	}
	auto temp2=p3;
	int i(0);
	while (i<broj_elemenata) {
		temp2++;
		i++;
	}
	std::sort (p3,temp2,f_bool);
	auto temp3=p4;
	auto temp4=p4;
	bool barem_jedan(false);
	for (int i = 0; i<broj_elemenata; i++) {
		for (int j = 0; j<broj_elemenata; j++) {
			temp4=temp3;
			if (fabs(f(*p1,*p3)-*p4)<0.000001) {      // Uzimanje elemenata bloka 1 i 2 i poređenje sa elementima bloka 4
				for(int k = 0; k<i; k++)
					temp4++;
				decltype(*p4+*p4) pomoc=*temp4;    // Pomoc pomaze da zamjenim elemente na relativnim pozicijama
				*temp4=*p4;
				*p4=pomoc;
				brojac++;     // Brojac uspjesnih dodjeljivanja
				barem_jedan=true;   // Postoji barem jedan koji je isti kao rez. funkcije f
			}
			p4++;
		}
		if (!barem_jedan) break;
		p1++;
		p3++;
		p4 = temp3;
	}
	if (!barem_jedan || brojac!=broj_elemenata) throw std::logic_error("Vrijednost koja odgovara nekom od parova nije nadjena");
}

int main ()
{
	try {
		std::cout<<"Unesite broj elemenata: ";
		int n;
		std::cin>>n;
		std::vector<int> v1,v2,v3;
		std::cout<<"Unesite elemente prvog vektora: ";
		v1=Unesi(n);
		std::cout<<"Unesite elemente drugog vektora: ";
		v2=Unesi(n);
		std::cout<<"Unesite elemente treceg vektora: ";
		v3=Unesi(n);
		SoritrajPodrucjeVrijednosti(v1.begin(),v1.begin()+n,v2.begin(),v3.begin(),f,f_bool);
		std::cout<<"\nNakon sortiranja podrucja vrijednosti imamo sljedece trojke: "<<std::endl;
		for (int i = 0; i<n; i++)
			std::cout<<"f("<<v1.at(i)<<", "<<v2.at(i)<<") = "<<v3.at(i)<<std::endl;
	} catch (std::logic_error izuzetak) {
		std::cout<<"\nIzuzetak: "<<izuzetak.what();
	}
	/*try{std::cout<<"Unesi: \n";
	std::deque<int> d1{1,2,3,4,5,6},d2{1,2,3,4,5,6};
	std::deque<int> d3{-1,-2,-3,-4,-5,-6};
	auto it1(d1.begin()),it2(d2.begin());
	auto it3(d3.begin());
	SoritrajPodrucjeVrijednosti(d1.begin(),d1.end(),d2.begin(),d3.begin(),f,f_bool);
	for (int i = 0; i<6; i++){
	std::cout<<"f("<<*it1++<<", "<<*it2++<<") = "<<*it3++<<std::endl;
	}
	}
	catch (std::logic_error izuzetak){
		std::cout<<izuzetak.what();
	}*/
	return 0;
}