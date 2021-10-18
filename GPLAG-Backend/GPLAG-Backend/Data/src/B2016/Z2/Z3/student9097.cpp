#include <iostream>
#include <deque>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>
int SumaDjelilaca (long long int a)
{
	int s(a);
	for (int i=1; i<=a/2; i++)
	{
		if(a%i==0)
		s+=i;
	}
	return s;
}

int BrojSavrsenihDjelilaca (long long int a)
{
	int s(0);
	for (int i=2; i<=a; i++)
	{
		int c=2*i;
		if(a%i==0&&(c==SumaDjelilaca(i)))
		{
			s++;
		}
	}
	return s;
}

bool prost(int a)
{
	for (int i=2; i<=sqrt(a); i++)
	{
		if(a%i==0)
		return 0;
	}
	return 1;
}

int BrojProstihFaktora (long long int a)
{
	int s(0);
	for (int i=2; i<=a; i++)
	{
		if(a%i==0&&prost(i))
		{
			int b(a);
			while(b%i==0&&b!=0)
			{
			
				b/=i;
				s++;
			}
		}
	}
	return s;
}

int SumaCifara (long long int a)
{
	int b, s(0);
	do{
		b=a%10;
		a/=10;
		s+=b;
	}while(a!=0);
	return s;
}
/*granica*/
template <typename Nekitip, typename Nekitip2>
auto UvrnutiPresjek(Nekitip a, Nekitip b, Nekitip2 c, Nekitip2 d) ->std::vector<std::vector<typename std::remove_reference<decltype(*a)>::type>>
{
	std::vector<std::vector<typename std::remove_reference<decltype(*a)>::type>> M;
	std::vector<typename std::remove_reference<decltype(*a)>::type> v;
	Nekitip pok(a);
	Nekitip2 pok2(c);
	int t(0);
	while (pok!=b)
	{
		while(pok2!=d)
		{
			if(*pok==*pok2&&t==0)
			{
				v.clear();
				v.push_back(*pok);
				v.push_back(0);
				M.push_back(v);
			}
			pok2++;
		}
		pok++;
		pok2=c;
	}
	std::sort(M.begin(), M.end(), [](std::vector<typename std::remove_reference<decltype(*a)>::type> v1, std::vector<typename std::remove_reference<decltype(*a)>::type> v2){if(v1[2]<v2[2]) return true; else if(v1[2]==v2[2]&&v1[0]<v2[0]) return true; else if(v1[0]==v2[0]&&v1[2]==v2[2]&&v1[1]<v2[1]) return true; else return false;});
	return M;
	
}
template <typename Nekitip, typename Nekitip2>
auto UvrnutaRazlika(Nekitip a, Nekitip b, Nekitip2 c, Nekitip2 d) ->std::vector<std::vector<typename std::remove_reference<decltype(*a)>::type>>
{
	std::vector<std::vector<typename std::remove_reference<decltype(*a)>::type>> M;
	std::vector<typename std::remove_reference<decltype(*a)>::type> v;
	Nekitip pok(a);
	Nekitip2 pok2(c);
	while (pok!=b)
	{
		bool ima=false;
		while(pok2!=d)
		{
			if(*pok==*pok2)
			{
				ima=1;
				break;
			}
			pok2++;
		}
		if(!ima)
		{
			v.clear();
			v.push_back(*pok);
			v.push_back(0);
			M.push_back(v);
		}
		pok++;
		pok2=c;
	}
	pok2=c;
	pok=a;
	while (pok2!=d)
	{
		bool ima=false;
		while(pok!=b)
		{
			if(*pok2==*pok)
			{
				ima=1;
				break;
			}
			pok++;
		}
		if(!ima)
		{
			v.clear();
			v.push_back(*pok2);
			v.push_back(0);
			M.push_back(v);
		}
		pok2++;
		pok=a;
	}
	std::sort(M.begin(), M.end(), [](std::vector<typename std::remove_reference<decltype(*a)>::type> v1, std::vector<typename std::remove_reference<decltype(*a)>::type> v2){if(v1[0]>v2[0])return true; else if(v1[0]==v2[0]&&v1[1]>v2[1]) return true; else return false;});
	return M;
}
/*granica*/
template <typename Nekitip, typename Nekitip2, typename Tip3, typename Tip4>
auto UvrnutiPresjek(Nekitip a, Nekitip b, Nekitip2 c, Nekitip2 d, Tip3 funk(Tip4)) ->std::vector<std::vector<typename std::remove_reference<decltype(*a)>::type>>
{
	std::vector<std::vector<typename std::remove_reference<decltype(*a)>::type>> M;
	std::vector<typename std::remove_reference<decltype(*a)>::type> v;
	Nekitip pok(a);
	Nekitip2 pok2(c);
	while (pok!=b)
	{
		while(pok2!=d)
		{
			if(funk(*pok)==funk(*pok2))
			{
				v.clear();
				v.push_back(*pok);
				v.push_back(*pok2);
				v.push_back(funk(*pok));
				M.push_back(v);
			}
			pok2++;
		}
		pok++;
		pok2=c;
	}
	std::sort(M.begin(), M.end(), [](std::vector<typename std::remove_reference<decltype(*a)>::type> v1, std::vector<typename std::remove_reference<decltype(*a)>::type> v2){if(v1[2]<v2[2]) return true; else if(v1[2]==v2[2]&&v1[0]<v2[0]) return true; else if(v1[0]==v2[0]&&v1[2]==v2[2]&&v1[1]<v2[1]) return true; else return false;});
	return M;
	
}
template <typename Nekitip, typename Nekitip2, typename Tip3, typename Tip4>
auto UvrnutaRazlika(Nekitip a, Nekitip b, Nekitip2 c, Nekitip2 d, Tip3 funk(Tip4)) ->std::vector<std::vector<typename std::remove_reference<decltype(*a)>::type>>
{
	std::vector<std::vector<typename std::remove_reference<decltype(*a)>::type>> M;
	std::vector<typename std::remove_reference<decltype(*a)>::type> v;
	Nekitip pok(a);
	Nekitip2 pok2(c);
	while (pok!=b)
	{
		bool ima=false;
		while(pok2!=d)
		{
			if(funk(*pok)==funk(*pok2))
			{
				ima=1;
				break;
			}
			pok2++;
		}
		if(!ima)
		{
			v.clear();
			v.push_back(*pok);
			v.push_back(funk(*pok));
			M.push_back(v);
		}
		pok++;
		pok2=c;
	}
	pok2=c;
	pok=a;
	while (pok2!=d)
	{
		bool ima=false;
		while(pok!=b)
		{
			if(funk(*pok2)==funk(*pok))
			{
				ima=1;
				break;
			}
			pok++;
		}
		if(!ima)
		{
			v.clear();
			v.push_back(*pok2);
			v.push_back(funk(*pok2));
			M.push_back(v);
		}
		pok2++;
		pok=a;
	}
	std::sort(M.begin(), M.end(), [](std::vector<typename std::remove_reference<decltype(*a)>::type> v1, std::vector<typename std::remove_reference<decltype(*a)>::type> v2){if(v1[0]>v2[0])return true; else if(v1[0]==v2[0]&&v1[1]>v2[1]) return true; else return false;});
	return M;
}


