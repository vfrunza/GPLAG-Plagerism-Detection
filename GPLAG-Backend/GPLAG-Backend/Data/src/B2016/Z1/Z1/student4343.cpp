/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include<iostream>
#include<vector>
#include<cmath>

long long int Konverzija(int n)
{
	long long int suma1(0);
	long long int suma2(0);
	int br(0);
	while(n%3==0)
	{
		br++;
		n/=3;
	}
	while(n!=0)
	{
		suma1+=n%3;
		suma1*=10;
		n/=3;
	}
	suma1/=10;
	while(suma1!=0)
	{
		suma2+=suma1%10;
		suma2*=10;
		suma1/=10;
	}
	suma2/=10;
	if(br!=0)
	{
		for(int i=1; i<=br; i++)
		{
			suma2*=10;
		}
	}
	return suma2;
}

bool Opaki(int n)
{
	if(n<0) n=-n;
	long long int O=Konverzija(n);
	int br0(0);
	int br1(0);
	int br2(0);
	while(O!=0)
	{
		int a(O%10);
		if(a==0) br0++;
		else if(a==1) br1++;
		else br2++;
		O/=10;
	}
	if(br0%2==0 && br1%2==0 && br2%2==0) return true;
	else return false;
}

bool Odvratni(int n)
{
	if(n<0) n=-n;
	long long int O=Konverzija(n);
	int br0(0);
	int br1(0);
	int br2(0);
	while(O!=0)
	{
		int a(O%10);
		if(a==0) br0++;
		else if(a==1) br1++;
		else br2++;
		O/=10;
	}
	if((br0==0 || br0%2==1) && (br1==0 || br1%2==1) && (br2==0 || br2%2==1)) return false;
	else return true;
}

std::vector<int> IzdvojiGadne(std::vector<int> v, bool T)
{
	std::vector<int> x;
	if(T==true)
	{
		for(int i=0; i<v.size(); i++)
		{
			if(Opaki(v[i])==T)
			{
				x.push_back(v[i]);
			}
		}
	}
	if(T==false)
	{
		for(int i=0; i<v.size(); i++)
		{
			if(Odvratni(v[i])==T)
			{
				x.push_back(v[i]);
			}
		}
	}
	if(x.size()>0)
	{
		for(int i=0; i<x.size()-1; i++)
		{
			for(int j=i+1; j<x.size(); j++)
			{
				if(x[i]==x[j])
				{
					for(int k=j; k<x.size()-1; k++)
					{
						x[k]=x[k+1];
					}
					x.resize(x.size()-1);
					j--;
				}
			}
		}
	}
	return x;
}

int main ()
{
	std::vector<int> v;
	std::cout << "Unesite brojeve (0 za prekid unosa): ";
	for(;;)
	{
		int a;
		std::cin >> a;
		if(a==0) break;
		v.push_back(a);
	}
	std::vector<int> m, n;
	m=IzdvojiGadne(v,true);
	n=IzdvojiGadne(v,false);
	std::cout << "Opaki: ";
	for(int i=0; i<m.size(); i++)
	{
		std::cout << m[i] << " ";
	}
	std::cout << "\nOdvratni: ";
	for(int i=0; i<n.size(); i++)
	{
		std::cout << n[i] << " ";
	}
	return 0;
} 