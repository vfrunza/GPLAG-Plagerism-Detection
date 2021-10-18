/*B 16/17, Zadaća 2, Zadatak 3
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba
	
*/
#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
#include <iomanip>
int SumaDjelilaca(long long int broj)
{
	int suma(0);
	for(int i=1; i<=broj; i++)
		if(broj%i==0) suma+=i;
	return suma;
}
bool ProstBroj(int broj)
{
	int brojac(0);
	for(int i=1; i<=broj; i++)
	{
		if(broj%i==0) brojac++;
	}
	if(brojac==2) return 1;
	else return 0;
}
int BrojProstihFaktora(long long int broj)
{
	int broj_prostih(0);
	for(int i=broj; i>=2; i--)
	{
		if(ProstBroj(i))
		{
			while(broj%i==0) 
			{
				broj_prostih++;
				broj/=i;
			}
		}
		
	}
	return broj_prostih;
}

int BrojSavrsenihDjelilaca(long long int broj)
{
	int broj_sav_djelilaca(0);
	for(int i=6; i<=broj; i++)
	{	//je li savrsen broj
		if(SumaDjelilaca(i)-i==i)		//jer je funkcija SumaDjelilaca napisana tako da u sumu sabira sve djelioce ukljucujuci i taj broj
		if(broj%i==0) broj_sav_djelilaca++;
	}
	return broj_sav_djelilaca;
}

int SumaCifara(int broj)
{
	int suma(0);
	while(broj!=0)
	{
		suma+=(broj%10);
		broj/=10;
	}
	return suma;
}

template <typename itertip1, typename itertip2, typename funtip>

std::vector<std::vector<int>>UvrnutiPresjek (itertip1 pocetak1, itertip1 kraj1, itertip2 pocetak2, itertip2 kraj2, funtip f)
{
	std::vector<std::vector<int>> v;
	int velicina(1);
	for(auto i=pocetak1; i!=kraj1; i++)
	{
		for(auto j=pocetak2; j!=kraj2; j++)
		{
			if(f(*i)==f(*j)) 
			{
				v.resize(velicina);
				v[velicina-1].push_back(*i); v[velicina-1].push_back(*j); v[velicina-1].push_back(f(*i));
				velicina++;
			}
		}
	}

	std::sort(v.begin(), v.end(),[](std::vector<int> x, std::vector<int> y) {if(x[2]!=y[2]) return x[2]<y[2];
		else if(x[0]!=y[0]) return x[0]<y[0];
		else return x[1]<y[1];
	});
	return v;
	
}
template <typename itertip1, typename itertip2>
std::vector<std::vector<int>>UvrnutiPresjek (itertip1 pocetak1, itertip1 kraj1, itertip2 pocetak2, itertip2 kraj2)
{
	std::vector<std::vector<int>> v;
	int velicina(1);
	for(auto i=pocetak1; i!=kraj1; i++)
	{
		for(auto j=pocetak2; j!=kraj2; j++)
		{
			if(*i==*j) 
			{
				v.resize(velicina);
				v[velicina-1].push_back(*i); v[velicina-1].push_back(0); v[velicina-1].push_back(0);
				velicina++;
			}
		}
	}

	std::sort(v.begin(), v.end());
	return v;
}

template <typename itertip1, typename itertip2, typename funtip>

std::vector<std::vector<int>>UvrnutaRazlika (itertip1 pocetak1, itertip1 kraj1, itertip2 pocetak2, itertip2 kraj2, funtip f)
{
	std::vector<std::vector<int>> v;
	int velicina(1);
	//prvi kontejner provjera ima li brojeva bez para i smjestanje u vektor
	for(auto i=pocetak1; i!=kraj1; i++)
	{
		bool ima_para(0);
		for(auto j=pocetak2; j!=kraj2; j++)
		{
			if(f(*i)==f(*j)) 
			ima_para=1;
		}
		if(!ima_para)
		{
			v.resize(velicina);
			v[velicina-1].push_back(*i); v[velicina-1].push_back(f(*i));
			velicina++;
		}
	}
	//drugi kontejner provjera ima li brojeva bez para i smjestanje u vektor
	for(auto j=pocetak2; j!=kraj2; j++)
	{
		bool ima_para(0);
		for(auto i=pocetak1; i!=kraj1; i++)
		{
			if(f(*i)==f(*j)) 
			ima_para=1;
		}
		if(!ima_para)
		{
			v.resize(velicina);
			v[velicina-1].push_back(*j); v[velicina-1].push_back(f(*j));
			velicina++;
		}
	}
	std::sort(v.begin(), v.end(),[](std::vector<int> x, std::vector<int> y) {if(x[0]!=y[0]) return x[0]>y[0];
		else return x[1]>y[1];
	});
	return v;
}

