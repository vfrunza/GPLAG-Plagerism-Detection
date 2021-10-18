/*B 16/17, Zadaća 2, Zadatak 3
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba
	
*/
#include <iostream>
#include <new>
#include <functional>
#include <algorithm>
#include <vector>
#include <deque>
#include <iomanip>
#include <cstdlib>
#include <iterator>

template <typename Tipi>
bool FunkcijaPresjek(std::vector<Tipi> a,std::vector<Tipi> b)
{
	return ((a[2]<b[2]) || ((a[2]==b[2]) && (a[0]<b[0])) || ((a[2]==b[2]) && (a[0]==b[0]) && (a[1]<b[1])));
}


template <typename Tipii>
bool FunkcijaRazlika(std::vector<Tipii> a,std::vector<Tipii> b)
{
	return ((a[0]>b[0]) || ((a[0]==b[0]) && (a[1]<b[1])));
}

int SumaDjelilaca(long long int a)
{
	int suma=0;
	if(a<0)
	{
		for(int i=-1;i>a;i--)
		{
			if(a%i==0)
			suma=suma-i;
		}
		return suma-a;
	}
	for(int i=1;i<a;i++)
	{
		if(a%i==0)
		suma=suma+i;
	}
	return suma+a;
}

int BrojProstihFaktora(long long int a)
{
	int broj=0;
	if(a<0)
	{
		for(int i=-2;i>=a;i--)
	{
	
		if(a%i==0)
		{
			
			bool jelprost=true;
			for(int j=-2;j>=i+1;j--)
			{
				if(i%j==0)
				{jelprost=false;
				break;}
				else
				jelprost=true;
			}
			if(jelprost)
			{
			while(a%i==0)
			{
				a=a/i;
				broj++;
			}
			}
		}
	}
	return broj;
	}
	
	for(int i=2;i<=a;i++)
	{
		if(a%i==0)
		{
			
			bool jelprost=true;
			for(int j=2;j<=i-1;j++)
			{
				if(i%j==0)
				{jelprost=false;
				break;}
				else
				jelprost=true;
			}
			if(jelprost)
			{
			while(a%i==0)
			{
				a=a/i;
				broj++;
			}
			}
		}
	}
	
	return broj;
}

int BrojSavrsenihDjelilaca(long long int a)
{
	int broj=0;
	
	if(a<0)
	{
		for(long long int i=-2;i>=a;i--)
	{
		long long int suma=0;
		if(a%i==0)
		{
			for(long long int j=-1;j>i;j--)
			{
				if(i%j==0)
				{
					suma=suma+j;
				}
				
				
			}
			if(suma==i)
			broj++;
			
		}
	}
	
	return broj;
		
	
	}
	for(long long int i=2;i<=a;i++)
	{
		long long int suma=0;
		if(a%i==0)
		{
			for(long long int j=1;j<i;j++)
			{
				if(i%j==0)
				{
					suma=suma+j;
				}
				
				
			}
			if(suma==i)
			broj++;
			
		}
	}
	
	return broj;
}

int SumaCifara(long long int a)
{
	int suma=0;
	while(a!=0)
	{
		suma=suma+abs(a%10);
		a=a/10;
	}
	
	
	return suma;
}





template <typename Tip1, typename Tip2,typename Tip8,typename Tip9>
auto UvrnutiPresjek (Tip1 p1, Tip1 p2, Tip2 p3, Tip2 p4, Tip8 f(Tip9)) -> std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>>
{
	using Tip=typename std::remove_reference<decltype(*p1)>::type;
	std::vector<std::vector<Tip>>izlaz;
	Tip1 p11=p1;
	Tip2 p33=p3;
	while(p11!=p2)
	{
		p33=p3;
		while(p33!=p4)
		{
			if(f(*p11)==f(*p33))
			{
				izlaz.resize(izlaz.size()+1);
				izlaz[izlaz.size()-1].resize(3);
				izlaz[izlaz.size()-1][0]=*p11;
				izlaz[izlaz.size()-1][1]=*p33;
				izlaz[izlaz.size()-1][2]=f(*p11);
				
			}
			p33++;
		}
		
		
		p11++;
	}
	std::sort(izlaz.begin(),izlaz.end(),FunkcijaPresjek<Tip>);
	
	return izlaz;
}

template <typename Tip1, typename Tip2>
auto UvrnutiPresjek (Tip1 p1, Tip1 p2, Tip2 p3, Tip2 p4) -> std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>>
{
	using Tip=typename std::remove_reference<decltype(*p1)>::type;
	std::vector<std::vector<Tip>>izlaz;
	Tip1 p11=p1;
	Tip2 p33=p3;
	while(p11!=p2)
	{
		p33=p3;
		while(p33!=p4)
		{
			if(*p11==*p33)
			{
				izlaz.resize(izlaz.size()+1);
				izlaz[izlaz.size()-1].resize(3);
				izlaz[izlaz.size()-1][0]=*p11;
				izlaz[izlaz.size()-1][1]=0;
				izlaz[izlaz.size()-1][2]=0;
				
			}
			p33++;
		}
		
		
		p11++;
	}
	std::sort(izlaz.begin(),izlaz.end(),FunkcijaPresjek<Tip>);
	
	return izlaz;
}

