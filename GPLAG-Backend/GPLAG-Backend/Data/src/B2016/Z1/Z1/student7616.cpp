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

std::vector<int> IzbaciDuple(std::vector<int> v)
{
	for(int i=0; i<v.size(); i++)
	{
		for(int j=i+1; j<v.size(); j++)
		{
			if(v[i]==v[j])
			{
				for(int k=j; k<v.size()-1; k++)
				{
					v[k]=v[k+1];
				}
				v.resize(v.size()-1);
				j--;
			}
		}
	}
	return v;
}

long long int Pretvori(int broj)
{
	std::vector<long long int>v;
	long long int suma(0);
	if(broj==0) return 0;
	bool cs(false);
	/*if(broj<0)
	{
		cs=true;
		broj=-broj;
	}*/
	broj=abs(broj);
	while(broj!=0)
	{
		int ostatak;
		ostatak=broj%3;
		v.push_back(abs(ostatak));
		broj/=3;
	}
	for(int i=v.size()-1; i>=0; i--)
	{
		suma=suma*10 + v[i];
	}
	//if(cs) suma=-suma;
	return suma;
}

std::vector<int> IzdvojiGadne(std::vector<int> v, bool t)
{ 
	
	std::vector<int> pomocni;
	std::vector<int> v1(0);
	std::vector<int> v2(0);
	if(v.size() == 0) return v1;
	v=IzbaciDuple(v);
	pomocni=v;
	std::vector<long long int> m(v.size());

	for(int i=0; i<v.size(); i++)
	{
		m[i]=Pretvori(v[i]); 
	}
	for(int i=0; i<m.size(); i++)
	{
		if(m[i]==0) v2.push_back(pomocni[i]);
		int br_nula(0);
	    int br_jednica(0);
		int br_dva(0);
		long long int pom(m[i]);
		while(pom!=0)
		{
			int n(pom%10);
			if(n == 0) br_nula++;
			else if(n == 1) br_jednica++;
			else if( n==2) br_dva++;
			pom/=10;
		} //std::cout<<br_nula<<br_jednica<<br_dva;
		if(br_nula%2==0 && br_jednica%2==0 && br_dva%2==0 && v[i]!=0) v1.push_back(pomocni[i]);
		else if((br_nula==0 && br_jednica%2!=0 && br_dva==0) || (br_nula%2!=0 && br_jednica==0 && br_dva==0) || (br_nula==0 && br_jednica==0 && br_dva%2!=0) ||
		(br_nula%2!=0 && br_jednica%2!=0 && br_dva%2!=0) || (br_nula==0 && br_jednica%2!=0 && br_dva%2!=0) || (br_nula%2!=0 && br_jednica==0 && br_dva%2!=0) ||
		(br_nula%2!=0 && br_jednica%2!=0 && br_dva==0)) v2.push_back(pomocni[i]);
		
	}

	if(t) return v1;
	return v2;
}
int main()
{
	int n;
	std::vector<int>a;
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	do{
		std::cin>>n;
		if(n!=0) a.push_back(n);
	} while(n!=0);
	if(a.size()==0) return 0;
	std::vector<int> b;
	b=IzdvojiGadne(a,true);
	std::cout<<"Opaki: ";
	for(int i=0; i<b.size(); i++) std::cout<<b[i]<< " ";
	std::cout<<std::endl;
	std::vector <int> c;
	c=IzdvojiGadne(a,false);
	std::cout<<"Odvratni: ";
	for(int i=0; i<c.size(); i++) std::cout<<c[i]<< " ";
	return 0;
}