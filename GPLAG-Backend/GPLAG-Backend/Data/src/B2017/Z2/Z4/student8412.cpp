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
#include <vector>
#include<string>
#include<math.h>
#include<algorithm>
#include<stdexcept>
typedef std::vector<int> Vekint; 
bool DaLiJeProst(int a)
{
	if(a==2) return 1;
	if(a<=1) return 0;
	for(int i=2;i<a;i++)
	{
		if(a%i==0) return 0;
	}
	return 1;
}
int Broj_prostih_faktora(int x)
{
	int n=0;
	if(DaLiJeProst(x)) return 1;
	for(int i=2;i<=x;i++)
	{
	if(x%i==0 and DaLiJeProst(i)){ 
		n++;
		x=x/i;
		if(DaLiJeProst(x)){n++; return n;}
		i=1;
	}
	}
	return n;
}
bool Fja_sort_po_prostim_faktorima(int x,int y)
{
if(Broj_prostih_faktora(x)>Broj_prostih_faktora(y)) return 1;
if(Broj_prostih_faktora(x)==Broj_prostih_faktora(y) && x>y) return 1; 
return 0;
}
	
template<typename Itertip1,typename Itertip2,typename Itertip3,typename fja,typename elem1,typename elem2>
void SortirajPodrucjeVrijednosti(Itertip1 a,Itertip1 b,Itertip2 c,Itertip3 d,fja f1,bool f2(elem1,elem2))
{
//sortiramo nizove, nakon toga idemo i-petljom uzimemo clanove v1 i v2 izracunamo f od njih napravimo j-petlju da ide kroz vektor rjesenja kada nađe rješenje zamijeni j-ti član sa i-tim članom i break-a 	
std::sort(a,b,f2);
auto vel=b-a;
std::sort(c,c+vel,f2);
auto p3=d;
auto p=a;
auto p2=c;
int i=0;
while(p!=b)
{
auto r=f1(*p,*p2);
//std::cout<<"\n vrijednost r je"<<r<<"za x= "<<*p<<"za y= "<<*p2;
int k=0;
p3=d;
while(p3!=(d+vel))
{
	if(*p3==r) {
		auto temp=*p3;
		*p3=*(d+i);
		d[i]=temp;
		k=1;
		break;
	}
	p3++;
}
if(k==0) throw std::logic_error("Vrijednost koja odgovara nekom od parova nije nadjena");
i++;
p++;
p2++;
}
	
}



int main ()
{
	std::cout<<"Unesite broj elemenata: ";
	int br;
	std::cin>>br;
	std::vector<int> v1,v2,v3;
	std::cout<<"Unesite elemente prvog vektora: ";
	int i=0;
	int c=0;
	int k=0;
	for(;i<br;i++)
	{
		std::cin>>c;
		auto p=v1.begin();
		k=0;
		while(p!=v1.end())
		{
			if(*p==c){ k=1; break;}
			p++;
		}
		if(k==0) v1.push_back(c); else i--;
		
	}
	c=0;
	i=0;
	k=0;
	std::cout<<"Unesite elemente drugog vektora: ";
	for(;i<br;i++)
	{
		std::cin>>c;
		auto p2=v2.begin();
		k=0;
		while(p2!=v2.end())
		{
			if(*p2==c) {k=1; break;}
			p2++;
		}
		
		if(k==0) v2.push_back(c); else i--;
	}
	c=0;
	i=0;
	k=0;
	std::cout<<"Unesite elemente treceg vektora: ";
	for(;i<br;i++)
	{
		std::cin>>c;
		k=0;
		auto p3=v3.begin();
		while(p3!=v3.end())
		{
		if(*p3==c){k=1; break;}
		p3++;	
		}
		if(k==0) v3.push_back(c); else i--;
	}
	try{
	SortirajPodrucjeVrijednosti(v1.begin(),v1.end(),v2.begin(),v3.begin(),[] (int x,int y){return (-2*x+y);},Fja_sort_po_prostim_faktorima);
	std::cout<<"\nNakon sortiranja podrucja vrijednosti imamo sljedece trojke: ";
	for(i=0;i<br;i++)
	{
		std::cout<<std::endl<<"f("<<v1[i]<<", "<<v2[i]<<") = "<<v3[i];
		
	}
	}
	catch(std::logic_error e)
	{
		std::cout<<"\nIzuzetak: "<<e.what();
	}
	return 0;
}