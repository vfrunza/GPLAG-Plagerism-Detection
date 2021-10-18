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

int TrebaMiOvaFunkcija(int x,int y)
{
	return -2*x+y;
}

bool MojaZaSortiranje(int x,int y)
{
	int BrojProstihFaktoraX(0);
	int BrojProstihFaktoraY(0);
	int temp1(fabs(x));
	int temp2(fabs(y));
	for (int i = 2; i<=x; i++) {
		if(temp1%i==0) {
			BrojProstihFaktoraX++;
			temp1=temp1/i;
			if(temp1==1) break;
			i=1;
		}
	}
	if(int(fabs(x))==1) BrojProstihFaktoraX=1;
	for (int i = 2; i<=y; i++) {
		if(temp2%i==0) {
			BrojProstihFaktoraY++;
			temp2=temp2/i;
			if(temp2==1) break;
			i=1;
		}
	}
	if(int(fabs(y))==1) BrojProstihFaktoraY=1;
	if(BrojProstihFaktoraX==BrojProstihFaktoraY) return x>y;
	return BrojProstihFaktoraX>BrojProstihFaktoraY;
}

template <typename Tip1,typename Tip2,typename Tip3>

void SortirajPodrucjeVrijednosti(Tip1 p1,Tip1 p2,Tip2 p3,Tip3 p4,typename std::remove_reference<decltype(*p4)>::type FunkKriterija(typename std::remove_reference<decltype(*p1)>::type,typename std::remove_reference<decltype(*p1)>::type),bool FunkKritSort(typename std::remove_reference<decltype(*p1)>::type,typename std::remove_reference<decltype(*p1)>::type))
{
	Tip1 temp1(p1);
	Tip2 temp2(p3);
	Tip3 temp3(p4);


	while(temp1!=p2) {
		temp1++;
		temp2++;
		temp3++;
	}
	sort(p1,p2,FunkKritSort);
	sort(p3,temp2,FunkKritSort);

	for (int i = 0; i < p2-p1; i++) {
		int j=0;
		for(j=0; j<p2-p1; j++) if(FunkKriterija(p1[i],p3[i])==p4[j]) break;
		if(j==p2-p1) throw std::logic_error("Vrijednost koja odgovara nekom od parova nije nadjena");
	}

	for(int i=0; i<p2-p1; i++) p4[i]=FunkKriterija(p1[i],p3[i]);
}

int main ()
{
	std::cout<<"Unesite broj elemenata: ";
	int n;
	std::cin>>n;
	std::cout<<"Unesite elemente prvog vektora: ";

	std::vector<int> v1(n);
	for(int i=0; i<n; i++) {
		std::cin>>v1.at(i);
		for(int j=0; j<i; j++) if(v1.at(i)==v1.at(j)) {
				i--;
				break;
			}

	}
	std::cin.ignore(10000,'\n');
	std::cout<<"Unesite elemente drugog vektora: ";
	std::vector<int> v2(n);
	for(int i=0; i<n; i++) {
		std::cin>>v2.at(i);
		for(int j=0; j<i; j++) if(v2.at(i)==v2.at(j)) {
				i--;
				break;
			}
	}
	std::cin.ignore(10000,'\n');
	std::cout<<"Unesite elemente treceg vektora: ";
	std::vector<int> v3(n);
	for(int i=0; i<n; i++) {
		std::cin>>v3.at(i);
		for(int j=0; j<i; j++) if(v3.at(i)==v3.at(j)) {
				i--;
				break;
			}
	}
	std::cin.ignore(10000,'\n');
	try {
		SortirajPodrucjeVrijednosti(v1.begin(),v1.end(),v2.begin(),v3.begin(),TrebaMiOvaFunkcija,MojaZaSortiranje);
	} catch(std::logic_error e) {
		std::cout<<std::endl<<"Izuzetak: "<<e.what();
		return 0;
	}
	std::cout<<std::endl<<"Nakon sortiranja podrucja vrijednosti imamo sljedece trojke: ";
	for(int i=0; i<v1.size(); i++) {

		std::cout<<std::endl;
		std::cout<<"f("<<v1.at(i)<<", "<<v2.at(i)<<") = "<<v3.at(i);

	}


	return 0;
}