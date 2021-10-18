/*B 2017/2018, Zadaća 2, Zadatak 4

	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!

	NAPOMENA: nece svi (javni) testovi sa zamgera biti
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za
	autotestove javiti se na forum (c2).
*/
#include <iostream>
#include <cctype>
#include <vector>
#include <deque>
#include <algorithm>
#include <iomanip>

bool is_prost(int x)
{
	if(x<0)x=-x;
	if(x<2)return false;
	for(int i=2; i<=x/i; i++)
	{
		if(x%i==0)return false;
	}
	return true;
}
bool po_prostim_faktorima(int x, int y)
{
	int br_x(0),br_y(0);
	for(int i=2; i<std::abs(x); i++)
	{
		if(x%i==0 && is_prost(i))
		{
			br_x++;
			int temp(x/i);
			while(temp%i==0)
			{
				temp/=i;
				br_x++;
			}
		}
	}
	for(int i=2; i<std::abs(y); i++)
		if(y%i==0 && is_prost(i))
		{
			br_y++;
			int temp(y/i);
			while(temp%i==0)
			{
				temp/=i;
				br_y++;
			}
		}

	if (br_y==br_x)return x>y;
	else return br_x>br_y;
}
int f(int x, int y)
{
	return (-2*x+y);
}

template <typename itertip1 ,typename itertip2, typename itertip3>
void SortirajPodrucjeVrijednosti(
    itertip1 pocetak,	itertip1 kraj, 	itertip2 poc2,	itertip3 poc3,
    decltype(*poc3+*poc3) funkcija( decltype(*pocetak+*pocetak) x,decltype(*pocetak+*pocetak) y),
    bool krit( decltype(*pocetak+*pocetak) x,decltype(*pocetak+*pocetak) y)
)
{
	std::sort(pocetak,kraj,krit);
	itertip1 test(pocetak);
	itertip2 test2(poc2);
	itertip3 kraj3(poc3);
	while(test!=kraj)
	{
		test++;
		test2++;
		kraj3++;
		
	}
	std::sort(poc2,test2,krit);
	test=pocetak;
	itertip2 klizac2(poc2);
	itertip3 klizac3(poc3),temp;
	decltype(+*klizac3) var3;

	for(; test!=kraj; test++,klizac2++,klizac3++)
	{
		
		
		
		for(temp=poc3;temp!=kraj3;temp++)
		{
			if(*temp==funkcija(*test,*klizac2))break;
		    if(temp+1==kraj3)throw std::logic_error("Vrijednost koja odgovara nekom od parova nije nadjena");
		}
			var3=*klizac3;
			*klizac3 = *temp ;
			*temp = var3;
	}

	return ;
}

int main ()
{
	std::cout<<"Unesite broj elemenata: ";
	int n;
	std::cin>>n;
	std::cout<<"Unesite elemente prvog vektora: ";
	std::vector<int> prvi;
	for(int i=0,x; i<n; i++)
	{
		std::cin>>x;
		std::sort(prvi.begin(),prvi.end());
		if(std::binary_search(prvi.begin(),prvi.end(),x))
		{
			i--;
		}
		else
		{
			prvi.push_back(x);
		}
	}
	std::vector<int> drugi;
	std::cout<<"Unesite elemente drugog vektora: ";
	for(int i=0,x; i<n; i++)
	{
		std::cin>>x;
		std::sort(drugi.begin(),drugi.end());
		if(std::binary_search(drugi.begin(),drugi.end(),x))
		{
			i--;
		}
		else
		{
			drugi.push_back(x);
		}
	}
	std::vector<int> treci;
	std::cout<<"Unesite elemente treceg vektora: ";
	for(int i=0,x; i<n; i++)
	{
		std::cin>>x;
		std::sort(treci.begin(),treci.end());
		if(std::binary_search(treci.begin(),treci.end(),x))
		{
			i--;
		}
		else
		{
			treci.push_back(x);
		}
	}
	try
	{
		SortirajPodrucjeVrijednosti(prvi.begin(),prvi.end(),drugi.begin(),treci.begin(),f,po_prostim_faktorima);
		std::cout<<"\nNakon sortiranja podrucja vrijednosti imamo sljedece trojke: \n";
		for(int i=0; i<n; i++)
		{
			std::cout<<"f("<<prvi.at(i)<<", "<<drugi.at(i)<<") = "<<treci.at(i)<<std::endl;
		}
	}
	catch(std::logic_error izuzetak)
	{
		std::cout<<"\nIzuzetak: "<<izuzetak.what();
	}
	return 0;
}