#include <vector>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <deque>
template <typename T>
int BrojProsti(T a)
{
	int br(0);
	T k;
	if(a==0) return 0;
	if(a==1) return 1;
	else {
		int b(a%2);
		while (b==0) {
			br++;
			k=a/2;
			a=k;
			b=a%2;
		}
		for(int i(3); i<=a; i+=2) {
			int b(a%i);
			while(b==0) {
				br++;
				k=a/i;
				a=k;
				b=a%i;
			}
		}
	}
	return br;
}
template <typename Tip1,typename Tip2>
bool Prosti(Tip1 a, Tip2 b)
{
	auto x(BrojProsti(a)),y(BrojProsti(b));
	if(x>y) {
		return true;
	}
	if(x<y) return false;
	if(a>=b) return true;
	return false;

}
template <typename NekiTip1, typename NekiTip2>
auto fun(NekiTip1 a, NekiTip2 b) ->decltype(a+b)
{
	return -2*a+b;
}
template <typename PokTip1,typename PokTip2,typename PokTip3>
void SortirajPodrucjeVrijednosti(PokTip1 pocetak1,PokTip1 kraj1,PokTip2 pocetak2,PokTip3 pocetak3,decltype (*pocetak3+*pocetak3) fun (decltype (*pocetak1+*pocetak1),decltype(*pocetak2+*pocetak2)), bool Prosti (decltype(*pocetak1+*pocetak1), decltype(*pocetak2+*pocetak2)))
{
	PokTip2 p1,p2;
	int p=kraj1-pocetak1,br(0);
	p2=pocetak3+p;
	std::sort(pocetak1,kraj1,Prosti);
	std::sort(pocetak2,pocetak2+p,Prosti);
	std::transform(pocetak1,kraj1,pocetak2,pocetak3+p,fun);
	while (p2!=pocetak3+p+p) {
		p1=pocetak3;
		while (p1!=pocetak3+p) {
			if(*p2==*p1)  br++;
			p1++;
		}
		if(br==0)
			throw std::logic_error(" ");
		if(br>0) br=0;
		p2++;

	}
	p1=pocetak3;
	p2=pocetak3+p;
	while (p2!=pocetak3+2*p) {
		*p1=*p2;
		p1++;
		p2++;

	}
}
int main ()
{
	try {
		std::cout << "Unesite broj elemenata: ";
		int br_elemenata,broj;
		std::cin >> br_elemenata;
		std::vector<int>v1,v2,v3;
		v1.resize(br_elemenata);
		v2.resize(br_elemenata);
		v3.resize(br_elemenata);
		std::cout << "Unesite elemente prvog vektora: ";
		int br(0);
		for(int i(0); i<br_elemenata; i++) {
			std::cin >> broj;
			if(i==0) v1.at(i)=broj;
			else {
				br=std::count(v1.begin(),v1.end(),broj);
				if(br==0) v1.at(i)=broj;
				else i--;
			}
		}
		std::cout << "Unesite elemente drugog vektora: ";
		for(int i(0); i<br_elemenata; i++) {
			std::cin >> broj;
			if(i==0) v2.at(i)=broj;
			else {
				br=std::count(v2.begin(),v2.end(),broj);
				if(br==0) v2.at(i)=broj;
				else i--;
			}
		}
		std::cout << "Unesite elemente treceg vektora: ";
		for(int i(0); i<br_elemenata; i++) {
			std::cin >>broj;
			if(i==0) v3.at(i)=broj;
			else {
				br=std::count(v3.begin(),v3.end(),broj);
				if(br==0) v3.at(i)=broj;
				else  i--;
			}
		}
		v3.resize(v3.size()*2);

		SortirajPodrucjeVrijednosti(std::begin(v1),std::end(v1),std::begin(v2),std::begin(v3),fun,Prosti);
		std::cout << "\nNakon sortiranja podrucja vrijednosti imamo sljedece trojke: " << std::endl;
		for(int i(0); i<v1.size(); i++) {
			std::cout << "f(" <<v1.at(i)<<", "<<v2.at(i)<<") = "<<v3.at(i)<<std::endl;
		}
	} catch (...) {
		std::cout <<"\nIzuzetak: Vrijednost koja odgovara nekom od parova nije nadjena";
	}


	return 0;
}