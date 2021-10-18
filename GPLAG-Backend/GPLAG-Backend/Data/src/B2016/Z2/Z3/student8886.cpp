/*B 16/17, Zadaća 2, Zadatak 3
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba
	
*/
#include <iostream>
#include <cmath>
#include <vector>
#include <deque>
#include <iomanip>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::deque;
using std::remove_reference;

//Pomocne funkcije
int SumaDjelilaca(long long int x)
{
	int suma(0);
	if (x<0) x*=(-1);
	for (int i=1; i<=x; i++)
		if (x%i==0) suma+=i;
	return suma;
}
bool DaLiJeProst(int n)
{
	if (n<2) return false;
	for (int i=2; i<n; i++)
		if (n%i==0) return false;
	return true;
}
int Rekurzivna(long long int x, int &faktor)
{
	int brojac(0), fakt(1);
	for (int i(1); i<=x; i++)
	{
		if (x%i==0 and DaLiJeProst(i))
		{
			fakt*=i;
			brojac++;
		}
	}
	faktor=fakt;
	return brojac;
}
int BrojProstihFaktora(long long int x)
{
	int faktor(1), brojac(0), broj(0);
	for (int i(1); i<x; i++)
	{
		if ((x%i)==0 and DaLiJeProst(i)) 
		{
			faktor*=i;
			brojac++;
		}
	}
	int ostatak=x/faktor;
	if((ostatak)!=1) 
	{
		while ((ostatak)!=1)
		{
			broj+=Rekurzivna(static_cast<long long int> (ostatak), faktor);
			ostatak/=faktor;
		}
	}
	return brojac+broj;
}
bool DaLiJeSavrsen(int n)
{
	int suma(0);
	for (int i=1; i<n; i++)
		if (n%i==0) suma+=i;
	if (suma==n) return true;
	return false;
}
int BrojSavrsenihDjelilaca(long long int x)
{
	int brojac(0);
	for (int i=1; i<=x; i++)
		if(x%i==0 and DaLiJeSavrsen(i)) brojac++;
	return brojac;
}
int SumaCifara(long long int x)
{
	int suma(0);
	while (x!=0)
	{
		suma+=x%10;
		x/=10;
	}
	return suma;
}
//Funkcija UvrnutiPresjek
template<typename Tip1, typename Tip2, typename TipFun1, typename TipFun2>
	auto UvrnutiPresjek(Tip1 poc1, Tip1 kraj1, Tip2 poc2, Tip2 kraj2, TipFun1 f(TipFun2)) 
		-> vector<vector<typename remove_reference<decltype(*poc1)>::type>>
		{
			Tip1 p1, p2;
			Tip2 p3, p4;
			p1=poc1;
			p2=kraj1;
			p3=poc2;
			p4=kraj2;
			vector<vector<typename remove_reference<decltype(*poc1)>::type>> M(0, vector<typename remove_reference<decltype(*poc1)>::type>(3));
			while (p1!=p2)
			{
				p3=poc2;
				while (p3!=p4)
				{
					if (f(*p1)==f(*p3))
					{
						vector<typename remove_reference<decltype(*poc1)>::type> v(3);
						v[0]=*p1;
						v[1]=*p3;
						v[2]=f(*p1);
						M.push_back(v);
					}
					p3++;
				}
				p1++;
			}
			std::sort(M.begin(), M.end(), [] (vector<typename remove_reference<decltype(*poc1)>::type> v1, vector<typename remove_reference<decltype(*poc1)>::type> v2) { 
				if (v1[2]==v2[2] and v1[0]!=v2[0]) return v1[0]<v2[0];
				else if (v1[2]==v2[2] and v1[0]==v2[0] and v1[1]!=v2[1]) return v1[1]<v2[1];
				return v1[2]<v2[2]; }); 
			return M;
		}
template<typename Tip1, typename Tip2>
	auto UvrnutiPresjek(Tip1 poc1, Tip1 kraj1, Tip2 poc2, Tip2 kraj2)
		->vector<vector<typename remove_reference<decltype(*poc1)>::type>>
		{
			vector<vector<typename remove_reference<decltype(*poc1)>::type>> M(0, vector<typename remove_reference<decltype(*poc1)>::type>(3));
			Tip1 p1=poc1, p2=kraj1;
			Tip2 p3=poc2, p4=kraj2;
			while (p1!=p2)
			{
				p3=poc2;
				while (p3!=p4)
				{
					if (*p1==*p3) 
					{
						vector<typename remove_reference<decltype(*poc1)>::type> v(3);
						v[0]=*p1;
						v[1]=0;
						v[2]=0;
						M.push_back(v);
					}
					p3++;
				}
				p1++;
			}
			std::sort(M.begin(), M.end(), [] (vector<typename remove_reference<decltype(*poc1)>::type> v1, vector<typename remove_reference<decltype(*poc1)>::type> v2) {
				return v1[0]<v2[0]; });
			return M;
		}
