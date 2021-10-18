/*B 16/17, Zadaća 2, Zadatak 3
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba
	
*/
#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>
#include<cmath>
#include<iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::deque;

bool DaLiJeProst(long long int n)
{
    if(n<2) return false;
    else
    {
		double n1(sqrt(n));
		for(long long int i=2; i<=n1; i++)
		{
			if(n%i==0) return false;
			if(i==int(n1)) break;
		}
    }
	return true;
}

int BrojProstihFaktora(long long int broj)
{
	int brojac(0);
	
	for(long long int i=1; i<=broj; i++)
	{	
		if(broj%i==0) 
		{
			if(DaLiJeProst(i)) 
			{
				brojac++;
				long long int rez(broj/i);
				do
				{
					if(rez%i==0) 
					{
						brojac++;
						rez/=i;
					}
					else break;
				}while(rez!=0);
			}
		}
		if(i==broj) break;
	}
	
	return brojac;
}

int BrojSavrsenihDjelilaca(long long int broj)
{
	int brojac(0);
	
	for(int i=6; i<=broj; i++)
	{
		if(broj%i==0)
		{
			int suma(0);
			for(int j=1; j<i; j++)
				if(i%j==0) suma+=j;
			
			if(suma==i) brojac++;
		}
	}
	
	return brojac;
}

int SumaDjelilaca(long long int broj)
{
	int suma(0);
	broj=abs(broj);
	for(int i=1; i<=broj; i++)
		if(broj%i==0) suma+=i;
	
	return suma;
}

int SumaCifara(long long int broj)
{
	int sum_cif(0);
	
	do
	{
		int cifra(broj%10);
		if(cifra<0) cifra*=(-1);
		broj/=10;
		
		sum_cif+=cifra;
	} while(broj!=0);
	
	return sum_cif;
}

// Funkcija UvrnutaRazlika odredjuje obicnu razliku dva bloka
template <typename NekiKon1, typename NekiKon2>
auto UvrnutaRazlika(NekiKon1 pocetak1, NekiKon1 iza_kraja1, NekiKon2 pocetak2, NekiKon2 iza_kraja2) -> vector<vector<decltype(*pocetak1+*pocetak1)>>
{
	vector<vector<decltype(*pocetak1+*pocetak1)>> mat;
	for(int i=0; i<(iza_kraja1-pocetak1); i++)
	{
		int j;
		for(j=0; j<(iza_kraja2-pocetak2); j++)
		{
			if(pocetak1[i]==pocetak2[j]) break;
		}
		if(j==(iza_kraja2-pocetak2))
		{
			vector<decltype(*pocetak1+*pocetak1)> pom_vek;
			pom_vek.push_back(pocetak1[i]);
			pom_vek.push_back(0);
			mat.push_back(pom_vek);
		}
	}
	for(int i=0; i<(iza_kraja2-pocetak2); i++)
	{
		int j;
		for(j=0; j<(iza_kraja1-pocetak1); j++)
		{
			if(pocetak2[i]==pocetak1[j]) break;
		}
		if(j==(iza_kraja1-pocetak1))
		{
			vector<decltype(*pocetak1+*pocetak1)> pom_vek;
			pom_vek.push_back(pocetak2[i]);
			pom_vek.push_back(0);
			mat.push_back(pom_vek);
		}
	}
	
	std::sort(mat.begin(), mat.end(), [](vector<decltype(*pocetak1+*pocetak1)> a, vector<decltype(*pocetak1+*pocetak1)> b)->bool
	{ 
		if(a[0]>b[0]) return true;
		
		return false;
	});
	
	return mat;
}

// Funkcija UvrnutaRazlika odredjuje one elemente iz jednog 
// ili drugog bloka koji nemaju svog para u odnosu na funkciju f
template <typename NekiKon1, typename NekiKon2, typename NekiTip1, typename NekiTip2>
auto UvrnutaRazlika(NekiKon1 pocetak1, NekiKon1 iza_kraja1, NekiKon2 pocetak2, NekiKon2 iza_kraja2, NekiTip1 f(NekiTip2)) -> vector<vector<decltype(*pocetak1+*pocetak1)>>
{
	vector<vector<decltype(*pocetak1+*pocetak1)>> mat;
	for(int i=0; i<(iza_kraja1-pocetak1); i++)
	{
		int j;
		for(j=0; j<(iza_kraja2-pocetak2); j++)
		{
			if(f(pocetak1[i])==f(pocetak2[j])) break;
		}
		if(j==(iza_kraja2-pocetak2))
		{
			vector<decltype(*pocetak1+*pocetak1)> pom_vek;
			pom_vek.push_back(pocetak1[i]);
			pom_vek.push_back(f(pocetak1[i]));
			mat.push_back(pom_vek);
		}
	}
	for(int i=0; i<(iza_kraja2-pocetak2); i++)
	{
		int j;
		for(j=0; j<(iza_kraja1-pocetak1); j++)
		{
			if(f(pocetak2[i])==f(pocetak1[j])) break;
		}
		if(j==(iza_kraja1-pocetak1))
		{
			vector<decltype(*pocetak1+*pocetak1)> pom_vek;
			pom_vek.push_back(pocetak2[i]);
			pom_vek.push_back(f(pocetak2[i]));
			mat.push_back(pom_vek);
		}
	}
	
	std::sort(mat.begin(), mat.end(), [](vector<decltype(*pocetak1+*pocetak1)> a, vector<decltype(*pocetak1+*pocetak1)> b)->bool
	{ 
		if(a[0]>b[0]) return true;
		else if(a[0]==b[0] && a[1]>b[1]) return true;
		
		return false;
	});
	
	return mat;
}

