#include <iostream>
#include <vector>
#include <cmath>
#include <stdexcept>
#include <algorithm>

using namespace std;

template<typename tip1, typename tip2>
void zasortiranje(tip1 pocetak1, int br, bool f(tip2,tip2))
{
	sort(pocetak1, pocetak1+br, f);
}

template<typename tip>
void zamijeni(tip p1, tip p2)
{
	auto temp=*p1; 
	*p1=*p2; 
	*p2=temp;
}


template<typename tip1, typename tip2, typename tip3, typename tip4, typename tip5>
void SortirajPodrucjeVrijednosti(tip1 pocetak1, tip1 kraj1, tip2 pocetak2, tip3 pocetak3, tip4 domen(tip4,tip4), bool yfun(tip5,tip5))
{
	zasortiranje(pocetak1, kraj1-pocetak1, yfun);
	zasortiranje(pocetak2, kraj1-pocetak1, yfun);
	tip1 pom1=pocetak1;
	tip2 pom2=pocetak2;
	tip3 pom3=pocetak3;
	while(pom1!=kraj1)
	{
		auto pom=pocetak3;
		int zamjena=0;
		while(pom!=pocetak3+(kraj1-pocetak1))
		{
			if(domen(*pom1, *pom2)!=*pom) {pom++; continue;}
			zamijeni(pom,pom3);
			zamjena=1;
			break;
		}
		if(zamjena!=1) throw logic_error("Vrijednost koja odgovara nekom od parova nije nadjena");
		pom1++;
		pom2++;
		pom3++;
	}
}

int funkcija(int n1, int n2) 
{ 
	return (-2*n1)+n2;
	
}

bool dalijeprost(int n)
{
	n=fabs(n);
	bool rez=true;
	if(n==0 || n==1) rez = false;
	if(n==2) rez = true;
	else for(int i=2; i<n; i++) 
			if(n%i==0) 
				rez = false;
	return rez;
}

vector<int> unos(vector<int> v, int br, int n) {
	cout<<"Unesite elemente ";
	if(br==1) cout<<"prvog vektora: ";
	else if(br==2) cout<<"drugog vektora: ";
	else cout<<"treceg vektora: ";
	br=0;
	while(br!=n)
	{
		int pom;
		cin>>pom;
		bool ima=false;
		for(int j=0; j<v.size(); j++) if(pom==v.at(j)) ima=true;
		if(!ima) {v.push_back(pom); br++;}
	}
	return v;
}

bool pfaktori(int n1, int n2)
{
	int pom1=n1, pom2=n2;
	int br1=0, br2=0;
	for(int i=1; i<pom1; i++) 
		if(dalijeprost(i)&& n1%i==0) 
			{ 
				pom1/=i;
				br1++;  
				i--;
				
			}
	for(int i=1; i<pom2; i++) 
		if(dalijeprost(i)&& n2%i==0) 
			{ 
				pom2/=i;
				br2++;  
				i--;
				
			}
	if(n1>n2)
		if(br1==br2) return true;
	if(br1>br2) return true;
	return false;
}


int main ()
{
	int n;
	vector<int> v1, v2, v3;
	cout<<"Unesite broj elemenata: ";
	cin>>n;
	v1=unos(v1,1,n);
	v2=unos(v2,2,n);
	v3=unos(v3,3,n);
	//cout<<endl<<v1.size()<<" "<<v2.size()<<" "<<v3.size()<<endl;
	cout<<endl;
	try {
		SortirajPodrucjeVrijednosti(v1.begin(), v1.end(), v2.begin(), v3.begin(), funkcija, pfaktori);
		cout<<"Nakon sortiranja podrucja vrijednosti imamo sljedece trojke: "<<endl;
		for(int i=0; i<v3.size(); i++) 
			cout<<"f("<<v1.at(i)<<", "<<v2.at(i)<<") = "<<v3.at(i)<<endl;
	}
	catch(logic_error ex) 
	{ 
		cout<<"Izuzetak: "<<ex.what(); 
		
	} 
	return 0;
}