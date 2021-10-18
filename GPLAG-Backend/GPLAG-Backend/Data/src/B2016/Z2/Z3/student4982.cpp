#include <iostream>
#include <stdexcept>
#include <vector>
#include <deque>
#include <type_traits>
#include <cmath>
#include <algorithm>
#include <iomanip>

int SumaCifara(long long int x)
{
	int suma=0;
	while(x!=0)
	{
		suma+=std::abs(x%10);
		x=x/10;
	}
	return suma;
}

int SumaDjelilaca(long long int x)
{
	int suma=0;
	if(x<0) x=-x;
	for(long long int i=1;i<=x;i++)
	{
		if(x%i==0) suma+=i;
	}
	return suma;
}

bool DaLiJeProst(long long int x)
{
	if(x<=1) return false;
	long long int i=0;
	for(i=2;i<=(int)sqrt(x);i++)
	{
		if(x%i==0) return false;
	}
	if(i==(int)sqrt(x)+1) return true;
}

int BrojProstihFaktora(long long int x)
{
	if(x<=1) return 0;
	if(DaLiJeProst(x)==true) return 1;
	int i=2, suma=0, n=x;
	while(1)
	{
		if(i==x) break;
		if(DaLiJeProst(i)==false) i++;
		if(DaLiJeProst(i)==true)
		{
			if(n==1) break;
			if(n%i==0)
			{
				n=n/i;
				suma++;
			}
			else i++;
		
		}
	}
	
	return suma;
}

bool DaLiJeSavrsen(long long int x)
{
	int suma=0;
	for(long long int i=1;i<x;i++) if(x%i==0) suma+=i;
	if(suma==x) return true;
	else return false;
}

int BrojSavrsenihDjelilaca(long long int x)
{
	if(x<0) x=-x;
	int broj=0;
	for(long long int i=1;i<=x;i++) if(x%i==0 && DaLiJeSavrsen(i)==true) broj++;
	return broj;
}

template <typename Tip1, typename Tip2, typename Tip3, typename Tip4>
auto UvrnutiPresjek(Tip1 p1, Tip1 p2, Tip2 p3, Tip2 p4, Tip3 fun(Tip4)) -> std::vector<std::vector<typename std::remove_reference<decltype((*p1)+(*p3))>::type>>   
{
	typedef typename std::remove_reference<decltype((*p1)+(*p3))>::type Tip;
	std::vector<std::vector<Tip>> matrica;
	Tip2 poc2=p3;
	while(p1!=p2)
	{
		while(p3!=p4)
		{ 
			if(fun(*p1)==fun(*p3))
			{
				std::vector<Tip> v;
				v.push_back(*p1); v.push_back(*p3); v.push_back(fun(*p1));
				matrica.push_back(v);
			}
			p3++;
		}
		p3=poc2;
		p1++;
	}
	std::sort(matrica.begin(), matrica.end(), [](std::vector<Tip> x, std::vector<Tip> y) { return x[2]<y[2]; } );
	if(matrica.size()>1) {
	for(int i=0;i<matrica.size()-1;i++)
	{
		for(int j=i+1;j<matrica.size();j++)
		{
			if(matrica[i][2]==matrica[j][2])  std::sort(matrica.begin()+i,matrica.begin()+j+1, [](std::vector<Tip> x, std::vector<Tip> y) { return x[0]<y[0];}); 
		}
		
	}
	
	for(int i=0;i<matrica.size()-1;i++)
		{
			for(int j=i+1;j<matrica.size();j++)
			{
				if(matrica[i][0]==matrica[j][0]) std::sort(matrica.begin()+i,matrica.begin()+j+1, [](std::vector<Tip> x, std::vector<Tip> y) { return x[1]<y[1];});
			}
			
		}
}
	return matrica;
}

template <typename Tip1, typename Tip2>
auto UvrnutiPresjek(Tip1 p1, Tip1 p2, Tip2 p3, Tip2 p4) -> std::vector<std::vector<typename std::remove_reference<decltype((*p1)+(*p3))>::type>>
{
	typedef typename std::remove_reference<decltype((*p1)+(*p3))>::type Tip;
	std::vector<std::vector<Tip>> matrica;
	Tip2 poc=p3;
	while(p1!=p2)
	{
		while(p3!=p4)
		{
			if(*p1==*p3)
			{
				std::vector<Tip> v1;
				v1.push_back(*p1); v1.push_back(0); v1.push_back(0);
				matrica.push_back(v1); 
			}
			p3++;
		}
		p3=poc;
		p1++;
	}
	std::sort(matrica.begin(), matrica.end(), [] (std::vector<Tip> x, std::vector<Tip> y) { return x[0]<y[0]; });
	return matrica;
}

