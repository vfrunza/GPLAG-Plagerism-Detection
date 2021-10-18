//B 2017/2018, Zadaća 2, Zadatak 4
#include <iostream>
#include <vector>
#include <algorithm>
#include <type_traits>
#include <deque>
#include <stdexcept>
#include <cmath>

bool DaLiJeProst(int n)
{	
	if(n<=0)n*=-1;
	for(unsigned i=2; i<sqrt(n+1) ;i++)if(n%i==0)return false;
	return true;
}

template <typename Tip1, typename Tip2, typename Tip>
Tip f(Tip1 x, Tip2 y)
{
	return -2*x+y;
}

template <typename Tip1, typename Tip2>
bool f_sort(Tip1 x, Tip2 y)
{ 
	int br1(0), br2(0); 
	for(int i=2; i<x; i++){if(DaLiJeProst(i) && x%i==0){int broj(x); while(broj>1){broj/=i; br1++;}}};  
	for(int i=2; i<y; i++){if(DaLiJeProst(i) && y%i==0){int broj(y); while(broj>1){broj/=i; br2++;}}};  
	if(br1!=br2)return br1>br2; else return x>y;
}

template <typename IterTip1, typename IterTip2, typename IterTip3>
void SortirajPodrucjeVrijednosti(IterTip1 p1, IterTip1 p2, IterTip2 p3, IterTip3 p4, typename std::remove_reference<decltype(*p4)>::type (*f1)(typename std::remove_reference<decltype(*p1)>::type, typename std::remove_reference<decltype(*p3)>::type), bool (*f2)(typename std::remove_reference<decltype(*p1)>::type, typename std::remove_reference<decltype(*p3)>::type))
{
	int vel(p2-p1);
	std::sort(p1, p2, f2);
	std::sort(p3,p3+vel, f2);
	IterTip3 r(p4), s(p4);
	for(int i=0; i<vel; i++)
	{
		r=s;int br(0);
		for(int j=0; j<vel; j++)
		{
			if(f1(*p1,*p3)==*r)
			{	
				br++;
				auto temp(*r);
				*r=*s;
				*s=temp;
				if(s<p4+vel-1)s++;
			}
			if(r<p4+vel-1)r++;
		}
		if(br==0)throw(std::logic_error)"Vrijednost koja odgovara nekom od parova nije nadjena";
		br=0;
		p1++; 
		p3++;
	}
}

int main ()
{
	std::cout << "Unesite broj elemenata: ";
	int n;
	std::cin >> n;
	
	std::cout << "Unesite elemente prvog vektora: ";
	std::vector<int> v1(n,-99999);
	for(int i=0; i<n; i++)
	{
		int x;
		std::cin >> x;
		if(std::count(v1.begin(), v1.end(), x)>0)
		{
			i--;
			continue;
		}
		else v1.at(i)=x;
	}
	
	std::cout << "Unesite elemente drugog vektora: ";
	std::vector<int> v2(n,-99999);
	for(int i=0; i<n; i++)
	{
		int x;
		std::cin >> x;
		if(std::count(v2.begin(), v2.end(), x)>0)
		{
			i--;
			continue;
		}
		else v2.at(i)=x;
	}
	
	std::cout << "Unesite elemente treceg vektora: " << std::endl;
	std::vector<int> v3(n,-99999);
	for(int i=0; i<n; i++)
	{
		int x;
		std::cin >> x;
		if(std::count(v3.begin(), v3.end(), x)>0)
		{
			i--;
			continue;
		}
		else v3.at(i)=x;
	}
	
	try
	{
		(SortirajPodrucjeVrijednosti(v1.begin(), v1.end(), v2.begin(), v3.begin(), f, f_sort));
	}
	
	catch(std::logic_error izuzetak)
	{
		std::cout << "Izuzetak: " << izuzetak.what() << std::endl;
		return 0;
	}
	
	std::cout << "Nakon sortiranja podrucja vrijednosti imamo sljedece trojke: " << std::endl;
	for(int i=0; i<n; i++)std::cout << "f(" << v1.at(i) <<", " << v2.at(i) << ")"<< " = " << v3.at(i) << std::endl;
	return 0;
}