template <typename itertip1, typename itertip2>

std::vector<std::vector<int>>UvrnutaRazlika (itertip1 pocetak1, itertip1 kraj1, itertip2 pocetak2, itertip2 kraj2)
{
	std::vector<std::vector<int>> v;
	int velicina(1);
	//prvi kontejner provjera ima li brojeva bez para i smjestanje u vektor
	for(auto i=pocetak1; i!=kraj1; i++)
	{
		bool ima_para(0);
		for(auto j=pocetak2; j!=kraj2; j++)
		{
			if(*i==*j) 
			ima_para=1;
		}
		if(!ima_para)
		{
			v.resize(velicina);
			v[velicina-1].push_back(*i); v[velicina-1].push_back(0);
			velicina++;
		}
	}
	//drugi kontejner provjera ima li brojeva bez para i smjestanje u vektor
	for(auto j=pocetak2; j!=kraj2; j++)
	{
		bool ima_para(0);
		for(auto i=pocetak1; i!=kraj1; i++)
		{
			if(*i==*j) 
			ima_para=1;
		}
		if(!ima_para)
		{
			v.resize(velicina);
			v[velicina-1].push_back(*j); v[velicina-1].push_back(0);
			velicina++;
		}
	}
	std::sort(v.begin(), v.end(),[](std::vector<int> x, std::vector<int> y) {return x[0]>y[0];});
	return v;
}

int main ()
{
	std::cout<<"Unesite broj elemenata prvog kontejnera: ";
	int n1;
	std::cin>>n1;
	int element;
	std::cout<<"Unesite elemente prvog kontejnera: ";
	std::deque<int>d;
	while(d.size()<n1)
	{
		std::cin>>element; 
		bool ponavlja_se(0);
		for(int j=0; j<d.size(); j++)
		{
			if(d[j]==element) ponavlja_se=1;
		}
		if(ponavlja_se==0) d.push_back(element);
	}
	std::cin.clear();
	std::cin.ignore(1,'\n');
	std::cout<<"Unesite broj elemenata drugog kontejnera: ";
	int n2;
	std::cin>>n2;
	std::cout<<"Unesite elemente drugog kontejnera: ";
	std::deque<int>d2;
	while(d2.size()<n2)
	{
		std::cin>>element; 
		bool ponavlja_se(0);
		for(int j=0; j<d2.size(); j++)
		{
			if(d2[j]==element) ponavlja_se=1;
		}
		if(ponavlja_se==0) d2.push_back(element);
	}
	
	std::vector<std::vector<int>>v(UvrnutiPresjek(d.begin(), d.end(), d2.begin(), d2.end(),SumaCifara));
	std::cout<<"Uvrnuti presjek kontejnera:\n";
	for(int i=0; i<v.size(); i++)
	{
		for(int j=0; j<v[i].size(); j++)
		{
			std::cout<<std::setw(6)<<v[i][j]<<" ";
		}
		std::cout<<"\n";
	}
	
	std::vector<std::vector<int>>v2(UvrnutaRazlika(d.begin(), d.end(), d2.begin(), d2.end(),BrojProstihFaktora));
	std::cout<<"Uvrnuta razlika kontejnera:\n";
	for(int i=0; i<v2.size(); i++)
	{
		for(int j=0; j<v2[i].size(); j++)
		{
			std::cout<<std::setw(6)<<v2[i][j]<<" ";
		}
		std::cout<<"\n";
	}
	std::cout<<"Dovidjenja!";

	return 0;
}