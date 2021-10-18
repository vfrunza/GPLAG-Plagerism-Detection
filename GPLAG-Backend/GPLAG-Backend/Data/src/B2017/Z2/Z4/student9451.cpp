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

using namespace std;

bool prost(int x)
{
	x=-x;
	if(x==1) return false;
	if(x==2) return true;
	for(int i=2;i<x;i++)
		if(x%i==0) return false;
	return true;
}

int ProstiFaktori(int x)
{
	int br=0,temp=x;
	for(int i=2;i<temp;i++)
		if(x%i==0 && prost(i)==true)
		{  
			br++;
			temp/=i;
			i--;
		}
	return br;
}
int fun(int x,int y){return -2*x+y;}
bool PoProstim(int x,int y)
{
	if(ProstiFaktori(x)==ProstiFaktori(y)) return x>y;
	return ProstiFaktori(x)>ProstiFaktori(y);
}

template<typename t1,typename t2,typename t3,typename t4,typename t5,typename t6,typename t7>
void SortirajPodrucjeVrijednosti(t1 p1,t1 k1,t2 p2,t3 p3,t4 f(t5,t6),bool f1(t7,t7))
{
	int duzina=k1-p1;
	sort(p1,p1+duzina,f1);
	sort(p2,p2+duzina,f1);
	
	auto temp=p3;
	for(auto i=p1,j=p2;i!=k1;i++,j++)
	{
		
		auto k=p3;auto k3=p3+duzina;
		bool ImaLiGa=0;int br=0;
		while(k!=k3)
		{
			if(f(*i,*j)==*k)
			{
				ImaLiGa=1;
				break;
			}
			k++;br++;
		}
		
		if(ImaLiGa==1)
		{
			auto pom=*k;
				 *k=*temp;
				 *temp=pom;
		}
		else 
		{
			throw logic_error("Vrijednost koja odgovara nekom od parova nije nadjena");
		}
		temp++;
	}
}
int main ()
{   
	//cout<<ProstiFaktori(6);
	cout<<"Unesite broj elemenata: ";
	int n;cin>>n;
	vector<int> v1,v2,v3;
	
	cout<<"Unesite elemente prvog vektora: ";
	for(int i=0;i<n;i++)
	{
		int temp;bool ImaLiGa=0;
		cin>>temp;
		for(int a:v1) 
			if(a==temp) {i--;ImaLiGa=1;break;}
		if(ImaLiGa==1) continue;
		v1.push_back(temp);
	}
	
	cout<<"Unesite elemente drugog vektora: ";
	for(int i=0;i<n;i++)
	{
		int temp;bool ImaLiGa=0;
		cin>>temp;
		for(int a:v2) 
			if(a==temp) {i--;ImaLiGa=1;break;}
		if(ImaLiGa==1) continue;
		v2.push_back(temp);
	}
	
	cout<<"Unesite elemente treceg vektora: ";
	for(int i=0;i<n;i++)
	{
		int temp;bool ImaLiGa=0;
		cin>>temp;
		for(int a:v3) 
			if(a==temp) {i--;ImaLiGa=1;break;}
		if(ImaLiGa==1) continue;
		v3.push_back(temp);
	}
	
	cout<<endl;
	
	try
	{
	    SortirajPodrucjeVrijednosti(v1.begin(),v1.end(),v2.begin(),v3.begin(),fun,PoProstim);
		cout<<"Nakon sortiranja podrucja vrijednosti imamo sljedece trojke: "<<endl;
		int br=0;
		for(int a:v3)
		{
			cout<<"f("<<v1[br]<<", "<<v2[br]<<") = "<<a<<endl;
			br++;
		}
	}
	catch(logic_error e)
	{
		cout<<"Izuzetak: "<<e.what();
	}
	
	return 0;
}