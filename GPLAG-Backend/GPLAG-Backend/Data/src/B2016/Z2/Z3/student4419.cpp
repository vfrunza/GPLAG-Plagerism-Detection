/*B 16/17, Zadaća 2, Zadatak 3
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba
	
*/
#include <iostream>
#include <deque>
#include <iomanip>
#include <algorithm>
#include <vector> 

int sumaCifara (long long int n) 
{
	int suma(0);
	while(n!=0)
	{
		int cifra=n%10;
		suma+=cifra;
		n/=10;
	}
	return suma;
}

int SumaDjelilaca (long long int n)
{
	if(n<0) n=(-1)*n;
	int suma(0);
	for(int i=1; i<=n; i++)
	{
		if(n%i==0) suma+=i;
	}
	return suma;
}

int BrojProstihFaktora(long long int n)
{
	bool prost(1);
	int brojac(0);
	for(int i=2; i<=n; i++)
 {
		if(i==2) prost=1;
		for(int j=3; j<i; j++) 
		{
			if(i%j==0) prost=0;
		}
		
		while(n%i==0)
		{
			if(prost==1) 
			{
				brojac++;
				n=n/i;
		    }
	    }
	    prost=1;
 }
 return brojac;
}

int BrojSavrsenihDjelilaca(long long int n)
{
	int brojac(0);
	for(int i=3; i<=n; i++)
	{
		if(n%i==0)
		{
			int suma(0);
			for(int j=1; j<i; j++)
			{
				if(i%j==0) suma+=j;
			}
			if(i==suma) brojac++;
		}
	}
	return brojac;
}

template <typename NekiTip1, typename NekiTip2, typename NekiTip3, typename NekiTip4>
auto UvrnutiPresjek(NekiTip1 it1, NekiTip1 it2, NekiTip2 it3, NekiTip2 it4, NekiTip3 funkcija(NekiTip4)) -> std::vector<std::vector<decltype((*it3)+0)>>
{
	std::vector<std::vector<decltype((*it3)+0)>> matrica(100);
	int brojac(0);
	auto pomocna=it3;
	int i(0);
	
	while(it1!=it2)
	{
		if(funkcija(*it1)==funkcija(*it3)) 
		{
			matrica[i].push_back(*it1);
			matrica[i].push_back(*it3);
			matrica[i].push_back(funkcija(*it1));
			i++;
			brojac++;
		}
		
		if(it3!=it4) it3++;
		if(it3==it4)
		{
			it1++;
			it3=pomocna;
		}
	}
	
	matrica.resize(brojac);
	
	std::sort(matrica.begin(), matrica.end(), [] (std::vector<decltype((*it3)+0)> v1, std::vector<decltype((*it3)+0)> v2) -> bool 
	{
		if(v1.at(2)<v2.at(2)) return true;
		else if(v1.at(0)<v2.at(0) && v1.at(2)==v2.at(2)) return true;
		else if(v1.at(2)==v2.at(2) && v1.at(0)==v2.at(0) && v1.at(1)<v2.at(1)) return true;
		
		return false;
	});

     return matrica;
}

template <typename NekiTip1, typename NekiTip2>
auto UvrnutiPresjek (NekiTip1 it1, NekiTip1 it2, NekiTip2 it3, NekiTip2 it4) -> std::vector<std::vector<decltype((*it3)+0)>> {
	std::vector<std::vector<decltype((*it3)+0)>> matrica(100);
	
	int brojac(0);
	int i(0);
	auto pomocna=it3;
	
	while(it1!=it2)
	{
		while(it3!=it4)
		{
			if(*it1==*it3)
			{
				matrica[i].push_back(*it1);
				matrica[i].push_back(0);
				matrica[i].push_back(0);
				i++;
				brojac++;
			}
			it3++;
			
		}
		it3=pomocna;
		it1++;
	}
	matrica.resize(brojac);
	return matrica;
}

