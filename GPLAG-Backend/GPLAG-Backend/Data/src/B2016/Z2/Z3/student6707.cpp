/*B 16/17, Zadaća 2, Zadatak 3
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba
*/

#include <iostream>
#include <vector>
#include <deque>
#include <iterator>
#include <algorithm>
#include<iomanip>
int SumaDjelilaca( long long int x)
{
	int suma=0;
	if(x<0) x=(-1)*x;
	for(int i=1; i<=x; i++)
	{
		if(x%i==0) suma+=i;
	}
	return suma;
}

int SumaCifara( long long int x)
{
	int suma=0;
	while(x!=0)
	{
		suma+=x%10;
		x=x/10;
	}
	return suma;
}

bool DaLiJeProst(long long int x)
{
	bool provjera=true;
	for(int i=2; i<x; i++)
	{
		if(x%i==0) provjera=false;
	}
	
	return provjera;
}
int BrojProstihFaktora(long long int x)
{
	int suma=0;
	
	for(int i=2;i<=x; i++)
		{
			while(x%i==0)
			{
				if(DaLiJeProst(i)) 
				{
					suma++;
				x=x/i;
				}
			}
			
		}
		
	return suma;
}
bool DaLiJeSavrsen(long long int x)
{
	int suma=0;
	for(int i=1; i<x; i++)
	{
		if(x%i==0) suma+=i;
	}
	if(suma==x) return true;
	else return false;
	
}
int BrojSavrsenihDjelilaca (long long int x)
{
	int broj=0;
	for(int i=2; i<=x; i++)
	{
		if(x%i==0) 
		{
			if(DaLiJeSavrsen(i)) broj++;
		}
	}
	return broj;
}
template<typename Tip1, typename Tip2,typename Tip3, typename Tip4>
auto UvrnutiPresjek(Tip1 it1, Tip1 it2, Tip2 it3, Tip2 it4, Tip3 f(Tip4 ) ) -> std::vector<std::vector<decltype((*it3)+0)>> 
{
	auto pomocni=it3;
	
	std::vector<std::vector<decltype((*it3)+0)>> matrica; 
	
	int prov=1;
	int brojac=0;
	while(it1<it2)
	{
		
		while(it3<it4)
		{
			if(f(*it1)==f(*it3))
			{
				
			 	matrica.resize(brojac+1);
			 	matrica[brojac].resize(1);
			 	matrica[brojac][0]=*it1;
				matrica[brojac].push_back(*it3);
				matrica[brojac].push_back(f(*it3));
				brojac++;
			 
			 }
		prov=1;
		
		it3++;	
		}
		it3=pomocni;
		it1++;
		
	}
	std::sort(matrica.begin(), matrica.end(), []  (std::vector<decltype((*it3)+0)> x, std::vector<decltype((*it3)+0)> y)-> bool { if(x[2]<y[2]) return true; else if(x[2]==y[2] && x[0]<y[0]) return true;	else if(x[2]==y[2] && x[0]==y[0] && x[1]<y[1]) return true; else return false;});
	return matrica;
}
template<typename Tip1, typename Tip2>
auto UvrnutiPresjek(Tip1 it1, Tip1 it2, Tip2 it3, Tip2 it4 ) -> std::vector<std::vector<decltype((*it3)+0)>> 
{
	auto pomocni=it3;
	
	std::vector<std::vector<decltype((*it3)+0)>> matrica; 
	
	int prov=0;
	int brojac=0;
	while(it1<it2)
	{
		
		while(it3<it4)
		{
			if(*it1==*it3)
			{
				for(int i=0; i<brojac; i++)
					{
						if(matrica[i][0]==*it1) prov=1;
					}
			 if(prov==0) 
			 {
			 	matrica.resize(brojac+1);
			 	matrica[brojac].resize(1);
			 	matrica[brojac][0]=*it1;
			 	brojac++;
			 }
			 }
		prov=0;
		
		it3++;	
		}
		it3=pomocni;
		it1++;
		
	}
	for(int i=0; i<matrica.size(); i++)
	{
		matrica[i].push_back(0);
		matrica[i].push_back(0);
	}
	
	std::sort(matrica.begin(), matrica.end(), []  (std::vector<decltype((*it3)+0)> x, std::vector<decltype((*it3)+0)> y)->bool { if(x[0]<y[0]) return true; else return false;});	
	
	return matrica;
}

