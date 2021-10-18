/*B 16/17, Zadaća 2, Zadatak 3

	NAPOMENA: i javni ATo-vi su dio postavke

	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba

*/
#include <iostream>

using namespace std;

template <typename T1,typename T2,typename T3>

UvrnutiPresjek(T1 pok1,T1 pok2,T2 pok3,T2 pok4,bool f(T3))
{
	vector<vector<int>>mat;
	mat.resize(n);
	for(int i=0; i<mat.size(); i++) {
		mat[i].resize(3);
	}

}

int SumaDjelilaca(int n)
{
	int suma=0;
	while(n!=0) {
		suma+=n%10;
		n/=10;
	}
	return suma;
}

vector<int>BrojProstihFaktora(int n)
{
	vector<int>v;
	int brojac=0;
	for(int i=2; i<n; i++) {
		if(n%i==0) {
			v.push_back(i);
			while(n%i==0)
			}
		n/=i;
	}
}
int main ()
{
	return 0;
}