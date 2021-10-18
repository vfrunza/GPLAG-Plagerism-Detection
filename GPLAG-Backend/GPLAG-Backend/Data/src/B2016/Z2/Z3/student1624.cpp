#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
using namespace::std;

bool JeProst(long long int a)
{
	for(long long int i = 2; i < i/2 + 1; i++)
	{
		if(a%i == 0)
			return false;
	}
	return true;
}

int SumaCifara(long long int a)
{
	long long int suma(0);
	while(a > 0)
	{
		suma = suma+a%10;
		a = a/10;
	}
	return suma;
	
}
int SumaDjelilaca(long long int b)
{
	unsigned long long int a;
	if(b < 0)
		a = -b;
	else
		a = b;
	int suma(0);
	long long int temp(a);
	
	while(temp > 0)
	{
		if(a/(double)temp == int(a/(double)temp))
		{
			suma = suma + temp;
		}
		temp--;
	}
	return suma;
}
int BrojProstihFaktora(long long int n)
{
    int brojac(0);
	for(long long int i = 2; i <= n;i++)
	{
			while(n % i == 0)
			{
				brojac++;
				n = n / i;
			}
	}
	return brojac;
}
int BrojSavrsenihDjelilaca(long long int a)
{
	int brojac(0);
	auto temp(a);
	while(temp > 1)
	{
		if (a % temp == 0)
		{
			if(2*temp == SumaDjelilaca(temp))
				brojac++;
		}
		temp--;
	}
	return brojac;
}
template <typename Tip1,typename Tip2,typename Tip3>
auto UvrnutiPresjek(Tip1 it1,Tip1 it2, Tip2 it3, Tip2 it4,Tip3* fun) ->vector<vector<decltype((*it2)+0)>>
{
	typedef vector<vector<decltype((*it2) + 0)>> mat;
	mat matrica;
	typedef vector<decltype((*it2) + 0)> red;
	auto temp_it1(it1);
	auto temp_it3(it3);
	while(it1 < it2)
	{
		while(temp_it3 < it4)
		{
			if(fun(*temp_it3) == fun(*it1))
			{
				red temp(3);
				temp[0] = *it1;
				temp[1] = *temp_it3;
				temp[2] = fun(*it1);
				matrica.push_back(temp);
			}
			temp_it3++;
		}
		temp_it3 = it3;
		it1++;
	}
	sort(matrica.begin(),matrica.end(),[](red x,red y)
	{
		if(x[2] == y[2] && x[0] == y[0])
			return x[1] < y[1];
		if(x[2] == y[2])
			return x[0] < y[0];
		return x[2] < y[2];
	});
	return matrica;
}
template <typename Tip1,typename Tip2>
auto UvrnutiPresjek(Tip1 it1,Tip1 it2, Tip2 it3, Tip2 it4) ->vector<vector<decltype((*it2)+0)>>
{
	typedef vector<vector<decltype((*it2) + 0)>> mat;
	mat matrica;
	typedef vector<decltype((*it2) + 0)> red;
	auto temp_it3(it3);
	while(it1 < it2)
	{
		while(temp_it3 < it4)
		{
			if(*it1 == *temp_it3)
			matrica.push_back(red{*it1,0,0});
			temp_it3++;
		}
		temp_it3 = it3;
		it1++;
	}
	sort(matrica.begin(),matrica.end(),[](red x,red y)
	{
		if(x[2] == y[2] && x[0] == y[0])
			return x[1] < y[1];
		if(x[2] == y[2])
			return x[0] < y[0];
		return x[2] < y[2];
	});
	return matrica;
}

