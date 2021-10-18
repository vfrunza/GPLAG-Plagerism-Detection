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
#include <algorithm>
#include <stdexcept>
#include <vector>

int BrProstihFaktora(int broj)
{
	if(broj<2) return 0;
	int br_faktora(0);
	int faktor(2);
	do {
		if(broj%faktor==0) {
			br_faktora++;
			broj/=faktor;
			if(broj==1) break;
		} else faktor++;
	} while(broj>0);
	return br_faktora;
}

bool Kriterij(int x, int y)
{
	if(BrProstihFaktora(x)>BrProstihFaktora(y)) return true;
	else if(BrProstihFaktora(x)==BrProstihFaktora(y) && x>y) return true;
	return false;
}

int Funkcija(int x, int y)
{
	return (-2)*x+y;
}

template <typename IterTip_1, typename IterTip_2, typename IterTip_3>

void SortirajPodrucjeVrijednosti(IterTip_1 poc1, IterTip_1 kraj1, IterTip_2 poc2, IterTip_3 poc3,
                                 decltype(*poc3+0) f(decltype(*poc1+0),decltype(*poc1+0)),bool f_2(decltype(*poc1+0),decltype(*poc1+0)))
{
	int velicina=kraj1-poc1;
	std::sort(poc1,kraj1,f_2);
	std::sort(poc2,poc2+velicina,f_2);
	int pozicija(0);
	IterTip_3 pocetak=poc3;
	while(poc1!=kraj1) {
		auto rezutat=f(*poc1,*poc2);
		bool nasao(false);
		poc3=pocetak;
		while(poc3!=pocetak+velicina) {
			if(*poc3==rezutat) {
				nasao=true;
				auto temp=*(pocetak+pozicija);
				*(pocetak+pozicija)=*poc3;
				*poc3=temp;
				break;
			}
			poc3++;
		}
		if(!nasao) throw std::logic_error("Vrijednost koja odgovara nekom od parova nije nadjena");
		pozicija++;
		poc1++;
		poc2++;
	}
}

int main ()
{
	int br_elemenata;
	std::cout<<"Unesite broj elemenata: ";
	std::cin>>br_elemenata;
	std::vector<int> v1(br_elemenata),v2(br_elemenata),v3(br_elemenata);
	std::cout<<"Unesite elemente prvog vektora: ";
	for(int i=0; i<br_elemenata; i++) {
		int broj;
		std::cin>>broj;
		bool unesi(true);
		for(int j=0; j<i; j++) {
			if(v1.at(j)==broj) {
				unesi=false;
				break;
			}
		}
		if(unesi)v1.at(i)=broj;
		else i--;
	}
	std::cout<<"Unesite elemente drugog vektora: ";
	for(int i=0; i<br_elemenata; i++) {
		int broj;
		std::cin>>broj;
		bool unesi(true);
		for(int j=0; j<i; j++) {
			if(v2.at(j)==broj) {
				unesi=false;
				break;
			}
		}
		if(unesi)v2.at(i)=broj;
		else i--;
	}
	std::cout<<"Unesite elemente treceg vektora: ";
	for(int i=0; i<br_elemenata; i++) {
		int broj;
		std::cin>>broj;
		bool unesi(true);
		for(int j=0; j<i; j++) {
			if(v3.at(j)==broj) {
				unesi=false;
				break;
			}
		}
		if(unesi)v3.at(i)=broj;
		else i--;
	}
	try {
		SortirajPodrucjeVrijednosti(v1.begin(),v1.end(),v2.begin(),v3.begin(),Funkcija,Kriterij);
		std::cout<<std::endl<<"Nakon sortiranja podrucja vrijednosti imamo sljedece trojke: "<<std::endl;
		for(int i=0; i<br_elemenata; i++)
			std::cout<<"f("<<v1.at(i)<<", "<<v2.at(i)<<") = "<<v3.at(i)<<std::endl;
	} catch(std::logic_error izuzetak) {
		std::cout<<std::endl<<"Izuzetak: "<<izuzetak.what();
	}

	return 0;
}