//Funkcija UvrnutaRazlika
template<typename Tip1, typename Tip2, typename TipFun1, typename TipFun2>
	auto UvrnutaRazlika(Tip1 poc1, Tip1 kraj1, Tip2 poc2, Tip2 kraj2, TipFun1 f(TipFun2))
		-> vector<vector<typename remove_reference<decltype(*poc1)>::type>>
		{
			Tip1 p1=poc1, p2=kraj1;
			Tip2 p3=poc2, p4=kraj2;
			bool isti(false);
			vector<vector<typename remove_reference<decltype(*poc1)>::type>> M(0, vector<typename remove_reference<decltype(*poc1)>::type>(2));
			while (p1!=p2)
			{
				isti=false;
				p3=poc2;
				while (p3!=p4)
				{
					if (f(*p1)==f(*p3)) isti=true;
					if (isti) break;
					p3++;
				}
				if (isti) p1++;
				else
				{
					vector<typename remove_reference<decltype(*poc1)>::type> v(2);
					v[0]=*p1;
					v[1]=f(*p1);
					M.push_back(v);
					p1++;
				}
			}
			p1=poc1;
			p2=kraj1;
			p3=poc2;
			p4=kraj2;
			while (p3!=p4)
			{
				isti=false;
				p1=poc1;
				while (p1!=p2)
				{
					if (f(*p3)==f(*p1)) isti=true;
					if (isti) break;
					p1++;
				}
				if (isti) p3++;
				else
				{
					vector<typename remove_reference<decltype(*poc1)>::type> v(2);
					v[0]=*p3;
					v[1]=f(*p3);
					M.push_back(v);
					p3++;
				}
			}
			std::sort(M.begin(), M.end(), [] (vector<typename remove_reference<decltype(*poc1)>::type> v1, vector<typename remove_reference<decltype(*poc1)>::type> v2) {
				if (v1[0]==v2[0]) return v1[1]>v1[1];
				return v1[0]>v2[0]; });
			return M;
		}
template<typename Tip1, typename Tip2>
	auto UvrnutaRazlika(Tip1 poc1, Tip1 kraj1, Tip2 poc2, Tip2 kraj2)
		-> vector<vector<typename remove_reference<decltype(*poc1)>::type>>
		{
			Tip1 p1=poc1, p2=kraj1;
			Tip2 p3=poc2, p4=kraj2;
			bool isti(false);
			vector<vector<typename remove_reference<decltype(*poc1)>::type>> M(0, vector<typename remove_reference<decltype(*poc1)>::type>(2));
			while (p1!=p2)
			{
				isti=false;
				p3=poc2;
				while (p3!=p4)
				{
					if (*p1==*p3) isti=true;
					if (isti) break;
					p3++;
				}
				if (isti) p1++;
				else
				{
					vector<typename remove_reference<decltype(*poc1)>::type> v(2);
					v[0]=*p1;
					v[1]=0;
					M.push_back(v);
					p1++;
				}
			}
			isti=false;
			p1=poc1;
			p2=kraj1;
			p3=poc2;
			p4=kraj2;
			while (p3!=p4)
			{
				isti=false;
				p1=poc1;
				while (p1!=p2)
				{
					if (*p1==*p3) isti=true;
					if (isti) break;
					p1++;
				}
				if (isti) p3++;
				else 
				{
					vector<typename remove_reference<decltype(*poc1)>::type> v(2);
					v[0]=*p3;
					v[1]=0;
					M.push_back(v);
					p3++;
				}
			}
			std::sort(M.begin(), M.end(), [] (vector<typename remove_reference<decltype(*poc1)>::type> v1, vector<typename remove_reference<decltype(*poc1)>::type> v2) {
				return v1[0]>v2[0]; });
			return M;
		}
//Glavni program
int main()
{
	int n1, broj1;
	bool isti;
	cout << "Unesite broj elemenata prvog kontejnera: ";
	cin >> n1;
	deque<int> dek1;
	cout << "Unesite elemente prvog kontejnera: ";
	while (dek1.size()!=n1)
	{
		cin >> broj1;
		isti=false;
		for (int i=0; i<dek1.size(); i++)
		{
			if (dek1[i]==broj1) 
			{
				cin.clear();
				cin.ignore(10000, ' ');
				isti=true;
			}
		}
		if (!isti) dek1.push_back(broj1);
	}
	int n2, broj2;
	cout << "Unesite broj elemenata drugog kontejnera: ";
	cin >> n2;
	deque<int> dek2;
	cout << "Unesite elemente drugog kontejnera: ";
	while (dek2.size()!=n2)
	{
		cin >> broj2;
		isti=false;
		for (int i=0; i<dek2.size(); i++)
		{
			if (dek2[i]==broj2) 
			{
				cin.clear();
				cin.ignore(10000, ' ');
				isti=true;
			}
		}
		if (!isti) dek2.push_back(broj2);
	}
	cout << "Uvrnuti presjek kontejnera:" << endl;
	vector<vector<int>> pM(0, vector<int> (3));
	pM=UvrnutiPresjek(dek1.begin(), dek1.end(), dek2.begin(), dek2.end(), SumaCifara);
	for (int i(0); i<pM.size(); i++)
	{
		for (int j(0); j<3; j++)
		{
			cout << std::right << std::setw(6) << pM[i][j] << " ";
		}
		cout << endl;
	} 
	cout << "Uvrnuta razlika kontejnera:" << endl;
	vector<vector<int>> rM(0, vector<int> (2));
	rM=UvrnutaRazlika(dek1.begin(), dek1.end(), dek2.begin(), dek2.end(), BrojProstihFaktora);
	for (int i(0); i<rM.size(); i++)
	{
		for (int j(0); j<2; j++)
		{
			cout << std::right << std::setw(6) << rM[i][j] << " ";
		}
		cout << endl;
	}
	cout << "Dovidjenja!"; 
	return 0;
}