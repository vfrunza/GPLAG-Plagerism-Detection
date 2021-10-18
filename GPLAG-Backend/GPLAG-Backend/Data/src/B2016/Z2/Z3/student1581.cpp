/*B 16/17, Zadaća 2, Zadatak 3
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba
	
*/
#include <iostream>
#include <deque>
#include <iomanip>
std::deque<std::deque<int>>KreitajMatricu(int broj_redova, int broj_kolona)
{
	return std::deque<std::deque<int>>(broj_redova, std::deque<int>(broj_kolona));
}


template <typename tip>
tip SumaCifara(tip x)
{
	tip suma(0);
	tip cifra;
	while(x!=0)
	{
	cifra=x%10;
	suma+=cifra;
	}
	return suma;
	
}
template <typename tip1, typename tip2,typename tip,typename tip3>
std::deque<std::deque<int>> UvrnutiPresjek(tip1 poc1, tip1 kraj1, tip2 poc2, tip2 kraj2, tip f(tip x))//ispraviti
{
	//tip3<tip3<tip>> m;
	int n(0),d(0);
	/*while(poc1!=kraj1)
	n++;
	while(poc2!=kraj2)
	d++*/
	std::deque<int>v ;//ispraviti
	for(auto i=poc1;i<kraj1;i++)
	{
		for(auto j=poc2;j<kraj2;j++)
		{
			if(f(*i)==f(*j))
			 {
			 	while(f(*i)==f(*j) && (i<kraj1 || j<kraj2))
			 	{
			 		v.push_back(*j);
			 		j++;
			 	}
			 }
			 	v.push_back(*i);
			 	v.push_back(f(*i));
			 	int n(v.size());
			 	auto m(KreitajMatricu(n,3));
			 	m.push_back(v);
			 	v.resize(0);
		}
	}
	return m;
}

int main ()
{
	std::deque<int> a;
	std::deque<int> b;
	int n,d;
	int element1,element2;
	std::cout << "Unesite elemente prvog kontejnera:";
	std::cin>>n;
	for(int i=0;i<n;i++)
	{
		std::cin>>element1;
		a.push_back(element1);
	}
	std::cout << "Unesite elemente drugog kontejnera: ";
	std::cin>>d;
	for(int i=0;i<d;i++)
	{
		std::cin>>element2;
		b.push_back(element2);
	}
	auto m(UvrnutiPresjek(a.begin(),a.end(),b.begin(),b.end(),SumaCifara));
	for(int i=0;i<m.size();i++)
	{
		for(int j=0;j<m[i].size();j++)
		{
			std::cout <<std::setw(6) <<m[i][j];
		}
		std::cout <<std::endl;
	}
	return 0;
}