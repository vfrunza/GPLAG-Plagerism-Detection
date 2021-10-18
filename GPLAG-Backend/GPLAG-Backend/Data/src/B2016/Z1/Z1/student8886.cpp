/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <deque>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::deque;

long int OkreniBroj(deque<long int> cifre)
{
	long int suma(0);
	for (int i=0; i<cifre.size(); i++)
	{
		suma=suma*10+(cifre[i]);
		if (i==cifre.size()-1) break;
	}
	return suma;
}

long int PretvoriUTernarni(int n)
{
	int a(n);
	deque<long int> cifre;
	do
	{
		a/=3;
		a*=3;
		int var=n-a;
		if (var<0) var*=(-1);
		cifre.push_front(var);
		a/=3;
		n/=3;
	} while (a!=0);
	return OkreniBroj(cifre);
}

int DaLiJeGadni(long int n)
{
	vector<int> brojaci(3);
	do
	{
		int cifra=n%10;
		if (cifra==0) brojaci[0]++;
		else if (cifra==1) brojaci[1]++;
		else if (cifra==2) brojaci[2]++;
		n/=10;
	} while (n!=0);
	if (brojaci[0]!=0 and brojaci[1]!=0 and brojaci[2]!=0) 
	{
		if (brojaci[0]%2==0 and brojaci[1]%2==0 and brojaci[2]%2==0) return 1;
		else if (brojaci[0]%2!=0 and brojaci[1]%2!=0 and brojaci[2]%2!=0) return 0;
	}
	else 
	{
		if (brojaci[0]!=0 and brojaci[1]!=0 and brojaci[2]==0)
		{
			if (brojaci[0]%2==0 and brojaci[1]%2==0) return 1;
			else if (brojaci[0]%2!=0 and brojaci[1]%2!=0) return 0;
		}
		if (brojaci[0]!=0 and brojaci[2]!=0 and brojaci[1]==0)
		{
			if (brojaci[0]%2==0 and brojaci[2]%2==0) return 1;
			else if (brojaci[0]%2!=0 and brojaci[2]%2!=0) return 0;
		}
		if (brojaci[1]!=0 and brojaci[2]!=0 and brojaci[0]==0)
		{
			if (brojaci[1]%2==0 and brojaci[2]%2==0) return 1;
			else if (brojaci[1]%2!=0 and brojaci[2]%2!=0) return 0;
		}
		if (brojaci[0]!=0 and brojaci[1]==0 and brojaci[2]==0)
		{
			if (brojaci[0]%2==0) return 1;
			else if (brojaci[0]%2!=0) return 0;
		}
		if (brojaci[1]!=0 and brojaci[0]==0 and brojaci[2]==0)
		{
			if (brojaci[1]%2==0) return 1;
			else if (brojaci[1]%2!=0) return 0;
		}
		if (brojaci[2]!=0 and brojaci[1]==0 and brojaci[0]==0)
		{
			if (brojaci[2]%2==0) return 1;
			else if (brojaci[2]%2!=0) return 0;
		}
	}
	return -1;
}

vector<int> IzdvojiGadne(vector<int> v, bool opaki)
{
	vector<int> OPAKI(0);
	vector<int> ODVRATNI(0);
	for (int i=0; i<v.size(); i++)
	{
		long int ternarni=PretvoriUTernarni(v[i]);
		if (DaLiJeGadni(ternarni)==1) OPAKI.push_back(v[i]);
		else if (DaLiJeGadni(ternarni)==0) ODVRATNI.push_back(v[i]);
		if (i==v.size()-1) break;
	}
	for (int i=0; i<OPAKI.size(); i++)
	{
		for (int j=i+1; j<OPAKI.size(); j++)
		{
			if (OPAKI[i]==OPAKI[j]) 
			{
				OPAKI.erase(OPAKI.begin() + j);
				j--;
				if (j==OPAKI.size()-1) break;
			}
		} 
	}
	for (int i=0; i<ODVRATNI.size(); i++)
	{
		for (int j=i+1; j<ODVRATNI.size(); j++)
		{
			if (ODVRATNI[i]==ODVRATNI[j])
			{
				ODVRATNI.erase(ODVRATNI.begin() + j);
				j--;
				if (j==ODVRATNI.size()-1) break;
			}
		} 
	} 
	if (opaki) return OPAKI;
	return ODVRATNI;
}

int main ()
{
	int n;
	vector<int> a;
	cout << "Unesite brojeve (0 za prekid unosa): ";
	do
	{
		cin >> n;
		if(n!=0) a.push_back(n);
	} while (n!=0);
	vector<int> b=IzdvojiGadne(a, true);
	vector<int> c=IzdvojiGadne(a, false);
	cout << "Opaki: ";
	for (int i=0; i<b.size(); i++)
	    cout << b[i] << " ";
	cout << endl;
	cout << "Odvratni: ";
	for (int x: c)
	    cout << x << " "; 
	return 0;
}