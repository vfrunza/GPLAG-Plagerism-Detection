/*B 16/17, Zadaća 2, Zadatak 3
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba
	
*/
#include <iostream>
#include <vector>
#include <algorithm>
using std::cin;
using std::cout;
template <typename tip,typename tip1,typename argtip>
std::vector<std::vector<double>>UvrnutiPresjek()(tip p,tip p1, tip1 q, tip1 q1, argtip f(argtip))
{
	std::vector<std::vector<>> matrix;
	std::vector<tip> v;
	for(tip i(p); i < p1; i++)
	{
		for(tip j(q); j < q1; j++)
		{
			if(f(i)==f(j))
			{
				v.push_back(i);
				v.push_back(j);
				v.push_back(f(i));
			}
			m.push_back(v);
			v.resize(0);
		}
	}
	std::sort(m.begin(),m.end(),[](tip x, tip y){
		if(x.at(2)!=y.at(2))
			return x.at(2)<y.at(2);
		else if(x.at(1)!=y.at(1))
			return x.at(1)<y.at(1);
		else return x.at(0)<y.at(0);
	});
	return m;
}
 
int main ()
{
	std::vector<int> v,v1;
	cout<<"Unesite broj elemenata prvog kontejnera: \n";
	int n;
	cin>>n;
	cout<<"Unesite elemente prvog kontejnera: \n";
	for(int i=0;i<n;i++)
	{
		int broj;
		cin>>broj;
		v.push_back(broj);
	}
	cout<<"Unesite broj elemente drugog kontejnera: \n";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int broj;
		cin>>broj;
		v1.push_back(broj);
	}
	auto x(UvrnutiPresjek(v.begin(),v.end(),v1.begin(),v1.end(),
			[](int x)));
	return 0;
}