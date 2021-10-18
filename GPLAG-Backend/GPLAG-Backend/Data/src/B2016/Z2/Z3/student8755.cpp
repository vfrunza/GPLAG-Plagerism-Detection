/*B 16/17, Zadaća 2, Zadatak 3
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba
	
*/
#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>
#include<cmath>
#include<iomanip>

int SumaCifri(long long int n)
{
	int suma(0);
	while(n!=0)
	{
		suma+=std::abs(n%10);
		n/=10;
	}
	return suma;
}
int SumaDjelilaca(long long int n)
{
	n=std::abs(n);
	int suma(0);
	if(n>=0)
		for(long long int i=1; i<=n; i++)
		{
			if(n%i==0)	suma+=i;
			if(i==n)	break;
		}
	return suma;
}
int BrojProstihFaktora(long long int n)
{
	n=std::abs(n);
	int br(0);
	auto temp=n;
	for(long long int i=2; i<=temp; i++)
	{
		if(n%i==0)
		{
			n/=i--;
			br++;
		}
		if(i==temp)	break;
	}
	return br;
}
int BrojSavrsenihDjelilaca(long long int n)
{
	int br(0);
	n=std::abs(n);
	for(long long int i=2; i<=n; i++)
	{
		int suma(0);
		if(n%i==0)
			for(long long int j=1; j<=i/2; j++)	
			{
				if(i%j==0)	suma+=j;
				if(j==i/2)	break;
			}
		if(suma==i)	br++;
		if(i==n)	break;
	}
	return br;
}
template<typename IterTip1, typename IterTip2, typename Tip1, typename Tip2>
auto UvrnutiPresjek(IterTip1 poc1, IterTip1 kraj1, IterTip2 poc2, IterTip2 kraj2, Tip1 f(Tip2))->std::vector<std::vector<decltype(*poc1+*poc1)>>
{
	std::vector<std::vector<decltype(*poc1+*poc1)>> mat;
	for(auto it1=poc1;it1!=kraj1; it1++)
	{
		for(auto it2=poc2;it2!=kraj2; it2++)
		{
			std::vector<decltype(*poc1+*poc1)> temp;
			if(f(*it1)==f(*it2))
			{
				temp.push_back(*it1);
				temp.push_back(*it2);
				temp.push_back(f(*it1));
				mat.push_back(temp);
			}
		}
	}
	std::sort(mat.begin(), mat.end(), [](const std::vector<decltype(*poc1+*poc1)> v1, const std::vector<decltype(*poc1+*poc1)> v2)->bool
	{
		if(v1[2]!=v2[2])		return v1[2]<v2[2];
		else if(v1[0]!=v2[0])	return v1[0]<v2[0];
		else					return v1[1]<v2[1];
	});
	return mat;
}
template<typename IterTip1, typename IterTip2>
auto UvrnutiPresjek(IterTip1 poc1, IterTip1 kraj1, IterTip2 poc2, IterTip2 kraj2)->std::vector<std::vector<decltype(*poc1+*poc1)>>
{
	std::vector<std::vector<decltype(*poc1+*poc1)>> mat;
	for(auto it1=poc1; it1!=kraj1; it1++)
		for(auto it2=poc2; it2!=kraj2; it2++)
		{
			std::vector<decltype(*poc1+*poc1)> temp;
			if(*it1==*it2)
			{
				temp.push_back(*it1);
				temp.push_back(0);
				temp.push_back(0);
				mat.push_back(temp);
			}
		}
	std::sort(mat.begin(), mat.end(), [](const std::vector<decltype(*poc1+*poc1)> v1, const std::vector<decltype(*poc1+*poc1)> v2)->bool
	{
		return(v1[0]<v2[0]);
	});
	
	return mat;
}
template<typename IterTip1, typename IterTip2, typename Tip1, typename Tip2>
auto UvrnutaRazlika(IterTip1 poc1, IterTip1 kraj1, IterTip2 poc2, IterTip2 kraj2, Tip1 f(Tip2))->std::vector<std::vector<decltype(*poc1+*poc2)>>
{
	bool NijeJednak(true);
	std::vector<std::vector<decltype(*poc1+*poc1)>> mat;
	for(auto it1=poc1; it1!=kraj1; it1++)
	{
		NijeJednak=true;
		std::vector<decltype(*poc1+*poc1)> temp;
		for(auto it2=poc2; it2!=kraj2; it2++)
			if(f(*it1)==f(*it2))	NijeJednak=false;
		if(NijeJednak)
		{
			temp.push_back(*it1);
			temp.push_back(f(*it1));
			mat.push_back(temp);
		}
	}
	for(auto it2=poc2; it2!=kraj2; it2++)
	{
		NijeJednak=true;
		std::vector<decltype(*poc1+*poc1)> temp;
		for(auto it1=poc1; it1!=kraj1; it1++)
			if(f(*it1)==f(*it2))	NijeJednak=false;
		if(NijeJednak)
		{
			temp.push_back(*it2);
			temp.push_back(f(*it2));
			mat.push_back(temp);
		}
	}
	std::sort(mat.begin(),mat.end(), [](const std::vector<decltype(*poc1+*poc1)> v1, const std::vector<decltype(*poc1+*poc2)> v2)->bool
	{
		if(v1[0]!=v2[0])	return v1[0]>v2[0];
		else 				return v1[1]>v2[1];
	});
	return mat;
}
template<typename IterTip1, typename IterTip2>
auto UvrnutaRazlika(IterTip1 poc1, IterTip1 kraj1, IterTip2 poc2, IterTip2 kraj2)->std::vector<std::vector<decltype(*poc1+*poc1)>>
{
	std::vector<std::vector<decltype(*poc1+*poc1)>> mat;
	for(auto it1=poc1; it1!=kraj1; it1++)
	{
		bool NijeJednak(true);
		std::vector<decltype(*poc1+*poc1)> temp;
		for(auto it2=poc2; it2!=kraj2; it2++)
			if(*it1==*it2)	NijeJednak=false;
		if(NijeJednak)
		{
			temp.push_back(*it1);
			temp.push_back(0);
			mat.push_back(temp);
		}
	}
	for(auto it2=poc2; it2!=kraj2; it2++)
	{
		bool NijeJednak(true);
		std::vector<decltype(*poc1+*poc1)>temp;
		for(auto it1=poc1; it1!=kraj1; it1++)
			if(*it1==*it2)	NijeJednak=false;
		if(NijeJednak)
		{
			temp.push_back(*it2);
			temp.push_back(0);
			mat.push_back(temp);
		}
	}
	std::sort(mat.begin(), mat.end(), [](const std::vector<decltype(*poc1+*poc1)> v1, const std::vector<decltype(*poc1+*poc1)>v2)->bool
	{
		return(v1[0]>v2[0]);
	});
	return mat;
}
int main ()
{
	std::deque<int> prvi, drugi;
	int n;
	std::cout<<"Unesite broj elemenata prvog kontejnera: ";
	std::cin>>n;
	
	std::cout<<"Unesite elemente prvog kontejnera: ";
	for(int i=0; i<n; i++)
	{
		bool Upisi(true);
		int x;
		std::cin>>x;
		for(int j=0; j<i; j++)
			if(prvi[j]==x)
			{
				i--;
				Upisi=false;
				break;
			}
		if(Upisi)	prvi.push_back(x);
	}
	std::cout<<"Unesite broj elemenata drugog kontejnera: ";
	std::cin>>n;
	std::cout<<"Unesite elemente drugog kontejnera: ";
	for(int i=0; i<n; i++)
	{
		bool Upisi(true);
		int x;
		std::cin>>x;
		for(int j=0; j<i; j++)
			if(drugi[j]==x)
			{
				i--;
				Upisi=false;
				break;
			}
		if(Upisi)	drugi.push_back(x);
	}
	auto presjek(UvrnutiPresjek(prvi.begin(), prvi.end(), drugi.begin(), drugi.end(),SumaCifri));
	std::cout<<"Uvrnuti presjek kontejnera:"<<std::endl;
	for(int i=0; i<presjek.size(); i++)
	{
		for(int j=0; j<presjek[i].size(); j++)
			std::cout<<std::setw(6)<<presjek[i][j]<<" ";
		std::cout<<std::endl;
	}
	std::cout<<"Uvrnuta razlika kontejnera:"<<std::endl;
	auto razlika(UvrnutaRazlika(prvi.begin(), prvi.end(), drugi.begin(), drugi.end(), BrojProstihFaktora));
	for(int i=0; i<razlika.size(); i++)
	{
		for(int j=0; j<razlika[i].size(); j++)
			std::cout<<std::setw(6)<<razlika[i][j]<<" ";
		std::cout<<std::endl;
	}
	std::cout<<"Dovidjenja!";
}