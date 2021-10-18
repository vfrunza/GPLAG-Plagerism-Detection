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

bool JelProst (int x)
{

	for (int i = 2; i < x; i++) {
		if (x%i == 0) return false;
	}
	return true;
}

bool f2(int x, int y)
{
	int br1(0), br2(0);
	int k(x), l(y);
	while(k>1) {
		for(int i=2 ; i<=k ; i++) {
			if (k%i == 0 && JelProst(i) == true) {
				br1++;
				k=k/i;
				break;
			}

		}
	}
	while(l>1) {
		for(int i=2 ; i<=l ; i++) {
			if (l%i == 0 && JelProst(i) == true) {
				br2++;
				l=l/i;
				break;
			}
		}
	}
	if( br1>br2) return true;
	else if(br1== br2 && x>y) return true ;
	else return false;
}
int f1(int x,int y)
{
	return -2*x+y;
}
template <typename tip1, typename tip2, typename tip3>
void SortirajPodrucijeVrijednosti(tip1 poc1, tip1 kraj1, tip2 poc2, tip3 poc3, decltype(*poc3+0) fun(decltype(*poc1+0), decltype(*poc2+0)),bool  FSortiranja(decltype(*poc1+0), decltype(*poc2+0)))
{
	tip1 p1(poc1);
	tip1 p2(kraj1);
	tip2 p3(poc2);
	tip3 p4(poc3);
	int duz(kraj1-poc1);
	std::sort(p1, p2, FSortiranja);
	std::sort(p3, p3+duz, FSortiranja);
	decltype(*poc3+0) rez;
	int br(0);
	while(p1!=p2) {

		rez=fun(*p1,*p3);
		auto p(find(p4, p4+duz, rez));
		if(p==p4+duz) throw std::logic_error ("Vrijednost koja odgovara nekom od parova nije nadjena");
		else {
			int i=0;
			tip3 poz(poc3);
			while (i<br) {
				poz++;
				i++;
			}
			*p=*poz;
			*poz=rez;
		}
		p1++;
		p3++;
		br++;
	}

}

int main ()
{
	int n;
	std::cout<<"Unesite broj elemenata: ";
	std::cin>>n;
	std::vector<int> s1,s2,s3;
	std::cout<<"Unesite elemente prvog vektora: ";
	for(int i = 0; i < n; i++) {
		int x;
		std::cin>>x;
		int k = 0;
		for (int i = 0; i < s1.size(); i++) {
			if(x == s1.at(i)) k = 1;
		}
		if(k == 0) s1.push_back(x);
		else i--;
	}

	std::cout<<"Unesite elemente drugog vektora: ";
	for(int i = 0; i < n; i++) {
		int x;
		std::cin>>x;
		int k = 0;
		for (int i = 0; i < s2.size(); i++) {
			if(x == s2.at(i)) k = 1;
		}
		if(k == 0) s2.push_back(x);
		else i--;
	}
	std::cout<<"Unesite elemente treceg vektora: ";
	for(int i = 0; i < n; i++) {
		int x;
		std::cin>>x;
		int k = 0;
		for (int i = 0; i < s3.size(); i++) {
			if(x == s3.at(i)) k = 1;
		}
		if(k == 0) s3.push_back(x);
		else i--;
	}
	std::cout<<std::endl;
	try {
		SortirajPodrucijeVrijednosti(s1.begin(), s1.end(), s2.begin(), s3.begin(), f1, f2);

		std::cout<<std::endl<<"Nakon sortiranja podrucja vrijednosti imamo sljedece trojke: ";
		for(int i = 0; i < n; i++) std::cout<<std::endl<<"f("<<s1.at(i)<<", "<<s2.at(i)<<") = "<<s3.at(i);
	} catch(std::logic_error e) {
		std::cout<<"Izuzetak: "<<e.what();
	}
	return 0;
}