template <typename Tip1,typename Tip2,typename Tip3>
auto UvrnutaRazlika(Tip1 it1,Tip1 it2, Tip2 it3, Tip2 it4,Tip3* fun) ->vector<vector<decltype((*it2)+0)>>
{
	auto temp_it1(it1);
	auto temp_it3(it3);
	typedef vector<vector<decltype((*it2) + 0)>> mat;
	mat matrica;
	typedef vector<decltype((*it2) + 0)> red;

	bool ima_par(false);
	while(it1 < it2)
	{
		ima_par = false;
		while(temp_it3 < it4)
		{
			if(fun(*it1) == fun(*temp_it3))
			{
				ima_par = true;
				temp_it3++;
				break;
			}
			temp_it3++;
		}
		if(ima_par == false)
		{
			matrica.push_back(red{*it1,fun(*it1)});
		}
		temp_it3 = it3;
		it1++;
	}
	it1 = temp_it1;
	while(it3 < it4)
	{
		ima_par = false;
		while(temp_it1 < it2)
		{
			if(fun(*temp_it1) == fun(*it3))
			{
				ima_par = true;
				temp_it1++;
				break;
			}
			temp_it1++;
		}
		if(ima_par == false)
		{
			matrica.push_back(red{*it3,fun(*it3)});
		}
		temp_it1 = it1;
		it3++;
	}
	sort(matrica.begin(),matrica.end(),[](red x,red y) 
	{
		if(x[0] == y[0])
			return x[1] > y[1];
		return x[0] > y[0];
	});
	return matrica;
}
template <typename Tip1,typename Tip2>
auto UvrnutaRazlika(Tip1 it1,Tip1 it2, Tip2 it3, Tip2 it4) ->vector<vector<decltype((*it2)+0)>>
{
	typedef vector<vector<decltype((*it2) + 0)>> mat;
	mat matrica;
	typedef vector<decltype((*it2) + 0)> red;
	auto temp_it3(it3);
	auto temp_it1(it1);
	auto temp_it4(it4);
	auto temp_it2(it2);
	bool ima_par(false);
	while(it1 < it2)
	{
		ima_par = false;
		while(temp_it3 < it4)
		{
			if(*it1 == *temp_it3)
			{
				ima_par = true;
				break;
			}
			temp_it3++;
		}
		if(ima_par == false)
		matrica.push_back(red{*it1,0});
		temp_it3 = it3;
		it1++;
	}
	it1 = temp_it1;
	it1 = it3;
	it3 = temp_it1;
	it2 = it4;
	it4 = temp_it2;
	temp_it3 = it3;
	while(it1 < it2)
	{
		ima_par = false;
		while(temp_it3 < it4)
		{
			if(*it1 == *temp_it3)
			{
				ima_par = true;
				break;
			}
			temp_it3++;
		}
		if(ima_par == false)
		matrica.push_back(red{*it1,0});
		temp_it3 = it3;
		it1++;
	}
	sort(matrica.begin(),matrica.end(),[](red x,red y) 
	{
		if(x[0] == y[0])
			return x[1] > y[1];
		return x[0] > y[0];
	});
	return matrica;
	
}
int main()
{
	deque<int> a,b;
	int broj,element;
	cout << "Unesite broj elemenata prvog kontejnera: ";
	cin >> broj;
	cout << "Unesite elemente prvog kontejnera: ";
	cin >> element;
	a.push_back(element);
	bool ima(false);
	for(int i = 0; i < broj-1 && i < a.size();i++)
	{
		ima = false;
		cin >> element;
		for(auto temp : a)
		{
			if(element == temp)
			{
				ima = true;
				i--;
				break;
			}
		}
		if(!ima)
			a.push_back(element);
	}
	ima = false;
	cout << "Unesite broj elemenata drugog kontejnera: ";
	cin >> broj;
	cout << "Unesite elemente drugog kontejnera: ";
	cin >> element;
	b.push_back(element);
	ima = false;
	for(int i = 0; i < broj-1 && i < b.size();i++)
	{
		ima = false;
		cin >> element;
		for(auto temp : b)
		{
			if(element == temp)
			{
				ima = true;
				i--;
				break;
			}
		}
		if(!ima)
		{
			b.push_back(element);
		}
	}
	cout << "Uvrnuti presjek kontejnera:" << endl;
	auto kont = UvrnutiPresjek(a.begin(),a.end(),b.begin(),b.end(),SumaCifara);
	for(auto red: kont)
	{
		cout << setw(6);
		cout << red[0] << " ";
		cout << setw(6);
		cout << red[1] << " ";
		cout << setw(6);
		cout << red[2] << " " << endl;
	}
	kont = UvrnutaRazlika(a.begin(),a.end(),b.begin(),b.end(),BrojProstihFaktora);
	cout << "Uvrnuta razlika kontejnera:" << endl;
	for(auto red: kont)
	{
		cout << setw(6);
		cout << red[0] << " ";
		cout << setw(6);
		cout << red[1] << " " << endl;
	}
	cout << "Dovidjenja!";
	return 0;
}