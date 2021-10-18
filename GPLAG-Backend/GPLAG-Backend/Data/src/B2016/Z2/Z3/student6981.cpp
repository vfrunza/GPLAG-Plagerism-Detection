/*B 16/17, Zadaća 2, Zadatak 3
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba
	
*/

#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

template <typename Tip, IterTip1, IterTip2, Tip1, Tip2>

vector<vector<Tip>> UvrnutiPresjek(IterTip1 pocetak1, IterTip1 iza_kraja1, IterTip2 pocetak2, IterTip2 iza_kraja2, Tip1 funkcija(Tip2))
{
	vector<vector<Tip3>> v;
	int brojac(0);
	while(pocetak1!=iza_kraja1)
	{
		IterTip2 pomocna(pocetak2);
		while(pomocna!=iza_kraja2)
		{
			if(funkcija(*pocetak1)==funkcija(*pomocna))
			{
				v.resize(++brojac);
				v[brojac].push_back(*pocetak1);
				v[brojac].push_back(*pomocna);
				v[brojac].push_back(funkcija(*pocetak1));
			}
			pomocna++;
		}
		pocetak1++;
	}
	std::sort(v.begin(), v.end(), [](Tip v1, Tip v2){if(v1[3]!=v2[3]) return v1[3]<v2[3]; if(v1[1]!=v2[1]) return v1[1]<v2[1]; return v1[2]<v2[2];});
	
	return v;
}

template <typename Tip, IterTip1, IterTip2, Tip1, Tip2>

vector<vector<Tip>> UvrnutaRazlika(IterTip1 pocetak1, IterTip1 iza_kraja1, IterTip2 pocetak2, IterTip2 iza_kraja2, Tip1 funkcija(Tip2))
{
	vector<vector<Tip>> v;
	int brojac(0);
	IterTip1 pomocna1(pocetak1);
	IterTip2 pomocna2;
	while(pomocna1!=iza_kraja1)
	{
		bool ima(false);
		pomocna2=pocetak2;
		while(pomocna2!=iza_kraja2)
		{
			if(funkcija(*pomocna1)==funkcija(*pomocna2))
			{
				ima=true;
				break;
			}
			pomocna2++;
		}
		if(!ima)
		{
			v.resize(++brojac);
			v[brojac].push_back(*pomocna1);
			v[brojac].push_back(funkcija(*pomocna1));
		}
		pomocna1++;
	}
	pomocna2=pocetak2;
	while(pomocna2!=iza_kraja2)
	{
		bool ima(false);
		pomocna1=pocetak1;
		while(pomocna1!=iza_kraja1)
		{
			if(funkcija(*pomocna1)==funkcija(*pomocna2))
			{
				ima=true;
				break;
			}
			pomocna1++;
		}
		if(!ima)
		{
			v.resize(++brojac);
			v[brojac].push_back(*pomocna2);
			v[brojac].push_back(funkcija(*pomocna2));
		}
		pomocna2++;
	}
	std::sort(v.begin(), v.end(), [](Tip v1, Tip v2){if(v1[1]!=v2[1])return v1[1]>v2[1]; return v1[2]>v2[2]});
	
	return v;
}

int main ()
{
	return 0;
}