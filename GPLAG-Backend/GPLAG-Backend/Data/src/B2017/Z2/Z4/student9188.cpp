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
#include <algorithm>
#include <stdexcept>
#include <cmath>

bool DaLiJeProst(int x)
{
	if(x<2) return false;
	for(int i=2; i<=sqrt(x); i++) if(x%i==0) {
			return false;
		}
	return true;
}

int BrojProstihFaktora(int x)
{
	if(x<=0) return 0;
	int brojac(0);
	int brojac2(2);
	while( x != 1) {
		if(abs(x) % brojac2 == 0) {
			if(DaLiJeProst(brojac2)) {
				x /= brojac2;
				brojac++;
				brojac2--;
			}
		}
		brojac2++;
	}
	return brojac;

}
bool funkcija_kriterija(int x, int y)
{
	if(BrojProstihFaktora(x)==BrojProstihFaktora(y)) return y<x;
	return BrojProstihFaktora(x)>BrojProstihFaktora(y);
}
int funkcija(int x, int y)
{
	return -2*x+y;

}
void UnosBrojeva(std::vector<int> &v,int velicina)
{
	bool ima(false);
	for(int i=0; i<velicina; i++) {
		int k;
		std::cin>>k;
		for(int i=0; i<v.size(); i++) {
			if(k==v.at(i)) {
				ima=true;
				break;
			}
		}
		if(ima) {
			ima=false;
			i--;
		} else v.push_back(k);
	}
}
template <typename Tip1, typename Tip2, typename Tip3,typename Tip4, typename Tip5>
void SortirajPodrucjeVrijednosti(Tip1 pocetak1, Tip1 kraj1, Tip2 pocetak2, Tip3 pocetak3, Tip4 funkcijica(Tip5,Tip5),bool funkcijica_kriterija(Tip5,Tip5))
{
	bool ima(false);
	int pozicija(-100),duzina(kraj1-pocetak1),koeficijent(0);
	std::sort(pocetak1, kraj1,funkcijica_kriterija);
	std::sort(pocetak2, pocetak2+duzina,funkcijica_kriterija);
	while(koeficijent<duzina) {
		auto rezultat(funkcijica(*(pocetak1+koeficijent),*(pocetak2+koeficijent)));
		for(int i=0; i<duzina; i++) {
			if( rezultat == *(pocetak3+i)) {
				ima = true;
				pozicija = i;
				break;
			}
		}
		if(ima) {
			auto temp = *(pocetak3+koeficijent);
			*(pocetak3+koeficijent) = *(pocetak3+pozicija);
			*(pocetak3+pozicija) = temp;
			ima = false;
		} else throw std::logic_error("Vrijednost koja odgovara nekom od parova nije nadjena");
		koeficijent++;
	}
}
int main ()
{
	std::cout<<"Unesite broj elemenata: ";
	int n;
	std::cin>>n;
	std::vector<int> s1,s2,s3;
	std::cout<<"Unesite elemente prvog vektora: ";
	UnosBrojeva(s1,n);
	std::cout<<"Unesite elemente drugog vektora: ";
	UnosBrojeva(s2,n);
	std::cout<<"Unesite elemente treceg vektora: ";
	UnosBrojeva(s3,n);
	
	try {
		SortirajPodrucjeVrijednosti(s1.begin(),s1.end(),s2.begin(),s3.begin(),funkcija,funkcija_kriterija);
		std::cout<<std::endl<<"Nakon sortiranja podrucja vrijednosti imamo sljedece trojke:"<<std::endl;
		for(int i=0; i<n; i++)
			std::cout<<"f("<<s1.at(i)<<", "<<s2.at(i)<<") = "<<s3.at(i)<<std::endl;

	} catch(std::logic_error izuzetak){
		std::cout<<std::endl<<"Izuzetak: "<<izuzetak.what();
	}



	return 0;
}