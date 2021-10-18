/*B 2017/2018, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na email: bcocalic1@etf.unsa.ba.	
*/
#include <iostream>
#include <vector>
#include <cmath>
bool Prost(int n)
{
	bool p(false);
	if(n<0) n=-n;
	int s(0);
	for(int i(2);i<=sqrt(n);i++)
	if(n%i==0) s++;
	if(s==0) p=true;
	return p;
}
int terarni(int x)
{
	int br(0),t(0);
	while(x!=0)
	{
		
		t=(x%3)*(pow(10.,br))+t;
		br++;
		x=x/3;
	}
	return t;
}

bool prsim(int a)
{
	if(a<0) a=-a;
	a=terarni(a);
	std::vector<int> c;
	int s(0),x(0);
	while(a>0)
	{
		x=a%10;
		c.push_back(x);
		a=a/10;
	}
	for(int i(0);i<=c.size()/2;i++)
	{
		if(c.at(i)!=c.at(c.size()-1-i)) s++;
	}
	if (s==0) return true;
	else return false;
}
std::vector<int> IzdvojiSimetricneTerarne(std::vector<int> b, bool k)
{
	std::vector<int> a;
	int br(0);
	if(k){
	for(int e:b)	if(Prost(e)&&prsim(e)) 
	{
		for(int i(0);i<a.size();i++)
		{
		if(a.at(i)==e) br++;}
		if(br==0) a.push_back(e);
	}
	return a;
	}
	else {
		br=0;
		for(int f:b) if(!Prost(f)&&prsim(f)) 
		{
			for(int i(0);i<a.size();i++){
				if(a.at(i)==f) br++;
			}
			if (br==0) a.push_back(f);
		}
		return a;
	}
}

int main ()
{
	int n(2),s(0);
	bool k;
	std::vector<int> x,y;
	std::cout<<"Unesite elemente vektora (-1 za kraj): ";
	while(s!=-1) 
	{
		std::cin>>s;
		if(s==-1) break;
		x.push_back(s);
	}
	std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	while(n!=0 || n!=1)
	{
	std::cin>>n;
	if(n==1){ k=true;break;}
	else if(n==0) {k=false;break;}
	else std::cout<<"Neispravan unos! Unesite ponovo: ";
	}
	y=IzdvojiSimetricneTerarne(x,k);
	if(k && y.size()==0) {std::cout<<"Nema prostih simetricnih brojeva u vektoru.";return 0;}
	else if(!k && y.size()==0) {std::cout<<"Nema slozenih simetricnih brojeva u vektoru. "; return 0;}
	if(k) std::cout<<"Prosti simetricni brojevi iz vektora su: ";
	else std::cout<<"Slozeni simetricni brojevi iz vektora su: ";
	for(int i(0);i<y.size();i++) 
	{
		if(i!=y.size()-1) std::cout<<y.at(i)<<", ";
		else std::cout<<y.at(i)<<".";
	}
	return 0;
}