template<typename Tip1, typename Tip2,typename Tip3, typename Tip4>
auto UvrnutaRazlika(Tip1 it1, Tip1 it2, Tip2 it3, Tip2 it4, Tip3 f(Tip4 ) ) -> std::vector<std::vector<decltype((*it3)+0)>> 
{
	auto pomocni=it3;
	auto pomocni2=it1;
	
	std::vector<std::vector<decltype((*it3)+0)>> matrica; 
	

	int brojac=0;
	int brojac2=0;
	while(it1<it2)
	{
		
		while(it3<it4)
		{
			if(f(*it1)==f(*it3))
			{
				brojac2++;
			}	
			 it3++;
			 }
			 
		if(brojac2==0) 
			 {
			 	matrica.resize(brojac+1);
			 	matrica[brojac].resize(1);
			 	matrica[brojac][0]=*it1;
				matrica[brojac].push_back(f(*it1));
				brojac++;
			 }	 
		brojac2=0;
		it3=pomocni;
		it1++;
		
	}
	brojac2=0;
	it1=pomocni2;
		while(it3<it4)
	{
		
		while(it1<it2)
		{
			if(f(*it3)==f(*it1))
			{
				brojac2++;
			}	
			 it1++;
			 }
			 
		if(brojac2==0) 
			 {
			 	matrica.resize(brojac+1);
			 	matrica[brojac].resize(1);
			 	matrica[brojac][0]=*it3;
				matrica[brojac].push_back(f(*it3));
				brojac++;
			 }	 
		brojac2=0;
		it1=pomocni2;
		it3++;
		
	}
	std::sort(matrica.begin(), matrica.end(), []  (std::vector<decltype((*it3)+0)> x, std::vector<decltype((*it3)+0)> y)->bool { if(x[0]>y[0]) return true; else if(x[0]==y[0] && x[1]>y[1]) return true; else return false;});
	
	return matrica;
}
template<typename Tip1, typename Tip2>
auto UvrnutaRazlika(Tip1 it1, Tip1 it2, Tip2 it3, Tip2 it4 ) -> std::vector<std::vector<decltype((*it3)+0)>> 
{
	auto pomocni=it3;
	auto pomocni2=it1;
	
	std::vector<std::vector<decltype((*it3)+0)>> matrica; 
	
	int prov=0;
	int brojac=0;
	while(it1<it2)
	{
		
		while(it3<it4)
		{
			if(*it1==*it3)
			{
				prov=1;
			}
				it3++;
		}
			 if(prov==0) 
			 {
			 	matrica.resize(brojac+1);
			 	matrica[brojac].resize(1);
			 	matrica[brojac][0]=*it1;
			 	brojac++;
			 }
			 
		prov=0;
		
		it3=pomocni;
		it1++;
		
	}
	
	it3=pomocni;
	it1=pomocni2;
	while(it3<it4)
	{
		
		while(it1<it2)
		{
			if(*it3==*it1)
			{
				prov=1;
			}
				it1++;
		}
			 if(prov==0) 
			 {
			 	matrica.resize(brojac+1);
			 	matrica[brojac].resize(1);
			 	matrica[brojac][0]=*it3;
			 	brojac++;
			 }
			 
		prov=0;
		
		it1=pomocni2;
		it3++;
		
	}
	for(int i=0; i<matrica.size(); i++)
	{
		matrica[i].push_back(0);
	}
	
std::sort(matrica.begin(), matrica.end(), []  (std::vector<decltype((*it3)+0)> x, std::vector<decltype((*it3)+0)> y)->bool { if(x[0]>y[0]) return true; else return false;});	
	return matrica;
}

template<typename NekiTip>
void IspisiMatricu(NekiTip matrica)
{
	for(int i=0; i<matrica.size(); i++)
	{
		for(int j=0; j<matrica[0].size(); j++)
		{
			std::cout<<std::right<<std::setw(6) << matrica[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
}
int main ()
{
	int n,n2;
	std::cout<<"Unesite broj elemenata prvog kontejnera: ";
	std::cin>>n;
	std::deque<int> s1,s2;
	std::cout<<"Unesite elemente prvog kontejnera: ";
	int a;
	for(;;)
	{
		int prov=0;
		std::cin>>a;
		for(int j=0; j<s1.size(); j++)
		{
			if(a==s1[j]) prov=1;
		}
		if(prov==0) s1.push_back(a);
		if(s1.size()==n) break;
	}
	std::cout<<"Unesite broj elemenata drugog kontejnera: ";
	std::cin>>n2;
	int b;
	std::cout<<"Unesite elemente drugog kontejnera: ";
	for(;;)
	{
		int prov=0;
		std::cin>>b;
		for(int j=0; j<s2.size(); j++)
		{
			if(b==s2[j]) prov=1;
		}
		if(prov==0) s2.push_back(b);
		if(s2.size()==n2) break;
	}
	
	std::cout<<"Uvrnuti presjek kontejnera:" <<std::endl;
	auto matrica2 = UvrnutiPresjek(s1.begin(), s1.end(), s2.begin(),s2.end(), SumaCifara);
	IspisiMatricu(matrica2);
	
	std::cout<<"Uvrnuta razlika kontejnera:" <<std::endl;
	auto matrica = UvrnutaRazlika(s1.begin(), s1.end(), s2.begin(),s2.end(), BrojProstihFaktora);
	IspisiMatricu(matrica);
	std::cout<<"Dovidjenja!";
	std::cout<<std::endl;
	return 0;
}