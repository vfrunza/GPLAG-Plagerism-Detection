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
#include <iterator>
#include <type_traits>
#include <cmath>


template <typename IterTip1, typename IterTip2, typename IterTip3, typename Funkcija1, typename Funkcija2> 
void SortirajPodrucjeVrijednosti( IterTip1 p1, IterTip1 p1_kraj, IterTip2 p2, IterTip3 p3, Funkcija1 f, Funkcija2 Kriterij )
{
	if(p1==p1_kraj) throw ("Prazan kontejner.");
	std::sort(p1, p1_kraj, Kriterij); //domen prvog parametra fije "f"
	int br_elemenata(p1_kraj-p1);
	std::sort(p2, p2 + br_elemenata, Kriterij); //domen drugog parametra fije "f"
	IterTip2 p2_kraj {};
	p2_kraj = p2 + br_elemenata;
	IterTip3 p3_kraj;
	p3_kraj = p3 + br_elemenata;
	int pozicija(0);
	while(p1!=p1_kraj && p2!=p2_kraj) {
		IterTip3 trenutno_mjesto (std::find(p3, p3_kraj, f(*p1, *p2)));
		if(trenutno_mjesto==p3_kraj) throw std::logic_error("Vrijednost koja odgovara nekom od parova nije nadjena");
		typename std::remove_reference<decltype(*p3)>::type temp(0);
		temp = *(p3 + pozicija);
		*(p3+pozicija) = *trenutno_mjesto;
		*trenutno_mjesto = temp;


		pozicija++;
		p1++;
		p2++;
	}
}


int main ()
{
	try {
		int n(0);
		std::cout<<"Unesite broj elemenata: ";
		std::cin>>n;
		std::cout<<"Unesite elemente prvog vektora: ";
		std::vector<int> S1;
		for(int i=0; i<n; i++) {
			int x;
			std::cin>>x;
			if( (std::count(std::begin(S1), std::end(S1), x)) == 0 ) S1.push_back(x);
			else i--;
		}
		std::cout<<"Unesite elemente drugog vektora: ";
		std::vector<int> S2;
		for(int i=0; i<n; i++) {
			int x;
			std::cin>>x;
			if( (std::count(std::begin(S2), std::end(S2), x)) == 0 ) S2.push_back(x);
			else i--;
		}
		std::cout<<"Unesite elemente treceg vektora: ";
		std::vector<int> S3;
		for(int i=0; i<n; i++) {
			int x;
			std::cin>>x;
			if( (std::count(std::begin(S3), std::end(S3), x)) == 0 ) S3.push_back(x);
			else i--;
		}
		SortirajPodrucjeVrijednosti(std::begin(S1), std::end(S1), std::begin(S2), std::begin(S3), [](int x, int y) {
			return -2*x + y;
		}, [](int x, int y) {
			int prosti_x(0);
			int prosti_y(0);
			int temp1(std::fabs(x));
			int temp2(std::fabs(y));
			for(int i=2; i<=x; i++) {
				while(temp1%i==0) {
					temp1/=i;
					prosti_x++;
				}
			}
			for(int i=2; i<=y; i++) {
				while(temp2%i==0) {
					temp2/=i;
					prosti_y++;
				}
			}
			if(prosti_x==prosti_y) return x>y;
			return prosti_x>prosti_y;
		} );
		std::cout<<"\nNakon sortiranja podrucja vrijednosti imamo sljedece trojke:\n";
		for(int i=0; i<n; i++) {
			std::cout<<"f("<<S1.at(i)<<", "<<S2.at(i)<<") = "<<S3.at(i)<<"\n";
		}
	} catch(std::logic_error izuzetak) {
		std::cout<<"\nIzuzetak: "<<izuzetak.what()<<std::endl;
	} catch(const char poruka[]) {
		std::cout<<"\nIzuzetak: "<<poruka<<std::endl;
	} catch(...) {
		std::cout<<"\nIzuzetak: Doslo je do greske.\n";
	}
	return 0;
}