int main ()
{
	std::cout<<"Unesite broj elemenata prvog kontejnera: ";
	int n;
	std::cin>>n;
	std::deque<int> a;
	std::cout<<"Unesite elemente prvog kontejnera: ";
	int broj;
	for (int i=0; i<n; i++)
	{
		std::cin>>broj;
		bool ima=false;
		for (int j=0; j<a.size(); j++)
		{
			if(a[j]==broj)
			{
				i--;
				ima=1;
				break;
			}
		}
		if(ima==false)
			a.push_back(broj);
	}
	std::cout<<"Unesite broj elemenata drugog kontejnera: ";
	int m;
	std::cin>>m;
	std::deque<int> b;
	std::cout<<"Unesite elemente drugog kontejnera: ";
	for (int i=0; i<m; i++)
	{
		std::cin>>broj;
		bool ima=false;
		for (int j=0; j<b.size(); j++)
		{
			if(b[j]==broj)
			{
				i--;
				ima=1;
				break;
			}
		}
		if (ima==false)
		b.push_back(broj);
	}
	std::cout<<"Uvrnuti presjek kontejnera:"<<std::endl;
	std::vector<std::vector<int>> v{UvrnutiPresjek(a.begin(),a.end(), b.begin(), b.end(), SumaCifara)};
	for (std::vector<int>& red : v)
	{
		for (int& broj : red)
			std::cout <<std::right<<std::setw(6)<< broj<<" ";
		std::cout << std::endl;
	}
	std::cout<<"Uvrnuta razlika kontejnera:";
	std::cout<<std::endl;
	std::vector<std::vector<int>> v2{UvrnutaRazlika(a.begin(),a.end(), b.begin(), b.end(), BrojProstihFaktora)};
		for (std::vector<int>& red : v2)
	{
		for (int& broj : red)
			std::cout << std::right<<std::setw(6)<< broj<<" ";
		std::cout << std::endl;
	}
	std::cout<<"Dovidjenja!";
	return 0;
}