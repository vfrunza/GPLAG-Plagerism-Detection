/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include<iostream>
#include<vector>
#include<deque>
#include<cmath>

bool PIliN(int n)
{
	if(n%2==0) return true;
	else return false;
}

int Test(std::vector<int> broj)
{
	std::vector<int> cifre(3, 0);
	for(int i=0; i<broj.size(); i++)
	{
		int c(broj[i]);
		cifre[c]++;
	}
	std::vector<bool> pomocni;
	for(int i=0; i<3; i++)
    {
        if(cifre[i]!=0) pomocni.push_back(PIliN(cifre[i]));
    }
    int p(0), q(0);
    for(int i=0; i<pomocni.size(); i++)
    {
        if(pomocni[i]) p++;
        else if(!pomocni[i]) q++;
    }
    if(p==pomocni.size()) return 1;
    else if(q==pomocni.size()) return 2;
    else return 3;
}

std::vector<int> Ternar(int br)
{
	if(br<0) br=fabs(br);
	std::deque<int> broj;
	for(;;)
	{
		int cifra;
		cifra=br%3;
		broj.push_front(cifra);
		br/=3;
		if(br==0) break;
	}
	std::vector<int> v;
	for(int i=0; i<broj.size(); i++)
	{
		v.push_back(broj[i]);
	}
	return v;
}

std::vector<int> IzdvojiGadne(std::vector<int> v, bool t)
{
	std::vector<int> pom;
	for(int i=0; i<v.size(); i++)
	{
		std::vector<int> broj(Ternar(v[i]));
		int k(Test(broj));
		if(t==true)
		{
			if(k==1) 
			{
				bool d(true);
				for(int j=0; j<pom.size(); j++)
				{
					if(v[i]==pom[j])
					{
						d=false;
						break;
					}
				}
				if(d==true) pom.push_back(v[i]);
			}
		}
		else if(t==false)
		{
			if(k==2) 
			{
				bool e(true);
				for(int j=0; j<pom.size(); j++)
				{
					if(v[i]==pom[j])
					{
						e=false;
						break;
					}
				}
				if(e==true) pom.push_back(v[i]);
			}
		}
	}
	return pom;
}

int main ()
{
	std::cout << "Unesite brojeve (0 za prekid unosa): ";
	std::vector<int> v;
	for(;;)
	{
		int n;
		std::cin >> n;
		if(n!=0) v.push_back(n);
		else break;
	}
	std::vector<int> a(IzdvojiGadne(v, true));
	std::vector<int> b(IzdvojiGadne(v, false));
	std::cout << "Opaki: ";
	for(int x: a) std::cout << x << " ";
	std::cout << std::endl;
	std::cout << "Odvratni: ";
	for(int y: b) std::cout << y << " ";
	return 0;
}