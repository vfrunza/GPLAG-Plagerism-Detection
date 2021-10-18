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
#include <vector>
#include <stdexcept>
#include <cmath>
int ProstiFaktori(int x)
{
	int br(0);
	if(x<=1) return 0;
	for(int i(2); i<x; i++) {
		if(x%i==0)br++;
	}
	return br;
}
int f1(int x,int y)
{
	return -2*x+y;
}
bool Prosti(int x,int y)
{
	if(ProstiFaktori(x)==ProstiFaktori(y))	return x>y;
	return ProstiFaktori(x)>ProstiFaktori(y);
}
template <typename Tip1,typename Tip2,typename Tip3>
void SortirajPodrucjeVrijednosti(Tip1 p1, Tip1 p2,Tip2 p3,Tip3 p4,decltype(*p4+*p4) f1 (decltype(*p1+*p1) x,decltype(*p1+*p1) y),
                                 bool f2(decltype(*p1+*p1) x,decltype(*p1+*p1) y))
{
	int velicina(p2-p1);
	std::sort(p1,p2,f2);
	std::sort(p3,p3+velicina,f2);
	auto pom(p1);



	while(p1!=p2) {
		int logicko(0);
		for(int i=0; i<velicina; i++) {

			if(f1(*p1,*p3)==*(p4+i)) {
				logicko=1;
				int pozicija(p1-pom);
				auto pomocna=*(p4+i);
				*(p4+i)=*(p4+pozicija);
				*(p4+pozicija)=pomocna;
			}
		}
		if(logicko==0) throw std::logic_error("Vrijednost koja odgovara nekom od parova nije nadjena");
		p1++;
		p3++;
	}
}

int main ()
{
	try {
		std::cout << "Unesite broj elemenata: " ;
		int n;
		std::cin >> n;
		std::cout << "Unesite elemente prvog vektora: ";
		std::vector<int> v1(n),v2(n),v3(n);
		for(int i(0); i<n; i++) {
			int logic(0);
			int x;
			std::cin >> x;
			for(int j(0); j<n; j++)
				if(x==v1.at(j)) {
					logic=1;
					i--;
					break;
				}
			if( logic==0) v1.at(i)=x;
		}
	/*	for(int i(0);i<v1.size();i++){
			for(int j(0);j<i;j++){
				if(v1.at(i)==v1.at(j)) {v1.erase(v1.begin()+i); i--; break;}
			}
		}
	*/	std::cout << "Unesite elemente drugog vektora: " ;
		for(int i(0); i<n; i++) {
			int logic(0);
			int x;
			std::cin >> x;
		for(int j(0); j<n; j++)
				if(x==v2.at(j)) {
					logic=1;
					i--;
					break;
				}
			if(logic==0) v2.at(i)=x;
			
		}
	/*		for(int i(0);i<v2.size();i++){
			for(int j(0);j<i;j++){
				if(v2.at(i)==v2.at(j)) {v2.erase(v2.begin()+i); i--; break;}
			}
		}
	*/	std::cout << "Unesite elemente treceg vektora: ";
		for(int i(0); i<n; i++) {
			int logic(0);
			int x;
			std::cin >> x;
			for(int j(0); j<n; j++)
				if(x==v3.at(j)) {
					logic=1;
					i--;
					break;
				}
			if(logic==0) v3.at(i)=x;
		
		}
	/*for(int i(0);i<v3.size();i++){
			for(int j(0);j<i;j++){
				if(v3.at(i)==v3.at(j)) {v3.erase(v3.begin()+i); i--; break;}
			}
		}
	*/	SortirajPodrucjeVrijednosti(v1.begin(),v1.end(),v2.begin(),v3.begin(),f1,Prosti);
		std::cout << std::endl<< "Nakon sortiranja podrucja vrijednosti imamo sljedece trojke: "<< std::endl;

		for (int i(0); i<n; i++) {
			std::cout << "f(" <<v1.at(i)<< ", "<< v2.at(i)<<") = "<<v3.at(i)<< std::endl;
		}
	} catch(std::logic_error poruka) {
		std::cout << std::endl<< "Izuzetak: "<< poruka.what() << std::endl;
	}

	return 0;
}