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
#include <type_traits>
#include <vector>
#include <deque>
#include <stdexcept>

/*template <typename TipA,TipB>
TipA funkcijaXY (Ti)
 */




template <typename Tip1, typename Tip2, typename Tip3>
void SortirajPodrucijeVrijednosti  (Tip1 a, Tip1 b, Tip2 c, Tip3 d , /*PETI PARAMETAR*/ typename std::remove_reference<decltype(*d)>::type Tip3 funkcijaXY(typename  std::remove_reference<decltype(*a)>::type Tip1 , 
typename  std::remove_reference<decltype(*b)>::type Tip2 ), /*ŠESTI PARAMETAR*/ bool Kriterij (typename  std::remove_reference<decltype(*a)>::type Tip1 , typename  std::remove_reference<decltype(*b)>::type Tip2 )) {
	auto Pom_A=a;
	auto Pom_B=b;
	auto Pom_C=c;
	auto Pom_D=d;
	int vel;
	while (Pom_A!=Pom_B) {
		vel++;
		
	}
	Pom_A=a;
	Pom_B=b;
//	std::sort (Pom_C, c+vel, kriterij);
//	std::sort (Pom_A, Pom_B, kriterij);

	while (Pom_A!=Pom_B) {
		auto temp= funkcijaXY (Pom_A, Pom_B);
		
	}
	
 	
 }
int main ()

{
	int vel;
	std::cout<<"Unesite broj elemenata: ";
	std::cin>>vel;
	std::vector<int> a(vel);
	int temp(0);
	std::cout<<"Unesite elemente prvog vektora: ";
	for (int i(0); i<vel ; i++) {
		std::cin>>temp;
		a[i]=temp;
	}
	std::vector<int> b(vel);
	std::cout<<"Unesite elemente drugog vektora: ";
	for (int i(0); i<vel ; i++) {
		std::cin>>temp;
		b[i]=temp;
	}
	std::vector<int> c(vel);
	std::cout<<"Unesite elemente treceg vektora: ";
	for (int i(0); i<vel ; i++) {
		std::cin>>temp;
		c[i]=temp;
	}
	try {
		SortirajPodrucijeVrijednosti (std::begin(a), std::end(a), std::begin(b), std::begin (c), [] (int x, int y) -> decltype (-2x+y) { return -2x+y;}, []  )
	}
	
	std::cout<<"Nakon sortiranja podrucja vrijednosti imamo sljedece trojke: "<<std::endl;
	

	
	
	return 0;
}