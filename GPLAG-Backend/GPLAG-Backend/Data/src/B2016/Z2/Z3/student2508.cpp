/*B 16/17, Zadaća 2, Zadatak 3
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba
	
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <iomanip>
#include <cmath>
template <typename Poktip1, typename Poktip2, typename Funktip1, typename Funktip2>

auto UvrnutiPresjek(Poktip1 p1, Poktip1 k1, Poktip2 p2, Poktip2 k2, Funktip1 f(Funktip2)) -> std::vector<std::vector<decltype(*p1+0)>>
{
	std::vector<decltype(*p1+0)> skup1,skup2;
	std::vector<std::vector<decltype(*p1+0)>> mat;
	while(p1!=k1)
	{
		skup1.push_back(*p1);
		p1++;
	}
	while(p2!=k2)
	{
		skup2.push_back(*p2);
		p2++;
	}
	for(decltype(skup1[0]) x: skup1)
	{
		for(decltype(skup2[0]) y: skup2)
		{
			if(f(x)==f(y))
			{
				std::vector<decltype(*p1+0)> pom {x,y,f(x)};
				mat.push_back(pom);
			}
		}
	}
	typename decltype(mat)::iterator it1(mat.begin());
	std::sort(it1,it1+mat.size(),[](decltype(skup1) v1, decltype(skup1) v2){
		if(v1[2]!=v2[2])
			return v1[2]<v2[2];
		else if(v1[0]!=v2[0])
			return v1[0]<v2[0];
		else return v1[1]<v2[1];
	} );
	
	return mat;
}

template <typename Poktip1, typename Poktip2>

auto UvrnutiPresjek(Poktip1 p1, Poktip1 k1, Poktip2 p2, Poktip2 k2) -> std::vector<std::vector<decltype(*p1+0)>>
{
	std::vector<decltype(*p1+0)> skup1,skup2;
	std::vector<std::vector<decltype(*p1+0)>> mat;
	while(p1!=k1)
	{
		skup1.push_back(*p1);
		p1++;
	}
	while(p2!=k2)
	{
		skup2.push_back(*p2);
		p2++;
	}
	for(decltype(skup1[0]) x: skup1)
	{
		for(decltype(skup2[0]) y: skup2)
		{
			if(x==y)
			{
				std::vector<decltype(*p1+0)> pom {x,0,0};
				mat.push_back(pom);
			}
		}
	}
	
	typename decltype(mat)::iterator it1(mat.begin());
	std::sort(it1,it1+mat.size(),[](decltype(skup1) v1, decltype(skup1) v2){ return v1[0]<v2[0];} );
	
	return mat;
} 

template <typename Poktip1, typename Poktip2>

auto UvrnutaRazlika(Poktip1 p1, Poktip1 k1, Poktip2 p2, Poktip2 k2) -> std::vector<std::vector<decltype(*p1+0)>>
{
	std::vector<decltype(*p1+0)> skup1,skup2;
	std::vector<std::vector<decltype(*p1+0)>> mat;
	while(p1!=k1)
	{
		skup1.push_back(*p1);
		p1++;
	}
	while(p2!=k2)
	{
		skup2.push_back(*p2);
		p2++;
	}
	for(decltype(skup2[0]) x: skup2)
	{
		bool ImaGa(false);
		for(decltype(skup1[0]) y: skup1)
		{
			if(x==y)
			{
				ImaGa=true;
				break;
			}
		}
			if(ImaGa==false)
			{
				std::vector<decltype(*p1+0)> pom {x,0};
				mat.push_back(pom);
			}
	}
	for(decltype(skup1[0]) x: skup1)
	{
		bool ImaGa(false);
		for(decltype(skup2[0]) y: skup2)
		{
			if(x==y)
			{
				ImaGa=true;
				break;
			}
		}
			if(ImaGa==false)
			{
				std::vector<decltype(*p1+0)> pom {x,0};
				mat.push_back(pom);
			}
	}
	
	typename decltype(mat)::iterator it1(mat.begin());
	std::sort(it1,it1+mat.size(),[](decltype(skup1) v1, decltype(skup1) v2){ return v1[0]>v2[0];} );
	
	return mat;
} 

template <typename Poktip1, typename Poktip2, typename Funktip1, typename Funktip2>

auto UvrnutaRazlika(Poktip1 p1, Poktip1 k1, Poktip2 p2, Poktip2 k2, Funktip1 f(Funktip2)) -> std::vector<std::vector<decltype(*p1+0)>>
{
	std::vector<decltype(*p1+0)> skup1,skup2;
	std::vector<std::vector<decltype(*p1+0)>> mat;
	while(p1!=k1)
	{
		skup1.push_back(*p1);
		p1++;
	}
	while(p2!=k2)
	{
		skup2.push_back(*p2);
		p2++;
	}
	for(int i(0);i<skup1.size();i++)
	{	bool NemaPar(true);
		for(int j(0);j<skup2.size();j++)
		{
			if(f(skup1[i])==f(skup2[j]))
			{
				NemaPar=false;
				break;
			}
			
		}
		if(NemaPar)
		{
			std::vector<decltype(*p1+0)> pom{skup1[i],f(skup1[i])};
			mat.push_back(pom);
		}
	}
	
	for(int i(0);i<skup2.size();i++)
	{	bool NemaPar(true);
		for(int j(0);j<skup1.size();j++)
		{
			if(f(skup2[i])==f(skup1[j]))
			{
				NemaPar=false;
				break;
			}
			
		}
		if(NemaPar)
		{
			std::vector<decltype(*p1+0)> pom{skup2[i],f(skup2[i])};
			mat.push_back(pom);
		}
	}
	
	typename decltype(mat)::iterator it1(mat.begin());
	std::sort(it1,it1+mat.size(),[](decltype(skup1) v1, decltype(skup1) v2){
		if(v1[0]!=v2[0]) return v1[0]>v2[0];
		else return v1[1]>v2[1];
	} );
	
	return mat;
}

int SumaCifara(long long int n)
{
	int suma(0);
	while(n)
	{
		suma+=n%10;
		n/=10;
	}
	return suma;
}

int SumaDjelilaca(long long int n)
{
	int suma{};
	for(int i(1);i<=n;i++)
		if(n%i==0 && n%i>=0) suma+=i;
	return suma;
}

int BrojProstihFaktora(long long int n) //cifre se mogu ponavljati
{
	int brojac{0};
		for(int i(2);i<=n;i++)
			if(n%i==0)
			{
				brojac++;
				n/=i;
				i=1;
			}
		return brojac;
}

int SumaDjelilaca2(long long int n)
{
	int suma{};
	for(int i(1);i<n;i++)
		if(n%i==0) suma+=i;
	return suma;
}

int BrojSavrsenihDjelilaca(long long int n)
{
	int brojac{};
	for(int i(1);i<=n;i++)
		if(n%i==0 && SumaDjelilaca2(i)==i) brojac++;
	return brojac;
}
int main ()
{
	std::cout<<"Unesite broj elemenata prvog kontejnera: ";
	int n,m;
	std::cin>>n;
	std::deque<int> d1;
	std::cout<<"Unesite elemente prvog kontejnera: ";
	for(int i(0);i<n;i++)
	{
		int x;
		std::cin>>x;
		bool ponavljanje(false);
		for(int j(0);j<d1.size();j++)
		{
			if(d1[j]==x)
			{
				ponavljanje=true;
				i--;
				break;
			}
		}
		if(ponavljanje==false)
				d1.push_back(x);
		
	}
	std::cout<<"Unesite broj elemenata drugog kontejnera: ";
	std::cin>>m;
	std::deque<int> d2;
	std::cout<<"Unesite elemente drugog kontejnera: ";
	for(int i(0);i<m;i++)
	{
		int x;
		std::cin>>x;
		bool ponavljanje(false);
		for(int j(0);j<d2.size();j++)
		{
			if(d2[j]==x)
			{
				ponavljanje=true;
				i--;
				break;
			}

		}
		if(ponavljanje==false)
			d2.push_back(x);
	}
	std::deque<int>::iterator it1(d1.begin()),it2(d2.begin());
	std::vector<std::vector<int>> mat(UvrnutiPresjek(it1,it1+d1.size(),it2,it2+d2.size(),SumaCifara)),mat2(UvrnutaRazlika(it1,it1+d1.size(),it2,it2+d2.size(),BrojProstihFaktora));
	std::cout<<"Uvrnuti presjek kontejnera:"<<std::endl;
	for(int i(0);i<mat.size();i++)
	{
		for(int j(0);j<mat[i].size();j++) std::cout<<std::setw(6)<<mat[i][j]<<" ";
		std::cout<<" "<<std::endl;
	}
	std::cout<<"Uvrnuta razlika kontejnera:"<<std::endl;
	for(int i(0);i<mat2.size();i++)
	{
		for(int j(0);j<mat2[i].size();j++) std::cout<<std::setw(6)<<mat2[i][j]<<" ";
		std::cout<<std::endl;
	}
	std::cout<<"Dovidjenja!";
	return 0;
}