// Funkcija UvrnutiPresjek odredjuje obicni presjek dva bloka
template <typename NekiKon1, typename NekiKon2>
auto UvrnutiPresjek(NekiKon1 pocetak1, NekiKon1 iza_kraja1, NekiKon2 pocetak2, NekiKon2 iza_kraja2) -> vector<vector<decltype(*pocetak1+*pocetak1)>>
{
	vector<vector<decltype(*pocetak1+*pocetak1)>> mat;
	for(int i=0; i<(iza_kraja1-pocetak1); i++)
	{
		for(int j=0; j<(iza_kraja2-pocetak2); j++)
		{
			if(pocetak1[i]==pocetak2[j])
			{
				vector<decltype(*pocetak1+*pocetak1)> pom_vek;
				pom_vek.push_back(pocetak1[i]);
				pom_vek.push_back(0);
				pom_vek.push_back(0);
				mat.push_back(pom_vek);
			}
		}
	}

	return mat;
}

// Funkcija UvrnutiPresjek odredjuje one elemente iz jednog 
// ili drugog bloka koji imaju svog para u odnosu na funkciju f
template <typename NekiKon1, typename NekiKon2, typename NekiTip1, typename NekiTip2>
auto UvrnutiPresjek(NekiKon1 pocetak1, NekiKon1 iza_kraja1, NekiKon2 pocetak2, NekiKon2 iza_kraja2, NekiTip1 f(NekiTip2)) -> vector<vector<decltype(*pocetak1+*pocetak1)>>
{
	vector<vector<decltype(*pocetak1+*pocetak1)>> mat;
	for(int i=0; i<(iza_kraja1-pocetak1); i++)
	{
		for(int j=0; j<(iza_kraja2-pocetak2); j++)
		{
			if(f(pocetak1[i])==f(pocetak2[j]))
			{
				vector<decltype(*pocetak1+*pocetak1)> pom_vek;
				pom_vek.push_back(pocetak1[i]);
				pom_vek.push_back(pocetak2[j]);
				pom_vek.push_back(f(pocetak1[i]));
				mat.push_back(pom_vek);
			}
		}
	}

	std::sort(mat.begin(), mat.end(), [](vector<decltype(*pocetak1+*pocetak1)> a, vector<decltype(*pocetak1+*pocetak1)> b)->bool
	{ 
		if(a[2]<b[2]) return true;
		else if(a[2]==b[2] && a[0]<b[0]) return true;
		else if(a[2]==b[2] && a[0]==b[0] && a[1]<b[1]) return true;
		
		return false;
	});
	
	return mat;
}

int main ()
{
	int n;
	cout << "Unesite broj elemenata prvog kontejnera: ";
	cin >> n;
	
	deque<int> prvi_kon;
	cout << "Unesite elemente prvog kontejnera: ";
	while(prvi_kon.size()!=n)
	{
		int broj;
		cin >> broj;
		int i;
		for(i=0; i<prvi_kon.size(); i++) if(prvi_kon[i]==broj) break;
		if(prvi_kon.size()==i) prvi_kon.push_back(broj);
	}
	
	int m;
	cout << "Unesite broj elemenata drugog kontejnera: ";
	cin >> m;
	
	deque<int> drugi_kon;
	cout << "Unesite elemente drugog kontejnera: ";
	while(drugi_kon.size()!=m)
	{
		int broj;
		cin >> broj;
		int i;
		for(i=0; i<drugi_kon.size(); i++) if(drugi_kon[i]==broj) break;
		if(drugi_kon.size()==i) drugi_kon.push_back(broj);
	}
	
	vector<vector<int>> mat1(UvrnutiPresjek(prvi_kon.begin(), prvi_kon.end(), drugi_kon.begin(), drugi_kon.end(), SumaCifara));
	cout << "Uvrnuti presjek kontejnera:" << endl;
	for(int i=0; i<mat1.size(); i++)
	{
		for(int j=0; j<mat1[i].size(); j++)
		{
			cout << std::setw(6) << mat1[i][j] << " ";
		}
		cout << endl;
	}
	
	vector<vector<int>> mat3(UvrnutaRazlika(prvi_kon.begin(), prvi_kon.end(), drugi_kon.begin(), drugi_kon.end(), BrojProstihFaktora));
	cout << "Uvrnuta razlika kontejnera:" << endl;
	for(int i=0; i<mat3.size(); i++)
	{
		for(int j=0; j<mat3[i].size(); j++)
		{
			cout << std::setw(6) << mat3[i][j] << " ";
		}
		cout << endl;
	}
	cout << "Dovidjenja!" << endl;
	
	return 0;
}