template <typename Tip1, typename Tip2>
auto UvrnutaRazlika (Tip1 p1, Tip1 p2, Tip2 p3, Tip2 p4) -> std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>> 
{
	using Tip=typename std::remove_reference<decltype(*p1)>::type;
	std::vector<std::vector<Tip>>izlaz;
	{Tip1 p11=p1;
	Tip2 p33=p3;
	bool imalga=false;
	while(p11!=p2)
	{
		p33=p3;
		imalga=false;
		while(p33!=p4)
		{
			if(*p11==*p33)
			{
				imalga=true;break;
			}
			else
			imalga=false;
			p33++;
		}
		
		if(!imalga)
			{
				izlaz.resize(izlaz.size()+1);
				izlaz[izlaz.size()-1].resize(2);
				izlaz[izlaz.size()-1][0]=*p11;
				izlaz[izlaz.size()-1][1]=0;
				
				
			}
			
			
		p11++;
	}
	}
	
	{
	Tip1 p11=p1;
	Tip2 p33=p3;
	bool imalga=false;
	while(p33!=p4)
	{
		p11=p1;
		imalga=false;
		while(p11!=p2)
		{
			if(*p33==*p11)
			{
				imalga=true;break;
			}
			else
			imalga=false;
			p11++;
		}
		
		if(!imalga)
			{
				izlaz.resize(izlaz.size()+1);
				izlaz[izlaz.size()-1].resize(2);
				izlaz[izlaz.size()-1][0]=*p33;
				izlaz[izlaz.size()-1][1]=0;
				
				
			}
			
			
		p33++;
	}
	}
	
	std::sort(izlaz.begin(),izlaz.end(),FunkcijaRazlika<Tip>);
	
	return izlaz;
}


template <typename Tip1, typename Tip2,typename Tip8,typename Tip9>
auto UvrnutaRazlika (Tip1 p1, Tip1 p2, Tip2 p3, Tip2 p4, Tip8 f(Tip9)) -> std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>> 
{
	using Tip=typename std::remove_reference<decltype(*p1)>::type;
	std::vector<std::vector<Tip>>izlaz;
	{Tip1 p11=p1;
	Tip2 p33=p3;
	bool imalga=false;
	while(p11!=p2)
	{
		p33=p3;
		imalga=false;
		while(p33!=p4)
		{
			if(f(*p11)==f(*p33))
			{
				imalga=true;break;
			}
			else
			imalga=false;
			p33++;
		}
		
		if(!imalga)
			{
				izlaz.resize(izlaz.size()+1);
				izlaz[izlaz.size()-1].resize(2);
				izlaz[izlaz.size()-1][0]=*p11;
				izlaz[izlaz.size()-1][1]=f(*p11);
				
				
			}
			
			
		p11++;
	}
	}
	
	{
	Tip1 p11=p1;
	Tip2 p33=p3;
	bool imalga=false;
	while(p33!=p4)
	{
		p11=p1;
		imalga=false;
		while(p11!=p2)
		{
			if(f(*p33)==f(*p11))
			{
				imalga=true;break;
			}
			else
			imalga=false;
			p11++;
		}
		
		if(!imalga)
			{
				izlaz.resize(izlaz.size()+1);
				izlaz[izlaz.size()-1].resize(2);
				izlaz[izlaz.size()-1][0]=*p33;
				izlaz[izlaz.size()-1][1]=f(*p33);
				
				
			}
			
			
		p33++;
	}
	}
	
	std::sort(izlaz.begin(),izlaz.end(),FunkcijaRazlika<Tip>);
	
	return izlaz;
}

int main()
{
	std::cout<<"Unesite broj elemenata prvog kontejnera: ";
	int prvi;
	std::cin>>prvi;
	std::cout<<"Unesite elemente prvog kontejnera: ";
	std::deque<int>kec;
	{bool dobar(true);
	for(int i=0;i<prvi;i++)
	{
		dobar=true;
		int a;
		std::cin>>a;
		for(int j=0;j<kec.size();j++)
		{
			if(a==kec[j])
			{dobar=false;
			break;}
			
		}
		if(!dobar)
		i--;
		else
		kec.push_back(a);
		
	}
	}
	
	
	std::cout<<"Unesite broj elemenata drugog kontejnera: ";
	int drugi;
	std::cin>>drugi;
	std::cout<<"Unesite elemente drugog kontejnera: ";
	std::deque<int>dvica;
	{bool dobar(true);
	for(int i=0;i<drugi;i++)
	{
		dobar=true;
		int a;
		std::cin>>a;
		for(int j=0;j<dvica.size();j++)
		{
			if(a==dvica[j])
			{dobar=false;
			break;}
			
		}
		if(!dobar)
		i--;
		else
		dvica.push_back(a);
		
	}
	}
	std::vector<std::vector<int>>izlaz=UvrnutiPresjek(kec.begin(),kec.end(),dvica.begin(),dvica.end(),SumaCifara);
	std::cout<<"Uvrnuti presjek kontejnera:"<<std::endl;
	for(int i=0;i<izlaz.size();i++)
	{
		std::cout<<std::setw(6)<<izlaz[i][0]<<std::setw(7)<<std::setprecision(12)<<izlaz[i][1]<<std::setw(7)<<std::setprecision(12)<<izlaz[i][2]<<" "<<std::endl;
	}
	izlaz=UvrnutaRazlika(kec.begin(),kec.end(),dvica.begin(),dvica.end(),BrojProstihFaktora);
	std::cout<<"Uvrnuta razlika kontejnera:"<<std::endl;
	for(int i=0;i<izlaz.size();i++)
	{
		std::cout<<std::setw(6)<<std::setprecision(12)<<izlaz[i][0]<<std::setw(7)<<std::setprecision(12)<<izlaz[i][1]<<" "<<std::endl;
	}
	std::cout<<"Dovidjenja!";
	
	return 0;
}