template <typename NekiTip1, typename NekiTip2, typename NekiTip3, typename NekiTip4>
auto UvrnutaRazlika(NekiTip1 it1, NekiTip1 it2, NekiTip2 it3, NekiTip2 it4, NekiTip3 funkcija(NekiTip4)) -> std::vector<std::vector<decltype((*it3)+0)>>
{
	std::vector<std::vector<decltype((*it3)+0)>> matrica(100);
	int brojac(0);
	int i(0);
	auto pomocna=it3;
	auto pomocna2=it1;
	
	while(it1!=it2)
	{
		int isti(0);
		
		while(it3!=it4)
		{
			if(funkcija(*it1)==funkcija(*it3)) isti++;
			it3++;
		}
		if(isti==0)
		{
			matrica[i].push_back(*it1);
			matrica[i].push_back(funkcija(*it1));
			brojac++;
			i++;
		}
		it1++;
		it3=pomocna;
	}
	it1=pomocna2;
	it3=pomocna;
	
	while(it3!=it4)
	{
		int isti(0);
		
		while(it1!=it2)
		{
			if(funkcija(*it3)==funkcija(*it1)) isti++;
			it1++;
		}
		if(isti==0)
		{
			matrica[i].push_back(*it3);
			matrica[i].push_back(funkcija(*it3));
			brojac++;
			i++;
		}
		it3++;
		it1=pomocna2;
	}
	matrica.resize(brojac);
	std::sort(matrica.begin(), matrica.end(), [] (std::vector<decltype((*it3)+0)>v1, std::vector<decltype((*it3)+0)>v2) -> bool {
		if(v1.at(0)>v2.at(0)) return true;
		else if(v1.at(1)>v2.at(1) && v1.at(0)==v2.at(0)) return true;
		
		return false;
	});
	return matrica;
}

template <typename NekiTip1, typename NekiTip2>

auto UvrnutaRazlika(NekiTip1 it1, NekiTip1 it2, NekiTip2 it3, NekiTip2 it4) -> std::vector<std::vector<decltype((*it3)+0)>> {
	std::vector<std::vector<decltype((*it3)+0)>> matrica(100);
	int brojac(0);
	int i(0);
	auto pomocna=it3;
	auto pomocna2=it1;
	
	while(it1!=it2)
	{
		int isti(0);
		
		while(it3!=it4)
		{
			if(*it1==*it3) isti++;
			it3++;
		}
		if(isti==0)
		{
			matrica[i].push_back(*it1);
			matrica[i].push_back(0);
			brojac++;
			i++;
		}
		it1++;
		it3=pomocna;
	}
	it1=pomocna2;
	it3=pomocna;
	
	while(it3!=it4)
	{
		int isti(0);
		
		while(it1!=it2)
		{
			if(*it3==*it1) isti++;
			it1++;
		}
		if(isti==0)
		{
			matrica[i].push_back(*it3);
			matrica[i].push_back(0);
			brojac++;
			i++;
		}
		it3++;
		it1=pomocna2;
	}
	matrica.resize(brojac);
	std::sort(matrica.begin(), matrica.end(), [] (std::vector<decltype((*it3)+0)>v1, std::vector<decltype((*it3)+0)>v2) -> bool {
		if(v1.at(0)>v2.at(0)) return true;
		else if(v1.at(1)>v2.at(1) && v1.at(0)==v2.at(0)) return true;
		
		return false;
	});
	return matrica;
}
		

int main ()
{
	std::deque<int> v;
	std::deque<int> v1;
	
	int n,n1,br,br1;
	
	std::cout<<"Unesite broj elemenata prvog kontejnera: ";
	std::cin>>br;
	std::cout << "Unesite elemente prvog kontejnera: ";
	for(;;)
	{
		std::cin>>n;
		int isti(0);
		for(int j=0; j<v.size(); j++)
		{
			if(n==v[j]) isti++;
		}
		if(isti==0) v.push_back(n);
		if(v.size()==br) break;
	}
	
	std::cout << "Unesite broj elemenata drugog kontejnera: ";
	std::cin>>br1;
	std::cout << "Unesite elemente drugog kontejnera: ";
	for(;;)
	{
		std::cin>>n1;
		int isti(0);
		for(int j=0; j<v1.size(); j++)
		{
			if(n1==v1[j]) isti++;
		}
		if(isti==0) v1.push_back(n1);
		if(v1.size()==br1) break;
	}
	
	std::cout << "Uvrnuti presjek kontejnera:" << std::endl;
	
	auto rez=UvrnutiPresjek(v.begin(), v.end(), v1.begin(), v1.end(), sumaCifara);
	auto rez2=UvrnutaRazlika(v.begin(), v.end(), v1.begin(), v1.end(), BrojProstihFaktora);
	
	for(int i=0; i<rez.size(); i++)
	{
		for(int j=0; j<rez[0].size(); j++)
		{
			std::cout << std::right <<std::setw(6)<<rez[i][j]<<" "; 
		}
		std::cout<< std::endl;
	}
	
	std::cout << "Uvrnuta razlika kontejnera:" << std::endl;
	
	for(int i=0; i<rez2.size(); i++)
	{
		for(int j=0; j<rez2[0].size(); j++)
		{
			std::cout << std::right <<std::setw(6)<<rez2[i][j]<<" ";
		}
		
		std::cout<< std::endl;
	}
	
	std::cout << "Dovidjenja!";
	
	return 0;
}