template<typename Tip1, typename Tip2, typename Tip3, typename Tip4>
auto UvrnutaRazlika(Tip1 p1, Tip1 p2, Tip2 p3, Tip2 p4, Tip3 fun(Tip4)) -> std::vector<std::vector<typename std::remove_reference<decltype((*p1)+(*p3))>::type>>
{
	typedef typename std::remove_reference<decltype((*p1)+(*p3))>::type Tip;
	std::vector<std::vector<Tip>> matrica;
	Tip1 poc=p1; Tip2 poc2=p3;
	while(p1!=p2)
	{
		bool par=false;
		while(p3!=p4)
		{
			if(fun(*p1)==fun(*p3)) par=true;
			p3++;
		}
		p3=poc2;
		if(par==false)
		{
			std::vector<Tip> v;
			v.push_back(*p1); v.push_back(fun(*p1));
			matrica.push_back(v);
		}
		p1++;
	}
	p1=poc;
	p3=poc2;
	while(p3!=p4)
	{
		bool par=false;
		while(p1!=p2)
		{
			if(fun(*p3)==fun(*p1)) par=true;
			p1++;
		}
		p1=poc;
		if(par==false)
		{
			std::vector<Tip> v;
			v.push_back(*p3); v.push_back(fun(*p3));
			matrica.push_back(v);
		}
		p3++;
	}
	std::sort(matrica.begin(),matrica.end(),[] (std::vector<Tip> x, std::vector<Tip> y) {return x[0]>y[0];} );
	if(matrica.size()>1) {
	for(int i=0;i<matrica.size()-1;i++)
	{
		for(int j=i+1;j<matrica.size();j++)
		{
			if(matrica[i][0]==matrica[j][0]) std::sort(matrica.begin()+i,matrica.begin()+j+1, [] (std::vector<Tip> x, std::vector<Tip> y) {return x[1]>y[1];} );
		}
	}
	}
	return matrica;
}

template<typename Tip1, typename Tip2>
auto UvrnutaRazlika(Tip1 p1, Tip1 p2, Tip2 p3, Tip2 p4) -> std::vector<std::vector<typename std::remove_reference<decltype((*p1)+(*p3))>::type>>
{
	typedef typename std::remove_reference<decltype((*p1)+(*p3))>::type Tip;
	std::vector<std::vector<Tip>> matrica;
	Tip1 poc=p1; Tip2 poc2=p3;
	while(p1!=p2)
	{
		bool par=false;
		while(p3!=p4)
		{
			if(*p1==*p3) par=true;
			p3++;
		}
		p3=poc2;
		if(par==false)
		{
			std::vector<Tip> v;
			v.push_back(*p1); v.push_back(0); 
			matrica.push_back(v);
		}
		p1++;
	}
	p1=poc; 
	p3=poc2;
	while(p3!=p4)
	{
		bool par=false;
		while(p1!=p2)
		{
			if(*p3==*p1) par=true;
			p1++;
		}
		p1=poc;
		if(par==false)
		{
			
			std::vector<Tip> v;
			v.push_back(*p3); v.push_back(0); 
			matrica.push_back(v);
			
		}
		p3++;
		}
		std::sort(matrica.begin(),matrica.end(),[](std::vector<Tip> x, std::vector<Tip> y){return x[0]>y[0];});
		return matrica;
	}
	


int main ()
{
	try {
	std::cout<<"Unesite broj elemenata prvog kontejnera: ";
	int n;
	std::cin>>n;
	std::deque<int> d1;
	std::cout<<"Unesite elemente prvog kontejnera: ";
	while(d1.size()<n)
	{
		int x;
		std::cin>>x;
		if(d1.size()==0) d1.push_back(x);
		else
		{
			bool ponavlja_se=false;
			for(int i=0;i<d1.size();i++) 
			{
				if(d1[i]==x)
				{
					ponavlja_se=true; break;
				}
			}
			if(ponavlja_se==false) d1.push_back(x);
		}
	}
	std::cout<<"Unesite broj elemenata drugog kontejnera: ";
	std::deque<int> d2; int k;
	std::cin>>k;
	std::cout<<"Unesite elemente drugog kontejnera: ";
	while(d2.size()<k)
	{
		int x; 
		std::cin>>x;
		if(d2.size()==0) d2.push_back(x);
		else
		{
			bool ponavlja_se=false;
			for(int i=0;i<d2.size();i++)
			{
				if(d2[i]==x)
				{
					ponavlja_se=true; break;
				}
			}
			if(ponavlja_se==false) d2.push_back(x);
		}
	}
	std::vector<std::vector<int>> matrica=UvrnutiPresjek(d1.begin(),d1.end(),d2.begin(),d2.end(),SumaCifara);
	std::vector<std::vector<int>> matrica2=UvrnutaRazlika(d1.begin(),d1.end(),d2.begin(),d2.end(),BrojProstihFaktora);
	std::cout<<"Uvrnuti presjek kontejnera:"<<std::endl;
	for(std::vector<int> red: matrica)
	{
		for(int x: red) std::cout<<std::setw(6)<<x<<" ";
		std::cout<<std::endl;
	}
	std::cout<<"Uvrnuta razlika kontejnera:"<<std::endl;
	for(std::vector<int> red: matrica2)
	{
		for(int x: red) std::cout<<std::setw(6)<<x<<" ";
		std::cout<<std::endl;
	}
	std::cout<<"Dovidjenja!";
	return 0;
	}
	catch(...)
	{
		std::cout<<"Izuzetak: nedovoljno memorije";
	}
}